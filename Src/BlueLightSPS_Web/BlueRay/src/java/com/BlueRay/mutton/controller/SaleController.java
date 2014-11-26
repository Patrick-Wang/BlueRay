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

import com.BlueRay.mutton.service.SaleService;

@Controller
@RequestMapping(value = "/sale")
public class SaleController {

	@Autowired
	SaleService service;

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

	@RequestMapping(value = "/map_id/{tableName}/{id}", method = RequestMethod.GET, produces = MediaType.APPLICATION_JSON_VALUE)
	public @ResponseBody String getValueById(@PathVariable String tableName,
			@PathVariable String id, HttpServletRequest request,
			HttpServletResponse response) {

		return id;
	}

	@RequestMapping(value = "/map_value/{tableName}/{value}", method = RequestMethod.GET, produces = MediaType.APPLICATION_JSON_VALUE)
	public @ResponseBody String getIdByValue(@PathVariable String tableName,
			@PathVariable String value, HttpServletRequest request,
			HttpServletResponse response) {

		return "";
	}

	@RequestMapping(value = "/query", method = RequestMethod.GET, produces = MediaType.APPLICATION_JSON_VALUE)
	public @ResponseBody String getSaleQueryData(HttpServletRequest request,
			HttpServletResponse response) {

		return JSONArray.fromObject(service.query()).toString();
	}

	@RequestMapping(value = "/add", method = RequestMethod.POST, produces = MediaType.APPLICATION_JSON_VALUE)
	public @ResponseBody String addSaleData(HttpServletRequest request,
			HttpServletResponse response) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(
				request.getInputStream()));
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
				request.getInputStream()));
		String line = null;
		StringBuilder sb = new StringBuilder();
		while ((line = br.readLine()) != null) {
			sb.append(line);
		}
		JSONObject jo = JSONObject.fromObject(sb.toString());
		JSONArray ja = JSONArray.fromObject(jo.get("del"));
		return service.delete(ja);
	}
}
