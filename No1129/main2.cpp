#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<vector<int>>> edge(2,vector<vector<int>>(n));
        for (auto& row:redEdges)
            edge[0][row[0]].push_back(row[1]);
        for (auto& row:blueEdges)
            edge[1][row[0]].push_back(row[1]);
        vector<vector<int>> dis(2,vector<int>(n,INT_MAX));
        queue<pair<int,int>> q;
        dis[0][0]=0;
        dis[1][0]=0;
        q.push({0,0});q.push({0,1});
        while (!q.empty()){
            auto [u,color]=q.front();q.pop();
            for (auto v:edge[1-color][u]){
                if (dis[1-color][v]!=INT_MAX) continue;
                dis[1-color][v]=dis[color][u]+1;
                q.push({v,1-color});
            }
        }
        vector<int> ans(n);
        for (int i=0;i<n;i++){
            ans[i]=min(dis[0][i],dis[1][i]);
            if (ans[i]==INT_MAX) ans[i]=-1;
        }
        return ans;
    }
};

signed main(){
    int n=3;
    vector<vector<int>> redEdge={{0,1}},blueEdge={{2,1}};
    Solution* sol=new Solution();
    vector<int> ans=sol->shortestAlternatingPaths(n,redEdge,blueEdge);
    for (int& p:ans)
        cout<<p<<' ';
    cout<<endl;

    return 0;
}