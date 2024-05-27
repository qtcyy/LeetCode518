#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct node{
        int s,to,next;
    };
    node que[6005];

    int head[105],dis[105];
    bool vis[105];
    int cnt=1;

    inline void add(int u,int v,int w){
        que[cnt].s=w;
        que[cnt].to=v;
        que[cnt].next=head[u];
        head[u]=cnt++;
    }

    void dijstra(int s){
        memset(dis,0x3f,sizeof(dis));
        memset(vis,false,sizeof(vis));
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        dis[s]=0;
        q.emplace(0,s);
        while (!q.empty()){
            int u=q.top().second;q.pop();
            if (vis[u]) continue;
            vis[u]=1;
            for (int i=head[u];i!=-1;i=que[i].next){
                int v=que[i].to;
                if (dis[v]>dis[u]+que[i].s){
                    dis[v]=dis[u]+que[i].s;
                    q.emplace(dis[v],v);
                }
            }
        }
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        memset(head,-1,sizeof(head));
        for (auto& e:times)
            add(e[0],e[1],e[2]);
        dijstra(k);
        int maxn=0;
        for (int i=1;i<=n;i++)
            maxn=max(maxn,dis[i]);
        if (maxn==0x3f3f3f3f)
            return -1;
        else
            return maxn;
    }
};

signed main(){
    Solution* sol=new Solution();
    vector<vector<int>> times={{2,1,1},{2,3,1},{3,4,1}};
    cout<<sol->networkDelayTime(times,4,2)<<endl;

    return 0;
}