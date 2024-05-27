#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool> vis(n,false);
        queue<int> q;
        q.push(0);
        while (!q.empty()){
            int u=q.front();q.pop();
            if (vis[u]) continue;
            vis[u]=1;
            for (int& v:rooms[u])
                q.push(v);
        }
        for (int i=1;i<n;i++)
            if (!vis[i])
                return false;
        return true;
    }
};

signed main(){
    vector<vector<int>> rooms={{1},{2},{3},{}};
    Solution* sol=new Solution();
    cout<<sol->canVisitAllRooms(rooms)<<endl;

    return 0;
}