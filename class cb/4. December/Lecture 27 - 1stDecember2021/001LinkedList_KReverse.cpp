#include<iostream>

using namespace std;

class node {
public:
    int data;
    node* next;

    node(int data) {
        this->data = data;
        this->next = NULL;
    }

};

void insertAtHead(node*& head, int data) {
    // 1. create a new node
    node* n = new node(data); // invokes the parameterised constuctor
                              // of the node class and constructs a
                              // node on the heap memory

    // 2. assign the address of the head node to the
    // next field of the newly created node

    n->next = head; // (*n).next = head;

    // 3. make the newly created node as the new head of the linked list
    // assign to the head pointer the address of the newly created node

    head = n;

}

void printLinkedList(node* head) {
    while(head != NULL) {
        cout << head->data;
        head = head->next;
        if(head != NULL) cout << "->";
    }
    cout << endl;
}

node* kReverse(node* head, int k) {

    // if(head == NULL) {
    //     // the given linked list is empty
    //     return head;
    // }

    if(!head) {
        return head;
    }

    // 1. Reverse the first k nodes of the linked

    // int i = 0;
    int i = k;
    node* cur = head;
    node* prev = NULL;

    // while(cur != NULL && i < k) {
    while(cur && i--) {
        node* tmp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = tmp;
        // i++;
    }

    // 2. Ask your friend to k-Reverse the linked list composed
    // of the last n-k nodes that starts with cur node
    node* headFromMyFriend = kReverse(cur, k);
    head->next = headFromMyFriend;

    return prev;


}

int main() {

    node* head = NULL; // initially, my linked list is empty

    insertAtHead(head, 6);
    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);

    printLinkedList(head);

    int k = 3;

    head = kReverse(head, k);

    printLinkedList(head);

    return 0;
}

//////////////////////////
///////////////srf 1 bar hi aye repeated vla
#include<iostream>

using namespace std;

class node {
public:
    int data;
    node* next;

    node(int data) {
        this->data = data;
        this->next = NULL;
    }

};

void insertAtHead(node*& head, int data) {
    // 1. create a new node
    node* n = new node(data); // invokes the parameterised constuctor
                              // of the node class and constructs a
                              // node on the heap memory

    // 2. assign the address of the head node to the
    // next field of the newly created node

    n->next = head; // (*n).next = head;

    // 3. make the newly created node as the new head of the linked list
    // assign to the head pointer the address of the newly created node

    head = n;

}

void printLinkedList(node* head) {
    while(head != NULL) {
        cout << head->data;
        head = head->next;
        if(head != NULL) cout << "->";
    }
    cout << endl;
}


node* removeDuplicates(node* head) {
    if(!head) {
        // linked list is empty
        return head;
    }

    node* tail= head;
    node* cur = head->next;
    while(cur != NULL) { // or while(cur) {
        if(cur->data != tail->data) {
            // cur node contains data that we are seeing for
            // the first time therefore track the cur node
            tail->next = cur;
            tail = cur;
        }
        cur = cur->next;
    }
    // ensure the next field of tail node of the final
    // ans. contains NULL address
    tail->next = NULL;//imp nhi to repeated rh jyge
    return head;
}

int main() {

    node* head = NULL; // initially, my linked list is empty

    insertAtHead(head, 5);
    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 3);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 2);
    insertAtHead(head, 1);

    printLinkedList(head);

    head = removeDuplicates(head);

    printLinkedList(head);

    return 0;
}
//////////////repeated puri tarah gayab

#include<iostream>

using namespace std;

class node {
public:
    int data;
    node* next;

    node(int data) {
        this->data = data;
        this->next = NULL;
    }

};

void insertAtHead(node*& head, int data) {
    // 1. create a new node
    node* n = new node(data); // invokes the parameterised constuctor
                              // of the node class and constructs a
                              // node on the heap memory

    // 2. assign the address of the head node to the
    // next field of the newly created node

    n->next = head; // (*n).next = head;

    // 3. make the newly created node as the new head of the linked list
    // assign to the head pointer the address of the newly created node

    head = n;

}

