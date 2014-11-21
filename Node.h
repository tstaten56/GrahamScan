#pragma once
#ifndef NODE_H

using namespace std;
class Node
{
private:
	double x, y; //The x/y values
	double angle; //the tanget angle between this node and 0,0
public:
	Node(); //Probably won't need this
	Node(double xVal, double yVal);
	~Node();
	void calcAngle(); //used for sorting these into order for pushing onto the stack, determine left/right turn etc
	double getX();
	double getY();
	void setX(double xVal); //Used for updating the x/y after the "lowest" node is chosen based on its Y
	void setY(double yVal); 
	double getAngle();
	void adjustCoords(double previousX, double previousY); //The node for 0,0 has been chosen, now we have to adjust all the other nodes to align with its previous coords
};
#endif
