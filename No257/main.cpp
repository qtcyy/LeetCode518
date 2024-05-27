#include "TreeTemplate.h"

class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
public:
    void dfs(TreeNode* root){
        if (root==nullptr)
            return;
        path.emplace_back(root->val);
        if (root->left==nullptr && root->right==nullptr)
            res.emplace_back(path);
        dfs(root->left);
        dfs(root->right);
        path.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root);
        vector<string> ans;
        for (auto& row:res){
            int u=row[0];
            string s="";s+=(char)(u+32);
            for (int i=1;i<row.size();i++)
                {s+="->";s+=(char)(row[i]+32);}
            ans.emplace_back(s);
        }
        return ans;
    }
};

signed main(){
    vector<int> root={1,2,3,-1,5};
    TreeNode* tree=buildTree(root);
    Solution *sol=new Solution();
    vector<string> ans=sol->binaryTreePaths(tree);
    for (auto p:ans)
        cout<<p<<endl;
    return 0;
}