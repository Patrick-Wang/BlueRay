package com.BlueRay.mutton.common;

public abstract class RequestHandler<T> {
	RequestHandler<T> nextHandler;
	public RequestHandler<T> next(RequestHandler<T> next){
		nextHandler = next;
		return next;
	}
	
	protected void callNext(T request){
		if (null != nextHandler){
			nextHandler.handle(request);
		}
	}

	public void handle(T request){
		if (match(request)){
			onHandle(request);
		}else{
			callNext(request);
		}
	}

	abstract protected boolean match(T request);
	
	abstract protected void onHandle(T request);
}