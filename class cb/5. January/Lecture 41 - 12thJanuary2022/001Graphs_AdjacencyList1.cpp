/*

Implementation of the graph using adjacency list.

Note : each vertex in the graph is an integer.

*/

#include<iostream>
#include<list>

using namespace std;

class graph {

	int V; // to store the no. of vertices present in the graph
	list<int>* arr; // to store the address of the dynamic array
	bool isDirected; // indicates if the graph is directed or not

	public :

		graph(int V, bool isDirected=false) {
			this->V = V;
			arr = new list<int>[V];
			this->isDirected = isDirected;
		}

		void addEdge(int u, int v) {
			arr[u].push_back(v);
			if(!isDirected) {
				arr[v].push_back(u);
			}
		}

		void print() {
			for(int i=0; i<V; i++) {
				cout << i << " : ";
				list<int> neighbourList = arr[i];
				for(int neighbour : neighbourList) {
					cout << neighbour << " ";
				}
				cout << endl;
			}
			cout << endl;
		}

};

int main() {

	graph g(5);

	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(1, 3);
	g.addEdge(2, 3);
	g.addEdge(2, 4);
	g.addEdge(3, 4);

	g.print();


	return 0;
}
/*

Implementation of the graph using adjacency list.

Note : each vertex in the graph is generic.

*/

#include<iostream>
#include<map>
#include<list>

using namespace std;

template <typename T>
class graph {
	map<T, list<T>> neighbourMap;
	bool isDirected;

	public :

		graph(bool isDirected=false) {
			this->isDirected = isDirected;
		}

		void addEdge(T u, T v) {
			neighbourMap[u].push_back(v);
			if(!isDirected) {
				neighbourMap[v].push_back(u);
			}
		}

		void print() {
			for(pair<T, list<T>> vertex : neighbourMap) {
				T vertexLabel = vertex.first;
				list<T> neighbourList = vertex.second;
				cout << vertexLabel << " : ";
				for(T neighbour : neighbourList) {
					cout << neighbour << " ";
				}
				cout << endl;
			}
			cout << endl;
		}

};


int main() {

	graph<char> g;

	g.addEdge('A', 'B');
	g.addEdge('A', 'C');
	g.addEdge('B', 'C');
	g.addEdge('B', 'D');
	g.addEdge('C', 'D');
	g.addEdge('C', 'E');
	g.addEdge('D', 'E');

	g.print();

	return 0;
}
/*

Implementation of the weighted graph using adjacency list.

Note : each vertex in the graph is generic.

*/

#include<iostream>
#include<map>
#include<list>

using namespace std;

template <typename T>
class graph {
	map<T, list<pair<T, int>>> neighbourMap;
	bool isDirected;

	public :

		graph(bool isDirected=false) {
			this->isDirected = isDirected;
		}

		void addEdge(T u, T v, int w) {
			neighbourMap[u].push_back({v, w});
			if(!isDirected) {
				neighbourMap[v].push_back({u, w});
			}
		}

		void print() {
			for(pair<T, list<pair<T, int>>> vertex : neighbourMap) {
				T vertexLabel = vertex.first;
				list<pair<T, int>> neighbourList = vertex.second;
				cout << vertexLabel << " : ";
				for(pair<T, int> neighbour : neighbourList) {
					T neighbourLabel = neighbour.first;
					int edgeWeight = neighbour.second;
					cout << "(" << neighbourLabel << ", " << edgeWeight << ") ";
				}
				cout << endl;
			}
			cout << endl;
		}

};


int main() {

	graph<char> g;

	g.addEdge('A', 'B', 10);
	g.addEdge('A', 'C', 5);
	g.addEdge('B', 'C', 3);
	g.addEdge('B', 'D', 1);
	g.addEdge('C', 'D', 9);
	g.addEdge('C', 'E', 2);
	g.addEdge('D', 'E', 8);

	g.print();

	return 0;
}
/*

Implementation of graph search using

  1. depth first search   (dfs)
  2. breadth first search (bfs)

*/

#include<iostream>
#include<map>
#include<list>
#include<unordered_set>
#include<queue>

using namespace std;

