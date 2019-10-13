#include "stdafx.h"
#include "BaseLayout.h"


BaseLayout::BaseLayout(shared_ptr<RenderWindow> window)
	: Window(window)
{

}


BaseLayout::~BaseLayout()
{

}

void BaseLayout::ObtainVector(vector<shared_ptr<IGuiElement>> V)
{
	GuiElements = V;
}

void BaseLayout::ObtainButtonsMap(map<string, shared_ptr<ButtonObject>> M) 
{
	ButtonObjectsMap = M;
}

void BaseLayout::HandleMouseEvent(const Event& evnt)
{
	switch (evnt.type)
	{
	case Event::MouseButtonPressed:
		if (evnt.mouseButton.button == sf::Mouse::Left)
		{
			for (auto elementPair : GuiElements)
			{
				float btnWidth, btnHeight, btnPositionX, btnPositionY;
				auto btnObject = elementPair; //first -> name(string), second -> value(buttonObject), bo mapa to zbiór obiektów posiadaj¹cych 2 wartoœci. 
				btnPositionX = btnObject->GetPositionX();
				btnPositionY = btnObject->GetPositionY();
				btnWidth = btnObject->GetWidth();
				btnHeight = btnObject->GetHeight();
				if ((evnt.mouseButton.x >= (btnPositionX - btnWidth / 2) && evnt.mouseButton.x < (btnPositionX + btnWidth / 2)) && // quick maths
					(evnt.mouseButton.y >= (btnPositionY - btnHeight / 2) && evnt.mouseButton.y <= (btnPositionY + btnHeight / 2)))
				{
					btnObject->action();
				}
			}
		}
		break;
	case Event::MouseMoved:
		for (auto elementPair : GuiElements)
		{
			float btnWidth, btnHeight, btnPositionX, btnPositionY;
			auto btnObject = elementPair; //first -> name(string), second -> value(buttonObject), bo mapa to zbiór obiektów posiadaj¹cych 2 wartoœci. 
			btnPositionX = btnObject->GetPositionX();
			btnPositionY = btnObject->GetPositionY();
			btnWidth = btnObject->GetWidth();
			btnHeight = btnObject->GetHeight();
			if ((evnt.mouseMove.x >= (btnPositionX - btnWidth / 2) && evnt.mouseMove.x < (btnPositionX + btnWidth / 2)) && // quick maths
				(evnt.mouseMove.y >= (btnPositionY - btnHeight / 2) && evnt.mouseMove.y <= (btnPositionY + btnHeight / 2)))
			{
				//cout << " dzia³a h" << endl;
				btnObject->Highlight();
			}
			else
			{
				//cout << " niedzia³a h" << endl;
				btnObject->Unhighlight();
			}
		}
	break;
	}
}