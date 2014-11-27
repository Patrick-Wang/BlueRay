package com.BlueRay.mutton.model.entity.jpa;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;

@Entity
@Table(name = "zdqdyflxx")
public class ZDQDYFLXX {
	private Integer zdqdyID;
	private String zdqdy;
	/**
	 * @return the zdqdyID
	 */
	@Id
	@GeneratedValue(strategy = GenerationType.AUTO)
	public Integer getZdqdyID() {
		return zdqdyID;
	}
	/**
	 * @return the zdqdy
	 */
	public String getZdqdy() {
		return zdqdy;
	}
	/**
	 * @param zdqdyID the zdqdyID to set
	 */
	public void setZdqdyID(Integer zdqdyID) {
		this.zdqdyID = zdqdyID;
	}
	/**
	 * @param zdqdy the zdqdy to set
	 */
	public void setZdqdy(String zdqdy) {
		this.zdqdy = zdqdy;
	}

}
