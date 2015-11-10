package com.BlueRay.mutton.common;

public enum PcjhColumn {
	id, 
	hth, // 合同号"
	khmc, // 客户名称"
	ggxh, // 规格型号"
	cg,//磁钢
	sl, // 数量"
	zc, // 轴承"
	dfr, // 单复绕"
	zdqdy, // 制动器电压"
	yylgg, // 曳引轮规格"
	jf, // 机房"
	bpqxh, // 变频器型号"
	bmqxh, // 编码器型号"
	dlcd, // 电缆长度"
	zxcd, // 闸线长度"
	mpzl, // 铭牌等资料"
	bz, // 备注"
	ddrq, // 订单日期"
	zjdy, // 主机电压
	zjys, // 主机颜色
	zdqxh, // 制动器型号
	zyz, // 左/右置
	bzxdtgg, // 包装箱/底托规格
	gh, // 工号
	zzs, // 制造商
	khqy, // 客户区域
	yxj, // 优先级"
	scrq, // 生产日期"
	jhshyw, // 计划审核-业务"
	jhshjh, // 计划审核-计划"
	bzrq, // 包装日期"
	bzshyw, // 包装审核-业务"
	bzshjh, // 包装审核-计划"
	fhrq, // 发货日期"
	tcbh, // 投产编号"
	ccbh, // 出厂编号"
	ywshrq, 
	jhshrq,
	bzywshrq, 
	bzjhshrq,
	end;
	public static PcjhColumn valueOf(int i){
		PcjhColumn[] cols = PcjhColumn.values();
		for (PcjhColumn col : cols){
			if (col.ordinal() == i){
				return col;
			}
		}
		return PcjhColumn.end;
	}
}
