/*

	Vectors Part I
	

	How to create a vector ? 
		> use empty container constructor (default constructor)
	How to add elements to a vector ?
	    > use vector::push_back to add element at back (constant time operator)
	How to remove elements from a vector ?
	    > use vector::pop_back to remove element from back (constant time operation)
	    > use vector::clear to remove all the elements from a vector
	How to check size of a vector ?
		> use vector::size to know number of elements in a vector
		> use vector::capacity to know current capacity of the vector
		> use vector::max_size to know maximum number of elements that can added in a vector
	How to check if a vector is empty ?
	    > use vector::empty or check if vector size is 0
	How to access elements in a vector at a particular index ? 
	    > use vector::operator[] 
	    > use vector::at
	How to iterate over elements in a vector ?
	    > use indexing like arrays
	    > use an iterator

*/

#include<iostream>
#include<vector>

using namespace std;

int main() {

	vector<int> v; // default constructor of the vector<int> class
				   // is invoked to create an empty vector object v


	cout << v.size() << " " << v.capacity() << endl;

	v.push_back(1);

	cout << v.size() << " " << v.capacity() << endl;

	v.push_back(2);

	cout << v.size() << " " << v.capacity() << endl;

	v.push_back(3);

	cout << v.size() << " " << v.capacity() << endl;

	v.push_back(4);

	cout << v.size() << " " << v.capacity() << endl;

	v.push_back(5);

	cout << v.size() << " " << v.capacity() << endl;

	cout << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << " " << v[4] << endl;

	for(int i=0; i<v.size(); i++) {
		cout << v[i] << " ";
	}

	cout << endl;

	for(auto x : v) {
		cout << x << " ";
	}

	cout << endl;

	// vector<int>::iterator begin = v.begin(); // returns iterator to the element at the 0th idx
	// auto end = v.end(); // returns an iterator the the elment at nth idx
	// 			        // i.e. the element after the last element

	for(auto begin=v.begin(), end=v.end(); begin != end; begin++) {
		cout << *begin << " ";
	}

	cout << endl;

	v.pop_back();

	for(auto x : v) {
		cout << x << " ";
	}

	cout << endl;

	cout << v.size() << " " << v.capacity() << endl;


	v.pop_back();

	for(auto x : v) {
		cout << x << " ";
	}

	cout << endl;

	cout << v.size() << " " << v.capacity() << endl;

	v.clear();
	
	cout << v.size() << " " << v.capacity() << endl;

	v.empty() ? cout << "true" << endl : cout << "false" << endl;
	v.size() == 0 ? cout << "true" << endl : cout << "false" << endl;
	
	return 0;
}






