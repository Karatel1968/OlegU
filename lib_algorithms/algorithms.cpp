#include "../lib_list/TList.h"

bool isCircle_turtle(TList<int> list) {
	if (list.isEmpty()) {
		throw std::logic_error("������ ����");
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
		throw std::logic_error("������ ����");
	}

	TNode<int>* cur = list.getHead();
	TNode<int>* next = nullptr;
	TNode<int>* prev = nullptr;

	while (cur != list.getHead()) {
		
		cur = cur->next();
		

	}
}