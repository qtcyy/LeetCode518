#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSegments(string s) {
        int n=s.length();
        if (n==0)
            return 0;
        int ans=0;
        for (int i=1;i<n;i++){
            if (s[i]==' ' && s[i-1]!=' ')
                ans++;
        }
        if (s[n-1]!=' ') ans++;
        return ans;
    }
};

signed main(){
    Solution* sol=new Solution();
    string s="Hello, my name is John";
    cout<<sol->countSegments(s)<<endl;

    return 0;
}