#include<iostream>
using namespace std;//二叉排序树结构
typedef int KeyType;//
typedef int InfoType;
typedef struct
{
    KeyType key;
    InfoType otherinfo;
}ElemType;

typedef struct BSTNode
{
    /* data */
    KeyType key;
    InfoType otherinfo;
    struct BSTNode *lchild,*rchild;
}BSTNode,*BSTree;
BSTree SearchBST(BSTree T,KeyType key)
{
    if(!T||key==T->key)
    return T;
    else if(key<T->key)
    return SearchBST(T->lchild,key);
    else
    return SearchBST(T->rchild,key);
}
int InsertBST(BSTree &T,KeyType k)
{
    if(!T)
    {
        T=(BSTree)malloc(sizeof(BSTNode));//生成新节点T=new BSTNode;
        T->key=k;
        T->lchild=T->rchild=NULL;
        return 1;
    }
    else if(k==T->key)
    return 0;
    else if(k<T->key)
    return InsertBST(T->lchild,k);
    else
    return InsertBST(T->rchild,k);
}
void CreateBST(BSTree &T,KeyType str[],int n)
{
    T=NULL;
    int i=0;
    while(i<n)
    {
        InsertBST(T,str[i]);
        i++;
    }
}
int DeleteBST(BSTree &T,KeyType k)
{
    if(!T)
    return 0;
    else
    {
        if(k==T->key)
        return Delete(T);
        else if(k<T->key)
        return DeleteBST(T->lchild,k);
        else
        return DeleteBST(T->rchild,k);
    }
}
int Delete(BSTree &p)
{
    BSTree q,s;
    if(!p->rchild)
    {
        q=p;
        p=p->lchild;
        free(q);
    }
    else if(!p->lchild)
    {
        q=p;
        p=p->rchild;
        free(q);
    }
    else
    {
        q=p;
        s=p->lchild;
        while(s->rchild)
        {
            q=s;
            s=s->rchild;
        }
        p->key=s->key;
        if(q!=p)
        q->rchild=s->lchild;
        else
        q->lchild=s->lchild;
        free(s);
    }
    return 1;
}
int main()
{
    int n;
    cin>>n;
    BSTree T;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        InsertBST(T,a);
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int b;
        cin>>b;
        DeleteBST(T,b);
    }
    return 0;
}
