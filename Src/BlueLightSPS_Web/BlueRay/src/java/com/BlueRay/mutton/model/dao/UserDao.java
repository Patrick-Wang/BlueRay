package com.BlueRay.mutton.model.dao;

import com.BlueRay.mutton.model.entity.jpa.User;

public interface UserDao {
	User getUserByName(String name);
}
