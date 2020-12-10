#pragma once
#include "SinglyLinkedList.h"
//asssssssssssssssssssaaaassssdsssssssssssss
//sorting algorithms
namespace sa {
	//array
	
	namespace arr {
		void swap(int* val1, int* val2) {
			int tmp = *val1;
			*val1 = *val2;
			*val2 = tmp;
		}
		void swap(long* val1, long* val2) {
			long tmp = *val1;
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
		long partition(long* arr, long l, long r) {
			long x = arr[r];
			long i = l-1;
			for (long j = l; j <= r-1; j++) {
				if (arr[j] <= x)
					swap(&arr[++i], &arr[j]);
			}
			swap(&arr[i + 1], &arr[r]);
			return i + 1;
		}
		long partitionHoare(int* arr, long l, long r) {
			int x = arr[l];
			long i = l;
			long j = r + 1;
			while (true) {
				do
					++i;
				while (i <= r && arr[i] < x);
				
				do
					--j;
				while (arr[j] > x);
				if (i > j)
					break;
				swap(&arr[i], &arr[j]);
			}
			arr[l] = arr[j];
			arr[j] = x;
			return j;
		}
		long partitionMed(int* arr, long l, long r) {
			if (r - l == 1) {
				if (arr[r] < arr[l])
					swap(&arr[r], &arr[l]);
				return l;
			}
			swap(&arr[l + 1], &arr[l + r >> 1]);

			if (arr[l + 1] > arr[r])
				swap(&arr[l + 1], &arr[r]);
			if (&arr[l] > &arr[r])
				swap(&arr[l], &arr[r]);
			if (arr[l + 1] > arr[l])
				swap(&arr[l + 1], &arr[l]);

			int x = arr[l];
			long i = l + 1;
			long j = r;
			while (true) {
				do
					++i;
				while (arr[i] < x);
				do
					--j;
				while (arr[j] > x);

				if (i > j)
					break;
				swap(&arr[i], &arr[j]);
			}
			arr[l] = arr[j];
			arr[j] = x;
			return j;
		}

		void bubbleSort(int* arr, int arrSize) {
			for(int i = 0; i < arrSize-1; i++)
				for (int j = 0; j < arrSize - i - 1; j++) {
					if (arr[j] > arr[j+1])
						swap(&arr[j], &arr[j+1]);
				}
		}
		void bubbleSortOptimized(long* arr, long arrSize) {
			bool isSwapped;
			
			for (long i = 0; i < arrSize - 1; i++) {
				isSwapped = false;
				for (long j = 0; j < arrSize - 1 - i; j++) {
					if (arr[j] > arr[j + 1]) {
						swap(&arr[j], &arr[j + 1]);
						isSwapped = true;
					}
				}
				if (isSwapped == false)
					break;
			}
		}
		void bubbleSortOptimized(long* arr, long l, long r) {
			bool isSwapped;
			int arrSize = r - l + 1;

			for (int i = 0; i < arrSize - 1; i++) {
				isSwapped = false;
				for (int j = l; j < arrSize - 1 - i; j++) {
					if (arr[j] > arr[j + 1]) {
						swap(&arr[j], &arr[j + 1]);
						isSwapped = true;
					}
				}
				if (isSwapped == false)
					break;
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
		void quickSort(long *arr, long l, long r) {
			if (l < r) {
				long p = partition(arr, l, r);
				//long p = partitionHoare(arr, l, r);
				//long p = partitionMed(arr, l, r);
				quickSort(arr, l, p -1);
				quickSort(arr, l + 1, p);
			}
		}
		void quickSortHybrid(long* arr, long l, long r) {
			if (r - l > 10) {
				long p = partition(arr, l, r);
				//long p = partitionHoare(arr, l, r);
				//long p = partitionMed(arr, l, r);
				quickSortHybrid(arr, l, p - 1);
				quickSortHybrid(arr, l + 1, p);
			}

			else
				bubbleSortOptimized(arr, l, r);
		}
		void quickSortGeneral(long* arr, long arrSize) {
			quickSortHybrid(arr, 0, arrSize - 1);
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