void printLinkedList(node* head) {
    while(head != NULL) {
        cout << head->data;
        head = head->next;
        if(head != NULL) cout << "->";
    }
    cout << endl;
}


node* removeDuplicates(node* head) {
    // base case
    if(!head || !head->next) {
        // a linked list which is either empty or contains a single
        // node doesn't have any duplicates so you don't have to
        // do anything.
        return head;
    }

    // recursive case

    if(head->data != head->next->data) {
        // the head of the linked list is not a duplicate node
        // therefore it will be the head of the final ans.

        // ask your friend to remove all the duplicate nodes
        // from the linked list that starts from head->next
        head->next = removeDuplicates(head->next);
        return head;
    } else {
        // the head of the linked list is a duplicate node therefore
        // skip over all the nodes that contain the data that matches
        // the data of the head node
        while(head->next && head->data == head->next->data) {
            head = head->next;
        }
        // ask your friend to remove all the duplicate nodes
        // from the linked list that starts from head->next
        return removeDuplicates(head->next);
    }


}

int main() {

    node* head = NULL; // initially, my linked list is empty

    insertAtHead(head, 6);
    insertAtHead(head, 5);
    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 3);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 2);
    insertAtHead(head, 1);

    printLinkedList(head);

    head = removeDuplicates(head);

    printLinkedList(head);

    return 0;
}

///add 2 nos

#include<iostream>

using namespace std;

class node {
public:
    int data;
    node* next;

    node(int data) {
        this->data = data;
        this->next = NULL;
    }

};

void insertAtHead(node*& head, int data) {
    // 1. create a new node
    node* n = new node(data); // invokes the parameterised constuctor
                              // of the node class and constructs a
                              // node on the heap memory

    // 2. assign the address of the head node to the
    // next field of the newly created node

    n->next = head; // (*n).next = head;

    // 3. make the newly created node as the new head of the linked list
    // assign to the head pointer the address of the newly created node

    head = n;

}

void printLinkedList(node* head) {
    while(head != NULL) {
        cout << head->data;
        head = head->next;
        if(head != NULL) cout << "->";
    }
    cout << endl;
}

node* add(node* head1, node* head2) {
    node* head = NULL;
    int c_val = 0;
    while(head1 != NULL && head2 != NULL) {

        int sum = head1->data + head2->data + c_val;
        c_val = sum/10;

        node* n = new node(sum%10);
        n->next = head;
        head = n;

        head1 = head1->next;
        head2 = head2->next;
    }

    while(head1 != NULL) {
        // insert the remaining digits of the first no. to
        // the final answer

        int sum = head1->data + c_val;
        c_val = sum/10;

        node* n = new node(sum%10);
        n->next = head;
        head = n;

        head1 = head1->next;

    }

    while(head2 != NULL) {
        // insert the remaining digits of the second no. to
        // the final answer

        int sum = head2->data + c_val;
        c_val = sum/10;

        node* n = new node(sum%10);
        n->next = head;
        head = n;

        head2 = head2->next;

    }


    if(c_val) {
        node* n = new node(c_val);
        n->next = head;
        head = n;
    }

    return head;

}

node* addCompact(node* head1, node* head2) {
    node* head = NULL;
    int c_val = 0;
    while(head1 || head2 || c_val) {

        int d1 = head1 ? head1->data : 0;
        int d2 = head2 ? head2->data : 0;

        int sum = d1 + d2 + c_val;
        c_val = sum/10;

        node* n = new node(sum%10);
        n->next = head;
        head = n;

        head1 = head1 ? head1->next : NULL;
        head2 = head2 ? head2->next : NULL;
    }

    return head;

}


int main() {

    node* head1 = NULL; // initially, my linked list is empty

    insertAtHead(head1, 9);
    insertAtHead(head1, 9);
    insertAtHead(head1, 7);
    insertAtHead(head1, 3);

    printLinkedList(head1);

    node* head2 = NULL;

    insertAtHead(head2, 4);
    insertAtHead(head2, 5);
    insertAtHead(head2, 6);

    printLinkedList(head2);

    node* head = add(head1, head2);

    printLinkedList(head);

    head = addCompact(head1, head2);

    printLinkedList(head);

    return 0;
}
//krotate
#include<iostream>

