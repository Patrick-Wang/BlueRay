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

import com.BlueRay.mutton.service.AccountService;
import com.BlueRay.mutton.service.SaleService;
import com.BlueRay.mutton.tool.Util;

@Controller
@RequestMapping(value = "/account")
public class AccountController {

	@Autowired
	AccountService service;

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

	@RequestMapping(value = "/login/{userName}/{psw}", method = RequestMethod.GET, produces = MediaType.APPLICATION_JSON_VALUE)
	public @ResponseBody String login(
			@PathVariable String userName,
			@PathVariable String psw,
			HttpServletRequest request,
			HttpServletResponse response) {

		HttpSession session = request.getSession(false);
		String ret = "error";
		if (null != session){
			ret= session.getId();
		}
		else{
			if (service.login(userName, psw)){
				session = request.getSession(true);
				ret= session.getId();
			}
		}
		return ret;
	}

	
}
