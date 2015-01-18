package com.BlueRay.mutton.model.entity.jpa;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;

@Entity
@Table(name = "bzxdtgg")
public class BZXDTGG {
	private Integer id;
	private String bzxdtgg;
	
	@Id
	@GeneratedValue(strategy = GenerationType.AUTO)
	public Integer getId() {
		return id;
	}
	public void setId(Integer id) {
		this.id = id;
	}
	public String getBzxdtgg() {
		return bzxdtgg;
	}
	public void setBzxdtgg(String bzxdtgg) {
		this.bzxdtgg = bzxdtgg;
	}
}
