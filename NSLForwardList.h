
template<class T>
class NSLForwardList {
public:
	T& front() {
		return head.next->val;
	}

	void pushFront(T newElement) {
		Node* newNode = new Node();
		newNode->val = newElement;
		newNode->next = head.next;
		head.next = newNode;
	}

	T popFront() {
		Node* old = head.next;
		head.next = old->next;
		T oldVal = old->val;
		delete old;
		return oldVal;
	}

	void clear() {
		while(!empty())
			popFront();
	}

	bool empty() {
		return head.next == NULL;
	}

private:
	class Node {
	public:
		T val;
		Node* next = NULL;
	};

	Node head;
};
