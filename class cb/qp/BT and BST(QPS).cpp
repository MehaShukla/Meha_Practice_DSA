#include<bits/stdc++.h>
using namespace std;

//leaf nodes
class node{
	public:
	node*left;
	node*right;
	int data;

	node(int data){
		this->left=NULL;
		this->right=NULL;
		this->data=data;
	}
};

node* createtree( ){

	node*head=NULL;
	int d;
	cin>>d;
	head=new node(d);
	queue<node*>q;
	q.push(head);

	while(!q.empty()){
		node*f=q.front();
		q.pop();

		int a,b;
		cin>>a>>b;

		if(a!=-1){
			f->left=new node(a);
			q.push(f->left);
		}
		if(b!=-1){
			f->right=new node(b);

			q.push(f->right);
		}
	}

	return head;

}

void printleafnodes(node*head){
	if(head==NULL)return;

	if(head->left==NULL and head->right==NULL){
		cout<<head->data<<" ";
		return;
	}

	printleafnodes(head->left);
	printleafnodes(head->right);
}


int main() {

	node*head=createtree();

	printleafnodes(head);

	return 0;
}

//structurally identical
#include<bits/stdc++.h>
using namespace std;
class node{
	public:
	node*left;
	node*right;
	int data;

	node(int data){
		this->left=NULL;
		this->right=NULL;
		this->data=data;
	}
};

node* createtree(string s){
	if(s=="true"){
		int d;
		cin>>d;

		node*head=new node(d);
		string l;
		cin>>l;

		head->left=createtree(l);
		string r;
		cin>>r;

		head->right=createtree(r);

		return head;
	}
	return NULL;
}

bool structurallyidentical(node*head1,node*head2){
	if(head1==NULL and head2==NULL)return true;

	if(head1==NULL or head2==NULL)return false;

	return structurallyidentical(head1->left,head2->left) and structurallyidentical(head1->right,head2->right);
}
int main() {

	node*head1=createtree("true");
	node*head2=createtree("true");

	cout<<boolalpha<<structurallyidentical(head1,head2);

	return 0;
}

//print all nodes with no sibling

#include<bits/stdc++.h>
using namespace std;
class node{
	public:
	node*left;
	node*right;
	int data;

	node(int data){
		this->left=NULL;
		this->right=NULL;
		this->data=data;
	}
};

node* createtree(string s){
	if(s=="true"){
		int d;
		cin>>d;

		node*head=new node(d);
		string l;
		cin>>l;

		head->left=createtree(l);
		string r;
		cin>>r;

		head->right=createtree(r);

		return head;
	}
	return NULL;
}

void sibling(node*head){
	if(head==NULL)return;


	if(head->left==NULL and head->right)cout<<head->right->data<<" ";
	if(head->left and !head->right)cout<<head->left->data<<" ";

	sibling(head->left);
	sibling(head->right);
}
int main(){
	node*head=createtree("true");
	sibling(head);
}

//kth largest in BST
#include<bits/stdc++.h>
using namespace std;
class node{
	public:
	node*left;
	node*right;
	int data;

	node(int data){
		this->left=NULL;
		this->right=NULL;
		this->data=data;
	}
};

void createtree(node*&head,int data){

	if(head==NULL){
		head=new node(data);
		return;
	}

	if(data<head->data){
		createtree(head->left,data);
	}

	else{
		createtree(head->right,data);
	}
}

vector<int>v;

void inorder(node*head){
	if(head==NULL)return;


	inorder(head->left);
	v.push_back(head->data);
	inorder(head->right);
}



int main(){
	node*head=NULL;

	int n;
	cin>>n;
	int m=n;
	while(n--){
		int d;
		cin>>d;
		createtree(head,d);
	}
	int k;
	cin>>k;

	inorder(head);

	cout<<v[m-k];

}
/*Root to Leaf print path ,if sum is k
Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf
path such that adding up all the values along the path equals targetSum.

A leaf is a node with no children.*/

#include<bits/stdc++.h>
using namespace std;
class node{
	public:
	node*left;
	node*right;
	int data;

	node(int data){
		this->left=NULL;
		this->right=NULL;
		this->data=data;
	}
};

node* createtree(string s){
	if(s=="true"){
		int d;
		cin>>d;

		node*head=new node(d);
		string l;
		cin>>l;

		head->left=createtree(l);
		string r;
		cin>>r;

		head->right=createtree(r);

		return head;
	}
	return NULL;
}

vector<int>v;

void roottoleafsum(node*head,int k,int sum){
	if(head==NULL)return;
	if(head->left==NULL and head->right==NULL and sum+head->data==k){
		v.push_back(head->data);
		for(auto x:v)cout<<x<<" ";//for each loop
		return;
	}



	v.push_back(head->data);
	roottoleafsum(head->left,k,sum+head->data);
	roottoleafsum(head->right,k,sum+head->data);

}

int main(){
	node*head=createtree("true");
	int k;
	cin>>k;

	roottoleafsum(head,k,0);
}

//replace each node  with sum of all elements value greater
// #include<iostream>
// using namespace std;
// class node{
// 	public:
// 	node*left;
// 	node*right;
// 	int data;
// 	node(int data){
// 		this->left=NULL;
// 		this->right=NULL;
// 		this->data=data;
// 	}
// };
// void createtree(node*&head,int data){
// 	if(head==NULL){
// 		head=new node(data);
// 		return ;
// 	}


// 	if(data<head->data){
// 		 createtree(head->left,data);

