#include <iostream>

using namespace std;

struct node {
    node *left, *right;
    int key;
    int height;
    node(int key): key(key)
    {
        left = right = 0;
        height = 1;
    }
};

node* search(node *root, int key)
{
    if (!root) return nullptr;

    if (key < root->key) return search(root->left, key);
    else if (key > root->key) return search(root->right, key);
    else return root;
}

int getHeight(node *u)
{
    if (u) return u->height;
    else return 0;
}
void rotateLeft(node *&root)
{
    node *newRoot = root->right;
    root->right = newRoot->left;
    newRoot->left = root;
    root = newRoot;

    root->left->height = max(getHeight(root->left->left), getHeight(root->left->right)) + 1;
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
}
void rotateRight(node *&root)
{
    node *newRoot = root->left;
    root->left = newRoot->right;
    newRoot->right = root;
    root = newRoot;

    root->right->height = max(getHeight(root->right->left), getHeight(root->right->right)) + 1;
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
}
void insert(node *&root, int key)
{
    if (!root)
    {
        root = new node(key);
        return;
    }
    if (key < root->key) insert(root->left, key);
    else if (key > root->key) insert(root->right, key);
    else return;
    
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    
    //balance
    int heightDiff = getHeight(root->left) - getHeight(root->right);

    if (heightDiff > 1)
    {
        if (getHeight(root->left->right) > getHeight(root->left->left))
        {
            rotateLeft(root->left);
        }
        rotateRight(root);
    } else if (heightDiff < -1)
    {
        if (getHeight(root->right->left) > getHeight(root->right->right))
        {
            rotateRight(root->right);
        }
        rotateLeft(root);
    }
}

node *findRightmost(node* root)
{
    while (root->right)
    {
        root = root->right;
    }
    return root;
}
void remove(node *&root, int key)
{
    if (!root) return;

    if (key < root->key) remove(root->left, key);
    else if (key > root->key) remove(root->right, key);
    else 
    {
        if (root->left && root->right)
        {
            node* alter = findRightmost(root->left);
            root->key = alter->key;
            remove(root->left, alter->key);
        } else
        {
            node *child;
            if (root->left) child = root->left;
            else child = root->right;
            delete root;
            root = child;
        }
    }
    if (!root) return;

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

    int heightDiff = getHeight(root->left) - getHeight(root->right);
    if (heightDiff > 1)
    {
        if (getHeight(root->left->right) > getHeight(root->left->left))
        {
            rotateLeft(root->left);
        }
        rotateRight(root);
    } else if (heightDiff < -1)
    {
        if (getHeight(root->right->left) > getHeight(root->right->right))
        {
            rotateRight(root->right);
        }
        rotateLeft(root);
    }
}
void preOrder(node*root)
{
    if (!root) return;
    cout << root->key << " ";
    preOrder(root->left);
    preOrder(root->right);
}
int main()
{
    node *root = nullptr;
    int x;
    while(cin >> x)
    {
        if (x == -1) break;
        insert(root, x);
        preOrder(root);
        cout << "\n";
    }
    while(cin >> x)
    {
        remove(root, x);
        preOrder(root);
        cout << "\n";
    }
}