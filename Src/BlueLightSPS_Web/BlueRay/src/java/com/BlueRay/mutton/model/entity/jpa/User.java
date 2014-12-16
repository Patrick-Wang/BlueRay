package com.BlueRay.mutton.model.entity.jpa;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;

@Entity
@Table(name = "user")
public class User {
	String name;
	String psw;
	String department;
	Role role;
	/**
	 * @return the name
	 */
	@Id
	public String getName() {
		return name;
	}
	/**
	 * @return the psw
	 */
	public String getPsw() {
		return psw;
	}
	/**
	 * @return the department
	 */
	public String getDepartment() {
		return department;
	}
	/**
	 * @return the role
	 */
	public String getRole() {
		return role.name();
	}
	/**
	 * @param name the name to set
	 */
	public void setName(String name) {
		this.name = name;
	}
	
	public Role role(){
		return role;
	}
	/**
	 * @param psw the psw to set
	 */
	public void setPsw(String psw) {
		this.psw = psw;
	}
	/**
	 * @param department the department to set
	 */
	public void setDepartment(String department) {
		this.department = department;
	}
	/**
	 * @param role the role to set
	 */
	public void setRole(String role) {
		this.role = Role.valueOf(role);
	}
}
