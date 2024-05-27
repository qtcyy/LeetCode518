#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> in(n+1),out(n+1);
        for (auto& row:trust){
            out[row[0]]++;
            in[row[1]]++;
        }
        for (int i=1;i<=n;i++)
            if (!out[i] && in[i]==n-1)
                return i;
        return -1;
    }
};

signed main(){
    Solution* sol=new Solution();
    vector<vector<int>> trust={{1,3},{2,3}};
    cout<<sol->findJudge(3,trust)<<endl;

    return 0;
}