package com.BlueRay.mutton.model.entity.jpa;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;

@Entity
@Table(name = "yylggflxx")
public class YYLGGFLXX {
	private Integer yylggID;
	private String yylgg;
	/**
	 * @return the yylggID
	 */
	@Id
	@GeneratedValue(strategy = GenerationType.AUTO)
	public Integer getYylggID() {
		return yylggID;
	}
	/**
	 * @return the yylgg
	 */
	public String getYylgg() {
		return yylgg;
	}
	/**
	 * @param yylggID the yylggID to set
	 */
	public void setYylggID(Integer yylggID) {
		this.yylggID = yylggID;
	}
	/**
	 * @param yylgg the yylgg to set
	 */
	public void setYylgg(String yylgg) {
		this.yylgg = yylgg;
	}

}
