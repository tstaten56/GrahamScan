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
	vector<Node> graph;
	int numOfNodes;
	
public:
	GrahamScan();
	~GrahamScan();
	void readFile(string filename); //reads the file and calls required execution
	void outputFile(string filename); //outputs file named   original_hull.txt
	void turnDirection(Node prev1st, Node prev2nd, Node prev3rd); //Calculates which turn we are taking
	void setNumOfNodes(int num);
	int getNumOfNodes();
	void scan(); //This is the main event
	void findLowestY();
};
#endif
