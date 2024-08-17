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

int main() {
    treenode* root = new treenode(50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    inorder(root);
    cout<<endl;

    cout<<search(root, 81)<<endl;
    delete root;
    return 0;
}