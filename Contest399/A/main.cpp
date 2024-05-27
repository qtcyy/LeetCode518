#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size(),m=nums2.size();
        int sum=0;
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                if (nums1[i]%(nums2[j]*k)==0)
                    sum++;
        return sum;
    }
};

signed main(){
    vector<int> nums1={1,3,4},nums2={1,3,4};
    Solution* sol=new Solution;
    cout<<sol->numberOfPairs(nums1,nums2,1)<<endl;

    return 0;
}