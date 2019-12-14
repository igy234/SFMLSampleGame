#pragma once
#include "BaseGuiElement.h"




///Class managing the preview card operations
class PreviewCard :	public BaseGuiElement
{
protected:
	///holding hardcoded scale coefficient
	const float HalfScale = 0.5f;
	
	///holding preview texture 
	Texture CardPreviewTexture;

	///holding sprite
	Sprite CardPreviewSprite;

public:
	///@brief constructor ascribing positions and dimension of preview object, seting position of sprite and its scale
	///@param "positionX" representing posion x of the preview object
	///@param "positionY" representing posion y of the preview object
	///@param "objectWidth" representingwidth of the preview object
	///@param "objectHeight" representing height of the preview object
	PreviewCard(int positionX, int positionY, float objectWidth, float objectHeight); 
	~PreviewCard();

	///@brief drawing card preview sprite
	///@param "window" representing program's window 
	virtual void Draw(shared_ptr<RenderWindow> window) override; 

	///@brief getter for card preview texture
	///@returns texture of card preview
	virtual Texture GetTexture() override; 

	///@brief setter for position x of the preview object and sprite
	///@param "x" used to specify position x 
	virtual void SetPositionX(float x) override;

	///@brief setter for position y of the preview object and sprite
	///@param "y" used to specify position y
	virtual void SetPositionY(float y) override;

	///@brief setter for texture of the preview object and sprite
	///@param "PreviewTexture" used to specify the texture
	void SetTexture(Texture PreviewTexture);
};