using namespace std;

class node {
public:
    int data;
    node* next;

    node(int data) {
        this->data = data;
        this->next = NULL;
    }

};

void insertAtHead(node*& head, int data) {
    // 1. create a new node
    node* n = new node(data); // invokes the parameterised constuctor
                              // of the node class and constructs a
                              // node on the heap memory

    // 2. assign the address of the head node to the
    // next field of the newly created node

    n->next = head; // (*n).next = head;

    // 3. make the newly created node as the new head of the linked list
    // assign to the head pointer the address of the newly created node

    head = n;

}

void printLinkedList(node* head) {
    while(head != NULL) {
        cout << head->data;
        head = head->next;
        if(head != NULL) cout << "->";
    }
    cout << endl;
}

node* kRotate(node* head, int k) {

    // 1. connect the tail of the linked list
    //    with the head to form a loop

    node* tail = head;
    int n = 1; // to keep track of the length of the linked list
    while(tail->next != NULL) {
        tail = tail->next;
        n++;
    }
    tail->next = head;

    // 2. iterate over the linked list n-(k%n)-1 times
    //    from the head to reach the newTail

    node* newTail = head;
    for(int i=0; i<n-(k%n)-1; i++) {
        newTail = newTail->next;
    }

    node* newHead = newTail->next;

    // 3. break the cycle or the loop by updating the next
    //    field of the newTail

    newTail->next = NULL;

    return newHead;
}


int main() {

    node* head = NULL; // initially, my linked list is empty

    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);

    printLinkedList(head);

    int k = 7;

    head = kRotate(head, k);

    printLinkedList(head);

    return 0;
}

/*

	Forward List - STL implementation of singly linked list

	How to create a forward_list ?
		> use empty container constructor (default constructor)
		> use fill constructor
		> use range constructor
		> use copy constructor
		> use initialiser list (C++11)
	How to add elements to a forward_list ?
	    > use forward_list::push_front to add element at head (constant time operator)
	How to remove elements from a forward_list ?
	    > use forward_list::pop_front to remove element from the head (constant time operation)
	    > use forward_list::clear to remove all the elements from a forward_list
	How to check size of a forward_list ?
	    > forward_list is the only standard container to deliberately lack a size member function
	      for efficiency considerations. To obtain the size of a forward_list object, you can use
	      the distance algorithm with its begin and end, which is an operation that takes linear time.
		> use forward_list::max_size to know maximum number of elements that can added in a forward_list
	How to check if a forward_list is empty ?
	    > use forward_list::empty or check if forward_list size is 0
	How to access element at the front?
	    > use forward_list::front
	How to iterate over elements in a forward_list ?
	    > use an iterator

*/

#include<iostream>
#include<forward_list>
#include<iterator>

using namespace std;

