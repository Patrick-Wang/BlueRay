package com.BlueRay.mutton.controller.plan;

import java.io.IOException;
import java.io.OutputStream;
import java.util.Calendar;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import net.sf.json.JSONArray;
import net.sf.json.JSONObject;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.MediaType;
import org.springframework.scheduling.annotation.Scheduled;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.ResponseBody;

import sun.misc.BASE64Decoder;

import com.BlueRay.mutton.common.PageData;
import com.BlueRay.mutton.service.plan.PlanService;
import com.BlueRay.mutton.tool.Util;

@Controller
@RequestMapping(value = "/plan")
public class PlanController {

	@Autowired
	PlanService planService;


	@RequestMapping(value = "/resetTcbh", method = RequestMethod.GET)
	public @ResponseBody String resetTcbh(
			HttpServletRequest request,
			HttpServletResponse response) {
		planService.resetTcSerialNumber();
		return "OK";
	}
	
	@RequestMapping(value = "/resetCcbh", method = RequestMethod.GET)
	public @ResponseBody String resetCcbh(
			HttpServletRequest request,
			HttpServletResponse response) {
		planService.resetCcSerialNumber();
		return "OK";
	}
	
	@Scheduled(cron="0 0 0 26 12 ?")
	public void scheduleResetTcSerialNumber(){
		planService.resetTcSerialNumber();
	}
	
	@Scheduled(cron="0 0 0 26 * ?")
	public void scheduleResetCcSerialNumber(){
		planService.resetCcSerialNumber();
	}
	
	@RequestMapping(value = "/getbh/{item}", method = RequestMethod.GET)
	public @ResponseBody String getbh(
			@PathVariable String item,
			HttpServletRequest request,
			HttpServletResponse response) {
		
		return planService.getBh(item, (String)request.getParameter("zzs"));
	}
	
	@RequestMapping(value = "/validate", method = RequestMethod.GET)
	public @ResponseBody String validate(
			HttpServletRequest request,
			HttpServletResponse response) {
		String item = (String)request.getParameter("item");
		String value = (String)request.getParameter("value");
		return planService.validate(item, value);
	}

	@RequestMapping(value = "/pagequery/{pagesize}/{pagenum}/{pagecount}", method = RequestMethod.POST, produces = MediaType.APPLICATION_JSON_VALUE)
	public @ResponseBody String getSaleQueryData(
			@PathVariable Integer pagesize,
			@PathVariable Integer pagenum,
			@PathVariable Integer pagecount,
			HttpServletRequest request,
			HttpServletResponse response) throws IOException {
		JSONObject jparam = Util.parse(request.getInputStream());
		BASE64Decoder decoder = new BASE64Decoder();
		String query = new String(decoder.decodeBuffer(jparam.getString("query")), "utf-16le");
		PageData pageData = planService.pageQuery(pagesize,pagenum,pagecount, JSONObject.fromObject(query));
		String ret = JSONObject.fromObject(pageData).toString().replace("null", "\"\"");
		return ret;
	}

	
	@RequestMapping(value = "/query/{approveType}/{approved}", method = RequestMethod.GET, produces = MediaType.APPLICATION_JSON_VALUE)
	public @ResponseBody String getSaleQueryData(
			@PathVariable String approveType,
			@PathVariable String approved,
			HttpServletRequest request,
			HttpServletResponse response) {
		JSONArray arr = JSONArray.fromObject(planService.query(approveType, approved));
		String strRet = arr.toString();
		String finalRet = strRet.replace("null", "\"\"");
		return finalRet;
	}
	
	@RequestMapping(value = "/export", method = RequestMethod.POST, produces = MediaType.APPLICATION_JSON_VALUE)
	public @ResponseBody String exportData(
			HttpServletRequest request,
			HttpServletResponse response) throws IOException {
		OutputStream out = response.getOutputStream();
		JSONObject jparam = Util.parse(request.getInputStream());
		BASE64Decoder decoder = new BASE64Decoder();
		String query = new String(decoder.decodeBuffer(jparam.getString("query")), "utf-16le");
		return planService.export(out, JSONObject.fromObject(query));
	}
	
	@RequestMapping(value = "/template/export", method = RequestMethod.POST, produces = MediaType.APPLICATION_JSON_VALUE)
	public @ResponseBody String templateExport(
			HttpServletRequest request,
			HttpServletResponse response) throws IOException {
		OutputStream out = response.getOutputStream();
		JSONObject jparam = Util.parse(request.getInputStream());
		BASE64Decoder decoder = new BASE64Decoder();
		String query = new String(decoder.decodeBuffer(jparam.getString("query")), "utf-16le");
		return planService.templateExport(out, JSONObject.fromObject(query));
	}
	
	@RequestMapping(value = "/bzjhtemplate/export", method = RequestMethod.POST, produces = MediaType.APPLICATION_JSON_VALUE)
	public @ResponseBody String bzjhtemplateExport(
			HttpServletRequest request,
			HttpServletResponse response) throws IOException {
		OutputStream out = response.getOutputStream();
		JSONObject jparam = Util.parse(request.getInputStream());
		BASE64Decoder decoder = new BASE64Decoder();
		String query = new String(decoder.decodeBuffer(jparam.getString("query")), "utf-16le");
		return planService.bzjhtemplateExport(out, JSONObject.fromObject(query));
	}
	
