#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        //(1+k)*k=2*n;
        if (n==1)
            return 1;
        long long l=1,r=n;
        while (l<r){
            long long mid=(l+r)>>1;
            if ((1+mid)*mid<=2ll*n)
                l=mid+1;
            else
                r=mid;
        }
        return l-1;
    }
};

signed main(){
    Solution* sol=new Solution();
    cout<<sol->arrangeCoins(1804289383)<<endl;

    return 0;
}