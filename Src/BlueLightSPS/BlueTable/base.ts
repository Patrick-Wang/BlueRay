﻿/// <reference path="jqgrid/jqassist.ts" />
/// <reference path="util.ts" />
declare var grids: {};
declare var mediator;

module base {

    class JQGridAssistantFactory {

        public static createTable(gridName: string, cols: string[], widths : number[]): JQTable.JQGridAssistant {
            var nodes: JQTable.Node[] = [];
            for (var i = 0; i < cols.length; ++i) {
                nodes.push(new JQTable.Node(cols[i], gridName + "_col_" + i, true, true, widths[i]));
            }
            return new JQTable.JQGridAssistant(nodes, gridName);
        }
    }

    export class GridView {

        private mTableName: string;
        private mTable: any;
        private mCols: string[];
        constructor(tableId: string, cols: string[], widths : number[]) {
            this.mCols = cols;
            grids[tableId] = this;
            this.mTableName = tableId;
            this.mTable = $('#' + tableId);
            this.updateTable(tableId, widths);
        }

        public getTableName(): string {
            return this.mTableName;
        }

        public showHideRow(rowId: number, show: boolean): void {
            if (show) {
                $("#" + this.mTableName + "p #" + rowId).css("display", "");
            }
            else {
                $("#" + this.mTableName + "p #" + rowId).css("display", "none");
            }
        }

        public getRowId(row: number): number {
            var ids = this.mTable.jqGrid('getDataIDs');
            if (ids.length <= row) {
                return -1;
            }
            return parseInt(ids[row]);
        }

        public addRowData(rdata: any): number {
            var ids = this.mTable.jqGrid('getDataIDs');
            var rowid = 0;
            if (ids != "") {
                rowid = parseInt(Math.max.apply(Math, ids)) + 1;
            }
            this.mTable.jqGrid('addRowData', rowid, rdata, 'last');
            return rowid;
        }

        public addRowDataById(id: number, rdata: any) {
            this.mTable.jqGrid('addRowData', id, rdata, 'last');
        }

        public delRowData(rowId: number): void {
            this.mTable.jqGrid('setSelection', rowId, false);
            this.mTable.jqGrid('delRowData', rowId)
        }

        public getRowData(rowId: number): void {
            return this.mTable.jqGrid('getRowData', rowId);
        }


        public getSelectedRowData(): void {
            return this.mTable.jqGrid('getGridParam', 'selarrrow');
        }

        public getRowCount(): number {
            return this.mTable.jqGrid("getRowData").length;
        }

        public setCellData(rowId, colId, data): void {
            this.mTable.jqGrid('setCell', rowId, colId, data, undefined, undefined, true);
        }

        public reload() {
            this.mTable.trigger("reloadGrid");
        }

        public showHideCol(colId: string, show: boolean) {
            if (show) {
                $("#" + this.mTableName).setGridParam().showCol(colId).trigger("reloadGrid");
            }
            else {
                $("#" + this.mTableName).setGridParam().hideCol(colId).trigger("reloadGrid");
            }

        }

        private updateTable(name: string, widths : number[]): void {
            var tableAssist: JQTable.JQGridAssistant = JQGridAssistantFactory.createTable(name, this.mCols, widths);
            var data = [];

            $("#" + name).jqGrid(
                tableAssist.decorate({
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
                    rowNum: 10000,
                    //rowList: [5, 10, 15],
                    autoScroll: true,
                    //pager: $('#pager'),
                    onSelectRow: (a, b, c) => {
                        mediator.onRowChecked(this.mTableName);
                    },
                    onSelectAll: (a, b, c) => {
                        mediator.onRowChecked(this.mTableName);
                    },
                    gridComplete: () => {
                        mediator.onGridComplete(this.mTableName);
                    }
                }))
                //.navGrid('#pager', { search: false, reloadGrid: false, edit: false, add: false, del: false });
        }
    }
}