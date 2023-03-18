/*---------------------------------------------------------------------
 *                  code :  graph_adj_List
 *               @author :  Atul Uttam
 *          Date Created :  17-03-2023(23:49:29)
 --------------------------------------------------------------------*/

#include <iostream>
#include <list>
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

    void printAdjList(){
        //iterate over all the rows
        for (int i = 0; i < TotalVertices; i++)
        {
            cout <<"|"<< i <<"|"<< "-->";
            //every element of the ith list
            for(auto j:l[i]){
                cout << j << "," ;
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(4, 5);
    // g.addEdge(5, 6);
    g.printAdjList();

    return 0;
}
