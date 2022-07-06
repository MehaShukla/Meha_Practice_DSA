/*

	Implementation of HashTable

*/

#include<iostream>

using namespace std;

template <typename T1, typename T2>
class node {

public:
	T1 key;
	T2 value;
	node<T1, T2>* next;

	node(T1 key, T2 value) {
		this->key = key;
		this->value = value;
		this->next = NULL;
	}
};

template <typename T1, typename T2>
class HashTable {
	int M; // to store the capacity of the hash table
	int N; // to store the size i.e. no. of key value pairs inside the hash table
	double LFT; // to store the load factor threshold
	node<T1, T2>** table; // to store the address of the dynamic array that represents the table

	int hash_fn(T1 key) {
		return key%M;
	}

	void transfer(node<T1, T2>* head) {
		node<T1, T2>* temp = head;
		while(temp) {
			insert(temp->key, temp->value);
			temp = temp->next;
		}

		// release the memory for the linked list at the ith index

		while(head) {
			node<T1, T2>* temp = head;
			head = head->next;
			delete temp;
		}

	}

	void rehash() {
		int oldM = M; // to store the current capacity
		node<T1, T2>** oldTable = table; // to store address of current table

		// 1. create a new array with double capacity
		M = 2*M;
		table = new node<T1, T2>*[M];
		for(int i=0; i<M; i++) {
			table[i] = NULL;
		}
		N = 0;

		// 2. transfer contents from the old array into the new array
		for(int i=0; i<oldM; i++) {
			transfer(oldTable[i]);
		}

		// 3. delete the old array
		delete [] oldTable;
	}

	public :

		HashTable(int M=5, double LFT=0.7) {
			this->M = M;
			this->LFT = LFT;
			this->N = 0;
			table = new node<T1, T2>*[M];
			for(int i=0; i<M; i++) {
				table[i] = NULL;
			}
		}

		void insert(T1 key, T2 value) {
			// 1. compute the hash index using the key
			int hash_idx = hash_fn(key);

			// 2. insert the (key, value) pair at the head of the LL at the hash index
			node<T1, T2>* n = new node<T1, T2>(key, value);
			n->next = table[hash_idx];
			table[hash_idx] = n;

			N++;

			// 3. rehash the HT, in case the load factor exceeds the load factor threshold
			double LF = N/(M*1.0);
			if(LF > LFT) {
				// rehash the HT
				cout << "load factor : " << LF << ", rehashing..." << endl;
				rehash();
			}
		}

		node<T1, T2>* find(T1 key) {
			// 1. compute the hash index for the given key
			int hash_idx = hash_fn(key);

			// 2. search for the key in the linked list at the hash_idx
			node<T1, T2>* temp = table[hash_idx];
			while(temp && temp->key != key) {
				temp = temp->next;
			}
			return temp;
		}

		void erase(T1 key) {
			// 1. compute the hash index corresponding to the key
			int hash_idx = hash_fn(key);

			// 2. delete the node with the given key, if present, from
			//    the linked list at the hash index
			node<T1, T2>* prev = NULL;
			node<T1, T2>* temp = table[hash_idx];
			if(temp->key == key) {
				// delete from the head of the linked list
				table[hash_idx] = temp->next;
				delete temp;
				N--;
			} else {
				// delete from non-head of the linked list
				while(temp) {
					if(temp->key == key) {
						prev->next = temp->next;
						delete temp;
						N--;
						break;
					}
					prev = temp;
					temp = temp->next;
				}
			}
		}

		void printLinkedList(node<T1, T2>* head) {
			while(head) {
				cout << "(" << head->key << ", " << head->value << ")";
				head = head->next;
				if(head) cout << "->";
			}
			cout << endl;
		}

		void print() {
			for(int i=0; i<M; i++) {
				cout << i << " : ";
				printLinkedList(table[i]);
			}
			cout << endl;
		}

