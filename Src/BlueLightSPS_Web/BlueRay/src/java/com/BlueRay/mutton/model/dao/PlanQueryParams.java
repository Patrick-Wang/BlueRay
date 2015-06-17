package com.BlueRay.mutton.model.dao;

import java.lang.reflect.Field;
import java.sql.Date;
import java.util.HashMap;
import java.util.Map;

import com.BlueRay.mutton.model.entity.jpa.BMQXHFLXX;
import com.BlueRay.mutton.model.entity.jpa.BPQXHFLXX;
import com.BlueRay.mutton.model.entity.jpa.BZXDTGG;
import com.BlueRay.mutton.model.entity.jpa.CGXXB;
import com.BlueRay.mutton.model.entity.jpa.CPGGXHXX;
import com.BlueRay.mutton.model.entity.jpa.HTXX;
import com.BlueRay.mutton.model.entity.jpa.KHQY;
import com.BlueRay.mutton.model.entity.jpa.KHXX;
import com.BlueRay.mutton.model.entity.jpa.MPZLXX;
import com.BlueRay.mutton.model.entity.jpa.PCJHXX;
import com.BlueRay.mutton.model.entity.jpa.YYLGGFLXX;
import com.BlueRay.mutton.model.entity.jpa.ZCXX;
import com.BlueRay.mutton.model.entity.jpa.ZDQDYFLXX;
import com.BlueRay.mutton.model.entity.jpa.ZDQXH;
import com.BlueRay.mutton.model.entity.jpa.ZJDY;
import com.BlueRay.mutton.model.entity.jpa.ZJYS;
import com.BlueRay.mutton.model.entity.jpa.ZZS;
import com.BlueRay.mutton.service.HtxxColumn;
import com.BlueRay.mutton.service.PcjhColumn;

import net.sf.json.JSONArray;
import net.sf.json.JSONObject;

//{
//approve : [[{
//	type : bussiness / plan,
//	approved : true/false
//}],[{
//	type : bussiness / plan,
//	approved : true/false
//}]],
//search : {
//	advanced : [],
//	basic : {
//		text : searchtext,
//		exact : true/false
//	},
//	date : {
//		startDate : 
//		endDate : 
//	}
//},
//sort : [
//  {
//  	col : index,
//  	order : true/false
//  },
//  {
//  	col : index,
//  	order : true/false
//  }
//]
//}

public class PlanQueryParams {
	private JSONObject mJo;
	private Map<String, Class<?>> connectMap = new HashMap<String, Class<?>>();
	private boolean mNeedsHtxx = false;
	private static Map<Integer, Integer> paramHtxxColMap = new HashMap<Integer, Integer>();
	private static Map<Integer, Integer> paramPcjhColMap = new HashMap<Integer, Integer>();
	private IAdvanceTranslator mTranslator;

	// private static int mColumnCount = PcjhColumn.end.ordinal() - 1;
	{
		for (int i = PcjhColumn.end.ordinal() - 1; i > PcjhColumn.id.ordinal(); --i) {
			PcjhColumn pcjhCol = PcjhColumn.valueOf(i);
			try {
				HtxxColumn htCol = HtxxColumn.valueOf(pcjhCol.name());
				paramHtxxColMap.put(i - 1, htCol.ordinal());
			} catch (Exception e) {
				paramPcjhColMap.put(i - 1, pcjhCol.ordinal());
			}
		}

		paramHtxxColMap.remove(PcjhColumn.bz.ordinal() - 1);
		paramHtxxColMap.remove(PcjhColumn.zc.ordinal() - 1);
		paramPcjhColMap.put(PcjhColumn.bz.ordinal() - 1, PcjhColumn.bz.ordinal());
		paramPcjhColMap.put(PcjhColumn.zc.ordinal() - 1, PcjhColumn.zc.ordinal());
		// for (int i = 0; i < 24; ++i) {
		// if (i == 3){
		// paramPcjhColMap.put(i, 13);//zc
		// } else if (i == 14){
		// paramPcjhColMap.put(i, 12);//bz
		// } else{
		// paramHtxxColMap.put(i, i + 1);
		// }
		// }
		// paramHtxxColMap.put(24, 27);//yxj
		//
		// for (int i = 25; i < mColumnCount; ++i) {
		// paramPcjhColMap.put(i, 2 + i - 25);
		// }
	}

