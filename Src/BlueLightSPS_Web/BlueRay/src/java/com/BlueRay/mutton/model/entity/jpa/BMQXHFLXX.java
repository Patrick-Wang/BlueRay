package com.BlueRay.mutton.model.entity.jpa;

import java.io.Serializable;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;

@Entity
@Table(name = "bmqxhflxx")
public class BMQXHFLXX implements Serializable {

	private static final long serialVersionUID = 1L;
	private Integer bmqxhID;
	private String bmqxh;
	/**
	 * @return the bmqxhID
	 */
	@Id
	public Integer getBmqxhID() {
		return bmqxhID;
	}
	/**
	 * @return the bmqxh
	 */
	public String getBmqxh() {
		return bmqxh;
	}
	/**
	 * @param bmqxhID the bmqxhID to set
	 */
	public void setBmqxhID(Integer bmqxhID) {
		this.bmqxhID = bmqxhID;
	}
	/**
	 * @param bmqxh the bmqxh to set
	 */
	public void setBmqxh(String bmqxh) {
		this.bmqxh = bmqxh;
	}
}
