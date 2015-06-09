package com.BlueRay.mutton.model.entity.jpa;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;

@Entity
@Table(name = "bpqxhflxx")
public class BPQXHFLXX {
	private Integer bpqxhID;
	private String bpqxh = "";
	
	/**
	 * @return the bpqxhID
	 */
	@Id
	@GeneratedValue(strategy = GenerationType.AUTO)
	public Integer getBpqxhID() {
		return bpqxhID;
	}
	/**
	 * @return the bpqxh
	 */
	public String getBpqxh() {
		return bpqxh;
	}
	/**
	 * @param bpqxhID the bpqxhID to set
	 */
	public void setBpqxhID(Integer bpqxhID) {
		this.bpqxhID = bpqxhID;
	}
	/**
	 * @param bpqxh the bpqxh to set
	 */
	public void setBpqxh(String bpqxh) {
		this.bpqxh = bpqxh;
	}

}
