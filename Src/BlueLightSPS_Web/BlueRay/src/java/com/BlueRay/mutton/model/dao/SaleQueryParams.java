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
import com.BlueRay.mutton.model.entity.jpa.YYLGGFLXX;
import com.BlueRay.mutton.model.entity.jpa.ZCXX;
import com.BlueRay.mutton.model.entity.jpa.ZDQDYFLXX;

import net.sf.json.JSONArray;
import net.sf.json.JSONObject;

//{
//approve : {
//	type : approved / unapproved,
//	approve : true/false
//},
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
//    {
//    	col : index,
//    	order : true/false
//    },
//    {
//    	col : index,
//    	order : true/false
//    }
//]
//}

public class SaleQueryParams {
	private JSONObject mJo;
	private Map<String, Class<?>> connectMap = new HashMap<String, Class<?>>();

	public SaleQueryParams(JSONObject jo) {
		mJo = jo;
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

		if (!advancedSql.isEmpty()) {
			if (firstSql) {
				firstSql = false;
			} else {
				whereBuilder.append(" and ");
			}
			whereBuilder.append(advancedSql);
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
			strDate = "HTXX_.ddrq >= '" + jdate.getString("startDate")
					+ "' and " + "HTXX_.ddrq <= '" + jdate.getString("endDate")
					+ "' ";
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
			try {
				Integer.valueOf(stringSearch);
				bIsInteger = true;
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
							|| fields[i].getType().getName()
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
							.equals(String.class.getName())) {
						searchText = stringSearch;
						if (!exact) {
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
			for (int i = 0; i < jadvanced.size(); ++i) {
				if (!jadvanced.getString(i).isEmpty()) {
					// if (i + 1 == fields.length - 1){
					//
					// }
					// else{
					if (firstSql) {
						firstSql = false;
					} else {
						advanceBuilder.append(" and ");
					}

					Class<?> cls = HTXX.getFroeignClass(i + 1);
					if (null != cls) {
						advanceBuilder.append(cls.getSimpleName() + "_."
								+ getForginName(cls) + " = "
								+ jadvanced.getString(i) + " ");
						connectMap.put(fields[i + 1].getName(), cls);
					} else {
						advanceBuilder.append("HTXX_."
								+ fields[i + 1].getName() + " = "
								+ jadvanced.getString(i) + " ");
					}
					// }
				}
			}
		}
		return advanceBuilder.toString();
	}

	private String parseApprove() {
		JSONObject japprove = mJo.getJSONObject("approve");
		if ("unapproved".equals(japprove.getString("type"))) {
			if (japprove.getBoolean("approve")) {
				return " HTXX_.sftgjhsh = 'Y' ";
			} else {
				return " HTXX_.sftgjhsh = 'N' ";
			}
		} else if ("approved".equals(japprove.getString("type"))) {
			if (japprove.getBoolean("approve")) {
				return " HTXX_.sftgywsh = 'Y' ";
			} else {
				return " HTXX_.sftgywsh = 'N' ";
			}
		}
		return "";
	}

	public String toSql() {
		if (null == mJo) {
			return "from HTXX";
		}
		StringBuilder sqlBuilder = new StringBuilder();
		sqlBuilder.append("select HTXX_ from HTXX HTXX_");
		// if (mJo.has("search") && (mJo.getJSONObject("search").has("advanced")
		// || mJo.getJSONObject("search").has("basic")) || mJo.has("sort")){
		// sqlBuilder.append(", KHXX KHXX_, CPGGXHXX CPGGXHXX_, ZCXX ZCXX_, ZDQDYFLXX ZDQDYFLXX_, YYLGGFLXX YYLGGFLXX_, BPQXHFLXX BPQXHFLXX_, BMQXHFLXX BMQXHFLXX_ ");
		// }

		String where = getWhereSql();
		String order = getOrderSql();

		for (String key : connectMap.keySet()) {
			sqlBuilder.append("," + connectMap.get(key).getSimpleName() + " "
					+ connectMap.get(key).getSimpleName() + "_");
		}
		
		boolean firstSql = true;;
		if (!where.isEmpty() || !connectMap.isEmpty()){
			sqlBuilder.append(" where ");
		}

		for (String key : connectMap.keySet()) {
			if (firstSql){
				firstSql = false;
			}
			else{
				sqlBuilder.append(" and ");
			}
			sqlBuilder.append(" HTXX_." + key + "="
					+ connectMap.get(key).getSimpleName() + "_."
					+ getForginId(connectMap.get(key)) + " ");	
		}
		
		if (!where.isEmpty()) {
			if (!firstSql){
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
			col = jsort.getJSONObject(i).getInt("col") + 1;

			if (firstSql) {
				firstSql = false;
			} else {
				sqlBuilder.append(",");
			}
			Class<?> cls = HTXX.getFroeignClass(col);
			if (null != cls) {
				sqlBuilder.append(cls.getSimpleName()
						+ "_."
						+ getForginName(cls)
						+ (jsort.getJSONObject(i).getBoolean("order") ? " asc "
								: " desc "));
			} else {
				sqlBuilder.append("HTXX_."
						+ fields[col].getName()
						+ (jsort.getJSONObject(i).getBoolean("order") ? " asc "
								: " desc "));
			}
		}

		return sqlBuilder.toString();
	}
}
