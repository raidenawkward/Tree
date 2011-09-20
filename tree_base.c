#include "tree_base.h"

Boolean tree_create (struct Tree **tree, tree_type_t type) {
	*tree = (struct Tree*)malloc(sizeof(struct Tree));
	if (!(*tree))
		return false;

	(*tree)->root = NULL;

	struct tree_node_operations *node_op = treenode_get_operation();
	(*tree)->node_opera = node_op;

	(*tree)->type = type;
	(*tree)->max_child_count_of_node = -1;

	return true;
}

void tree_destory (struct Tree **tree) {
	if (tree)
		free(tree);
}

Int32 tree_clear (struct Tree **tree) {
	return 0;
}

Boolean tree_is_empty (struct Tree *tree) {
	Boolean ret = false;
	if (!tree)
		return ret;

	if (!tree->root)
		return ret;

	ret = true;
	return ret;
}

Int32 tree_tree_depth (struct Tree *tree) {

}

static Int32 print_node (struct tree_node* node) {
	if (node) {
		printf("node : %c\n",node->data);
		return 1;
	} else
		return -1;
}

static Int32 depth_priority_traverse(struct tree_node *node, Int32 (*visit) (struct tree_node*)) {
	if (!node)
		return -1;
	Int32 i;

	visit(node);

	for (i = 0; i < node->child_count; ++i) {
		depth_priority_traverse(node->childs[i],visit);
	}
	return 1;
}

void tree_traverse (struct Tree *tree, tree_traverse_t type, Int32 (*visit) (struct tree_node*)) {
	if (!tree)
		return;
	if (!tree->root)
		return;
	switch (type) {
	case TREE_TRAVERSE_DEPTHPRIORITY:
		depth_priority_traverse(tree->root,visit);
		break;
	default:
		break;
	}
}

struct tree_node* tree_root_of_tree (struct Tree *tree) {
	if (!tree)
		return NULL;
	return tree->root;
}