// 	}
// 	else{
// 		 createtree(head->right,data);
// 	}

// }

// int sum=0;

// void sumtree(node*head){
// 	if(head==NULL)return;


// 	sumtree(head->right);
// 	int d=head->data;
// 	head->data=sum;
// 	sum+=d;
// 	sumtree(head->left);
// }


// void print(node*head){
// 	if(head==NULL)return;


// 	if(head->left!=NULL){
// 		cout<<head->left->data<<" => ";
// 	}
// 	else{
// 		cout<<"END"<<" => ";
// 	}

// 	cout<<head->data;

// 	if(head->right!=NULL){
// 		cout<<" <= "<<head->right->data;
// 	}
// 	else{
// 		cout<<" <= "<<"END";
// 	}

// 	cout<<endl;

// 	print(head->left);
// 	print(head->right);


// }


// int main () {
// 	int n;
// 	cin>>n;
// 	node*head=NULL;
// 	for(int i=0;i<n;i++){
// 		int d;
// 		cin>>d;

// 		createtree(head,d);
// 	}

// 	sumtree(head);
// 	print(head);


// 	return 0;
// }
//code for Recursion-Codes of the string.
/*Take as input str, a string. Assume that value of a=1, b=2, c=3, d=4, …. z=26.
 Write a recursive function (return type Arraylist) to print all possible codes for the string.
 E.g. for “1123” possible codes are aabc, kbc, alc, aaw, kw.

Input Format
Enter a number

Constraints
None

Output Format
Display all the possible codes

Sample Input
1125
Sample Output
[aabe, aay, ale, kbe, ky]*/
#include<bits/stdc++.h>
using namespace std;

