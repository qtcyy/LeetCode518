#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        for (int& p:nums1)
            if (p%k)
                p=-1;
            else
                p/=k;
        unordered_map<int, int> freq;
    
    // 计算 nums2 中每个数的频率
    for (int num : nums2) {
        freq[num]++;
    }

    long long count = 0;

    for (int num : nums1) {
        for (int j = 1; j * j <= num; ++j) {
            if (num % j == 0) {
                if (freq.find(j) != freq.end()) {
                    count += 1ll*freq[j];
                }
                if (j != num / j && freq.find(num / j) != freq.end()) {
                    count += 1ll*freq[num / j];
                }
            }
        }
    }

    return count;
    }
};

signed main(){
    Solution* sol=new Solution();
    vector<int> nums1={1,3,4},nums2={1,3,4};
    cout<<sol->numberOfPairs(nums1,nums2,1)<<endl;

    return 0;
}