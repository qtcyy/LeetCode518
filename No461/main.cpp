#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans=0;
        while (x || y){
            ans+=(x&1)^(y&1);
            x>>=1;y>>=1;
        }
        return ans;
    }
};

signed main(){
    Solution* sol=new Solution();
    cout<<sol->hammingDistance(3,1)<<endl;

    return 0;
}