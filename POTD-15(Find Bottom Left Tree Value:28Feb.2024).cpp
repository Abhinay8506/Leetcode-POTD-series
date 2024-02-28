/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*>queue;//level order traversal
        TreeNode* current=root;
        queue.push(current);
        while(!queue.empty()){
            current=queue.front();
            queue.pop();
            if(current->right!=NULL){
                queue.push(current->right);
            }
            if(current->left!=NULL)
            {
               queue.push(current->left);
            }

        }
        return current->val;
    }
};
