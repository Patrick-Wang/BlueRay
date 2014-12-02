﻿/// <reference path="base.ts" />
//var instance: base.GridView;
var grids = {};
var mediator = window.external;

function showCol(gridName, id) {
    var colId = gridName + "_col_" + id;
    grids[gridName].showHideCol(colId, true);
}

function hideCol(gridName, id) {
    var colId = gridName + "_col_" + id;
    grids[gridName].showHideCol(colId, false);
}

function showGrid(gridName) {
    $("#" + gridName + "p").css("display", "");
    //grids[gridName] = grids[gridName];
    //alert("show" + gridName);
}

function hideGrid(gridName) {
    $("#" + gridName + "p").css("display", "none");
    //alert("hide" + gridName);
}

function addRowData(gridName, rdata) {
    var ardata = rdata.split(',');
    var targetData = {};
    for (var i = 0; i < ardata.length; ++i) {
        targetData[gridName + "_col_" + i] = ardata[i];
    }
    return grids[gridName].addRowData(targetData);
}

function addRowDataById(gridName, id, rdata) {
    var ardata = rdata.split(',');
    var targetData = {};
    for (var i = 0; i < ardata.length; ++i) {
        targetData[gridName + "_col_" + i] = ardata[i];
    }
    return grids[gridName].addRowDataById(id, targetData);
}

function getRowId(gridName, rowIndex) {
    return grids[gridName].getRowId(rowIndex);
}

function showHideRow(gridName, rowId, show) {
    //alert(show + gridName);
    grids[gridName].showHideRow(rowId, show == "true");
}

function getSelectedRows(gridName) {
    return grids[gridName].getSelectedRowData().toString();
}

function getRowCount(gridName) {
    return grids[gridName].getRowCount();
}

function delRowData(gridName, rowId) {
    //alert("delRow" + row);
    grids[gridName].delRowData(rowId);
}

function reload(gridName) {
    //alert("delRow" + row);
    grids[gridName].reload();
}

function getRowData(gridName, rowId) {
    var rw = grids[gridName].getRowData(rowId);
    var ret = "";
    for (var i in rw) {
        ret += rw[i] + ',';
    }
    return ret.substring(0, ret.length - 1);
}

function setCellData(gridName, row, col, data) {
    grids[gridName].setCellData(row, col, data + "");
}
//# sourceMappingURL=jqgridapi.js.map
