#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> st;
        for (int& p:nums)
            st.insert(p);
        if (st.size()<3)
            return *st.end();
        auto it=st.end();
        it--;it--;it--;
        return *it;
    }
};

signed main(){
    Solution* sol=new Solution();
    vector<int> nums={1,2};
    cout<<sol->thirdMax(nums)<<endl;

    return 0;
}