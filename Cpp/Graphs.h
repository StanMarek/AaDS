#pragma once
#include <fstream>

namespace gr {
	
	int** createMatrix(int& rozmiar) {
		std::fstream read;
		read.open("graf.txt");
		read >> rozmiar;

		int** matrix = new int* [rozmiar];
		for (int i = 0; i < rozmiar; i++)
			matrix[i] = new int[rozmiar];

		for (int i = 0; i < rozmiar; i++) {
			for (int j = 0; j < rozmiar; j++)
				read >> matrix[i][j];
		}

		return matrix;
	}

	struct Node {
		int to;
		int dis; //distance
		Node* ng; //neighbour
	};
	Node** createLN(int& rozmiar) {
		std::fstream read;
		read.open("graf.txt");
		read >> rozmiar;

		Node** LN = new Node * [rozmiar];
		for (int i = 0; i < rozmiar; i++)
			LN[i] = nullptr;

		int currentVal;

		for (int i = 0; i < rozmiar; i++) {
			for (int j = 0; j < rozmiar; j++) {
				Node* tmp = LN[i];
				read >> currentVal;
				if (currentVal != 0) {
					LN[i] = new Node;
					LN[i]->dis = currentVal;
					LN[i]->to = j;
					LN[i]->ng = tmp;
				}
			}
		}

		return LN;
	}

	struct Node2 {
		int to;
		int from;
		int dis;
		Node* ng;
	};
}