template <typename T>
class graph {
	map<T, list<T>> neighbourMap;
	bool isDirected;

	public :

		graph(bool isDirected=false) {
			this->isDirected = isDirected;
		}

		void addEdge(T u, T v) {
			neighbourMap[u].push_back(v);
			if(!isDirected) {
				neighbourMap[v].push_back(u);
			}
		}

		void print() {
			for(pair<T, list<T>> vertex : neighbourMap) {
				T vertexLabel = vertex.first;
				list<T> neighbourList = vertex.second;
				cout << vertexLabel << " : ";
				for(T neighbour : neighbourList) {
					cout << neighbour << " ";
				}
				cout << endl;
			}
			cout << endl;
		}

		void dfsHelper(T s, unordered_set<T>& visited) {
			visited.insert(s);
			cout << s << " ";
			list<T> neighbourList = neighbourMap[s];
			for(T neighbour : neighbourList) {
				if(visited.find(neighbour) == visited.end()) {
					dfsHelper(neighbour, visited);
				}
			}

		}

		void dfs(T s) {
			unordered_set<T> visited;
			cout << "dfs(" << s << ") : ";
			dfsHelper(s, visited);
			cout << endl;
		}

		void bfs(T s) {

			cout << "bfs(" << s << ") : ";
			unordered_set<T> visited;
			queue<T> q; // contains vertices which are visited but not yet processed/explored

			visited.insert(s);
			q.push(s);

			while(!q.empty()) {
				T front = q.front();
				q.pop();

				cout << front << " ";
				list<T> neighbourList = neighbourMap[front];
				for(T neighbour : neighbourList) {
					if(visited.find(neighbour) == visited.end()) {
						visited.insert(neighbour);
						q.push(neighbour);
					}
				}
			}

			cout << endl;
		}

};


int main() {

	graph<int> g;

	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 3);
	g.addEdge(1, 4);
	g.addEdge(2, 4);
	g.addEdge(2, 5);
	g.addEdge(3, 6);
	g.addEdge(4, 6);
	g.addEdge(4, 7);
	g.addEdge(5, 7);
	g.addEdge(6, 8);
	g.addEdge(7, 8);

	g.print();

	g.dfs(0);
	g.bfs(1);

	return 0;
}
/*

Implementation of graph traversal using

	1. depth first search (dfs)
	2. breadth first search (bfs)

*/

#include<iostream>
#include<map>
#include<list>
#include<unordered_set>
#include<queue>

using namespace std;

template <typename T>
class graph {
	map<T, list<T>> neighbourMap;
	bool isDirected;

	public :

		graph(bool isDirected=false) {
			this->isDirected = isDirected;
		}

		void addEdge(T u, T v) {
			neighbourMap[u].push_back(v);
			if(!isDirected) {
				neighbourMap[v].push_back(u);
			}
		}

		void print() {
			for(pair<T, list<T>> vertex : neighbourMap) {
				T vertexLabel = vertex.first;
				list<T> neighbourList = vertex.second;
				cout << vertexLabel << " : ";
				for(T neighbour : neighbourList) {
					cout << neighbour << " ";
				}
				cout << endl;
			}
			cout << endl;
		}

		void bfs(T s, unordered_set<T>& visited) {

			cout << "bfs(" << s << ") : ";
			queue<T> q; // contains vertices which are visited but not yet processed/explored

			visited.insert(s);
			q.push(s);

			while(!q.empty()) {
				T front = q.front();
				q.pop();

				cout << front << " ";
				list<T> neighbourList = neighbourMap[front];
				for(T neighbour : neighbourList) {
					if(visited.find(neighbour) == visited.end()) {
						visited.insert(neighbour);
						q.push(neighbour);
					}
				}
			}

			cout << endl;
		}

		void bfsTraverse() {
			unordered_set<T> visited;
			int numComponents = 0;
			for(pair<T, list<T>> vertex : neighbourMap) {
				T vertexLabel = vertex.first;
				if(visited.find(vertexLabel) == visited.end()) {
					bfs(vertexLabel, visited);
					numComponents++;
				}
			}
			cout << "numComponents : " << numComponents << endl;
		}

};