int main() {

	// create an empty forward_list

	forward_list<int> l1;

	cout << "size = " << distance(l1.begin(), l1.end()) << endl;

	// insert data at the head

	l1.push_front(50);
	l1.push_front(40);
	l1.push_front(30);
	l1.push_front(20);
	l1.push_front(10);

	cout << "size = " << distance(l1.begin(), l1.end()) << endl;

	// access the element at the head
	cout << "head = " << l1.front() << endl;

	// iterate over the foward_list using iterator

	for(auto it = l1.begin(), end = l1.end(); it != end; it++) {
		cout << *it << " ";
	}

	cout << endl;

	// iterate over the forward list using for-each loop

	for(int x : l1) {
		cout << x << " ";
	}

	cout << endl;

	// remove data at the head

	l1.pop_front();
	l1.pop_front();

	cout << "size = " << distance(l1.begin(), l1.end()) << endl;

	// iterate over the foward_list using iterator

	for(auto it = l1.begin(), end = l1.end(); it != end; it++) {
		cout << *it << " ";
	}

	cout << endl;

	// clear forward_list

	l1.clear();
	cout << "size = " << distance(l1.begin(), l1.end()) << endl;

	// check if list is empty
	cout << "is list empty ? " << l1.empty() << endl;

	// create a list using fill constructor

	forward_list<int> l2(3, 100); // creates a forward_list of size 3 all with values 1

	cout << "size = " << distance(l2.begin(), l2.end()) << endl;

	// iterate over the foward_list using iterator

	for(auto it = l2.begin(), end = l2.end(); it != end; it++) {
		cout << *it << " ";
	}

	cout << endl;

	forward_list<int> l3(4); // creates a forward_list of size 4

	cout << "size = " << distance(l3.begin(), l3.end()) << endl;

	// iterate over the foward_list using iterator

	for(auto it = l3.begin(), end = l3.end(); it != end; it++) {
		cout << *it << " ";
	}

	cout << endl;

	// create a list using initializer list
	forward_list<int> l4 = {1, 2, 3, 4, 5};
	cout << "size = " << distance(l4.begin(), l4.end()) << endl;

	// iterate over the foward_list using iterator

	for(auto it = l4.begin(), end = l4.end(); it != end; it++) {
		cout << *it << " ";
	}

	cout << endl;

	return 0;
}
//////////////////////////

#include<iostream>

using namespace std;

template <typename T>
class node {
public:
    T data;
    node<T>* next;

    node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

template <typename T>
class forward_list {
    node<T>* head;
    int count;

public:

    forward_list() {
        head = NULL;
        count = 0;
    }

    void push_front(T data) {
        node<T>* n = new node<T>(data);
        n->next = head;
        head = n;
        count++;
    }

    void pop_front() {
        if(!head) return;
        node<T>* tmp = head;
        head = head->next;
        delete tmp;
        count--;
    }

    T front() {
        return head->data;
    }

    int size() {
        return count;
    }

    bool empty() {
        return head == NULL; // or count == 0
    }

    void traverse() {
        node<T>* tmp = head;
        while(tmp != NULL) {
            cout << tmp->data;
            tmp = tmp->next;
            if(tmp != NULL) cout << "->";
        }
        cout << endl;
    }

};

int main() {

    forward_list<char> l;

    l.push_front('a');
    l.push_front('b');
    l.push_front('c');
    l.push_front('d');
    l.push_front('e');

    cout << "size : " << l.size() << endl;

    l.traverse();

    l.pop_front();

    cout << "size : " << l.size() << endl;

    l.traverse();

    l.empty() ? cout << "true" << endl : cout << "false" << endl;

    cout << "head->data = " << l.front() << endl;

    return 0;
}
/*

Implementation of the stack data structure using an array.

*/

#include<iostream>

using namespace std;

template <typename T>
class stack {
	T* arr;
	int t; // stores the index of the last item
		   // pushed onto the stack
	int n; // stores the maximum capacity of the
		   // stack data structure

public:

	stack(int n) {
		arr = new T[n];
		t = -1;
		this->n = n;
	}

	void push(T data) {
		if(t == n-1) {
			// stack is already full
			return;
		}
		t = t+1;
		arr[t] = data;
	}

	void pop() {
		if(t == -1) {
			// stack is empty
			return;
		}
		t = t-1;
	}

	T top() {
		return arr[t];
	}

	bool empty() {
		return t == -1;
	}

	int size() {
		return t+1;
	}

};

int main() {

	stack<int> s(10);

	s.push(50);
	s.push(40);
	s.push(30);
	s.push(20);
	s.push(10);

	cout << "size : " << s.size() << endl;
	cout << "top : " << s.top() << endl;

	s.pop();

	cout << "size : " << s.size() << endl;
	cout << "top : " << s.top() << endl;

	s.pop();

	cout << "size : " << s.size() << endl;
	cout << "top : " << s.top() << endl;

	s.pop();

	cout << "size : " << s.size() << endl;
	cout << "top : " << s.top() << endl;

	s.pop();

	cout << "size : " << s.size() << endl;
	cout << "top : " << s.top() << endl;

	s.pop();

	s.empty() ? cout << "stack is empty!" << endl : cout << "stack is non-empty!" << endl;


	return 0;
}
/*

Implementation of the stack data structure using the vector container.

*/

#include<iostream>
#include<vector>

using namespace std;

template <typename T>
class stack {
	vector<T> v;

public:

