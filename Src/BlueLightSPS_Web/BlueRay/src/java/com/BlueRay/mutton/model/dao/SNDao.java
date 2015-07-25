package com.BlueRay.mutton.model.dao;

import java.util.List;

import com.BlueRay.mutton.model.entity.jpa.SNIDType;
import com.BlueRay.mutton.model.entity.jpa.SerialNumber;

public interface SNDao {
	//SerialNumber getSNById(Integer id);
	SerialNumber getSNByZzs(Integer zzsId, SNIDType type);
	List<SerialNumber> getSNByType(SNIDType type);
	void saveSN(SerialNumber sn);
}
