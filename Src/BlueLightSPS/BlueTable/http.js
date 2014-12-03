var mediator = window.external;
$.support.cors = true;
$.ajaxSetup({ cache: false });
function ajaxGet(caller, id, addr) {
    //alert(addr);
    $.ajax({
        url: addr,
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
        url: addr,
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
//# sourceMappingURL=http.js.map
