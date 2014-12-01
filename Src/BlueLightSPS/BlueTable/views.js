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
            _super.call(this, gridName, ["合同号", "客户名称", "规格型号", "数量", "轴承", "单复绕", "制动器电压", "曳引轮规格", "机房", "变频器型号", "编码器型号", "电缆长度", "闸线长度", "铭牌等资料", "备注", "订单日期", "审核-业务", "审核-计划"]);
        }
        SaleView.getInstance = function (gridName) {
            if (SaleView.ins == undefined) {
                SaleView.ins = new SaleView(gridName);
            }
            return SaleView.ins;
        };
        return SaleView;
    })(base.GridView);
    ui.SaleView = SaleView;

    var PlanView = (function (_super) {
        __extends(PlanView, _super);
        function PlanView(gridName) {
            _super.call(this, gridName, ["合同号", "客户名称", "规格型号", "数量", "轴承", "单复绕", "制动器电压", "曳引轮规格", "机房", "变频器型号", "编码器型号", "电缆长度", "闸线长度", "铭牌等资料", "备注", "订单日期", "生产日期", "计划审核-业务", "计划审核-计划", "包装日期", "包装审核-业务", "包装审核-计划", "发货日期", "投产编号", "出厂编号"]);
        }
        PlanView.getInstance = function (gridName) {
            if (PlanView.ins == undefined) {
                PlanView.ins = new PlanView(gridName);
            }
            return PlanView.ins;
        };
        return PlanView;
    })(base.GridView);
    ui.PlanView = PlanView;

    var ProductView = (function (_super) {
        __extends(ProductView, _super);
        function ProductView(gridName) {
            _super.call(this, gridName, ["合同号", "客户名称", "规格型号", "数量", "订单日期", "生产日期", "包装日期", "发货日期", "投产编号", "出厂编号", "机座号", "转子号", "定子编号", "曳引轮号", "制动器号", "编码器号", "上线时间", "整机检验时间", "包装检验时间", "入库时间", "入库审核时间", "出库时间"]);
        }
        ProductView.getInstance = function (gridName) {
            if (ProductView.ins == undefined) {
                ProductView.ins = new ProductView(gridName);
            }
            return ProductView.ins;
        };
        return ProductView;
    })(base.GridView);
    ui.ProductView = ProductView;
})(ui || (ui = {}));
//# sourceMappingURL=views.js.map
