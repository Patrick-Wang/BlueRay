declare var $;
declare var mediator;
$.support.cors = true;
function ajaxGet(caller: number, addr: string): void {
    alert(addr);
    $.ajax({
        url: addr,
        success: (data: any) => {
            //alert(data);
            mediator.onGet(caller, 1, data);
        },
        error: (XMLHttpRequest, textStatus, errorThrown) => {
            //alert(textStatus);
            //alert(errorThrown);
            mediator.onGet(caller, textStatus);
        }
    });
}

function ajaxPost(caller: number, addr : string, data : string) : void {
    $.ajax({
        url: addr,
        data: data,
        success: (retData: any) => {
            mediator.onPost(caller, 1, retData);
        },
        error: (XMLHttpRequest, textStatus, errorThrown) => {
            mediator.onPost(caller, textStatus);
        }
    });
}