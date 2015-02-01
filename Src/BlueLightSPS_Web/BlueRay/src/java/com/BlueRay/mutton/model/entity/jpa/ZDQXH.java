package com.BlueRay.mutton.model.entity.jpa;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;

@Entity
@Table(name = "zdqxh")
public class ZDQXH {
	private Integer id;
	private String zdqxh = "";
	@Id
	@GeneratedValue(strategy = GenerationType.AUTO)
	public Integer getId() {
		return id;
	}
	public void setId(Integer id) {
		this.id = id;
	}
	public String getZdqxh() {
		return zdqxh;
	}
	public void setZdqxh(String zdqxh) {
		this.zdqxh = zdqxh;
	}
	
}
