package com.BlueRay.mutton.model.dao;

import java.lang.reflect.Field;
import java.sql.Date;
import java.util.HashMap;
import java.util.Map;

import com.BlueRay.mutton.model.entity.jpa.BMQXHFLXX;
import com.BlueRay.mutton.model.entity.jpa.BPQXHFLXX;
import com.BlueRay.mutton.model.entity.jpa.BZXDTGG;
import com.BlueRay.mutton.model.entity.jpa.CPGGXHXX;
import com.BlueRay.mutton.model.entity.jpa.HTXX;
import com.BlueRay.mutton.model.entity.jpa.KHQY;
import com.BlueRay.mutton.model.entity.jpa.KHXX;
import com.BlueRay.mutton.model.entity.jpa.MPZLXX;
import com.BlueRay.mutton.model.entity.jpa.YYLGGFLXX;
import com.BlueRay.mutton.model.entity.jpa.ZCXX;
import com.BlueRay.mutton.model.entity.jpa.ZDQDYFLXX;
import com.BlueRay.mutton.model.entity.jpa.ZDQXH;
import com.BlueRay.mutton.model.entity.jpa.ZJDY;
import com.BlueRay.mutton.model.entity.jpa.ZJYS;
import com.BlueRay.mutton.model.entity.jpa.ZZS;
import com.BlueRay.mutton.service.HtxxColumn;

import net.sf.json.JSONArray;
import net.sf.json.JSONObject;

