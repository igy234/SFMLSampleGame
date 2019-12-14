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

void BaseLayout::HandleMouseEvent(const Event& evnt)
{
	switch (evnt.type)
	{
	case Event::MouseButtonPressed:
		if (evnt.mouseButton.button == sf::Mouse::Left)
		{
			for (auto element : GuiElements)
			{
				float GuiElementWidth, GuiElementHeight, GuiElementPositionX, GuiElementPositionY;
				GuiElementPositionX = element->GetPositionX();
				GuiElementPositionY = element->GetPositionY();
				GuiElementWidth = element->GetWidth();
				GuiElementHeight = element->GetHeight();
				if ((evnt.mouseButton.x >= (GuiElementPositionX - GuiElementWidth / 2) && evnt.mouseButton.x < (GuiElementPositionX + GuiElementWidth / 2)) && // quick maths
					(evnt.mouseButton.y >= (GuiElementPositionY - GuiElementHeight / 2) && evnt.mouseButton.y <= (GuiElementPositionY + GuiElementHeight / 2)))
				{
					element->action();
				}
			}
		}

		for (auto element : GuiElemtnsForCurrentState)
		{
			if (!element->GetIsUserInteractive())
			{
				continue;
			}
			float GuiElementWidth, GuiElementHeight, GuiElementPositionX, GuiElementPositionY;
			GuiElementPositionX = element->GetPositionX();
			GuiElementPositionY = element->GetPositionY();
			GuiElementWidth = element->GetWidth();
			GuiElementHeight = element->GetHeight();
			if ((evnt.mouseButton.x >= (GuiElementPositionX - GuiElementWidth / 2) && evnt.mouseButton.x < (GuiElementPositionX + GuiElementWidth / 2)) && // quick maths
				(evnt.mouseButton.y >= (GuiElementPositionY - GuiElementHeight / 2) && evnt.mouseButton.y <= (GuiElementPositionY + GuiElementHeight / 2)))
			{
				element->action();
			}
		}
		break;

	case Event::MouseMoved:
		for (auto element : GuiElements)
		{
			float GuiElementWidth, GuiElementHeight, GuiElementPositionX, GuiElementPositionY;
			GuiElementPositionX = element->GetPositionX();
			GuiElementPositionY = element->GetPositionY();
			GuiElementWidth = element->GetWidth();
			GuiElementHeight = element->GetHeight();
			if ((evnt.mouseMove.x >= (GuiElementPositionX - GuiElementWidth / 2) && evnt.mouseMove.x < (GuiElementPositionX + GuiElementWidth / 2)) && // quick maths
				(evnt.mouseMove.y >= (GuiElementPositionY - GuiElementHeight / 2) && evnt.mouseMove.y <= (GuiElementPositionY + GuiElementHeight / 2)))
			{
				element->Highlight();
			}
			else
			{
				element->Unhighlight();
			}
		}

		for (auto element : GuiElemtnsForCurrentState)
		{
			if (!element->GetIsUserInteractive())
			{
				continue;
			}

			float GuiElementWidth, GuiElementHeight, GuiElementPositionX, GuiElementPositionY;
			GuiElementPositionX = element->GetPositionX();
			GuiElementPositionY = element->GetPositionY();
			GuiElementWidth = element->GetWidth();
			GuiElementHeight = element->GetHeight();
			if ((evnt.mouseMove.x >= (GuiElementPositionX - GuiElementWidth / 2) && evnt.mouseMove.x < (GuiElementPositionX + GuiElementWidth / 2)) && // quick maths
				(evnt.mouseMove.y >= (GuiElementPositionY - GuiElementHeight / 2) && evnt.mouseMove.y <= (GuiElementPositionY + GuiElementHeight / 2)))
			{
				element->Highlight();
			}
			else
			{
				element->Unhighlight();
			}
		}
	break;
	}
}

void BaseLayout::SetGuiElementsForCurrentState(vector<shared_ptr<IGuiElement>> V)
{
	GuiElemtnsForCurrentState = V;
}

void BaseLayout::AddGuiElementToCurrentState(shared_ptr<IGuiElement> E)
{
	GuiElemtnsForCurrentState.push_back(E);
}
