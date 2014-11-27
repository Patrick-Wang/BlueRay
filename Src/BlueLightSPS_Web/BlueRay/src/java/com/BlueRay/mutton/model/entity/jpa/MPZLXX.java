package com.BlueRay.mutton.model.entity.jpa;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;

@Entity
@Table(name = "mpzlxx")
public class MPZLXX {
	private Integer id;
	private String mpzl;
	/**
	 * @return the id
	 */
	@Id
	@GeneratedValue(strategy = GenerationType.AUTO)
	public Integer getId() {
		return id;
	}
	/**
	 * @return the mpzl
	 */
	public String getMpzl() {
		return mpzl;
	}
	/**
	 * @param id the id to set
	 */
	public void setId(Integer id) {
		this.id = id;
	}
	/**
	 * @param mpzl the mpzl to set
	 */
	public void setMpzl(String mpzl) {
		this.mpzl = mpzl;
	}
}
