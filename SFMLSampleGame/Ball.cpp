#include "stdafx.h"
#include "Ball.h"


Ball::Ball(float t_x, float t_y)
{
	circle.setPosition(t_x, t_y);
	circle.setRadius(this->ballRadius);
	circle.setFillColor(Color::White);

	circle.setOrigin(this->ballRadius, this->ballRadius); //ustawiamy origin na œrodek kó³ka czyli w prawo radius i w dó³ radius
}

void Ball::draw(RenderTarget& target, RenderStates state) const 
{
	target.draw(this->circle, state);
}

void Ball::update(int BorderX, int BorderY)
{
	circle.move(this->velocity); 

	if (this->left() < 0)
		velocity.x = ballVelocity; 
	if (this->right() > BorderX)
		velocity.x = -ballVelocity;
	if (this->top() < 0)
		velocity.y = ballVelocity;
	if (this->bottom() > BorderY)
		velocity.y = -ballVelocity;
}

float Ball::left()
{
	return this->circle.getPosition().x - circle.getRadius();
}
float Ball::right()
{
	return this->circle.getPosition().x + circle.getRadius();
}
float Ball::top()
{
	return this->circle.getPosition().y - circle.getRadius();
}
float Ball::bottom()
{
	return this->circle.getPosition().y + circle.getRadius();
}
