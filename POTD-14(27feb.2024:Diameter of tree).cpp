
class Solution {
public:
    pair<int,int> solve(TreeNode* root){
        if(root==NULL){
            return make_pair(0,0);
        }
        
        pair<int,int>left=solve(root->left);
        pair<int,int>right=solve(root->right);
        int op1=left.first;
        int op2=right.first;
        int op3=left.second+right.second;
        pair<int,int>ans;
        ans.first=max(op1,max(op2,op3));
        ans.second=max(left.second,right.second)+1;
        return ans;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        pair<int,int>ans=solve(root);
        return ans.first;
    }
};
