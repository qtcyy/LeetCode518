#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    struct node{
        int s,to,next;
    };
    node que[205];
    
    int head[205],cnt=0,N;
    inline void add(int u,int v,int w){
        que[cnt].s=w;
        que[cnt].to=v;
        que[cnt].next=head[u];
        head[u]=cnt++;
    }

    void dijkstra(int s){
        vector<int> dis(N+1,0x3f3f3f3f);
        vector<bool> vis(N+1,false);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.emplace(0,s);
        dis[s]=0;
        while (!q.empty()){
            
        }
    }
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        memset(head,-1,sizeof(head));
        N=n;
        for (auto& row:redEdges){
            add(row[0],row[1],0);
            add(row[1],row[0],0);
        }
        for (auto& row:blueEdges){
            add(row[0],row[1],1);
            add(row[1],row[0],1);
        }
        dijkstra(0);
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