		T2& operator[](T1 key) {
			node<T1, T2>* n = find(key);
			if(!n) {
				// key is not present inside the hash table
				T2 garbage;
				insert(key, garbage);
				n = find(key);
			}
			return n->value;
		}
};


int main() {

	// HashTable<int, int> hashTable;

	// hashTable.insert(0, 0);
	// hashTable.insert(10, 100);
	// hashTable.insert(1, 1);
	// hashTable.insert(11, 121);
	// hashTable.insert(13, 169);

	// hashTable.print();

	// hashTable.erase(0);

	// hashTable.print();

	// node<int, int>* node = hashTable.find(13);
	// node ? cout << "(" << node->key << ", " << node->value << ")" << endl :
	//        cout << "not found!" << endl;

	// hashTable.erase(13);

	// hashTable.print();

	// node = hashTable.find(13);
	// node ? cout << "(" << node->key << ", " << node->value << ")" << endl :
	//        cout << "not found!" << endl;

	HashTable<int, int> hashTable;

	hashTable.insert(0, 0);
	hashTable.insert(10, 100);
	hashTable.insert(1, 1);

	hashTable.print();

	hashTable.insert(11, 121); // N = 4, M = 5, 4/5 = 0.8 > 0.7

	hashTable.print();

	hashTable.insert(13, 169);

	hashTable[14] = 0; // hashTable.operator[](14) = 0;
	hashTable[14] += 196;

	hashTable.print();

}

#include<iostream>

using namespace std;

class Test {
public:
	int* x;

	Test() {
		x  = new int;
		*x = 10;
	}

	int* f1() {
		return x;
	}

	int f2() {
		return *x; // dereference x and return its value
	}

	int& f3() { // returning the value by reference
		return *x;
	}

};

int main() {

	Test t;

	int*x1 = t.f1();
	cout << "x1=" << x1 << ", *x1=" << *x1 << endl;

	int x2 = t.f2();
	cout << "x2 = " << x2 << endl;

	*x1 = 20;
	x2 = t.f2();
	cout << "*x1=" << *x1 << ", x2=" << x2 << endl;

	int x3 = t.f3();
	cout << "*x1=" << *x1 << ", x2=" << x2 << ", x3=" << x3 << endl;

	// // when a value is returned by reference, we can assign values to it since it
	// // is just a new variable name
	t.f3() = 50;
	x2 = t.f2();
	x3 = t.f3();
	cout << "*x1=" << *x1 << ", x2=" << x2 << ", x3=" << x3 << endl;

	return 0;
}
/*

	Implementation of HashTable with key as a "string"

*/

#include<iostream>

using namespace std;

template <typename T1, typename T2>
class node {

public:
	T1 key;
	T2 value;
	node<T1, T2>* next;

	node(T1 key, T2 value) {
		this->key = key;
		this->value = value;
		this->next = NULL;
	}
};

template <typename T1, typename T2>
class HashTable {
	int M; // to store the capacity of the hash table
	int N; // to store the size i.e. no. of key value pairs inside the hash table
	double LFT; // to store the load factor threshold
	node<T1, T2>** table; // to store the address of the dynamic array that represents the table

	int hash_fn(T1 key, int base=61) {
		int sum = 0;
		int power = 1;
		for(int i=0; i<key.size(); i++) {
			sum += (key[i]%M)*(power%M)%M;
			power = (power*base)%M;
		}
		return sum%M;
	}

	void transfer(node<T1, T2>* head) {
		node<T1, T2>* temp = head;
		while(temp) {
			insert(temp->key, temp->value);
			temp = temp->next;
		}

		// release the memory for the linked list at the ith index

		while(head) {
			node<T1, T2>* temp = head;
			head = head->next;
			delete temp;
		}

	}

	void rehash() {
		int oldM = M; // to store the current capacity
		node<T1, T2>** oldTable = table; // to store address of current table

		// 1. create a new array with double capacity
		M = 2*M;
		table = new node<T1, T2>*[M];
		for(int i=0; i<M; i++) {
			table[i] = NULL;
		}
		N = 0;

		// 2. transfer contents from the old array into the new array
		for(int i=0; i<oldM; i++) {
			transfer(oldTable[i]);
		}

		// 3. delete the old array
		delete [] oldTable;
	}