//{
//approve : [[{
//	type : business / plan,
//	approved : true/false
//}],[{
//	type : business / plan,
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
//	"united": [
//	{
//		"col": 1,
//			"param" : "1111"
//	},
//	{
//		"and": true
//	},
//	{
//		"group": [
//		{
//			"col": 2,
//				"param" : "123"
//		},
//		{
//			"and": false
//		},
//		{
//			"col": 3,
//			"param" : "1243"
//		}
//		]
//	},
//	{
//		"and": false
//	},
//	{
//		"col": 8,
//		"param" : "123"
//	}
//],
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
//	private static Map<Integer, Integer> paramColMap = new HashMap<Integer, Integer>();
//	{
//		for (int i = 0; i < HtxxColumn.end.ordinal() - 1; ++i) {
//			paramColMap.put(i, i + 1);
//		}
//	}

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
			whereBuilder.append("  ( " +unitedSql + " ) ");
		}

		return whereBuilder.toString();
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
			for (int i = 0; i < junited.size(); ++i){
				junit = junited.getJSONObject(i);
				if (junit.containsKey("group")){
					unitedBuilder.append(parseUnitedGroup(junit));
				} else if(junit.containsKey("col")){
					unitedBuilder.append(parseUnit(junit));
				} else if(junit.containsKey("and")){
					unitedBuilder.append(parseUnitedAnd(junit));
				}
			}
		}
		return unitedBuilder.toString();
	}

	private String parseUnit(JSONObject junit) {
		int index = junit.getInt("col");
		String param = junit.getString("param");
		Class<?> cls = HTXX.getFroeignClass(index + 1);
		String keyName = null;
		//Field[] fields = HTXX.class.getDeclaredFields();
		String sql = null;
		Field field = HTXX.getField(index + 1);
		if (null != mTranslator) {
			String newValue = mTranslator.in(
					field.getName(),
					param);
			if (null != newValue) {
				param = newValue;
			}
		}
		if (null != cls){
			connectMap.put(field.getName(), cls);
			keyName = cls.getSimpleName() + "_."
					+ getForginName(cls);			
			sql = QueryColumnCommandParser
					.parse(String.class, keyName, param);
			if (null == sql){
				sql = keyName + " = '" + param + "'";
			}
			connectMap.put(field.getName(), cls);
		}
		else {
			keyName = "HTXX_." + field.getName();
			sql = QueryColumnCommandParser.parse(field.getType(), keyName, param);
			if (null == sql) {
				if (field.getType().getName()
						.equals(String.class.getName())
						|| field.getType().getName()
								.equals(Date.class.getName())) {
					sql = keyName + " = '" + param + "'";
				} else {
					sql = keyName + " = " + param;
				}
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
		for (int i = 0; i < jgroup.size(); ++i){
			junit = jgroup.getJSONObject(i);
			if (junit.containsKey("group")){
				groupBuilder.append(parseUnitedGroup(junit));
			} else if(junit.containsKey("col")){
				groupBuilder.append(parseUnit(junit));
			} else if(junit.containsKey("and")){
				groupBuilder.append(parseUnitedAnd(junit));
			}
		}
		return " ( " + groupBuilder.toString() + " ) ";
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
			//Field[] fields = HTXX.class.getDeclaredFields();
			String link = null;
			for (int i = HtxxColumn.hth.ordinal(); i < HtxxColumn.end.ordinal(); ++i) {

				Class<?> cls = HTXX.getFroeignClass(i);
				Field field = HTXX.getField(i);
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
						searchText = "'%" + normaltext + "%'";
					} else {
						link = " = ";
						
					}
					connectMap.put(field.getName(), cls);
					basicBuilder.append(cls.getSimpleName() + "_."
							+ getForginName(cls) + link + searchText + " ");
				} else {

					if ((!bIsInteger && field.getType().getName()
							.equals(Integer.class.getName()))
							|| !bIsDate
							&& field.getType().getName()
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
					if (field.getType().getName()
							.equals(String.class.getName())
							|| field.getType().getName()
									.equals(Date.class.getName())) {
						searchText = stringSearch;
						if (!exact
								&& field.getType().getName()
										.equals(String.class.getName())) {
							link = " like ";
							searchText = "'%" + normaltext + "%'";
						}
					} else {
						searchText = normaltext;
					}

					basicBuilder.append(" HTXX_." + field.getName() + link
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
			for (int i = 0; i < jadvanced.size() && i < HtxxColumn.end.ordinal(); ++i) {
				if (!jadvanced.getString(i).isEmpty()) {
					
					Field field = HTXX.getField(i);
					
					if (firstSql) {
						firstSql = false;
					} else {
						advanceBuilder.append(" and ");
					}
					if (null != mTranslator) {
						String newValue = mTranslator.in(
								field.getName(),
								jadvanced.getString(i));
						if (null != newValue) {
							jadvanced.set(i, newValue);
						}
					}

					Class<?> cls = HTXX.getFroeignClass(i);
					String sql = null;
					if (null != cls) {
						sql = QueryColumnCommandParser
								.parse(String.class, cls.getSimpleName() + "_."
										+ getForginName(cls),
										jadvanced.getString(i));
						if (null == sql) {
							sql = cls.getSimpleName() + "_."
									+ getForginName(cls) + " = '"
									+ jadvanced.getString(i) + "' ";
						}
						connectMap.put(field.getName(), cls);
					} else {
						sql = QueryColumnCommandParser.parse(field.getType(), "HTXX_."
								+ field.getName(),
								jadvanced.getString(i));
						if (null == sql) {
							if (field.getType().getName()
									.equals(String.class.getName())
									|| field.getType().getName()
											.equals(Date.class.getName())) {
								sql = "HTXX_." + field.getName()
										+ " = '" + jadvanced.getString(i)
										+ "' ";
							} else {
								sql = "HTXX_." + field.getName()
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
			if (!sqlApprove.isEmpty()){
				if (firstSql){
					firstSql = false;
					approve += " ( ";
				}
				else{
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

		//Field[] fields = HTXX.class.getDeclaredFields();
		//int col = 0;
		for (int i = 0; i < jsort.size(); ++i) {
			int col = jsort.getJSONObject(i).getInt("col");
			if (col < HtxxColumn.end.ordinal()) {
				if (firstSql) {
					firstSql = false;
				} else {
					sqlBuilder.append(",");
				}
				Class<?> cls = HTXX.getFroeignClass(col + 1);
				String order = jsort.getJSONObject(i).getBoolean(
						"order") ? " asc " : " desc ";
				Field field = HTXX.getField(col + 1);
				if (null != cls) {
					connectMap.put(field.getName(), cls);
					
					if (CPGGXHXX.class.equals(cls)){
						sqlBuilder
						.append(cls.getSimpleName()
								+ "_.xh"
								+ order + ",");
						sqlBuilder
						.append(cls.getSimpleName()
								+ "_.dw"
								+ order + ",");
						sqlBuilder
						.append(cls.getSimpleName()
								+ "_.ts"
								+ order);
					}
					else {
						sqlBuilder
						.append(cls.getSimpleName()
								+ "_."
								+ getForginName(cls)
								+ order);
					}
					
				
				} else {
					sqlBuilder
							.append("HTXX_."
									+ field.getName()
									+ order);
				}
			}
		}

		return sqlBuilder.toString();
	}
}
