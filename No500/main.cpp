#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string line1="qwertyuiop",
                line2="asdfghjkl",
                line3="zxcvbnm";
        unordered_map<char,int> mp;
        for (char& c:line1)
            mp[c]=1;
        for (char& c:line2)
            mp[c]=2;
        for (char& c:line3)
            mp[c]=3;
        vector<string> ans;
        for (auto& p:words){
            string str=p;
            transform(str.begin(),str.end(),str.begin(),::tolower);
            int flag=mp[str[0]];
            for (int i=1;i<str.size();i++)
                if (flag!=mp[str[i]]){
                    flag=0;
                    break;
                }
            if (flag)
                ans.push_back(p);
        }
        return ans;
    }
};

signed main(){
    vector<string> words={"omk"};
    Solution* sol=new Solution;
    for (auto& str:sol->findWords(words))
        cout<<str<<endl;

    return 0;
}