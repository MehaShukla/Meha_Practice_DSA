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