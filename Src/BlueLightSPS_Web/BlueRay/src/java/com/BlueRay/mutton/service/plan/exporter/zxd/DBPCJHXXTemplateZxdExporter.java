package com.BlueRay.mutton.service.plan.exporter.zxd;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import org.apache.poi.hssf.usermodel.HSSFCellStyle;
import org.apache.poi.hssf.usermodel.HSSFFont;
import org.apache.poi.hssf.usermodel.HSSFWorkbook;
import org.apache.poi.hssf.util.HSSFColor;
import com.BlueRay.mutton.common.PcjhColumn;
import com.BlueRay.mutton.common.RequestHandler;
import com.BlueRay.mutton.model.dao.ItemDao;
import com.BlueRay.mutton.model.dao.PlanDao;
import com.BlueRay.mutton.model.dao.SaleDao;
import com.BlueRay.mutton.model.dao.ZxdDao;
import com.BlueRay.mutton.model.entity.jpa.CPGGXHXX;
import com.BlueRay.mutton.model.entity.jpa.HTXX;
import com.BlueRay.mutton.model.entity.jpa.PCJHXX;
import com.BlueRay.mutton.service.plan.PlanServiceImpl;
import com.BlueRay.mutton.service.plan.exporter.zxd.config.ConfigurationFactory;
import com.BlueRay.mutton.service.plan.exporter.zxd.handler.EnglishRequestHandler;
import com.BlueRay.mutton.service.plan.exporter.zxd.handler.GrSTAURequestHandler;
import com.BlueRay.mutton.service.plan.exporter.zxd.handler.GrYRequestHandler;
import com.BlueRay.mutton.service.plan.exporter.zxd.handler.Request;
import com.BlueRay.mutton.service.plan.exporter.zxd.handler.Request.GGXHPicker;
import com.BlueRay.mutton.service.plan.exporter.zxd.handler.UsualRequestHandler;
import com.BlueRay.mutton.service.plan.exporter.zxd.handler.WksRequestHandler;
import com.BlueRay.mutton.service.plan.exporter.zxd.handler.XdRequestHandler;
import com.BlueRay.mutton.service.plan.exporter.zxd.handler.ZjydRequestHandler;
import com.BlueRay.mutton.tool.AbstractExcel;
import com.BlueRay.mutton.tool.IExcelExporter;

public class DBPCJHXXTemplateZxdExporter implements IExcelExporter<PCJHXX> {

	ItemDao itemDao;
	SaleDao saleDao;
	PlanDao planDao;
	AbstractExcel<PCJHXX> excel;
	OutputStream os;
	ZxdDao zxdDao;
	ConfigurationFactory configFactory = new ConfigurationFactory();

	public DBPCJHXXTemplateZxdExporter(ItemDao itemDao, SaleDao saleDao,
			PlanDao planDao, ZxdDao zxdDao, AbstractExcel<PCJHXX> excel, OutputStream os) {
		this.itemDao = itemDao;
		this.saleDao = saleDao;
		this.planDao = planDao;
		this.excel = excel;
		this.os = os;
		this.zxdDao = zxdDao;
	}

	public void exports() throws IOException {

		final Map<Integer, HTXX> htxxMap = new HashMap<Integer, HTXX>();

		HSSFWorkbook workbook = new HSSFWorkbook(new FileInputStream(new File(
				configFactory.getPathTemplate())));

		HSSFCellStyle style = workbook.createCellStyle();
		style.setBorderBottom(HSSFCellStyle.BORDER_THIN); // 下边框
		style.setBorderLeft(HSSFCellStyle.BORDER_THIN);// 左边框
		style.setBorderTop(HSSFCellStyle.BORDER_THIN);// 上边框
		style.setBorderRight(HSSFCellStyle.BORDER_THIN);// 右边框
		HSSFFont font = workbook.createFont();
		font.setFontHeightInPoints((short) 10);
		style.setFont(font);

		HSSFCellStyle styleHighlight = workbook.createCellStyle();
		styleHighlight.setBorderBottom(HSSFCellStyle.BORDER_THIN); // 下边框
		styleHighlight.setBorderLeft(HSSFCellStyle.BORDER_THIN);// 左边框
		styleHighlight.setBorderTop(HSSFCellStyle.BORDER_THIN);// 上边框
		styleHighlight.setBorderRight(HSSFCellStyle.BORDER_THIN);// 右边框
		styleHighlight.setFillForegroundColor(HSSFColor.YELLOW.index);
		styleHighlight.setFillBackgroundColor(HSSFColor.YELLOW.index);
		styleHighlight.setFillPattern(HSSFCellStyle.SOLID_FOREGROUND);
		styleHighlight.setFont(font);

		List<PCJHXX> pcxxs = new ArrayList<PCJHXX>(1);
		pcxxs.add(null);
		String[] record = new String[PcjhColumn.end.ordinal()];

		RequestHandler<Request> handler = new EnglishRequestHandler(
				configFactory.getEnglishConfiguration());
		handler.next(
				new GrSTAURequestHandler(configFactory.getGrSTAUConfiguration(), zxdDao))
				.next(new GrYRequestHandler(configFactory.getGrYConfiguration(), zxdDao))
				.next(new WksRequestHandler(configFactory.getWksConfiguration(), zxdDao))
				.next(new XdRequestHandler(configFactory.getXdConfiguration()))
				.next(new ZjydRequestHandler(configFactory.getZjydConfiguration(), zxdDao))
				.next(new UsualRequestHandler(configFactory
						.getUsualConfiguration()));

		Request req = new Request();
		req.record = record;
		req.workbook = workbook;
		for (int i = 0, len = excel.getRowCount(); i < len; ++i) {
			final PCJHXX pcjh = excel.getRow(i);
			pcxxs.set(0, pcjh);
			PlanServiceImpl.getHtxxMap(pcxxs, saleDao, planDao, htxxMap);
			PlanServiceImpl.setPCJH(record, pcxxs.get(0), htxxMap, itemDao);

			req.setGGXHPicker(new GGXHPicker() {
				public CPGGXHXX pick() {
					HTXX htxx = htxxMap.get(pcjh.getHtxxID());
					CPGGXHXX ggxh = itemDao.queryCpggxhxxById(htxx.getGgxhID());
					return ggxh;
				}
			});

			handler.handle(req);
		}

		for (int i = 6; i >= 0; --i) {
			workbook.removeSheetAt(i);
		}

		workbook.write(os);
	}

}
