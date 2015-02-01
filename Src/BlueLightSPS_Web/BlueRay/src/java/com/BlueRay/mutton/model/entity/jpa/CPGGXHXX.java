package com.BlueRay.mutton.model.entity.jpa;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;

@Entity
@Table(name = "cpggxhxx")
public class CPGGXHXX {
	private Integer cpggxhID;
	private String gg = "";
	/**
	 * @return the cpggxhID
	 */
	@Id
	@GeneratedValue(strategy = GenerationType.AUTO)
	public Integer getCpggxhID() {
		return cpggxhID;
	}
	/**
	 * @return the gg
	 */
	public String getGg() {
		return gg;
	}
	/**
	 * @param cpggxhID the cpggxhID to set
	 */
	public void setCpggxhID(Integer cpggxhID) {
		this.cpggxhID = cpggxhID;
	}
	/**
	 * @param gg the gg to set
	 */
	public void setGg(String gg) {
		this.gg = gg;
	}

}
