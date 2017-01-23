
typedef struct _DOUBLE_LIKE_NODE
{
	int data;
	struct _DOUBLE_LIKE_NODE *prev;
	struct _DOUBLE_LIKE_NODE *next;
} DOUBLE_LIKE_NODE;

typedef int STATUS; // 0 fail , 1 success

DOUBLE_LIKE_NODE* create_double_link_node(int value);
DOUBLE_LIKE_NODE double_link_node_intersect(DOUBLE_LIKE_NODE *node1, DOUBLE_LIKE_NODE *node2);

STATUS insert_data_into_double_link(DOUBLE_LIKE_NODE **ppDLinkNode, int data);
STATUS switch_double_link_node(DOUBLE_LIKE_NODE *pDLinkNode, int pos);
STATUS find_data_in_double_link(DOUBLE_LIKE_NODE *head, int data);
STATUS delete_head_double_link_node(DOUBLE_LIKE_NODE *node);

void print_double_link_node(const DOUBLE_LIKE_NODE *pDLinkNode);
void print_to_head_double_link_node(const DOUBLE_LIKE_NODE *pDLinkNode);
