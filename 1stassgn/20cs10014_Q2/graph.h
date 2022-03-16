
typedef struct 
{
    int **A;
    int size;// no.of.nodes
    int size_of_edges;
    
}GRAPH;


GRAPH readGraph(char *FName);
void DFS(GRAPH G);
void BFS(GRAPH G);
void MST(GRAPH G);