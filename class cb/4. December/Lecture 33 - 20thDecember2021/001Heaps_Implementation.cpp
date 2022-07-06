/*

	Implementation of the heap/priority_queue data structure.

*/

#include<iostream>
#include<vector>

using namespace std;

class MaxHeap {
	vector<int> v;

	void heapify(int i) {
		int max_idx = i; // assume the root node contains the maximum value
		int left_idx = 2*i;
		if(left_idx < v.size() && v[left_idx] > v[max_idx]) {
			max_idx = left_idx;
		}

		int right_idx = 2*i + 1;
		if(right_idx < v.size() && v[right_idx] > v[max_idx]) {
			max_idx = right_idx;
		}

		if(i != max_idx) {  // base is handled here when i == max_idx
			swap(v[i], v[max_idx]);
			heapify(max_idx);
		}

		// you return from here as soon as you hit the base case
	}

public:

	MaxHeap() {
		v.push_back(-1); // to reserve the 0th index
	}

	void push(int data) {
		v.push_back(data); // this may violate the heap property
		int childIdx = v.size()-1;
		int parentIdx = childIdx/2;
		while(childIdx > 1 && v[childIdx] > v[parentIdx]) {
			swap(v[childIdx], v[parentIdx]);
			childIdx = parentIdx;
			parentIdx = childIdx/2;
		}
	}

	void pop() {
		swap(v[1], v[v.size()-1]); // heap property may be violated at the root node
		v.pop_back();
		heapify(1);
	}

	int top() {
		return v[1]; // since root node is the maximum element and assigned the index 1.
	}

	int size() {
		return v.size() - 1; // to avoid counting dummy element at the 0th index
	}

	bool empty() {
		return v.size() == 1; // heap only contains the dummy element
	}

