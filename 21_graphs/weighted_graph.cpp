/*---------------------------------------------------------------------
 *                  code :  weighted_graph
 *               @author :  Atul Uttam
 *          Date Created :  19-03-2023(02:29:47)
 --------------------------------------------------------------------*/

#include <iostream>
#include <list>
#include <set>
using namespace std;

class Graph
{

    int TotalVertices;
    list<pair<int, int>> *l;

public:
    Graph(int v)
    {
        TotalVertices = v;
        l = new list<pair<int, int>>[TotalVertices];
    }

    void addEdge(int from, int to, int wt, bool undir = true)
    {

        l[from].push_back({wt, to});
        if (undir)
        {
            l[to].push_back({wt, from});
        }
    }
};

int main()
{

    Graph g(5);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 2);
    g.addEdge(0, 2, 4);
    g.addEdge(0, 3, 7);
    g.addEdge(3, 2, 2);
    g.addEdge(3, 4, 3);
}
