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
            _super.call(this, gridName, ["合同号", "客户名称", "规格型号", "数量", "轴承", "单复绕", "制动器电压", "曳引轮规格", "机房", "变频器型号", "编码器型号", "电缆长度", "闸线长度", "铭牌等资料", "备注", "订单日期", "审核-业务", "审核-计划", "优先级", "订单日期"], SaleView.widths);
        }
        SaleView.getInstance = function (gridName) {
            if (undefined == SaleView.ins) {
                SaleView.ins = new SaleView(gridName);
            }
            return SaleView.ins;
        };
        SaleView.widths = [
            53, 96, 81, 40, 34, 56, 78, 81, 44, 77, 80, 80, 80, 126, 89, 86, 63, 63
        ];
        return SaleView;
    })(base.GridView);
    ui.SaleView = SaleView;

    var PlanView = (function (_super) {
        __extends(PlanView, _super);
        function PlanView(gridName) {
            _super.call(this, gridName, ["合同号", "客户名称", "规格型号", "数量", "轴承", "单复绕", "制动器电压", "曳引轮规格", "机房", "变频器型号", "编码器型号", "电缆长度", "闸线长度", "铭牌等资料", "备注", "订单日期", "优先级", "订单日期", "生产日期", "计划审核-业务", "计划审核-计划", "包装日期", "包装审核-业务", "包装审核-计划", "发货日期", "投产编号", "出厂编号"], PlanView.widths);
        }
        PlanView.getInstance = function (gridName) {
            if (undefined == PlanView.ins) {
                PlanView.ins = new PlanView(gridName);
            }
            return PlanView.ins;
        };
        PlanView.widths = [
            68, 82, 69, 34, 48, 80, 80, 124, 80, 80, 80, 80, 80, 123, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80
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
            _super.call(this, gridName, ["合同号", "客户名称", "规格型号", "数量", "轴承", "单复绕", "制动器电压", "曳引轮规格", "机房", "变频器型号", "编码器型号", "电缆长度", "闸线长度", "铭牌等资料", "备注", "订单日期", "生产日期", "计划审核-业务", "计划审核-计划", "包装日期", "包装审核-业务", "包装审核-计划", "发货日期", "投产编号", "出厂编号"], NotificationView.widths);
        }
        NotificationView.getInstance = function (gridName) {
            if (undefined == NotificationView.ins) {
                NotificationView.ins = new NotificationView(gridName);
            }
            return NotificationView.ins;
        };
        NotificationView.widths = [
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
            80,
            80,
            80,
            80
        ];
        return NotificationView;
    })(base.GridView);
    ui.NotificationView = NotificationView;
})(ui || (ui = {}));
//# sourceMappingURL=views.js.map
