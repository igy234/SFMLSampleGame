#pragma once

#include "stdafx.h"

class Ball : public Drawable
{
public:

	Ball(float t_x, float t_y);
	Ball() = delete; //usuwamy domyslny robimy w³asny konstruktor
	~Ball() = default;

	void update(int BorderX, int BorderY);

	float left();
	float right();
	float top();
	float bottom();

private:
	CircleShape circle;
	const float ballRadius{ 10.0f }; //promien kulki
	const float ballVelocity{ 0.3f }; //predkosc kulki
	Vector2f velocity{ ballVelocity, ballVelocity }; //velocity to wektor poziomu i pionu
	void draw(RenderTarget& target, RenderStates state) const override;

};

