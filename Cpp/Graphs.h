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

	bool everyNodeVisited(bool* array, int size) {
		for (int i = 0; i < size; i++) {
			if (array[i] == false)
				return false;
		}
		return true;
	}
	void AddEdgeNode(NodeEdge*& head, int from, int to, int dis) {
		NodeEdge* p = new NodeEdge;
		p->from = from;
		p->to = to;
		p->dis = dis;
		p->ng = head;
		head = p;
	}
	void PrimsAlgorithm(NodeNeigh** ln, int size, int start = 0) {

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
				if (visited[i] == true) {
					NodeNeigh* newNode = ln[i];
					while (newNode) {
						if (minimum == -1 && visited[newNode->to] == false) {
							minimum = newNode->dis;
							endEdge = newNode->to;
							startEdge = i;
							newNode = newNode->ng;
						}
						else if (minimum == -1 && visited[newNode->to] == true) {
							newNode = newNode->ng;
						}
						else if (minimum > newNode->dis && visited[newNode->to] == false) {
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

			visited[endEdge] = true;
			AddEdgeNode(outcome, startEdge, endEdge, minimum);

		} while (everyNodeVisited(visited, size));

		print_le(outcome);
	}

	void swap(NodeEdge*& le) {
		if (le && le->ng) {
			NodeEdge* p = le;
			le = le->ng;
			p->ng = le->ng;
			le->ng = p;
		}
	}
	void swap(NodeEdge*& le, NodeEdge* p) {
		if (le && le->ng && p == nullptr) {
			swap(le);
			return;
		}
		if (p && p->ng && p->ng->ng) {
			NodeEdge* p1 = p->ng;
			p->ng = p1->ng;
			p1->ng = p->ng->ng;
			p->ng->ng = p1;
		}
	}
	void sorting(NodeEdge*& le) {
		if (le && le->ng) {
			NodeEdge* p = le;
			NodeEdge* endEdge = NULL;
			NodeEdge* endEdge2 = NULL;
			bool is = true;
			while (is) {
				is = false;
				if (le->dis > le->ng->dis) {
					swap(le);
					is = true;
					endEdge = le;
				}
				p = le;
				while (p->ng && p->ng->ng && p->ng->ng != endEdge2) {
					if (p->ng->dis > p->ng->ng->dis) {
						endEdge = p->ng;
						is = true;
						swap(le, p);
					}
					p = p->ng;
				}
				endEdge2 = endEdge;
			}
		}
	}

	void KruskalsAlgorithm(NodeEdge* le, int size) {
		sorting(le);
		NodeEdge* outcome = nullptr;
		NodeEdge* p;
		int* lasy = new int[size];
		int las = 0;
		bool* visited = new bool[size];
		for (int i = 0; i < size; i++) {
			lasy[i] = 0;
			visited[i] = false;
		}

		while (le)
		{
			if (visited[le->to] == false && visited[le->from] == false) {
				visited[le->to] = true;
				visited[le->from] = true;
				las += 1;
				lasy[le->to] = las;
				lasy[le->from] = las;

				p = le;
				le = le->ng;
				p->ng = outcome;
				outcome = p;
			}
			else if (visited[le->to] == true && visited[le->from] == true) {
				if (lasy[le->to] != lasy[le->from]) {
					las = lasy[le->to] + lasy[le->from];
					for (int i = 0; i < size; i++) {
						if (lasy[i] == lasy[le->to])
							lasy[i] = las;
					}
					for (int i = 0; i < size; i++) {
						if (lasy[i] == lasy[le->from])
							lasy[i] = las;
					}
					p = le;
					le = le->ng;
					p->ng = outcome;
					outcome = p;
				}
				else {
					p = le;
					le = p->ng;
					delete p;
				}
			}
			else if ((visited[le->to] == false && visited[le->from] == true) ||
				(visited[le->to] == true && visited[le->from] == false)) {

				visited[le->to] = true;
				visited[le->from] = true;
				if (visited[le->from] == true)
					lasy[le->to] = lasy[le->from];
				else
					lasy[le->from] = lasy[le->to];
				p = le;
				le = le->ng;
				p->ng = outcome;
				outcome = p;
			}
		}
		print_le(outcome);
	}
}
