#include "../lib_list/TList.h"
#include "../lib_binary_search_tree/TBinSearchTree.h"

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
	TNode<int>* cur1 = list1.getHead();
	TNode<int>* cur2 = list2.getHead();
	TList<int> list3;
	while ((cur1 != nullptr) && (cur2 != nullptr)) {
		if (cur1->value() >= cur2->value()) {
			list3.push_back(cur2->value());
			cur2 = cur2->next();
		}
		else {
			list3.push_back(cur1->value());
			cur1 = cur1->next();
		}
	}

	
		while (cur2 != nullptr) {
			list3.push_back(cur2->value());
			cur2 = cur2->next();
		}
	
	
		while (cur1 != nullptr) {
			list3.push_back(cur1->value());
			cur1 = cur1->next();
		}
	

	TNode<int>* cur = list3.getHead();
	while (cur != nullptr) {
		std::cout << cur->value() << " ";
		cur = cur->next();
	}
}

void Printree(const TBinSearchTree<int>& tree) {

}