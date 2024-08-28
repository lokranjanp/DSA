#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>&nums, int left, int mid, int right)
{
    vector<int>temp;
    int low = left;
    int high = mid+1;

    while(low<=mid && high<=right)
    {
        if(nums[low] <= nums[high])
        {
            temp.push_back(nums[low]);
            low++;
        }
        else
        {
            temp.push_back(nums[high]);
            high++;
        }
    }

    while(low<=mid){
        temp.push_back(nums[low]);
        low++;
    }

    while(high<=right){
        temp.push_back(nums[high]);
        high++;
    }

    for(int i = left; i<=right; i++)
        nums[i] = temp[i-left];
}

void mergesort(vector<int>&nums, int low, int high)
{
    if(low>=high)
        return;

    int mid = low + (high - low)/2;
    mergesort(nums, low, mid);
    mergesort(nums, mid+1, high);
    merge(nums, low, mid, high);
}


int main()
{
    vector<int>nums = {7, 6, 9, 2, 0, 11, 10, 3, 5, 1};
    int n = nums.size();
    mergesort(nums, 0, n-1);
    for(int n : nums)
        cout<<n<<"  ";

    cout<<endl;
    return 0;
}