int main() {

	graph<int> g;

	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 3);
	g.addEdge(1, 4);
	g.addEdge(2, 4);
	g.addEdge(2, 5);
	g.addEdge(3, 6);
	g.addEdge(4, 6);
	g.addEdge(4, 7);
	g.addEdge(5, 7);
	g.addEdge(6, 8);
	g.addEdge(7, 8);

	g.addEdge(9, 10);
	g.addEdge(10, 11);
	g.addEdge(11, 9);

	g.addEdge(12, 13);
	g.addEdge(13, 14);

	g.print();

	g.bfsTraverse();

	return 0;
}
/*

Computing SSSP using the BFS algorithm in an unweighted graph.

Note : each vertex in the graph is generic.

*/

#include<iostream>
#include<map>
#include<list>
#include<unordered_set>
#include<queue>

using namespace std;

template <typename T>
class graph {
	map<T, list<T>> neighbourMap;
	bool isDirected;

	public :

		graph(bool isDirected=false) {
			this->isDirected = isDirected;
		}

		void addEdge(T u, T v) {
			neighbourMap[u].push_back(v);
			if(!isDirected) {
				neighbourMap[v].push_back(u);
			}
		}

		void print() {
			for(pair<T, list<T>> vertex : neighbourMap) {
				T vertexLabel = vertex.first;
				list<T> neighbourList = vertex.second;
				cout << vertexLabel << " : ";
				for(T neighbour : neighbourList) {
					cout << neighbour << " ";
				}
				cout << endl;
			}
			cout << endl;
		}

		void bfs(T s, T d) {

			cout << "bfs(" << s << ") : ";
			unordered_set<T> visited;
			queue<T> q; // to track visited but unexplored vertices

			visited.insert(s);
			q.push(s);

			map<T, int> distanceMap;
			distanceMap[s] = 0;

			map<T, T> parentMap;
			parentMap[s] = s;

			while(!q.empty()) {
				T front = q.front();
				q.pop();

				cout << front << " ";
				list<T> neighbourList = neighbourMap[front];
				for(T neighbour : neighbourList) {
					if(visited.find(neighbour) == visited.end()) {
						visited.insert(neighbour);
						q.push(neighbour);
						distanceMap[neighbour] = 1 + distanceMap[front];
						parentMap[neighbour] = front;
					}
				}
			}

			cout << endl;

			for(pair<T, int> vertex : distanceMap) {
				T vertexLabel = vertex.first;
				int vertexDist = vertex.second;
				cout << "(" << vertexLabel << ", " << vertexDist << ")" << endl;
			}

			cout << endl;

			cout << "The length of the shortest path between " <<
			s << " and " << d << " : " << distanceMap[d] << endl;

			// for(pair<T, T> vertex : parentMap) {
			// 	T vertexLabel = vertex.first;
			// 	T parentLabel = vertex.second;
			// 	cout << "(" << vertexLabel << ", " << parentLabel << ")" << endl;
			// }

			// cout << endl;

			cout << "The shortest path between " << s << " and " << d << " : ";
			T temp = d;
			while(parentMap[temp] != temp) {
				cout << temp << "<-";
				temp = parentMap[temp];
			}
			cout << temp << endl; // at this point temp is equal to source
		}

};


int main() {

	graph<int> g;

	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 3);
	g.addEdge(1, 4);
	g.addEdge(2, 4);
	g.addEdge(2, 5);
	g.addEdge(3, 6);
	g.addEdge(4, 6);
	g.addEdge(4, 7);
	g.addEdge(5, 7);
	g.addEdge(6, 8);
	g.addEdge(7, 8);

	g.print();

	g.bfs(0, 6);

	return 0;
}
/*

Computing SSSP using the Dijkstra's algorithm in a weighted graph.

Note : each vertex in the graph is generic.

*/

#include<iostream>
#include<map>
#include<list>
#include<climits>
#include<unordered_set>
#include<set>

using namespace std;

template <typename T>
class graph {
	map<T, list<pair<T, int>>> neighbourMap;
	bool isDirected;

	public :

		graph(bool isDirected=false) {
			this->isDirected = isDirected;
		}

