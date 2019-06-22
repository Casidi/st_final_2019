#include <iostream>
#include <string>
#include <exception>
using namespace std;
template<class T>
class NSLDeque {
private:
        class Node {
        public:
                T val;
                Node* prev = NULL;
                Node* next = NULL;
        };

        Node *head;
        Node *tail;
	int mysize;
public:
        NSLDeque()
        {
                tail = new Node();
                head = new Node();
                head->prev = NULL;
                head->next = tail;
                tail->prev = head;
                tail->next = NULL;
		mysize = 0;
        }
	int size() {
		return mysize;
	}
        T& front() {
                if(mysize<=0)
                {
                    //nothing in the deque
			throw std::out_of_range("No such element");
                }
                return head->next->val;
        }
        T& back() {
                if(mysize<=0)
                {
                    //nothing in the deque
			throw std::out_of_range("No such element");
                }
                return tail->prev->val;
        }
        void push_front(T newElement) {
                Node* newNode = new Node();
                newNode->val = newElement;
                newNode->next = head->next;
                newNode->prev = head;

                head->next->prev = newNode;
                head->next = newNode;
		mysize++;
        }
        void push_back(T newElement) {
                Node* newNode = new Node();
                newNode->val = newElement;
                newNode->next = tail;
                newNode->prev = tail->prev;

                tail->prev->next = newNode;
                tail->prev = newNode;
		mysize++;
        }
        void pop_front() {
                Node* ret = head->next;
                if(ret->next == NULL)
                {
                    //nothing in the deque
			throw std::out_of_range("No such element");
                }
                head->next = ret->next;
                ret->next->prev = head;
                T retVal = ret->val;
                delete ret;
		mysize--;
        }

        void pop_back() {
                Node* ret = tail->prev;
                if(ret->prev == NULL)
                {
                    //nothing in the deque
			throw std::out_of_range("No such element");
                }
                tail->prev = ret->prev;
                ret->prev->next = tail;
                T retVal = ret->val;
                delete ret;
		mysize--;
        }
        void insert(int pos, int value) {
            Node *iter = head;
            Node *newNode = new Node();
            newNode->val = value;
	    if (pos < 0 || pos > mysize)
			throw std::out_of_range("Can not insert in taht position");
            for (int i=0;i<pos;i++){
                iter = iter->next;
	    }
            newNode->next = iter->next; 
            newNode->prev = iter;
            iter->next->prev = newNode;
            iter->next = newNode;
	    mysize++;
        }
	T& operator[](int index)
	{
		if(index < 0 || index >= mysize)
			throw std::out_of_range("No Such element");
		Node *iter = head->next;
		Node *riter = tail->prev;
		if (index <= mysize/2)
		{
			for(int i =0;i < index; i++)
			{
				iter = iter->next;
			}
			return iter->val;
		}
		else
		{
			for(int i =0;i < mysize - index -1; i++)
			{
				riter = riter->prev;
			}
			return riter->val;
		}

	}
        void erase(int pos) 
        {
            Node *iter = head->next;
	    if (pos < 0 || pos >= mysize)
			throw std::out_of_range("No such element");
            for (int i=0;i<pos;i++)
	    {
		iter = iter->next;
	    }
            //itrt is back no element in deque 
            
            iter->next->prev = iter->prev;
            iter->prev->next = iter->next;
	    mysize--;
            
            //Node *iter_next = iter->next;
            delete iter;
            
            //return (iter_next->next) ? 0 : -1;
        }
        
        bool empty() {
		return mysize == 0;
                //return head->next->next == NULL;
        }
        
        void clear() {
                while (!empty())
                        pop_front();
        }

        


};
/*
int main()
{
  NSLDeque<int> te;
  for(int i=0;i<3;i++)
    te.push_front(i);
     
  te.insert(0,5);
  te.insert(2,5);
  te.erase(0);
  while(!te.empty())
    {
        cout<<(te.front())<<endl;
        te.pop_front();
    }  
for(int i=0;i<3;i++)
    te.push_back(i);
     

  while(!te.empty())
    {
        cout<<(te.back())<<endl;
        te.pop_front();
    }  
}*/

