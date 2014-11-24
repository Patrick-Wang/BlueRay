$.support.cors = true;
function ajaxGet(caller, addr) {
    alert(addr);
    $.ajax({
        url: addr,
        success: function (data) {
            //alert(data);
            window.external.onGet(caller, 1, data);
        },
        error: function (XMLHttpRequest, textStatus, errorThrown) {
            //alert(textStatus);
            //alert(errorThrown);
            window.external.onGet(caller, textStatus);
        }
    });
}

function ajaxPost(caller, addr, data) {
    $.ajax({
        url: addr,
        data: data,
        success: function (retData) {
            window.external.onPost(caller, 1, retData);
        },
        error: function (XMLHttpRequest, textStatus, errorThrown) {
            window.external.onPost(caller, textStatus);
        }
    });
}
//# sourceMappingURL=http.js.map
