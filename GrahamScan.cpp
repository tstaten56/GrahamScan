#include "GrahamScan.h"
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

GrahamScan::GrahamScan()
{
}

GrahamScan::~GrahamScan()
{
}

void GrahamScan::setNumOfNodes(int num)
{
	numOfNodes = num;
}

int GrahamScan::getNumOfNodes()
{
	return numOfNodes;
}

void GrahamScan::readFile(string filename)
{
	ifstream myFile;
	string temp;
	int numNodes, lineNum = 1;

	myFile.open(filename.c_str());
	if (!myFile)
	{
		cout << "File Failed to Open! Filename:" << filename << endl;
		exit(1);
	}
	cout << "Reading file..." << endl;
	//Get the file from input
	getline(myFile, temp);
	numNodes = atoi(temp.c_str()); //The first line is always the number of Nodes in the graph
	this->setNumOfNodes(numNodes);
	while (getline(myFile, temp))
	{
		int comma = temp.find(",");
		string xVal = temp.substr(0, comma);
		string yVal = temp.substr(comma + 1);
		graph.push_back(Node(atoi(xVal.c_str()), atoi(yVal.c_str()))); //adding the new node to the graph
	}
	myFile.close();
	this->scan();
}

void GrahamScan::outputFile(string filename)
{
	filename = filename.substr(0, filename.length() - 4);
	filename += "_hull.txt";
	ofstream myFile(filename);
	if (!myFile)
	{
		cout << "Error! Output file failed to open. Filename: " << filename << endl;
		exit(1);
	}
	else
	{
		//Readjust the coordinates to be the originals again
		//output the size of the hull, then the X,Y nodes
		myFile << stack.size() << "\n";
		for (int outputLoop = 0; outputLoop < stack.size(); outputLoop++)
		{
			myFile << stack[outputLoop].getX() + savedX << "," << stack[outputLoop].getY() + savedY << "\n";
		}
	}
	myFile.close();
}

void GrahamScan::turnDirection(Node current, Node prev1st, Node prev2nd) 
{
	//Calcs which direction of a turn we are taking
	//If a left turn, the new node is fine
	//If a  right turn, pop off the previous node off the stack  Calc turnDirection again
	int position = (prev1st.getX() - prev2nd.getX()) * (current.getY() - prev2nd.getY()) - (prev1st.getY() - prev2nd.getY()) * (current.getX() - prev2nd.getX());
	if (position >= 0) //Left hand, add the node! Same line? add the node! (this could mess us up)
	{
		stack.push_back(current);
	}
	else if (position < 0) //Negative means right hand turn
	{
		stack.pop_back(); //popping the previous
		if (stack.size() > 1) //Stack has to be 2 or greater to decide the turn direction
		{
			turnDirection(current, prev2nd, stack[stack.size() - 2]);
		}
		else
		{
			stack.push_back(current); //less than 2, just put the node on the stack!
		}
	}
}

void GrahamScan::findLowestY()
{
	//This will find the lowest Y then update graph
	double lowY = graph[0].getY();
	double xPos = graph[0].getX();
	for (int yLoop = 1; yLoop < numOfNodes; yLoop++)
	{
		if (graph[yLoop].getY() <= lowY)
		{
			if ((graph[yLoop].getY() == lowY) && (graph[yLoop].getX() < xPos) || (graph[yLoop].getY() < lowY))
			{
				xPos = graph[yLoop].getX(); //the lowest X is chosen when there is a tie in lowest Y
				//xPos is unchanged if the new X is greater than xPos and the Y vals are the same
			}
			lowY = graph[yLoop].getY();
		}
	}
	//Save the X and Y original lowest Y values
	savedX = xPos;
	savedY = lowY;
	//Next update all the values based on lowest Y
	for (int updateLoop = 0; updateLoop < numOfNodes; updateLoop++)
	{
		graph[updateLoop].adjustCoords(xPos, lowY);
		graph[updateLoop].calcAngle();
	}
}

void GrahamScan::scan()
{
	//First find lowest Y and update all values based on making this 0,0
	findLowestY();
	sort(graph.begin(), graph.end());
	for (int scanLoop = 0; scanLoop < numOfNodes; scanLoop++)
	{
		if (stack.size() < 3)
		{
			stack.push_back(graph[scanLoop]); //The first three will always be added to the stack
		} 
		else
		{
			turnDirection(graph[scanLoop], stack[stack.size() - 1], stack[stack.size() - 2]); //last added node, and the 2nd to last added node
		}
	}
}

void ReadTest()
{
	GrahamScan ex;
	string filename = "test1.txt";
	ex.readFile(filename);
	ex.outputFile(filename); 
}

void Test()
{
	ReadTest();
}

//int main()
//{
//	Test();
//	return 0;
//}
