//Reverse first q elements of the queue.

queue<int> modifyQueue(queue<int> q, int k) {
    // add code here.

    stack<int>s;

    for(int i=0;i<k;i++){
        s.push(q.front());
        q.pop();
    }

    while(!s.empty()){
        q.push(s.top());
        s.pop();

    }


    for(int i=0;i<q.size()-k;i++){
        q.push(q.front());
        q.pop();
    }

    return q;

}

//hoodies at coding blocks
/*It's winter season. There is a long queue of students from the four prime courses at Coding Blocks and
everyone is here to grab his hoodie. Each student of a course has a different roll number.
Whenever a new student will come, he will search for his friend from the end of the queue.
Note that a student can only has friend from his course and not from any other course.
As soon as he will find any of the friend in the queue, he will stand behind him, otherwise he will stand
at the end of the queue. At any moment Kartik Bhaiya will ask the student, who is standing in front of the queue,
 to come and put his name and grab his hoodie and then remove that student from the queue.
 There are Q operations of one of the following types:

E x y : A new student of course x whose roll number is y will stand in queue according to the method mentioned above.
D : Kartik Bhaiya will ask the student, who is standing in front of the queue, to come and put his name for the
 hoodie and remove him from the queue.
Find out the order in which student put their name.

Note: Number of dequeue operations will never be greater than enqueue operations at any point of time.

Input Format
First line contains an integer Q, denoting the number of operations. Next Q lines will contains
one of the 2 types of operations.

Constraints
1 ≤ x ≤ 4 1 ≤ y ≤ 50000 1 ≤ Q ≤ 100000

Output Format
For each 2nd type of operation, print two space separated integers, the front student's course and roll number.

Sample Input
5
E 1 1
E 2 1
E 1 2
D
D
Sample Output
1 1
1 2*/
#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin>>n;

	queue<int>q[5];

	int preference[5];

	for(int i=0;i<5;i++){
		preference[i]=-1;
	}
	preference[0]=0;

	while(n--){
		char ch;
		cin>>ch;

		if(ch=='E'){
			preference[0]++;
			int a,b;
			cin>>a>>b;

			if(preference[a]==-1){
				preference[a]=preference[0];
			}
			q[a].push(b);
		}else{
			int id=0;
			int mini=INT_MAX;

			for(int i=1;i<=4;i++){
				if(preference[i]!=-1 and preference[i]<mini){
					id=i;
					mini=preference[i];
				}
			}

			cout<<id<<" "<<q[id].front()<<endl;

			q[id].pop();
			if(q[id].empty()){
				preference[id]=-1;
			}
		}
	}
	return 0;
}

//first negstive in every window:
#include<bits/stdc++.h>
using namespace std;

void windownegative(int arr[],int n,int k){
	deque<int>q;

	for(int i=0;i<k;i++){
		if(arr[i]<0){
			q.push_back(i);
		}
	}

	for(int i=k;i<n;i++){
		if(!q.empty())cout<<arr[q.front()]<<" ";
		else{
			cout<<0<<" ";
		}

		while(!q.empty() and q.front()<=i-k){
			q.pop_front();
		}

		if(arr[i]<0){
			q.push_back(i);
		}
	}
	if(!q.empty())cout<<arr[q.front()]<<" ";
		else{
			cout<<0<<" ";
		}

}

int main() {
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;

		int arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}

		windownegative(arr,n,k);

		cout<<endl;
	}
	return 0;
}
//maxsubarray
#include<iostream>
#include<climits>
using namespace std;

int kadanes(int arr[], int n)
{
    int currSum = 0;
    int maxSum = INT_MIN;

    for(int i=0; i<n; i++)
    {
        currSum += arr[i];
        maxSum = max(currSum, maxSum);

        if(currSum < 0)
        {
            currSum = 0;
        }
    }

    return maxSum;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    cout<<kadanes(arr, n);
	return 0;
}
//missing no
#include<iostream>
using namespace std;

int missingNumber(int arr[], int n)
{
    int totalSum = n*(n+1)/2;
    int arraySum = 0;

    for(int i=0; i<n; i++)
    {
        arraySum += arr[i];
    }

    return totalSum - arraySum;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    cout<<missingNumber(arr, n);
	return 0;
}
//move 0s
// Given an integer array nums, move all 0's to the end of it while maintaining t
//the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.



Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
#include<iostream>
using namespace std;

void moveZeros(int arr[], int n)
{
    int j = 0;

    for(int i=0; i<n; i++)
    {
        if(arr[i]!=0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    moveZeros(arr, n);
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
	return 0;
}
//pivot index
#include<iostream>
using namespace std;

int pivotIndex(int arr[], int n)
{
    int totalSum = 0;
    for(int i=0; i<n; i++)
    {
        totalSum += arr[i];
    }

    int leftSum = 0;
    int rightSum = totalSum;

    for(int i=0; i<n; i++)
    {
        rightSum -= arr[i];
        if(leftSum == rightSum)
        {
            return i;
        }
        leftSum += arr[i];
    }
    return -1;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    cout<<pivotIndex(arr, n);
	return 0;
}
//sort by parity even phle odd bad
#include<iostream>
using namespace std;

void sortByParity(int arr[], int n)
{
    int i=0;
    int j=n-1;

    while(i<j)
    {
        if(arr[i]%2!=0)
        {
            swap(arr[i], arr[j]);//not here i++ as hme kya pta new elemnt jo aya vio satisfy krra k ni
            j--;
        }
        else
        {
            i++;
        }
    }

}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    sortByParity(arr, n);
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
	return 0;
}
