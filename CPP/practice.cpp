#include<iostream>
using namespace std;
typedef struct BSTNode
{
    int data;
    BSTNode *lchild,*rchild;
}BSTNode,*BSTree;
void InsertBST(BSTree &T,int key)
{
    if(T==NULL)
    {
        T=new BSTNode;
        T->data=key;
        T->lchild=T->rchild=NULL;
    }
    else if(key<T->data)
    {
        InsertBST(T->lchild,key);
    }
    else if(key>T->data)
    {
        InsertBST(T->rchild,key);
    }
}
void CreateBST(BSTree &T,int n)
{
    T=NULL;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        InsertBST(T,a);
    }
}   
BSTNode* SearchBST(BSTree T,int key)
{
    if(T==NULL)
    {
        return NULL;
    }
    else if(key==T->data)
    {
        return T;
    }
    else if(key<T->data)
    {
        return SearchBST(T->lchild,key);
    }
    else
    {
        return SearchBST(T->rchild,key);
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    BSTree T;
    CreateBST(T,n);
    for(int i=0;i<m;i++)
    {
        int a;
        cin>>a;
        if(SearchBST(T,a)==NULL)
        {
            cout<<"n"<<endl;
        }
        else
        {
            cout<<"y"<<endl;
        }
    }
}