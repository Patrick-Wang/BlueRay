/// <reference path="jqgrid/jqassist.ts" />
/// <reference path="util.ts" />
/// <reference path="base.ts" />
module ui {

    export class SaleView extends base.GridView{
        private static ins: SaleView;

        public static getInstance(gridName: string): SaleView {
            if (SaleView.ins == undefined) {
                SaleView.ins = new SaleView(gridName, ["合同号", "客户名称", "规格型号", "数量", "轴承", "单复绕", "制动器电压", "曳引轮规格", "机房", "变频器型号", "编码器型号", "电缆长度", "闸线长度", "铭牌等资料", "备注", "订单日期", "审核-业务", "审核-计划"]);
            }
            return SaleView.ins;
        }
        constructor(gridName: string, cols: string[]) {
            super(gridName, cols);
        }
    }

    export class PlanView extends base.GridView {
        private static ins: PlanView;

        public static getInstance(gridName: string): SaleView {
            if (PlanView.ins == undefined) {
                PlanView.ins = new PlanView(gridName, ["合同号", "客户名称", "规格型号", "数量", "轴承", "单复绕", "制动器电压", "曳引轮规格", "机房", "变频器型号", "编码器型号", "电缆长度", "闸线长度", "铭牌等资料", "备注", "订单日期", "生产日期", "计划审核-业务", "计划审核-计划", "包装日期", "包装审核-业务", "包装审核-计划", "发货日期", "投产编号", "出厂编号"]);
            }
            return PlanView.ins;
        }
        constructor(gridName: string, cols: string[]) {
            super(gridName, cols);
        }
    }

    export class ProductView extends base.GridView {
        private static ins: ProductView;

        public static getInstance(gridName: string): SaleView {
            if (ProductView.ins == undefined) {
                ProductView.ins = new ProductView(gridName, ["合同号", "客户名称", "规格型号", "数量", "订单日期", "生产日期", "包装日期", "发货日期", "投产编号", "出厂编号", "机座号", "转子号", "定子编号", "曳引轮号", "制动器号", "编码器号", "上线时间", "整机检验时间", "包装检验时间", "入库时间", "入库审核时间", "出库时间"]);
            }
            return ProductView.ins;
        }

        constructor(gridName: string, cols: string[]) {
            super(gridName, cols);
        }
    }
}