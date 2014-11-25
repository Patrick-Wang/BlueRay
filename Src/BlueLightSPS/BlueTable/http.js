$.support.cors = true;
function ajaxGet(caller, addr) {
    alert(addr);
    $.ajax({
        url: addr,
        success: function (data) {
            //alert(data);
            mediator.onGet(caller, 1, data);
        },
        error: function (XMLHttpRequest, textStatus, errorThrown) {
            //alert(textStatus);
            //alert(errorThrown);
            mediator.onGet(caller, textStatus);
        }
    });
}

function ajaxPost(caller, addr, data) {
    $.ajax({
        url: addr,
        data: data,
        success: function (retData) {
            mediator.onPost(caller, 1, retData);
        },
        error: function (XMLHttpRequest, textStatus, errorThrown) {
            mediator.onPost(caller, textStatus);
        }
    });
}
//# sourceMappingURL=http.js.map