	public PlanQueryParams(JSONObject jo, IAdvanceTranslator translator) {
		mJo = jo;
		mTranslator = translator;
	}

	private String getForginId(Class<?> cls) {
		String colName = null;
		String id = null;
		if (cls.getName().equals(KHXX.class.getName())) {
			id = "clientID";
			colName = "khmc";
		} else if (cls.getName().equals(CPGGXHXX.class.getName())) {
			id = "cpggxhID";
			colName = "gg";
		} else if (cls.getName().equals(ZCXX.class.getName())) {
			colName = "zcxh";
			id = "zcxhID";
		} else if (cls.getName().equals(ZDQDYFLXX.class.getName())) {
			colName = "zdqdy";
			id = "zdqdyID";
		} else if (cls.getName().equals(YYLGGFLXX.class.getName())) {
			colName = "yylgg";
			id = "yylggID";
		} else if (cls.getName().equals(BPQXHFLXX.class.getName())) {
			colName = "bpqxh";
			id = "bpqxhID";
		} else if (cls.getName().equals(BMQXHFLXX.class.getName())) {
			colName = "bmqxh";
			id = "bmqxhID";
		} else if (cls.getName().equals(MPZLXX.class.getName())) {
			colName = "mpzl";
			id = "id";
		} else if (cls.getName().equals(ZJDY.class.getName())) {
			colName = "zjdy";
			id = "id";
		} else if (cls.getName().equals(ZJYS.class.getName())) {
			colName = "zjys";
			id = "id";
		} else if (cls.getName().equals(ZDQXH.class.getName())) {
			colName = "zdqxh";
			id = "id";
		} else if (cls.getName().equals(BZXDTGG.class.getName())) {
			colName = "bzxdtgg";
			id = "id";
		} else if (cls.getName().equals(ZZS.class.getName())) {
			colName = "zzs";
			id = "id";
		} else if (cls.getName().equals(KHQY.class.getName())) {
			colName = "khqy";
			id = "id";
		} else if (cls.getName().equals(CGXXB.class.getName())) {
			colName = "cg";
			id = "cgID";
		}
		return id;
	}

	private String getForginName(Class<?> cls) {
		String colName = null;
		String id = null;
		if (cls.getName().equals(KHXX.class.getName())) {
			id = "clientID";
			colName = "khmc";
		} else if (cls.getName().equals(CPGGXHXX.class.getName())) {
			id = "cpggxhID";
			colName = "gg";
		} else if (cls.getName().equals(ZCXX.class.getName())) {
			colName = "zcxh";
			id = "zcxhID";
		} else if (cls.getName().equals(ZDQDYFLXX.class.getName())) {
			colName = "zdqdy";
			id = "zdqdyID";
		} else if (cls.getName().equals(YYLGGFLXX.class.getName())) {
			colName = "yylgg";
			id = "yylggID";
		} else if (cls.getName().equals(BPQXHFLXX.class.getName())) {
			colName = "bpqxh";
			id = "bpqxhID";
		} else if (cls.getName().equals(BMQXHFLXX.class.getName())) {
			colName = "bmqxh";
			id = "bmqxhID";
		} else if (cls.getName().equals(MPZLXX.class.getName())) {
			colName = "mpzl";
			id = "id";
		} else if (cls.getName().equals(ZJDY.class.getName())) {
			colName = "zjdy";
			id = "id";
		} else if (cls.getName().equals(ZJYS.class.getName())) {
			colName = "zjys";
			id = "id";
		} else if (cls.getName().equals(ZDQXH.class.getName())) {
			colName = "zdqxh";
			id = "id";
		} else if (cls.getName().equals(BZXDTGG.class.getName())) {
			colName = "bzxdtgg";
			id = "id";
		} else if (cls.getName().equals(ZZS.class.getName())) {
			colName = "zzs";
			id = "id";
		} else if (cls.getName().equals(KHQY.class.getName())) {
			colName = "khqy";
			id = "id";
		} else if (cls.getName().equals(CGXXB.class.getName())) {
			colName = "cg";
			id = "cgID";
		}
		return colName;
	}

