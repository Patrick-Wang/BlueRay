#pragma once
#include "BRButton.h"
#include <vector>
class CBRButtonGroup
{
public:
	CBRButtonGroup();
	~CBRButtonGroup();
	void AddButton(CBRButton* lpButton){
		m_groupBtns.push_back(lpButton);
	}
	void OnClicked(CBRButton* lpButton);
	CDelegate<void(CBRButton*)> d_onSelected;
	CDelegate<void(CBRButton*)> d_onUnSelected;
	CBRButton* GetSelected(){
		return m_lpSelectedBtn;
	}
private:
	std::vector<CBRButton*> m_groupBtns;
	CBRButton* m_lpSelectedBtn;
};