		void addEdge(T u, T v, int w) {
			neighbourMap[u].push_back({v, w});
			if(!isDirected) {
				neighbourMap[v].push_back({u, w});
			}
		}

		void print() {
			for(pair<T, list<pair<T, int>>> vertex : neighbourMap) {
				T vertexLabel = vertex.first;
				list<pair<T, int>> neighbourList = vertex.second;
				cout << vertexLabel << " : ";
				for(pair<T, int> neighbour : neighbourList) {
					T neighbourLabel = neighbour.first;
					int edgeWeight = neighbour.second;
					cout << "(" << neighbourLabel << ", " << edgeWeight << ") ";
				}
				cout << endl;
			}
			cout << endl;
		}

		void dijkstra(T s, T d) {

			map<T, int> distanceMap;
			for(auto vertex : neighbourMap) {
				T vertexLabel = vertex.first;
				distanceMap[vertexLabel] = INT_MAX;
			}

			distanceMap[s] = 0; // shortest dist of 's' from itself is 0

			unordered_set<T> explored; // to store vertices whose shortest dist. from the
								       // source has been computed and all the tensed edges
								       // have been relaxed

			set<pair<int, T>> minHeap; // to store the unexplored vertices
			for(pair<T, int> vertex : distanceMap) {
				T vertexLabel  = vertex.first;
				int vertexDist = vertex.second;
				minHeap.insert({vertexDist, vertexLabel});
			}

			map<T, T> parentMap;
			parentMap[s] = s;

			while(!minHeap.empty()) {
				pair<int, T> minVertex = *(minHeap.begin());
				minHeap.erase(minHeap.begin());

				int minVertexDist = minVertex.first;
				T minVertexLabel  = minVertex.second;

				list<pair<T, int>> neighbourList = neighbourMap[minVertexLabel];
				for(pair<T, int> neighbour : neighbourList) {
					T neighbourLabel = neighbour.first;
					int edgeWeight = neighbour.second;
					if(explored.find(neighbourLabel) == explored.end() &&
						distanceMap[neighbourLabel] > distanceMap[minVertexLabel] + edgeWeight) {

						// relax the edge between minVertexLabel & neighbourLabel

						// update the distance of the neighbourLabel in the minHeap
						auto it = minHeap.find({distanceMap[neighbourLabel], neighbourLabel});
						minHeap.erase(it);
						minHeap.insert({distanceMap[minVertexLabel] + edgeWeight, neighbourLabel});

						// update the distance of the neighbourLabel in the distanceMap
						distanceMap[neighbourLabel] = distanceMap[minVertexLabel] + edgeWeight;

						// update the parent of neighbourLabel
						parentMap[neighbourLabel] = minVertexLabel;
					}
				}

				explored.insert(minVertexLabel);
			}

			for(pair<T, int> vertex : distanceMap) {
				T vertexLabel = vertex.first;
				int vertexDist = vertex.second;
				cout << "(" << vertexLabel << ", " << vertexDist << ")" << endl;
			}

			cout << endl;

			cout << "The length of the shortest path between " <<
			s << " and " << d << " : " << distanceMap[d] << endl;


			cout << "The shortest path between " << s << " and " << d << " : ";
			T temp = d;
			while(parentMap[temp] != temp) {
				cout << temp << "<-";
				temp = parentMap[temp];
			}
			cout << temp << endl; // at this point temp is equal to source


		}

};

