struct node_ptr
{
    int value,rank;
    struct node_ptr *next;
};

typedef struct node_ptr* NODE_PTR;

typedef struct union_find
{
    NODE_PTR *A;
    int size;

}UNION_FIND;


UNION_FIND createUF(int n);
UNION_FIND makeSetUF(UNION_FIND F, int x, int *i);
NODE_PTR findUF(UNION_FIND F, int i);
void unionUF(UNION_FIND F, int i, int j);