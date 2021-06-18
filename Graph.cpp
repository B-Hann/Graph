#include <iostream>

using namespace std;

struct graph
{
    int v; //vertices
    int e; //edges
    int **direct; //direction
};

int findVertexDegree(struct graph *g, int ver)
{
    int degree = 0;
    for (int i=0; i<g->v; i++)
        if (g->direct[ver][i] == 1)
            degree++;
    //khuyen
    if (g->direct[ver][ver] == 1)
        degree++;

    return degree;
}

int findGraphDegree(struct graph *g)
{
    int degree = 0;
    for (int i=0; i<g->v; i++)
        degree += findVertexDegree(g,i);

    return degree;
}

struct graph *createGraph(int v, int e)
{
    struct graph *g = new graph;
    g->v = v;
    g->e = e;
    g->direct = new int *[v];
    for (int i=0; i<v; i++)
        g->direct[i] = new int [v];

    g->direct[0][1]=1;
    g->direct[0][2]=1;
    g->direct[0][3]=1;

    g->direct[1][0]=1;
    g->direct[1][3]=1;

    g->direct[2][0]=1;
    g->direct[2][3]=1;

    g->direct[3][0]=1;
    g->direct[3][1]=1;
    g->direct[3][2]=1;

    return g;
};

int main()
{
    int vertices = 4;
    int edges = 5;
    struct graph *g = createGraph(vertices,edges);

    cout << "Degree of graph: " << findGraphDegree(g);
    

    system("pause");
    return 0;
}