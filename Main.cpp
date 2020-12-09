#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include "SinglyLinkedList.h"
#include "SortingAlgs.h"
#include "BinarySearchTree.h"

#define	UNDERLINE\
	std::cout << "----------------------------------------------" << std::endl;
#define RAND\
	rand()%99+0
#define HUGE_ARR 1000000

using sll::Node;

void printArray(int arr[], int size);

int main() {

	srand(time(NULL));
	/*Node* head = nullptr;

	for (int i = 0; i < 15; i++) 
		sll::addFront(head, RAND);
	sll::show(head);
	sll::removeBack(head);
	sll::removeFront(head);
	sll::show(head);
	
	UNDERLINE;

	Node* toMerge1 = nullptr;
	Node* toMerge2 = nullptr;
	Node* empty = nullptr;
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

	UNDERLINE;

	Node* toMergeSort = nullptr;
	for (int i = 0; i < 15; i++)
		sll::addFront(toMergeSort, RAND);
	std::cout << "Before mergeSort: ";  sll::show(toMergeSort);
	sa::ll::mergeSort(toMergeSort);
	std::cout << "After mergeSort: "; sll::show(toMergeSort);*/

	/*UNDERLINE;

	Node* toCombSort = nullptr;
	for (int i = 0; i < 15; i++)
		sll::addFront(toCombSort, RAND);
	std::cout << "Before combSort: ";  sll::show(toCombSort);
	sa::ll::combSort(toCombSort);
	std::cout << "After combSort: "; sll::show(toCombSort);

	UNDERLINE;

	Node* toBubbleSort = nullptr;
	for (int i = 0; i < 15; i++)
		sll::addFront(toBubbleSort, RAND);
	std::cout << "Before bubbleSort: ";  sll::show(toBubbleSort);
	sa::ll::bubbleSort(toBubbleSort);
	std::cout << "After bubbleSort: "; sll::show(toBubbleSort);*/

	UNDERLINE;

	const int arrSize = 15;
	int heapArray[arrSize+1];
	for (int i = 1; i <= arrSize; i++)
		heapArray[i] = RAND;
	std::cout << "Before: ";	for (int i = 1; i <= arrSize; i++)
									std::cout << heapArray[i] << " ";
	
	sa::arr::heapSort(heapArray, arrSize);
	std::cout << std::endl << "After: "; for (int i = 1; i <= arrSize; i++)
									std::cout << heapArray[i] << " "; std::cout << std::endl;

	UNDERLINE;

	long* bigArr1 = new long[HUGE_ARR];
	long* bigArr2 = new long[HUGE_ARR];
	long* bigArr3 = new long[HUGE_ARR];
	long val;
	for (int i = 0; i < HUGE_ARR; i++) {
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
	sa::arr::bubbleSortOptimized(bigArr3, HUGE_ARR - 1);
	t2 = std::chrono::high_resolution_clock::now();
	auto durationBs = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
	std::cout << "BS:  " << durationBs << std::endl;

	
	
	delete [] bigArr1;
	delete [] bigArr2;
	delete [] bigArr3;
	
	system("pause");
	return 0;
}

void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}
