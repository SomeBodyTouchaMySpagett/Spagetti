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

    var data = {"OkPercent": 98.52247720842503, "KoPercent": 1.4775227915749765};
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
    createTable($("#apdexTable"), {"supportsControllersDiscrimination": true, "overall": {"data": [0.9827657331438786, 500, 1500, "Total"], "isController": false}, "titles": ["Apdex", "T (Toleration threshold)", "F (Frustration threshold)", "Label"], "items": [{"data": [1.0, 500, 1500, "II_SELECT"], "isController": false}, {"data": [1.0, 500, 1500, "II_TRUNCATE"], "isController": false}, {"data": [1.0, 500, 1500, "I_Clients_GET"], "isController": false}, {"data": [0.9480088495575221, 500, 1500, "I_SendComment"], "isController": true}, {"data": [1.0, 500, 1500, "II_CountRecords"], "isController": true}, {"data": [1.0, 500, 1500, "II_HomePage"], "isController": true}, {"data": [0.9480088495575221, 500, 1500, "I_CheckCommentServiceGuestBook_GET"], "isController": false}, {"data": [1.0, 500, 1500, "I_HomePage_GET"], "isController": false}, {"data": [1.0, 500, 1500, "I_SendCommentServiceGuestBook_GET"], "isController": false}, {"data": [1.0, 500, 1500, "II_HomePage_GET"], "isController": false}, {"data": [1.0, 500, 1500, "I_sendComment_Clients"], "isController": true}, {"data": [1.0, 500, 1500, "I_CheckComment_GET"], "isController": false}, {"data": [1.0, 500, 1500, "II_GuestBook_GET"], "isController": false}, {"data": [0.9480088495575221, 500, 1500, "I_SendCommentServiceGuestBook_POST"], "isController": false}, {"data": [1.0, 500, 1500, "I_HomePage"], "isController": true}, {"data": [1.0, 500, 1500, "I_GuestBook"], "isController": true}, {"data": [1.0, 500, 1500, "II_GuestBook"], "isController": true}, {"data": [0.9480088495575221, 500, 1500, "I_CheckComment"], "isController": true}, {"data": [1.0, 500, 1500, "I_GuestBook_GET"], "isController": false}]}, function(index, item){
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
    createTable($("#statisticsTable"), {"supportsControllersDiscrimination": true, "overall": {"data": ["Total", 12724, 188, 1.4775227915749765, 2.4989783087079647, 0, 226, 3.0, 5.0, 11.0, 41.702308965472035, 253.56022908370613, 16.030885639431034], "isController": false}, "titles": ["Label", "#Samples", "KO", "Error %", "Average", "Min", "Max", "90th pct", "95th pct", "99th pct", "Transactions\/s", "Received", "Sent"], "items": [{"data": ["II_SELECT", 17, 0, 0.0, 9.470588235294118, 0, 122, 29.99999999999992, 122.0, 122.0, 0.05662797088656085, 6.896329175063707E-4, 0.0], "isController": false}, {"data": ["II_TRUNCATE", 16, 0, 0.0, 0.75, 0, 1, 1.0, 1.0, 1.0, 0.05332551225820213, 4.686812600818547E-4, 0.0], "isController": false}, {"data": ["I_Clients_GET", 1808, 0, 0.0, 1.627765486725663, 1, 18, 2.0, 2.0, 4.0, 5.932498146094329, 35.54303042722682, 2.2710344465517354], "isController": false}, {"data": ["I_SendComment", 1808, 94, 5.199115044247788, 7.534845132743367, 2, 130, 11.0, 41.0, 51.0, 5.9327317473338805, 19.9494783121411, 4.784223748974569], "isController": true}, {"data": ["II_CountRecords", 17, 0, 0.0, 9.470588235294118, 0, 122, 29.99999999999992, 122.0, 122.0, 0.05662797088656085, 6.896329175063707E-4, 0.0], "isController": true}, {"data": ["II_HomePage", 18, 0, 0.0, 15.055555555555555, 0, 226, 25.300000000000317, 226.0, 226.0, 0.05989558203531843, 1.2500213170040229, 0.020163416152840213], "isController": true}, {"data": ["I_CheckCommentServiceGuestBook_GET", 1808, 94, 5.199115044247788, 2.720685840707967, 1, 14, 5.0, 7.0, 10.0, 5.934172694928383, 18.094971430716566, 1.9529455060457668], "isController": false}, {"data": ["I_HomePage_GET", 1809, 0, 0.0, 2.2459922609176353, 1, 226, 3.0, 3.0, 4.0, 5.928912049555086, 131.01579015289317, 2.113332908288678], "isController": false}, {"data": ["I_SendCommentServiceGuestBook_GET", 1808, 0, 0.0, 2.2726769911504454, 1, 19, 3.0, 4.0, 9.0, 5.933822129743283, 18.115793016928457, 1.8079614301561566], "isController": false}, {"data": ["II_HomePage_GET", 17, 0, 0.0, 15.941176470588236, 2, 226, 47.59999999999984, 226.0, 226.0, 0.056583112270880004, 1.2503541645170633, 0.02016878513561641], "isController": false}, {"data": ["I_sendComment_Clients", 1808, 0, 0.0, 1.627765486725663, 1, 18, 2.0, 2.0, 4.0, 5.932498146094329, 35.54303042722682, 2.2710344465517354], "isController": true}, {"data": ["I_CheckComment_GET", 1808, 0, 0.0, 1.646570796460177, 1, 5, 2.0, 2.0, 4.0, 5.934153217998077, 23.83055200671531, 2.497675817340987], "isController": false}, {"data": ["II_GuestBook_GET", 17, 0, 0.0, 2.88235294117647, 1, 17, 7.3999999999999915, 17.0, 17.0, 0.05662570740497706, 0.22738760629811106, 0.022782999463721244], "isController": false}, {"data": ["I_SendCommentServiceGuestBook_POST", 1808, 94, 5.199115044247788, 5.262168141592923, 1, 124, 9.0, 38.549999999999955, 44.91000000000008, 5.932906960336811, 1.8370684552620096, 2.976682453296406], "isController": false}, {"data": ["I_HomePage", 1809, 0, 0.0, 2.246545052515201, 1, 226, 3.0, 3.0, 4.0, 5.929533930110822, 131.029532332185, 2.113554574697705], "isController": true}, {"data": ["I_GuestBook", 1808, 0, 0.0, 1.5376106194690302, 1, 4, 2.0, 2.0, 3.0, 5.932887491714302, 23.824677539730327, 2.3870602017444265], "isController": true}, {"data": ["II_GuestBook", 17, 0, 0.0, 2.88235294117647, 1, 17, 7.3999999999999915, 17.0, 17.0, 0.05662589602153116, 0.22738836371146107, 0.02278307535241293], "isController": true}, {"data": ["I_CheckComment", 1808, 94, 5.199115044247788, 4.367256637168139, 2, 15, 7.0, 9.0, 14.0, 5.934094787974268, 41.92505123203033, 4.450571090980701], "isController": true}, {"data": ["I_GuestBook_GET", 1808, 0, 0.0, 1.5370575221238965, 1, 4, 2.0, 2.0, 3.0, 5.932887491714302, 23.824677539730327, 2.3870602017444265], "isController": false}]}, function(index, item){
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
    createTable($("#errorsTable"), {"supportsControllersDiscrimination": false, "titles": ["Type of error", "Number of errors", "% in errors", "% in all samples"], "items": [{"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Sierra\'&lt;br&gt;\\\/", 4, 2.127659574468085, 0.03143665513989312], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'India\'&lt;br&gt;\\\/", 3, 1.5957446808510638, 0.023577491354919836], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Echo\'&lt;br&gt;\\\/", 4, 2.127659574468085, 0.03143665513989312], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Papa\'&lt;br&gt;\\\/", 4, 2.127659574468085, 0.03143665513989312], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Romeo\'&lt;br&gt;\\\/", 2, 1.0638297872340425, 0.01571832756994656], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Delta\'&lt;br&gt;\\\/", 2, 1.0638297872340425, 0.01571832756994656], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'November\'&lt;br&gt;\\\/", 5, 2.6595744680851063, 0.039295818924866395], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Bravo\'&lt;br&gt;\\\/", 5, 2.6595744680851063, 0.039295818924866395], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Victor\'&lt;br&gt;\\\/", 4, 2.127659574468085, 0.03143665513989312], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Charlie\'&lt;br&gt;\\\/", 7, 3.723404255319149, 0.055014146494812954], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Mike\'&lt;br&gt;\\\/", 5, 2.6595744680851063, 0.039295818924866395], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Golf\'&lt;br&gt;\\\/", 8, 4.25531914893617, 0.06287331027978624], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Lima\'&lt;br&gt;\\\/", 2, 1.0638297872340425, 0.01571832756994656], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Alpha\'&lt;br&gt;\\\/", 4, 2.127659574468085, 0.03143665513989312], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Oscar\'&lt;br&gt;\\\/", 5, 2.6595744680851063, 0.039295818924866395], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Foxtrot\'&lt;br&gt;\\\/", 2, 1.0638297872340425, 0.01571832756994656], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'X-Ray\'&lt;br&gt;\\\/", 3, 1.5957446808510638, 0.023577491354919836], "isController": false}, {"data": ["Response was null", 2, 1.0638297872340425, 0.01571832756994656], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Juliett\'&lt;br&gt;\\\/", 3, 1.5957446808510638, 0.023577491354919836], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Hotel\'&lt;br&gt;\\\/", 5, 2.6595744680851063, 0.039295818924866395], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Yankee\'&lt;br&gt;\\\/", 3, 1.5957446808510638, 0.023577491354919836], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Whiskey\'&lt;br&gt;\\\/", 1, 0.5319148936170213, 0.00785916378497328], "isController": false}, {"data": ["500", 94, 50.0, 0.7387613957874882], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Quebec\'&lt;br&gt;\\\/", 1, 0.5319148936170213, 0.00785916378497328], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Tango\'&lt;br&gt;\\\/", 2, 1.0638297872340425, 0.01571832756994656], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Kilo\'&lt;br&gt;\\\/", 4, 2.127659574468085, 0.03143665513989312], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Zulu\'&lt;br&gt;\\\/", 4, 2.127659574468085, 0.03143665513989312], "isController": false}]}, function(index, item){
        switch(index){
            case 2:
            case 3:
                item = item.toFixed(2) + '%';
                break;
        }
        return item;
    }, [[1, 1]]);

        // Create top5 errors by sampler
    createTable($("#top5ErrorsBySamplerTable"), {"supportsControllersDiscrimination": false, "overall": {"data": ["Total", 12724, 188, "500", 94, "Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Golf\'&lt;br&gt;\\\/", 8, "Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Charlie\'&lt;br&gt;\\\/", 7, "Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'November\'&lt;br&gt;\\\/", 5, "Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Bravo\'&lt;br&gt;\\\/", 5], "isController": false}, "titles": ["Sample", "#Samples", "#Errors", "Error", "#Errors", "Error", "#Errors", "Error", "#Errors", "Error", "#Errors", "Error", "#Errors"], "items": [{"data": [], "isController": false}, {"data": [], "isController": false}, {"data": [], "isController": false}, {"data": [], "isController": false}, {"data": [], "isController": false}, {"data": [], "isController": false}, {"data": ["I_CheckCommentServiceGuestBook_GET", 1808, 94, "Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Golf\'&lt;br&gt;\\\/", 8, "Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Charlie\'&lt;br&gt;\\\/", 7, "Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'November\'&lt;br&gt;\\\/", 5, "Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Bravo\'&lt;br&gt;\\\/", 5, "Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Mike\'&lt;br&gt;\\\/", 5], "isController": false}, {"data": [], "isController": false}, {"data": [], "isController": false}, {"data": [], "isController": false}, {"data": [], "isController": false}, {"data": [], "isController": false}, {"data": [], "isController": false}, {"data": ["I_SendCommentServiceGuestBook_POST", 1808, 94, "500", 94, null, null, null, null, null, null, null, null], "isController": false}, {"data": [], "isController": false}, {"data": [], "isController": false}, {"data": [], "isController": false}, {"data": [], "isController": false}, {"data": [], "isController": false}]}, function(index, item){
        return item;
    }, [[0, 0]], 0);

});
