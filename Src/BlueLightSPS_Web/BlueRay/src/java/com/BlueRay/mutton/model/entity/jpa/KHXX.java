package com.BlueRay.mutton.model.entity.jpa;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;

@Entity
@Table(name = "khxx")
public class KHXX {
	private Integer clientID;
	private String khmc = "";
	private String khcz = "";
	private String lxr = "";
	private String lxdh = "";
	private String qtnr = "";
	/**
	 * @return the clientID
	 */
	@Id
	@GeneratedValue(strategy = GenerationType.AUTO)
	public Integer getClientID() {
		return clientID;
	}
	/**
	 * @return the khmc
	 */
	public String getKhmc() {
		return khmc;
	}
	/**
	 * @return the khcz
	 */
	public String getKhcz() {
		return khcz;
	}
	/**
	 * @return the lxr
	 */
	public String getLxr() {
		return lxr;
	}
	/**
	 * @return the lxdh
	 */
	public String getLxdh() {
		return lxdh;
	}
	/**
	 * @return the qtnr
	 */
	public String getQtnr() {
		return qtnr;
	}
	/**
	 * @param clientID the clientID to set
	 */
	public void setClientID(Integer clientID) {
		this.clientID = clientID;
	}
	/**
	 * @param khmc the khmc to set
	 */
	public void setKhmc(String khmc) {
		this.khmc = khmc;
	}
	/**
	 * @param khcz the khcz to set
	 */
	public void setKhcz(String khcz) {
		this.khcz = khcz;
	}
	/**
	 * @param lxr the lxr to set
	 */
	public void setLxr(String lxr) {
		this.lxr = lxr;
	}
	/**
	 * @param lxdh the lxdh to set
	 */
	public void setLxdh(String lxdh) {
		this.lxdh = lxdh;
	}
	/**
	 * @param qtnr the qtnr to set
	 */
	public void setQtnr(String qtnr) {
		this.qtnr = qtnr;
	}

}
