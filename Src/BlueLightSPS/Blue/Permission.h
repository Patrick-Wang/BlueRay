#pragma once
class CPermission
{
public:
	CPermission();
	~CPermission();
	bool xsywsh;
	bool xsjhsh;
	bool jhywsh;
	bool jhjhsh;
	bool jhbzywsh;
	bool jhbzjhsh;
	bool plan;
	bool sale;

	/**
	* @return the plan
	*/
	bool getPlan() {
		return plan;
	}
	/**
	* @return the sale
	*/
	bool getSale() {
		return sale;
	}

	/**
	* @return the xsywsh
	*/
	bool getXsywsh() {
		return xsywsh;
	}
	/**
	* @return the xsjhsh
	*/
	bool getXsjhsh() {
		return xsjhsh;
	}
	/**
	* @return the jhywsh
	*/
	bool getJhywsh() {
		return jhywsh;
	}
	/**
	* @return the jhjhsh
	*/
	bool getJhjhsh() {
		return jhjhsh;
	}
	/**
	* @return the jhbzywsh
	*/
	bool getJhbzywsh() {
		return jhbzywsh;
	}
	/**
	* @return the jhbzjhsh
	*/
	bool getJhbzjhsh() {
		return jhbzjhsh;
	}
	/**
	* @param xsywsh the xsywsh to set
	*/
	void setXsywsh(bool xsywsh) {
		this->xsywsh = xsywsh;
	}
	/**
	* @param xsjhsh the xsjhsh to set
	*/
	void setXsjhsh(bool xsjhsh) {
		this->xsjhsh = xsjhsh;
	}
	/**
	* @param jhywsh the jhywsh to set
	*/
	void setJhywsh(bool jhywsh) {
		this->jhywsh = jhywsh;
	}
	/**
	* @param jhjhsh the jhjhsh to set
	*/
	void setJhjhsh(bool jhjhsh) {
		this->jhjhsh = jhjhsh;
	}
	/**
	* @param jhbzywsh the jhbzywsh to set
	*/
	void setJhbzywsh(bool jhbzywsh) {
		this->jhbzywsh = jhbzywsh;
	}
	/**
	* @param jhbzjhsh the jhbzjhsh to set
	*/
	void setJhbzjhsh(bool jhbzjhsh) {
		this->jhbzjhsh = jhbzjhsh;
	}

	/**
	* @param plan the plan to set
	*/
	void setPlan(bool plan) {
		this->plan = plan;
	}

	/**
	* @param sale the sale to set
	*/
	void setSale(bool sale) {
		this->sale = sale;
	}
};

