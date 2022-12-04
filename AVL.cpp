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
int calHeight(node *root)
{
    if (!root) return 0;
    return max(calHeight(root->left), calHeight(root->right)) + 1;
}
int count(node *root)
{
    if (!root) return 0;
    return count(root->left) + count(root->right) + 1;
}
int countLess(node *root, int key)
{
    if (!root) return 0;
    int res = countLess(root->left, key);
    if (key > root->key) res += countLess(root->right, key) + 1;
    return res;
}
int countGreater(node *root, int key)
{
    if (!root) return 0;
    int res = countGreater(root->right, key);
    if (key < root->key) res += countGreater(root->left, key) + 1;
    return res;
}
int countLeaf(node *root)
{
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    return countLeaf(root->left) + countLeaf(root->right);
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
        if (calHeight(root) != root->height)
        {
            cout << "WRONG\n";
        }
        cout << count(root) << "\n";
        cout << "Node less than 20: " << countLess(root, 20) << "\n"; 
        cout << "Node greater than 20: " << countGreater(root, 20) << "\n"; 
        cout << "Leaf: " << countLeaf(root) << "\n";
    }
    while(cin >> x)
    {
        remove(root, x);
        preOrder(root);
        cout << "\n";
        if (calHeight(root) != root->height)
        {
            cout << "WRONG\n";
        }
        cout << count(root) << "\n";
        cout << "Node less than 20: " << countLess(root, 20) << "\n"; 
        cout << "Node greater than 20: " << countGreater(root, 20) << "\n"; 
        cout << "Leaf: " << countLeaf(root) << "\n";
    }
}
