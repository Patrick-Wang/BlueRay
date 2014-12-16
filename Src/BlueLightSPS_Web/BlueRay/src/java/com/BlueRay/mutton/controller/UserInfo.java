package com.BlueRay.mutton.controller;

import com.BlueRay.mutton.model.entity.jpa.Permission;
import com.BlueRay.mutton.model.entity.jpa.User;

public class UserInfo {
	User usr;
	Permission perm;
	String session;
	/**
	 * @return the usr
	 */
	public User getUsr() {
		return usr;
	}
	/**
	 * @return the perm
	 */
	public Permission getPerm() {
		return perm;
	}
	/**
	 * @param usr the usr to set
	 */
	public void setUsr(User usr) {
		this.usr = usr;
	}
	/**
	 * @param perm the perm to set
	 */
	public void setPerm(Permission perm) {
		this.perm = perm;
	}
	/**
	 * @return the session
	 */
	public String getSession() {
		return session;
	}
	/**
	 * @param session the session to set
	 */
	public void setSession(String session) {
		this.session = session;
	}
}
