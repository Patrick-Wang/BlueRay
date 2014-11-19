#include "stdafx.h"
#include "BRButtonGroup.h"


CBRButtonGroup::CBRButtonGroup()
	: m_lpSelectedBtn(NULL)
{
}


CBRButtonGroup::~CBRButtonGroup()
{
}

void CBRButtonGroup::OnClicked(CBRButton* lpButton)
{
	if (m_lpSelectedBtn != lpButton)
	{
		std::vector<CBRButton*>::iterator it = std::find(m_groupBtns.begin(), m_groupBtns.end(), lpButton);
		if (it != m_groupBtns.end())
		{
			if (m_lpSelectedBtn != NULL)
			{
				d_onUnSelected(m_lpSelectedBtn);
			}
			m_lpSelectedBtn = lpButton;
			d_onSelected(lpButton);
		}
	}
}
