/// <reference path="jqgrid/jqassist.ts" />
/// <reference path="util.ts" />
declare var echarts;
declare var instance;
declare var grids: {};
declare var mediator;

module plan {

    class JQGridAssistantFactory {

        public static createSaleTable(gridName: string): JQTable.JQGridAssistant {
            var cols = ["合同号", "客户名称", "规格型号", "数量", "轴承", "单复绕", "制动器电压", "曳引轮规格", "机房", "变频器型号", "编码器型号", "电缆长度", "闸线长度", "铭牌等资料", "备注", "订单日期", "审核-业务", "审核-计划"];
            var nodes: JQTable.Node[] = [];
            for (var i = 0; i < cols.length; ++i) {
                nodes.push(new JQTable.Node(cols[i], gridName + "_col_" + i));
            }
            return new JQTable.JQGridAssistant(nodes, gridName);
        }
    }

    export class View {
        private static ins: View;

        public static newInstance(): View {
            if (View.ins == undefined) {
                View.ins = new View();
            }
            return View.ins;
        }

        private mTableName: string;
        private mTable: any;
        public init(tableId: string): void {
            grids[tableId] = this;
            this.mTableName = tableId;
            this.mTable = $('#' + tableId);
            this.updateTable(tableId);   
                     
        }

        public getTableName() : string{
            return this.mTableName;
        }

        public showHideRow(rowId: number, show: boolean): void {
            if (show) {
                $("#" + rowId).css("display", "");
            }
            else {
                $("#" + rowId).css("display", "none");
            }
        }

        public getRowId(row: number) : number {
            var ids = this.mTable.jqGrid('getDataIDs');
            if (ids.length <= row) {
                return -1;
            }
            return parseInt(ids[row]);
        }

        public addRowData(rdata: any): number{
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
        }
        public delRowData(rowId: number): void {
            this.mTable.jqGrid('setSelection', rowId, false);
            this.mTable.jqGrid('delRowData', rowId)
        }
  
        public getRowData(rowId: number): void {
            //var cur = table.jqGrid('getGridParam', "selrow");
            return this.mTable.jqGrid('getRowData', rowId);
        }
        

        public getSelectedRowData(): void {
            return this.mTable.jqGrid('getGridParam', 'selarrrow');
        }

        public getRowCount(): number {
            return this.mTable.jqGrid("getRowData").length;
        }
        
        public setCellData(rowId, colId, data): void {
            this.mTable.jqGrid('setCell', rowId, colId, data);
        }

        public reload() {
            this.mTable.trigger("reloadGrid");
        }

        private updateTable(name: string): void {
            var tableAssist: JQTable.JQGridAssistant = JQGridAssistantFactory.createSaleTable(name);
            // tableAssist.mergeTitle();
         
            //tableAssist.mergeRow(0);
	        //   tableAssist.mergeColum(0, 4);
	        //   tableAssist.mergeColum(0, 5);
	        //   tableAssist.mergeColum(0, 6);
	        //   tableAssist.mergeColum(0, 7);
	        //   tableAssist.mergeColum(0, 8);
            var data = [];

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
                    //rowNum: 5,
                    //rowList: [5, 10, 15],
                    autoScroll: true,
                    //pager: $('#pager'),
                    onSelectRow: (a, b, c) => {
                        mediator.onRowChecked();
                    },
                    onSelectAll: (a, b, c) => {
                        mediator.onRowChecked();
                    },
                    gridComplete: () => {
                        mediator.onGridComplete();
                    }
                }))
                //.navGrid('#pager', { search: false, reloadGrid: false, edit: false, add: false, del: false });
        }
    }
}