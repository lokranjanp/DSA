#include<bits/stdc++.h>
using namespace std;

class treenode{
public:
    int val;
    treenode *left;
    treenode *right;

    treenode(int num)
    {
        this->val = num;
        this->left = nullptr;
        this->right = nullptr;
    }

};

treenode * insert(treenode *root, int num){
    if(root == nullptr)
        return new treenode(num);

    if(root->val == num)
        return root;

    if(root->val < num)
        root->right = insert(root->right, num);

    else
        root->left = insert(root->left, num);

    return root;
}

bool search(treenode *root, int key)
{
    if(root == nullptr)
        return false;

    if(root->val == key)
        return true;

    if(root->val < key)
        return search(root->right, key);

    else
        return search(root->left, key);
}

void inorder(treenode* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
}

int maxheight(treenode *root){
    if(root == nullptr)
        return 0;

    int left = maxheight(root->left)+1;
    int right = maxheight(root->right)+1;

    return max(left, right);
}

int count_leafnode(treenode *root){
    if(root == nullptr)
        return 0;
    if(root->right == nullptr && root->left == nullptr)
        return 1;

    int left = count_leafnode(root->left);
    int right = count_leafnode(root->right);

    return left+right;
}

int count_totalnode(treenode *root){
    if(root == nullptr)
        return 0;

    return count_totalnode(root->right) + count_totalnode(root->left) + 1;
}


int main() {
    treenode* root = new treenode(5);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 60);
    root = insert(root, 80);

    inorder(root);
    cout<<endl;

    cout<<count_totalnode(root)<<endl;
    delete root;
    return 0;
}