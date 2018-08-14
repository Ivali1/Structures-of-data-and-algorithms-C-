#include<iostream>
/**
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
*/

struct NodeBT
{
	int data;
	NodeBT* left;
	NodeBT* right;

	NodeBT(int otherData)
	{
		data = otherData;
		left = right = NULL;
	}
};
NodeBT* CreateNewNode(int otherData)
{
	NodeBT* newNode = new NodeBT(otherData);
	return newNode;
}
void InsertNodeBT(NodeBT** root, int otherData)
{
	if (*root == NULL)
	{
		*root = CreateNewNode(otherData);
		return;
	}

	if ((*root)->left == NULL)
	{
		InsertNodeBT(&(*root)->left, otherData);
	}
	else if ((*root)->right==NULL)
	{
		InsertNodeBT(&(*root)->right, otherData);
	}
	else if ((*root)->left->left != NULL && (*root)->left->right != NULL)
	{
		InsertNodeBT(&(*root)->right, otherData);

	}
	else
	{
		InsertNodeBT(&(*root)->left, otherData);

	}
}

static bool flag = true;
bool isBst(NodeBT* root)
{
	
	if (root == NULL)
	{
		return true;
	}

	if (root->left != NULL && root->left->data >= root->data)
	{
		return false;
	}
	if (root->left!= NULL && root->left->right!=NULL && 
		  ( root->left->right->data > root->data || root->left->right->data <root->left->data) )
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
	
  
static int hightLeft=0;
static int higtRigh=0;

bool IsFull(NodeBT* root)
{
	if (root == NULL)
	{
		return true;
	}

		if (root->left!= NULL)
		{
			++hightLeft;

		}
		if (root->right!= NULL)
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
/*static NodeBT* tempRoot = NULL;
bool ReduceToBst(NodeBT* root)
{
	if (root == NULL)
	{
		return true;
	}
	
	if (root->left != NULL && root->data <= root->left->data)
	{
		tempRoot = root;
		root = root->left;
		if (root->left != NULL && root->right != NULL)
		{
			ReduceToBst(root->left);
		}
		if (root->right != NULL)
		{
			ReduceToBst(root->right);
		}
		tempRoot->data = root->right->data;
		delete root->right;
		root->right = NULL;
	}
	if (root->left != NULL && root->right!=NULL &&( root->data <= root->left->data || root->left->right->data> root->data))
	{
		tempRoot = root;
		root = root->left;
		if (root->left != NULL && root->right != NULL)
		{
			ReduceToBst(root->left);
		} 
		if (root->right != NULL)
		{
			ReduceToBst(root->right);
		}
		tempRoot->data = root->right->data;
		delete root->right;
		root->right = NULL;
	}

	if (root->right != NULL &&root->data > root->right->data)
	{
		tempRoot = root;
		root = root->left;
		if (root->left != NULL && root->right != NULL)
		{
			ReduceToBst(root->left);
		}

		if (root->right != NULL)
		{
			ReduceToBst(root->right);
		}
		tempRoot->data = root->right->data;
		delete root->right;
		root->right = NULL;
	}
	if (root->left != NULL && root->right != NULL &&  (root->data > root->right->data || root->left->left->data < root->data))
	{
		tempRoot = root;
		root = root->left;
		if (root->left != NULL && root->right != NULL)
		{
			ReduceToBst(root->left);
		}
		if (root->right != NULL)
		{
			ReduceToBst(root->right);
		}
		tempRoot->data = root->right->data;
		delete root->right;
		root->right = NULL;
	}

	ReduceToBst(root->left);
	ReduceToBst(root->right);
}
*/
static NodeBT* tempRoot = NULL;
bool ReduceToBst(NodeBT* root)
{
	if (root == NULL)
	{
		return true;
	}

	if (root->left != NULL && root->right == NULL && root->data <= root->left->data)
	{
		NodeBT* temp= root;
		root = root->left;
		delete temp;
	}
	if ((root->left != NULL &&root->data > root->left->data))
	{
		tempRoot = root;
		root = root->left;
		if (root->left != NULL && root->right != NULL)
		{
			ReduceToBst(root->left);
		}
		tempRoot->data = root->right->data;
		delete root->right;
		root->right = NULL;
	}
	if (root->left != NULL && root->right != NULL && (root->data <= root->left->data || root->left->right->data> root->data))
	{
		tempRoot = root;
		root = root->left;
		if (root->left != NULL && root->right != NULL)
		{
			ReduceToBst(root->left);
		}
		tempRoot->data = root->right->data;
		delete root->right;
		root->right = NULL;
	}

	if (root->right != NULL &&root->left == NULL&& root->data > root->right->data)
	{
			NodeBT* temp = root;
			root = root->right;
			delete temp;
	}
	if (root->right != NULL &&root->data > root->right->data)
	{
		tempRoot = root;
		root = root->left;
		if (root->left != NULL && root->right != NULL)
		{
			ReduceToBst(root->left);
		}
		tempRoot->data = root->right->data;
		delete root->right;
		root->right = NULL;
	}
	if (root->left != NULL && root->right != NULL && (root->data > root->right->data || root->left->left->data < root->data))
	{
		tempRoot = root;
		root = root->left;
		if (root->left != NULL && root->right != NULL)
		{
			ReduceToBst(root->left);
		}
		tempRoot->data = root->right->data;
		delete root->right;
		root->right = NULL;
	}


	ReduceToBst(root->left);
	ReduceToBst(root->right);
}

void printTree(NodeBT* root)
{
	if (root == NULL) 
	{
		return;
	}
	std::cout << root->data<<" ";
	printTree(root->left);
	printTree(root->right);
}



int main()
{
	NodeBT* root=NULL;
	InsertNodeBT((&root),100);
    InsertNodeBT(&root, 50);
    InsertNodeBT(&root, 200);
    InsertNodeBT(&root, 20);
	InsertNodeBT(&root, 60);
	InsertNodeBT(&root, 150);
	InsertNodeBT(&root, 210);
	/*InsertNodeBT(&root, 10);
	InsertNodeBT(&root, 30);
	InsertNodeBT(&root, 40);
	InsertNodeBT(&root, 70);
	InsertNodeBT(&root, 140);
	InsertNodeBT(&root, 145);
	InsertNodeBT(&root, 208);
	InsertNodeBT(&root, 220);*/
	printTree(root);
	std::cout << std::endl;
	std::cout<<isBst(root)<<std::endl;
	std::cout << IsFull(root) << std::endl;
	std::cout << ReduceToBst(root) << std::endl; 
	printTree(root);
	std::cout << std::endl;
	std::cout << IsFull(root) << std::endl;
	std::cout << std::endl;
	std::cout << isBst(root) << std::endl;



}