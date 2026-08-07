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

class Codec {
public:
    void helper(TreeNode*root,string &ans){
        if(root==NULL){
            ans+="#,";
            return;
        }
        ans+=to_string(root->val)+",";
        helper(root->left,ans);
        helper(root->right,ans);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        helper(root,ans);
        return ans;
        
    }
    TreeNode* build(int &index,vector<string>&tokens){
        if(index>=tokens.size()){
            return NULL;
        }
        if(tokens[index]=="#"){
            index++;
            return NULL;
        }
        TreeNode* root=new TreeNode(stoi(tokens[index]));
        index++;
        root->left=build(index,tokens);
        root->right=build(index,tokens);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string>tokens;

        string temp="";
        for(char c:data){
            if(c==','){
                tokens.push_back(temp);
                temp="";
            }else{
                temp+=c;
            }
        }
        int index=0;
        return build(index,tokens);

    }
};
