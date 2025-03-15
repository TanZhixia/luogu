#include <iostream>
using namespace std;
class TreeNode {
    public:
        char val;
        TreeNode* left;
        TreeNode* right;
};
void build(TreeNode &tree, string post, string mid) {
    if (post.length() == 0)
        return;
    tree.val = post[post.length() - 1];
    int midIndex = mid.find(tree.val);
    string leftMid = mid.substr(0, midIndex);
    string rightMid = mid.substr(midIndex + 1);
    string leftPost = post.substr(0, leftMid.length());
    string rightPost = post.substr(leftMid.length(), post.length() - leftMid.length() - 1);
    tree.left = new TreeNode();
    tree.right = new TreeNode();
    build(*tree.left, leftPost, leftMid);
    build(*tree.right, rightPost, rightMid);
}
string first(TreeNode tree) {
    string result = "";
    if (tree.val != '\0') {
        result += tree.val;
        result += first(*tree.left);
        result += first(*tree.right);
    }
    return result;
}
int main() {
    string post, mid;
    cin >> mid >> post;
    TreeNode tree;
    build(tree, post, mid);
    cout << first(tree) << endl;
    return 0;
}