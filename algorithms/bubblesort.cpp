#include<bits/stdc++.h>
using namespace std;

vector<int> bubblesort(vector<int>&arr)
{
    int n = arr.size();

    for(int i = 0; i<n; i++)
    {
        for(int j = i+1; j<n; j++)
        {
            if(arr[i]>arr[j])
                swap(arr[i], arr[j]);
        }
    }

    return arr;
}

int main()
{
    vector<int>nums = {7, 6, 9, 2, 0, 11, 10, 3, 5, 1};

    vector<int>ans = bubblesort(nums);
    for(int n : ans)
        cout<<n<<"  ";

    cout<<endl;
    return 0;
}