package com.BlueRay.mutton.service.account;

import com.BlueRay.mutton.common.UserInfo;
import com.BlueRay.mutton.model.entity.jpa.User;

public interface AccountService {

	boolean login(String userName, String psw);

	UserInfo getUsrInfo(String usrName);

}
