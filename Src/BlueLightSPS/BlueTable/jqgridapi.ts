/// <reference path="base.ts" />
/// <reference path="util.ts" />
//var instance: base.GridView;
var grids = {}
var mediator: any = window.external;

function cancelSort(gridName: string) {
    $(".s-ico").hide();
}

function setRowBgColor(gridName: string, rowId: number, r: number, g: number, b: number) {
    grids[gridName].setRowBgColor(rowId, r, g, b);
}

function setRowFgColor(gridName: string, rowId: number, r: number, g: number, b: number) {
    grids[gridName].setRowFgColor(rowId, r, g, b);
}

function setCellColor(gridName: string, rowId: number, colId: number, r: number, g: number, b: number) {
    var colIdInternal: string = gridName + "_col_" + colId;
   // alert(colIdInternal);
    grids[gridName].setCellColor(rowId, colIdInternal, r, g, b);
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
    return Util.stringify(grids[gridName].getDisabledRows());
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
    var ardata: string[] = Util.parse(rdata);
    var targetData = {};
    for (var i = 0; i < ardata.length; ++i) {
        targetData[gridName + "_col_" + i] = ardata[i];
    }
    return grids[gridName].addRowData(targetData);
}

function update(gridName: string, tdata: string) {
    var jdata = Util.parse(tdata);
    cleanSelectedRow(gridName);
    $("#" + gridName)[0].addJSONData(jdata);
}

function addRowDataById(gridName: string, id: number, rdata: string) : void{
    var ardata: string[] = Util.parse(rdata);
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
    return Util.stringify(grids[gridName].getSelectedRowData());
}

function getRowCount(gridName: string) {
    return grids[gridName].getRowCount();
}

function setSelect(gridName: string, rowId: number, sel: boolean) {
    return grids[gridName].setSelect(rowId, sel);
}

function cleanSelectedRow(gridName: string): void {
    return grids[gridName].cleanSelectedRow();
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
    var rowData = grids[gridName].getRowData(rowId);
    var count = 0;
    //alert(rowData);
    for (var i in rowData) {
        ++count;
    }
    var retData = [];
    for (var i : any = 0; i < count; ++i) {
        retData.push(rowData[gridName + "_col_" + i]);
    }
    //alert(retData);
    return Util.stringify(retData);
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
    return Util.stringify(widths);
}

function curPage(gridName: string) {
    return grids[gridName].getCurPage();
}

function rowNum(gridName: string) {
    return grids[gridName].getRowNum();
}