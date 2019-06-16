#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int              val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
        val(x),
        left(NULL),
        right(NULL)
    {
    }
};

class Solution
{
  public:
    int find_height(TreeNode *pRoot)
    {
        if (!pRoot)
        {
            return 0;
        }

        int lh = find_height(pRoot->left);
        int rh = find_height(pRoot->right);

        if (lh > rh)
        {
            return 1 + lh;
        }
        else
        {
            return 1 + rh;
        }
    }

    void fill(vector<vector<int>> &res, TreeNode *pRoot, int h)
    {
        if (!pRoot)
        {
            return;
        }

        res[h].push_back(pRoot->val);
        fill(res, pRoot->left, h + 1);
        fill(res, pRoot->right, h + 1);
    }

    vector<vector<int>> Print(TreeNode *pRoot)
    {
        int                 h = find_height(pRoot);
        vector<vector<int>> res(h);
        fill(res, pRoot, 0);
        return res;
    }
};

int main(int argc, char const *argv[])
{
    TreeNode *pRoot           = new TreeNode(7);
    pRoot->left               = new TreeNode(2);
    pRoot->left->left         = new TreeNode(9);
    pRoot->left->right        = new TreeNode(4);
    pRoot->left->right->left  = new TreeNode(10);
    pRoot->right              = new TreeNode(6);
    pRoot->right->left        = new TreeNode(8);
    pRoot->right->left->right = new TreeNode(3);
    pRoot->right->right       = new TreeNode(5);
    Solution            solution;
    vector<vector<int>> res = solution.Print(pRoot);
    for (size_t i = 0; i < res.size(); i++)
    {
        for (size_t j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
