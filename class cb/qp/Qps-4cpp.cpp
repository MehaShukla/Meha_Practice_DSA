
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