	private String getWhereSql() {
		StringBuilder whereBuilder = new StringBuilder();
		String approveSql = parseApprove();
		String advancedSql = parseAdvance();
		String basicSql = parseBasic();
		String dateSql = parseDateRange();
		String unitedSql = parseUnited();
		whereBuilder.append("");
		boolean firstSql = true;

		if (!advancedSql.isEmpty()) {
			if (firstSql) {
				firstSql = false;
			} else {
				whereBuilder.append(" and ");
			}
			whereBuilder.append(advancedSql);
		}

		if (!basicSql.isEmpty()) {
			if (firstSql) {
				firstSql = false;
			} else {
				whereBuilder.append(" and ");
			}
			whereBuilder.append(basicSql);
		}

		if (!approveSql.isEmpty()) {
			if (firstSql) {
				firstSql = false;
			} else {
				whereBuilder.append(" and ");
			}
			whereBuilder.append(approveSql);
		}

		if (!dateSql.isEmpty()) {
			if (firstSql) {
				firstSql = false;
			} else {
				whereBuilder.append(" and ");
			}
			whereBuilder.append(dateSql);
		}

		if (!unitedSql.isEmpty()) {
			if (firstSql) {
				firstSql = false;
			} else {
				whereBuilder.append(" and ");
			}
			whereBuilder.append("  ( " + unitedSql + " ) ");
		}

		return whereBuilder.toString();
	}

	private String parseDateRange() {
		String strDate = "";
		JSONObject search = mJo.getJSONObject("search");
		JSONObject jdate = null;
		if (!search.isNullObject()) {
			jdate = search.getJSONObject("date");
		}

		if (null != jdate && !jdate.isNullObject()) {
			mNeedsHtxx = true;
			String startDate = jdate.getString("startDate");
			String endDate = jdate.getString("endDate");
			if (!startDate.isEmpty()) {
				strDate = "HTXX_.ddrq >= '" + startDate + "'";
			}
			if (!endDate.isEmpty()) {
				if (!strDate.isEmpty()) {
					strDate += " and ";
				}
				strDate += "HTXX_.ddrq <= '" + endDate + "' ";
			}
		}
		return strDate;
	}

