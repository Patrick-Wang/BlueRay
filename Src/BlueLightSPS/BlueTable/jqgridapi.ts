/// <reference path="base.ts" />
//var instance: base.GridView;
var grids = {}
var mediator: any = window.external;

function highLightRow(gridName: string, rowId: number) {
    grids[gridName].highLightRow(rowId);
}

function showCol(gridName: string, id: string) {
    var colId: string = gridName + "_col_" + id;
    grids[gridName].showHideCol(colId, true);
}

function hideCol(gridName: string, id: string) {
    var colId: string = gridName + "_col_" + id;
    grids[gridName].showHideCol(colId, false);
}

function disableSelect(gridName: string, rowId : number) {
    return grids[gridName].disableSelect(rowId);
}

function enableSelect(gridName: string, rowId: number) {
    return grids[gridName].enableSelect(rowId);
}

function getDisabledRows(gridName: string) {
    return grids[gridName].getDisabledRows().toString();
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

function update(gridName: string, tdata: string) {
    $("#" + gridName)[0].addJSONData(Util.parse(tdata));
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

function setCellData(gridName: string, row: number, col: number, data: string) {
    grids[gridName].setCellData(row, col, data + "");
}

function setWidths(gridName: string, strwidths: string) {
    var widths: number[] = Util.parse(strwidths);
    var colModel = $("#" + gridName).jqGrid('getGridParam', 'colModel'); 
    var tds = $("#" + gridName + " .jqgfirstrow td");
    var ths = $("#" + gridName + "p .ui-jqgrid-labels th");
    for (var i = 0; i < widths.length; ++i) {
        colModel[i].width = widths[i];
        tds[i].style.width = widths[i];
        ths[i].style.width = widths[i];
    }
    grids[gridName].reload();
}

function getWidths(gridName: string) {
    var widths: number[] = [];
    var colModel = $("#" + gridName).jqGrid('getGridParam', 'colModel');
    //alert(colModel);
    for (var i = 0; i < colModel.length; ++i) {
        widths.push(colModel[i].width);
    }
    return "[" + widths + "]";
}

function curPage(gridName: string) {
    return grids[gridName].getCurPage();
}

function rowNum(gridName: string) {
    return grids[gridName].getRowNum();
}