	public :

		HashTable(int M=5, double LFT=0.7) {
			this->M = M;
			this->LFT = LFT;
			this->N = 0;
			table = new node<T1, T2>*[M];
			for(int i=0; i<M; i++) {
				table[i] = NULL;
			}
		}

		void insert(T1 key, T2 value) {
			// 1. compute the hash index using the key
			int hash_idx = hash_fn(key);

			// 2. insert the (key, value) pair at the head of the LL at the hash index
			node<T1, T2>* n = new node<T1, T2>(key, value);
			n->next = table[hash_idx];
			table[hash_idx] = n;

			N++;

			// 3. rehash the HT, in case the load factor exceeds the load factor threshold
			double LF = N/(M*1.0);
			if(LF > LFT) {
				// rehash the HT
				cout << "load factor : " << LF << ", rehashing..." << endl;
				rehash();
			}
		}

		node<T1, T2>* find(T1 key) {
			// 1. compute the hash index for the given key
			int hash_idx = hash_fn(key);

			// 2. search for the key in the linked list at the hash_idx
			node<T1, T2>* temp = table[hash_idx];
			while(temp && temp->key != key) {
				temp = temp->next;
			}
			return temp;
		}

		void erase(T1 key) {
			// 1. compute the hash index corresponding to the key
			int hash_idx = hash_fn(key);

			// 2. delete the node with the given key, if present, from
			//    the linked list at the hash index
			node<T1, T2>* prev = NULL;
			node<T1, T2>* temp = table[hash_idx];
			if(temp->key == key) {
				// delete from the head of the linked list
				table[hash_idx] = temp->next;
				delete temp;
				N--;
			} else {
				// delete from non-head of the linked list
				while(temp) {
					if(temp->key == key) {
						prev->next = temp->next;
						delete temp;
						N--;
						break;
					}
					prev = temp;
					temp = temp->next;
				}
			}
		}

		void printLinkedList(node<T1, T2>* head) {
			while(head) {
				cout << "(" << head->key << ", " << head->value << ")";
				head = head->next;
				if(head) cout << "->";
			}
			cout << endl;
		}

		void print() {
			for(int i=0; i<M; i++) {
				cout << i << " : ";
				printLinkedList(table[i]);
			}
			cout << endl;
		}

		T2& operator[](T1 key) {
			node<T1, T2>* n = find(key);
			if(!n) {
				// key is not present inside the hash table
				T2 garbage;
				insert(key, garbage);
				n = find(key);
			}
			return n->value;
		}
};


int main() {

	HashTable<string, string> hashTable;

	hashTable.insert("abc", "word 1");
	hashTable.insert("def", "word 2");
	hashTable.insert("ghi", "word 3");

	hashTable.print();

	hashTable["jki"] = "word 4";

	hashTable.print();

	return 0;

}

/*

What are unordered maps ?

Unordered maps are associative containers that store elements formed by the combination of a
key value and a mapped value, and which allows for fast retrieval of individual elements based
on their keys.

No two elements in the container can have equivalent keys.

What is the meaning of associative container ?

Elements in associative containers are referenced by their key and not by their absolute
position in the container.

How to create an unordered_map ?
	> use empty container constructor (default constructor)
	> use initialiser list (C++11)
	> use copy constructor
	> use range constructor
How to insert (K, V) pair into an unordered_map ?
	> use unordered_map::insert (C++11)
    > use []
How to update a (K, V) pair in an unordered_map ?
    > use []
How to lookup/search for the value corresponding to a key in an unordered_map ?
    > use unordered_map::find
    > use unordered_map::count
    > use []
How to delete a (K, V) pair from an unordered_map ?
	> use unordered_map::erase
	  > by key
	  > by position
	  > by range
    > use unordered_map::clear to remove all the elements from an unordered_map
How to check size of an unordered_map ?
	> use unordered_map::size to know number of (K, V) pairs present in an unordered_map
How to check number of buckets in an unordered_map ?
	> use unordered_map::bucket_count to know number of buckets present in an unordered_map
How to check if a unordered_map is empty ?
    > use unordered_map::empty or check if size of unordered_map is 0
How to iterate over elements in an unordered_map ?
    > use an iterator

*/

