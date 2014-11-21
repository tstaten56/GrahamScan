#pragma once
#ifndef GRAHAMSCAN_H
#include <vector>
#include "Node.h"

using namespace std;
class GrahamScan
{
private:
	//An array of Nodes, Node* arr; or  vector<Node> arr; might be better! 
	vector<Node> stack; //For hull-making
	Node* graph; //Holds the entire graph
	int numOfNodes;
	
public:
	GrahamScan();
	~GrahamScan();
	void readFile(string filename); //reads the file and calls required execution
	void outputFile(string filename); //outputs file named   original_hull.txt
	void turnDirection(int position1, int position2); //Calculates which turn we are taking
	void setNumOfNodes(int num);
	int getNumOfNodes();
	void scan(); //This is the main event
	void findLowestY();
};
#endif
