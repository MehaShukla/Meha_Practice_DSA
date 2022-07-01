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