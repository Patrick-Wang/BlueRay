package com.BlueRay.mutton.service.account;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import com.BlueRay.mutton.common.UserInfo;
import com.BlueRay.mutton.model.dao.PermissionDao;
import com.BlueRay.mutton.model.dao.UserDao;
import com.BlueRay.mutton.model.entity.jpa.Permission;
import com.BlueRay.mutton.model.entity.jpa.User;
import com.BlueRay.mutton.tool.Util;

@Service
@Transactional("transactionManager")
public class AccountServiceImpl implements AccountService{

	@Autowired
	UserDao userDao;
	
	@Autowired
	PermissionDao permDao;
	
	public boolean login(String userName, String psw) {
		User usr = userDao.getUserByName(userName);
		if (usr != null && psw != null){
			return Util.Md5(psw).equals(usr.getPsw());
		}
		return false;
	}



	public UserInfo getUsrInfo(String usrName) {
		UserInfo usrInfo = null;
		User usr = userDao.getUserByName(usrName);
		if (usr != null){
			Permission perm = permDao.getPermissionByRole(usr.getRole());
			if (null != perm){
				usrInfo = new UserInfo();
				usrInfo.setPerm(perm);
				usrInfo.setUsr(usr);
			}
		}
		return usrInfo;
	}

}
