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