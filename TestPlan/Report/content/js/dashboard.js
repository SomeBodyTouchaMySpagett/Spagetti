/*
   Licensed to the Apache Software Foundation (ASF) under one or more
   contributor license agreements.  See the NOTICE file distributed with
   this work for additional information regarding copyright ownership.
   The ASF licenses this file to You under the Apache License, Version 2.0
   (the "License"); you may not use this file except in compliance with
   the License.  You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/
var showControllersOnly = false;
var seriesFilter = "";
var filtersOnlySampleSeries = true;

/*
 * Add header in statistics table to group metrics by category
 * format
 *
 */
function summaryTableHeader(header) {
    var newRow = header.insertRow(-1);
    newRow.className = "tablesorter-no-sort";
    var cell = document.createElement('th');
    cell.setAttribute("data-sorter", false);
    cell.colSpan = 1;
    cell.innerHTML = "Requests";
    newRow.appendChild(cell);

    cell = document.createElement('th');
    cell.setAttribute("data-sorter", false);
    cell.colSpan = 3;
    cell.innerHTML = "Executions";
    newRow.appendChild(cell);

    cell = document.createElement('th');
    cell.setAttribute("data-sorter", false);
    cell.colSpan = 6;
    cell.innerHTML = "Response Times (ms)";
    newRow.appendChild(cell);

    cell = document.createElement('th');
    cell.setAttribute("data-sorter", false);
    cell.colSpan = 1;
    cell.innerHTML = "Throughput";
    newRow.appendChild(cell);

    cell = document.createElement('th');
    cell.setAttribute("data-sorter", false);
    cell.colSpan = 2;
    cell.innerHTML = "Network (KB/sec)";
    newRow.appendChild(cell);
}

/*
 * Populates the table identified by id parameter with the specified data and
 * format
 *
 */
function createTable(table, info, formatter, defaultSorts, seriesIndex, headerCreator) {
    var tableRef = table[0];

    // Create header and populate it with data.titles array
    var header = tableRef.createTHead();

    // Call callback is available
    if(headerCreator) {
        headerCreator(header);
    }

    var newRow = header.insertRow(-1);
    for (var index = 0; index < info.titles.length; index++) {
        var cell = document.createElement('th');
        cell.innerHTML = info.titles[index];
        newRow.appendChild(cell);
    }

    var tBody;

    // Create overall body if defined
    if(info.overall){
        tBody = document.createElement('tbody');
        tBody.className = "tablesorter-no-sort";
        tableRef.appendChild(tBody);
        var newRow = tBody.insertRow(-1);
        var data = info.overall.data;
        for(var index=0;index < data.length; index++){
            var cell = newRow.insertCell(-1);
            cell.innerHTML = formatter ? formatter(index, data[index]): data[index];
        }
    }

    // Create regular body
    tBody = document.createElement('tbody');
    tableRef.appendChild(tBody);

    var regexp;
    if(seriesFilter) {
        regexp = new RegExp(seriesFilter, 'i');
    }
    // Populate body with data.items array
    for(var index=0; index < info.items.length; index++){
        var item = info.items[index];
        if((!regexp || filtersOnlySampleSeries && !info.supportsControllersDiscrimination || regexp.test(item.data[seriesIndex]))
                &&
                (!showControllersOnly || !info.supportsControllersDiscrimination || item.isController)){
            if(item.data.length > 0) {
                var newRow = tBody.insertRow(-1);
                for(var col=0; col < item.data.length; col++){
                    var cell = newRow.insertCell(-1);
                    cell.innerHTML = formatter ? formatter(col, item.data[col]) : item.data[col];
                }
            }
        }
    }

    // Add support of columns sort
    table.tablesorter({sortList : defaultSorts});
}

