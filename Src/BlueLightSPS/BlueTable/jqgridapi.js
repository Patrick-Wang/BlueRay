﻿var grids = {};
var mediator = window.external;

function setRowBgColor(gridName, rowId, r, g, b) {
    grids[gridName].setRowBgColor(rowId, r, g, b);
}

function setRowFgColor(gridName, rowId, r, g, b) {
    grids[gridName].setRowFgColor(rowId, r, g, b);
}

function showCol(gridName, id) {
    var colId = gridName + "_col_" + id;
    grids[gridName].showHideCol(colId, true);
}

function hideCol(gridName, id) {
    var colId = gridName + "_col_" + id;
    grids[gridName].showHideCol(colId, false);
}

function disableSelect(gridName, rowId) {
    return grids[gridName].disableSelect(rowId);
}

function enableSelect(gridName, rowId) {
    return grids[gridName].enableSelect(rowId);
}

function getDisabledRows(gridName) {
    return Util.stringify(grids[gridName].getDisabledRows());
}

function showGrid(gridName) {
    $("#" + gridName + "p").css("display", "");
}

function hideGrid(gridName) {
    $("#" + gridName + "p").css("display", "none");
}

function addRowData(gridName, rdata) {
    var ardata = Util.parse(rdata);
    var targetData = {};
    for (var i = 0; i < ardata.length; ++i) {
        targetData[gridName + "_col_" + i] = ardata[i];
    }
    return grids[gridName].addRowData(targetData);
}

function update(gridName, tdata) {
    var jdata = Util.parse(tdata);
    cleanSelectedRow(gridName);
    $("#" + gridName)[0].addJSONData(jdata);
}

function addRowDataById(gridName, id, rdata) {
    var ardata = Util.parse(rdata);
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
    grids[gridName].showHideRow(rowId, show == "true");
}

function getSelectedRows(gridName) {
    return Util.stringify(grids[gridName].getSelectedRowData());
}

function getRowCount(gridName) {
    return grids[gridName].getRowCount();
}

function setSelect(gridName, rowId, sel) {
    return grids[gridName].setSelect(rowId, sel);
}

function cleanSelectedRow(gridName) {
    return grids[gridName].cleanSelectedRow();
}

function delRowData(gridName, rowId) {
    grids[gridName].delRowData(rowId);
}

function reload(gridName) {
    grids[gridName].reload();
}

function getRowData(gridName, rowId) {
    var rowData = grids[gridName].getRowData(rowId);
    var count = 0;

    for (var i in rowData) {
        ++count;
    }
    var retData = [];
    for (var i = 0; i < count; ++i) {
        retData.push(rowData[gridName + "_col_" + i]);
    }

    return Util.stringify(retData);
}

function setCellData(gridName, row, col, data) {
    grids[gridName].setCellData(row, col, data + "");
}

function setWidths(gridName, strwidths) {
    var widths = Util.parse(strwidths);
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

function getWidths(gridName) {
    var widths = [];
    var colModel = $("#" + gridName).jqGrid('getGridParam', 'colModel');

    for (var i = 0; i < colModel.length; ++i) {
        widths.push(colModel[i].width);
    }
    return Util.stringify(widths);
}

function curPage(gridName) {
    return grids[gridName].getCurPage();
}

function rowNum(gridName) {
    return grids[gridName].getRowNum();
}