	void push(T data) {
		if(size() == v.max_size()) {
			// stack is full
		}
		v.push_back(data);
	}

	void pop() {
		if(empty()) {
			// stack is empty
			return;
		}
		v.pop_back();
	}

	T top() {
		return v.back(); // v[v.size()-1];
	}

	int size() {
		return v.size();
	}

	bool empty() {
		return v.empty();
	}

};

int main() {

	stack<int> s;

	s.push(50);
	s.push(40);
	s.push(30);
	s.push(20);
	s.push(10);

	cout << "size : " << s.size() << endl;
	cout << "top : " << s.top() << endl;

	s.pop();

	cout << "size : " << s.size() << endl;
	cout << "top : " << s.top() << endl;

	s.pop();

	cout << "size : " << s.size() << endl;
	cout << "top : " << s.top() << endl;

	s.pop();

	cout << "size : " << s.size() << endl;
	cout << "top : " << s.top() << endl;

	s.pop();

	cout << "size : " << s.size() << endl;
	cout << "top : " << s.top() << endl;

	s.pop();

	s.empty() ? cout << "stack is empty!" << endl : cout << "stack is non-empty!" << endl;

	return 0;
}
/*

Implementation of the stack data structure using the linked list data structure.

*/

#include<iostream>

using namespace std;

template <typename T>
class node {
public:
    T data;
    node<T>* next;

    node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

template <typename T>
class forward_list {
    node<T>* head;
    int count;

public:

    forward_list() {
        head = NULL;
        count = 0;
    }

    void push_front(T data) {
        node<T>* n = new node<T>(data);
        n->next = head;
        head = n;
        count++;
    }

    void pop_front() {
        if(!head) return;
        node<T>* tmp = head;
        head = head->next;
        delete tmp;
        count--;
    }

    T front() {
        return head->data;
    }

    int size() {
        return count;
    }

    bool empty() {
        return head == NULL;
    }
};

template <typename T>
class stack {
    forward_list<T> l;
public:

    void push(T data) {
        l.push_front(data);
    }

    void pop() {
        if(empty()) {
            // stack is empty
            return;
        }
        l.pop_front();
    }

    bool empty() {
        return l.empty();
    }

    int size() {
        return l.size();
    }

