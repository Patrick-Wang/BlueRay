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

	private Integer ID;
	private String htID;
	private Integer clientID;
	private Integer ggxhID;
	private Integer sl;
	private Integer zcID;
	private String dfr = "N";
	private Integer zdqdyID;
	private Integer yylggID;
	private String sfjf = "N";
	private Integer bpqxhID;
	private Integer bmqxhID;
	private String dlcd;
	private String zxcd;
	private Integer mpzl;
	private String bz;
	private Date ddrq;
	private String sftgywsh = "N";
	private String sftgjhsh = "N";
	private Integer yxj = 100;
	private String ddzt;
	
	public static Class<?>  getFroeignClass(int col){
		switch(col){
		case 2:
			return KHXX.class;
		case 3:
			return CPGGXHXX.class;
		case 5:
			return ZCXX.class;
		case 7:
			return ZDQDYFLXX.class;
		case 8:
			return YYLGGFLXX.class;
		case 10:
			return BPQXHFLXX.class;
		case 11:
			return BMQXHFLXX.class;
		case 14:
			return MPZLXX.class;
		default:
			return null;
		}
	}
	
	public Integer getYxj() {
		return yxj;
	}
	public void setYxj(Integer yxj) {
		this.yxj = yxj;
	}
	/**
	 * @return the iD
	 */
	@Id
	@GeneratedValue(strategy = GenerationType.AUTO)
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
	public Integer getClientID() {
		return clientID;
	}
	/**
	 * @return the ggxhID
	 */
	public Integer getGgxhID() {
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
	public Integer getZcID() {
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
	public Integer getZdqdyID() {
		return zdqdyID;
	}
	/**
	 * @return the yylggID
	 */
	public Integer getYylggID() {
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
	public Integer getBpqxhID() {
		return bpqxhID;
	}
	/**
	 * @return the bmqxhID
	 */
	public Integer getBmqxhID() {
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
	public Integer getMpzl() {
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
	public void setClientID(Integer clientID) {
		this.clientID = clientID;
	}
	/**
	 * @param ggxhID the ggxhID to set
	 */
	public void setGgxhID(Integer ggxhID) {
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
	public void setZcID(Integer zcID) {
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
	public void setZdqdyID(Integer zdqdyID) {
		this.zdqdyID = zdqdyID;
	}
	/**
	 * @param yylggID the yylggID to set
	 */
	public void setYylggID(Integer yylggID) {
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
	public void setBpqxhID(Integer bpqxhID) {
		this.bpqxhID = bpqxhID;
	}
	/**
	 * @param bmqxhID the bmqxhID to set
	 */
	public void setBmqxhID(Integer bmqxhID) {
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
	public void setMpzl(Integer mpzl) {
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