int main() {

	graph<char> g;

	g.addEdge('A', 'B', 10);
	g.addEdge('A', 'C', 5);
	g.addEdge('B', 'C', 3);
	g.addEdge('B', 'D', 1);
	g.addEdge('C', 'D', 9);
	g.addEdge('C', 'E', 2);
	g.addEdge('D', 'E', 8);

	g.print();

	g.dijkstra('A', 'D');

	return 0;
}
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
/*

Given an directed graph design an algorithm to check if there exists a back edge or not.

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
			// insert a directed edge between vertex 'u' and 'v'
			neighbourMap[u].push_back(v);
		}

		bool dfsHelper(T s, unordered_set<T>& visited, unordered_set<T>& stackState) {
			visited.insert(s);
			stackState.insert(s);

			list<T> neighbourList = neighbourMap[s];
			for(T neighbour : neighbourList) {
				if(visited.find(neighbour) == visited.end()) {
					if(dfsHelper(neighbour, visited, stackState)) {
						return true;
					}
				} else {
					if(stackState.find(neighbour) != stackState.end()) {
						// there exists a directed path from neighbour
						// to the current vertex
						return true;
					}
				}
			}
			stackState.erase(s);
			return false;
		}

		bool detectBackEdge() {
			unordered_set<T> visited;
			bool flag = false; // assume back edge is not present
			unordered_set<T> stackState; // keeps track of vertices currently
									     // present on the call stack
			for(pair<T, list<T>> vertex : neighbourMap) {
				T vertexLabel = vertex.first;
				if(visited.find(vertexLabel) == visited.end()) {
					if(dfsHelper(vertexLabel, visited, stackState)) {
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
	g.addEdge('B', 'C');
	g.addEdge('C', 'D');
	g.addEdge('D', 'A');

	g.detectBackEdge() ? cout << "Back edge found !" << endl :
	                     cout << "Back edge not found !" << endl;

	return 0;
}
/*

Snake and Ladders Game

*/

#include<iostream>
#include<map>
#include<list>
#include<unordered_set>
#include<queue>

using namespace std;

template <typename T>
class graph {
	map<T, list<T>> neighbourMap;

	public :

		void addEdge(T u, T v) {
			// insert a directed edge between vertex 'u' and 'v'
			neighbourMap[u].push_back(v);
		}

		int bfs(T s, T d) {

			queue<T> q;
			q.push(s);

			unordered_set<T> visited;
			visited.insert(s);

			map<T, int> distanceMap;
			distanceMap[s] = 0;

			map<T, T> parentMap;
			parentMap[s] = s;

			while(!q.empty()) {
				T front = q.front();
				q.pop();

				list<T> neighbourList = neighbourMap[front];
				for(T neighbour : neighbourList) {
					if(visited.find(neighbour) == visited.end()) {
						visited.insert(neighbour);
						q.push(neighbour);
						distanceMap[neighbour] = 1 + distanceMap[front];
						parentMap[neighbour] = front;
					}
				}
			}

			T temp = d;
			while(parentMap[temp] != temp) {
				cout << temp << "<-";
				temp = parentMap[temp];
			}
			cout << temp << endl;

			return distanceMap[d];
		}

		void print() {
			for(pair<T, list<T>> vertex : neighbourMap) {
				T vertexLabel = vertex.first;
				list<T> neighbourList = vertex.second;
				cout << vertexLabel << " : ";
				for(T neighbour : neighbourList) {
					cout << neighbour << " ";
				}
				cout << endl;
			}
			cout << endl;
		}

};

int minDiceThrows(int n, vector<pair<int,int>> snakes, vector<pair<int,int>> ladders) {

	graph<int> g;

	vector<int> weight(n+1, 0);
	for(auto snakePos : snakes) {
		int s = snakePos.first;
		int e = snakePos.second;
		weight[s] = e-s;
	}

	for(auto ladderPos : ladders) {
		int s = ladderPos.first;
		int e = ladderPos.second;
		weight[s] = e-s;
	}

	for(int u=1; u<n; u++) {
		for(int d=1; d<=6 && u+d <= n; d++) {
			int v = u+d;
			v += weight[v];
		    g.addEdge(u, v);
		}
	}

	return g.bfs(1, n);

}

