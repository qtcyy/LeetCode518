#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findComplement(int num) {
        int k=0;
        while (num>>++k);
        long long Xor=(1ll<<k)-1;
        return Xor^(1ll*num);
    }
};

signed main(){
    int num=2147483647;
    Solution* sol=new Solution();
    cout<<sol->findComplement(num)<<endl;

    return 0;
}