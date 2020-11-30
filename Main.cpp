#include <iostream>
#include <ctime>
#include <cstdlib>
#include "SinglyLinkedList.h"
#include "SortingAlgs.h"

#define	UNDERLINE\
	std::cout << "----------------------------------------------" << std::endl;
#define RAND\
	rand()%99+0

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
	for (int i = 1; i <= arrSize; i++)
		std::cout << heapArray[i] << " ";
	sa::arr::heapSort(heapArray, arrSize);
	std::cout << std::endl;
	for (int i = 1; i <= arrSize; i++)
		std::cout << heapArray[i] << " ";
	

	system("pause");
	return 0;
}

void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}
