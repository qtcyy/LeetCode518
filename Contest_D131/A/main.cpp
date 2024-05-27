#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_map<int,int> mp;
        for (auto& p:nums)
            mp[p]++;
        int ans=0;
        for (auto& [num,times]:mp){
            if (times==2)
                ans^=num;
        }
        
        return ans;
    }
};

signed main(){
    vector<int> nums={1,2,2,1};
    Solution* sol=new Solution();
    cout<<sol->duplicateNumbersXOR(nums)<<endl;

    return 0;
}