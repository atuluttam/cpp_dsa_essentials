/*---------------------------------------------------------------------
 *                  code : build_tree_and_traversal
 *               @author :  Atul Uttam
 *          Date Created :  19-02-2023(03:20:15)
 --------------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

// input: 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1, here -1 means that it is null
// preorder: 1 2 4 5 7 3 6
// inorder: 4 2 7 5 1 3 6
// postorder: 4 7 5 2 6 3 1

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

    return 0;
}
