package com.BlueRay.mutton.service;

import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

@Service
@Transactional("transactionManager")
public class AccountServiceImpl implements AccountService{

	public boolean login(String userName, String psw) {
		// TODO Auto-generated method stub
		return true;
	}

}