char arr[27]={' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
vector<string>v;

void codesofthestring(string s,int i,int n,string str){

//base case
	if(i>=n){
		v.push_back(str);

		return;
	}

		int no=s[i]-'0';

		codesofthestring(s,i+1,n,str+arr[no]);//individual

		if(i<n-1){
			no*=10;
			no+=s[i+1]-'0';

			if(no<=26){
				codesofthestring(s,i+2,n,str+arr[no]);
			}
		}




return;

}


int main() {
	string s;
	cin>>s;
	int n=s.length();

	string str="";

	codesofthestring(s,0,n,str);


	cout<<"[";
	for(int i=0;i<v.size()-1;i++){
		cout<<v[i]<<", ";
		// if(i!=v.size()-1)cout<<", ";
	}
	cout<<v[v.size()-1];
	cout<<"]";
	return 0;
}

// Partition Equal Subset Sum
/*Given a non-empty array nums containing only positive integers, find if the array can be partitioned
 into two subsets such that the sum of elements in both subsets is equal.



Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
 */

class Solution {
public:
    bool helper(vector<int>&nums,int sum,int i,int k,int n){
        //base case
        if(k==sum)return true;

        if(k>sum or i>=n)return false;


        return helper(nums,sum,i+1,k,n) || helper(nums,sum,i+1,k+nums[i],n);
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(auto x:nums){
            sum+=x;
        }
        if(sum%2!=0)return false;
        sum/=2;


        return helper(nums,sum,0,0,n);
    }
};

//Target sum
/*You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-'
before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to
build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.



Example 1:

Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3*/
class Solution {
public:
    int helper(vector<int>&nums,int n,int i,int sum,int target){
        //base case

        if(i==n){
            if(sum==target)return 1;

            return 0;
        }



        return helper(nums,n,i+1,sum+nums[i],target)+helper(nums,n,i+1,sum-nums[i],target);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return helper(nums,n,0,0,target);
    }
};

// Perfect sqaures
/*Given an integer n, return the least number of perfect square numbers that sum to n.

A perfect square is an integer that is the square of an integer; in other words,
 it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares
 while 3 and 11 are not.



Example 1:

Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.*/
class Solution {
public:

    int helper(int n){
        //base case
        if(n==0)return 0;



        int ans=INT_MAX;
        for(int i=1;i*i<=n;i++){
            ans=min(ans,helper(n-i*i));
        }

        return ans+1;

    }
    int numSquares(int n) {
          return helper(n);
    }
};



//---------------------Move all x at end------------


#include<iostream>
using namespace std;
string moveallxtoend(string s){

	//base case
	if(s.length()==0)return "";


	char ch=s[0];
	string ros=s.substr(1);
	string res=moveallxtoend(ros);//recursive call

	if(ch=='x'){
		return res+'x';//
	}
	return ch+res;



}
int main() {

	string s;
	cin>>s;

	// cout<<s.substr(1);


	cout<<moveallxtoend(s);

	return 0;
}



//---------------------------------------------Subsets--------------------------------------------
#include<iostream>
#include<vector>
using namespace std;

void subsets(int arr[],int n,int k,int i,int sum,vector<int>v){
	//base case
	if(sum==k){
		for(int i=v.size()-1;i>=0;i--){
			cout<<v[i]<<" ";
		}
		cout<<endl;
		return;
	}
	if(i>=n or sum>k)return;


	subsets(arr,n,k,i+1,sum,v);//exclude
	v.push_back(arr[i]);
	subsets(arr,n,k,i+1,sum+arr[i],v);//include

}
int main() {
	int n;
	cin>>n;

	int arr[n];

	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int k;
	cin>>k;

	vector<int>v;

	subsets(arr,n,k,0,0,v);
	return 0;
}


//------------------------------------------------------House Robber(LeetCode)-----------------------------------------
class Solution {
public:
    int helper(vector<int>&nums,int i){
        //base case
        if(i>=nums.size())return 0;


        int ans1=nums[i]+helper(nums,i+2);
        int ans2=helper(nums,i+1);

        return max(ans1,ans2);
    }
    int rob(vector<int>& nums) {
        return helper(nums,0);
    }
};
//Generate parenthesis **************************************************
/*Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.



Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]*/
#include<bits/stdc++.h>
using namespace std;

void generateparenthesis(int n,int no,int nc,string s){
	//base case

	if(nc==n){
		cout<<s<<" ";
		cout<<endl;
		return;
	}

	if(nc<no){
		generateparenthesis(n,no,nc+1,s+')');
	}
	if(no<n){
		generateparenthesis(n,no+1,nc,s+'(');
	}


}
int main(){
	int n;
	cin>>n;

	int no=0,nc=0;

	generateparenthesis(n,no,nc,"");
}

//**********************************************************
// Recursion Ascii subsequences:
/*Given a string str of length N, the task is to print all possible non-empty subsequences of the given string such that the subsequences either contains characters or ASCII value of the characters from the given string.

Examples:

Input: str = “ab”
Output: b 98 a ab a98 97 97b 9798
Explanation:
Possible subsequence of the strings are { b, a, ab }.
Possible subsequences of the string generated by including either the characters or the ASCII value of the characters from the given string are { 98, b, a, 97, ab, 97b, a98, 9798 }.
Therefore, the required output is { b, 98, a, ab, a98, 97, 97b, 9798 }.

Input: str = “a”
Output: a 97*/

#include<iostream>
using namespace std;

void codes(string s,string str,int i,int n){
	if(s[i]=='\0'){
		cout<<str<<" ";
		return;
	}

	codes(s,str,i+1,n);

	codes(s,str+s[i],i+1,n);

	codes(s,str+to_string(int(s[i])),i+1,n);
	// cout<<str;

	return;


}
int main() {

	string s;
	cin>>s;

	codes(s,"",0,s.length());
	return 0;
}


// ********************************************
// RAt chases its cheese
/*You are given an N*M grid. Each cell (i,j) in the grid is either blocked, or empty.
The rat can move from a position towards left, right, up or down on the grid.
Initially rat is on the position (1,1). It wants to reach position (N,M) where it's cheese is waiting for.
There exits a unique path in the grid . Find that path and help the rat reach its cheese.

Input Format
First line contains 2 integers N and M denoting the rows and columns in the grid.
Next N line contains M characters each. An 'X' in position (i,j) denotes that the cell is blocked and
ans 'O' denotes that the cell is empty.

Constraints
1 <= N , M <= 10

Output Format
Print N lines, containing M integers each. A 1 at a position (i,j) denotes that the (i,j)th cell is
 covered in the path and a 0 denotes that the cell is not covered in the path.
If a path does not exits then print "NO PATH FOUND"

Sample Input
5 4
OXOO
OOOX
XOXO
XOOX
XXOO
Sample Output
1 0 0 0
1 1 0 0
0 1 0 0
0 1 1 0
0 0 1 1 */
#include<bits/stdc++.h>
using namespace std;

bool flag=false;//assuming that there will be no path.

void ratchasesitscheese(vector<vector<char>>&v,vector<vector<int>>sol,int i,int j,int n,int m){

	if(i==n and j==m){//final condition
		//base case;
		sol[i][j]=1;
		for(int k=0;k<=n;k++){
			for(int l=0;l<=m;l++){
				cout<<sol[k][l]<<" ";
			}
			cout<<endl;
		}

        // cout<<"**************************************"<<endl;

        flag=true;
		return;

	}


	if(i>n or j>m or v[i][j]=='X' or i<0 or j<0){//they are leading out of the grid or barrier
		return;
	}

	sol[i][j]=1;

     if(j-1>=0 and sol[i][j-1]==0)
    ratchasesitscheese(v,sol,i,j-1,n,m);

     if(j+1<=m and sol[i][j+1]==0)
	ratchasesitscheese(v,sol,i,j+1,n,m);

    if(i+1<=n and sol[i+1][j]==0)
	ratchasesitscheese(v,sol,i+1,j,n,m);

    if(i-1>=0 and sol[i-1][j]==0)
    ratchasesitscheese(v,sol,i-1,j,n,m);






//


	sol[i][j]=0;


//
return;
}
int main() {

	int n,m;
	cin>>n>>m;

	vector<vector<char>>v(n,vector<char>(m));

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>v[i][j];
		}
	}

	vector<vector<int>>sol(n,vector<int>(m,0));

	ratchasesitscheese(v,sol,0,0,n-1,m-1);

    if(flag==false){
        cout<< "NO PATH FOUND";
    }

	return 0;
}

// Board path count
/*Take as input N, a number. N is the size of a snakes and ladder board (without any snakes and ladders).
Take as input M, a number. M is the number of faces of the dice.

a. Write a recursive function which returns the count of different ways the board can be traveled using the dice.
 Print the value returned.

b. Write a recursive function which prints dice-values for all valid paths across the board
 (void is the return type for function).

Input Format
Enter a number N (size of the board) and number M(number of the faces of a dice)

Constraints
None

Output Format
Display the number of paths and print all the paths in a space separated manner

Sample Input
3
3
Sample Output
111 12 21 3
4*/

#include<iostream>
using namespace std;

