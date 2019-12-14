#pragma once
#include "RectangleObject.h"
#include "ICardModel.h"

///Base class for card entity
class BaseCard : public RectangleObject 
{
protected:
	///holding card's texture
	Texture CardTexture; 
	///holding card's sprite
	Sprite CardSprite;
	///holding shared pointer to card model
	shared_ptr<ICardModel> Model;

public:

	///@brief seting width scale for sprite and width for rectangle
	///@param "width" Used to set width
	virtual void SetWidth(float width) override; 

	///@brief seting height scale for sprite and height for rectangle
	///@param "height" Used to set height
	virtual void SetHeight(float height) override;

	///@brief seting position for sprite and for rectangle
	///@param "x" Used to set x position
	virtual void SetPositionX(float x) override; 

	///@brief seting position for sprite and for rectangle
	///@param "y" Used to set y position
	virtual void SetPositionY(float y) override; 

	///@brief getter for texture
	///@return texture of the card
	virtual Texture GetTexture() override;  

	///@brief sets appropriate color of outlinethickness of card, and marks that base gui element is highlighted 
	virtual void Highlight() override; 

	///@brief removes outlinethickness of card, and marks that base gui element is unhighlighted
	virtual void Unhighlight() override;  
	
	///@brief gers model of the card
	shared_ptr<ICardModel> GetModel();

	///@brief loading texture and setting it to sprite, rescalling it, default color implemented
	///@param "model" used to ascribe model of the card
	///@param "positionX" Used to set x position
	///@param "positionY" Used to set y position
	///@param "objectWidth" Used to set object's width
	///@param "objectHeight" Used to set object;s height
	///@param "color" Used to specify the color
	BaseCard(shared_ptr<ICardModel> model, int positionX = 0, int positionY = 0, float objectWidth = 163, float objectHeight = 185, Color color = Color(0, 0, 0, 0));
	~BaseCard();

	///@brief drawing appropriate components to window
	///@param "window" shared pointer to SFML's output window
	void Draw(shared_ptr<RenderWindow> window) override;
};

