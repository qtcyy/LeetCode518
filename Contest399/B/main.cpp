#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string compressedString(string word) {
        string res;
        int n=word.length(),count=1;
        for (int i=0;i<n-1;i++){
            if (word[i]==word[i+1])
                count++;
            else{
                if (count<=9){
                    res+=(char)(count+'0');
                    res+=word[i];
                }
                else{
                    int tmp=count;
                    while (tmp>0){
                        if (tmp>=9){
                            res+='9';
                            res+=word[i];
                        }
                        else{
                            res+=(char)(tmp+'0');
                            res+=word[i];
                        }
                        tmp-=9;
                    }
                }
                count=1;
            }
        }
        int tmp=count;
        while (tmp>0){
            if (tmp>=9){
                res+='9';
                res+=word[n-1];
            }
            else{
                res+=(char)(tmp+'0');
                res+=word[n-1];
            }
            tmp-=9;
        }
        return res;
    }
};

signed main(){
    string word="aaaaaaaaaaaaaabb";
    Solution* sol=new Solution();
    cout<<sol->compressedString(word)<<endl;

    return 0;  
}