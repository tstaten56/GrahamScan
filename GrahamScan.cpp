#include "GrahamScan.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

GrahamScan::GrahamScan()
{
}

GrahamScan::~GrahamScan()
{
	delete [] graph;
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
	graph = new Node[numOfNodes]; //allocate space
	int nodeLoop = 0;
	while (getline(myFile, temp))
	{
		int comma = temp.find(",");
		string xVal = temp.substr(0, comma);
		string yVal = temp.substr(comma + 1);
		graph[nodeLoop] = Node(atoi(xVal.c_str()), atoi(yVal.c_str()));
		nodeLoop++;
		//graph.push_back(Node(atoi(xVal.c_str()), atoi(yVal.c_str()))); //adding the new node to the graph
	}
	myFile.close();
	//this->scan();
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
		//output the size of the hull, then the X,Y nodes
		myFile << numOfNodes << "\n";
		for (int outputLoop = 0; outputLoop < numOfNodes; outputLoop++)
		{
			myFile << stack[outputLoop].getX() << "," << stack[outputLoop].getY() << "\n";
		}
	}
	myFile.close();
}

void GrahamScan::turnDirection(int position1, int position2)
{
	//Calcs which direction of a turn we are taking
	//If a left turn, he new node is fine
	//If a  right turn, pop off the previous node off the stack and push the new node on. Wont need the previous node ever again

}

void GrahamScan::findLowestY()
{
	//This will find the lowest Y using mergesort the update graph
	//int positionX, positionY;
	//Next update all the values based on lowest Y
	for (int updateLoop = 0; updateLoop < numOfNodes; updateLoop++)
	{
//		graph[updateLoop].adjustCoords(positionX, positionY);
	}
}

void GrahamScan::scan()
{
	//First find lowest Y and update all values based on making this 0,0
	findLowestY();
	
}

void ReadTest()
{
	GrahamScan ex;
	string filename = "midtermTest.txt";
	ex.readFile(filename);
	ex.outputFile(filename); //both appear to be working with just the array. outputFile was changed to vector(Stack) but havent tested that
}

void Test()
{
	ReadTest();
}

int main()
{
	Test();
	return 0;
}