int boardpaths(int cur,int n,int faces,string str){
		//base case
		if(cur==n){
			cout<<str<<" ";
			return 1;
		}

	int count=0;
	for(int dice=1;dice<=faces and dice+cur<=n;dice++){
		count+=boardpaths(cur+dice,n,faces,str+to_string(dice));
	}

	return count;

}
int main() {
	int n;
	cin>>n;

	int faces;
	cin>>faces;

	int ans=boardpaths(0,n,faces,"");
	cout<<endl;
	cout<<ans;
	return 0;
}

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
//postfix evaluation
class Solution
{
    public:
    //Function to convert an infix expression to a postfix expression.
    int precedence(char ch){
        if(ch=='^')return 3;
        else if (ch=='/' or ch=='*')return 2;

        else if(ch=='+' || ch=='-')return 1;

        return -1;
    }

    string infixToPostfix(string s)
    {
        // Your code here

            string res="";

            stack<char>st;

            for(int i=0;i<s.length();i++){
                char ch=s[i];
                if(ch>='a' and ch<='z' || ch>='A' and ch<='Z' || ch>='0' and ch<='9'){
                    res+=ch;
                }

                else if(ch=='('){
                    st.push(ch);
                }

                else if(ch==')'){
                    while(!st.empty() and st.top()!='('){
                        res+=st.top();
                        st.pop();
                    }
                    st.pop();
                }
                else{
                    while(!st.empty() and precedence(s[i])<=precedence(st.top())){
                        res+=st.top();
                        st.pop();
                    }
                    st.push(s[i]);
                }
            }

            while(!st.empty()){
                res+=st.top();
                st.pop();
            }

            return res;

    }
};


//next greater element
#include <bits/stdc++.h>
using namespace std;

// Function to print Next Greater Element for each element of the array
void nextGreater(int arr[], int n)
{
 // Write Code here

 stack<int>s;
 vector<int>res(n);


        for(int i=0;i<n;i++){

            while(!s.empty() and arr[i]>arr[s.top()]){
                res[s.top()]=arr[i];
                s.pop();
            }

            s.push(i);
        }

        while(!s.empty()){
            res[s.top()]=-1;
            s.pop();
        }

        for(int i=0;i<n;i++){
            cout<<arr[i]<<","<<res[i]<<endl;
        }


}

// The Main Function
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        nextGreater(arr, n);
    }

	return 0;
}
//asteroid We are given an array asteroids of integers representing asteroids in a row.

/*For each asteroid, the absolute value represents its size, and the sign represents its direction
 (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet,
 the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.



Example 1:

Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.*/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& v) {
        stack<int>s;
        int n=v.size();

        for(int i=0;i<n;i++){
            if(v[i]>0 || s.empty() ){
                s.push(v[i]);
            }

            else{
                while(!s.empty() and s.top()<abs(v[i]) and s.top()>0)s.pop();

                if(!s.empty() and s.top()==abs(v[i]))s.pop();

                else{
                    if(s.empty() or s.top()<0)s.push(v[i]);
                }
            }
        }



        vector<int>res(s.size());

        for(int i=int(s.size())-1;i>=0;i--){
            res[i]=s.top();
            s.pop();
        }

        return res;




    }
};

//----------------------------------------------------Smallest distinct window------------------------------------------------------
/*Given a string 's'. The task is to find the smallest window length that contains all the characters of the given string at least one time.

Input Format
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains a string S.

Constraints
1 <= T <= 100
1 <= |S| <= 105

Output Format
For each test case in a new line print the length of the smallest such string.

Sample Input
2
aabcbcdbca
aaab
Sample Output
4
2
Explanation
Testcase 1: Smallest window size is 4 which is of "dbca" which consists all characters of the string.*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int len=INT_MAX;
		int n=s.length();

		int freq1[123]={0},fre2[123]={0};
		int count1=0,count2=0;

		for(int i=0;i<n;i++){
			freq1[s[i]]++;
			if(freq1[s[i]]==1){
				count1++;
			}
		}


		int i=0,j=0;
		while(j<n){
			fre2[s[j]]++;
			if(fre2[s[j]]==1)count2++;


			if(count1==count2){
				while(fre2[s[i]]>1){
					fre2[s[i]]--;
					len=min(len,j-i);
					i++;
				}
			}

			j++;
		}

		cout<<len<<endl;


	}
}

//--------------------------------------------------------------------Piyush and Magical Park--------------------------------------------------------
/*Piyush is lost in a magical park which contains N rows and M columns.In order to get out of park safely and return home,
 he needs atleast K amount of strength.Given a N by M pattern, your task is to find weather Piyush can ever escape the
 park.



Piyush enters the park with strength S. The park is filled with some obstacles denoted by ‘.’ ,
some magical beans denoted by ‘*’ and some blockades denoted as ‘#’. If he encounters an obstacle (.) ,
strength decreases by 2. If he encounters a magic bean (' * ') , his strength increases by 5.
Piyush can only walk row wise, so he starts from left of a row and moves towards right and he does this for every row.
However when he encounters a blockade (#) , he cannot go any further in his current row and simply jumps to the
start of a new line without losing any strength. Piyush requires a strength of 1 for every step. His strength should
always be greater than K while traversing or else Piyush will get lost. Assume that Piyush can shift immediately from
last of one row to the start of next one without loss of any strength, help out Piyush to escape the park.
His escape is successful if he is able to return home with atleast K strength.

Input Format
First line of input contains four integers – N,M,K and S. Next N lines contains M space separated
characters which can be '.', '*' or '#'.

Constraints
1 <= N,M,K,S <= 100

Output Format
Print "Yes" or "No" depending on whether Piyush can escape or not. If the answer is "Yes",
 also print the amount of strength he escaped with.

Sample Input
4 4 5 20
. . * .
. # . .
* * . .
. # * *
Sample Output
Yes
13
Explanation
Piyush starts with strength S=20.
For first row, he encounters a obstacle ‘.’ and his strength reduces by 3 ( 2+1 ( 1 for taking the step) ).
 Similarly after the second obstacle , his strength reduces by 3 again and becomes S=14.
 Then he encounters a '*' , and his strength increases by 5 but decreases by 1 for taking the step.
 Then his strength reduces by 2 (Not 3 as he will jump with no extra strength from here) after the last '.' .
 At the end of the first row his strength is S=16.

In the second row, he encounters a ‘.’ and his strength reduces by 3( 2+1 for the '.' ).
Then he encounters a '#' and without losing any extra strength simply jumps to the first cell of the next row.
Similarly, his strength at the beginning of the third row is 13 and after completing it, his strength is 16.
In the fourth row, he first encounters a '.' and his strength reduces to 13. Then he encounters a '#'
at the second position and jumps to the next row. Since this is the last row, when he jumps he escapes from the park .
His strength left is 13. Since this is clearly greater than K=5, his escape was successful.
Piyush escaped with final strength = 13.*/
#include<iostream>
using namespace std;

