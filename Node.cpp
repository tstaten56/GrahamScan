#include "Node.h"

Node::Node()
{
}

Node::Node(double xVal, double yVal)
{
	x = xVal;
	y = yVal;
}

Node::~Node()
{
}

double Node::getX()
{
	return x;
}

double Node::getY()
{
	return y;
}

double Node::getAngle()
{
	return angle;
}

void Node::calcAngle()
{
	angle = y / x; //Not sure if this is right yet, it was in my notes like this though
}

void Node::setX(double xVal)
{
	x = xVal;
}

void Node::setY(double yVal)
{
	y = yVal;
}

void Node::adjustCoords(double previousX, double previousY)
{
	//The node for 0,0 has been chosen, now we have to adjust all the other nodes to align with its previous coords
	x = x - previousX;
	y = y - previousY;
}
