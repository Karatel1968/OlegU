#include "../lib_list/TList.h"

bool isCircle_turtle(TList<int> list) {
	if (list.isEmpty()) {
		throw std::logic_error("Список пуст");
	}

	TNode<int>* fast = list.getHead();
	TNode<int>* slow = list.getHead();

	while (fast != nullptr) {
		slow = slow->next();
		fast = fast->next()->next();
	}

	if (slow = fast) {
		return true;
	}

	return false;
}

bool isCircle_reverse(TList<int> list) {
	if (list.isEmpty()) {
		throw std::logic_error("Список пуст");
	}

	TNode<int>* tail = list.getTail();
	TNode<int>* head = list.getHead();
	TNode<int>* cur = list.getHead();
	TNode<int>* next = nullptr;
	TNode<int>* prev = nullptr;

	while (cur != head) {
		prev = cur;
		cur = cur->next();
	}

	if (cur == tail) {
		return false;
	}

	return true;
}