package com.BlueRay.mutton.controller;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

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

import com.BlueRay.mutton.service.SaleService;
import com.BlueRay.mutton.tool.Util;

@Controller
@RequestMapping(value = "/sale")
public class SaleController {

	@Autowired
	SaleService service;

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
	@RequestMapping(value = "/pagesearch/{approveType}/{approved}/{pagesize}/{pagenum}/{pagecount}/{colIndex}/{sort}", method = RequestMethod.POST, produces = MediaType.APPLICATION_JSON_VALUE)
	public @ResponseBody String getPageSearchData(
			@PathVariable String approveType,
			@PathVariable String approved,
			@PathVariable Integer pagesize,
			@PathVariable Integer pagenum,
			@PathVariable Integer pagecount,
			@PathVariable Integer colIndex,
			@PathVariable Boolean sort,
			HttpServletRequest request,
			HttpServletResponse response) throws IOException {
		
		JSONObject jo = Util.parse(request.getInputStream());
		JSONArray keyWords = JSONArray.fromObject(jo.get("search"));
		PageData pageData = service.pageSearch(approveType, approved, pagesize,pagenum,pagecount,colIndex >= 0 ? colIndex + 1 : -1,sort, keyWords);

		
		return JSONObject.fromObject(pageData).toString().replace("null", "\"\"");
	}
	
	@RequestMapping(value = "/simplepagesearch/{approveType}/{approved}/{pagesize}/{pagenum}/{pagecount}/{colIndex}/{sort}", method = RequestMethod.POST, produces = MediaType.APPLICATION_JSON_VALUE)
	public @ResponseBody String getSimplePageSearchData(
			@PathVariable String approveType,
			@PathVariable String approved,
			@PathVariable Integer pagesize,
			@PathVariable Integer pagenum,
			@PathVariable Integer pagecount,
			@PathVariable Integer colIndex,
			@PathVariable Boolean sort,
			HttpServletRequest request,
			HttpServletResponse response) throws IOException {
		JSONObject jo = Util.parse(request.getInputStream());
		String keyword = jo.getString("search");
		PageData pageData = service.pageSearch(approveType, approved, pagesize,pagenum,pagecount,colIndex >= 0 ? colIndex + 1 : -1,sort, keyword);
		return JSONObject.fromObject(pageData).toString().replace("null", "\"\"");
	}

	@RequestMapping(value = "/pagequery/{approveType}/{approved}/{pagesize}/{pagenum}/{pagecount}/{colIndex}/{sort}", method = RequestMethod.GET, produces = MediaType.APPLICATION_JSON_VALUE)
	public @ResponseBody String getPageQueryData(
			@PathVariable String approveType,
			@PathVariable String approved,
			@PathVariable Integer pagesize,
			@PathVariable Integer pagenum,
			@PathVariable Integer pagecount,
			@PathVariable Integer colIndex,
			@PathVariable Boolean sort,
			HttpServletRequest request,
			HttpServletResponse response) {
		PageData pageData = service.pageQuery(approveType, approved, pagesize,pagenum,pagecount,colIndex >= 0 ? colIndex + 1 : -1 ,sort);
		return JSONObject.fromObject(pageData).toString().replace("null", "\"\"");
	}
	
	@RequestMapping(value = "/query/{approveType}/{approved}", method = RequestMethod.GET, produces = MediaType.APPLICATION_JSON_VALUE)
	public @ResponseBody String getSaleQueryData(
			@PathVariable String approveType,
			@PathVariable String approved,
			HttpServletRequest request,
			HttpServletResponse response) {

		return JSONArray.fromObject(service.query(approveType, approved)).toString().replace("null", "\"\"");
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
	
}
