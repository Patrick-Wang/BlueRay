var __extends = this.__extends || function (d, b) {
    for (var p in b) if (b.hasOwnProperty(p)) d[p] = b[p];
    function __() { this.constructor = d; }
    __.prototype = b.prototype;
    d.prototype = new __();
};
/// <reference path="jqgrid/jqassist.ts" />
/// <reference path="util.ts" />
/// <reference path="base.ts" />
var ui;
(function (ui) {
    var SaleView = (function (_super) {
        __extends(SaleView, _super);
        function SaleView(gridName) {
            _super.call(this, gridName, ["合同号", "客户名称", "规格型号", "数量", "轴承", "单复绕", "制动器电压", "曳引轮规格", "机房", "变频器型号", "编码器型号", "电缆长度", "闸线长度", "铭牌等资料", "备注", "订单日期", "主机电压", "主机颜色", "制动器型号", "左/右置", "包装箱/底托规格", "工号", "制造商", "客户区域", "优先级", "审核-业务", "审核-计划"], SaleView.widths);
        }
        SaleView.getInstance = function (gridName) {
            if (undefined == SaleView.ins) {
                SaleView.ins = new SaleView(gridName);
            }
            return SaleView.ins;
        };
        SaleView.widths = [
            66, 136, 63, 35, 35, 42, 62, 127, 34, 72, 60, 47, 46, 107, 62, 72, 48, 45, 70, 47, 120, 34, 39, 48, 41, 51, 51
        ];
        return SaleView;
    })(base.GridView);
    ui.SaleView = SaleView;

    var PlanView = (function (_super) {
        __extends(PlanView, _super);
        function PlanView(gridName) {
            _super.call(this, gridName, ["合同号", "客户名称", "规格型号", "数量", "轴承", "单复绕", "制动器电压", "曳引轮规格", "机房", "变频器型号", "编码器型号", "电缆长度", "闸线长度", "铭牌等资料", "备注", "订单日期", "主机电压", "主机颜色", "制动器型号", "左/右置", "包装箱/底托规格", "工号", "制造商", "客户区域", "优先级", "生产日期", "计划审核-业务", "计划审核-计划", "包装日期", "包装审核-业务", "包装审核-计划", "发货日期", "投产编号", "出厂编号"], PlanView.widths);
            var templateExporteId = gridName + "_template_export";
            this.mTable.jqGrid('navButtonAdd', "#" + gridName + 'pager', {
                caption: "", buttonicon: "none", onClickButton: function () {
                    //alert(gridName);
                    mediator.onTemplateExportClicked(gridName);
                }, position: "last", title: "按模板导出数据", id: templateExporteId
            });
            this.reload();
            $("#" + templateExporteId + " div").addClass("ui-icon");
            $("#" + templateExporteId + " div").addClass("ui-icon-disk");
        }
        PlanView.getInstance = function (gridName) {
            if (undefined == PlanView.ins) {
                PlanView.ins = new PlanView(gridName);
            }
            return PlanView.ins;
        };
        PlanView.widths = [
            66, 136, 63, 35, 35, 42, 62, 127, 34, 72, 60, 47, 46, 107, 62, 72, 48, 45, 70, 47, 120, 34, 39, 48, 41, 71, 71, 80, 75, 80, 80, 70, 50, 52
        ];
        return PlanView;
    })(base.GridView);
    ui.PlanView = PlanView;

    var ProductView = (function (_super) {
        __extends(ProductView, _super);
        function ProductView(gridName) {
            _super.call(this, gridName, ["合同号", "客户名称", "规格型号", "数量", "订单日期", "生产日期", "包装日期", "发货日期", "投产编号", "出厂编号", "机座号", "转子号", "定子编号", "曳引轮号", "制动器号", "编码器号", "上线时间", "整机检验时间", "包装检验时间", "入库时间", "入库审核时间", "出库时间"], ProductView.widths);
        }
        ProductView.getInstance = function (gridName) {
            if (undefined == ProductView.ins) {
                ProductView.ins = new ProductView(gridName);
            }
            return ProductView.ins;
        };
        ProductView.widths = [
            80,
            80,
            80,
            80,
            80,
            80,
            80,
            80,
            80,
            80,
            80,
            80,
            80,
            80,
            80,
            80,
            80,
            80,
            80,
            80,
            80,
            80
        ];
        return ProductView;
    })(base.GridView);
    ui.ProductView = ProductView;

    var NotificationView = (function (_super) {
        __extends(NotificationView, _super);
        function NotificationView(gridName) {
            _super.call(this, gridName, ["合同号", "客户名称", "规格型号", "数量", "轴承", "单复绕", "制动器电压", "曳引轮规格", "机房", "变频器型号", "编码器型号", "电缆长度", "闸线长度", "铭牌等资料", "备注", "订单日期", "主机电压", "主机颜色", "制动器型号", "左/右置", "包装箱/底托规格", "工号", "制造商", "客户区域", "优先级", "生产日期", "计划审核-业务", "计划审核-计划", "包装日期", "包装审核-业务", "包装审核-计划", "发货日期", "投产编号", "出厂编号"], NotificationView.widths);
        }
        NotificationView.getInstance = function (gridName) {
            if (undefined == NotificationView.ins) {
                NotificationView.ins = new NotificationView(gridName);
            }
            return NotificationView.ins;
        };
        NotificationView.widths = [
            66, 136, 63, 35, 35, 42, 62, 127, 34, 72, 60, 47, 46, 107, 62, 72, 48, 45, 70, 47, 120, 34, 39, 48, 41, 71, 71, 80, 75, 80, 80, 70, 50, 52
        ];
        return NotificationView;
    })(base.GridView);
    ui.NotificationView = NotificationView;
})(ui || (ui = {}));
//# sourceMappingURL=views.js.map