	private String parseBasic() {
		StringBuilder basicBuilder = new StringBuilder();
		basicBuilder.append("");
		JSONObject search = mJo.getJSONObject("search");
		JSONObject jbasic = null;
		if (!search.isNullObject()) {
			jbasic = search.getJSONObject("basic");
		}

		if (null != jbasic && !jbasic.isNullObject()) {
			String normaltext = jbasic.getString("text");
			String stringSearch = "'" + normaltext + "'";
			String searchText;
			Boolean exact = jbasic.getBoolean("exact");
			boolean firstSql = true;
			boolean bIsInteger = false;
			boolean bIsDate = false;
			try {
				Integer.valueOf(normaltext);
				bIsInteger = true;
			} catch (Exception e) {

			}

			try {
				Date.valueOf(normaltext);
				bIsDate = true;
			} catch (Exception e) {

			}
			// Field[] fields = HTXX.class.getDeclaredFields();
			Field fdTmp = null;
			String link = null;
			// int column = 0;
			for (int i = 0; i < PcjhColumn.end.ordinal(); ++i) {
				if (paramHtxxColMap.containsKey(i)) {
					// connectMap.put("htxxID", HTXX.class);
					mNeedsHtxx = true;
					// column = paramHtxxColMap.get(i);
					fdTmp = HTXX.getField(paramHtxxColMap.get(i));
					Class<?> cls = HTXX.getFroeignClass(paramHtxxColMap.get(i));
					if (null != cls) {
						if (firstSql) {
							firstSql = false;
							basicBuilder.append("( ");
						} else {
							basicBuilder.append(" or ");
						}

						searchText = stringSearch;
						if (!exact) {
							link = " like ";
							searchText = "upper('%" + normaltext + "%')";
							basicBuilder.append("upper(" + cls.getSimpleName() + "_."
									+ getForginName(cls) + ")" + link + searchText + " ");
						} else {
							link = " = ";
							basicBuilder.append(cls.getSimpleName() + "_."
									+ getForginName(cls) + link + searchText + " ");
						}

						connectMap.put(fdTmp.getName(), cls);

						
					} else {
						if ((!bIsInteger && fdTmp.getType().getName()
								.equals(Integer.class.getName()))) {
							continue;
						}

						if ((!bIsDate && fdTmp.getType().getName()
								.equals(Date.class.getName()))) {
							continue;
						}

						if (firstSql) {
							firstSql = false;
							basicBuilder.append("( ");
						} else {
							basicBuilder.append(" or ");
						}

						link = " = ";
						if (fdTmp.getType().getName()
								.equals(String.class.getName())
								|| fdTmp.getType().getName()
										.equals(Date.class.getName())) {
							searchText = stringSearch;
							if (!exact
									&& fdTmp.getType().getName()
											.equals(String.class.getName())) {
								link = " like ";
								searchText = "upper('%" + normaltext + "%')";
								basicBuilder.append(" upper(HTXX_." + fdTmp.getName() + ")" + link + searchText
										+ " ");
							} else{
								basicBuilder.append(" HTXX_." + fdTmp.getName() + link + searchText
									+ " ");
							}
						} else {
							searchText = normaltext;
							basicBuilder.append(" HTXX_." + fdTmp.getName() + link + searchText
									+ " ");
						}

						
					}
				} else if (paramPcjhColMap.containsKey(i)) {
					// column = paramPcjhColMap.get(i);
					fdTmp = PCJHXX.getField(paramPcjhColMap.get(i));

					if ((!bIsInteger && fdTmp.getType().getName()
							.equals(Integer.class.getName()))) {
						continue;
					}

					if ((!bIsDate && fdTmp.getType().getName()
							.equals(Date.class.getName()))) {
						continue;
					}

					if (firstSql) {
						firstSql = false;
						basicBuilder.append("( ");
					} else {
						basicBuilder.append(" or ");
					}

					link = " = ";
					if (fdTmp.getType().getName()
							.equals(String.class.getName())
							|| fdTmp.getType().getName()
									.equals(Date.class.getName())) {
						searchText = stringSearch;
						if (!exact) {
							link = " like ";
							searchText = "upper('%" + normaltext + "%')";
							basicBuilder.append(" upper(PCJHXX_." + fdTmp.getName() + ")" + link + searchText
									+ " ");
						}else{
							basicBuilder.append(" PCJHXX_." + fdTmp.getName() + link + searchText
									+ " ");
						}
					} else {
						searchText = normaltext;
						basicBuilder.append(" PCJHXX_." + fdTmp.getName() + link + searchText
								+ " ");
					}


				}

			}
			if (!firstSql) {
				basicBuilder.append(" ) ");
			}
		}

		return basicBuilder.toString();
	}

	private String parseUnited() {
		JSONObject search = mJo.getJSONObject("search");
		JSONArray junited = null;
		if (!search.isNullObject() && search.has("united")) {
			junited = search.getJSONArray("united");
		}
		StringBuilder unitedBuilder = new StringBuilder();
		JSONObject junit = null;
		unitedBuilder.append("");
		if (null != junited) {
			for (int i = 0; i < junited.size(); ++i) {
				junit = junited.getJSONObject(i);
				if (junit.containsKey("group")) {
					unitedBuilder.append(parseUnitedGroup(junit));
				} else if (junit.containsKey("col")) {
					unitedBuilder.append(parseUnit(junit));
				} else if (junit.containsKey("and")) {
					unitedBuilder.append(parseUnitedAnd(junit));
				}
			}
		}
		return unitedBuilder.toString();
	}

