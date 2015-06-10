package com.bar;

import java.awt.Font;
import java.awt.FontMetrics;
import java.awt.Graphics;
import java.awt.image.BufferedImage;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.math.BigDecimal;

import javax.imageio.ImageIO;

import org.apache.poi.hssf.usermodel.HSSFCell;
import org.apache.poi.hssf.usermodel.HSSFClientAnchor;
import org.apache.poi.hssf.usermodel.HSSFFont;
import org.apache.poi.hssf.usermodel.HSSFPatriarch;
import org.apache.poi.hssf.usermodel.HSSFPicture;
import org.apache.poi.hssf.usermodel.HSSFSheet;
import org.apache.poi.hssf.usermodel.HSSFWorkbook;
import org.apache.poi.ss.usermodel.Workbook;
import org.apache.poi.util.IOUtils;
import org.jbarcode.JBarcode;
import org.jbarcode.encode.Code128Encoder;
import org.jbarcode.encode.Code39Encoder;
import org.jbarcode.encode.EAN13Encoder;
import org.jbarcode.paint.BaseLineTextPainter;
import org.jbarcode.paint.EAN13TextPainter;
import org.jbarcode.paint.WideRatioCodedPainter;
import org.jbarcode.paint.WidthCodedPainter;
import org.jbarcode.util.ImageUtil;
import org.krysalis.barcode4j.impl.code128.Code128Bean;
import org.krysalis.barcode4j.output.bitmap.BitmapCanvasProvider;
import org.krysalis.barcode4j.tools.UnitConv;

public class Demo {
	
	
	
	public static void main(String[] paramArrayOfString) {
		try {
			JBarcode localJBarcode =  new JBarcode(
					Code128Encoder.getInstance(),
					WidthCodedPainter.getInstance(),
					BaseLineTextPainter.getInstance());
			// ��������ֵ
			String str = "803013-803014";
			//localJBarcode.setWideRatio(3);
			localJBarcode.setXDimension(0.32);
			
			//localJBarcode.setWideRatio(arg0);
			BufferedImage localBufferedImage = localJBarcode.createBarcode(str);
			
			int k = localBufferedImage.getType();
			ByteArrayOutputStream byteArrayOut = new ByteArrayOutputStream();
			
			
//			  Code128Bean bean = new Code128Bean();
//	            
//	            final int dpi = 150;
//	            
//	            //Configure the barcode generator
//	            bean.setModuleWidth(UnitConv.in2mm(1.2f / dpi)); //makes the narrow bar 
//	                                                             //width exactly one pixel
//	            //bean.setWideFactor(3);
//	            bean.doQuietZone(false);
//	            bean.setBarHeight(7);
//	            bean.setFontSize(2);
//	            //Open output file
////	            File outputFile = new File("out.jpg");
////	            OutputStream out = new FileOutputStream(outputFile);
//	            try {
//	                //Set up the canvas provider for monochrome JPEG output 
//	                BitmapCanvasProvider canvas = new BitmapCanvasProvider(
//	                		byteArrayOut, "image/png", dpi, BufferedImage.TYPE_BYTE_BINARY, false, 0);
//	            
//	                //Generate the barcode
//	                bean.generateBarcode(canvas, "803013-803014");
//	            
//	                localBufferedImage = canvas.getBufferedImage();
//	                //Signal end of generation
//	               // canvas.finish();
//	            } finally {
//	               // out.close();
//	            }
			
			
			
			
			saveToPNG(localBufferedImage, "Code39.png");
		
			HSSFWorkbook workbook = new HSSFWorkbook(new FileInputStream(new File(
					"E:\\template.xls")));
			HSSFSheet sheet = workbook.getSheetAt(0);
			
			//画图的顶级管理器，一个sheet只能获取一个（一定要注意这点）  
            HSSFPatriarch patriarch = sheet.createDrawingPatriarch();     
            //anchor主要用于设置图片的属性  
            
            HSSFClientAnchor anchor = PoiUtil.measureAnchor(13, 2, 5, 7, localBufferedImage.getWidth(), localBufferedImage.getHeight(), sheet, workbook);
//            anchor.setDx1(10000);
//            anchor = new HSSFClientAnchor(200, 20000,
//					200, 200, (short) 13, 2, (short) 17, 5);     
            anchor.setAnchorType(HSSFClientAnchor.DONT_MOVE_AND_RESIZE);     
            //插入图片    
            ImageUtil.encodeAndWrite(localBufferedImage, "png",
            		byteArrayOut, 96, 96);
            HSSFPicture pic = patriarch.createPicture(anchor, workbook.addPicture(byteArrayOut.toByteArray(), HSSFWorkbook.PICTURE_TYPE_PNG));   
//            pic.resize(1.0);
//            pic.getAnchor().setDx1(200);
////          
//           pic.getAnchor().setDy1(100);
           
            // 写入excel文件     
            workbook.write(new FileOutputStream("E:/测试Excel.xls"));     
			

//			str = "JBARCODE-39";
//			localJBarcode.setEncoder(Code39Encoder.getInstance());
//			localJBarcode.setPainter(WideRatioCodedPainter.getInstance());
//			localJBarcode.setTextPainter(BaseLineTextPainter.getInstance());
//			localJBarcode.setShowCheckDigit(false);
//			localBufferedImage = localJBarcode.createBarcode(str);
//			saveToGIF(localBufferedImage, "EAN13.gif");
//			// ������
//			saveToPNG(localBufferedImage, "Code39.png");
		} catch (Exception localException) {
			localException.printStackTrace();
		}
	}

	static void saveToJPEG(BufferedImage paramBufferedImage, String paramString) {
		saveToFile(paramBufferedImage, paramString, "jpeg");
	}

	static void saveToPNG(BufferedImage paramBufferedImage, String paramString) {
		saveToFile(paramBufferedImage, paramString, "png");
	}

	static void saveToGIF(BufferedImage paramBufferedImage, String paramString) {
		saveToFile(paramBufferedImage, paramString, "gif");
	}

	static void saveToFile(BufferedImage paramBufferedImage,
			String paramString1, String paramString2) {
		try {
			FileOutputStream localFileOutputStream = new FileOutputStream(
					"E:/" + paramString1);
			ImageUtil.encodeAndWrite(paramBufferedImage, paramString2,
					localFileOutputStream, 96, 96);
			localFileOutputStream.close();
		} catch (Exception localException) {
			localException.printStackTrace();
		}
	}
}