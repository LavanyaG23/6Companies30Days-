
//LEETCODE 216. Combination Sum III

/*Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, and the 
combinations may be returned in any order.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int k, int n, vector<vector<int>>&ans, vector<int>&ans1, int s){
        if(n==0 && k==0){
            ans.push_back(ans1);
            return;
        }
        if(n==0) return;
        if(k==0) return;
        for(int i=s; i<=9; i++){
            ans1.push_back(i);
            solve(k-1,n-i,ans,ans1,i+1);
            ans1.pop_back();
        }

    }


    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>ans1;
        if(k>=n || n==1) return ans;
        solve(k,n,ans,ans1,1);
        return ans;
    }
};

 



