/*

Given an undirected graph design an algorithm to check if there exists a cycle or not.

*/

#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<list>

using namespace std;

template <typename T>
class graph {
	unordered_map<T, list<T>> neighbourMap;

	public :

		void addEdge(T u, T v) {
			neighbourMap[u].push_back(v);
			neighbourMap[v].push_back(u);
		}

		bool dfsHelper(T source, unordered_set<T>& visited, T parent) {
			visited.insert(source);
			list<T> neighbourList = neighbourMap[source];
			for(T neighbour : neighbourList) {
				if(visited.find(neighbour) == visited.end()) {
					// neighbour hasn't been visited previously
					if(dfsHelper(neighbour, visited, source)) {
						return true;
					}
				} else {
					// neighbour has been visited previously
					if(neighbour  != parent) {
						return true;
					}
				}
			}

			return false;
		}

		bool detectCycle() {
			unordered_set<T> visited;
			bool flag = false; // assume cycle is not present
			for(pair<T, list<T>> vertex : neighbourMap) {
				T vertexLabel = vertex.first;
				if(visited.find(vertexLabel) == visited.end()) {
					if(dfsHelper(vertexLabel, visited, vertexLabel)) {
						flag = true;
						break;
					}
				}
			}

			return flag;
		}
};


int main() {

	graph<char> g;

	g.addEdge('A', 'B');
	g.addEdge('A', 'C');
	g.addEdge('B', 'C');

	g.detectCycle() ? cout << "Cycle is present" << endl :
	                  cout << "Cycle is not present" << endl;

	return 0;
}