int main() {
	int n,m,k,s;
	cin>>n>>m>>k>>s;

	char park[n][m];

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>park[i][j];
		}
	}


	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){

			if(s<k){
				cout<<"No";
				return 0;
			}
			if(park[i][j]=='.'){
				s-=2;
			}
			else if(park[i][j]=='*'){
				s+=5;
			}
			else{
				break;
			}

			if(j!=m-1){
				s-=1;
			}
		}
	}


	if(s>=k){
		cout<<"Yes"<<endl;
		cout<<s;
	}
	else{
		cout<<"No";
	}




	return 0;
}
// ------------------------------------------------------------Diagonal Traversal-------------------------------------------------------------
/*Given an array of M x N elements (M rows, N columns), return all elements of the array in diagonal order .

Input Format
Two integers M(row) and N(column) and Second line contains N*M space separated integers denoting the elements of Array.


Constraints
The total number of elements of the given array will not exceed 10,000.

Output Format
display Diagonal

Sample Input
3 3
1 2 3 4 5 6 7 8 9
Sample Output
1 2 4 7 5 3 6 8 9 */
#include<iostream>
using namespace std;

int main() {
	int m,n;
	cin>>m>>n;

	int arr[m][n];

	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}

	int i=0,j=0;
	int count=0;
	while(i<m and j<n){
		if(count%2==0){
			cout<<arr[i][j]<<" ";
			while(i-1>=0 and j+1<n){
				i--;j++;
				cout<<arr[i][j]<<" ";
			}
			if(j+1<n){
				j++;
			}
			else{
				i++;
			}
		}else{
			cout<<arr[i][j]<<" ";
			while(i+1<m and j-1>=0){
				i++;j--;
				cout<<arr[i][j]<<" ";
			}
			if(i+1<m)i++;
			else j++;
		}
		count++;
	}


	return 0;
}

//-------------------------------------------------------------------Rotate Image!---------------------------------------------------------------
#include<iostream>
using namespace std;

int main() {
	int n;
	cin>>n;

	int arr[n][n],temp[n][n];

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
			temp[j][i]=arr[i][j];
		}
	}

	int i=0,j=n-1;//to handle the first and the last row initialli and gradually it will be incremented and decremented.

	while(i<j){
		for(int k=0;k<n;k++){
			swap(temp[i][k],temp[j][k]);
		}
		i++,j--;
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<temp[i][j]<<" ";
		}
		cout<<endl;
	}



	return 0;
}
//-------------------------------------------------------------------Maximum consecutive ones-3(Leetcode)---------------------------------------------
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int count=0,maxi=INT_MIN;

        int i=0,j=0;//2 pointers here.


        int n=nums.size();

        while(i<n){
            if(nums[i]==0)count++;//keep the track about how many zeroes we have changed

            while(count>k){//if count >k means that you have reached beyond the limit for 0's.
                if(nums[j]==0){
                    count--;
                }
                j++;
            }

            maxi=max(maxi,i-j+1);

            i++;
        }

        return maxi;

    }
};
//--------------------------------------------------Finding CB Numbers----------------------------------------------------------
/*Deepak and Gautam are having a discussion on a new type of number that they call Coding Blocks Number or CB Number.
They use following criteria to define a CB Number.

0 and 1 are not a CB number.
2,3,5,7,11,13,17,19,23,29 are CB numbers.
Any number not divisible by the numbers in point 2( Given above) are also CB numbers.
Deepak said he loved CB numbers.Hearing it, Gautam throws a challenge to him.

Gautam will give Deepak a string of digits. Deepak's task is to find the number of CB numbers in the string.

CB number once detected should not be sub-string or super-string of any other CB number.
Ex- In 4991, both 499 and 991 are CB numbers but you can choose either 499 or 991, not both.

Further, the CB number formed can only be a sub-string of the string.
Ex - In 481, you can not take 41 as CB number because 41 is not a sub-string of 481.

As there can be multiple solutions, Gautam asks Deepak to find the maximum number of CB numbers
that can be formed from the given string.

Deepak has to take class of Launchpad students. Help him by solving Gautam's challenge.

Input Format
First line contain size of the string.

Next line is A string of digits.

Constraints
1 <= Length of strings of digits <= 17

Output Format
Maximum number of CB numbers that can be formed.

Sample Input
5
81615
Sample Output
2*/
#include<bits/stdc++.h>
using namespace std;
int cbnumber[10]={2,3,5,7,11,13,17,19,23,29};//why??
bool check(long long int num){
	if(num==0 or num==1)return false;

	for(int i=0;i<10;i++){
		if(num-cbnumber[i]==0)return true;
	}


	for(int i=0;i<10;i++){
		if(num%cbnumber[i]==0)return false;
	}

	return true;
}

