package com.BlueRay.mutton.controller.account;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import net.sf.json.JSONObject;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.MediaType;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.ResponseBody;

import com.BlueRay.mutton.common.UserInfo;
import com.BlueRay.mutton.service.account.AccountService;
import com.vbarunner.VBAExcel;

@Controller
@RequestMapping(value = "/account")
public class AccountController {

	@Autowired
	AccountService service;

	public AccountController(){
		System.out.println(getClass().getClassLoader().getResource("/").getPath().substring(1) + "META-INF/template.xls");
	}
	
	@RequestMapping(value = "/login/{userName}/{psw}", method = RequestMethod.GET, produces = MediaType.APPLICATION_JSON_VALUE)
	public @ResponseBody String login(
			@PathVariable String userName,
			@PathVariable String psw,
			HttpServletRequest request,
			HttpServletResponse response) {
		HttpSession session = request.getSession(false);
		String ret = "error";
		if (null != session){
			//session.invalidate();
			ret= session.getId();
		}
		else{
			if (service.login(userName, psw)){
				session = request.getSession(true);
				session.setAttribute("usrName", userName);
				UserInfo usrInfo = service.getUsrInfo(userName);
				usrInfo.setSession(session.getId());
				if (null != usrInfo){
					ret = JSONObject.fromObject(usrInfo).toString();
				}
			}
		}
		return ret;
	}
	
	@RequestMapping(value = "/info", method = RequestMethod.GET, produces = MediaType.APPLICATION_JSON_VALUE)
	public @ResponseBody String getInfo(
			HttpServletRequest request,
			HttpServletResponse response) {

		HttpSession session = request.getSession(false);
		String ret = "error";
		if (null != session){
			String userName = (String) session.getAttribute("usrName");
			UserInfo usrInfo = service.getUsrInfo(userName);
			usrInfo.setSession(session.getId());
			if (null != usrInfo){
				ret = JSONObject.fromObject(usrInfo).toString();
			}
		}
		return ret;
	}
	
}
