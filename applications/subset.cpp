#include<bits/stdc++.h>
using namespace std;

bool helper(int i, vector<int>&nums, int target, vector<vector<int>>&dp)
{
    if (target == 0)
        return true;

    if (i == 0)
        return nums[i] == target;

    if(i<0 || target<0)
        return false;

    if(dp[i][target] != -1)
        return dp[i][target];

    bool pick = false;
    if(target >= nums[i])
        pick = helper(i-1, nums, target-nums[i], dp);
    bool skip = helper(i-1, nums, target, dp);

    return dp[i][target] = pick || skip;
}

bool subsetsum(vector<int>&nums, int target)
{
    int n = nums.size();
    vector<vector<int>>dp(n, vector<int>(target+1, -1));
    return helper(n-1, nums, target, dp);
}

int main(){
    vector<int>nums = {2, 3, 4, 5, 1, 6};
    int target_sum = 9;

    bool found = subsetsum(nums, target_sum);

    if(found)
        cout<<"Subset with sum "<<target_sum<<" found"<<endl;
    else
        cout<<"Subset with sum "<<target_sum<<" not found"<<endl;

    return 0;
}