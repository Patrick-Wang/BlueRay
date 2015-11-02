package com.BlueRay.mutton.service.plan.exporter;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

import org.w3c.dom.Element;
import org.w3c.dom.NodeList;

import com.BlueRay.mutton.common.Location;
import com.BlueRay.mutton.common.PcjhColumn;

public class ConfigurationUtil {

	private final static String ATTR_COL = "col";
	private final static String ATTR_ROW = "row";
	private final static String TAG_SHEET_NAME = "sheet_name";
	private final static String TAG_BASE_ROW = "baseRow";
	private final static String TAG_TABLE_FIELD = "table_field";
	private final static String TAG_CELL = "cell";
	private final static String ATTR_NAME = "name";

	
	public static Element getByTag(Element eSheet, String tagName){
		if (eSheet != null){
		NodeList list = eSheet.getElementsByTagName(tagName);
		if (list.getLength() > 0){
			return (Element) list.item(0);
		}
		}
		return null;
	}
	
	public static Location loadLocation(
			Element eSheet, String tagName) {
		
			Element cell = getByTag(eSheet, tagName);
			if (cell != null){
				return new Location(cell.getAttribute(ATTR_COL), Integer.valueOf(cell
						.getAttribute(ATTR_ROW)));
			}
		
		return null;
	
	}
	
	public static void loadLocation(Map<Integer, List<Location>> locsMap,
			Element eSheet, int key, String tagName) {
		
		if (!locsMap.containsKey(key)) {
			locsMap.put(key, new ArrayList<Location>());
		}
		Location loc = loadLocation(eSheet, tagName);
		if (null != loc){
			locsMap.get(key).add(loc);
		}
	}

	public static List<Location> loadLocationMultiCell(Element eTagElem) {
	
		 List<Location> locs = new ArrayList<Location>();
		if (null != eTagElem) {
			NodeList cells = eTagElem.getElementsByTagName(TAG_CELL);
			for (int j = 0; j < cells.getLength(); j++) {
				Element cell = (Element) cells.item(j);
				locs.add(
						new Location(cell.getAttribute(ATTR_COL), Integer
								.valueOf(cell.getAttribute(ATTR_ROW))));
			}
		}
		return locs;
	}

	public static List<Location> loadLocationMultiCell(Element eSheet, String tag) {
		Element e = getByTag(eSheet, tag);
		return loadLocationMultiCell(e);
	}

	public static void loadLocationMultiCell(
			Map<Integer, List<Location>> locsMap, int key, Element eTagElem
			) {
		if (!locsMap.containsKey(key)) {
			locsMap.put(key, new ArrayList<Location>());
		}
		locsMap.get(key).addAll(loadLocationMultiCell(eTagElem));
	}
	
	public static void loadLocationMultiCell(
			Map<Integer, List<Location>> locsMap, Element eSheet, int key,
			String tagName) {
		if (!locsMap.containsKey(key)) {
			locsMap.put(key, new ArrayList<Location>());
		}
		locsMap.get(key).addAll(loadLocationMultiCell(eSheet, tagName));
	}

	public static int getBaseRow(Element eSheet) {
		try {
			return Integer.valueOf(eSheet.getElementsByTagName(TAG_BASE_ROW)
					.item(0).getFirstChild().getNodeValue());
		} catch (Exception e) {
			return 0;
		}
	}

	public static String getSheetName(Element eSheet) {
		return eSheet.getElementsByTagName(TAG_SHEET_NAME).item(0)
				.getFirstChild().getNodeValue();
	}

	public static void loadTableFields(Map<Integer, List<Location>> locsMap,
			Element eSheet) {
		NodeList fields = eSheet.getElementsByTagName(TAG_TABLE_FIELD);

		for (int i = 0; i < fields.getLength(); i++) {
			Element eTagElem = (Element) fields.item(i);
			try {
				PcjhColumn enPcjh = PcjhColumn.valueOf(eTagElem
						.getAttribute(ATTR_NAME));
				loadLocationMultiCell(locsMap, enPcjh.ordinal(), eTagElem);
			} catch (Exception ex) {

			}
		}
	}
}
