#pragma once
#ifndef NODE_H

using namespace std;
class Node
{
private:
	double x, y; //The x/y values
	double angle; //the tanget angle between this node and 0,0
public:
	Node();
	Node(double xVal, double yVal);
	~Node();
	void calcAngle(); //used for sorting these into order for pushing onto the stack, determine left/right turn etc
	double getX();
	double getY();
	void setX(double xVal); //Used for updating the x/y after the "lowest" node is chosen based on its Y
	void setY(double yVal); 
	bool operator<(Node& thatNode) const; //for sorting
	double getAngle();
	void adjustCoords(double xPos, double yPos); //The node for 0,0 has been chosen, now we have to adjust all the other nodes to align with its previous coords
};
#endif
