#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> book(20005,0);
        for (auto& num:nums)
            book[num+10000]++;
        int i=20000;
        for (;i>=0;i--){
            if ((k-=book[i],k)<=0)
                break;
        }
        return i-10000;
    }
};

signed main(){
    vector<int> nums={3,2,1,5,6,4};
    Solution* sol=new Solution();
    cout<<sol->findKthLargest(nums,2)<<endl;

    return 0;
}