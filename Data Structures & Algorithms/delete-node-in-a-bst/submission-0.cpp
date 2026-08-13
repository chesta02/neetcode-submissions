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
    TreeNode* helper(TreeNode*root,int key){
        if(root==NULL) return NULL;
        if(key<root->val){
            root->left=helper(root->left,key);
        }else if(key>root->val){
            root->right=helper(root->right,key);
        }else{
            if(root->left==NULL && root->right==NULL){
                return NULL;
            }else if(root->left!=NULL && root->right!=NULL){
                TreeNode*successor=root->right;
                while(successor->left!=NULL){
                    successor=successor->left;
                }
                root->val=successor->val;
                root->right=helper(root->right,successor->val);
            }else{
                if(root->left!=NULL && root->right==NULL){
                    return root->left;
                }else if(root->right!=NULL && root->left==NULL){
                    return root->right;
                }
            }
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        return helper(root,key);
    }
};