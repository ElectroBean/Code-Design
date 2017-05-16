#include "DefenseItem.h"



DefenseItem::DefenseItem(Vector3 aPosition)
{
	this->Global->columns[2] = aPosition;
}

DefenseItem::~DefenseItem()
{
}

void DefenseItem::update(float deltaTime) 
{
	
}

void DefenseItem::drawBox(aie::Renderer2D * a_Render)
{
	a_Render->drawBox(Global->columns[2].x, Global->columns[2].y, 32, 32);
}

void DefenseItem::getShot()
{

}