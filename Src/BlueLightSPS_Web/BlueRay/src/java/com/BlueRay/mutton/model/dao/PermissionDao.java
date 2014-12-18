package com.BlueRay.mutton.model.dao;

import com.BlueRay.mutton.model.entity.jpa.Permission;
import com.BlueRay.mutton.model.entity.jpa.User;

public interface PermissionDao {
	Permission getPermissionByRole(String role);
}
