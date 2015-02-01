package com.BlueRay.mutton.model.entity.jpa;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;

@Entity
@Table(name = "zjdy")
public class ZJDY {
	private Integer id;
	private String zjdy = "";
	@Id
	@GeneratedValue(strategy = GenerationType.AUTO)
	public Integer getId() {
		return id;
	}
	public void setId(Integer id) {
		this.id = id;
	}
	public String getZjdy() {
		return zjdy;
	}
	public void setZjdy(String zjdy) {
		this.zjdy = zjdy;
	}
}