	private String parseUnit(JSONObject junit) {
		int col = junit.getInt("col");
		String param = junit.getString("param");
		String sql = null;
		if (paramHtxxColMap.containsKey(col)) {
			int index = paramHtxxColMap.get(col);
			mNeedsHtxx = true;
			Class<?> cls = HTXX.getFroeignClass(index);
			Field fd = HTXX.getField(index);
			// Field[] fields = HTXX.class.getDeclaredFields();
			if (null != mTranslator) {
				String newValue = mTranslator.in(fd.getName(), param);
				if (null != newValue) {
					param = newValue;
				}
			}

			if (null != cls) {
				String keyName = cls.getSimpleName() + "_."
						+ getForginName(cls);

				sql = QueryColumnCommandParser.parse(String.class, keyName,
						param);
				if (null == sql) {
					sql = keyName + " = '" + param + "'";
				}
				connectMap.put(fd.getName(), cls);
			} else {

				String keyName = "HTXX_." + fd.getName();
				sql = QueryColumnCommandParser.parse(fd.getType(), keyName,
						param);
				if (null == sql) {
					if (fd.getType().getName().equals(String.class.getName())
							|| fd.getType().getName()
									.equals(Date.class.getName())) {
						sql = keyName + " = '" + param + "'";
					} else {
						sql = keyName + " = " + param;
					}
				}
			}

		} else if (paramPcjhColMap.containsKey(col)) {

			int index = paramPcjhColMap.get(col);
			Field fd = PCJHXX.getField(index);
			if (null != mTranslator) {
				String newValue = mTranslator.in(fd.getName(), param);
				if (null != newValue) {
					param = newValue;
				}
			}

			sql = QueryColumnCommandParser.parse(fd.getType(),
					"PCJHXX_." + fd.getName(), param);
			if (null == sql) {
				sql = "PCJHXX_." + fd.getName() + " = '" + param + "' ";
			}
		}

		return " " + sql + " ";
	}

	private String parseUnitedAnd(JSONObject jand) {
		if (jand.getBoolean("and")) {
			return " and ";
		}
		return " or ";

	}

	private String parseUnitedGroup(JSONObject junit) {
		JSONArray jgroup = junit.getJSONArray("group");
		StringBuilder groupBuilder = new StringBuilder();
		for (int i = 0; i < jgroup.size(); ++i) {
			junit = jgroup.getJSONObject(i);
			if (junit.containsKey("group")) {
				groupBuilder.append(parseUnitedGroup(junit));
			} else if (junit.containsKey("col")) {
				groupBuilder.append(parseUnit(junit));
			} else if (junit.containsKey("and")) {
				groupBuilder.append(parseUnitedAnd(junit));
			}
		}
		return " ( " + groupBuilder.toString() + " ) ";
	}

