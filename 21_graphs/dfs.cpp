/*---------------------------------------------------------------------
 *                  code :  dfs   
 *               @author :  Atul Uttam     
 *          Date Created :  19-03-2023(00:56:12)       
 --------------------------------------------------------------------*/

#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Graph
{
    int TotalVertices;
    list<int> *l;

public:
    Graph(int v)
    {
        TotalVertices = v;
        l = new list<int>[TotalVertices];
    }

    void addEdge(int from, int to, bool undir = true)
    {
        l[from].push_back(to);
        if (undir)
        {
            l[to].push_back(from);
        }
    }

    void dfsHelper(int node,bool *visited){
        visited[node] = true;
        cout << node << ",";

        //make a dfs call on its unvisited neighbours
        for (int neighbour: l[node])
        {
            if (!visited[neighbour])
            {
                dfsHelper(neighbour, visited);
            }
        }
        
    }

    void dfs(int source){
        bool *visited = new bool[TotalVertices]{0};
        dfsHelper(source, visited);
    }
};

int main()
{
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(4, 5);
    g.addEdge(5, 6);

    g.dfs(1);

    return 0;
}
