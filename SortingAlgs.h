#pragma once
#include "SinglyLinkedList.h"

//sorting algorithms
namespace sa {
	//array
	namespace arr {
		void swap(int* val1, int* val2) {
			int tmp = *val1;
			*val1 = *val2;
			*val2 = tmp;
		}
		void swap(int val1, int val2) {
			int tmp = val1;
			val1 = val2;
			val2 = tmp;
		}
		
		void heapify(int n, int* arr, int heapSize) {
			int left = 2 * n;
			int right = 2 * n + 1;
			int largest;

			if (left <= heapSize && arr[left] > arr[n])
				largest = left;
			else
				largest = n;
			if (right <= heapSize && arr[right] > arr[largest])
				largest = right;
			if (largest != n) {
				swap(&arr[n], &arr[largest]);
				heapify(largest, arr, heapSize);
			}
		}

		void bubbleSort(int* arr, int arrSize) {
			for(int i = 0; i < arrSize-1; i++)
				for (int j = 0; j < arrSize - i - 1; j++) {
					if (arr[j] > arr[j+1])
						swap(&arr[j], &arr[j+1]);
				}
		}
		void heapSort(int* arr, int arrSize) {
			int heapSize = arrSize;
			
			for (int i = arrSize / 2 ; i > 0; i--)
				heapify(i, arr, arrSize);

			while (heapSize > 1) {
				swap(&arr[1], &arr[heapSize]);
				heapSize--;
				heapify(1, arr, heapSize);
			}
		}
	}

	//linked list
	namespace ll {
		using sll::Node;
		void bubbleSort(Node*& head) {	//poprawic
			if (head == nullptr && head->next == nullptr)
				return;

			bool isSwapped = false;
			Node* tmp1;
			Node* tmp2 = nullptr;
			do {
				isSwapped = false;
				tmp1 = head;
				while (tmp1->next != tmp2) {
					if (tmp1->val > tmp1->next->val) {
						sll::swap(tmp1, tmp1->next);
						isSwapped = true;
					}
					tmp1 = tmp1->next;
				}
				tmp2 = tmp1;
			} while (isSwapped);
		}
		void mergeSort(Node*& head) {
			if (head && head->next) {
				Node* h1 = nullptr;
				Node* h2 = nullptr;
				split(head, h1, h2);
				mergeSort(h1);
				mergeSort(h2);
				merge(head, h1, h2);
			}
		}
		void combSort(Node*& head) {	//poprawic
			int size = listSize(head);
			int gap = size;
			bool isSwapped = true;

			while (gap > 1 || isSwapped) {
				gap = gap * 10 / 13;
				if (gap == 0)
					gap = 1;
				isSwapped = false;
				Node* tmp = head;
				for (int i = 0; i < gap - i; i++)
					tmp = tmp->next;

				Node* tmp2 = tmp;

				if (head->val > tmp->next->val)
					sll::swapHeadNode(head, tmp);

				tmp = tmp2;
				tmp2 = head;

				while (tmp->next) {
					if (tmp2->next->val > tmp->next->val) {
						sll::swap(tmp2, tmp);
						isSwapped = true;
					}
					tmp2 = tmp2->next;
					tmp = tmp->next;
				}
			}
			bubbleSort(head);
		}
	}
}