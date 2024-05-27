#include <bits/stdc++.h>
using namespace std;

const int N = 10005;

class Solution {
private:
    struct Edge{
        int u,v,w;
    };
    int f[N];
    
public:
    int find(int x){
        if (f[x]==x) return x;
        return f[x]=find(f[x]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<Edge> edge;
        int n=points.size();
        for (int i=1;i<=n;i++)
            f[i]=i;
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++){
                if (i==j) continue;
                edge.push_back((Edge){i,j,abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1])});
            }
        sort(edge.begin(),edge.end(),[](const auto& p1,const auto& p2){
            return p1.w<p2.w;
        });
        long long ans=0;int count=0;
        for (auto& [u,v,w]:edge){
            int x=find(u),y=find(v);
            if (x!=y){
                f[x]=y;
                ans+=1ll*w;
                if (++count==n-1)
                    break;
            }
        }
        return ans;
    }
};

signed main(){
    vector<vector<int>> points={{3,12},{-2,5},{-4,1}};
    Solution *sol=new Solution();
    cout<<sol->minCostConnectPoints(points)<<endl;

    return 0;
}
/**  /\_/\
 *  (= ._.)
 *  / >0  \>1
 */