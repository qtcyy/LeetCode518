#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),[](const auto& p1,const auto& p2){
            return p1[0]>p2[0] || (p1[0]==p2[0] && p1[1]<p2[1]);
        });
        vector<vector<int>> ans;
        for (auto& row:people){
            ans.insert(ans.begin()+row[1],row);
        }
        return ans;
    }
};

signed main(){
    vector<vector<int>> people={{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
    Solution *sol=new Solution();
    vector<vector<int>> ans=sol->reconstructQueue(people);
    for (auto& row:ans){
        for (auto& i:row)
            cout<<i<<' ';
        cout<<endl;
    }

    return 0;
}