#include<bits/stdc++.h>
using namespace std;

vector<int> bfs(int num, vector<vector<int>>&adj, int start){
    queue<int>q;
    vector<bool>vis(num, false);
    vector<int>res;

    vis[start] = true;
    q.push(start);
    res.push_back(start);

    while(!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (int n = 0; n < num; n++) {
            if (adj[curr][n] == 1 && !vis[n]) {
                vis[n] = true;
                q.push(n);
                res.push_back(n);
            }
        }
    }
    return res;
}

void printvector(vector<int>&ans)
{
    for(auto n : ans)
        cout<<n<<"  ";

    cout<<endl;
}

int main(){
    int num = 0;
    cout<<"Enter number of nodes in graph : ";
    cin>>num;
    vector<vector<int>> adjmat(num, vector<int>(num, 0));

    cout << "Enter Adjacency matrix: \n";
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            cin >> adjmat[i][j];
        }
    }

    vector<int> ans = bfs(num, adjmat, 0);
    cout<<endl<<"BFS Traversal : ";
    printvector(ans);
    return 0;
}