#include<iostream>
#include<unordered_map>

using namespace std;

int main() {

	// build an unordered_map using the default constructor
	unordered_map<string, string> captilMap;

	// inserting into a map

	// using unordered_map::insert
	captilMap.insert(make_pair("India", "New Delhi"));
	captilMap.insert({"USA", "Washington"});

	// using []
	captilMap["France"] = "Paris";

	// print map size using unordered_map::size
	cout << "size : " << captilMap.size() << endl;

	cout << endl;

	// iterating over the map

	// using an iterator
	for(auto it=captilMap.begin(), end=captilMap.end(); it != end; it++) {
		// pair<string, string> p = *it;
		// cout << p.first << " " << p.second << endl;

		// cout << (*it).first << " " << (*it).second << endl;

		cout << "(" << it->first << ", " << it->second << ")" << endl;
	}

	cout << endl;

	// using for-each loop

	for(auto p : captilMap) {
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}

	cout << endl;

	// using an iterator to iterate over buckets
	for(int i=0; i<captilMap.bucket_count(); i++) {
		cout << i << " : ";
		for(auto it=captilMap.begin(i), end=captilMap.end(i); it != end; it++) {
			cout << "(" << it->first << ", " << it->second << ") ";
		}
		cout << endl;
	}

	cout << endl;

	// updating a value corresponding to a key in a map using []
	captilMap["India"] = "Delhi";

	for(auto p : captilMap) {
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}

	cout << endl;

	// lookups

	// using unordered_map::find
	string key = "Japan";
	if(captilMap.find(key) != captilMap.end()) {
		cout << "(" << key << ", " << captilMap[key] << ")" << endl;
	} else {
		cout << key << " not found!" << endl;
	}

	// using unordered_map::count

	key = "India";
	if(captilMap.count(key)) {
		cout << "(" << key << ", " << captilMap[key] << ")" << endl;
	} else {
		cout << key << " not found!" << endl;
	}

	// deletion using unordered_map::erase

	// by key

	cout << endl;

	key = "France";
	captilMap.erase(key);

	for(auto p : captilMap) {
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}

	cout << endl;

	if(captilMap.count(key)) {
		cout << "(" << key << ", " << captilMap[key] << ")" << endl;
	} else {
		cout << key << " not found!" << endl;
	}

	// clear using unordered_map::clear

	captilMap.clear();

	cout << "size : " << captilMap.size() << endl;

	// build an unordered_map using the initialiser list

	unordered_map<int, int> squareMap = {{1, 1},
										 {2, 4},
										 {3, 9},
										 {4, 16}};


	for(auto p : squareMap) {
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}

	cout << endl;

	return 0;
}
/*

What are maps ?

Maps are associative containers that store elements formed by a combination of a key value
and a mapped value, following a specific order. Internally, the elements in a map are always
sorted by its key.

Maps are typically implemented as binary search trees, and therefore are generally slower
than unordered_map containers to access individual elements by their key.

How to create an map ?
	> use empty container constructor (default constructor)
	> use initialiser list (C++11)
	> use copy constructor
	> use range constructor
How to insert (K, V) pair into an map ?
	> use map::insert (C++11)
    > use []
How to update a (K, V) pair in an map ?
    > use []
How to lookup/search for the value corresponding to a key in an map ?
    > use map::find
    > use map::count
    > use []
How to delete a (K, V) pair from an map ?
	> use map::erase
	  > by key
	  > by position
	  > by range
    > use map::clear to remove all the elements from an map
How to check size of an map ?
	> use map::size to know number of (K, V) pairs present in an map
How to check if a map is empty ?
    > use map::empty or check if size of map is 0
How to iterate over elements in an map ?
    > use an iterator

*/

