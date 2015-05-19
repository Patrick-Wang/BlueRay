/// <reference path="jqgrid/jqassist.ts" />
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
        private rowNum: number = mediator.onGetRowNum();
        private curPage: number;
        mTableName: string;
        mTable: any;
        private mCols: string[];
        private mInit: boolean = false;
        private mDisabledRows: number[] = [];
        private mIsShowHideTriggered: boolean = false;
        constructor(tableId: string, cols: string[], widths : number[]) {
            this.mCols = cols;
            grids[tableId] = this;
            this.mTableName = tableId;
            this.mTable = $('#' + tableId);
            this.updateTable(tableId, widths);
        }

        private getRowNum() {
            return this.rowNum;
        }

        private getCurPage() {
            return this.curPage;
        }

        public getTableName(): string {
            return this.mTableName;
        }

        private isSelected(rowId: number): boolean {
            var rows: any = this.getSelectedRowData();
            for (var i = 0; i < rows.length; ++i) {
                if (rows[i] == rowId) {
                    return true;
                }
            }
            return false;
        }

        private isDisabled(rowId: number) : boolean {
            for (var i = 0; i < this.mDisabledRows.length; ++i) {
                if (this.mDisabledRows[i] == rowId) {
                    return true;
                }
            }
            return false;
        }

        public disableSelect(rowId: number) {
            if (this.isSelected(rowId)) {
                this.mTable.jqGrid('setSelection', rowId, false);
            }
            if (!this.isDisabled(rowId)) {
                var checkBox = $("#" + this.mTableName + " #jqg_" + this.mTableName + "_" + rowId);
                if (checkBox.length > 0) {
                    checkBox[0].disabled = true;
                }
                this.mDisabledRows.push(rowId);
            }
        }

        public enableSelect(rowId: number) {
            for (var i = 0; i < this.mDisabledRows.length; ++i) {
                if (this.mDisabledRows[i] == rowId) {
                    var tmp = this.mDisabledRows[this.mDisabledRows.length - 1];
                    this.mDisabledRows[i] = tmp;
                    this.mDisabledRows.pop();
                    var checkBox = $("#" + this.mTableName + " #jqg_" + this.mTableName + "_" + rowId);
                    if (checkBox.length > 0) {
                        checkBox[0].disabled = false;
                    }
                    break;
                }
            }
        }

        public getDisabledRows() {
            return this.mDisabledRows;
        }

        public showHideRow(rowId: number, show: boolean): void {
            if (show) {
                $("#" + this.mTableName + "p #" + rowId).css("display", "");
            }
            else {
                $("#" + this.mTableName + "p #" + rowId).css("display", "none");
            }
        }

        public setRowBgColor(row: number, r: number, g: number, b: number): void {
            $("#" + this.mTableName + " #" + row).css("background", "rgb(" + r + "," + g + "," + b + ")");
        }

        public setRowFgColor(row: number, r: number, g: number, b: number): void {
            $("#" + this.mTableName + " #" + row).css("color", "rgb(" + r + "," + g + "," + b + ")");
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
            if (this.isSelected(rowId)) {
                this.mTable.jqGrid('setSelection', rowId, false);
            }
            this.mTable.jqGrid('delRowData', rowId)
        }

        public setSelect(rowId: number, sel: boolean) {
            this.mTable.jqGrid('setSelection', rowId, sel);
        }

        public cleanSelectedRow(): void {
            var rowIds : Array<string> = [].concat(this.getSelectedRowData());
            if (null != rowIds) {
                //alert(rowIds);
                for (var id in rowIds) {
                    this.mTable.jqGrid('setSelection', rowIds[id], false);
                }
            }
        }

        public getRowData(rowId: number): void {
            return this.mTable.jqGrid('getRowData', rowId);
        }

        public getSelectedRowData(): Array<string> {
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
            this.mIsShowHideTriggered = true;
            if (show) {
                $("#" + this.mTableName).setGridParam().showCol(colId);
            }
            else {
                $("#" + this.mTableName).setGridParam().hideCol(colId);
            }
            this.mIsShowHideTriggered = false;
        }

        private updateTable(name: string, widths : number[]): void {
            var tableAssist: JQTable.JQGridAssistant = JQGridAssistantFactory.createTable(name, this.mCols, widths);
            var data = [];

            this.mTable.jqGrid(
                tableAssist.decorate({
                    // url: "TestTable/WGDD_load.do",
                    // datatype: "json",
                    //data: tableAssist.getData(data),
                    // datatype: "json",
                    datatype: (postdata) => {
                        //page: 1
                        //rows: 200
                        //sidx: "sale_col_2"
                        //sord: "asc"
                        //$('#' + name)[0].addJSONData(Util.parse('{' +
                        //    'total: 12, ' +
                        //    'page: 1, ' +
                        //    'records: 2000,' +
                        //    'rows : [' +
                        //    ' { id: "1", cell: ["cell11", "cell12", "cell13"] }, ' +
                        //    '{ id: "2", cell: ["cell21", "cell22", "cell23"] } ' +
                        //    ' ]' +
                        //    '}'));
                        try {
                            this.rowNum = postdata.rows;
                            this.curPage = postdata.page;
                            if (!this.mInit) {
                                this.mInit = true;
                                this.cleanSelectedRow();
                                mediator.onGridComplete(this.mTableName);
                            } else if (!this.mIsShowHideTriggered){
                                var index = -1;
                                if ("" != postdata.sidx) {
                                    index = parseInt(postdata.sidx.replace(name + "_col_", ""));
                                }
                                //alert("onupdate");
                                this.cleanSelectedRow();
                                mediator.onUpdate(this.mTableName, postdata.page, postdata.rows, index, ("asc" == postdata.sord));
                            }
                        }
                        catch (e) {
                        }

                    },
                    //onPaging: (v1, v2, v3) => {
                    //    var k = 0;
                    //},
                    multiselect: true,
                    //multikey: "ctrlKey",
                    //drag: false,
                    // resize: false,
                    // autowidth : true,
                    //cellsubmit: 'clientArray',
                    // cellEdit: false,
                    //viewrecords: true,
                    sortorder: "desc",
                    height: document.documentElement.clientHeight - 22 - 3 - 27,
                    width: document.documentElement.clientWidth - 3,
                    shrinkToFit: false,
                    rowNum: this.rowNum,
                    //rowList: [5, 10, 15],
                    autoScroll: true,
                    viewrecords: true,
                    pager: name + 'pager',
                    beforeSelectRow: (rowId) => {
                        return !this.isDisabled(rowId);
                    },
                    onSelectRow: (a, b, c) => {
                       mediator.onRowChecked(this.mTableName);
                    },
                    onSelectAll: (a, b, c) => {
                       mediator.onRowChecked(this.mTableName);
                    },
                    gridComplete: () => {

                    }
                }));
            var exporteId = name + "_export";
            this.mTable
                .jqGrid('navGrid', "#" + name + 'pager', { search: false, refresh: false, edit: false, add: false, del: false })
                .jqGrid('navButtonAdd', "#" + name + 'pager', {
                    caption: "", buttonicon: "none", onClickButton: () => {
                        mediator.onExportClicked(this.mTableName);
                    }, position: "last", title: "按表格导出数据", id: exporteId
                });
            this.reload();
           
            $("#" + exporteId + " div").addClass("ui-icon");
            $("#" + exporteId + " div").addClass("ui-icon-circle-arrow-s");
            $("#" + name + "pager_left").css("padding-top", "3px");
           
                //.navGrid('#pager', { search: false, reloadGrid: false, edit: false, add: false, del: false });
        }
    }
}