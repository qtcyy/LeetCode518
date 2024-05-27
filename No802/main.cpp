#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<int>> edge;
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        edge.resize(n);
        vector<int> in(n),out(n);
        for (int i=0;i<n;i++)
            for (int& p:graph[i]){
                edge[p].push_back(i);
                in[i]++;out[p]++;
            }
        set<int> st;
        for (int i=0;i<n;i++){
            if (!in[i]){
                st.insert(i);
                for (auto& p:edge[i])
                    if (in[p]==1)
                        st.insert(p);
            }
        }
        vector<int> ans;
        for (auto& p:st)
            ans.push_back(p);
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