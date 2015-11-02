package com.BlueRay.mutton.model.entity.jpa;

import java.io.Serializable;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;

@Entity
@Table(name = "zxd")
public class ZXD implements Serializable {

	private static final long serialVersionUID = 1L;
	
	@Id
	@GeneratedValue(strategy = GenerationType.AUTO)
	private Integer id;
	
	private String type;
	
	private Double capacity;
	
	private Double power;

	public String getType() {
		return type;
	}

	public void setType(String type) {
		this.type = type;
	}

	public Integer getId() {
		return id;
	}

	public void setId(Integer id) {
		this.id = id;
	}

	public Double getCapacity() {
		return capacity;
	}

	public void setCapacity(Double capacity) {
		this.capacity = capacity;
	}

	public Double getPower() {
		return power;
	}

	public void setPower(Double power) {
		this.power = power;
	}

}
