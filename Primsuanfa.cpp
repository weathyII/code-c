//最短生成树普里姆算法（选点）
#include<iostream>
#include<cstdio>
#include<cstring>//memset
#include<algorithm>
using namespace std;
typedef char VerTexType;
typedef int ArcType;
#define MVNum 100
#define MaxInt 32767
struct 
{
    VerTexType adjvex;
    ArcType lowcost;//最小代价
}closedge[MVNum];//辅助数组
typedef struct 
{
    VerTexType vexs[MVNum];//顶点表
    ArcType arcs[MVNum][MVNum];
    int vexnum.arcnum;
    /* data */
}AMGraph;
int LOcateVex(AMGraph G,VerTexType v)//定位顶点v在图G中的位置
{
    for(int i=0;i<G.vexnum;i++)
    {
        if(G.vexs[i]==v)
        return 1;
        return -1;
    }
}
void CreateUDN(AMGraph &G)//创建无向网
{
    int i,j,k;
    cin>>G.vexnum>>G.arcnum;
    for(i=0;i<G.vexnum;i++)
    cin>>G.vexs[i];
     for(i=0;i<G.vexnum;i++)
    for(j=0;j<G.vexnum;i++)
    G.arcs[i][j]=MaxInt;
    for(k=0;k<G.arcnum;++k)
    {
        VerTexType v1,v2;
        AMGraph w;
        cin>>v1>>v2>>w;
        i=LOcateVex(G,v1);j=LOcateVex(G,v2);
        G.arcs[i][j]=w;
        G.arcs[j][i]=G.arcs[i][j];
    }
}
int Min(AMGraph G)//求出最小代价的边
{
    int i;
    int index=-1;
    int min=MaxInt;
    for(i=0;i<G.vexnum;i++)
    {
        if(min>closedge[i].lowcost&&closedge[i].lowcost!=0)
        {
            min=closedge[i].lowcost;
            index=i;
        }
    }
    return index;
}
void MiniSpanTree_Prim(AMGraph G,VerTexType U)//普里姆算法
{
    int k,j,i;
    VerTexType v0,u0;
    k=LOcateVex(G,U);
    for(j=0;j<G.vexnum;j++)//初始化辅助数组
    {
        if(j!=k)
        {
            closedge[j].adjvex=U;
            closedge[j].lowcost=G.arcs[k][j];
        }
    }
    closedge[k].lowcost=0;
    for(i=1;i<G.vexnum;++i)//选择其余G.vexnum-1个顶点
    {
        k=Min(G);
        u0=closedge[k].adjvex;//输出生成树的一条边
        v0=G.vexs[k];       //输出生成树的一条边
        cout<<u0<<" "<<v0<<endl;//输出生成树的一条边
        closedge[k].lowcost=0;//顶点k并入U集
        for(j=0;j<G.vexnum;j++)//新顶点并入U集后重新选择最小边
        {
            if(G.arcs[k][j]<closedge[j].lowcost)//新顶点并入U集后重新选择最小边
            {
                closedge[j].adjvex=G.vexs[k];
                closedge[j].lowcost=G.arcs[k][j];//新顶点并入U集后重新选择最小边
            }
        }
    }
}
int main()
{
    AMGraph G;
    VerTexType U;
    CreateUDN(G);
    cin>>U;
    MiniSpanTree_Prim(G,U);
    return 0;
}