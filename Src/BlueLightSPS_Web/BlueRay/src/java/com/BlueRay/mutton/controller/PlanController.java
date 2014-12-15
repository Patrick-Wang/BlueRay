package com.BlueRay.mutton.controller;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import net.sf.json.JSONArray;
import net.sf.json.JSONObject;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.MediaType;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.ResponseBody;

import com.BlueRay.mutton.service.PlanService;
import com.BlueRay.mutton.service.SaleService;
import com.BlueRay.mutton.tool.Util;

@Controller
@RequestMapping(value = "/plan")
public class PlanController {

	@Autowired
	PlanService planService;


//	@Autowired
//	MapQueryService mqService;
	
	// @RequestMapping(value = "syhkjhzxqk.do", method = RequestMethod.GET,
	// produces=MediaType.APPLICATION_JSON_VALUE)
	// public @ResponseBody Response getSyhkjhzxqkData(
	// @RequestParam("page") Integer page, // get the requested page
	// @RequestParam("rows") Integer rows, // get how many rows we want to have
	// into the grid
	// @RequestParam("sidx") String sidx, // get index row - i.e. user click to
	// sort
	// @RequestParam("sord") String sord // get the direction
	// , HttpServletResponse response) {
	// SaleService service = getSyhkjhzxqkService();
	// return service.query();
	// }

//	@RequestMapping(value = "/map_id/{tableName}/{id}", method = RequestMethod.GET, produces = MediaType.APPLICATION_JSON_VALUE)
//	public @ResponseBody String getValueById(@PathVariable String tableName,
//			@PathVariable String id, HttpServletRequest request,
//			HttpServletResponse response) {
//
//		return id;
//	}
//
//	@RequestMapping(value = "/map_value/{tableName}/{value}", method = RequestMethod.GET, produces = MediaType.APPLICATION_JSON_VALUE)
//	public @ResponseBody String getIdByValue(@PathVariable String tableName,
//			@PathVariable String value, HttpServletRequest request,
//			HttpServletResponse response) {
//
//		return "";
//	}

	@RequestMapping(value = "/query/{approveType}/{approved}", method = RequestMethod.GET, produces = MediaType.APPLICATION_JSON_VALUE)
	public @ResponseBody String getSaleQueryData(
			@PathVariable String approveType,
			@PathVariable String approved,
			HttpServletRequest request,
			HttpServletResponse response) {

		return JSONArray.fromObject(planService.query(approveType, approved)).toString().replace("null", "");
	}
	
//	@RequestMapping(value = "/query", method = RequestMethod.GET, produces = MediaType.APPLICATION_JSON_VALUE)
//	public @ResponseBody String getSaleQueryData(HttpServletRequest request,
//			HttpServletResponse response) {
//	
//		return JSONArray.fromObject(planService.query()).toString().replace("null", "");
//	}

//	@RequestMapping(value = "/add", method = RequestMethod.POST, produces = MediaType.APPLICATION_JSON_VALUE)
//	public @ResponseBody String addSaleData(HttpServletRequest request,
//			HttpServletResponse response) throws Exception {
//		BufferedReader br = new BufferedReader(new InputStreamReader(
//				request.getInputStream(), "UTF-8"));
//		String line = null;
//		StringBuilder sb = new StringBuilder();
//		while ((line = br.readLine()) != null) {
//			sb.append(line);
//		}
//		JSONObject jo = JSONObject.fromObject(sb.toString());
//		JSONArray ja = JSONArray.fromObject(jo.get("add"));
//		return service.add(ja);
//	}
//
//	@RequestMapping(value = "/delete", method = RequestMethod.POST, produces = MediaType.APPLICATION_JSON_VALUE)
//	public @ResponseBody String delSaleData(HttpServletRequest request,
//			HttpServletResponse response) throws IOException {
//		BufferedReader br = new BufferedReader(new InputStreamReader(
//				request.getInputStream(), "UTF-8"));
//		String line = null;
//		StringBuilder sb = new StringBuilder();
//		while ((line = br.readLine()) != null) {
//			sb.append(line);
//		}
//		JSONObject jo = JSONObject.fromObject(sb.toString());
//		JSONArray ja = JSONArray.fromObject(jo.get("del"));
//		return service.delete(ja);
//	}
	
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
