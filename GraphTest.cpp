////============================================================================
//// Name        : GraphTest.cpp
//// Author      : Khadeja Khalid & Tiffany Tran
//// Version     : Tuesday, March 6, 2018
////============================================================================
//
//#include <iostream>
//#include <cstdlib>
//#include <vector>
//#include "List.h"
//#include "Graph.h"
//
//using namespace std;
//
//int main()
//{
//   Graph g(5);   //5 vertices
//
//   g.addEdge(1,2);
//   g.addEdge(1,5);
//   g.addEdge(2,3);
//   g.addEdge(2,4);
//   g.addEdge(4,3);
//   g.addEdge(4,5);
//   g.addEdge(5,5);
//
//   cout << "************** Adjacency List *******************" << endl;
//   g.printGraph(cout);
//
//   cout << endl;
//   cout << "************** get Functions pt.1 *********************" << endl;
//   cout << g.getNumEdges()    << endl; //7
//   cout << g.getNumVertices() << endl; //5
//   cout << g.getDistance(4)   << endl; //-1
//   cout << g.getDistance(1)   << endl; //-1
//   cout << g.getParent(4)     << endl; //0
//   cout << g.getParent(2)     << endl; //0
//   cout << g.getColor(4)      << endl; //W
//   cout << g.getColor(3)      << endl; //W
//
//   cout << endl;
//   cout << "************** Breadth First Search **************" << endl;
//   //Source at 1
//   g.BFS(1);
//   g.printBFS(cout);
//
//   cout << endl;
//   cout << "************** Shortest Path *********************" << endl;
//   g.printPath(1, 1, cout); // 1
//
//   cout << endl;
//   g.printPath(1, 2, cout); // 1 - 2
//
//   cout << endl;
//   g.printPath(1, 3, cout); // 1 - 2 - 3
//
//   cout << endl;
//   g.printPath(1, 4, cout); // 1 - 2 - 4 or 1 - 5 - 4
//
//   cout << endl;
//   g.printPath(1, 5, cout); // 1 - 5
//
//   cout << endl;
//   cout << "************** get Functions pt.2 *********************" << endl;
//
//   cout << g.getNumEdges()    << endl; //7
//   cout << g.getNumVertices() << endl; //5
//   cout << g.getDistance(4)   << endl; //2
//   cout << g.getDistance(1)   << endl; //0
//   cout << g.getParent(4)     << endl; //2 or 5
//   cout << g.getParent(2)     << endl; //1
//   cout << g.getColor(4)      << endl; //B
//   cout << g.getColor(3)      << endl; //B
//
//   //Testing asserts
//   //g.getColor(8);
//   //g.BFS(8);
//   //Graph e(0);
//   //e.BFS(1);
//
//   return 0;
//
//}
//
///* Output
//************** Adjacency List *******************
//1: 2 5
//2: 1 3 4
//3: 2 4
//4: 2 3 5
//5: 1 4 5
//
//************** get Functions pt.1 *********************
//7
//5
//-1
//-1
//0
//0
//W
//W
//
//************** Breadth First Search **************
//v    c    p    d
//1    B    0    0
//2    B    1    1
//3    B    2    2
//4    B    2    2
//5    B    1    1
//
//************** Shortest Path *********************
//1
//1 - 2
//1 - 2 - 3
//1 - 2 - 4
//1 - 5
//************** get Functions pt.2 *********************
//7
//5
//2
//0
//2
//1
//B
//B
//*/