	void print() {
		for(int i=1; i<v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << endl;
	}

};



int main() {

	MaxHeap maxHeap;

	maxHeap.push(10);
	maxHeap.push(7);
	maxHeap.push(9);
	maxHeap.push(4);
	maxHeap.push(3);
	maxHeap.push(5);
	maxHeap.push(6);
	maxHeap.push(2);
	maxHeap.push(0);
	maxHeap.push(1);

	cout << "size : " << maxHeap.size() << endl;

	maxHeap.print();

	maxHeap.push(20);

	cout << "size : " << maxHeap.size() << endl;

	maxHeap.print();

	maxHeap.pop();

	cout << "size : " << maxHeap.size() << endl;

	maxHeap.print();

	return 0;
}
/*

	STL implementation of the heap/priority_queue data structure.

*/

#include<iostream>
#include<queue>

using namespace std;

void print(priority_queue<int> maxHeap) {
	while(!maxHeap.empty()) {
		cout << maxHeap.top() << " ";
		maxHeap.pop();
	}
	cout << endl;
}

int main() {

	priority_queue<int> maxHeap;

	maxHeap.push(10);
	maxHeap.push(7);
	maxHeap.push(9);
	maxHeap.push(4);
	maxHeap.push(3);
	maxHeap.push(5);
	maxHeap.push(6);
	maxHeap.push(2);
	maxHeap.push(0);
	maxHeap.push(1);

	cout << "size : " << maxHeap.size() << endl;

	print(maxHeap);

	maxHeap.push(20);

	cout << "size : " << maxHeap.size() << endl;

	print(maxHeap);

	maxHeap.pop();

	cout << "size : " << maxHeap.size() << endl;

	print(maxHeap);

	maxHeap.pop();

	cout << "size : " << maxHeap.size() << endl;

	print(maxHeap);

	return 0;
}/*

	STL implementation of the heap/priority_queue data structure.

*/

#include<iostream>
#include<queue>

using namespace std;

void print(priority_queue<int> maxHeap) {
	while(!maxHeap.empty()) {
		cout << maxHeap.top() << " ";
		maxHeap.pop();
	}
	cout << endl;
}

int main() {

	priority_queue<int> maxHeap;

	maxHeap.push(10);
	maxHeap.push(7);
	maxHeap.push(9);
	maxHeap.push(4);
	maxHeap.push(3);
	maxHeap.push(5);
	maxHeap.push(6);
	maxHeap.push(2);
	maxHeap.push(0);
	maxHeap.push(1);

	cout << "size : " << maxHeap.size() << endl;

	print(maxHeap);

	maxHeap.push(20);

	cout << "size : " << maxHeap.size() << endl;

	print(maxHeap);

	maxHeap.pop();

	cout << "size : " << maxHeap.size() << endl;

	print(maxHeap);

	maxHeap.pop();

	cout << "size : " << maxHeap.size() << endl;

	print(maxHeap);

	return 0;
}
/*

	STL implementation of the min_heap data structure.


*/

#include<iostream>
#include<queue>

using namespace std;

void print(priority_queue<int, vector<int>, greater<int>> minHeap) {
	while(!minHeap.empty()) {
		cout << minHeap.top() << " ";
		minHeap.pop();
	}
	cout << endl;
}

int main() {

	priority_queue<int, vector<int>, greater<int>> minHeap;

	minHeap.push(10);
	minHeap.push(7);
	minHeap.push(9);
	minHeap.push(4);
	minHeap.push(3);
	minHeap.push(5);
	minHeap.push(6);
	minHeap.push(2);
	minHeap.push(1);

	cout << "size : " << minHeap.size() << endl;

	print(minHeap);

	minHeap.push(0);

	cout << "size : " << minHeap.size() << endl;

	print(minHeap);

	minHeap.pop();

	cout << "size : " << minHeap.size() << endl;

	print(minHeap);

	minHeap.pop();

	cout << "size : " << minHeap.size() << endl;

	print(minHeap);

	return 0;
}
/*

	STL implementation of the min_heap data structure with custom comparator.


*/

#include<iostream>
#include<queue>

using namespace std;

class Comparator {
public:
	bool operator()(int a, int b) { // return true when swap is needed, 'b' is the newly inserted data
		// return a < b; // in maxHeap, swap is needed when a < b
		return a > b; // in minHeap, swap is needed when a > b
	}
};

void print(priority_queue<int, vector<int>, Comparator> minHeap) {
	while(!minHeap.empty()) {
		cout << minHeap.top() << " ";
		minHeap.pop();
	}
	cout << endl;
}

int main() {

	priority_queue<int, vector<int>, Comparator> minHeap;

	minHeap.push(10);
	minHeap.push(7);
	minHeap.push(9);
	minHeap.push(4);
	minHeap.push(3);
	minHeap.push(5);
	minHeap.push(6);
	minHeap.push(2);
	minHeap.push(1);

	cout << "size : " << minHeap.size() << endl;

	print(minHeap);

	minHeap.push(0);

	cout << "size : " << minHeap.size() << endl;

	print(minHeap);

	minHeap.pop();

	cout << "size : " << minHeap.size() << endl;

	print(minHeap);

	minHeap.pop();

	cout << "size : " << minHeap.size() << endl;

	print(minHeap);

	return 0;
}
/*

	Given an array of integers, design a algorirthm to build a max_heap in linear time
	without using any extra space (in-place).

*/

#include<iostream>

using namespace std;

void heapify(int* v, int n, int i) {
		int max_idx = i; // assume the root node contains the maximum value
		int left_idx = 2*i;
		if(left_idx < n && v[left_idx] > v[max_idx]) {
			max_idx = left_idx;
		}

		int right_idx = 2*i + 1;
		if(right_idx < n && v[right_idx] > v[max_idx]) {
			max_idx = right_idx;
		}

		if(i != max_idx) {  // base is handled here when i == max_idx
			swap(v[i], v[max_idx]);
			heapify(v, n, max_idx);
		}

		// you return from here as soon as you hit the base case
	}

int main() {

	int v[] = {-1, 2, 0, 1, 4, 6, 5, 7, 3};
	int n = sizeof(v) / sizeof(int) ;

	for(int i=n/2-1; i>=1; i--) {
		heapify(v, n, i);
	}

	for(int i=1; i<n; i++) {
		cout << v[i] << " ";
	}

	cout << endl;

	return 0;
}
/*

	Given an array of integers, sort the array using heap sort algorithm.

*/

#include<iostream>

using namespace std;

void heapify(int* v, int n, int i) {
		int max_idx = i; // assume the root node contains the maximum value
		int left_idx = 2*i;
		if(left_idx < n && v[left_idx] > v[max_idx]) {
			max_idx = left_idx;
		}

		int right_idx = 2*i + 1;
		if(right_idx < n && v[right_idx] > v[max_idx]) {
			max_idx = right_idx;
		}

		if(i != max_idx) {  // base is handled here when i == max_idx
			swap(v[i], v[max_idx]);
			heapify(v, n, max_idx);
		}

		// you return from here as soon as you hit the base case
	}

int main() {

	int v[] = {-1, 2, 0, 1, 4, 6, 5, 7, 3};
	int n = sizeof(v) / sizeof(int) ;

	for(int i=n/2-1; i>=1; i--) {
		heapify(v, n, i);
	}

	for(int i=1; i<n; i++) {
		cout << v[i] << " ";
	}

	cout << endl;

	int heapsize = n;

	while(heapsize > 1) {
		swap(v[1], v[heapsize-1]);
		heapsize--;
		heapify(v, heapsize, 1);
	}

	for(int i=1; i<n; i++) {
		cout << v[i] << " ";
	}

	cout << endl;

	return 0;
}

/*

    There are given n ropes of different lengths, we need to connect these ropes into one rope.
    The cost to connect two ropes is equal to the sum of their lengths. We need to connect the
    ropes with minimum cost.

    Example :

    Input : {4, 3, 2, 6}
    Output: 29

*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main() {

    vector<int> ropeLengths = {4, 3, 2, 6};
    int minCost = 0;

    priority_queue<int, vector<int>, greater<int>> minHeap(ropeLengths.begin(),
                                                           ropeLengths.end());

    while(minHeap.size() > 1) {
        int a = minHeap.top();
        minHeap.pop();

        int b = minHeap.top();
        minHeap.pop();

        minCost += (a+b);
        minHeap.push(a+b);
    }

    cout << "minCost : " << minCost << endl;

    return 0;
}
/*

Given an infinite stream of non-negative integers, design an algorithm to output the
top-K integers every time you encounter -1.

Example : Input = 4, 1, 2, -1, 3, -1 7 0 1 2 -1 8 -1 . . . ; K = 3
          Output = 1 2 4
                   2 3 4
                   3 4 7
                   4 7 8
                   . . .

*/

#include<iostream>
#include<queue>

using namespace std;

void printMinHeap(priority_queue<int, vector<int>, greater<int>> minHeap) {
    while(!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    cout << endl;
}

int main() {

    int k;
    cin >> k;

    int x; // to read value from the stream

    priority_queue<int, vector<int>, greater<int>> minHeap;

    // build a minHeap using the first k values read from the
    // stream, assume you'll not get a -1 till you've read
    // atleast k values from the stream

    for(int i=0; i<k; i++) {
        cin >> x;
        minHeap.push(x);
    }

    while(true) {
        cin >> x;
        if(x == -1) {
            // print the top-k elements you've read
            printMinHeap(minHeap);
        } else {
            // check if the x is greater than min. of top-k you've read
            if(x > minHeap.top()) {
                minHeap.pop();
                minHeap.push(x);
            }
        }
    }

    return 0;

}
/*

    Given k sorted arrays, merge them and print the sorted output.

    k = 3
    Input : {
                {1, 3, 5, 7},
                {2, 4, 6, 8},
                {0, 9, 10, 11}
            }

    Output: 0 1 2 3 4 5 6 7 8 9 10 11

*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// class Triple {
// public:
//     int val;
//     int arr_idx;
//     int val_idx;

//     Triple(int val, int arr_idx, int val_idx) {
//         this->val = val;
//         this->arr_idx = arr_idx;
//         this->val_idx = val_idx;
//     }
// };

// class TripleCompare {
// public:
//     bool operator()(Triple t1, Triple t2) const {
//         return t1.val > t2.val;
//     }

// };

int main() {

    vector<vector<int>> v = {{1, 3, 5, 7},
                             {2, 4, 6, 8},
                             {0, 9, 10, 11}};

    int k = v.size();

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;

    for(int arr_idx=0; arr_idx<k; arr_idx++) {
        int val = v[arr_idx][0];
        int val_idx = 0;
        minHeap.push({val, arr_idx, val_idx});
    }

    vector<int> result;
    while(!minHeap.empty()) {
        vector<int> minNode = minHeap.top();
        minHeap.pop();

        int val = minNode[0];
        int arr_idx = minNode[1];
        int val_idx = minNode[2];

        result.push_back(val);

        if(val_idx+1 < v[arr_idx].size()) {

           minHeap.push({v[arr_idx][val_idx+1],
                         arr_idx,
                         val_idx+1});
        }

    }

    for(auto x : result) {
        cout << x << " ";
    }





    return 0;

}