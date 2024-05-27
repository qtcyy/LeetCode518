#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestWord(vector<string>& words) {
        vector<string> res;
        int maxn=0;
        for (auto& word:words){
            if (word.size()>maxn){
                res.clear();
                maxn=word.size();
                res.emplace_back(word);
            }
            else if (word.size()==maxn){
                res.emplace_back(word);
                cout<<word<<' ';
            }
        }
        cout<<endl;
        sort(res.begin(),res.end());
        for (auto& s:res)
            cout<<s<<' ';
        return res[0];
    }
};

signed main(){
    Solution *sol=new Solution();
    vector<string> words={"a","banana","app","appl","ap","apply","apple"};
    cout<<sol->longestWord(words)<<endl;

    return 0;
}