bool visornot(bool vis[],int s,int e){
	for(int i=s;i<e;i++){
		if(vis[i]==1)return false;
	}

	return true;
}

int main() {
	int n;
	cin>>n;

	string s;
	cin>>s;
	int count=0;

	bool vis[17];
	for(int i=0;i<17;i++)vis[i]=false;


	for(int l=1;l<=n;l++){
		for(int k=0;k<=n-l;k++){
			int end=k+l;
			string str=s.substr(k,l);

			long long int num=stoll(str);

			if(check(num) and visornot(vis,k,end)){
				count++;
				for(int i=k;i<end;i++)vis[i]=1;
			}
		}
	}


cout<<count;

	return 0;
}

//----------------------------------------------------Calculate The Sum-------------------------------------------------------------
/*Raj is a very smart kid who recently started learning computer programming. His coach gave him a cyclic array A
having N numbers, and he has to perform Q operations on this array. In each operation the coach would provide
him with a number X. After each operation, every element of the cyclic array would be replaced by the sum of
 itself and the element lying X positions behind it in the cyclic array. All these replacements take place simultaneously
 . For example, if the cyclic array was [a, b, c, d], then after the operation with X = 1,
 the new array would be [a+d, b+a, c+b, d+c]. He needs to output the sum of the elements of the final array
  modulus 10^9+7. He made a program for it but it's not very efficient.
  You know he is a beginner, so he wants you to make an efficient program for this task because he doesn't want
  to disappoint his coach.

Input Format
The first line of each test file contains a integer N. The next line contains N space separated integers
which represent the elements of the cyclic array. The third line contains a integer Q representing the number
 of operations that will be applied to the array. Finally, Q lines follow, each one containing an integer X .

Constraints
1 <= N <= 100000
1 <= Ai<= 10^9
0 <= Q <= 1000000
0 <= X < N

Output Format
Your program should output to the standard output stream the sum of the elements of the final array
 modulus 10^9+7.

Sample Input
5
1 2 3 4 5
2
1
0
Sample Output
60
Explanation
After the 1st operation (X = 1), the array would be [1+5, 2+1, 3+2, 4+3, 5+4] =[6, 3, 5, 7, 9]
After 2nd operation (X = 0), the array would be [6+6, 3+3, 5+5, 7+7, 9+9] =[12, 6, 10, 14, 18]
Thus the correct answer would equal to = (12+6+10+14+18) % (10^9+7) = 60*/
#include<iostream>
#include <math.h>
using namespace std;
int main() {
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	int q,j;
	int s=0;
	for(int i=0;i<n;i++)
{

s+=a[i];

}
	cin>>q;
	while(q--)
	{
cin>>j;
s+=s;

	}int w=s%((int)(pow(10,9)+7));
	cout<<w<<'\n';

	return 0;
}
#include<iostream>
using namespace std;
#define int long long int
int mod=1e9+7;
int32_t main() {
	int n;
	cin>>n;

	int arr[n];
	for(int i=0;i<n;i++)cin>>arr[i];

	int q;
	cin>>q;

	while(q--){
		int x;
		cin>>x;

		int temp[n]={0};

		if(x==0){
			for(int i=0;i<n;i++)temp[i]=2*arr[i];
		}else{
			temp[x]=arr[x-x]+arr[x];
			int k=x-1;
			while(k!=x){
				int index=k-x;
				if(index<0)index+=n;
				temp[k]=arr[k]+arr[index];
				k--;
				if(k<0)k=n-1;
			}
		}
		for(int i=0;i<n;i++)arr[i]=temp[i];

	}


	int sum=0;
	for(int i=0;i<n;i++){
		sum+=arr[i];
		sum=sum%mod;
	}
	cout<<sum%mod;

	return 0;
}

//----------------------------------------------------------------Custom Sort String----------------------------------------------------
/* Sort the second string in the order of the first string.

Input Format
The first string s1. The second string s2.

Constraints
The length of first string is less than 26 with non repeating characters.
The length of second string is less than 200.

Output Format
The second string sorted with context to first.

Sample Input
cba
abcd
Sample Output
cbad
Explanation
"a", "b", "c" appear in S, so the order of "a", "b", "c" should be "c", "b", and "a".

Since "d" does not appear in S, it can be at any position in T. "dcba", "cdba", "cbda" are also valid outputs.*/
#include<iostream>
using namespace std;

int main () {

	string order,s;
	cin>>order>>s;

	int freq[123]={0};


	for(int i=0;i<s.length();i++){
		int val=s[i];
		freq[val]++;
	}

	string str="";


	for(int i=0;i<order.length();i++){
		while(freq[order[i]]>0){
			str+=order[i];
			freq[order[i]]--;
		}
		freq[order[i]]=0;
	}

	for(int i=0;i<123;i++){
		while(freq[i]>0){
			str+=i;
			freq[i]--;
		}
	}

	cout<<str;

	return 0;
}

