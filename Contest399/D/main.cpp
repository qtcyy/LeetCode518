#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
        const int MOD = 1e9+7;
        long long ans=0;
        int n=nums.size();
        if (n==1){
            for (auto& rows:queries){
                ans=(ans+(rows[1]>0?rows[1]:0))%MOD;
            }
            return ans;
        }
        long long dp[50005];
        for (auto& rows:queries){
            nums[rows[0]]=rows[1];
            memset(dp,0,sizeof(dp));
            dp[0]=(nums[0]>0?nums[0]:0);
            dp[1]=max(1ll*(nums[1]>0?nums[1]:0),dp[0]);
            for (int i=2;i<n;i++){
                if (nums[i]>0)
                    dp[i]=max(dp[i-2]+nums[i],dp[i-1]);
                else
                    dp[i]=max(dp[i-1],dp[i-2]);
            }
            ans=(ans+dp[n-1])%MOD;
        }
        return ans;
    }
};

signed main(){
    vector<int> nums={7,3,-7,2,-6,6,4};vector<vector<int>> queries={{0,5},{1,6},{5,-4},{6,5},{0,-4},{6,4},{4,3},{0,-2},{3,-7}};
    Solution* sol=new Solution();
    cout<<sol->maximumSumSubsequence(nums,queries)<<endl;

    return 0;
}