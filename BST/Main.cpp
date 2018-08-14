#include<iostream>

struct NodeBST
{
	int data;
	NodeBST* left;
	NodeBST* right;

NodeBST(int otherData)
{
	data = otherData;
	left =right = NULL;
}
};
NodeBST* CreateNewNode(int otherData)
{
	NodeBST* newNode = new NodeBST(otherData);
	return newNode;
}


void InsertNodeBST(NodeBST** root, int otherData)
{
	if (*root == NULL)
		{
			*root = CreateNewNode(otherData);
			return;
		}

	if (otherData <= (*root)->data)
		{
			InsertNodeBST(&(*root)->left, otherData);
		}
	else if (otherData > (*root)->data)
		{
			InsertNodeBST(&(*root)->right, otherData);
		}
}

static bool flag = true;
bool isBst(NodeBST* root)
{

	if (root == NULL)
	{
		return true;
	}

	if (root->left != NULL && root->left->data >= root->data)
	{
		return false;
	}
	if (root->left != NULL && root->left->right != NULL &&
		(root->left->right->data > root->data || root->left->right->data <root->left->data))
	{
		return false;
	}
	if (root->right != NULL&& root->right->data < root->data)
	{
		return false;
	}
	if (root->right != NULL && root->right->left != NULL &&
		(root->right->left->data < root->data || root->right->left->data > root->right->data))
	{
		return false;
	}
	isBst(root->left);
	isBst(root->right);
}


bool IsFull(NodeBST* root)
{
	if (root == NULL)
	{
		return true;
	}

	if (root->left == NULL && root->right==NULL)
	{
		return true;
	}

	if (root->left != NULL && root->right != NULL)
	{
		return (IsFull(root->left) && IsFull(root->right));
	}
	
	 return false;

}
static int hightLeft = 0;
static int higtRigh = 0;

bool IsFull2(NodeBST* root)
{
	if (root == NULL)
	{
		return true;
	}

	if (root->left != NULL)
	{
		++hightLeft;

	}
	if (root->right != NULL)
	{
		++higtRigh;
	}
	if (hightLeft != higtRigh)
	{
		return false;
	}

	IsFull(root->left);
	IsFull(root->right);

}
void printTree(NodeBST* root)
{
	if (root == NULL)
	{
		return;
	}
	std::cout << root->data << " ";
	printTree(root->left);
	printTree(root->right);
}
int main()
{
	NodeBST* root = NULL;
	InsertNodeBST((&root), 100);
	InsertNodeBST(&root, 50);
	InsertNodeBST(&root, 200);
	InsertNodeBST(&root, 20);
	InsertNodeBST(&root, 60);
	InsertNodeBST(&root, 150);
	InsertNodeBST(&root, 210);
	InsertNodeBST(&root, 10);
	InsertNodeBST(&root, 30);
	InsertNodeBST(&root, 40);
	InsertNodeBST(&root, 70);
	InsertNodeBST(&root, 140);
	InsertNodeBST(&root, 145);
	InsertNodeBST(&root, 208);
	InsertNodeBST(&root, 220);
	printTree(root);
	std::cout << std::endl;
	std::cout << "isBst: " << isBst(root) << std::endl;
	std::cout << std::endl;
	std::cout << "IsFull: "<<IsFull(root) << std::endl;
	std::cout << std::endl;
	std::cout << "IsFull2: " << IsFull2(root) << std::endl;
	std::cout << std::endl;
	return 0;
}