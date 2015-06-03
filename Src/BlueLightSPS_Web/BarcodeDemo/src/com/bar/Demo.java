package com.bar;

import java.awt.image.BufferedImage;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;

import javax.imageio.ImageIO;

import org.apache.poi.hssf.usermodel.HSSFClientAnchor;
import org.apache.poi.hssf.usermodel.HSSFPatriarch;
import org.apache.poi.hssf.usermodel.HSSFPicture;
import org.apache.poi.hssf.usermodel.HSSFSheet;
import org.apache.poi.hssf.usermodel.HSSFWorkbook;
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

public class Demo {
	public static void main(String[] paramArrayOfString) {
		try {
			JBarcode localJBarcode =  new JBarcode(
					Code128Encoder.getInstance(),
					WidthCodedPainter.getInstance(),
					BaseLineTextPainter.getInstance());
			// ��������ֵ
			String str = "PO01503170008.2jjfew";
			//localJBarcode.setWideRatio(1.5);
			//localJBarcode.setXDimension(0.3);
			BufferedImage localBufferedImage = localJBarcode.createBarcode(str);
			
			int k = localBufferedImage.getType();
			ByteArrayOutputStream byteArrayOut = new ByteArrayOutputStream();
			saveToPNG(localBufferedImage, "Code39.png");
			byte[] bytes = IOUtils.toByteArray(new FileInputStream(new File("E:\\Code39.png")));
			BufferedImage image = ImageIO.read(new File("E:\\Code39.png"));  //读取1.gif并传输  
	        ByteArrayOutputStream out = new ByteArrayOutputStream();  
	        boolean flag = ImageIO.write(image, "dib", out);
	        byte[] bytes2 = out.toByteArray();
			//ImageIO.write(localBufferedImage, "PNG", byteArrayOut);
			;
			HSSFWorkbook workbook = new HSSFWorkbook(new FileInputStream(new File(
					"E:\\template.xls")));
			HSSFSheet sheet = workbook.getSheetAt(0);
			
			//画图的顶级管理器，一个sheet只能获取一个（一定要注意这点）  
            HSSFPatriarch patriarch = sheet.createDrawingPatriarch();     
            //anchor主要用于设置图片的属性  
            HSSFClientAnchor anchor = new HSSFClientAnchor(200, 100,
					1000, 200, (short) 13, 2, (short) 17, 5);     
            anchor.setAnchorType(HSSFClientAnchor.DONT_MOVE_AND_RESIZE);     
            //插入图片    
            ImageUtil.encodeAndWrite(localBufferedImage, "png",
            		byteArrayOut, 48, 48);
            HSSFPicture pic = patriarch.createPicture(anchor, workbook.addPicture(byteArrayOut.toByteArray(), HSSFWorkbook.PICTURE_TYPE_PNG));   
            pic.resize(1.0);
            pic.getAnchor().setDx1(200);
//          
           pic.getAnchor().setDy1(100);
           
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