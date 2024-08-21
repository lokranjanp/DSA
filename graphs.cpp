#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<bool>&vis, vector<int>&ans, vector<vector<int>>&adjmat){
    vis[node] = true;
    ans.push_back(node);

    for(int i = 0; i<vis.size(); ++i)
    {
        if(adjmat[node][i]==1 && !vis[i])
            dfs(i, vis, ans, adjmat);
    }
}

vector<int> dfstrav(int N, vector<vector<int>>&adjmat, int start){
    vector<bool> vis(N, false);
    vector<int>ans;
    int startnode = start;

    dfs(startnode, vis, ans, adjmat);
    return ans;
}


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

    vector<int> ans = dfstrav(num, adjmat, 0);
    cout<<endl<<"DFS Traversal : ";
    printvector(ans);
    return 0;
}