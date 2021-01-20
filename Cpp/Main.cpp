#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <string>
#include "SinglyLinkedList.h"
#include "SortingAlgs.h"
#include "BinarySearchTree.h"
#include "Graphs.h"

#define	UNDERLINE\
	std::cout << "----------------------------------------------" << std::endl;
#define RAND\
	rand()%99+0
#define HUGE_ARR 1000000

int size = 0;
void _size() {
	std::cout << size << std::endl;
}

void printArray(int arr[], int size);
void printMatrix(int** arr, int size);
void test_linkedListBasics();
void test_merge_linkedList();
void test_mergeSort_linkedLis();
void test_combSort_linkedLis();
void test_bubbleSort_linkedLis();
void test_timeMeasurement_array();
void test_heapSort_array();
void test_mergeSort_array();
void test_matrix_graph();
void test_ln_graph();
void test_le_graph();
void test_graphs();
void test_Prim();
void test_Kruskal();

///////////////////////////////////////////
//WYSZUKIWANIE WZORCA W OPARCIU O AUTOMAT//
///////////////////////////////////////////
//FIXME: naprawic bo cos nie dziala
bool isALgAvailable(std::string pattern, std::string text) {
	if (pattern.length() <= text.length())
		return true;
	else
		return false;
}
std::string generateString(int length) {
	std::string text = "";
	for (int i = 0; i < length; i++) {
		text += char(65 + (rand() % 3));
	}
	return text;
}
int* createTable(std::string pattern) {
	int* T = new int[pattern.length()];
	int i = 2;
	int j = 0;
	T[0] = -1;
	T[1] = 0;

	while(i < pattern.length())	{
		if (pattern[i - 1] == pattern[j]) {
			T[i] = j + 1;
			i++;
			j++;
		}
		else {
			if (j > 0) {
				j = T[j];
			}
			else {
				T[i] = 0;
				i++;
			}
		}
	}

	return T;
}
int automat(std::string text, std::string pattern) {
	if (!isALgAvailable(pattern, text))
		return -1;
	else {

		int m = 0;
		int i = 0;
		int* T = createTable(pattern);

		while (m + i < text.length()) {
			if (pattern[i] == text[m + i]) {
				i += 1;
				if (i == pattern.length())
					return m;
			}
			else {
				m += 1;
				if (i > 0) {
					i = T[i];
				}
			}
			return text.length();
		}
	}
}

int main()
{	
	srand(time(NULL));
	std::string text = generateString(20);
	std::string pattern = generateString(7);
	std::cout << "TEXT: " << text << std::endl;
	std::cout << "PATTERN: " << pattern << std::endl;
	std::cout << "POSITION: " << automat(text, pattern) << std::endl;
	
	/*std::cout << "TEXT: " << "ABC ABCDAB ABCDABCDABDE" << std::endl;
	std::cout << "PATTERN: " << "ABCDABD" << std::endl;
	std::cout << "POSITION: " << automat("ABC ABCDAB ABCDABCDABDE", "ABCDABD") << std::endl;*/
	UNDERLINE;
	

	return 0;
}

void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

void printMatrix(int** arr, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
			std::cout << arr[i][j] << "	  ";
		std::cout << std::endl;
	}
}

void test_linkedListBasics()
{
	sll::Node* head = nullptr;

	for (int i = 0; i < 15; i++)
		sll::addFront(head, RAND);
	sll::show(head);
	sll::removeBack(head);
	sll::removeFront(head);
	sll::show(head);
}

void test_merge_linkedList()
{
	sll::Node* toMerge1 = nullptr;
	sll::Node* toMerge2 = nullptr;
	sll::Node* empty = nullptr;
	int j = 2;
	int k = 1;
	for (int i = 0; i < 10; i++) {
		sll::addBack(toMerge1, k);
		sll::addBack(toMerge2, j);
		k += 2;
		j += 2;
	}
	sll::show(toMerge1);
	sll::show(toMerge2);
	sll::merge(empty, toMerge1, toMerge2);
	sll::show(empty);
}

void test_mergeSort_linkedLis()
{
	sll::Node* toMergeSort = nullptr;
	for (int i = 0; i < 15; i++)
		sll::addFront(toMergeSort, RAND);
	std::cout << "Before mergeSort: ";  sll::show(toMergeSort);
	sa::ll::mergeSort(toMergeSort);
	std::cout << "After mergeSort: "; sll::show(toMergeSort);
}

