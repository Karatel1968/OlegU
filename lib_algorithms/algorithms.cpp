#include "../lib_list/TList.h"

bool isCircle_turtle(const TList<int>& list) {
	if (list.isEmpty()) {
		throw std::logic_error("Список пуст");
	}

	TNode<int>* fast = list.getHead();
	TNode<int>* slow = list.getHead();

	while (fast->next() != nullptr && fast->next()->next() != nullptr) {
		slow = slow->next();
		fast = fast->next()->next();

		if (slow == fast) {
			return true;
		}
	}

	return false;
}

bool isCircle_reverse(const TList<int>& list) {
	if (list.isEmpty()) {
		throw std::logic_error("Список пуст");
	}

	TNode<int>* tail = list.getTail();
	TNode<int>* head = list.getHead();
	TNode<int>* cur = list.getHead();
	TNode<int>* next = nullptr;
	TNode<int>* prev = nullptr;

	while (cur != head) {
		next = cur->next();
		
		cur->setNext(prev);

		prev = cur;
		cur = next;
	}

	if (cur == tail) {
		return false;
	}

	return true;
}