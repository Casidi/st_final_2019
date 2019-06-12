#include <exception>
template<class T>
class NSLForwardList {
public:
	NSLForwardList()
	{
		head = new Node();
	}
	T& front() {
		return head->next->val;
	}

	void pushFront(T newElement) {
		Node* newNode = new Node();
		newNode->val = newElement;
		newNode->next = head->next;
		head->next = newNode;
	}

	T popFront() {
		Node* old = head->next;
		head->next = old->next;
		T oldVal = old->val;
		delete old;
		return oldVal;
	}

	void erase(int pos) {
		if(pos < 0 )
		       throw std::out_of_range("No such element");
		Node *iter = head;
		if (head->next == NULL)
			return;
		for(int i=0;i<pos;i++)
			iter = iter->next;
		Node *del = iter->next;
		iter->next = iter->next->next;
		delete del;
	}
	void clear() {
		while(!empty())
			popFront();
	}

	bool empty() {
		return head->next == NULL;
	}

private:
	class Node {
	public:
		T val;
		Node* next = NULL;
	};

	Node *head;
};
