#include<bits/stdc++.h>
using namespace std;

int linearsearch(vector<int>&nums, int key){
    for(int i = 0; i<nums.size(); ++i)
        if(nums[i] == key)
            return i;

    return -1;
}

int binarysearch(vector<int>&nums, int key){
    int low = 0, high = nums.size()-1;

    while(low<=high){
        int mid = low + (high-low)/2;

        if(nums[mid]<key)
            low = mid+1;

        if(nums[mid]>key)
            high = mid-1;

        else if(nums[mid] == key)
            return mid;
    }

    return -1;
}

int main(){
    int size = 0;
    cout<<"enter size of array : ";
    cin>>size;

    vector<int>nums(size);
    cout<<"Enter the elements of the array : ";
    for(int i = 0; i<size; ++i)
        cin>>nums[i];

    int searchval = -1;
    cout<<"Enter value to be searched : ";
    cin>>searchval;
    cout<<binarysearch(nums, searchval)<< endl;
}