	private String parseAdvance() {
		JSONObject search = mJo.getJSONObject("search");
		JSONArray jadvanced = null;
		if (!search.isNullObject() && search.has("advanced")) {
			jadvanced = search.getJSONArray("advanced");
		}
		StringBuilder advanceBuilder = new StringBuilder();
		advanceBuilder.append("");
		boolean firstSql = true;

		if (null != jadvanced) {
			int column = 0;
			// Field[] fields = HTXX.class.getDeclaredFields();
			for (int i = 0; i < jadvanced.size(); ++i) {
				if (!jadvanced.getString(i).isEmpty()) {
					if (firstSql) {
						firstSql = false;
					} else {
						advanceBuilder.append(" and ");
					}

					if (paramHtxxColMap.containsKey(i)) {
						mNeedsHtxx = true;
						column = paramHtxxColMap.get(i);
						Field fd = HTXX.getField(column);
						Class<?> cls = HTXX.getFroeignClass(column);
						String sql = null;
						if (null != cls) {

							if (null != mTranslator) {
								String newValue = mTranslator.in(
										getForginName(cls),
										jadvanced.getString(i));
								if (null != newValue) {
									jadvanced.set(i, newValue);
								}
							}
							sql = QueryColumnCommandParser.parse(String.class,
									cls.getSimpleName() + "_."
											+ getForginName(cls),
									jadvanced.getString(i));
							if (null == sql) {
								sql = cls.getSimpleName() + "_."
										+ getForginName(cls) + " = '"
										+ jadvanced.getString(i) + "' ";
							}
							connectMap.put(fd.getName(), cls);
						} else {
							if (null != mTranslator) {
								String newValue = mTranslator.in(fd.getName(),
										jadvanced.getString(i));
								if (null != newValue) {
									jadvanced.set(i, newValue);
								}
							}

							sql = QueryColumnCommandParser.parse(fd.getType(),
									"HTXX_." + fd.getName(),
									jadvanced.getString(i));

							if (fd.getType().getName()
									.equals(String.class.getName())
									|| fd.getType().getName()
											.equals(Date.class.getName())) {
								if (null == sql) {
									sql = "HTXX_." + fd.getName() + " = '"
											+ jadvanced.getString(i) + "' ";
								}

							} else {
								if (null == sql) {
									sql = "HTXX_." + fd.getName() + " = "
											+ jadvanced.getString(i) + " ";
								}

							}
						}
						advanceBuilder.append(sql);
					} else if (paramPcjhColMap.containsKey(i)) {
						column = paramPcjhColMap.get(i);
						Field fd = PCJHXX.getField(column);
						if (null != mTranslator) {
							String newValue = mTranslator.in(fd.getName(),
									jadvanced.getString(i));
							if (null != newValue) {
								jadvanced.set(i, newValue);
							}
						}

						String sql = QueryColumnCommandParser.parse(
								fd.getType(), "PCJHXX_." + fd.getName(),
								jadvanced.getString(i));
						if (null == sql) {
							sql = "PCJHXX_." + fd.getName() + " = '"
									+ jadvanced.getString(i) + "' ";
						}
						advanceBuilder.append(sql);
					}
				}
			}
		}
		return advanceBuilder.toString();
	}

	private String getApproveSql(String type, boolean approved) {
		if ("plan".equals(type)) {
			if (approved) {
				return " PCJHXX_.sftgjhsh = 'Y' ";
			} else {
				return " PCJHXX_.sftgjhsh = 'N' ";
			}
		} else if ("business".equals(type)) {
			if (approved) {
				return " PCJHXX_.sftgywsh = 'Y' ";
			} else {
				return " PCJHXX_.sftgywsh = 'N' ";
			}
		} else if ("pack_plan".equals(type)) {
			if (approved) {
				return " PCJHXX_.bzsftgjhsh = 'Y' ";
			} else {
				return " PCJHXX_.bzsftgjhsh = 'N' ";
			}
		} else if ("pack_business".equals(type)) {
			if (approved) {
				return " PCJHXX_.bzsftgywsh = 'Y' ";
			} else {
				return " PCJHXX_.bzsftgywsh = 'N' ";
			}
		}
		return "";
	}

	private String parseApproveItem(JSONArray japprove) {
		boolean firstSql = true;
		String approve = "";
		String sqlApprove;
		for (int i = japprove.size() - 1; i >= 0; --i) {
			sqlApprove = getApproveSql(
					japprove.getJSONObject(i).getString("type"), japprove
							.getJSONObject(i).getBoolean("approved"));
			if (!sqlApprove.isEmpty()) {
				if (firstSql) {
					firstSql = false;
					approve += " ( ";
				} else {
					approve += " and ";
				}
				approve += sqlApprove;
			}
		}

		if (!firstSql) {
			approve += ") ";
		}
		return approve;
	}

	private String parseApprove() {
		StringBuilder sb = new StringBuilder();
		if (!mJo.has("approve")) {
			return "";
		}
		JSONArray japprove = mJo.getJSONArray("approve");
		if (null == japprove) {
			return "";
		}
		boolean firstSql = true;
		for (int i = 0; i < japprove.size(); ++i) {
			String approveItem = parseApproveItem(japprove.getJSONArray(i));
			if (!"".equals(approveItem)) {
				if (firstSql) {
					firstSql = false;
				} else {
					sb.append(" or ");
				}

				sb.append(approveItem);
			}
		}
		if (!firstSql) {
			return " (" + sb.toString() + ") ";
		}
		return sb.toString();
	}

