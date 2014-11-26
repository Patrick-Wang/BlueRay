declare var $;
var mediator: any = window.external;
$.support.cors = true;
function ajaxGet(caller: number, id: number, addr: string): void {
    $.ajax({
        url: addr,
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
        url: addr,
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