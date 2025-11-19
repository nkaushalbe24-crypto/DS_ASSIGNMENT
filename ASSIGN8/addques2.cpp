#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

vector<TreeNode*> generate(int start, int end) {
    vector<TreeNode*> result;

    if (start > end) {
        result.push_back(NULL);
        return result;
    }

    for (int i = start; i <= end; i++) {

        
        vector<TreeNode*> leftTrees = generate(start, i - 1);

        vector<TreeNode*> rightTrees = generate(i + 1, end);

        for (int l = 0; l < leftTrees.size(); l++) {
            for (int r = 0; r < rightTrees.size(); r++) {

                TreeNode* root = new TreeNode(i);
                root->left = leftTrees[l];
                root->right = rightTrees[r];

                result.push_back(root);
            }
        }
    }

    return result;
}
vector<TreeNode*> generateTrees(int n) {
    if (n == 0) return {};
    return generate(1, n);
}

void printTree(TreeNode* root) {
    if (root == NULL) {
        cout << "null ";
        return;
    }
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

int main() {
    int n = 3;
    vector<TreeNode*> trees = generateTrees(n);

    cout << "Total Unique BSTs = " << trees.size() << "\n\n";

    for (int i = 0; i < trees.size(); i++) {
        cout << "Tree " << i + 1 << ": ";
        printTree(trees[i]);
        cout << endl;
    }

    return 0;
}