	@RequestMapping(value = "/scjhtemplate/export", method = RequestMethod.POST, produces = MediaType.APPLICATION_JSON_VALUE)
	public @ResponseBody String scjhtemplateExport(
			HttpServletRequest request,
			HttpServletResponse response) throws IOException {
		OutputStream out = response.getOutputStream();
		JSONObject jparam = Util.parse(request.getInputStream());
		BASE64Decoder decoder = new BASE64Decoder();
		String query = new String(decoder.decodeBuffer(jparam.getString("query")), "utf-16le");
		return planService.scjhtemplateExport(out, JSONObject.fromObject(query));
	}
	
	@RequestMapping(value = "/update", method = RequestMethod.POST, produces = MediaType.APPLICATION_JSON_VALUE)
	public @ResponseBody String modifySaleData(HttpServletRequest request,
			HttpServletResponse response) throws IOException {
		String args = Util.getUtf8(request.getInputStream());
		JSONObject jo = JSONObject.fromObject(args);
		JSONArray rows = JSONArray.fromObject(jo.get("rows"));
		JSONArray data = JSONArray.fromObject(jo.get("data"));
		return planService.update(rows, data);
	}
	
	@RequestMapping(value = "/approve/business", method = RequestMethod.POST, produces = MediaType.APPLICATION_JSON_VALUE)
	public @ResponseBody String planBussinessApprove(HttpServletRequest request,
			HttpServletResponse response) throws IOException {
		JSONObject jo = Util.parse(request.getInputStream());
		JSONArray rows = JSONArray.fromObject(jo.get("rows"));
		return planService.businessApprove(rows);
	}
	@RequestMapping(value = "/approve/plan", method = RequestMethod.POST, produces = MediaType.APPLICATION_JSON_VALUE)
	public @ResponseBody String planApprove(HttpServletRequest request,
			HttpServletResponse response) throws IOException {
		JSONObject jo = Util.parse(request.getInputStream());
		JSONArray rows = JSONArray.fromObject(jo.get("rows"));
		return planService.planApprove(rows);
	}
	
	@RequestMapping(value = "/approve/pack/business", method = RequestMethod.POST, produces = MediaType.APPLICATION_JSON_VALUE)
	public @ResponseBody String packBusinessApprove(HttpServletRequest request,
			HttpServletResponse response) throws IOException {
		JSONObject jo = Util.parse(request.getInputStream());
		JSONArray rows = JSONArray.fromObject(jo.get("rows"));
		return planService.packBusinessApprove(rows);
	}
	
	@RequestMapping(value = "/approve/pack/plan", method = RequestMethod.POST, produces = MediaType.APPLICATION_JSON_VALUE)
	public @ResponseBody String planPlanApprove(HttpServletRequest request,
			HttpServletResponse response) throws IOException {
		JSONObject jo = Util.parse(request.getInputStream());
		JSONArray rows = JSONArray.fromObject(jo.get("rows"));
		return planService.packPlanApprove(rows);
	}
	
	@RequestMapping(value = "/unapprove/business", method = RequestMethod.POST, produces = MediaType.APPLICATION_JSON_VALUE)
	public @ResponseBody String planBussinessUnapprove(HttpServletRequest request,
			HttpServletResponse response) throws IOException {
		JSONObject jo = Util.parse(request.getInputStream());
		JSONArray rows = JSONArray.fromObject(jo.get("rows"));
		return planService.businessUnapprove(rows);
	}
	@RequestMapping(value = "/unapprove/plan", method = RequestMethod.POST, produces = MediaType.APPLICATION_JSON_VALUE)
	public @ResponseBody String planUnapprove(HttpServletRequest request,
			HttpServletResponse response) throws IOException {
		JSONObject jo = Util.parse(request.getInputStream());
		JSONArray rows = JSONArray.fromObject(jo.get("rows"));
		return planService.planUnapprove(rows);
	}
	
	@RequestMapping(value = "/unapprove/pack/business", method = RequestMethod.POST, produces = MediaType.APPLICATION_JSON_VALUE)
	public @ResponseBody String packBusinessUnapprove(HttpServletRequest request,
			HttpServletResponse response) throws IOException {
		JSONObject jo = Util.parse(request.getInputStream());
		JSONArray rows = JSONArray.fromObject(jo.get("rows"));
		return planService.packBusinessUnapprove(rows);
	}
	
	@RequestMapping(value = "/unapprove/pack/plan", method = RequestMethod.POST, produces = MediaType.APPLICATION_JSON_VALUE)
	public @ResponseBody String planPlanUnapprove(HttpServletRequest request,
			HttpServletResponse response) throws IOException {
		JSONObject jo = Util.parse(request.getInputStream());
		JSONArray rows = JSONArray.fromObject(jo.get("rows"));
		return planService.packPlanUnapprove(rows);
	}
}
