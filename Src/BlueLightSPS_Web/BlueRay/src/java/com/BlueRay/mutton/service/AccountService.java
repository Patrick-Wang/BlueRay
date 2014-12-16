package com.BlueRay.mutton.service;

import com.BlueRay.mutton.controller.UserInfo;
import com.BlueRay.mutton.model.entity.jpa.User;

public interface AccountService {

	boolean login(String userName, String psw);

	UserInfo getUsrInfo(String usrName);

}
