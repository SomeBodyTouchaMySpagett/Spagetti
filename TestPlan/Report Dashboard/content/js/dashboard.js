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

    var data = {"OkPercent": 98.41208064139488, "KoPercent": 1.587919358605122};
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
    createTable($("#apdexTable"), {"supportsControllersDiscrimination": true, "overall": {"data": [0.9814772778862305, 500, 1500, "Total"], "isController": false}, "titles": ["Apdex", "T (Toleration threshold)", "F (Frustration threshold)", "Label"], "items": [{"data": [1.0, 500, 1500, "II_SELECT"], "isController": false}, {"data": [1.0, 500, 1500, "II_TRUNCATE"], "isController": false}, {"data": [1.0, 500, 1500, "I_Clients_GET"], "isController": false}, {"data": [0.9441401971522454, 500, 1500, "I_SendComment"], "isController": true}, {"data": [1.0, 500, 1500, "II_CountRecords"], "isController": true}, {"data": [1.0, 500, 1500, "II_HomePage"], "isController": true}, {"data": [0.9441401971522454, 500, 1500, "I_CheckCommentServiceGuestBook_GET"], "isController": false}, {"data": [1.0, 500, 1500, "I_HomePage_GET"], "isController": false}, {"data": [1.0, 500, 1500, "I_SendCommentServiceGuestBook_GET"], "isController": false}, {"data": [1.0, 500, 1500, "II_HomePage_GET"], "isController": false}, {"data": [1.0, 500, 1500, "I_sendComment_Clients"], "isController": true}, {"data": [1.0, 500, 1500, "I_CheckComment_GET"], "isController": false}, {"data": [1.0, 500, 1500, "II_GuestBook_GET"], "isController": false}, {"data": [0.9441401971522454, 500, 1500, "I_SendCommentServiceGuestBook_POST"], "isController": false}, {"data": [1.0, 500, 1500, "I_HomePage"], "isController": true}, {"data": [1.0, 500, 1500, "I_GuestBook"], "isController": true}, {"data": [1.0, 500, 1500, "II_GuestBook"], "isController": true}, {"data": [0.9441401971522454, 500, 1500, "I_CheckComment"], "isController": true}, {"data": [1.0, 500, 1500, "I_GuestBook_GET"], "isController": false}]}, function(index, item){
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
    createTable($("#statisticsTable"), {"supportsControllersDiscrimination": true, "overall": {"data": ["Total", 12847, 204, 1.587919358605122, 2.616097143301919, 0, 167, 4.0, 5.0, 12.0, 42.00562385561078, 256.32095277044374, 16.16235204682187], "isController": false}, "titles": ["Label", "#Samples", "KO", "Error %", "Average", "Min", "Max", "90th pct", "95th pct", "99th pct", "Transactions\/s", "Received", "Sent"], "items": [{"data": ["II_SELECT", 16, 0, 0.0, 9.312500000000002, 0, 111, 38.200000000000074, 111.0, 111.0, 0.05327739207165809, 6.536105838869187E-4, 0.0], "isController": false}, {"data": ["II_TRUNCATE", 16, 0, 0.0, 0.9375, 0, 2, 1.3000000000000007, 2.0, 2.0, 0.05330366096206445, 4.6848920767439466E-4, 0.0], "isController": false}, {"data": ["I_Clients_GET", 1826, 0, 0.0, 1.725629791894852, 1, 7, 2.0, 3.0, 4.0, 5.975971749951728, 35.80336803464656, 2.2876766855283956], "isController": false}, {"data": ["I_SendComment", 1826, 102, 5.585980284775466, 7.819277108433745, 2, 124, 12.0, 23.649999999999864, 52.0, 5.976226010001833, 20.566509677206884, 4.8324700421625035], "isController": true}, {"data": ["II_CountRecords", 16, 0, 0.0, 9.312500000000002, 0, 111, 38.200000000000074, 111.0, 111.0, 0.0532772146672172, 6.536084074774571E-4, 0.0], "isController": true}, {"data": ["II_HomePage", 17, 0, 0.0, 12.705882352941176, 0, 167, 37.399999999999885, 167.0, 167.0, 0.05656127415915012, 1.1763497349937948, 0.018975059805229587], "isController": true}, {"data": ["I_CheckCommentServiceGuestBook_GET", 1826, 102, 5.585980284775466, 2.901971522453454, 1, 22, 6.0, 8.0, 11.0, 5.977478067303916, 18.70115589093394, 1.9671973717591986], "isController": false}, {"data": ["I_HomePage_GET", 1827, 0, 0.0, 2.320744389709908, 1, 167, 3.0, 3.0, 4.0, 5.973711744703113, 132.0058780224137, 2.1293015496256213], "isController": false}, {"data": ["I_SendCommentServiceGuestBook_GET", 1826, 0, 0.0, 2.456188389923326, 1, 50, 4.0, 4.0, 9.0, 5.9772041349420935, 18.700359601988907, 1.821179384865169], "isController": false}, {"data": ["II_HomePage_GET", 16, 0, 0.0, 13.5, 2, 167, 53.600000000000115, 167.0, 167.0, 0.053247427483659696, 1.1766433487307146, 0.01897979592923417], "isController": false}, {"data": ["I_sendComment_Clients", 1826, 0, 0.0, 1.725629791894852, 1, 7, 2.0, 3.0, 4.0, 5.975971749951728, 35.80336803464656, 2.2876766855283956], "isController": true}, {"data": ["I_CheckComment_GET", 1826, 0, 0.0, 1.753559693318729, 1, 5, 2.0, 3.0, 4.0, 5.977458499873969, 24.00462879135691, 2.5159029428180477], "isController": false}, {"data": ["II_GuestBook_GET", 16, 0, 0.0, 2.3125, 1, 7, 4.900000000000002, 7.0, 7.0, 0.05327703726395775, 0.21394060276308033, 0.0214356829616705], "isController": false}, {"data": ["I_SendCommentServiceGuestBook_POST", 1826, 102, 5.585980284775466, 5.363088718510419, 1, 116, 9.299999999999955, 19.649999999999864, 47.0, 5.976245569363396, 1.8692163674589173, 3.01159853625349], "isController": false}, {"data": ["I_HomePage", 1827, 0, 0.0, 2.320744389709908, 1, 167, 3.0, 3.0, 4.0, 5.974395448079659, 132.02098636181555, 2.1295452524893315], "isController": true}, {"data": ["I_GuestBook", 1826, 0, 0.0, 1.6549835706462241, 1, 5, 2.0, 2.0, 4.0, 5.976186891662794, 23.998489844818785, 2.4044814446924523], "isController": true}, {"data": ["II_GuestBook", 16, 0, 0.0, 2.3125, 1, 7, 4.900000000000002, 7.0, 7.0, 0.05327703726395775, 0.21394060276308033, 0.0214356829616705], "isController": true}, {"data": ["I_CheckComment", 1826, 102, 5.585980284775466, 4.65607886089813, 2, 23, 8.0, 9.649999999999864, 14.0, 5.977458499873969, 42.705723463570564, 4.483093874905477], "isController": true}, {"data": ["I_GuestBook_GET", 1826, 0, 0.0, 1.6549835706462241, 1, 5, 2.0, 2.0, 4.0, 5.976186891662794, 23.998489844818785, 2.4044814446924523], "isController": false}]}, function(index, item){
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
    createTable($("#errorsTable"), {"supportsControllersDiscrimination": false, "titles": ["Type of error", "Number of errors", "% in errors", "% in all samples"], "items": [{"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Sierra\'&lt;br&gt;\\\/", 9, 4.411764705882353, 0.0700552658208142], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'India\'&lt;br&gt;\\\/", 4, 1.9607843137254901, 0.031135673698139642], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Papa\'&lt;br&gt;\\\/", 6, 2.9411764705882355, 0.04670351054720946], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Echo\'&lt;br&gt;\\\/", 4, 1.9607843137254901, 0.031135673698139642], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Romeo\'&lt;br&gt;\\\/", 3, 1.4705882352941178, 0.02335175527360473], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Delta\'&lt;br&gt;\\\/", 3, 1.4705882352941178, 0.02335175527360473], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'November\'&lt;br&gt;\\\/", 4, 1.9607843137254901, 0.031135673698139642], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Bravo\'&lt;br&gt;\\\/", 1, 0.49019607843137253, 0.007783918424534911], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Victor\'&lt;br&gt;\\\/", 7, 3.4313725490196076, 0.05448742897174438], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Charlie\'&lt;br&gt;\\\/", 2, 0.9803921568627451, 0.015567836849069821], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Mike\'&lt;br&gt;\\\/", 5, 2.450980392156863, 0.038919592122674554], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Golf\'&lt;br&gt;\\\/", 3, 1.4705882352941178, 0.02335175527360473], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Lima\'&lt;br&gt;\\\/", 7, 3.4313725490196076, 0.05448742897174438], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Alpha\'&lt;br&gt;\\\/", 3, 1.4705882352941178, 0.02335175527360473], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Foxtrot\'&lt;br&gt;\\\/", 4, 1.9607843137254901, 0.031135673698139642], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'X-Ray\'&lt;br&gt;\\\/", 4, 1.9607843137254901, 0.031135673698139642], "isController": false}, {"data": ["Response was null", 2, 0.9803921568627451, 0.015567836849069821], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Juliett\'&lt;br&gt;\\\/", 3, 1.4705882352941178, 0.02335175527360473], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Hotel\'&lt;br&gt;\\\/", 3, 1.4705882352941178, 0.02335175527360473], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Yankee\'&lt;br&gt;\\\/", 4, 1.9607843137254901, 0.031135673698139642], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Whiskey\'&lt;br&gt;\\\/", 4, 1.9607843137254901, 0.031135673698139642], "isController": false}, {"data": ["500", 102, 50.0, 0.793959679302561], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Quebec\'&lt;br&gt;\\\/", 3, 1.4705882352941178, 0.02335175527360473], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Tango\'&lt;br&gt;\\\/", 4, 1.9607843137254901, 0.031135673698139642], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Zulu\'&lt;br&gt;\\\/", 3, 1.4705882352941178, 0.02335175527360473], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Kilo\'&lt;br&gt;\\\/", 5, 2.450980392156863, 0.038919592122674554], "isController": false}, {"data": ["Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Uniform\'&lt;br&gt;\\\/", 2, 0.9803921568627451, 0.015567836849069821], "isController": false}]}, function(index, item){
        switch(index){
            case 2:
            case 3:
                item = item.toFixed(2) + '%';
                break;
        }
        return item;
    }, [[1, 1]]);

        // Create top5 errors by sampler
    createTable($("#top5ErrorsBySamplerTable"), {"supportsControllersDiscrimination": false, "overall": {"data": ["Total", 12847, 204, "500", 102, "Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Sierra\'&lt;br&gt;\\\/", 9, "Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Victor\'&lt;br&gt;\\\/", 7, "Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Lima\'&lt;br&gt;\\\/", 7, "Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Papa\'&lt;br&gt;\\\/", 6], "isController": false}, "titles": ["Sample", "#Samples", "#Errors", "Error", "#Errors", "Error", "#Errors", "Error", "#Errors", "Error", "#Errors", "Error", "#Errors"], "items": [{"data": [], "isController": false}, {"data": [], "isController": false}, {"data": [], "isController": false}, {"data": [], "isController": false}, {"data": [], "isController": false}, {"data": [], "isController": false}, {"data": ["I_CheckCommentServiceGuestBook_GET", 1826, 102, "Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Sierra\'&lt;br&gt;\\\/", 9, "Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Victor\'&lt;br&gt;\\\/", 7, "Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Lima\'&lt;br&gt;\\\/", 7, "Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Papa\'&lt;br&gt;\\\/", 6, "Test failed: text expected to contain \\\/&lt;b&gt;&quot;\\u0426\\u0435\\u043D\\u0442\\u0440\\u0430\\u043B\\u044C\\u043D\\u044B\\u0439 \\u0431\\u0430\\u043D\\u043A \\u0420\\u043E\\u0441\\u0441\\u0438\\u0439\\u0441\\u043A\\u043E\\u0439 \\u0424\\u0435\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438&quot; &lt;\\\/b&gt;: \'Mike\'&lt;br&gt;\\\/", 5], "isController": false}, {"data": [], "isController": false}, {"data": [], "isController": false}, {"data": [], "isController": false}, {"data": [], "isController": false}, {"data": [], "isController": false}, {"data": [], "isController": false}, {"data": ["I_SendCommentServiceGuestBook_POST", 1826, 102, "500", 102, null, null, null, null, null, null, null, null], "isController": false}, {"data": [], "isController": false}, {"data": [], "isController": false}, {"data": [], "isController": false}, {"data": [], "isController": false}, {"data": [], "isController": false}]}, function(index, item){
        return item;
    }, [[0, 0]], 0);

});