	public String toSql() {
		if (null == mJo) {
			return "from PCJHXX";
		}
		StringBuilder sqlBuilder = new StringBuilder();
		sqlBuilder.append("select PCJHXX_ from PCJHXX PCJHXX_");

		String where = getWhereSql();
		String order = getOrderSql();

		if (mNeedsHtxx) {
			sqlBuilder.append(", HTXX HTXX_");
		}

		for (String key : connectMap.keySet()) {
			sqlBuilder.append("," + connectMap.get(key).getSimpleName() + " "
					+ connectMap.get(key).getSimpleName() + "_");
		}

		boolean firstSql = true;
		;
		if (!where.isEmpty() || !connectMap.isEmpty() || mNeedsHtxx) {
			sqlBuilder.append(" where ");
		}

		if (mNeedsHtxx) {
			if (firstSql) {
				firstSql = false;
			} else {
				sqlBuilder.append(" and ");
			}
			sqlBuilder.append("PCJHXX_.htxxID = HTXX_.ID");
		}

		for (String key : connectMap.keySet()) {
			if (firstSql) {
				firstSql = false;
			} else {
				sqlBuilder.append(" and ");
			}
			sqlBuilder.append(" HTXX_." + key + "="
					+ connectMap.get(key).getSimpleName() + "_."
					+ getForginId(connectMap.get(key)) + " ");
		}

		if (!where.isEmpty()) {
			if (!firstSql) {
				sqlBuilder.append(" and ");
			}
			sqlBuilder.append(where);
		}

		if (!order.isEmpty()) {
			sqlBuilder.append(" order by ").append(order);
		}
		return sqlBuilder.toString();
	}

	private String getOrderSql() {
		StringBuilder sqlBuilder = new StringBuilder();
		boolean firstSql = true;
		sqlBuilder.append("");
		if (!mJo.has("sort")) {
			return sqlBuilder.toString();
		}

		JSONArray jsort = mJo.getJSONArray("sort");

		// Field[] fields = HTXX.class.getDeclaredFields();
		int col = 0;
		for (int i = 0; i < jsort.size(); ++i) {
			col = jsort.getJSONObject(i).getInt("col");
			String order = jsort.getJSONObject(i).getBoolean("order") ? " asc "
					: " desc ";
			if (paramHtxxColMap.containsKey(col)) {
				// connectMap.put("htxxID", HTXX.class);
				mNeedsHtxx = true;
				col = paramHtxxColMap.get(col);

				Class<?> cls = HTXX.getFroeignClass(col);
				Field fd = HTXX.getField(col);
				if (firstSql) {
					firstSql = false;
				} else {
					sqlBuilder.append(",");
				}

				if (null != cls) {
					connectMap.put(fd.getName(), cls);

					if (CPGGXHXX.class.equals(cls)) {
						sqlBuilder.append(cls.getSimpleName() + "_.xh" + order
								+ ",");
						sqlBuilder.append(cls.getSimpleName() + "_.ts" + order
								+ ",");
						sqlBuilder.append(cls.getSimpleName() + "_.dw" + order);
						
					} else {
						sqlBuilder.append(cls.getSimpleName() + "_."
								+ getForginName(cls) + order);
					}
				} else {
					sqlBuilder
							.append("HTXX_."
									+ fd.getName()
									+ (jsort.getJSONObject(i).getBoolean(
											"order") ? " asc " : " desc "));
				}
			} else if (paramPcjhColMap.containsKey(col)) {
				col = paramPcjhColMap.get(col);
				Field fd = PCJHXX.getField(col);
				sqlBuilder.append("PCJHXX_." + fd.getName() + order);
			}

		}

		return sqlBuilder.toString();
	}
}
