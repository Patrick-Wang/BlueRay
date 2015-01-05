package com.BlueRay.mutton.model.dao;

import java.lang.reflect.Field;
import java.sql.Date;
import java.util.HashMap;
import java.util.Map;

import com.BlueRay.mutton.model.entity.jpa.BMQXHFLXX;
import com.BlueRay.mutton.model.entity.jpa.BPQXHFLXX;
import com.BlueRay.mutton.model.entity.jpa.CPGGXHXX;
import com.BlueRay.mutton.model.entity.jpa.HTXX;
import com.BlueRay.mutton.model.entity.jpa.KHXX;
import com.BlueRay.mutton.model.entity.jpa.MPZLXX;
import com.BlueRay.mutton.model.entity.jpa.YYLGGFLXX;
import com.BlueRay.mutton.model.entity.jpa.ZCXX;
import com.BlueRay.mutton.model.entity.jpa.ZDQDYFLXX;

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

public class SaleQueryParams {

	private IAdvanceTranslator mTranslator;
	private JSONObject mJo;
	private Map<String, Class<?>> connectMap = new HashMap<String, Class<?>>();
	private static Map<Integer, Integer> paramColMap = new HashMap<Integer, Integer>();
	{
		for (int i = 0; i < 19; ++i) {
			paramColMap.put(i, i + 1);
		}
	}

	public SaleQueryParams(JSONObject jo, IAdvanceTranslator translator) {
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
		}
		return colName;
	}

	private String getWhereSql() {
		StringBuilder whereBuilder = new StringBuilder();
		String approveSql = parseApprove();
		String advancedSql = parseAdvance();
		String basicSql = parseBasic();
		String dateSql = parseDateRange();
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
			Field[] fields = HTXX.class.getDeclaredFields();
			String link = null;
			for (int i = 1; i < fields.length - 1; ++i) {

				Class<?> cls = HTXX.getFroeignClass(i);

				if (null != cls) {
					if (firstSql) {
						firstSql = false;
						basicBuilder.append("( ");
					} else {
						basicBuilder.append(" or ");
					}

					if (!exact) {
						link = " like ";
					} else {
						link = " = ";
					}
					connectMap.put(fields[i].getName(), cls);
					searchText = stringSearch;
					basicBuilder.append(cls.getSimpleName() + "_."
							+ getForginName(cls) + link + searchText + " ");
				} else {

					if ((!bIsInteger && fields[i].getType().getName()
							.equals(Integer.class.getName()))
							|| !bIsDate
							&& fields[i].getType().getName()
									.equals(Date.class.getName())) {
						continue;
					}

					if (firstSql) {
						firstSql = false;
						basicBuilder.append("( ");
					} else {
						basicBuilder.append(" or ");
					}

					link = " = ";
					if (fields[i].getType().getName()
							.equals(String.class.getName())
							|| fields[i].getType().getName()
									.equals(Date.class.getName())) {
						searchText = stringSearch;
						if (!exact
								&& fields[i].getType().getName()
										.equals(String.class.getName())) {
							link = " like ";
						}
					} else {
						searchText = normaltext;
					}

					basicBuilder.append(" HTXX_." + fields[i].getName() + link
							+ searchText + " ");
				}
			}
			if (!firstSql) {
				basicBuilder.append(" ) ");
			}
		}

		return basicBuilder.toString();
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
			Field[] fields = HTXX.class.getDeclaredFields();
			int column = 0;
			for (int i = 0; i < jadvanced.size(); ++i) {
				if (!jadvanced.getString(i).isEmpty()
						&& paramColMap.containsKey(i)) {
					column = paramColMap.get(i);
					if (firstSql) {
						firstSql = false;
					} else {
						advanceBuilder.append(" and ");
					}

					if (null != mTranslator) {
						String newValue = mTranslator.in(
								fields[column].getName(),
								jadvanced.getString(i));
						if (null != newValue) {
							jadvanced.set(i, newValue);
						}
					}

					Class<?> cls = HTXX.getFroeignClass(column);
					String sql = null;
					if (null != cls) {
						sql = QueryColumnCommandParser
								.parse(cls.getSimpleName() + "_."
										+ getForginName(cls),
										jadvanced.getString(i));
						if (null == sql) {
							sql = cls.getSimpleName() + "_."
									+ getForginName(cls) + " = '"
									+ jadvanced.getString(i) + "' ";
						}
						connectMap.put(fields[column].getName(), cls);
					} else {
						sql = QueryColumnCommandParser.parse("HTXX_."
								+ fields[column].getName(),
								jadvanced.getString(i));
						if (null == sql) {
							if (fields[column].getType().getName()
									.equals(String.class.getName())
									|| fields[column].getType().getName()
											.equals(Date.class.getName())) {
								sql = "HTXX_." + fields[column].getName()
										+ " = '" + jadvanced.getString(i)
										+ "' ";
							} else {
								sql = "HTXX_." + fields[column].getName()
										+ " = " + jadvanced.getString(i) + " ";
							}
						}
					}
					advanceBuilder.append(sql);
				}
			}
		}
		return advanceBuilder.toString();
	}

	private String getApproveSql(String type, boolean approved) {
		if ("business".equals(type)) {
			if (approved) {
				return " HTXX_.sftgywsh = 'Y' ";
			} else {
				return " HTXX_.sftgywsh = 'N' ";
			}
		} else if ("plan".equals(type)) {
			if (approved) {
				return " HTXX_.sftgjhsh = 'Y' ";
			} else {
				return " HTXX_.sftgjhsh = 'N' ";
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
				} else {
					approve += " and ";
				}
				approve += sqlApprove;
			}
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

				sb.append(" ( ");
				sb.append(approveItem);
				sb.append(" ) ");
			}
		}

		return sb.toString();
	}

	public String toSql() {
		if (null == mJo) {
			return "from HTXX";
		}
		StringBuilder sqlBuilder = new StringBuilder();
		sqlBuilder.append("select HTXX_ from HTXX HTXX_");

		String where = getWhereSql();
		String order = getOrderSql();

		for (String key : connectMap.keySet()) {
			sqlBuilder.append("," + connectMap.get(key).getSimpleName() + " "
					+ connectMap.get(key).getSimpleName() + "_");
		}

		boolean firstSql = true;
		;
		if (!where.isEmpty() || !connectMap.isEmpty()) {
			sqlBuilder.append(" where ");
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

		Field[] fields = HTXX.class.getDeclaredFields();
		int col = 0;
		for (int i = 0; i < jsort.size(); ++i) {
			col = jsort.getJSONObject(i).getInt("col");
			if (paramColMap.containsKey(col)) {
				col = paramColMap.get(col);
				if (firstSql) {
					firstSql = false;
				} else {
					sqlBuilder.append(",");
				}
				Class<?> cls = HTXX.getFroeignClass(col);
				if (null != cls) {
					connectMap.put(fields[col].getName(), cls);
					sqlBuilder
							.append(cls.getSimpleName()
									+ "_."
									+ getForginName(cls)
									+ (jsort.getJSONObject(i).getBoolean(
											"order") ? " asc " : " desc "));
				} else {
					sqlBuilder
							.append("HTXX_."
									+ fields[col].getName()
									+ (jsort.getJSONObject(i).getBoolean(
											"order") ? " asc " : " desc "));
				}
			}
		}

		return sqlBuilder.toString();
	}
}