#include<iostream>
#include<map>

using namespace std;

int main() {

	// build an map using the default constructor
	map<string, string> captilMap;

	// inserting into a map

	// using map::insert
	captilMap.insert(make_pair("India", "New Delhi"));
	captilMap.insert({"USA", "Washington"});

	// using []
	captilMap["France"] = "Paris";

	// print map size using map::size
	cout << "size : " << captilMap.size() << endl;

	cout << endl;

	// iterating over the map

	// using an iterator
	for(auto it=captilMap.begin(), end=captilMap.end(); it != end; it++) {
		// pair<string, string> p = *it;
		// cout << p.first << " " << p.second << endl;

		// cout << (*it).first << " " << (*it).second << endl;

		cout << "(" << it->first << ", " << it->second << ")" << endl;
	}

	cout << endl;

	// using for-each loop

	for(auto p : captilMap) {
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}

	cout << endl;

	// updating a value corresponding to a key in a map using []
	captilMap["India"] = "Delhi";

	for(auto p : captilMap) {
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}

	cout << endl;

	// lookups

	// using map::find
	string key = "Japan";
	if(captilMap.find(key) != captilMap.end()) {
		cout << "(" << key << ", " << captilMap[key] << ")" << endl;
	} else {
		cout << key << " not found!" << endl;
	}

	// using map::count

	key = "India";
	if(captilMap.count(key)) {
		cout << "(" << key << ", " << captilMap[key] << ")" << endl;
	} else {
		cout << key << " not found!" << endl;
	}

	// deletion using map::erase

	// by key

	cout << endl;

	key = "France";
	captilMap.erase(key);

	for(auto p : captilMap) {
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}

	cout << endl;

	if(captilMap.count(key)) {
		cout << "(" << key << ", " << captilMap[key] << ")" << endl;
	} else {
		cout << key << " not found!" << endl;
	}

	// clear using map::clear

	captilMap.clear();

	cout << "size : " << captilMap.size() << endl;

	// build an map using the initialiser list

	map<int, int> squareMap = {{4, 1},
							   {1, 4},
							   {3, 9},
							   {2, 16}};


	for(auto p : squareMap) {
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}

	cout << endl;

	return 0;

	return 0;
}
/*

	Implement a phonebook storing mapping between person's name and their phone numbers
	using an unordered_map.

*/

#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

int main() {

	unordered_map<string, vector<string>> phonebook;

	phonebook["Abhishek"].push_back("9999366996");
	phonebook["Abhishek"].push_back("1123455667");

	phonebook["Shrutika"].push_back("0123455667");
	phonebook["Saksham"].push_back("123445667");
	phonebook["Saksham"].push_back("1259494875");
	phonebook["Utsav"].push_back("012334566");

	cout << "size : " << phonebook.size() << endl;

	for(auto p : phonebook) {
		cout << p.first << " : ";
		for(auto x : p.second) {
			cout << x << " ";
		}
		cout << endl;
	}

	if(phonebook.find("Abhishek") != phonebook.end()) {
		vector<string> phoneNumbers = phonebook["Abhishek"];
		for(auto no :  phoneNumbers) {
			cout << no <<  " ";
		}
		cout << endl;
	}


	return 0;
}
/*
	Given N cartesian points in a 2D plane, count the number of right-angled triangles that
	can be formed such that the base or perpendicular is parallel to the x-axis or y-axis.

	Examples

	Input : {(0, 0),
	         (2, 0),
	         (0, 1)}

	Output: 1

	Input : {(1, 2),
			 (2, 0),
			 (2, 2),
			 (2, 3),
			 (4, 2)}

	Output: 4
*/

#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

