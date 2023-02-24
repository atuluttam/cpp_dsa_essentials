/*---------------------------------------------------------------------
 *                  code : height_of_tree
 *               @author :  Atul Uttam
 *          Date Created :  19-02-2023(22:18:30)
 --------------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

// input:  1 2 3 4 5 -1 6 -1 -1 7 -1 -1 -1 -1 -1, here -1 means that it is null
// levelorder:  1
// 2 3
// 4 5 6
// 7

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

Node *levelOrderBuild()
{
    int d;
    cin >> d;
    Node *root = new Node(d);
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();

        int c1, c2;
        cin >> c1 >> c2;

        if (c1 != -1)
        {
            current->left = new Node(c1);
            q.push(current->left);
        }
        if (c2 != -1)
        {
            current->right = new Node(c2);
            q.push(current->right);
        }
    }
    return root;
}

int treeHeight(Node *root)
{
    if (root == NULL)
        return 0;
    int h1 = treeHeight(root->left);
    int h2 = treeHeight(root->right);
    return 1 + max(h1, h2);
}

int main()
{
    Node *root = levelOrderBuild();
    cout << "tree height is: " << treeHeight(root) << endl;

    return 0;
}
