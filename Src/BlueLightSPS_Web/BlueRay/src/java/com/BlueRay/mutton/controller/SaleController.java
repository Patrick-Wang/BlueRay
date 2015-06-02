package com.BlueRay.mutton.controller;

import java.io.BufferedReader;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import net.sf.json.JSONArray;
import net.sf.json.JSONObject;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.MediaType;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.ResponseBody;

import sun.misc.BASE64Decoder;

import com.BlueRay.mutton.service.SaleService;
import com.BlueRay.mutton.tool.Util;

@Controller
@RequestMapping(value = "/sale")
public class SaleController {

	@Autowired
	SaleService service;

	@RequestMapping(value = "/import", method = RequestMethod.POST, produces = MediaType.APPLICATION_JSON_VALUE)
	public @ResponseBody ImportResult ImportData(
			HttpServletRequest request,
			HttpServletResponse response) throws IOException, InterruptedException {

//		ByteArrayOutputStream outSteam = new ByteArrayOutputStream();  
//        byte[] buffer = new byte[4 * 1024];  
//        int len = -1;  
//        InputStream is = request.getInputStream();
//        while ((len = is.read(buffer)) != -1) {  
//            outSteam.write(buffer, 0, len);  
//            Thread.sleep(100);
//        }  
//        outSteam.close(); 
//        
		BufferedReader br = new BufferedReader(new InputStreamReader(
				request.getInputStream(), "UTF-16LE"));
		String line = null;
		StringBuilder sb = new StringBuilder();
		while ((line = br.readLine()) != null) {
			sb.append(line);
		}
		ImportResult ret = new ImportResult();
		JSONArray ja = JSONArray.fromObject(sb.toString());
		ret.total = ja.size();
		for (int i = 0, len = ja.size(); i < len; ++i){
			try {
				service.add(ja.getJSONArray(i));
				++ret.succeed;
			} catch (Exception e) {
				++ret.failed;
				e.printStackTrace();
			}
		}
		return ret;
	}
	
	@RequestMapping(value = "/export", method = RequestMethod.POST, produces = MediaType.APPLICATION_JSON_VALUE)
	public @ResponseBody String exportData(
			HttpServletRequest request,
			HttpServletResponse response) throws IOException {
		OutputStream out = response.getOutputStream();
		JSONObject jparam = Util.parse(request.getInputStream());
		BASE64Decoder decoder = new BASE64Decoder();
		String query = new String(decoder.decodeBuffer(jparam.getString("query")), "utf-16le");
		return service.export(out, JSONObject.fromObject(query));
	}
	
	@RequestMapping(value = "/pagequery/{pagesize}/{pagenum}/{pagecount}", method = RequestMethod.POST, produces = MediaType.APPLICATION_JSON_VALUE)
	public @ResponseBody String getPageQueryData(
			@PathVariable Integer pagesize,
			@PathVariable Integer pagenum,
			@PathVariable Integer pagecount,
			HttpServletRequest request,
			HttpServletResponse response) throws IOException {
		JSONObject jparam = Util.parse(request.getInputStream());
		BASE64Decoder decoder = new BASE64Decoder();
		String query = new String(decoder.decodeBuffer(jparam.getString("query")), "utf-16le");
		PageData pageData = service.pageQuery(pagesize,pagenum,pagecount, JSONObject.fromObject(query));
		return JSONObject.fromObject(pageData).toString().replace("null", "\"\"");
	}
	
	@RequestMapping(value = "/add", method = RequestMethod.POST, produces = MediaType.APPLICATION_JSON_VALUE)
	public @ResponseBody String addSaleData(HttpServletRequest request,
			HttpServletResponse response) throws Exception {
		HttpSession sess = request.getSession(false);
		BufferedReader br = new BufferedReader(new InputStreamReader(
				request.getInputStream(), "UTF-8"));
		String line = null;
		StringBuilder sb = new StringBuilder();
		while ((line = br.readLine()) != null) {
			sb.append(line);
		}
		JSONObject jo = JSONObject.fromObject(sb.toString());
		JSONArray ja = JSONArray.fromObject(jo.get("add"));
		return service.add(ja);
	}

	@RequestMapping(value = "/delete", method = RequestMethod.POST, produces = MediaType.APPLICATION_JSON_VALUE)
	public @ResponseBody String delSaleData(HttpServletRequest request,
			HttpServletResponse response) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(
				request.getInputStream(), "UTF-8"));
		String line = null;
		StringBuilder sb = new StringBuilder();
		while ((line = br.readLine()) != null) {
			sb.append(line);
		}
		JSONObject jo = JSONObject.fromObject(sb.toString());
		JSONArray ja = JSONArray.fromObject(jo.get("del"));
		return service.delete(ja);
	}
	
	@RequestMapping(value = "/modify", method = RequestMethod.POST, produces = MediaType.APPLICATION_JSON_VALUE)
	public @ResponseBody String modifySaleData(HttpServletRequest request,
			HttpServletResponse response) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(
				request.getInputStream(), "UTF-8"));
		String line = null;
		StringBuilder sb = new StringBuilder();
		while ((line = br.readLine()) != null) {
			sb.append(line);
		}
		JSONObject jo = JSONObject.fromObject(sb.toString());
		JSONArray rows = JSONArray.fromObject(jo.get("rows"));
		JSONArray data = JSONArray.fromObject(jo.get("data"));
		return service.update(rows, data);
	}
	
	@RequestMapping(value = "/approve/business", method = RequestMethod.POST, produces = MediaType.APPLICATION_JSON_VALUE)
	public @ResponseBody String bussinessApprove(HttpServletRequest request,
			HttpServletResponse response) throws IOException {
		JSONObject jo = Util.parse(request.getInputStream());
		JSONArray rows = JSONArray.fromObject(jo.get("rows"));
		return service.businessApprove(rows);
	}
	
	@RequestMapping(value = "/approve/plan", method = RequestMethod.POST, produces = MediaType.APPLICATION_JSON_VALUE)
	public @ResponseBody String planApprove(HttpServletRequest request,
			HttpServletResponse response) throws IOException {
		JSONObject jo = Util.parse(request.getInputStream());
		JSONArray rows = JSONArray.fromObject(jo.get("rows"));
		return service.planApprove(rows);
	}
	
	
	@RequestMapping(value = "/unapprove/business", method = RequestMethod.POST, produces = MediaType.APPLICATION_JSON_VALUE)
	public @ResponseBody String bussinessUnapprove(HttpServletRequest request,
			HttpServletResponse response) throws IOException {
		JSONObject jo = Util.parse(request.getInputStream());
		JSONArray rows = JSONArray.fromObject(jo.get("rows"));
		return service.businessUnapprove(rows);
	}
	
	@RequestMapping(value = "/unapprove/plan", method = RequestMethod.POST, produces = MediaType.APPLICATION_JSON_VALUE)
	public @ResponseBody String planUnapprove(HttpServletRequest request,
			HttpServletResponse response) throws IOException {
		JSONObject jo = Util.parse(request.getInputStream());
		JSONArray rows = JSONArray.fromObject(jo.get("rows"));
		return service.planUnapprove(rows);
	}
	
	@RequestMapping(value = "/isHtIDExist")
	public @ResponseBody String isHtIDExist(HttpServletRequest request,
			HttpServletResponse response) throws IOException {
		String htId = request.getParameter("HtID");
		Result ret = new Result(service.isHtidExist(htId));
		JSONObject jo = JSONObject.fromObject(ret);
		return jo.toString();
	}
	
}
