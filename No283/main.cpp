#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.size()==0)
            return;
        int j=0;
        for (int i=0;i<nums.size();i++)
            if (nums[i]!=0)
                nums[j++]=nums[i];
        for (int i=j;i<nums.size();i++)
            nums[i]=0;
        return;
    }
};

signed main(){
    Solution* sol=new Solution();
    vector<int> nums={{0,1,0,3,12}};
    sol->moveZeroes(nums);
    for (int& p:nums)
        cout<<p<<' ';
    cout<<endl;

    return 0;
}