int main() {

	int n = 36;

	vector<pair<int, int>> snakes  = {{17, 4},
									  {20, 6},
									  {24, 16},
									  {32, 30},
									  {34, 12}};

	vector<pair<int, int>> ladders = {{2, 15},
	                                  {5, 7},
	                                  {9, 27},
	                                  {18, 29},
	                                  {25, 35}};

	cout << minDiceThrows(n, snakes, ladders) << endl;

	return 0;
}
/////////////////////////////djikstra//////////////
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m,source;
	cin >> n >> m;
	vector<pair<int,int> > g[n+1]; 	// 1-indexed adjacency list for of graph

	int a,b,wt;
	for(int i = 0; i<m ; i++){
		cin >> a >> b >> wt;
		g[a].push_back(make_pair(b,wt));
		g[b].push_back(make_pair(a,wt));
	}

	cin >> source;

	// Dijkstra's algorithm begins from here
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;// min-heap ; In pair => (dist,from)
	vector<int> distTo(n+1,INT_MAX); 	// 1-indexed array for calculating shortest paths;

	distTo[source] = 0;
	pq.push(make_pair(0,source));	// (dist,from)

	while( !pq.empty() ){
		int dist = pq.top().first;
		int prev = pq.top().second;
		pq.pop();

		vector<pair<int,int> >::iterator it;
		for( it = g[prev].begin() ; it != g[prev].end() ; it++){
			int next = it->first;
			int nextDist = it->second;
			if( distTo[next] > distTo[prev] + nextDist){
				distTo[next] = distTo[prev] + nextDist;
				pq.push(make_pair(distTo[next], next));
			}
		}

	}

	cout << "The distances from source, " << source << ", are : \n";
	for(int i = 1 ; i<=n ; i++)	cout << distTo[i] << " ";
	cout << "\n";

	return 0;
	/////////////////////////////////////////////////////////////////////////////////

/*

	You are given an m x n binary matrix grid. An island is a group of 1's
	(representing land) connected 4-directionally (horizontal or vertical.)
	You may assume all four edges of the grid are surrounded by water.

	The area of an island is the number of cells with a value 1 in the island.
	Return the maximum area of an island in grid. If there is no island, return 0.

*/

#include<iostream>
#include<vector>

using namespace std;

int dfsHelper(vector<vector<int>> grid, int m, int n, int i, int j, vector<vector<bool>>& visited) {
	// mark the (i, j)th vertex as visted
	visited[i][j] = true;
	int count = 1; // to track no. of vertices in this component

	// int n_x = i+1;
	// int n_y = j;

	// if(n_x >= 0 && n_x < m && n_y >= 0 && n_y < n &&
	//    grid[n_x][n_y] == 1 &&
	//    !visited[n_x][n_y]) {
	// 	count += dfsHelper(grid, m, n, n_x, n_y, visited);
	// }

	// n_x = i-1;
	// n_y = j;

	// if(n_x >= 0 && n_x < m && n_y >= 0 && n_y < n &&
	//    grid[n_x][n_y] == 1 &&
	//    !visited[n_x][n_y]) {
	// 	count += dfsHelper(grid, m, n, n_x, n_y, visited);
	// }

	// n_x = i;
	// n_y = j+1;

	// if(n_x >= 0 && n_x < m && n_y >= 0 && n_y < n &&
	//    grid[n_x][n_y] == 1 &&
	//    !visited[n_x][n_y]) {
	// 	count += dfsHelper(grid, m, n, n_x, n_y, visited);
	// }

	// n_x = i;
	// n_y = j-1;

	// if(n_x >= 0 && n_x < m && n_y >= 0 && n_y < n &&
	//    grid[n_x][n_y] == 1 &&
	//    !visited[n_x][n_y]) {
	// 	count += dfsHelper(grid, m, n, n_x, n_y, visited);
	// }

	int d_x[4] = {1, -1, 0, 0};
	int d_y[4] = {0, 0, 1, -1};

	for(int k=0; k<4; k++) {
		int n_x = i+d_x[k];
		int n_y = j+d_y[k];
		if(n_x >= 0 && n_x < m && n_y >= 0 && n_y < n && grid[n_x][n_y] == 1 && !visited[n_x][n_y]) {
			count += dfsHelper(grid, m, n, n_x, n_y, visited);
		}
	}


	return count;

}

int largestIsland(vector<vector<int>> grid, int m, int n) {
	int maxArea = 0;
	vector<vector<bool>> visited(m, (vector<bool>(n, false)));
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			if(grid[i][j] == 1 && !visited[i][j]) {
				maxArea = max(maxArea, dfsHelper(grid, m, n, i, j, visited));
			}
		}
	}
	return maxArea;
}

