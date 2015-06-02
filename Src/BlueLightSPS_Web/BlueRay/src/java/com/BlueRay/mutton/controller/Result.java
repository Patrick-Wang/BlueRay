package com.BlueRay.mutton.controller;

public class Result {
	private boolean result = false;

	public Result(boolean result) {
		super();
		this.result = result;
	}

	/**
	 * @return the result
	 */
	public boolean isResult() {
		return result;
	}

	/**
	 * @param result the result to set
	 */
	public void setResult(boolean result) {
		this.result = result;
	}
}
