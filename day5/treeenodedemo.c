

struct BinaryTreeNode{
	struct BinaryTreeNode *left;
	int data;
	struct BinaryTreeNode *right;
}

struct TernaryTreeNode{
	struct BinaryTreeNode *left;
	int data;
	struct BinaryTreeNode *mid;
	struct BinaryTreeNode *right;
}

struct NAryTreeNode{
	struct BinaryTreeNode *child1;
	struct BinaryTreeNode *child2;
	.....
	struct BinaryTreeNode *childN;
	int data;
}