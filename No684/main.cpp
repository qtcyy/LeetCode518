#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int f[100005];
public:
    inline int find(int x){
        if (f[x]==x) return x;
        return f[x]=find(f[x]);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for (int i=0;i<=edges.size();i++)
            f[i]=i;
        vector<int> ans;
        for (auto& row:edges){
            auto [x,y]=make_pair(row[0],row[1]);
            int tx=find(x),ty=find(y);
            if (tx==ty){
                ans.emplace_back(x);ans.emplace_back(y);
                break;
            }
            f[tx]=ty;
            find(ty);
        }
        return ans;
    }
};

signed main(){
    vector<vector<int>> edges={{1,2},{2,3},{3,4},{1,4},{1,5}};
    Solution *sol=new Solution();
    vector<int> ans=sol->findRedundantConnection(edges);
    for (auto& p:ans)
        cout<<p<<' ';
    cout<<endl;
    return 0;
}