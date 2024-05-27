#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> st;
        for (int& p:nums)
            st.insert(p);
        vector<int> ans;
        for (int i=1;i<=n;i++)
            if (st.find(i)==st.end())
                ans.push_back(i);
        return ans;
    }
};

signed main(){
    vector<int> nums={1,1};
    Solution* sol=new Solution();
    for (auto& p:sol->findDisappearedNumbers(nums))
        cout<<p<<' ';
    cout<<endl;

    return 0;
}