#pragma once
#include <fstream>

namespace gr {
	
	int** createMatrix(int& size) {
		std::fstream read;
		read.open("graf.txt");
		read >> size;

		int** matrix = new int* [size];
		for (int i = 0; i < size; i++)
			matrix[i] = new int[size];

		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++)
				read >> matrix[i][j];
		}

		return matrix;
	}

	struct NodeNeigh {
		int to;
		int dis; //distance
		NodeNeigh* ng; //neighbour
	};
	NodeNeigh** createListOfNeighbourhood(int& size) {
		std::fstream read;
		read.open("graf.txt");
		read >> size;

		NodeNeigh** LN = new NodeNeigh * [size];
		for (int i = 0; i < size; i++)
			LN[i] = nullptr;

		int currentVal;

		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				NodeNeigh* tmp = LN[i];
				read >> currentVal;
				if (currentVal != 0) {
					LN[i] = new NodeNeigh;
					LN[i]->dis = currentVal;
					LN[i]->to = j;
					LN[i]->ng = tmp;
				}
			}
		}

		return LN;
	}

	struct NodeEdge {
		int to;
		int from;
		int dis;
		NodeEdge* ng;
	};
	NodeEdge* createListOfEdges(int& size) {
		std::fstream read;
		read.open("graf.txt");
		read >> size;

		NodeEdge* LE = nullptr;

		int currentVal;

		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				read >> currentVal;
				if (currentVal != 0) {
					NodeEdge* tmp2 = LE;
					LE = new NodeEdge;
					LE->dis = currentVal;
					LE->to = j;
					LE->ng = tmp2;
					LE->from = i;
				}
			}
		}
		return LE;
	}
	bool everyNodeVisited(bool* array, int size) {
		for (int i = 0; i < size; i++) {
			if (array[i] == true)
				return true;
		}
		return false;
	}
	void AddEdgeNode(NodeEdge*& head, int from, int to, int dis) {
		NodeEdge* p = new NodeEdge;
		p->from = from;
		p->to = to;
		p->dis = dis;
		p->ng = head;
		head = p;
	}
	NodeEdge* PrimsAlgorithm(NodeNeigh** ln, int& size, int start) {
		
		NodeEdge* outcome = nullptr;
		bool* visited = new bool[size];
		for (int i = 0; i < size; i++)
			visited[i] = false;
		visited[start] = true;

		int minimum = -1;
		int startEdge;
		int endEdge;
		
		do {
			for (int i = 0; i < size; i++) {
				if (visited[i] == false) {
					NodeNeigh* newNode = ln[i];
					while (newNode){
						if (minimum == -1 && visited[newNode->to] == true) {
							minimum = newNode->dis;
							endEdge = newNode->to;
							startEdge = i;
							newNode = newNode->ng;
						}
						else if (minimum == -1 && visited[newNode->to] == false) {
							newNode = newNode->ng;
						}
						else if (minimum > newNode->dis && visited[newNode->to] == true) {
							minimum = newNode->dis;
							endEdge = newNode->to;
							startEdge = i;
						}
						else {
							newNode = newNode->ng;
						}
					}
				}
			}

			visited[endEdge] = false;
			AddEdgeNode(outcome, startEdge, endEdge, minimum);

		} while (everyNodeVisited(visited, size));

		return outcome;
	}
	
	void print_ln(NodeNeigh** lnoriginal, int size) {
		NodeNeigh** LN = lnoriginal;
		for (int i = 0; i < size; i++) {
			std::cout << i << "-> ";
			while (LN[i]) {
				std::cout << "to:" << LN[i]->to << " dis:" << LN[i]->dis << "\t";
				LN[i] = LN[i]->ng;
			}
			std::cout << std::endl;
		}
	}
	void print_le(NodeEdge* leoriginal) {
		NodeEdge* LE = leoriginal;
		while (LE) {
			std::cout << "from:" << LE->from << " to:" << LE->to << " dis:" << LE->dis << "-->";
			LE = LE->ng;
		}
		std::cout << "NULL" << std::endl;
	}
}
