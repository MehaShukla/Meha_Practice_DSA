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