    T top() {
        return l.front();
    }

};


int main() {

    stack<int> s;

    s.push(50);
    s.push(40);
    s.push(30);
    s.push(20);
    s.push(10);

    cout << "size : " << s.size() << endl;
    cout << "top : " << s.top() << endl;

    s.pop();

    cout << "size : " << s.size() << endl;
    cout << "top : " << s.top() << endl;

    s.pop();

    cout << "size : " << s.size() << endl;
    cout << "top : " << s.top() << endl;

    s.pop();

    cout << "size : " << s.size() << endl;
    cout << "top : " << s.top() << endl;

    s.pop();

    cout << "size : " << s.size() << endl;
    cout << "top : " << s.top() << endl;

    s.pop();

    s.empty() ? cout << "stack is empty!" << endl : cout << "stack is non-empty!" << endl;


	return 0;
}

/*

C++ STL implementation of the stack data structure

*/

#include<iostream>
#include<stack>

using namespace std;

int main() {

	stack<int> s;

    s.push(50);
    s.push(40);
    s.push(30);
    s.push(20);
    s.push(10);

    cout << "size : " << s.size() << endl;
    cout << "top : " << s.top() << endl;

    s.pop();

    cout << "size : " << s.size() << endl;
    cout << "top : " << s.top() << endl;

    s.pop();

    cout << "size : " << s.size() << endl;
    cout << "top : " << s.top() << endl;

    s.pop();

    cout << "size : " << s.size() << endl;
    cout << "top : " << s.top() << endl;

    s.pop();

    cout << "size : " << s.size() << endl;
    cout << "top : " << s.top() << endl;

    s.pop();

    s.empty() ? cout << "stack is empty!" << endl : cout << "stack is non-empty!" << endl;

    return 0;

}
/*

Given a stack of integers and an integer element 'x', write a program to
insert 'x' at the bottom of the stack.

*/

#include<iostream>
#include<stack>

using namespace std;

void insertAtBottom(stack<int>& s, int x) {

	// base case
	if(s.empty()) {
		s.push(x);
		return;
	}

	// recursive case

	// 1. remove the element at the top of the stack and store it
	int y = s.top();
	s.pop();

	// 2. insert x at the bottom of the resulting stack -- ask your friend
	insertAtBottom(s, x);

	// 3. push the item your removed initally from the stack top back onto the stack
	s.push(y);

}

void print(stack<int> s) {
	while(!s.empty()) {
		cout << s.top() << endl;
		s.pop();
	}
	cout << endl;
}

int main() {

	stack<int> s;

	s.push(50);
    s.push(40);
    s.push(30);
    s.push(20);
    s.push(10);

    int x = 60;

    print(s);

    insertAtBottom(s, x);

    print(s);

	return 0;
}
/*

Given a stack of integers, write a program to reverse the stack without
use of any supplementary data structure.

*/
#include<iostream>
#include<stack>

using namespace std;

void insertAtBottom(stack<int>& s, int x) {

	// base case
	if(s.empty()) {
		s.push(x);
		return;
	}

	// recursive case

	// 1. remove the element at the top of the stack and store it
	int y = s.top();
	s.pop();

	// 2. insert x at the bottom of the resulting stack -- ask your friend
	insertAtBottom(s, x);

	// 3. push the item your removed initally from the stack top back onto the stack
	s.push(y);

}

void reverse(stack<int>& s) {

	// base case
	if(s.empty()) {
		return;
	}

	// recursive case

	// 1. remove the element at the top of the stack and store it
	int x = s.top();
	s.pop();

	// 2. reverse the resulting stack -- ask your friend
	reverse(s);

	// 3. insert the item you've popped initially at the
	// bottom of the stack
	insertAtBottom(s, x);

}

void print(stack<int> s) {
	while(!s.empty()) {
		cout << s.top() << endl;
		s.pop();
	}
	cout << endl;
}

int main() {

	stack<int> s;

	s.push(50);
    s.push(40);
    s.push(30);
    s.push(20);
    s.push(10);

    print(s);

    reverse(s);

    print(s);

	return 0;
}

/*

Implementation of queues using arrays.

*/

#include<iostream>

using namespace std;

template <typename T>
class queue {
	T* arr;
	int f; // to store the idx from where last item was deleted
	int r; // to store the idx at which the last item was inserted
	int c; // to store number of items inside the queue
	int m; // to store the queue capacity

public:

	queue(int n) {
		m = n;
		arr = new T[m];
		f = r = -1;
		c = 0;
	}

	void push(T data) {
		if(r+1 == m) { // or r == m-1
			// queue is already full
			return;
		}
		r = r+1;
		arr[r] = data;
		c++;
	}

	void pop() {
		if(f == r) {
			// queue is empty
			return;
		}
		f = f+1;
		c--;
	}

	bool empty() {
		return f == r;
	}

	int size() {
		return c; // or r-f
	}

	T front() {
		return arr[f+1];
	}
};

int main() {

	queue<int> q(5);

	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);
	q.push(50);

	cout << "size : " << q.size() << endl;
	cout << "front : " << q.front() << endl;

	q.pop();

	cout << "size : " << q.size() << endl;
	cout << "front : " << q.front() << endl;

	q.pop();

	cout << "size : " << q.size() << endl;
	cout << "front : " << q.front() << endl;

	q.pop();

	cout << "size : " << q.size() << endl;
	cout << "front : " << q.front() << endl;

	q.pop();

	cout << "size : " << q.size() << endl;
	cout << "front : " << q.front() << endl;

