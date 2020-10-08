//traversals in Binary Search Tree
#include<iostream>
#include<queue>
using namespace std;
class node
{
    public:
    int data;
    node* left;
    node* right;
    node(int d)
    {
        data=d;
        left=right=NULL;
    }
};
// creating bst
node* insertbst(node* root,int data)
{
    if(root == NULL)
    {
        root= new node(data);
        return root;
    }
    if (root->data>data)
    {
        root->left= insertbst(root->left,data);
    }
    else
    {
        root->right= insertbst(root->right,data);
    }
    return root;
}
// enter nodes value 
node* bst()
{
    node* root = NULL;
    int data;
    cin>>data;
    if (data == -1)
    {
        return root;
    }
    while (data != -1)
    {
        root = insertbst(root,data);
        cin>>data;
    }
    return root;     
}
// root Left Right
void preorder(node* root)
{
    if (root == NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
// Left root Right
void inorder(node* root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
// Left Right root
void postorder(node* root)
{
    if(root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int main()
{
    node* root = bst();
    cout<<"Preorder"<<": ";
	preorder(root);
	cout<<endl;
    cout<<"Inorder"<<": ";
	inorder(root);
	cout<<endl;
    cout<<"Postorder"<<": ";
	postorder(root);
	cout<<endl;
    return 0;
}