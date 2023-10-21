#include<iostream>
#include<iomanip>
using namespace std;
typedef struct 
{
    int weight;
    int parent,lchild,rchild;
    /* data */
}HTNode,*HuffmanTree;

void Select(HuffmanTree &HT,int n,int &s1,int &s2)
{
    int i;
    int min=10000;
    for(i=1;i<=n;i++)
    {
        if(HT[i].parent==0&&HT[i].weight<min)
        {
            min=HT[i].weight;
            s1=i;
        }
    }
    int temp=HT[s1].weight;
    HT[s1].weight=min+1;
    for(i=1;i<=n;i++)
    {
        if(HT[i].parent==0&&HT[i].weight<min)
        {
            min=HT[i].weight;
            s2=i;
        }
    }
    HT[s1].weight=temp;
}
 void CreatHuffmanTree(HuffmanTree &HT,int n)
 {
    int m,s1,s2,i;
    if(n<=1) return;
    m=2*n-1;
    HT=new HTNode[m+1];
    for(i=1;i<=m;i++)
    {
        HT[i].parent=HT[i].lchild=HT[i].rchild=0;
    }
    for(i=1;i<=n;i++)
    {
        cin>>HT[i].weight;
    }
    for(i=n+1;i<=m;i++)
    {
        Select(HT,i-1,s1,s2);
        HT[s1].parent=i;
        HT[s2].parent=i;
        HT[i].lchild=s1;
        HT[i].rchild=s2;
        HT[i].weight=HT[s1].weight+HT[s2].weight;
    }

 }