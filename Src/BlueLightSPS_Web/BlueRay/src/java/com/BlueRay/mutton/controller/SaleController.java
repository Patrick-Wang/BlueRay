package com.BlueRay.mutton.controller;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

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
	
//	@RequestMapping(value = "syhkjhzxqk.do", method = RequestMethod.GET, produces=MediaType.APPLICATION_JSON_VALUE)
//	public @ResponseBody Response getSyhkjhzxqkData(
//			@RequestParam("page") Integer page, // get the requested page  
//			@RequestParam("rows") Integer rows,	// get how many rows we want to have into the grid
//			@RequestParam("sidx") String sidx, // get index row - i.e. user click to sort
//			@RequestParam("sord") String sord // get the direction
//		, HttpServletResponse response) {
//		SaleService service = getSyhkjhzxqkService();
//		return service.query();
//	}
	
//	@RequestMapping(value = "/{id}", method = RequestMethod.GET, produces=MediaType.APPLICATION_JSON_VALUE)
//	public @ResponseBody String getSaleData(@PathVariable String id, HttpServletRequest request,
//			HttpServletResponse response) {
//
//		
//		return id;
//	}
	
	@RequestMapping(value = "/query", method = RequestMethod.GET, produces=MediaType.APPLICATION_JSON_VALUE)
	public @ResponseBody String[][] getSaleQueryData(HttpServletRequest request,
			HttpServletResponse response) {
		
		return service.query();
	}
	
	@RequestMapping(value = "/update", method = RequestMethod.GET, produces=MediaType.APPLICATION_JSON_VALUE)
	public @ResponseBody boolean updateSaleData(HttpServletRequest request,
			HttpServletResponse response) {
		
		return service.update();
	}
}
