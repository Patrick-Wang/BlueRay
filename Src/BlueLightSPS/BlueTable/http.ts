declare var $;
$.support.cors = true;
function ajaxGet(caller: number, addr: string): void {
    alert(addr);
    $.ajax({
        url: addr,
        success: (data: any) => {
            //alert(data);
            window.external.onGet(caller, 1, data);
        },
        error: (XMLHttpRequest, textStatus, errorThrown) => {
            //alert(textStatus);
            //alert(errorThrown);
            window.external.onGet(caller, textStatus);
        }
    });
}

function ajaxPost(caller: number, addr : string, data : string) : void {
    $.ajax({
        url: addr,
        data: data,
        success: (retData: any) => {
            window.external.onPost(caller, 1, retData);
        },
        error: (XMLHttpRequest, textStatus, errorThrown) => {
            window.external.onPost(caller, textStatus);
        }
    });
}