class Point {
public:
	int x;
	int y;

	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

int main() {

	vector<Point> points = {Point(0, 1),
	 					    Point(2, 0),
	 						Point(0, 0)};

	unordered_map<int, int> xFreqMap;
	unordered_map<int, int> yFreqMap;

	for(Point point : points) {
		xFreqMap[point.x]++;
		yFreqMap[point.y]++;
	}


	int count = 0;
	for(Point point : points) {
		// compute the no. of right angled triangles whose base or
		// perpendicular is parallel to the x or y axis that can
		// be formed with 'point' as the pivot.

		// int a = 0; // count of points that have the same x coordinate as 'point'
		// int b = 0; // count of points that have the same y coordinate as 'point'
		// for(Point p : points) {
		// 	if(p.x == point.x) {
		// 		a++;
		// 	}
		// 	if(p.y == point.y) {
		// 		b++;
		// 	}
		// }

		int a = xFreqMap[point.x];
		int b = yFreqMap[point.y];

		count += (a-1)*(b-1);
	}

	cout << "count : " << count << endl;

	return 0;
}
/*
	Given N cartesian points in a 2D plane, count the number of axis parallel rectangles that
	can be formed.

	Example

	Input : {(0, 0), (0, 1), (1, 1), (1, 0), (2, 1), (2, 0), (3, 1), (3, 0)}
	Output: 6

*/

#include<iostream>
#include<vector>
#include<set>

using namespace std;

class Point {
public:
	int x;
	int y;

	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

class PointCompare {

public:
	bool operator()(const Point p1, const Point p2) const {
		if(p1.x == p2.x) {
			return p1.y < p2.y;
		}
		return p1.x < p2.x;
	}


};

int main() {

	vector<Point> points{Point(0, 0),
						 Point(0, 1),
						 Point(1, 1),
						 Point(1, 0),
						 Point(2, 1),
						 Point(2, 0),
						 Point(3, 1),
						 Point(3, 0)};

	set<Point, PointCompare> s(points.begin(), points.end());

	int count = 0;
	for(int i=0; i<points.size()-1; i++) {
		Point p1 = points[i];
		for(int j=i+1; j<points.size(); j++) {
			Point p2 = points[j];
			if(p1.x != p2.x && p1.y != p2.y) {
				// assume p1 and p2 form the endPoints of the diagnoal
				// of an axis parallel rectangle
				Point p3 = Point(p1.x, p2.y);
				Point p4 = Point(p2.x, p1.y);
				if(s.find(p3) != s.end() && s.find(p4) != s.end()) {
					count++;
				}
			}
		}
	}

	count /= 2; // to avoid double-counting of rectangles

	cout << "count : " << count << endl;

	return 0;
}
/*

	given the pre-order traversal of a binary tree, output its vertical order traversal.

	Example
		Input : 10 20 40 -1 -1 50 70 -1 -1 -1 30 -1 60 -1 -1
		Output: 40
		        20 70
		        10 50
		        30
		        60
*/

#include<iostream>
#include<vector>
#include<map>

using namespace std;

class node {
public:
	int data;
	node* left;
	node* right;

	node(int data) {
		this->data = data;
		this->left = this->right = NULL;
	}
};

node* buildTree() {
	int x;
	cin >> x;

	if(x == -1) {
		node* root = NULL;
		// root represents an empty tree
		return root;
	}

	node* root = new node(x);
	root->left = buildTree();
	root->right=buildTree();

	return root;
}


void verticalOrder(node* root, int d, map<int, vector<int>>& m) {
	// base case
	if(!root) {
		return;
	}

	// recursive case

	m[d].push_back(root->data);
	verticalOrder(root->left,  d-1, m);
	verticalOrder(root->right, d+1, m);

}

int main() {

	node* root = NULL;
	root = buildTree();

	map<int, vector<int>> m;
	verticalOrder(root, 0, m);

	for(auto p : m) {
		// cout << p.first << " ";
		for(auto x : p.second) {
			cout << x << " ";
		}
		cout << endl;
	}
	cout << endl;

	return 0;
}


