#include<iostream>
using namespace std;
#define MaxInt 32767
#define MVNum 100
typedef char VerTexType;
typedef int ArcType;
int *D=new int [MVNum];
bool *S=new bool[MVNum];
int *Path=new int[MVNum];
typedef struct 
{
    /* data */
    VerTexType vexs[MVNum];
    ArcType arcs[MVNum][MVNum];
    int vexnum,aexnum;
}AMGraph;
int LocateVex(AMGraph G,VerTexType v)
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
    cin>>G.vexnum>>G.aexnum;
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
    for(int k=0;k<G.aexnum;k++)
    {
        VerTexType v1,v2;
        ArcType w;
        cin>>v1>>v2>>w;
        int i=LocateVex(G,v1);
        int j=LocateVex(G,v2);
        G.arcs[i][j]=w;
        G.arcs[j][i]=G.arcs[i][j];
    }
}
void ShortestPath_DIJ(AMGraph G,int v0)
{
    int v,w,min,i;
    int n=G.vexnum;
    for(i=0;i<n;i++)
    {
        S[i]=false;
        D[i]=G.arcs[v0][i];
        if(D[i]<MaxInt)
        {
            Path[i]=v0;
        }
        else
        {
            Path[i]=-1;
        }   
        S[v0]=true;
        D[v0]=0;
        for(i=1;i<n;i++)
        {
            min=MaxInt;
            for(w=0;w<n;w++)
            {
                if(!S[w]&&D[w]<min)
                {
                    v=w;
                    min=D[w];
                }
            }
            S[v]=true;
            for(w=0;w<n;w++)
            {
                if(!S[w]&&(min+G.arcs[v][w]<D[w]))
                {
                    D[w]=min+G.arcs[v][w];
                    Path[w]=v;
                }
            }
        }
        

    }
}