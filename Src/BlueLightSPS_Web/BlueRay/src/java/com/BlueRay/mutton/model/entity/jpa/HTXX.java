package com.BlueRay.mutton.model.entity.jpa;

import java.io.Serializable;
import java.sql.Date;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;

@Entity
@Table(name = "htxx")
public class HTXX implements Serializable {

	private static final long serialVersionUID = 1L;
	
	private Integer ID;
	private String htID;
	private String clientID;
	private String ggxhID;
	private Integer sl;
	private String zcID;
	private String dfr;
	private String zdqdyID;
	private String yylggID;
	private String sfjf;
	private String bpqxhID;
	private String bmqxhID;
	private String dlcd;
	private String zxcd;
	private String mpzl;
	private Date ddrq;
	private String bz;
	private String ddzt;
	private String sftgywsh;
	private String sftgjhsh;
	/**
	 * @return the iD
	 */
	@Id
	@GeneratedValue(strategy = GenerationType.AUTO)
	@Column(name = "ID")
	public Integer getID() {
		return ID;
	}
	/**
	 * @return the htID
	 */
	public String getHtID() {
		return htID;
	}
	/**
	 * @return the clientID
	 */
	public String getClientID() {
		return clientID;
	}
	/**
	 * @return the ggxhID
	 */
	public String getGgxhID() {
		return ggxhID;
	}
	/**
	 * @return the sl
	 */
	public Integer getSl() {
		return sl;
	}
	/**
	 * @return the zcID
	 */
	public String getZcID() {
		return zcID;
	}
	/**
	 * @return the dfr
	 */
	public String getDfr() {
		return dfr;
	}
	/**
	 * @return the zdqdyID
	 */
	public String getZdqdyID() {
		return zdqdyID;
	}
	/**
	 * @return the yylggID
	 */
	public String getYylggID() {
		return yylggID;
	}
	/**
	 * @return the sfjf
	 */
	public String getSfjf() {
		return sfjf;
	}
	/**
	 * @return the bpqxhID
	 */
	public String getBpqxhID() {
		return bpqxhID;
	}
	/**
	 * @return the bmqxhID
	 */
	public String getBmqxhID() {
		return bmqxhID;
	}
	/**
	 * @return the dlcd
	 */
	public String getDlcd() {
		return dlcd;
	}
	/**
	 * @return the zxcd
	 */
	public String getZxcd() {
		return zxcd;
	}
	/**
	 * @return the mpzl
	 */
	public String getMpzl() {
		return mpzl;
	}
	/**
	 * @return the ddrq
	 */
	public Date getDdrq() {
		return ddrq;
	}
	/**
	 * @return the bz
	 */
	public String getBz() {
		return bz;
	}
	/**
	 * @return the ddzt
	 */
	public String getDdzt() {
		return ddzt;
	}
	/**
	 * @return the sftgywsh
	 */
	public String getSftgywsh() {
		return sftgywsh;
	}
	/**
	 * @return the sftgjhsh
	 */
	public String getSftgjhsh() {
		return sftgjhsh;
	}
	/**
	 * @param iD the iD to set
	 */
	public void setID(Integer iD) {
		ID = iD;
	}
	/**
	 * @param htID the htID to set
	 */
	public void setHtID(String htID) {
		this.htID = htID;
	}
	/**
	 * @param clientID the clientID to set
	 */
	public void setClientID(String clientID) {
		this.clientID = clientID;
	}
	/**
	 * @param ggxhID the ggxhID to set
	 */
	public void setGgxhID(String ggxhID) {
		this.ggxhID = ggxhID;
	}
	/**
	 * @param sl the sl to set
	 */
	public void setSl(Integer sl) {
		this.sl = sl;
	}
	/**
	 * @param zcID the zcID to set
	 */
	public void setZcID(String zcID) {
		this.zcID = zcID;
	}
	/**
	 * @param dfr the dfr to set
	 */
	public void setDfr(String dfr) {
		this.dfr = dfr;
	}
	/**
	 * @param zdqdyID the zdqdyID to set
	 */
	public void setZdqdyID(String zdqdyID) {
		this.zdqdyID = zdqdyID;
	}
	/**
	 * @param yylggID the yylggID to set
	 */
	public void setYylggID(String yylggID) {
		this.yylggID = yylggID;
	}
	/**
	 * @param sfjf the sfjf to set
	 */
	public void setSfjf(String sfjf) {
		this.sfjf = sfjf;
	}
	/**
	 * @param bpqxhID the bpqxhID to set
	 */
	public void setBpqxhID(String bpqxhID) {
		this.bpqxhID = bpqxhID;
	}
	/**
	 * @param bmqxhID the bmqxhID to set
	 */
	public void setBmqxhID(String bmqxhID) {
		this.bmqxhID = bmqxhID;
	}
	/**
	 * @param dlcd the dlcd to set
	 */
	public void setDlcd(String dlcd) {
		this.dlcd = dlcd;
	}
	/**
	 * @param zxcd the zxcd to set
	 */
	public void setZxcd(String zxcd) {
		this.zxcd = zxcd;
	}
	/**
	 * @param mpzl the mpzl to set
	 */
	public void setMpzl(String mpzl) {
		this.mpzl = mpzl;
	}
	/**
	 * @param ddrq the ddrq to set
	 */
	public void setDdrq(Date ddrq) {
		this.ddrq = ddrq;
	}
	/**
	 * @param bz the bz to set
	 */
	public void setBz(String bz) {
		this.bz = bz;
	}
	/**
	 * @param ddzt the ddzt to set
	 */
	public void setDdzt(String ddzt) {
		this.ddzt = ddzt;
	}
	/**
	 * @param sftgywsh the sftgywsh to set
	 */
	public void setSftgywsh(String sftgywsh) {
		this.sftgywsh = sftgywsh;
	}
	/**
	 * @param sftgjhsh the sftgjhsh to set
	 */
	public void setSftgjhsh(String sftgjhsh) {
		this.sftgjhsh = sftgjhsh;
	}

}
