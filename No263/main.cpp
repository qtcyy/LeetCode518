#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isUgly(int n) {
        if (n<=0)
            return false;
        vector<int> fact={2,3,5};
        for (int& p:fact){
            while (n%p==0)
                n/=p;
        }
        return n==1;
    }
};

signed main(){
    Solution* sol=new Solution();
    cout<<sol->isUgly(14)<<endl;

    return 0;
}