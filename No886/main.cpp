#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> f;
    inline int find(int x){
        if (f[x]==x) return x;
        return f[x]=find(f[x]);
    }
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        f.resize(n+1);
        iota(f.begin(),f.end(),0);
        for (auto& row:dislikes){
            int x=find(row[0]),y=find(row[1]);
            if (x!=y)
                f[x]=y;
            else
                return false;
        }

        return true;
    }
};

signed main(){
    vector<vector<int>> dislikes={{1,2},{1,3},{2,4}};
    Solution* sol=new Solution();
    cout<<sol->possibleBipartition(4,dislikes)<<endl;

    return 0;
}