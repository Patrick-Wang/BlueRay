package com.BlueRay.mutton.model.dao;

import com.BlueRay.mutton.model.entity.jpa.SerialNumber;

public interface SNDao {
	SerialNumber getSNById(Integer id);
	void saveSN(SerialNumber sn);
}
