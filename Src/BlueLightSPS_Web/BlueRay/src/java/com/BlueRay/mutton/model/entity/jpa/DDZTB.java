package com.BlueRay.mutton.model.entity.jpa;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;

@Entity
@Table(name = "ddztb")
public class DDZTB {
	private Integer ddztID;
	private String ddzt;
	/**
	 * @return the ddztID
	 */
	@Id
	@GeneratedValue(strategy = GenerationType.AUTO)
	public Integer getDdztID() {
		return ddztID;
	}
	/**
	 * @return the ddzt
	 */
	public String getDdzt() {
		return ddzt;
	}
	/**
	 * @param ddztID the ddztID to set
	 */
	public void setDdztID(Integer ddztID) {
		this.ddztID = ddztID;
	}
	/**
	 * @param ddzt the ddzt to set
	 */
	public void setDdzt(String ddzt) {
		this.ddzt = ddzt;
	}

}
