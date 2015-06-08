package com.BlueRay.mutton.model.entity.jpa;

import javax.persistence.Entity;
import javax.persistence.Table;

@Entity
@Table(name = "cgxxb")
public class CGXXB {
	public Integer cgID;
	public String cg = "";
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
