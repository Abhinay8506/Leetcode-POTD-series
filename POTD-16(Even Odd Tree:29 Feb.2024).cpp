//APPROACH-1

class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        vector<int>a;
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(!q.empty() && node==NULL){
               ans.push_back(a);
               a.clear();
               q.push(NULL);
            }
            else if(!q.empty()){
                if(node->left!=NULL){
                   q.push(node->left);
                }
                if(node->right!=NULL){
                   q.push(node->right);
                }
                a.push_back(node->val);
            }
            
           
            
        }
        ans.push_back(a);
        for(int i=0;i<ans.size();i++){
            vector<int>aut=ans[i];
            if(i%2==0){
                if(aut[aut.size()-1]%2==0){
                    return false;
                }
                for(int j=0;j<aut.size()-1;j++){
                   if(aut[j]%2==0 || aut[j]>=aut[j+1]){
                       return false;
                   }   
                }
            }
            else{
                if(aut[aut.size()-1]%2!=0){
                   return false;
                }
                for(int j=0;j<aut.size()-1;j++){
                   if(aut[j]%2!=0 || aut[j]<=aut[j+1]){
                       return false;
                   }
                }
            }
            
        }
        return true;
    }
};

//APPROACH-2
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> queue;
        TreeNode* current = root;//front element of queue
        queue.push(current);
        bool even = true;
        while (!queue.empty()) {
            int size = queue.size();//Level size
            int prev = INT_MAX;
            if (even) {
                prev = INT_MIN;
            }
            while (size > 0) {
                current = queue.front();
                queue.pop();
                if ((even && (current->val % 2 == 0 || current->val <= prev)) || 
                        (!even && (current->val % 2 == 1 || current->val >= prev))) {
                    return false;
                }
                prev = current->val;
                if (current->left) {
                    queue.push(current->left);
                }
                if (current->right) {
                    queue.push(current->right);
                }

                size--;
            }
            
            even = !even;//level change
        }
       
        return true;
    }
};