int main() {

	vector<vector<int>> grid = {{1, 0, 0, 1, 0},
                                {1, 0, 1, 0, 0},
                                {0, 0, 1, 0, 1},
                                {1, 0, 1, 1, 1},
                                {1, 0, 1, 1, 0}};

	// vector<vector<int>> grid = {{0,0,1,0,0,0,0,1,0,0,0,0,0},
	//                             {0,0,0,0,0,0,0,1,1,1,0,0,0},
	//                             {0,1,1,0,1,0,0,0,0,0,0,0,0},
	//                             {0,1,0,0,1,1,0,0,1,0,1,0,0},
	//                             {0,1,0,0,1,1,0,0,1,1,1,0,0},
	//                             {0,0,0,0,0,0,0,0,0,0,1,0,0},
	//                             {0,0,0,0,0,0,0,1,1,1,0,0,0},
	//                             {0,0,0,0,0,0,0,1,1,0,0,0,0}};

    int m = grid.size();
    int n = grid[0].size();

    cout << largestIsland(grid, m, n) << endl;

    return 0;
}
/*

	Given a matrix of dimension m x n in which each cell contains an integer denoting
	the cost to traverse through the cell, design an algorithm to compute the sum of
	numbers along the minimum sum path from the top-left cell to the bottom-right cell.

	Assume there does not exist any negative cost cycles in the given matrix.

*/

#include<iostream>
#include<vector>
#include<set>
#include<climits>

using namespace std;

int shortestPath(vector<vector<int>> grid, int m, int n) {

	vector<vector<int>> distanceMap(m, vector<int>(n, INT_MAX));

	// to reach the source vertex i.e. the cell at top-left corner
	// we incur a cost of grid[0][0]
	distanceMap[0][0] = grid[0][0];

	vector<vector<bool>> explored(m, vector<bool>(n, false));

	// each entry in the minHeap is pair composed of tentative distance
	// of the vertex (i, j) from the source vertex and vertex label (i, j).
	set<pair<int, pair<int, int>>> minHeap;
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			minHeap.insert({
								distanceMap[i][j],
					            {i, j}
					       });
		}
	}

	int d_x[4] = {1, -1, 0, 0};
	int d_y[4] = {0, 0, 1, -1};

	while(!minHeap.empty()) {
		pair<int, pair<int, int>> minVertex = *(minHeap.begin());
		minHeap.erase(minHeap.begin());

		int minVertexDistance = minVertex.first;
		int minVertex_x = minVertex.second.first; // ith idx of the extracted vertex
		int minVertex_y = minVertex.second.second;// jth idx of the extracted vertex

		for(int k=0; k<4; k++) {
			int n_x = minVertex_x + d_x[k];
			int n_y = minVertex_y + d_y[k];

			if(n_x >= 0 && n_x < m && n_y >= 0 && n_y < n && !explored[n_x][n_y] &&
			   distanceMap[n_x][n_y] > minVertexDistance + grid[n_x][n_y]) {
				// relax the directed edge between minVertex and neighbour

				// update the tentative distance of the neighbour in the minHeap
				auto it = minHeap.find({ distanceMap[n_x][n_y],
					                     {n_x, n_y}
					                   });
			    minHeap.erase(it);
			    minHeap.insert({  minVertexDistance + grid[n_x][n_y],
			                      {n_x, n_y}
			                   });

				// update the tentaitve distance of the neighbour in the distanceMap
				distanceMap[n_x][n_y] = minVertexDistance + grid[n_x][n_y];

			}
		}

		explored[minVertex_x][minVertex_y] = true;

	}

	// return shortest distance of the destination i.e. the cell at the
	// bottom-right corner at index (m-1, n-1)
	return distanceMap[m-1][n-1];

}

int main() {

	vector<vector<int>> grid = {{31,  100, 65,  12,  18},
                                {10,  13,  47,  157, 6},
                                {100, 113, 174, 11,  33},
                                {88,  124, 41,  20,  140},
                                {99,  32,  111, 41,  20}};

    int m = grid.size();
    int n = grid[0].size();

    cout << shortestPath(grid, m, n) << endl;

    return 0;
}