#pragma once
template<typename RType>
class IMessageStation
{
public:
	virtual ~IMessageStation(){};
	virtual RType OnMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) = 0;
};

