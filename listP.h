typedef struct node NodeType;

struct node {
        char ch;
        NodeType *next;
   };

struct l {
        int length;
        NodeType *head;
    } ;
typedef struct l List;

void check(int item, List L);
void init(List *L,int maxSize) ;
int length(List L) ;
void add(List *L, char c) ;
void print(List L) ;