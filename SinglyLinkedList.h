#pragma once
//singly linked list
namespace sll {

	struct Node{
		Node* next;
		int val;
	};

	bool isEmpty(Node*& head) {
		return head == nullptr;
	}

	int listSize(Node* head) {
		int size = 0;
		Node* tmp = head;

		while (tmp)
			size++;

		return size;
	}

	void show(Node* head) {
		Node* tmp = head;
		std::cout << "HEAD->";
		while (tmp) {
			std::cout << tmp->val << "->";
			tmp = tmp->next;
		}
		std::cout << "NULL" << std::endl;
	}
	void addFront(Node*& head, int x) {
		Node* newNode = new Node;
		newNode->val = x;
		newNode->next = head;
		head = newNode;
	}
	void addBack(Node*& head, int x) {
		Node* newNode = new Node;
		if (isEmpty(head)) {
			addFront(head, x);
		}
		else {
			Node* tmp = head;
			newNode->val = x;
			newNode->next = nullptr;

			while (tmp->next) {
				tmp = tmp->next;
			}

			tmp->next = newNode;
		}
	}
	void addBefore(Node*& head, Node* nodeAfter, int x) {
		Node* newNode = new Node;
		
		if (head == nodeAfter)
			addFront(head, x);
		else {
			newNode->val = x;
			newNode->next = nodeAfter;
			Node* currentNode = head;
			while (currentNode->next != nodeAfter) {
				currentNode = currentNode->next;
			}
			currentNode->next = newNode;
		}
	}
	void addAfter(Node*& nodeBefore, int x) {
		Node* newNode = new Node;
		newNode->val = x;
		newNode->next = nodeBefore->next;
		nodeBefore->next = newNode;
	}
	void removeFront(Node*& head) {
		
		if (!head)
			return;
		else {
			Node* tmp = head;
			head = head->next;

			delete tmp;
		}
	}
	void removeBack(Node*& head) {
		if (!head)
			return;
		if (head->next) {
			Node* tmp = head;
			while (tmp->next->next)
				tmp = tmp->next;

			delete tmp->next;
			tmp->next = nullptr;
		}
		else {
			removeFront(head);
			head = nullptr;
		}
	}
	void removeNode(Node*& head, Node* toRemove) {
		if (!head)
			return;
		if (head == toRemove)
			removeFront(head);
		else {
			Node* tmp = head;
			while (tmp->next != toRemove)
				tmp = tmp->next;
			tmp->next = toRemove->next;
			delete toRemove;
		}
	}
	void removeValue(Node*& head, int valToRemove) {
		if (!head)
			return;
		if (head->val == valToRemove)
			removeFront(head);
		else {
			Node* tmp = head;
			while (tmp->next->val != valToRemove && tmp->next != nullptr)
				tmp = tmp->next;
			if (tmp->next != nullptr)
				removeFront(tmp->next);
		}
	}
	void swapHead(Node*& head) {
		if (head && head->next) {
			Node* tmp = head;
			head = head->next;
			tmp->next = head->next;
			head->next = tmp;
			delete tmp;
		}
	}
	void swapHeadNode(Node*& head, Node* toSwap) {
		if (head && toSwap->next) {
			Node* tmp = toSwap->next;
			toSwap->next = head;
			Node* tmp2 = head->next;
			head->next = tmp->next;
			tmp->next = tmp2;
			head = tmp;
		}
	}
	void swapFirstLast(Node*& head) {
		/*Node* tmp = head;
		while (tmp->next->next)
			tmp = tmp->next;
		tmp->next->next = head->next;
		head->next = tmp->next;
		tmp->next = head;
		head = head->next;*/
	}
	void swapNodeNext(Node*& head, Node* toSwap) {
		if (head && head->next && toSwap == nullptr) {
			swapHead(head);
			return;
		}
		if (toSwap && toSwap->next && toSwap->next->next) {
			Node* tmp = toSwap->next;
			toSwap->next = tmp->next;
			tmp->next = toSwap->next->next;
			toSwap->next->next = tmp;
		}

	}
	void swap(Node*& node1, Node*& node2) {
		if (node1 && node2->next) {
			if (node1->next == node2) {
				Node* tmp = node2->next;
				node2->next = node2->next->next;
				tmp->next = node2;
				node1->next = tmp;
			}
			else {
				Node* tmp = node1->next;
				Node* tmp2 = node2->next->next;
				node2->next->next = node1->next->next;
				node1->next = node2->next;
				node2->next = tmp;
				tmp->next = tmp2;
			}
		}
	}
	void reverse(Node*& head) {
		Node* prev = nullptr;
		Node* tmpHead = head;

		while (tmpHead){
			Node* tmp = tmpHead->next;
			tmpHead->next = prev;
			prev = tmpHead;
			tmpHead = tmp;
		}
		head = prev;
	}
	void split(Node*& head, Node*& empty1, Node*& empty2) {
		Node* tmp = head;
		while (tmp) {
			head = head->next;
			tmp->next = empty1;
			empty1 = tmp;
			tmp = head;
			if (tmp) {
				head = head->next;
				tmp->next = empty2;
				empty2 = tmp;
				tmp = head;
			}
		}
	}
	void merge(Node*& empty, Node*& ll1, Node*& ll2) {
		Node* tmp;
		addFront(empty, 0);
		tmp = empty;

		while (ll1 && ll2) {
			if (ll1->val > ll2->val) {
				tmp->next = ll2;
				ll2 = ll2->next;
			}
			else {
				tmp->next = ll1;
				ll1 = ll1->next;
			}
			tmp = tmp->next;
		}
		while (ll1) {
			tmp->next = ll1;
			ll1 = ll1->next;
			tmp = tmp->next;
		}
		while (ll2) {
			tmp->next = ll2;
			ll2 = ll2->next;
			tmp = tmp->next;
		}

		removeFront(empty);
	}

	Node* findElement(Node* head, int key) {
		if (!head)
			return nullptr;

		Node* tmp = head;
		while (tmp) {
			if (tmp->val == key)
				return tmp;
			else
				tmp = tmp->next;
		}
		delete tmp;		
	}
	Node* findIndex(Node* head, int id) {
		if (!head)
			return nullptr;
		
		Node* p = head;
		int index = 0;
		while (index != id) {
			p = p->next;
			index++;
		}
		return p;
	}
}
