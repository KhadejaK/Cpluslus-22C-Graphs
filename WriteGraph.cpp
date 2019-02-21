//============================================================================
// Name        : WriteGraph.cpp
// Author      : Khadeja Khalid & Tiffany Tran
// Version     : Tuesday, March 6, 2018
//============================================================================

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "List.h"
#include "Graph.h"

using namespace std;

int main()
{
	ifstream inFile;
	ofstream outFile;
	string infilename;
	string outfilename;

	int n;		// number of vertices


	cout << "Welcome to WriteGraph!\n\n";


	// prompt a user for the name of a file
	cout << "Enter the name of the file containing the graph information: ";
	getline(cin, infilename);
	inFile.open(infilename);


	// loop to report an error if the file name is not found in the directory
	while(!inFile)
	{
		cout << "Invalid file name! \n\n"
			 << "Please enter the name of the file: ";
		getline(cin, infilename); 	// or cin >> filename; ??? both work :>
		inFile.open(infilename);
	}


	// read in the contents of the file specified by the user
	cout << "\n***Reading from " << infilename << "***\n";

	inFile >> n;	// read in the number of vertices
	Graph g(n);

	// prompt the user for the name of an output file
	cout << "\nPlease enter the name of the output file: ";
	getline(cin, outfilename);
	outFile.open(outfilename);

	int n1, n2;
	do
	{
		inFile >> n1;
		inFile >> n2;
		if (n1 != 0)
			g.addEdge(n1, n2);

	} while (n1 != 0);

	g.printGraph(outFile);
	outFile << endl;

	int m1, m2;
	do
	{
		inFile >> m1;
		inFile >> m2;
		if (m1 != 0)
		{
			g.BFS(m1);
			outFile << "The distance from " << m1 << " to " << m2 << ": " <<
					g.getDistance(m2) << endl;

			outFile << "The shortest path from " << m1 << " to " << m2 << ": ";
			g.printPath(m1, m2, outFile);
			outFile << endl;
		}
	} while (m1 != 0);

	inFile.close();
	outFile.close();

	cout << "\nThank you! Your Graph is now written to " << outfilename << "!";


	return 0;
}
/*
Welcome to WriteGraph!

Enter the name of the file containing the graph information: asdkshjkdshljkdsf
Invalid file name!

Please enter the name of the file: input
Invalid file name!

Please enter the name of the file: input.txt
Invalid file name!

Please enter the name of the file: input1.txt

***Reading from input1.txt***

Please enter the name of the output file: output1.txt
Thank you! Your Graph is now written to output1.txt!
*/
