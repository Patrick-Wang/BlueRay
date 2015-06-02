package com.BlueRay.mutton.model.entity.jpa;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;

@Entity
@Table(name = "cpggxhxx")
public class CPGGXHXX {
	public Integer cpggxhID;
	public String gg = "";
	public String xh = "";
	public String dw = "";
	public String ts = "";
	/**
	 * @return the cpggxhID
	 */
	@Id
	@GeneratedValue(strategy = GenerationType.AUTO)
	public Integer getCpggxhID() {
		return cpggxhID;
	}
	/**
	 * @return the xh
	 */
	public String getXh() {
		return xh;
	}
	/**
	 * @return the dw
	 */
	public String getDw() {
		return dw;
	}
	/**
	 * @return the ts
	 */
	public String getTs() {
		return ts;
	}
	/**
	 * @param xh the xh to set
	 */
	public void setXh(String xh) {
		this.xh = xh;
	}
	/**
	 * @param dw the dw to set
	 */
	public void setDw(String dw) {
		this.dw = dw;
	}
	/**
	 * @param ts the ts to set
	 */
	public void setTs(String ts) {
		this.ts = ts;
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
