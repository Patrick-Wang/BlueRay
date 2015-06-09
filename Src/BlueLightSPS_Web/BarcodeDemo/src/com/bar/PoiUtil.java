package com.bar;

import java.math.BigDecimal;

import org.apache.poi.hssf.usermodel.HSSFClientAnchor;
import org.apache.poi.hssf.usermodel.HSSFSheet;
import org.apache.poi.hssf.usermodel.HSSFWorkbook;
import org.apache.poi.ss.usermodel.Workbook;

public class PoiUtil {
	
	public static class FontInfo{
		int charWidth;
		int spacing;
	}
	
	private static final short TWIPS_PER_PIEXL = 15; //1 Pixel = 1440 TPI / 96 DPI = 15 Twips
	
	
    public static  int getAnchorX(int px, int colWidth){  
        return (int) Math.round((px * 1.0 / colWidth) * 1023.0);  
    }  
      
    public static int getAnchorY(int px, int rowHeight){  
        return (int) Math.round((px * 1.0 / rowHeight) * 255.0);  
    }  
	
	public static short pixel2PoiHeight(int pixel) {
		return (short) (pixel * TWIPS_PER_PIEXL);
	}

	public static int poiHeight2Pixel(short height) {
		return height / TWIPS_PER_PIEXL;
	}

	//像素转poi宽度
	public static int pixel2PoiWidth(FontInfo fontInfo, int pixel) {
		double numChars = pixel2Character(fontInfo, pixel);
		numChars *= fontInfo.charWidth;
		numChars += fontInfo.spacing;
		numChars /= fontInfo.charWidth;
		numChars *= 256;
		return (int)numChars;
	}
	
	//poi宽度转像素
	public static int poiWidth2Pixel(FontInfo fontInfo, int poiWidth) {
		double numChars = poiWidth2Character(fontInfo, poiWidth);
		return character2Piexl(fontInfo, numChars);
	}
	
	public static double poiWidth2Character(FontInfo fontInfo, int poiWidth){
		double numChars = poiWidth / 256.0 - (fontInfo.spacing * 1.0 / fontInfo.charWidth);
		//2位小数
		return new BigDecimal(numChars).setScale(2, BigDecimal.ROUND_HALF_UP).doubleValue();
	}
	
	public static int character2PoiWidth(FontInfo fontInfo, double numChars){
		double w = (numChars + (fontInfo.spacing * 1.0 / fontInfo.charWidth)) * 256;
		return (int) w;
	}
	
	//excel字符转像素
	public static int character2Piexl(FontInfo fontInfo, double numChars){
		double pixel = fontInfo.charWidth * numChars + fontInfo.spacing;
		return (int)pixel;
	}
	
	//excel像素转字符
	public static double pixel2Character(FontInfo fontInfo, int pixel){
		double numChars =  (pixel - fontInfo.spacing) * 1.0 / fontInfo.charWidth;
		return new BigDecimal(numChars).setScale(2, BigDecimal.ROUND_HALF_UP).doubleValue();
	}
	
	//获得工作簿默认字符宽度
	public static FontInfo getDefaultCharWidth(Workbook wb){
//		HSSFFont hf = (HSSFFont) wb.getFontAt((short) 0);
//		Font stringFont = new Font(hf.getFontName(),Font.PLAIN, hf.getFontHeightInPoints());//调用awt包中的Font类，这里有个问题：Font的构造函数最后一个参数是要表示font size，是用font.getFontHeightInPoints()得到吗？
//		Graphics graphics = new java.awt.image.BufferedImage(20, 20,java.awt.image.BufferedImage.TYPE_INT_ARGB ).getGraphics(); 
//		FontMetrics fontMetrics = graphics.getFontMetrics(stringFont);
//		String baseSize = "123456789";
//		int maxWidth = fontMetrics.stringWidth("0");
//		for(int i = 0; i < baseSize.length(); ++i){
//			int width = fontMetrics.stringWidth("" + baseSize.charAt(i));
//			if (width > maxWidth){
//				maxWidth = width;
//			}
//		}
		FontInfo fi = new FontInfo();
		fi.charWidth = 8;
		fi.spacing = 1;
		return fi;
	}
	
	//获得不同字体的字符边距 
	private static int getSpacing(int fontHeightInPoints, int charWidth){
		return 1;
	}
	
	public static HSSFClientAnchor measureAnchor(int col, int row, int dxPx, int dyPx, int picWidth, int picHeight, HSSFSheet sheet, HSSFWorkbook wb){
		HSSFClientAnchor anchor = new HSSFClientAnchor();

		anchor.setRow1(row);
		anchor.setCol1(col);
		FontInfo fi = PoiUtil.getDefaultCharWidth(wb);
		int k = PoiUtil.getAnchorX(dxPx, PoiUtil.poiWidth2Pixel(fi, sheet.getColumnWidth(col)));
		anchor.setDx1(k);
		k = PoiUtil.getAnchorY(dyPx, PoiUtil.poiHeight2Pixel(sheet.getRow(row).getHeight()));
		anchor.setDy1(k);
		int colTmp = col;
		int rowTmp = row;
		int startX = PoiUtil.poiWidth2Pixel(fi, sheet.getColumnWidth(col)) - dxPx;
		int startY = PoiUtil.poiHeight2Pixel(sheet.getRow(row).getHeight()) - dyPx;
		while (startX < picWidth){
			startX += PoiUtil.poiWidth2Pixel(fi, sheet.getColumnWidth(++colTmp));
		}
		

		anchor.setCol2(colTmp);
		k = PoiUtil.getAnchorX(
				PoiUtil.poiWidth2Pixel(fi, sheet.getColumnWidth(colTmp)) - (startX - picWidth), 
				PoiUtil.poiWidth2Pixel(fi, sheet.getColumnWidth(colTmp)));
		anchor.setDx2(k);

		while (startY < picHeight){
			startY += PoiUtil.poiHeight2Pixel(sheet.getRow(++rowTmp).getHeight());
		}

		anchor.setRow2(rowTmp);
		k = PoiUtil.getAnchorY(PoiUtil.poiHeight2Pixel(sheet.getRow(rowTmp).getHeight()) - (startY - picHeight), PoiUtil.poiHeight2Pixel(sheet.getRow(rowTmp).getHeight()));
		anchor.setDy2(k);
		
		return anchor;
	}
}