void test_combSort_linkedLis()
{
	sll::Node* toCombSort = nullptr;
	for (int i = 0; i < 15; i++)
		sll::addFront(toCombSort, RAND);
	std::cout << "Before combSort: ";  sll::show(toCombSort);
	sa::ll::combSort(toCombSort);
	std::cout << "After combSort: "; sll::show(toCombSort);
}

void test_bubbleSort_linkedLis()
{
	sll::Node* toBubbleSort = nullptr;
	for (int i = 0; i < 15; i++)
		sll::addFront(toBubbleSort, RAND);
	std::cout << "Before bubbleSort: ";  sll::show(toBubbleSort);
	sa::ll::bubbleSort(toBubbleSort);
	std::cout << "After bubbleSort: "; sll::show(toBubbleSort);
}

void test_timeMeasurement_array()
{
	long* bigArr1 = new long[HUGE_ARR];
	long* bigArr2 = new long[HUGE_ARR];
	long* bigArr3 = new long[HUGE_ARR];
	long val;
	for (long i = 0; i < HUGE_ARR; i++) {
		val = rand() % HUGE_ARR;
		bigArr1[i] = val;
		bigArr2[i] = val;
		bigArr3[i] = val;
	}

	std::cout << "Czas dzialania: " << std::endl;

	auto t1 = std::chrono::high_resolution_clock::now();
	sa::arr::quickSort(bigArr1, 0, HUGE_ARR - 1);
	auto t2 = std::chrono::high_resolution_clock::now();
	auto durationQs = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
	std::cout << "QSN: " << durationQs << std::endl;

	t1 = std::chrono::high_resolution_clock::now();
	sa::arr::quickSortHybrid(bigArr2, 0, HUGE_ARR - 1);
	t2 = std::chrono::high_resolution_clock::now();
	auto durationQsh = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
	std::cout << "QSH: " << durationQsh << std::endl;

	t1 = std::chrono::high_resolution_clock::now();
	sa::arr::bubbleSortOptimized(bigArr3, 0, HUGE_ARR-1);
	t2 = std::chrono::high_resolution_clock::now();
	auto durationBs = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
	std::cout << "BS:  " << durationBs << std::endl;

	delete[] bigArr1;
	delete[] bigArr2;
	delete[] bigArr3;
}

void test_heapSort_array()
{
	const int arrSize = 15;
	int heapArray[arrSize + 1];
	for (int i = 1; i <= arrSize; i++)
		heapArray[i] = RAND;
	std::cout << "Before: ";	for (int i = 1; i <= arrSize; i++)
		std::cout << heapArray[i] << " ";

	sa::arr::heapSort(heapArray, arrSize);
	std::cout << std::endl << "After: "; for (int i = 1; i <= arrSize; i++)
		std::cout << heapArray[i] << " "; std::cout << std::endl;
}

void test_mergeSort_array()
{
	int tablica[10];
	for (int i = 0; i < 10; i++) {
		tablica[i] = RAND;
		//tablica[i] = i;
	}
	printArray(tablica, 10);
	sa::arr::mergeSort<int>(tablica, 10);
	printArray(tablica, 10);
}

void test_matrix_graph()
{
	int** matrix = gr::createMatrix(size);
	printMatrix(matrix, size);

	for (int i = 0; i < size; i++)
		delete[] matrix[i];
	delete[] matrix;
}

void test_ln_graph()
{
	gr::NodeNeigh** LN = gr::createListOfNeighbourhood(size);
	gr::print_ln(LN, size);

	for (int i = 0; i < size; i++)
		delete[] LN[i];
	delete[] LN;

}

void test_le_graph()
{
	gr::NodeEdge* LE = gr::createListOfEdges(size);
	gr::print_le(LE);

	delete[] LE;
}

void test_graphs()
{
	test_matrix_graph();
	UNDERLINE;
	test_ln_graph();
	UNDERLINE;
	test_le_graph();

}

void test_Prim()
{
	gr::NodeNeigh** ln = gr::createListOfNeighbourhood(size);
	gr::PrimsAlgorithm(ln, size, 1);
}

void test_Kruskal()
{
	gr::NodeEdge* le = gr::createListOfEdges(size);
	gr::KruskalsAlgorithm(le, size);
}
