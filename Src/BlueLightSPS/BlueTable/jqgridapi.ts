/// <reference path="base.ts" />
//var instance: base.GridView;
var grids = {}
var mediator: any = window.external;

function showCol(gridName: string, id: string) {
    var colId: string = gridName + "_col_" + id;
    grids[gridName].showHideCol(colId, true);
}

function hideCol(gridName: string, id: string) {
    var colId: string = gridName + "_col_" + id;
    grids[gridName].showHideCol(colId, false);
}

function showGrid(gridName: string) {
    $("#" + gridName + "p").css("display", "");
    //grids[gridName] = grids[gridName];
    //alert("show" + gridName);
}

function hideGrid(gridName: string) {
    $("#" + gridName + "p").css("display", "none");
    //alert("hide" + gridName);
}

function addRowData(gridName: string, rdata: string) {
    var ardata: string[] = rdata.split(',');
    var targetData = {};
    for (var i = 0; i < ardata.length; ++i) {
        targetData[gridName + "_col_" + i] = ardata[i];
    }
    return grids[gridName].addRowData(targetData);
}

function addRowDataById(gridName: string, id: number, rdata: string) : void{
    var ardata: string[] = rdata.split(',');
    var targetData = {};
    for (var i = 0; i < ardata.length; ++i) {
        targetData[gridName + "_col_" + i] = ardata[i];
    }
    return grids[gridName].addRowDataById(id, targetData);
}

function getRowId(gridName: string, rowIndex: number) {
    return grids[gridName].getRowId(rowIndex);
}

function showHideRow(gridName: string, rowId: number, show: string) {
    //alert(show + gridName);
    grids[gridName].showHideRow(rowId, show == "true");
}

function getSelectedRows(gridName: string) {
    return grids[gridName].getSelectedRowData().toString();
}

function getRowCount(gridName: string) {
    return grids[gridName].getRowCount();
}


function delRowData(gridName: string, rowId: number): void {
    //alert("delRow" + row);
    grids[gridName].delRowData(rowId);
}


function reload(gridName: string): void {
    //alert("delRow" + row);
    grids[gridName].reload();
}

function getRowData(gridName: string,rowId: number): string {
    var rw: any = grids[gridName].getRowData(rowId);
    var ret: string = "";
    for (var i in rw) {
        ret += rw[i] + ',';
    }
    return ret.substring(0, ret.length - 1);
}

function setCellData(gridName: string,row: number, col: number, data: string) {
    grids[gridName].setCellData(row, col, data + "");
}
