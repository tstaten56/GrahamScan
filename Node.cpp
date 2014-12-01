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
	if (y == 0)
	{
		if (x > 0)
		{
			angle = 5;
		}
		else if (x == 0)
		{
			angle = 0;
		}
		else
		{
			angle = 0; 
		}
	}
	else
	{
		if (x > 0)
		{
			angle = y / x; 
		}
		else
		{ //X is negative, we'll make it positive and larger than the rest 
			angle = ((x / y) * -1) + 1000; //so we know it's in the 2nd quadrant when we sort by angle
		}
	}
}

bool Node::operator<(Node& thatNode) const
{//For sorting, based on the Y values
	return (angle < thatNode.getAngle());
}

void Node::setX(double xVal)
{
	x = xVal;
}

void Node::setY(double yVal)
{
	y = yVal;
}

void Node::adjustCoords(double xPos, double  yPos)
{
	//The node for 0,0 has been chosen, now we have to adjust all the other nodes to align with its previous coords
	x = x - xPos;
	y = y - yPos;
}
