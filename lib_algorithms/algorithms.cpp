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

	while (cur != nullptr) {
		next = cur->next();
			 
		cur->setNext(prev);

		if (next == list.getHead()) {
			return true;
		}

		prev = cur;
		cur = next;

	}

	return false;
}

void listMerge(const TList<int>& list1, const TList<int>& list2) {

}