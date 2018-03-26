/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// [)
TreeNode* my_reConstructBinaryTree(vector<int> &pre,vector<int> &vin,int l1,int r1, int l2, int r2)
{
    if(l1>=r1)
        return NULL;
    
    if(l1 + 1 == r1)
        return new TreeNode(pre[l1]);
    
    // 0, 8, 0, 8
    int root_val=pre[l1];//1
    int p;
    for(int i=l2; i<r2; i++)
        if(root_val == vin[i])
            p=i;// 3
    int n = p-l2;// 3
    
    TreeNode *root = new TreeNode(pre[l1]);
    root->left = my_reConstructBinaryTree(pre, vin, l1+1, l1+n+1, l2, p);
    root->right = my_reConstructBinaryTree(pre, vin, l1+n+1, r1, p+1, r2);
    return root;
}

class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(!pre.empty())
            return my_reConstructBinaryTree(pre, vin, 0, pre.size(), 0, vin.size());
        else
            return NULL;
    }
};
