#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0,maxn=0;
        if (nums.size()==1)
            return nums[0];
        bool flag=false;
        for (int i=0;i<nums.size()-1;i++){
            if (nums[i]==1 || nums[i+1]==1)
                flag=true;
            if (nums[i]==1 && nums[i+1]==1)
                ans++;
            else
                ans=0;
            maxn=max(maxn,ans);
        }
        return maxn+flag;
    }
};

signed main(){
    Solution* sol=new Solution();
    vector<int> nums={1,0,1,1,0,1};
    cout<<sol->findMaxConsecutiveOnes(nums)<<endl;

    return 0;
}