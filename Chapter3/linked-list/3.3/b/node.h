typedef struct _DOUBLE_LIKE_NODE
{
	int data;
	struct _DOUBLE_LIKE_NODE *prev;
	struct _DOUBLE_LIKE_NODE *next;
} DOUBLE_LIKE_NODE;

typedef int STATUS; // 0 fail , 1 success

DOUBLE_LIKE_NODE* create_double_link_node(int value);
STATUS insert_data_into_double_link(DOUBLE_LIKE_NODE **ppDLinkNode, int data);
STATUS switch_double_link_node(DOUBLE_LIKE_NODE *pDLinkNode, int pos);
void print_double_link_node(const DOUBLE_LIKE_NODE *pDLinkNode);