$(document).ready(function() {

    // Customize table sorter default options
    $.extend( $.tablesorter.defaults, {
        theme: 'blue',
        cssInfoBlock: "tablesorter-no-sort",
        widthFixed: true,
        widgets: ['zebra']
    });

    var data = {"OkPercent": 98.49933908716274, "KoPercent": 1.5006609128372599};
    var dataset = [
        {
            "label" : "KO",
            "data" : data.KoPercent,
            "color" : "#FF6347"
        },
        {
            "label" : "OK",
            "data" : data.OkPercent,
            "color" : "#9ACD32"
        }];
    $.plot($("#flot-requests-summary"), dataset, {
        series : {
            pie : {
                show : true,
                radius : 1,
                label : {
                    show : true,
                    radius : 3 / 4,
                    formatter : function(label, series) {
                        return '<div style="font-size:8pt;text-align:center;padding:2px;color:white;">'
                            + label
                            + '<br/>'
                            + Math.round10(series.percent, -2)
                            + '%</div>';
                    },
                    background : {
                        opacity : 0.5,
                        color : '#000'
                    }
                }
            }
        },
        legend : {
            show : true
        }
    });

    // Creates APDEX table
    createTable($("#apdexTable"), {"supportsControllersDiscrimination": true, "overall": {"data": [0.9824951249376446, 500, 1500, "Total"], "isController": false}, "titles": ["Apdex", "T (Toleration threshold)", "F (Frustration threshold)", "Label"], "items": [{"data": [1.0, 500, 1500, "II_SELECT"], "isController": false}, {"data": [1.0, 500, 1500, "II_TRUNCATE"], "isController": false}, {"data": [1.0, 500, 1500, "I_Clients_GET"], "isController": false}, {"data": [0.9474835886214442, 500, 1500, "I_SendComment"], "isController": true}, {"data": [1.0, 500, 1500, "II_CountRecords"], "isController": true}, {"data": [1.0, 500, 1500, "II_HomePage"], "isController": true}, {"data": [0.9469365426695843, 500, 1500, "I_CheckCommentServiceGuestBook_GET"], "isController": false}, {"data": [1.0, 500, 1500, "I_HomePage_GET"], "isController": false}, {"data": [1.0, 500, 1500, "I_SendCommentServiceGuestBook_GET"], "isController": false}, {"data": [1.0, 500, 1500, "II_HomePage_GET"], "isController": false}, {"data": [1.0, 500, 1500, "I_sendComment_Clients"], "isController": true}, {"data": [1.0, 500, 1500, "I_CheckComment_GET"], "isController": false}, {"data": [1.0, 500, 1500, "II_GuestBook_GET"], "isController": false}, {"data": [0.9474835886214442, 500, 1500, "I_SendCommentServiceGuestBook_POST"], "isController": false}, {"data": [1.0, 500, 1500, "I_HomePage"], "isController": true}, {"data": [1.0, 500, 1500, "I_GuestBook"], "isController": true}, {"data": [1.0, 500, 1500, "II_GuestBook"], "isController": true}, {"data": [0.9469365426695843, 500, 1500, "I_CheckComment"], "isController": true}, {"data": [1.0, 500, 1500, "I_GuestBook_GET"], "isController": false}]}, function(index, item){
        switch(index){
            case 0:
                item = item.toFixed(3);
                break;
            case 1:
            case 2:
                item = formatDuration(item);
                break;
        }
        return item;
    }, [[0, 0]], 3);

    // Create statistics table
    createTable($("#statisticsTable"), {"supportsControllersDiscrimination": true, "overall": {"data": ["Total", 12861, 193, 1.5006609128372599, 2.3910271363035536, 0, 141, 3.0, 4.0, 15.0, 42.057725135221744, 256.8566539330808, 16.17812269554831], "isController": false}, "titles": ["Label", "#Samples", "KO", "Error %", "Average", "Min", "Max", "90th pct", "95th pct", "99th pct", "Transactions\/s", "Received", "Sent"], "items": [{"data": ["II_SELECT", 16, 0, 0.0, 11.437499999999998, 0, 141, 47.200000000000095, 141.0, 141.0, 0.05327189308331058, 6.535431219327043E-4, 0.0], "isController": false}, {"data": ["II_TRUNCATE", 16, 0, 0.0, 0.5625, 0, 1, 1.0, 1.0, 1.0, 0.053304371291598235, 4.684954508050626E-4, 0.0], "isController": false}, {"data": ["I_Clients_GET", 1828, 0, 0.0, 1.9381838074398285, 1, 81, 3.0, 3.0, 4.0, 5.980833848640407, 35.832497876403195, 2.289537957682656], "isController": false}, {"data": ["I_SendComment", 1828, 96, 5.25164113785558, 5.923413566739593, 2, 34, 11.0, 18.0, 24.0, 5.980970828043817, 20.68375836575207, 4.831983552330223], "isController": true}, {"data": ["II_CountRecords", 16, 0, 0.0, 11.437499999999998, 0, 141, 47.200000000000095, 141.0, 141.0, 0.05327171571548908, 6.535409459724918E-4, 0.0], "isController": true}, {"data": ["II_HomePage", 17, 0, 0.0, 4.529411764705882, 0, 33, 9.79999999999998, 33.0, 33.0, 0.05657953418402327, 1.17672950323169, 0.018981185640779868], "isController": true}, {"data": ["I_CheckCommentServiceGuestBook_GET", 1828, 97, 5.306345733041575, 2.7822757111597363, 1, 24, 4.0, 8.0, 17.710000000000036, 5.981655819189073, 18.83136758592086, 1.9685722764323415], "isController": false}, {"data": ["I_HomePage_GET", 1829, 0, 0.0, 2.35975943138327, 1, 33, 3.0, 3.0, 5.0, 5.981150709301033, 132.16995844731258, 2.1319531336864035], "isController": false}, {"data": ["I_SendCommentServiceGuestBook_GET", 1828, 0, 0.0, 2.388949671772433, 1, 24, 3.0, 4.0, 14.0, 5.9815775265457045, 18.831181820691743, 1.822511902619394], "isController": false}, {"data": ["II_HomePage_GET", 16, 0, 0.0, 4.8125, 2, 33, 12.70000000000002, 33.0, 33.0, 0.05326586323989613, 1.177050735734736, 0.01898636726812704], "isController": false}, {"data": ["I_sendComment_Clients", 1828, 0, 0.0, 1.9387308533916856, 1, 81, 3.0, 3.0, 4.0, 5.980833848640407, 35.832497876403195, 2.289537957682656], "isController": true}, {"data": ["I_CheckComment_GET", 1828, 0, 0.0, 1.8183807439824944, 1, 6, 2.0, 3.0, 4.0, 5.981636245836087, 24.021890220981867, 2.5176613495657754], "isController": false}, {"data": ["II_GuestBook_GET", 16, 0, 0.0, 1.9375, 1, 5, 3.6000000000000014, 5.0, 5.0, 0.05327189308331058, 0.21391994566266906, 0.021433613232738243], "isController": false}, {"data": ["I_SendCommentServiceGuestBook_POST", 1828, 96, 5.25164113785558, 3.5344638949671774, 1, 30, 7.0, 13.0, 20.0, 5.981009966168686, 1.8544986865417459, 3.0096761976743425], "isController": false}, {"data": ["I_HomePage", 1829, 0, 0.0, 2.35975943138327, 1, 33, 3.0, 3.0, 5.0, 5.981717986035028, 132.18249398537276, 2.132155336819126], "isController": true}, {"data": ["I_GuestBook", 1828, 0, 0.0, 1.8347921225382924, 1, 6, 2.0, 3.0, 4.0, 5.980990397042223, 24.01759668906539, 2.406414105059957], "isController": true}, {"data": ["II_GuestBook", 16, 0, 0.0, 1.9375, 1, 5, 3.6000000000000014, 5.0, 5.0, 0.05327189308331058, 0.21391994566266906, 0.021433613232738243], "isController": true}, {"data": ["I_CheckComment", 1828, 97, 5.306345733041575, 4.6012035010940915, 2, 26, 6.0, 10.0, 20.0, 5.9815970995144045, 42.852915737154945, 4.486197824635804], "isController": true}, {"data": ["I_GuestBook_GET", 1828, 0, 0.0, 1.8347921225382924, 1, 6, 2.0, 3.0, 4.0, 5.980990397042223, 24.01759668906539, 2.406414105059957], "isController": false}]}, function(index, item){
        switch(index){
            // Errors pct
            case 3:
                item = item.toFixed(2) + '%';
                break;
            // Mean
            case 4:
            // Mean
            case 7:
            // Percentile 1
            case 8:
            // Percentile 2
            case 9:
            // Percentile 3
            case 10:
            // Throughput
            case 11:
            // Kbytes/s
            case 12:
            // Sent Kbytes/s
                item = item.toFixed(2);
                break;
        }
        return item;
    }, [[0, 0]], 0, summaryTableHeader);

    // Create error table
    createTable($("#errorsTable"), {"supportsControllersDiscrimination": false, "titles": ["Type of error", "Number of errors", "% in errors", "% in all samples"], "items": [{"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Sierra\'&lt;br&gt;\\\/", 4, 2.0725388601036268, 0.03110178057693803], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'India\'&lt;br&gt;\\\/", 6, 3.1088082901554404, 0.046652670865407045], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Papa\'&lt;br&gt;\\\/", 4, 2.0725388601036268, 0.03110178057693803], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Echo\'&lt;br&gt;\\\/", 5, 2.5906735751295336, 0.03887722572117254], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Romeo\'&lt;br&gt;\\\/", 1, 0.5181347150259067, 0.007775445144234508], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Delta\'&lt;br&gt;\\\/", 2, 1.0362694300518134, 0.015550890288469016], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'November\'&lt;br&gt;\\\/", 2, 1.0362694300518134, 0.015550890288469016], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Bravo\'&lt;br&gt;\\\/", 3, 1.5544041450777202, 0.023326335432703522], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Victor\'&lt;br&gt;\\\/", 2, 1.0362694300518134, 0.015550890288469016], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Charlie\'&lt;br&gt;\\\/", 3, 1.5544041450777202, 0.023326335432703522], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Mike\'&lt;br&gt;\\\/", 2, 1.0362694300518134, 0.015550890288469016], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Golf\'&lt;br&gt;\\\/", 2, 1.0362694300518134, 0.015550890288469016], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Alpha\'&lt;br&gt;\\\/", 2, 1.0362694300518134, 0.015550890288469016], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Lima\'&lt;br&gt;\\\/", 8, 4.1450777202072535, 0.06220356115387606], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Oscar\'&lt;br&gt;\\\/", 4, 2.0725388601036268, 0.03110178057693803], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Foxtrot\'&lt;br&gt;\\\/", 4, 2.0725388601036268, 0.03110178057693803], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'X-Ray\'&lt;br&gt;\\\/", 8, 4.1450777202072535, 0.06220356115387606], "isController": false}, {"data": ["Response was null", 2, 1.0362694300518134, 0.015550890288469016], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Juliett\'&lt;br&gt;\\\/", 2, 1.0362694300518134, 0.015550890288469016], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Hotel\'&lt;br&gt;\\\/", 5, 2.5906735751295336, 0.03887722572117254], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Yankee\'&lt;br&gt;\\\/", 3, 1.5544041450777202, 0.023326335432703522], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Whiskey\'&lt;br&gt;\\\/", 4, 2.0725388601036268, 0.03110178057693803], "isController": false}, {"data": ["500", 96, 49.740932642487046, 0.7464427338465127], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Quebec\'&lt;br&gt;\\\/", 3, 1.5544041450777202, 0.023326335432703522], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Tango\'&lt;br&gt;\\\/", 3, 1.5544041450777202, 0.023326335432703522], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Kilo\'&lt;br&gt;\\\/", 3, 1.5544041450777202, 0.023326335432703522], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Zulu\'&lt;br&gt;\\\/", 6, 3.1088082901554404, 0.046652670865407045], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Uniform\'&lt;br&gt;\\\/", 4, 2.0725388601036268, 0.03110178057693803], "isController": false}]}, function(index, item){
        switch(index){
            case 2:
            case 3:
                item = item.toFixed(2) + '%';
                break;
        }
        return item;
    }, [[1, 1]]);

        // Create top5 errors by sampler
    createTable($("#top5ErrorsBySamplerTable"), {"supportsControllersDiscrimination": false, "overall": {"data": ["Total", 12861, 193, "500", 96, "Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Lima\'&lt;br&gt;\\\/", 8, "Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'X-Ray\'&lt;br&gt;\\\/", 8, "Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'India\'&lt;br&gt;\\\/", 6, "Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Zulu\'&lt;br&gt;\\\/", 6], "isController": false}, "titles": ["Sample", "#Samples", "#Errors", "Error", "#Errors", "Error", "#Errors", "Error", "#Errors", "Error", "#Errors", "Error", "#Errors"], "items": [{"data": [], "isController": false}, {"data": [], "isController": false}, {"data": [], "isController": false}, {"data": [], "isController": false}, {"data": [], "isController": false}, {"data": [], "isController": false}, {"data": ["I_CheckCommentServiceGuestBook_GET", 1828, 97, "Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Lima\'&lt;br&gt;\\\/", 8, "Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'X-Ray\'&lt;br&gt;\\\/", 8, "Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'India\'&lt;br&gt;\\\/", 6, "Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Zulu\'&lt;br&gt;\\\/", 6, "Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Echo\'&lt;br&gt;\\\/", 5], "isController": false}, {"data": [], "isController": false}, {"data": [], "isController": false}, {"data": [], "isController": false}, {"data": [], "isController": false}, {"data": [], "isController": false}, {"data": [], "isController": false}, {"data": ["I_SendCommentServiceGuestBook_POST", 1828, 96, "500", 96, null, null, null, null, null, null, null, null], "isController": false}, {"data": [], "isController": false}, {"data": [], "isController": false}, {"data": [], "isController": false}, {"data": [], "isController": false}, {"data": [], "isController": false}]}, function(index, item){
        return item;
    }, [[0, 0]], 0);

});