	q.pop();

	q.empty() ? cout << "queue is empty!" << endl : cout << "queue is non-empty!" << endl;

	return 0;
}

/*

Implementation of the circurlar queues using arrays.

*/


/*

Implementation of queues using arrays.

*/

#include<iostream>

using namespace std;

template <typename T>
class queue {
	T* arr;
	int f; // to store the idx from where last item was deleted
	int r; // to store the idx at which the last item was inserted
	int c; // to store number of items inside the queue
	int m; // to store the queue capacity

public:

	queue(int n) {
		m = n+1;
		arr = new T[m];
		f = r = 0;
		c = 0;
	}

	void push(T data) {
		if((r+1)%m == f) {
			// queue is already full
			return;
		}
		r = (r+1)%m;
		arr[r] = data;
		c++;
	}

	void pop() {
		if(f == r) {
			// queue is empty
			return;
		}
		f = (f+1)%m;
		c--;
	}

	bool empty() {
		return f == r;
	}

	int size() {
		return c;
	}

	T front() {
		return arr[(f+1)%m];
	}
};

int main() {

	queue<int> q(3);

	q.push(10);
	q.push(20);
	q.push(30);

	cout << "size : " << q.size() << endl;
	cout << "front : " << q.front() << endl;

	q.pop();
	q.pop();

	cout << "size : " << q.size() << endl;
	cout << "front : " << q.front() << endl;

	q.push(40);
	q.push(50);

	cout << "size : " << q.size() << endl;
	cout << "front : " << q.front() << endl;

	q.pop();

	cout << "size : " << q.size() << endl;
	cout << "front : " << q.front() << endl;

	q.pop();

	cout << "size : " << q.size() << endl;
	cout << "front : " << q.front() << endl;


	return 0;
}

/*

Implementation of the queue data structure using the linked list data structure.

*/

#include<iostream>
#include<list>

using namespace std;

template <typename T>
class queue {
	list<T> l;

public:

	void push(T data) {
		l.push_back(data); // or l.push_front(data);
	}

	void pop() {
		l.pop_front(); // or l.pop_back();
	}

	bool empty() {
		return l.empty();
	}

	int size() {
		return l.size();
	}

	T front() {
		return l.front(); // or l.back();
	}

};

int main() {

	queue<int> q;

	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);
	q.push(50);

	cout << "size : " << q.size() << endl;
	cout << "front : " << q.front() << endl;

	q.pop();

	cout << "size : " << q.size() << endl;
	cout << "front : " << q.front() << endl;

	q.pop();

	cout << "size : " << q.size() << endl;
	cout << "front : " << q.front() << endl;

	q.pop();

	cout << "size : " << q.size() << endl;
	cout << "front : " << q.front() << endl;

	q.pop();

	cout << "size : " << q.size() << endl;
	cout << "front : " << q.front() << endl;

	q.pop();

	q.empty() ? cout << "queue is empty!" << endl : cout << "queue is non-empty!" << endl;


	return 0;
}


/*

C++ STL implementation of the queue data structure

*/

#include<iostream>
#include<queue>

using namespace std;

int main() {

	queue<int> q;

	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);
	q.push(50);

	cout << "size : " << q.size() << endl;
	cout << "front : " << q.front() << endl;

	q.pop();

	cout << "size : " << q.size() << endl;
	cout << "front : " << q.front() << endl;

	q.pop();

	cout << "size : " << q.size() << endl;
	cout << "front : " << q.front() << endl;

	q.pop();

	cout << "size : " << q.size() << endl;
	cout << "front : " << q.front() << endl;

	q.pop();

	cout << "size : " << q.size() << endl;
	cout << "front : " << q.front() << endl;

	q.pop();

	q.empty() ? cout << "queue is empty!" << endl : cout << "queue is non-empty!" << endl;

	return 0;
}
/*

Implementation of the stack using two queues.

*/

#include<iostream>
#include<queue>

using namespace std;

template <typename T>
class stack {
	queue<T> q1;
	queue<T> q2;

public:

