//克鲁斯卡尔算法选边
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
typedef char VertexType;
typedef int ArcType;
#define MANum 100
#define MaxInt 32767
typedef struct
{
    VertexType vexs[MANum];
    ArcType arcs[MANum][MANum];
    int vexnum,arcnum;
} AMGraph;
struct 
{
    VertexType head;
    VertexType tail;
    ArcType lowcast;

} Edge[MANum*((MANum-1)/2)];
int Vexset[MANum];
int LocateVex(AMGraph &G,VertexType v)
{
    for(int i=0;i<G.vexnum;i++)
    {
        if(G.vexs[i]==v)
        {
            return i;
        }
    }
    return -1;
}
void CreateUDN(AMGraph &G)
{
    cin>>G.vexnum>>G.arcnum;
    for(int i=0;i<G.vexnum;i++)
    {
        cin>>G.vexs[i];
    }
    for(int i=0;i<G.vexnum;i++)
    {
        for(int j=0;j<G.vexnum;j++)
        {
            G.arcs[i][j]=MaxInt;
        }
    }
    for(int k=0;k<G.arcnum;k++)
    {
        VertexType v1,v2;
        ArcType w;
        cin>>v1>>v2>>w;
        int i=LocateVex(G,v1);
        int j=LocateVex(G,v2);
        G.arcs[i][j]=w;
        G.arcs[j][i]=w;
        Edge[k].head=v1;
        Edge[k].tail=v2;
        Edge[k].weight=w;
    }
}
   
void Sort(AMGraph &G)
{
    int m=G.arcnum-2;
    int flag=1;
    while(m>0&&flag==1)
    {
        flag=0;
        for(int i=0;i<m;i++)
        {
            if(Edge[i].lowcast>Edge[i+1].lowcast)
            {
                flag=1;
                VertexType temp1=Edge[i].head;
                Edge[i].head=Edge[i+1].head;
                Edge[i+1].head=temp1;
                VertexType temp2=Edge[i].tail;
                Edge[i].tail=Edge[i+1].tail;
                Edge[i+1].tail=temp2;
                ArcType temp3=Edge[i].lowcast;
                Edge[i].lowcast=Edge[i+1].lowcast;
                Edge[i+1].lowcast=temp3;

            }
        }
        m--;
    }
}
void MiniSpanTree_Kruskal(AMGraph &G)
{
    int i,j;
    int k=0;
    for(i=0;i<G.vexnum;i++)
    {
        Vexset[i]=i;
    }
    Sort(G);
    for(i=0;i<G.arcnum;i++)
    {
        int v1=LocateVex(G,Edge[i].head);
        int v2=LocateVex(G,Edge[i].tail);
        if(Vexset[v1]!=Vexset[v2])
        {
            cout<<Edge[i].head<<" "<<Edge[i].tail<<" "<<Edge[i].lowcast<<endl;
            for(j=0;j<G.vexnum;j++)
            {
                if(Vexset[j]==Vexset[v2])
                {
                    Vexset[j]=Vexset[v1];
                }
            }
        }
    }
}