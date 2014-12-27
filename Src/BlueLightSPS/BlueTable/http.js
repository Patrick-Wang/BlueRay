var mediator = window.external;
$.support.cors = true;
$.ajaxSetup({ cache: false });
function ajaxGet(caller, id, addr) {
    //alert(addr);
    $.ajax({
        url: encodeURI(addr),
        //dataType: "json",
        success: function (data) {
            //alert(data);
            mediator.onGet(caller, 1, id, data.toString());
        },
        error: function (XMLHttpRequest, textStatus, errorThrown) {
            //alert(textStatus);
            //alert(errorThrown);
            mediator.onGet(caller, 0, id);
        }
    });
}

function ajaxPost(caller, id, addr, d) {
    $.ajax({
        type: 'POST',
        url: encodeURI(addr),
        dataType: "json",
        data: d,
        success: function (retData) {
            mediator.onPost(caller, 1, id, retData.toString());
        },
        error: function (XMLHttpRequest, textStatus, errorThrown) {
            mediator.onPost(caller, 0, id);
        }
    });
}

function ajaxSyncGet(addr) {
    //alert(addr);
    var ret = 0;
    $.ajax({
        async: false,
        url: encodeURI(addr),
        //dataType: "json",
        success: function (data) {
            ret = data.toString();
        },
        error: function (XMLHttpRequest, textStatus, errorThrown) {
        }
    });
    return ret;
}

function ajaxSyncPost(addr, d) {
    var ret = 0;
    $.ajax({
        async: false,
        type: 'POST',
        url: encodeURI(addr),
        dataType: "json",
        data: d,
        success: function (retData) {
            ret = retData.toString();
        },
        error: function (XMLHttpRequest, textStatus, errorThrown) {
        }
    });
    return ret;
}
//# sourceMappingURL=http.js.map
