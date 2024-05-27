#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
        const int MOD = 1e9+7;
        int n = nums.size();
        vector<long long> dp(n, 0);
        long long ans = 0;

        // 初始化 dp 数组
        if (n > 0) dp[0] = max(0, nums[0]);
        if (n > 1) dp[1] = max({dp[0], (long long)nums[1], 0LL});
        for (int i = 2; i < n; ++i) {
            dp[i] = max(dp[i-1], dp[i-2] + max(0, nums[i]));
        }

        // 处理每个查询
        for (auto& query : queries) {
            int index = query[0];
            int value = query[1];

            // 更新 nums
            nums[index] = value;

            // 从 index 开始更新 dp
            if (index<=2){
                dp[0]=(nums[0]>0?nums[0]:0);
            dp[1]=max(1ll*(nums[1]>0?nums[1]:0),dp[0]);}
            else if (index < n) dp[index] = (index > 0 ? max(dp[index-1], (index > 1 ? dp[index-2] : 0) + max(0, value)) : max(0, value));

            for (int i = max(index + 1,2); i < n; ++i) {
                dp[i] = max(dp[i-1], dp[i-2] + max(0, nums[i]));
            }

            // 累加到最终结果
            ans = (ans + dp[n-1]) % MOD;
        }

        return ans;
    }
};

int main() {
    vector<int> nums={7,3,-7,2,-6,6,4};vector<vector<int>> queries={{0,5},{1,6},{5,-4},{6,5},{0,-4},{6,4},{4,3},{0,-2},{3,-7}};
    
    Solution sol;
    cout << sol.maximumSumSubsequence(nums, queries) << endl;
    return 0;
}
