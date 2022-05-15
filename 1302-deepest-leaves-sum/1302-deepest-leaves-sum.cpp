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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*>que;
        que.push(root);
        int sum;
        while(!que.empty())
        {
            sum=0;
            int size=que.size();
            while(size--)
            {
                TreeNode*curr=que.front();
                que.pop();
                if(curr->left)que.push(curr->left);
                if(curr->right)que.push(curr->right);
                sum+=curr->val;
            }
        }
        return sum;
    }
};