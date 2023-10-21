#include< iostream >
using namespace std;   
#define MAX 100
#define MVNum 100
#define OK 1
typedef char VertexType;
typedef int ArcType;
typedef struct
{
    /* data */
    VertexType vexs[MVNum];
    ArcType arcs[MVNum][MVNum];
    int vexnum,arcnum;
} AMGraph;
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
int CreateUDN(AMGraph &G)
{
    int i,j,k;
    VertexType v1,v2;
    ArcType w;
    cin>>G.vexnum>>G.arcnum;
    for(i=0;i<G.vexnum;i++)
    {
        cin>>G.vexs[i];
    }
    for(i=0;i<G.vexnum;i++)
    {
        for(j=0;j<G.vexnum;j++)
        {
            G.arcs[i][j]=MAX;
        }
    }
    for(k=0;k<G.arcnum;k++)
    {
        cin>>v1>>v2>>w;
        i=LocateVex(G,v1);
        j=LocateVex(G,v2);
        G.arcs[i][j]=w;
        G.arcs[j][i]=w;
        
    }
}