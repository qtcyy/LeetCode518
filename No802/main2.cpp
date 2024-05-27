#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> in(n),out(n);
        for (int i=0;i<n;i++)
            for (auto& p:graph[i])
                out[i]++,in[p]++;

        vector<int> ans;
        for (int i=0;i<n;i++){
            if (!out[i]){ans.push_back(i);continue;};
            bool flag=true;
            for (auto& p:graph[i])
                if (in[p]){
                    flag=false;break;
                }
            if (flag)
                ans.push_back(i);
        }
        return ans;
    }
};

signed main(){
    vector<vector<int>> graph={{},{0,2,3,4},{3},{4},{}};
    Solution* sol=new Solution();
    vector<int> ans=sol->eventualSafeNodes(graph);
    for (int& p:ans)
        cout<<p<<' ';
    cout<<endl;

    return 0;
}