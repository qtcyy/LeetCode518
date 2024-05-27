#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> edge(n);
        for (auto& row:paths){
            edge[row[0]-1].emplace_back(row[1]-1);
            edge[row[1]-1].emplace_back(row[0]-1);
        }
        vector<int> ans(n);
        for (int i=0;i<n;i++){
            vector<int> colored(5,false);
            for (auto& v:edge[i])
                colored[ans[v]]=1;
            for (int j=1;j<=4;j++)
                if (!colored[j]){
                    ans[i]=j;
                    break;
                }
        }
        return ans;
    }
};

signed main(){
    vector<vector<int>> paths={{1,2},{2,3},{3,1}};
    Solution* sol=new Solution();
    vector<int> ans=sol->gardenNoAdj(3,paths);
    for (int& p:ans)
        cout<<p<<' ';
    cout<<endl;

    return 0;
}