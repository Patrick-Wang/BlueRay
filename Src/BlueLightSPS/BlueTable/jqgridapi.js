/// <reference path="base.ts" />
var instance;
var grids = {};
var mediator = window.external;

function showCol(id) {
    var colId = instance.getTableName() + "_col_" + id;
    instance.showHideCol(colId, true);
}

function hideCol(id) {
    var colId = instance.getTableName() + "_col_" + id;
    instance.showHideCol(colId, false);
}

function showGrid(gridName) {
    $("#" + grids[gridName].getTableName() + "p").css("display", "");
    instance = grids[gridName];
    //alert("show" + instance.getTableName());
}

function hideGrid(gridName) {
    $("#" + grids[gridName].getTableName() + "p").css("display", "none");
    //alert("hide" + gridName);
}

function addRowData(rdata) {
    var ardata = rdata.split(',');
    var targetData = {};
    for (var i = 0; i < ardata.length; ++i) {
        targetData[instance.getTableName() + "_col_" + i] = ardata[i];
    }
    return instance.addRowData(targetData);
}

function addRowDataById(id, rdata) {
    var ardata = rdata.split(',');
    var targetData = {};
    for (var i = 0; i < ardata.length; ++i) {
        targetData[instance.getTableName() + "_col_" + i] = ardata[i];
    }
    return instance.addRowDataById(id, targetData);
}

function getRowId(rowIndex) {
    return instance.getRowId(rowIndex);
}

function showHideRow(rowId, show) {
    //alert(show + instance.getTableName());
    instance.showHideRow(rowId, show == "true");
}

function getSelectedRows() {
    return instance.getSelectedRowData().toString();
}

function getRowCount() {
    return instance.getRowCount();
}

function delRowData(rowId) {
    //alert("delRow" + row);
    instance.delRowData(rowId);
}

function reload() {
    //alert("delRow" + row);
    instance.reload();
}

function getRowData(rowId) {
    var rw = instance.getRowData(rowId);
    var ret = "";
    for (var i in rw) {
        ret += rw[i] + ',';
    }
    return ret.substring(0, ret.length - 1);
}

function setCellData(row, col, data) {
    instance.setCellData(row, col, data + "");
}
//# sourceMappingURL=jqgridapi.js.map
