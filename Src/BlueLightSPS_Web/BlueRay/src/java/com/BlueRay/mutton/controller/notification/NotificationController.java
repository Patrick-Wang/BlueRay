package com.BlueRay.mutton.controller.notification;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import net.sf.json.JSONObject;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.MediaType;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.ResponseBody;

import com.BlueRay.mutton.common.UnapprovedBean;
import com.BlueRay.mutton.service.notification.NotificationService;

@Controller
@RequestMapping(value = "/notification")
public class NotificationController {
	@Autowired
	NotificationService notificationService;
	
	@RequestMapping(value = "/unapproved", method = RequestMethod.GET, produces = MediaType.APPLICATION_JSON_VALUE)
	public @ResponseBody String getUnapprovedData(HttpServletRequest request,
			HttpServletResponse response) {
		UnapprovedBean unapproved = notificationService.getUnapproved();
		return JSONObject.fromObject(unapproved).toString();
	}
}
