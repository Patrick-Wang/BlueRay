package com.BlueRay.mutton.common;

import com.BlueRay.mutton.tool.Util;



public class ExporterUtil {
	public static boolean validatePlanHighlight(PcjhColumn col, String[] row){
		return validatePlanHighlight(col.ordinal(), row);
	}
	
	public static boolean validatePlanHighlight(int col, String[] row){
		String ggxh = row[PcjhColumn.ggxh.ordinal()];
		if (Util.ggIsS(ggxh)){
			if (row[PcjhColumn.zdqdy.ordinal()].equalsIgnoreCase("AC220V") && 
				!row[PcjhColumn.zdqxh.ordinal()].equalsIgnoreCase("DZE-14EB2")){
				if (col == PcjhColumn.zdqxh.ordinal() || col == PcjhColumn.zdqdy.ordinal()){
					return true;
				}
			}
			
			if (row[PcjhColumn.zdqdy.ordinal()].equalsIgnoreCase("DC110V") && 
					!row[PcjhColumn.zdqxh.ordinal()].equalsIgnoreCase("DZE-14EA")){
				if (col == PcjhColumn.zdqxh.ordinal() || col == PcjhColumn.zdqdy.ordinal()){
					return true;
				}
			}

			if (!row[PcjhColumn.yylgg.ordinal()].equalsIgnoreCase("400*5*10*16")){
				if (col == PcjhColumn.yylgg.ordinal()){
					return true;
				}
			}
		}
		
		if (Util.ggIsTStart(ggxh)){
			if (!row[PcjhColumn.zdqdy.ordinal()].equalsIgnoreCase("DC110v")){
				if (col == PcjhColumn.zdqdy.ordinal()){
					return true;
				}
			}

			if (!row[PcjhColumn.zdqxh.ordinal()].equalsIgnoreCase("WYT-TA.3（10簧）") && 
				!row[PcjhColumn.zdqxh.ordinal()].equalsIgnoreCase("WYT-TA.3（12簧）")){
				if (col == PcjhColumn.zdqxh.ordinal()){
					return true;
				}
			}

			if (!row[PcjhColumn.yylgg.ordinal()].equalsIgnoreCase("400*5*10*16")){
				if (col == PcjhColumn.yylgg.ordinal()){
					return true;
				}
			}
		}
		
		if (Util.ggIsU(ggxh)){
			if (!row[PcjhColumn.zdqdy.ordinal()].equalsIgnoreCase("DC110V")){
				if (col == PcjhColumn.zdqdy.ordinal()){
					return true;
				}
			}

			if (!row[PcjhColumn.yylgg.ordinal()].equalsIgnoreCase("480*7*12*18")){
				if (col == PcjhColumn.yylgg.ordinal()){
					return true;
				}
			}

		}
		
		if (!row[PcjhColumn.zjdy.ordinal()].equalsIgnoreCase("AC380V")){
			if (col == PcjhColumn.zjdy.ordinal()){
				return true;
			}
		}

		if (!row[PcjhColumn.jf.ordinal()].equalsIgnoreCase("有")){
			if (col == PcjhColumn.jf.ordinal()){
				return true;
			}
		}

		if (!row[PcjhColumn.bmqxh.ordinal()].equalsIgnoreCase("海1387")){
			if (col == PcjhColumn.bmqxh.ordinal()){
				return true;
			}
		}

		return false;
	}
	
	public static boolean validateSaleHighlight(HtxxColumn col, String[] row){
		return validateSaleHighlight(col.ordinal(), row);
	}
	
	public static boolean validateSaleHighlight(int col, String[] row){
		String ggxh = row[HtxxColumn.ggxh.ordinal()];
		if (Util.ggIsS(ggxh)){
			if (row[HtxxColumn.zdqdy.ordinal()].equalsIgnoreCase("AC220V") && 
				!row[HtxxColumn.zdqxh.ordinal()].equalsIgnoreCase("DZE-14EB2")){
				if (col == HtxxColumn.zdqxh.ordinal() || col == HtxxColumn.zdqdy.ordinal()){
					return true;
				}
			}
			
			if (row[HtxxColumn.zdqdy.ordinal()].equalsIgnoreCase("DC110V") && 
					!row[HtxxColumn.zdqxh.ordinal()].equalsIgnoreCase("DZE-14EA")){
				if (col == HtxxColumn.zdqxh.ordinal() || col == HtxxColumn.zdqdy.ordinal()){
					return true;
				}
			}

			if (!row[HtxxColumn.yylgg.ordinal()].equalsIgnoreCase("400*5*10*16")){
				if (col == HtxxColumn.yylgg.ordinal()){
					return true;
				}
			}
		}
		
		if (Util.ggIsTStart(ggxh)){
			if (!row[HtxxColumn.zdqdy.ordinal()].equalsIgnoreCase("DC110v")){
				if (col == HtxxColumn.zdqdy.ordinal()){
					return true;
				}
			}

			if (!row[HtxxColumn.zdqxh.ordinal()].equalsIgnoreCase("WYT-TA.3（10簧）") && 
				!row[HtxxColumn.zdqxh.ordinal()].equalsIgnoreCase("WYT-TA.3（12簧）")){
				if (col == HtxxColumn.zdqxh.ordinal()){
					return true;
				}
			}

			if (!row[HtxxColumn.yylgg.ordinal()].equalsIgnoreCase("400*5*10*16")){
				if (col == HtxxColumn.yylgg.ordinal()){
					return true;
				}
			}
		}
		
		if (Util.ggIsU(ggxh)){
			if (!row[HtxxColumn.zdqdy.ordinal()].equalsIgnoreCase("DC110V")){
				if (col == HtxxColumn.zdqdy.ordinal()){
					return true;
				}
			}

			if (!row[HtxxColumn.yylgg.ordinal()].equalsIgnoreCase("480*7*12*18")){
				if (col == HtxxColumn.yylgg.ordinal()){
					return true;
				}
			}

		}
		
		if (!row[HtxxColumn.zjdy.ordinal()].equalsIgnoreCase("AC380V")){
			if (col == HtxxColumn.zjdy.ordinal()){
				return true;
			}
		}

		if (!row[HtxxColumn.jf.ordinal()].equalsIgnoreCase("有")){
			if (col == HtxxColumn.jf.ordinal()){
				return true;
			}
		}

		if (!row[HtxxColumn.bmqxh.ordinal()].equalsIgnoreCase("海1387")){
			if (col == HtxxColumn.bmqxh.ordinal()){
				return true;
			}
		}

		return false;
	}
	
}
