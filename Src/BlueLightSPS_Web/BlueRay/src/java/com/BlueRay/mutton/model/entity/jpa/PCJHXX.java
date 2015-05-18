package com.BlueRay.mutton.model.entity.jpa;

import java.sql.Date;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;

@Entity
@Table(name = "pcjhxxb")
public class PCJHXX {
	public String getBz() {
		return bz;
	}

	public void setBz(String bz) {
		this.bz = bz;
	}

	Integer pcjhID;
	Integer htxxID;
	Date jhscrq;
	String sftgywsh = "N";
	String sftgjhsh = "N";
	
	Date jhbzrq;
	String bzsftgywsh = "N";
	String bzsftgjhsh = "N";
	
	Date jhfhrq;
	String tcbh = "";
	String ccbh = "";
	
	String ddzt = "";
	String bz="";
	/**
	 * @return the pcjhID
	 */
	@Id
	@GeneratedValue(strategy = GenerationType.AUTO)
	public Integer getPcjhID() {
		return pcjhID;
	}

	/**
	 * @return the jhscrq
	 */
	public Date getJhscrq() {
		return jhscrq;
	}
	/**
	 * @return the jhbzrq
	 */
	public Date getJhbzrq() {
		return jhbzrq;
	}
	/**
	 * @return the jhfhrq
	 */
	public Date getJhfhrq() {
		return jhfhrq;
	}
	/**
	 * @return the tcbh
	 */
	public String getTcbh() {
		return tcbh;
	}
	/**
	 * @return the ccbh
	 */
	public String getCcbh() {
		return ccbh;
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
	 * @return the bzsftgywsh
	 */
	public String getBzsftgywsh() {
		return bzsftgywsh;
	}
	/**
	 * @return the bzsftgjhsh
	 */
	public String getBzsftgjhsh() {
		return bzsftgjhsh;
	}
	/**
	 * @return the ddzt
	 */
	public String getDdzt() {
		return ddzt;
	}
	/**
	 * @param pcjhID the pcjhID to set
	 */
	public void setPcjhID(Integer pcjhID) {
		this.pcjhID = pcjhID;
	}

	/**
	 * @param jhscrq the jhscrq to set
	 */
	public void setJhscrq(Date jhscrq) {
		this.jhscrq = jhscrq;
	}
	/**
	 * @param jhbzrq the jhbzrq to set
	 */
	public void setJhbzrq(Date jhbzrq) {
		this.jhbzrq = jhbzrq;
	}
	/**
	 * @param jhfhrq the jhfhrq to set
	 */
	public void setJhfhrq(Date jhfhrq) {
		this.jhfhrq = jhfhrq;
	}
	/**
	 * @param tcbh the tcbh to set
	 */
	public void setTcbh(String tcbh) {
		this.tcbh = tcbh;
	}
	/**
	 * @param ccbh the ccbh to set
	 */
	public void setCcbh(String ccbh) {
		this.ccbh = ccbh;
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
	/**
	 * @param bzsftgywsh the bzsftgywsh to set
	 */
	public void setBzsftgywsh(String bzsftgywsh) {
		this.bzsftgywsh = bzsftgywsh;
	}
	/**
	 * @param bzsftgjhsh the bzsftgjhsh to set
	 */
	public void setBzsftgjhsh(String bzsftgjhsh) {
		this.bzsftgjhsh = bzsftgjhsh;
	}
	/**
	 * @param ddzt the ddzt to set
	 */
	public void setDdzt(String ddzt) {
		this.ddzt = ddzt;
	}

	/**
	 * @return the htxxID
	 */
	public Integer getHtxxID() {
		return htxxID;
	}

	/**
	 * @param htxxID the htxxID to set
	 */
	public void setHtxxID(Integer htxxID) {
		this.htxxID = htxxID;
	}
}
