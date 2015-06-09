package com.BlueRay.mutton.service;

import java.io.IOException;
import java.io.OutputStream;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import com.BlueRay.mutton.model.dao.ItemDao;
import com.BlueRay.mutton.model.dao.PlanDao;
import com.BlueRay.mutton.model.dao.SaleDao;
import com.BlueRay.mutton.model.entity.jpa.HTXX;
import com.BlueRay.mutton.model.entity.jpa.PCJHXX;
import com.BlueRay.mutton.tool.AbstractExcel;
import com.BlueRay.mutton.tool.IExcelExporter;

class DBPCJHXXCSVExporter implements IExcelExporter<PCJHXX> {

	ItemDao itemDao;
	SaleDao saleDao;
	PlanDao planDao;
	AbstractExcel<PCJHXX> excel;
	OutputStream os;

	public DBPCJHXXCSVExporter(ItemDao itemDao, SaleDao saleDao,
			PlanDao planDao, AbstractExcel<PCJHXX> excel, OutputStream os) {
		super();
		this.itemDao = itemDao;
		this.saleDao = saleDao;
		this.planDao = planDao;
		this.excel = excel;
		this.os = os;
	}

	public void exports() throws IOException {

		Map<Integer, HTXX> htxxMap = new HashMap<Integer, HTXX>();

		//os.write(new byte[] { (byte) 0xEF, (byte) 0xBB, (byte) 0xBF });

		List<PCJHXX> pcxxs = new ArrayList<PCJHXX>(1);
		pcxxs.add(null);
		StringBuilder builder = new StringBuilder();
		String[] header = excel.getheader().get(0);
		boolean firstCol = true;
		for (short i = 0; i < header.length; i++) {
			if (firstCol) {
				firstCol = false;
			} else {
				builder.append(",");
			}
			builder.append(header[i]);
		}

		builder.append("\r\n");
		String[] ret = new String[PcjhColumn.end.ordinal()];
		for (int i = 0, len = excel.getRowCount(); i < len; ++i) {
			pcxxs.set(0, excel.getRow(i));
			PlanServiceImpl.getHtxxMap(pcxxs, saleDao, planDao, htxxMap);
			PlanServiceImpl.setPCJH(ret, pcxxs.get(0), htxxMap, itemDao);
			firstCol = true;
			for (int j = 1; j < ret.length; ++j) {
				if (firstCol) {
					firstCol = false;
				} else {
					builder.append(",");
				}
				builder.append(ret[j]);
			}
			builder.append("\r\n");

			os.write(builder.toString().getBytes("utf-8"));
			builder = new StringBuilder();
			os.flush();

		}
	}

}