//--------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;
void dfs(vector<bool>&vis,vector<int>adj[],int cur){



    vis[cur]=1;
    for(auto x:adj[cur]){
        if(!vis[x]){
            dfs(vis,adj,x);
        }
    }
     cout<<cur<<" ";

}

int main() {
    int n,m;
    cin>>n>>m;

    vector<int>adj[n+1];

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;

        adj[a].push_back(b);
    }

    vector<bool>vis(n+1,0);
    dfs(vis,adj,0);

}

/*In a town, there are n people labeled from 1 to n. There is a rumor that one of these people is
secretly the town judge.

If the town judge exists, then:

The town judge trusts nobody.
Everybody (except for the town judge) trusts the town judge.
There is exactly one person that satisfies properties 1 and 2.
You are given an array trust where trust[i] = [ai, bi] representing that the person
labeled ai trusts the person labeled bi.

Return the label of the town judge if the town judge exists and can be identified, or return -1*/
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>indeg(n+1,0);
        vector<int>outdeg(n+1,0);

        for(auto x:trust){
            outdeg[x[0]]++;
            indeg[x[1]]++;
        }

        for(int i=1;i<=n;i++){
            if(indeg[i]==n-1 and outdeg[i]==0)return i;
        }

        return -1;
    }
};

//What is a Mother Vertex?
//A mother vertex in a graph G = (V, E) is a vertex v such that all other vertices in G can be reached by a path from v.


class Solution
{
    public:
    //Function to find a Mother Vertex in the Graph.

    void dfs(int cur,vector<bool>&vis,vector<int>adj[],int &V){

        vis[cur]=1;
        V-=1;

        for(auto x:adj[cur]){
            if(!vis[x]){
                dfs(x,vis,adj,V);
            }
        }

    }
	int findMotherVertex(int V, vector<int>adj[])
	{
	    // Code here

	    vector<bool>vis(V+1,0);
	    int no=V;

	    for(int i=0;i<=V;i++){
	        V=no;
	        dfs(i,vis,adj,V);
	        if(V==0)return i;
	    }

	    return -1;
	}

};





public:

    bool dfs(vector<bool>&vis,vector<int>adj[],int count,int cur,int N){
        vis[cur]=1;
        count++;

        if(count==N)return true;//one condition for backtrack

        for(auto x:adj[cur]){
            if(!vis[x]){
               if(dfs(vis,adj,count,x,N)) return true;
            }
        }


        //backtracking part
        vis[cur]=0;
        count--;
        return false;

    }
    bool check(int N,int M,vector<vector<int>> v)
    {
        // code here
        int count=0;
        vector<int>adj[N+1];
        for(int i=0;i<v.size();i++)
        {
            adj[v[i][0]].push_back(v[i][1]);
            adj[v[i][1]].push_back(v[i][0]);
        }

        vector<bool>vis(N+1,0);

        for(int i=0;i<=N;i++){
            if(dfs(vis,adj,count,i,N)==true)return 1;
        }

        return 0;

    }
	#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    vector<node*>v;
    int data;
    node(int data){
        this->data=data;
    }
};

node* insert(){
    int d;
    cin>>d;

    node*root=new node(d);

    int sz;
    cin>>sz;

    for(int i=0;i<sz;i++){
        (root->v).push_back(insert());
    }

    return node1;

}

void sum(node*root,int &total){
    total+=root->data;

    for(int i=0;i<(root->v).size();i++){
        sum((root->v)[i],total);
    }

}

int main() {

    node*root=insert();
    int total=0;
    sum(root,total);

    cout<<total;


}

//shortest unique prefix
/*Given an array of words, find all shortest unique prefixes to represent each word in the given array.
 Assume that no word is prefix of another.
Examples:


Input: arr[] = {"zebra", "dog", "duck", "dove"}
Output: dog, dov, du, z
Explanation: dog => dog
             dove => dov
             duck => du
             zebra => z*/
#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    node* arr[26];
    int count;

    node(){
        this->count=0;
        for(int i=0;i<26;i++){
            arr[i]=NULL;
        }
    }
};


void insert(node*root,string s){
    for(int i=0;i<s.length();i++)
    {
        if(!root->arr[s[i]-'a']){
            root->arr[s[i]-'a']=new node();

        }
        root->count++;
        root=root->arr[s[i]-'a'];
    }
}

int shortestprefix(node*root,string s){
    for(int i=0;i<s.length();i++){
        root=root->arr[s[i]-'a'];
        if(root->count==1)return i;
    }

    return s.length();
}


int main() {
    int n;
    cin>>n;
    vector<string>v(n);
    node*root=new node();
    for(int i=0;i<n;i++){
        cin>>v[i];
    insert(root,v[i]);
    }

    for(auto x:v){
        int k=shortestprefix(root,x);
        cout<<x.substr(0,k+1)<<" ";
    }


}

