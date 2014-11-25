/// <reference path="jqgrid/jqassist.ts" />
/// <reference path="util.ts" />

var base;
(function (base) {
    var JQGridAssistantFactory = (function () {
        function JQGridAssistantFactory() {
        }
        JQGridAssistantFactory.createTable = function (gridName, cols) {
            var nodes = [];
            for (var i = 0; i < cols.length; ++i) {
                nodes.push(new JQTable.Node(cols[i], gridName + "_col_" + i));
            }
            return new JQTable.JQGridAssistant(nodes, gridName);
        };
        return JQGridAssistantFactory;
    })();

    var GridView = (function () {
        function GridView(tableId, cols) {
            this.mCols = cols;
            grids[tableId] = this;
            this.mTableName = tableId;
            this.mTable = $('#' + tableId);
            this.updateTable(tableId);
        }
        GridView.prototype.getTableName = function () {
            return this.mTableName;
        };

        GridView.prototype.showHideRow = function (rowId, show) {
            if (show) {
                $("#" + rowId).css("display", "");
            } else {
                $("#" + rowId).css("display", "none");
            }
        };

        GridView.prototype.getRowId = function (row) {
            var ids = this.mTable.jqGrid('getDataIDs');
            if (ids.length <= row) {
                return -1;
            }
            return parseInt(ids[row]);
        };

        GridView.prototype.addRowData = function (rdata) {
            var ids = this.mTable.jqGrid('getDataIDs');
            var rowid = 0;
            if (ids != "") {
                rowid = parseInt(Math.max.apply(Math, ids)) + 1;
            }
            this.mTable.jqGrid('addRowData', rowid, rdata, 'last');
            return rowid;
        };
        GridView.prototype.delRowData = function (rowId) {
            this.mTable.jqGrid('setSelection', rowId, false);
            this.mTable.jqGrid('delRowData', rowId);
        };

        GridView.prototype.getRowData = function (rowId) {
            return this.mTable.jqGrid('getRowData', rowId);
        };

        GridView.prototype.getSelectedRowData = function () {
            return this.mTable.jqGrid('getGridParam', 'selarrrow');
        };

        GridView.prototype.getRowCount = function () {
            return this.mTable.jqGrid("getRowData").length;
        };

        GridView.prototype.setCellData = function (rowId, colId, data) {
            this.mTable.jqGrid('setCell', rowId, colId, data);
        };

        GridView.prototype.reload = function () {
            this.mTable.trigger("reloadGrid");
        };

        GridView.prototype.updateTable = function (name) {
            var tableAssist = JQGridAssistantFactory.createTable(name, this.mCols);
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
        return GridView;
    })();
    base.GridView = GridView;
})(base || (base = {}));
//# sourceMappingURL=base.js.map
