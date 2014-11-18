#include <iostream>
#include "GrahamScan.h"
using namespace std;

int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		string file;
		int vert, horz;
		file = argv[1];
		GrahamScan ex;
		ex.readFile(file);
	}
	else
	{
		cout << "Wrong input format!" << endl;
		return 1;
	}

	return 0;
}