#include<bits/stdc++.h>
using namespace std;

int linearsearch(vector<int>&nums, int key){
    for(int i = 0; i<nums.size(); ++i)
        if(nums[i] == key)
            return i;

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
    cout<<linearsearch(nums, searchval)<< endl;
}