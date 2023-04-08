/*---------------------------------------------------------------------
 *                  code : diameter_of_tree
 *               @author :  Atul Uttam
 *          Date Created :  20-02-2023(00:10:24)
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

// diameter o(N^2)
int diameter(Node *root)
{
    if (root == NULL)
        return 0;

    int d1 = treeHeight(root->left) + treeHeight(root->right);
    int d2 = diameter(root->left);
    int d3 = diameter(root->right);

    return max(d1, max(d2, d3));
}

// diameter optimized o(N)
class HeightDistancePair
{
public:
    int height;
    int diameter;
};
HeightDistancePair optimizedDiameter(Node *root)
{
    HeightDistancePair p;
    if (root == NULL)
    {
        p.height = p.diameter = 0;
        return p;
    }

    HeightDistancePair left = optimizedDiameter(root->left);
    HeightDistancePair right = optimizedDiameter(root->right);

    p.height = max(left.height, right.height) + 1;

    int d1 = left.height + right.height;
    int d2 = left.diameter;
    int d3 = right.diameter;

    p.diameter = max(d1, max(d2, d3));
    return p;
}

int main()
{
    Node *root = levelOrderBuild();
    cout << "tree diameter is: " << diameter(root) << endl;

    cout << "tree diameter is: " << optimizedDiameter(root).diameter << endl;

    return 0;
}
