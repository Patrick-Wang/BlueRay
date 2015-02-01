package com.BlueRay.mutton.controller;

import java.util.List;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import net.sf.json.JSONArray;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.MediaType;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.ResponseBody;

import com.BlueRay.mutton.service.ItemQueryService;

@Controller
@RequestMapping(value = "/itemquery")
public class ItemQueryController {
	
	@Autowired
	ItemQueryService service;


	@RequestMapping(value = "/{tableName}", method = RequestMethod.GET, produces = MediaType.APPLICATION_JSON_VALUE)
	public @ResponseBody String getValueById(@PathVariable String tableName, HttpServletRequest request,
			HttpServletResponse response) {
		List<String> list = service.queryItems(tableName);
		return JSONArray.fromObject(list).toString() ;
	}

}
