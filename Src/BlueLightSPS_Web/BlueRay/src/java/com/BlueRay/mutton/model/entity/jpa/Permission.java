package com.BlueRay.mutton.model.entity.jpa;

import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.Table;

@Entity
@Table(name = "permission")
public class Permission {
	String role;
	Boolean xsywsh;
	Boolean xsjhsh;
	Boolean jhywsh;
	Boolean jhjhsh;
	Boolean jhbzywsh;
	Boolean jhbzjhsh;
	
	/**
	 * @return the xsywsh
	 */
	public Boolean getXsywsh() {
		return xsywsh;
	}
	/**
	 * @return the xsjhsh
	 */
	public Boolean getXsjhsh() {
		return xsjhsh;
	}
	/**
	 * @return the jhywsh
	 */
	public Boolean getJhywsh() {
		return jhywsh;
	}
	/**
	 * @return the jhjhsh
	 */
	public Boolean getJhjhsh() {
		return jhjhsh;
	}
	/**
	 * @return the jhbzywsh
	 */
	public Boolean getJhbzywsh() {
		return jhbzywsh;
	}
	/**
	 * @return the jhbzjhsh
	 */
	public Boolean getJhbzjhsh() {
		return jhbzjhsh;
	}
	/**
	 * @param xsywsh the xsywsh to set
	 */
	public void setXsywsh(Boolean xsywsh) {
		this.xsywsh = xsywsh;
	}
	/**
	 * @param xsjhsh the xsjhsh to set
	 */
	public void setXsjhsh(Boolean xsjhsh) {
		this.xsjhsh = xsjhsh;
	}
	/**
	 * @param jhywsh the jhywsh to set
	 */
	public void setJhywsh(Boolean jhywsh) {
		this.jhywsh = jhywsh;
	}
	/**
	 * @param jhjhsh the jhjhsh to set
	 */
	public void setJhjhsh(Boolean jhjhsh) {
		this.jhjhsh = jhjhsh;
	}
	/**
	 * @param jhbzywsh the jhbzywsh to set
	 */
	public void setJhbzywsh(Boolean jhbzywsh) {
		this.jhbzywsh = jhbzywsh;
	}
	/**
	 * @param jhbzjhsh the jhbzjhsh to set
	 */
	public void setJhbzjhsh(Boolean jhbzjhsh) {
		this.jhbzjhsh = jhbzjhsh;
	}
	/**
	 * @return the role
	 */
	@Id
	public String getRole() {
		return role;
	}
	/**
	 * @param role the role to set
	 */
	public void setRole(String role) {
		this.role = role;
	}
}