/*Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i]
 is the number of 1's in the binary representation of i.



Example 1:

Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10*/
//counting bits
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>dp(n+1,0);

        if(n==0){
            dp[0]=0;
            return dp;
        }
        else if(n==1){
            dp[0]=0;
            dp[1]=1;
            return dp;
        }
        else if(n==2){
            dp[0]=0;
            dp[1]=1;
            dp[2]=1;
            return dp;
        }
        dp[0]=0;
            dp[1]=1;
            dp[2]=1;


        for(int i=3;i<=n;i++){
            int ones=0;
            int k=i;
            while(k){
                if(k&1)ones++;

                k=k>>1;
                if(dp[k]!=-1)break;
            }

            dp[i]=dp[k]+ones;
        }

        return dp;
    }
};
/*You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the
 width and the height of an envelope.

One envelope can fit into another if and only if both the width and height of one envelope are greater
than the other envelope's width and height.

Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).

Note: You cannot rotate an envelope.



Example 1:

Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
Output: 3
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
Example 2:

Input: envelopes = [[1,1],[1,1],[1,1]]
Output: 1*/
//russian doles
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& v) {
        int n=v.size();
        sort(v.begin(),v.end());

        vector<int>dp(n,1);

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(v[j][0]<v[i][0] and v[j][1]<v[i][1]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }



        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,dp[i]);
        }


        return maxi;



    }
};

// minimum cost minCostClimbingStairs
/*You are given an integer array cost where cost[i] is the cost of ith step on a staircase.
 Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.



Example 1:

Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.*/
class Solution {
public:
    int helper(vector<int>&cost,int i,vector<int>&dp){

        if(i>=cost.size())return 0;

        if(dp[i]!=-1)return dp[i];


        return dp[i]=cost[i]+min(helper(cost,i+1,dp),helper(cost,i+2,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {

        int n=cost.size();

        vector<int>dp(n,-1);

        return min(helper(cost,0,dp),helper(cost,1,dp));
    }
};
/*. Maximum Product of Two Elements in an Array
Given the array of integers nums, you will choose two different indices i and j of that array.
 Return the maximum value of (nums[i]-1)*(nums[j]-1).


Example 1:

Input: nums = [3,4,5,2]
Output: 12
Explanation: If you choose the indices i=1 and j=2 (indexed from 0), you will get the maximum value,
that is, (nums[1]-1)*(nums[2]-1) = (4-1)*(5-1) = 3*4 = 12.
Example 2:

Input: nums = [1,5,4,5]
Output: 16
Explanation: Choosing the indices i=1 and j=3 (indexed from 0), you will get the maximum value of (5-1)*(5-1) = 16.
Example 3:

Input: nums = [3,7]
Output: 12*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int>pq;

        for(auto x:nums){
            pq.push(x);
        }

        int x=pq.top();
        pq.pop();
        int y =pq.top();
        pq.pop();

        return (x-1)*(y-1);
    }
};

/*Last Stone Weight
You are given an array of integers stones where stones[i] is the weight of the ith stone.

We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash them together. Suppose the heaviest two stones have weights x and y with x <= y. The result of this smash is:

If x == y, both stones are destroyed, and
If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
At the end of the game, there is at most one stone left.

Return the weight of the last remaining stone. If there are no stones left, return 0.



Example 1:

Input: stones = [2,7,4,1,8,1]
Output: 1*/
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;

        for(auto x:stones){
            pq.push(x);
        }

        while(pq.size()>1){
            int x=pq.top();
            pq.pop();
            int y=pq.top();
            pq.pop();

            if(x==y)continue;

            pq.push(x-y);
        }


        return pq.size()!=0?pq.top():0;
    }
};
//K Closest Points to Origin

class Solution {
public:
    #define node pair<int,pair<int,int>>
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<node,vector<node>,greater<node>>pq;

        for(auto x:points){
            int dis=(x[0])*(x[0])+(x[1])*(x[1]);

            pq.push({dis,{x[0],x[1]}});
            // pq.push(make_pair(dis,make_pair(x[0],x[1])));
        }


        vector<vector<int>>v;

        while(!pq.empty() and k--){

            node n=pq.top();
            pq.pop();
            vector<int>d;
            d.push_back(n.second.first);
            d.push_back(n.second.second);

            v.push_back(d);
        }




        return v;



    }
};
//
#include<bits/stdc++.h>
using namespace std;
#define int long long int
int32_t main() {
	priority_queue<int>pq;

		int q,k;
		cin>>q>>k;
		while(q--){

		int d;
		cin>>d;

		if(d==2){

			while(pq.size()>k){
				pq.pop();
			}
			cout<<pq.top()<<endl;
		}
		else{

			int x,y;
			cin>>x>>y;

			int dis=pow(x,2)+pow(y,2);
			pq.push(dis);
		}

	}

	return 0;
}
//k pairs with smallest sum
// Given two integer arrays arr1[] and arr2[] sorted in ascending order
// and an integer k. Find k pairs with smallest sums such that one element of a
//pair belongs to arr1[] and other element belongs to arr2[]
Examples:
class Solution {
public:
    #define node pair<int,pair<int,int>>
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<node,vector<node>,greater<node>>pq;

        int s1=nums1.size();
        int s2=nums2.size();

        int m=min(s1,k);
        int n=min(s2,k);

        int count=0;
        vector<vector<int>>v;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                // count++;
                // if(count>k)break;
                int res=nums1[i]+nums2[j];
                pq.push({res,{nums1[i],nums2[j]}});

                // vector<int>d;
                // d.push_back(nums1[i]);
                // d.push_back(nums2[j]);
                // v.push_back(d);



            }
        }

        while(k-- and !pq.empty()){
            node n=pq.top();
            pq.pop();


            vector<int>d;
                d.push_back(n.second.first);
                d.push_back(n.second.second);
                v.push_back(d);


        }



        return v;
    }
};
