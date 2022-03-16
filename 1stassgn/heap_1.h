typedef struct HEAP
{
   int *A;
   int count;

}HEAP;
HEAP createHeap();
int findMin(HEAP H);
void heapify(HEAP H,int i);
HEAP extractMin (HEAP H);
HEAP insertHeap(HEAP H, int k);
int isFullHeap(HEAP H);
int isEmptyHeap(HEAP H);
void print(HEAP H);
