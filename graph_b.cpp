#include <iostream>
#include <list>
using namespace std;

class graph
{
    private:
        int ver; //vertices
        list<int> *adj; //adjacency lists
        void DFS(int v, bool visited[], int &);
    public:
        graph(){}
        graph(int ver)
        {
            this->ver = ver;
            adj = new list<int>[ver];
        }
        void addEdge(int v, int w);
        void connectedComponents();
        ~graph(){delete [] adj;}
};

void graph::DFS(int v, bool visited[], int &n)
{
    visited[v] = 1;
    cout << v << " ";
    n++;

    list<int>::iterator i;
    for (i = adj[v].begin(); i!=adj[v].end(); i++)
        if (!visited[*i])
            DFS(*i,visited,n);
}

void graph::connectedComponents()
{
    bool *visited = new bool [ver];
    
    int maxVertices = 0;

    for (int i=0; i<ver; i++)
        visited[i] = 0;

    for (int i=0; i<ver; i++)
        if (visited[i] == 0)
        {
            int n = 0;
            DFS(i,visited,n);
            cout << " - Vertices of connected components: " << n << endl;
            if (maxVertices < n)
                maxVertices = n; 
        }

    cout << "\nThe maximum number of vertices among the connected components: " << maxVertices;
    

    delete [] visited;
}

void graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

int main()
{
    graph g(9);
    g.addEdge(1,0);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(5,6);
    g.addEdge(6,7);
    g.addEdge(7,8);

    cout << "Connected components: \n";
    g.connectedComponents();

    system("pause");
    return 0;
}