﻿/// <reference path="jqgrid/jqassist.ts" />
/// <reference path="util.ts" />

function testCall(arg) {
    alert(arg);
}

var cqk;
(function (cqk) {
    var JQGridAssistantFactory = (function () {
        function JQGridAssistantFactory() {
        }
        JQGridAssistantFactory.createTable = function (gridName, year) {
            return new JQTable.JQGridAssistant([
                new JQTable.Node("订单日期", "ddrq"),
                new JQTable.Node("合同号", "ID"),
                new JQTable.Node("客户ID", "clientID"),
                new JQTable.Node("规格型号ID", "ggxhID"),
                new JQTable.Node("数量", "sl"),
                new JQTable.Node("轴承ID", "zcID"),
                new JQTable.Node("单复绕", "dfr"),
                new JQTable.Node("制动器电压ID", "zdqdyID"),
                new JQTable.Node("曳引轮规格ID", "yylggID"),
                new JQTable.Node("是否机房", "sfjf"),
                new JQTable.Node("变频器型号ID", "bpqxhID"),
                new JQTable.Node("编码器型号ID", "bmqxhID"),
                new JQTable.Node("电缆长度", "dlcd"),
                new JQTable.Node("闸线长度", "zxcd"),
                new JQTable.Node("铭牌等资料", "mpzl"),
                new JQTable.Node("备注", "bz")
            ], gridName);
        };
        return JQGridAssistantFactory;
    })();

    var View = (function () {
        function View() {
            this.currentSelected = 0;
        }
        View.newInstance = function () {
            if (View.ins == undefined) {
                View.ins = new View();
            }
            return View.ins;
        };

        View.prototype.init = function (echartIdPie, echartIdSquire, echartIdLine, tableId, args) {
            //this.mMonth = args[0];
            //this.mYear = args[1];
            //this.mLineData = args[2];
            //this.mTableData = args[3];
            this.mEchartIdLine = echartIdLine;
            this.mEchartIdPie = echartIdPie;
            this.mEchartIdSquire = echartIdSquire;
            this.updateTable(tableId);
            window.external.ready("first arg from js", "sec arg from js");
            //this.updatePieEchart(this.mEchartIdPie);
            //this.updateLineEchart(this.mEchartIdLine);
            //this.updateSquareEchart(this.mEchartIdSquire);
        };

        View.prototype.onSelected = function (i) {
            this.currentSelected = i;
            this.updateLineEchart(this.mEchartIdLine);
            this.updateSquareEchart(this.mEchartIdSquire);
        };

        View.prototype.updateSquareEchart = function (echart) {
            var data = [];
            var month = [];
            if (data == null) {
                data = [];
                data.push([]);
                data.push([]);
                data.push([]);
                for (var i = 1; i <= this.mMonth; ++i) {
                    month.push(i + "月");
                    data[0].push(Math.floor(Math.random() * (1000 + 1)) + "");
                    data[1].push(Math.floor(Math.random() * (1000 + 1)) + "");
                    data[2].push(Math.floor(Math.random() * (1000 + 1)) + "");
                }
            } else {
                data.push(this.mLineData[this.currentSelected * 5 + 2]);
                data.push(this.mLineData[this.currentSelected * 5 + 3]);
                data.push(this.mLineData[this.currentSelected * 5 + 4]);
                for (var i = 1; i <= this.mMonth; ++i) {
                    month.push(i + "月");
                }
            }

            var legend = ["陈欠4年及以上", "陈欠3年", "陈欠2年"];
            var ser = [];
            for (var i = 0; i < legend.length; ++i) {
                ser.push({
                    name: legend[i],
                    type: 'line',
                    smooth: true,
                    stack: "金额",
                    itemStyle: { normal: { areaStyle: { type: 'default' } } },
                    data: data[i]
                });
            }

            var option = {
                title: {
                    text: '行业陈欠款趋势'
                },
                tooltip: {
                    trigger: 'axis'
                },
                legend: {
                    data: legend
                },
                toolbox: {
                    show: true
                },
                calculable: false,
                xAxis: [
                    {
                        type: 'category',
                        boundaryGap: false,
                        data: month
                    }
                ],
                yAxis: [
                    {
                        type: 'value'
                    }
                ],
                series: ser
            };

            echarts.init($('#' + echart)[0]).setOption(option);
        };

        View.prototype.updateLineEchart = function (echart) {
            var data = [];
            var month = [];
            if (data == null) {
                data = [];
                data.push([]);
                data.push([]);

                for (var i = 1; i <= this.mMonth; ++i) {
                    month.push(i + "月");
                    data[0].push(Math.floor(Math.random() * (1000 + 1)) + "");
                    data[1].push(Math.floor(Math.random() * (1000 + 1)) + "");
                }
            } else {
                data.push(this.mLineData[this.currentSelected * 5]);
                data.push(this.mLineData[this.currentSelected * 5 + 1]);
                for (var i = 1; i <= this.mMonth; ++i) {
                    month.push(i + "月");
                }
            }
            var legend = [this.mYear - 1 + "年", this.mYear + "年"];

            //var chart: ECharts.Chart = new ECharts.Chart(new ECharts.XAxis(month), new ECharts.YAxis());
            // chart.setLegend(new ECharts.Legend([this.mYear - 1 + "年", this.mYear + "年"], ECharts.LegendX.center));
            //var ser: ECharts.Line.SeriesImpl = new ECharts.Line.SeriesImpl(this.mYear - 1 + '年', data[0]);
            //chart.addSeries(ser);
            //ser = new ECharts.Line.SeriesImpl(this.mYear + '年', data[1]);
            //chart.addSeries(ser);
            //chart.update(echart);
            var ser = [];
            for (var i = 0; i < legend.length; ++i) {
                ser.push({
                    name: legend[i],
                    type: 'line',
                    smooth: true,
                    data: data[i]
                });
            }

            var option = {
                title: {
                    text: '行业陈欠款同期对比'
                },
                tooltip: {
                    trigger: 'axis'
                },
                legend: {
                    data: legend
                },
                toolbox: {
                    show: true
                },
                calculable: false,
                xAxis: [
                    {
                        type: 'category',
                        boundaryGap: false,
                        data: month
                    }
                ],
                yAxis: [
                    {
                        type: 'value'
                    }
                ],
                series: ser
            };

            echarts.init($('#' + echart)[0]).setOption(option);
        };
        View.prototype.updatePieEchart = function (echart) {
            var data = this.mTableData;

            var legend = ["国网、南网", "省、市电力公司", "五大发电", "其他电源", "石油石化", "轨道交通", "出口合同", "其他"];
            var dljpt = 0;
            for (var i = 0; i < 4; ++i) {
                dljpt += parseInt(this.mTableData[i][3]);
            }
            var dataIn = [
                { name: "电力 \r\n及配套", value: dljpt },
                { name: "", value: parseInt(this.mTableData[4][3]) },
                { name: " ", value: parseInt(this.mTableData[5][3]) },
                { name: "  ", value: parseInt(this.mTableData[6][3]) },
                { name: "   ", value: parseInt(this.mTableData[7][3]) }
            ];

            //            var dataIn = [
            //                { name: " 电力 \r\n及配套", value: Math.random() * (1000 + 1) },
            //                { name: "石油\r\n石化", value: Math.random() * (1000 + 1) },
            //                { name: "制造\r\n行业", value: Math.random() * (1000 + 1) },
            //                { name: "    铁路    \r\n（轨道交通）", value: Math.random() * (1000 + 1) },
            //                { name: " 出口\r\n合同", value: Math.random() * (1000 + 1) },
            //                { name: "其它", value: Math.random() * (1000 + 1) }
            //            ];
            var dataOut = [];
            for (var i = 0; i < legend.length; ++i) {
                //dataOut.push({ name: legend[i], value: Math.random() * (1000 + 1) });
                dataOut.push({ name: legend[i], value: this.mTableData[i][3] });
            }

            //var dataIn = [{ name: "  电力\r\n及配套", value: Math.random() * (1000 + 1) },
            //    { name: "出口\r\n合同", value: Math.random() * (1000 + 1) },
            //    { name: "其它", value: Math.random() * (1000 + 1) }];
            var option = {
                title: {
                    text: '行业占比'
                },
                tooltip: {
                    trigger: 'axis'
                },
                legend: {
                    x: "left",
                    y: '40',
                    data: legend,
                    orient: "vertical"
                },
                toolbox: {
                    show: true
                },
                calculable: false,
                series: [
                    {
                        name: "1",
                        type: 'pie',
                        radius: [100, 130],
                        data: dataOut
                    }, {
                        name: "2",
                        type: 'pie',
                        radius: [0, 60],
                        itemStyle: {
                            normal: {
                                label: {
                                    position: 'inner'
                                },
                                labelLine: {
                                    show: false
                                }
                            }
                        },
                        data: dataIn
                    }
                ]
            };

            echarts.init($('#' + echart)[0]).setOption(option);
        };

        View.prototype.updateTable = function (name) {
            var tableAssist = JQGridAssistantFactory.createTable(name, this.mYear);
            tableAssist.mergeTitle();

            //tableAssist.mergeRow(0);
            //   tableAssist.mergeColum(0, 4);
            //   tableAssist.mergeColum(0, 5);
            //   tableAssist.mergeColum(0, 6);
            //   tableAssist.mergeColum(0, 7);
            //   tableAssist.mergeColum(0, 8);
            var data = [
                ["电力及配套", "国网、南网"],
                ["电力及配套", "省、市电力系统"],
                ["电力及配套", "五大发电"],
                ["电力及配套", "其它"],
                ["石油", "石化"],
                ["轨道", "交通"],
                ["出口", "合同"],
                ["其", "他"],
                ["合", "计"]
            ];

            //			for (var i = 0; i < data.length; ++i){
            //				data[i] = data[i].concat(this.mTableData[i]);
            //			}
            //var row = [];
            //for (var i = 0; i < data.length; ++i) {
            //    row = [].concat(this.mTableData[i]);
            //    for (var col in row) {
            //        row[col] = Util.formatCurrency(row[col]);
            //    }
            //    data[i] = data[i].concat(row);
            //}
            $("#" + name).jqGrid(tableAssist.decorate({
                // url: "TestTable/WGDD_load.do",
                // datatype: "json",
                data: tableAssist.getData(data),
                datatype: "local",
                multiselect: false,
                drag: false,
                resize: false,
                //autowidth : false,
                cellsubmit: 'clientArray',
                cellEdit: true,
                height: document.documentElement.clientHeight - 22 - 3,
                width: document.documentElement.clientWidth - 3,
                shrinkToFit: false,
                autoScroll: true
            }));
        };
        return View;
    })();
    cqk.View = View;
})(cqk || (cqk = {}));
//# sourceMappingURL=cqk.js.map