	void push(T data) {
		if(q1.empty() && q2.empty()) {
			q1.push(data); // or q2.push(data)
		} else if(q1.empty() && !q2.empty()) {
			q2.push(data);
		} else {
			q1.push(data);
		}
	}

	void pop() {
		if(q1.empty() && q2.empty()) {
			// stack is empty
		} else if(q1.empty() && !q2.empty()) {
			// transfer n-1 elements from q2 to q1
			while(q2.size() > 1) {
				q1.push(q2.front());
				q2.pop();
			}
			// pop stack top i.e. pop the nth element from q2
			q2.pop();
		} else {
			// transfer n-1 elements from q1 to q2
			while(q1.size() > 1) {
				q2.push(q1.front());
				q1.pop();
			}
			// pop stack top i.e. pop the nth element from q1
			q1.pop();
		}
	}

	T top() {
		if(q1.empty() && !q2.empty()) {
			// transfer n-1 elements from q2 to q1
			while(q2.size() > 1) {
				q1.push(q2.front());
				q2.pop();
			}
			// save & pop the nth element from q2 and transfer it to q1
			T ans = q2.front();
			q2.pop();
			q1.push(ans);
			return ans;
		} else {
			// transfer n-1 elements from q1 to q2
			while(q1.size() > 1) {
				q2.push(q1.front());
				q1.pop();
			}
			// save & pop the nth element from q1 and transfer it to q2
			T ans = q1.front();
			q1.pop();
			q2.push(ans);
			return ans;
		}
	}

	bool empty() {
		return q1.empty() && q2.empty();
	}

	int size() {
		return max(q1.size(), q2.size());
	}
};

int main() {

	stack<int> s;

	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);

	cout << "size = " << s.size() << endl;

	while(!s.empty()) {
		cout << s.top() << endl;
		s.pop();
	}

	cout << endl;

	s.empty() ? cout << "true" << endl : cout << "false" << endl;

	return 0;
}
/*

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the
input string is valid.

An input string is valid if:
	Open brackets must be closed by the same type of brackets.
	Open brackets must be closed in the correct order.

Examples

	Input: s = "{[()]}"
	Output: true

	Input: s = "{[]()}"
	Output: true

	Input: s = "([)]"
	Output: false

*/

#include<iostream>
#include<stack>

using namespace std;

// bool isValid(string str) {
//  	stack<char> s;
//  	for(char ch : str) {
//  		if(ch == '{' || ch == '(' || ch == '[') {
//  			s.push(ch);
//  		} else {
//  			// ch represents a closing bracket
//  			if(ch == '}') {
//  				if(!s.empty() && s.top() == '{') {
//  					s.pop();
//  				} else {
//  					return false;
//  				}
//  			} else if(ch == ')') {
//  				if(!s.empty() && s.top() == '(') {
//  					s.pop();
//  				} else {
//  					return false;
//  				}
//  			} else {
//  				if(!s.empty() && s.top() == '[') {
//  					s.pop();
//  				} else {
//  					return false;
//  				}
//  			}
//  		}
//  	}

//  	return s.empty();

// }

bool isValid(string str) {
 	stack<char> s;
 	for(char ch : str) {
 		switch(ch) {
 			case '{' :
 			case '[' :
 			case '(' : s.push(ch); break;
 			case '}' : if(!s.empty() && s.top() == '{') s.pop(); else return false; break;
 			case ']' : if(!s.empty() && s.top() == '[') s.pop(); else return false; break;
 			case ')' : if(!s.empty() && s.top() == '(') s.pop(); else return false; break;
 		}
 	}

 	return s.empty();

}

int main() {

	string str = "{[]()}{{}}";

	isValid(str) ? cout << "balanced" << endl :
				   cout << "unbalanced" << endl;

	return 0;
}
#include<iostream>

using namespace std;

int main() {

	string str = "10";

	switch(str) {
		case "10" : cout << "10" << endl; break;
		case "20" : cout << "20" << endl; break;
		default : cout << "no cases matched" << endl; break;
	}
}
