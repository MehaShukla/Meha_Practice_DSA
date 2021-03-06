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