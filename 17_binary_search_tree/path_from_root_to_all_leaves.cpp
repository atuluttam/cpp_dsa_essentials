/*---------------------------------------------------------------------
 *                  code : path_from_root_to_all_leaves   
 *               @author :  Atul Uttam     
 *          Date Created :  25-02-2023(01:00:08)       
 --------------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

// input: 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1, here -1 means that it is null

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

Node *buildTree()
{
    int d;
    cin >> d;
    if (d == -1)
    {
        return NULL;
    }
    Node *n = new Node(d);
    n->left = buildTree();
    n->right = buildTree();
    return n;
}

void printPreorder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void printInorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

// also called bottom up approach
void printPostorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->data << " ";
}

void printRootToLeafPaths(Node* root,vector<int> &path){
    if(root == NULL)
        return;
    if(root->left == NULL and root->right ==NULL){
        for(int node:path){
            cout << node << "->";
        }
        cout << root->data << "->";
        cout << endl;
        return;
    }

    path.push_back(root->data);
    printRootToLeafPaths(root->left, path);
    printRootToLeafPaths(root->right, path);
    // backtracking
    path.pop_back();
}

int main()
{
    Node *root = buildTree();
    cout << "pre-order: ";
    printPreorder(root);
    cout << endl;
    cout << "in-order: ";
    printInorder(root);
    cout << endl;
    cout << "post-order: ";
    printPostorder(root);
    cout << endl;
    vector<int> path;
    printRootToLeafPaths(root, path);

    return 0;
}
