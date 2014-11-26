var mediator = window.external;
$.support.cors = true;
function ajaxGet(caller, id, addr) {
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

function ajaxPost(caller, id, addr, data) {
    $.ajax({
        url: addr,
        data: data,
        success: function (retData) {
            mediator.onPost(caller, 1, id, retData.toString());
        },
        error: function (XMLHttpRequest, textStatus, errorThrown) {
            mediator.onPost(caller, 0, id);
        }
    });
}
//# sourceMappingURL=http.js.map
