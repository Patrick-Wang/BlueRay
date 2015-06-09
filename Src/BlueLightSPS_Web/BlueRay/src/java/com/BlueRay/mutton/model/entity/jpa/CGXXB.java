package com.BlueRay.mutton.model.entity.jpa;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;

@Entity
@Table(name = "cgxxb")
public class CGXXB {
	private Integer cgID;
	private String cg = "";
	
	@Id
	@GeneratedValue(strategy = GenerationType.AUTO)
	public Integer getCgID() {
		return cgID;
	}
	public void setCgID(Integer cgID) {
		this.cgID = cgID;
	}
	public String getCg() {
		return cg;
	}
	public void setCg(String cg) {
		this.cg = cg;
	}
	


}
