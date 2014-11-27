/// <reference path="base.ts" />
var instance: base.GridView;
var grids = {}
var mediator: any = window.external;


function showGrid(gridName: string) {
    $("#" + grids[gridName].getTableName() + "p").css("display", "");
    instance = grids[gridName];
    //alert("show" + instance.getTableName());
}

function hideGrid(gridName: string) {
    $("#" + grids[gridName].getTableName() + "p").css("display", "none");
    //alert("hide" + gridName);
}

function addRowData(rdata: string) {
    var ardata: string[] = rdata.split(',');
    var targetData = {};
    for (var i = 0; i < ardata.length; ++i) {
        targetData[instance.getTableName() + "_col_" + i] = ardata[i];
    }
    return instance.addRowData(targetData);
}

function addRowDataById(id: number, rdata: string) : void{
    var ardata: string[] = rdata.split(',');
    var targetData = {};
    for (var i = 0; i < ardata.length; ++i) {
        targetData[instance.getTableName() + "_col_" + i] = ardata[i];
    }
    return instance.addRowDataById(id, targetData);
}

function getRowId(rowIndex: number) {
    return instance.getRowId(rowIndex);
}

function showHideRow(rowId: number, show: string) {
    //alert(show + instance.getTableName());
    instance.showHideRow(rowId, show == "true");
}

function getSelectedRows() {
    return instance.getSelectedRowData().toString();
}

function getRowCount() {
    return instance.getRowCount();
}


function delRowData(rowId: number): void {
    //alert("delRow" + row);
    instance.delRowData(rowId);
}


function reload(): void {
    //alert("delRow" + row);
    instance.reload();
}

function getRowData(rowId: number): string {
    var rw: any = instance.getRowData(rowId);
    var ret: string = "";
    for (var i in rw) {
        ret += rw[i] + ',';
    }
    return ret.substring(0, ret.length - 1);
}

function setCellData(row: number, col: number, data: string) {
    instance.setCellData(row, col, data + "");
}
