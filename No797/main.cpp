#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> path;
    vector<vector<int>> ans,g;
    vector<bool> vis;
    int n;
public:
    void dfs(int u){
        if (u==n){
            ans.push_back(path);
            return;
        }
        for (int& v:g[u]){
            if (vis[v]) continue;
            vis[v]=1;
            path.push_back(v);
            dfs(v);
            path.pop_back();
            vis[v]=0;
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        g=graph;
        n=graph.size()-1;
        vis.resize(n+1);
        path.push_back(0);
        dfs(0);
        return ans;
    }
};

signed main(){
    vector<vector<int>> graph={{1,2},{3},{3},{}};
    Solution* sol=new Solution();
    vector<vector<int>> ans=sol->allPathsSourceTarget(graph);
    for (auto& row:ans){
        for (auto& p:row)
            cout<<p<<' ';
        cout<<endl;
    }

    return 0;
}