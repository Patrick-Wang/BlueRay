package com.BlueRay.mutton.model.entity.jpa;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;

@Entity
@Table(name = "zcxx")
public class ZCXX {
	private Integer zcxhID;
	private String zcxh = "";
	
	/**
	 * @return the zcxhID
	 */
	@Id
	@GeneratedValue(strategy = GenerationType.AUTO)
	public Integer getZcxhID() {
		return zcxhID;
	}
	/**
	 * @return the zcxh
	 */
	public String getZcxh() {
		return zcxh;
	}
	/**
	 * @param zcxhID the zcxhID to set
	 */
	public void setZcxhID(Integer zcxhID) {
		this.zcxhID = zcxhID;
	}
	/**
	 * @param zcxh the zcxh to set
	 */
	public void setZcxh(String zcxh) {
		this.zcxh = zcxh;
	}

}
