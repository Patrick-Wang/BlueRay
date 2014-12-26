declare var $;
var mediator: any = window.external;
$.support.cors = true;
$.ajaxSetup({ cache: false }); 
function ajaxGet(caller: number, id: number, addr: string): void {
//alert(addr);
    $.ajax({
        url: encodeURI(addr),
        //dataType: "json",
        success: (data: any) => {
           //alert(data);
            mediator.onGet(caller, 1, id, data.toString());
        },
        error: (XMLHttpRequest, textStatus, errorThrown) => {
            //alert(textStatus);
            //alert(errorThrown);
            mediator.onGet(caller, 0, id);
        }
    });
}

function ajaxPost(caller: number, id: number, addr: string, d: string): void {
    $.ajax({
        type: 'POST',
        url: encodeURI(addr),
        dataType: "json",
        data: d,
        success: (retData: any) => {
            mediator.onPost(caller, 1, id, retData.toString());
        },
        error: (XMLHttpRequest, textStatus, errorThrown) => {
            mediator.onPost(caller, 0, id);
        }
    });
}

function ajaxSyncGet(addr: string): any {
    //alert(addr);
    var ret = 0;
    $.ajax({
        async: false, 
        url: encodeURI(addr),
        //dataType: "json",
        success: (data: any) => {
            ret = data.toString();
        },
        error: (XMLHttpRequest, textStatus, errorThrown) => {

        }
    });
    return ret;
}

function ajaxSyncPost(addr: string, d: string): any {
    var ret = 0;
    $.ajax({
        async: false, 
        type: 'POST',
        url: encodeURI(addr),
        dataType: "json",
        data: d,
        success: (retData: any) => {
            ret = retData.toString();
        },
        error: (XMLHttpRequest, textStatus, errorThrown) => {
           
        }
    });
    return ret;
}