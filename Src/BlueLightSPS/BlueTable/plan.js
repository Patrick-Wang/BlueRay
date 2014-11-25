﻿/// <reference path="jqgrid/jqassist.ts" />
/// <reference path="util.ts" />

var plan;
(function (plan) {
    var JQGridAssistantFactory = (function () {
        function JQGridAssistantFactory() {
        }
        JQGridAssistantFactory.createTable = function (gridName) {
            var cols = ["合同号", "客户名称", "规格型号", "数量", "轴承", "单复绕", "制动器电压", "曳引轮规格", "机房", "变频器型号", "编码器型号", "电缆长度", "闸线长度", "铭牌等资料", "备注", "订单日期", "生产日期", "计划审核-业务", "计划审核-计划", "包装日期", "包装审核-业务", "包装审核-计划", "发货日期", "投产编号", "出厂编号"];
            var nodes = [];
            for (var i = 0; i < cols.length; ++i) {
                nodes.push(new JQTable.Node(cols[i], gridName + "_col_" + i));
            }
            return new JQTable.JQGridAssistant(nodes, gridName);
        };
        return JQGridAssistantFactory;
    })();

    var View = (function () {
        function View() {
        }
        View.newInstance = function () {
            if (View.ins == undefined) {
                View.ins = new View();
            }
            return View.ins;
        };

        View.prototype.init = function (tableId) {
            grids[tableId] = this;
            this.mTableName = tableId;
            this.mTable = $('#' + tableId);
            this.updateTable(tableId);
        };

        View.prototype.getTableName = function () {
            return this.mTableName;
        };

        View.prototype.showHideRow = function (rowId, show) {
            if (show) {
                $("#" + rowId).css("display", "");
            } else {
                $("#" + rowId).css("display", "none");
            }
        };

        View.prototype.getRowId = function (row) {
            var ids = this.mTable.jqGrid('getDataIDs');
            if (ids.length <= row) {
                return -1;
            }
            return parseInt(ids[row]);
        };

        View.prototype.addRowData = function (rdata) {
            var ids = this.mTable.jqGrid('getDataIDs');

            //获得当前最大行号（数据编号）
            //alert("add " + rdata);
            var rowid = 0;
            if (ids != "") {
                rowid = parseInt(Math.max.apply(Math, ids)) + 1;
            }

            // alert(rowid);
            this.mTable.jqGrid('addRowData', rowid, rdata, 'last');
            return rowid;
        };
        View.prototype.delRowData = function (rowId) {
            this.mTable.jqGrid('setSelection', rowId, false);
            this.mTable.jqGrid('delRowData', rowId);
        };

        View.prototype.getRowData = function (rowId) {
            //var cur = table.jqGrid('getGridParam', "selrow");
            return this.mTable.jqGrid('getRowData', rowId);
        };

        View.prototype.getSelectedRowData = function () {
            return this.mTable.jqGrid('getGridParam', 'selarrrow');
        };

        View.prototype.getRowCount = function () {
            return this.mTable.jqGrid("getRowData").length;
        };

        View.prototype.setCellData = function (rowId, colId, data) {
            this.mTable.jqGrid('setCell', rowId, colId, data);
        };

        View.prototype.reload = function () {
            this.mTable.trigger("reloadGrid");
        };

        View.prototype.updateTable = function (name) {
            var tableAssist = JQGridAssistantFactory.createTable(name);

            // tableAssist.mergeTitle();
            //tableAssist.mergeRow(0);
            //   tableAssist.mergeColum(0, 4);
            //   tableAssist.mergeColum(0, 5);
            //   tableAssist.mergeColum(0, 6);
            //   tableAssist.mergeColum(0, 7);
            //   tableAssist.mergeColum(0, 8);
            var data = [];

            $("#" + name).jqGrid(tableAssist.decorate({
                // url: "TestTable/WGDD_load.do",
                // datatype: "json",
                data: tableAssist.getData(data),
                datatype: "local",
                multiselect: true,
                //multikey: "ctrlKey",
                //drag: false,
                // resize: false,
                // autowidth : true,
                //cellsubmit: 'clientArray',
                // cellEdit: false,
                //viewrecords: true,
                sortorder: "desc",
                height: document.documentElement.clientHeight - 22 - 3,
                width: document.documentElement.clientWidth - 3,
                shrinkToFit: false,
                //rowNum: 5,
                //rowList: [5, 10, 15],
                autoScroll: true,
                //pager: $('#pager'),
                onSelectRow: function (a, b, c) {
                    mediator.onRowChecked();
                },
                onSelectAll: function (a, b, c) {
                    mediator.onRowChecked();
                },
                gridComplete: function () {
                    mediator.onGridComplete();
                }
            }));
            //.navGrid('#pager', { search: false, reloadGrid: false, edit: false, add: false, del: false });
        };
        return View;
    })();
    plan.View = View;
})(plan || (plan = {}));
//# sourceMappingURL=plan.js.map
