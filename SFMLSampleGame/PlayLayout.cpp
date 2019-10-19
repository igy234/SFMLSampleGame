#include "stdafx.h"
#include "PlayLayout.h"
#include "ColumnMaker.h"
#include "RowMaker.h"
#include "RectangleObject.h"
#include "Utils.h"

#define STARE_BABY_JEBAC_PRADEM (!this->BackgroundTexture.loadFromFile("Resources/Images/rain.png"))
PlayLayout::PlayLayout(shared_ptr<RenderWindow> window)
	:BaseLayout(window),
	BackDrop(0, 0, Window->getSize().x, Window->getSize().y)
{
	if STARE_BABY_JEBAC_PRADEM
	{
		cerr << "Error while loading Menu Texture" << endl; //error handling
		system("pause");
	}

	BackgroundSprite.setTexture(BackgroundTexture);
	BackDrop.setOrigin(0, 0);
	BackDrop.setFillColor(Color(0, 0, 0, 175));
	BackDrop.setOutlineThickness(Thickness);
	int FieldX, FieldY, WidthFactor, HeightFactor, WindowSizeX, WindowSizeY;

	WindowSizeX = Window->getSize().x;
	WindowSizeY = Window->getSize().y;

	tie(FieldX, FieldY, WidthFactor, HeightFactor) = CalcualteStartingPoint(WindowSizeX, WindowSizeY, EnumScreenFields::FieldOne, EnumScreenFields::FieldOne);
	ScoreRectangle.setPosition(0,0);
	ScoreRectangle.setOutlineThickness(Thickness);
	ScoreRectangle.SetWidth(FieldX + WidthFactor);
	ScoreRectangle.SetHeight(WindowSizeY);

	
	tie(FieldX, FieldY, WidthFactor, HeightFactor) = CalcualteStartingPoint(WindowSizeX, WindowSizeY, EnumScreenFields::FieldTwo, EnumScreenFields::FieldNine);
	HandRectangle.setPosition(FieldX+ThicknessShift, FieldY - ThicknessShift);
	HandRectangle.setOutlineThickness(Thickness);
	HandRectangle.SetWidth(FieldX + WidthFactor * (static_cast<int>(EnumScreenFields::FieldSix) + 1));
	HandRectangle.SetHeight(HeightFactor*(static_cast<int>(EnumScreenFields::FieldThree) + 1) - ThicknessShift);
	
	tie(FieldX, FieldY, WidthFactor, HeightFactor) = CalcualteStartingPoint(WindowSizeX, WindowSizeY, EnumScreenFields::FieldTwo, EnumScreenFields::FieldOne);
	UpperOponentRectangle.setPosition(FieldX + ThicknessShift, FieldY - ThicknessShift);
	UpperOponentRectangle.setOutlineThickness(Thickness);
	UpperOponentRectangle.SetWidth(FieldX + WidthFactor * (static_cast<int>(EnumScreenFields::FieldSix) + 1));
	UpperOponentRectangle.SetHeight(HeightFactor*(static_cast<int>(EnumScreenFields::FieldTwo) + 1) - ThicknessShift);

	tie(FieldX, FieldY, WidthFactor, HeightFactor) = CalcualteStartingPoint(WindowSizeX, WindowSizeY, EnumScreenFields::FieldTwo, EnumScreenFields::FieldThree);
	LowerOponentRectangle.setPosition(FieldX + ThicknessShift, FieldY - ThicknessShift);
	LowerOponentRectangle.setOutlineThickness(Thickness);
	LowerOponentRectangle.SetWidth(FieldX + WidthFactor * (static_cast<int>(EnumScreenFields::FieldSix) + 1));
	LowerOponentRectangle.SetHeight(HeightFactor*(static_cast<int>(EnumScreenFields::FieldTwo) + 1) - ThicknessShift);


	tie(FieldX, FieldY, WidthFactor, HeightFactor) = CalcualteStartingPoint(WindowSizeX, WindowSizeY, EnumScreenFields::FieldTwo, EnumScreenFields::FieldFive);
	UpperPlayerRectangle.setPosition(FieldX + ThicknessShift, FieldY);
	UpperPlayerRectangle.setOutlineThickness(Thickness);
	UpperPlayerRectangle.SetWidth(FieldX + WidthFactor * (static_cast<int>(EnumScreenFields::FieldSix) + 1));
	UpperPlayerRectangle.SetHeight(HeightFactor*(static_cast<int>(EnumScreenFields::FieldTwo) + 1) - ThicknessShift * ThicknessShift);
	

	tie(FieldX, FieldY, WidthFactor, HeightFactor) = CalcualteStartingPoint(WindowSizeX, WindowSizeY, EnumScreenFields::FieldTwo, EnumScreenFields::FieldSeven);
	LowerPlayerRectangle.setPosition(FieldX + ThicknessShift, FieldY - ThicknessShift);
	LowerPlayerRectangle.setOutlineThickness(Thickness);
	LowerPlayerRectangle.SetWidth(FieldX + WidthFactor * (static_cast<int>(EnumScreenFields::FieldSix) + 1));
	LowerPlayerRectangle.SetHeight(HeightFactor*(static_cast<int>(EnumScreenFields::FieldTwo) + 1) - ThicknessShift);
	


	PreviewCardRectangle;

}

PlayLayout::~PlayLayout()
{
}

void PlayLayout::Show()
{
	Window->draw(BackgroundSprite);
	Window->draw(BackDrop);
	Window->draw(ScoreRectangle);
	Window->draw(HandRectangle);
	Window->draw(LowerPlayerRectangle);
	Window->draw(UpperPlayerRectangle);
	Window->draw(LowerOponentRectangle);
	Window->draw(UpperOponentRectangle);
	
	
	//Window->draw(*ButtonObjectsMap["Play"]); // . get() nie dzia³a ale * bierze nam zwykly obiekt a nie shared_ptr, wywlekamy to na co ten shared ptr wskazuje
	//Window->draw(*ButtonObjectsMap["Deck"]);
	//Window->draw(*ButtonObjectsMap["Quit"]);
	//Window->draw(ButtonObjectsMap["Play"]->GetText());
	//Window->draw(ButtonObjectsMap["Deck"]->GetText());
	//Window->draw(ButtonObjectsMap["Quit"]->GetText());
	
}

void PlayLayout::ObtainVector(vector<shared_ptr<IGuiElement>> V)
{
	BaseLayout::ObtainVector(V); //zapisuje sobie na pó¿niej (ewentualnie)
	ColumnMaker columnMaker(Window->getSize().x, Window->getSize().y, EnumScreenFields::FieldThree, EnumScreenFields::FieldFour);
	columnMaker.OrganizePosition(V);
	/*RowMaker rowMaker(window->getSize().x, window->getSize().y, EnumScreenFields::FieldThree, EnumScreenFields::FieldFour);
	vector<reference_wrapper<BaseGuiElement>> Ve;
	Ve.push_back(b4);
	Ve.push_back(b5);
	Ve.push_back(b6);
	rowMaker.OrganizePosition(Ve);*/
}