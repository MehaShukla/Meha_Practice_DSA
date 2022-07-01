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

		if(i+1<n){
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

