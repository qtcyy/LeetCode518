#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for (auto& num:nums){
            if (mp.find(num)==mp.end())
                mp[num]=1;
            else
                mp[num]++;
        }
        vector<pair<int,int>> res;
        for (auto& [num,times]:mp)
            res.emplace_back(times,num);
        sort(res.begin(),res.end(),[](const auto& p1,const auto& p2){
            return p1.first>p2.first || (p1.first==p2.first && p1.second<p2.second);
        });
        vector<int> ans;
        for (int i=0;i<k;i++)
            ans.emplace_back(res[i].second);
        return ans;
    }
};

signed main(){
    vector<int> nums={1,1,1,2,2,3};
    int k=2;
    Solution *sol=new Solution();
    vector<int> ans=sol->topKFrequent(nums,k);
    for (auto& p:ans)
        cout<<p<<' ';
    cout<<endl;

    return 0;
}