#include<iostream>
#include<iomanip>
using namespace std;

#define MVNum 100
#define OK 1

typedef string VerTexType;
typedef int OtherInfo;

typedef struct ArcNode
{
    int adjvex;
    struct ArcNode *nextarc;
    OtherInfo info;

}ArcNode;

 typedef struct VNode
 {
    VerTexType data;
    ArcNode *firstarc;
 }VNode,AdjList[MVNum];

typedef struct
{
    AdjList vertices;
    int vexnum,arcnum;
}Graph;

VerTexType Vertexdata(const Graph &g,int i)
{
    return g.vertices[i].data;
}

int LocateVex(const Graph &g,VerTexType v)
{
    for(int i=0;i<g.vexnum;i++)
        if(g.vertices[i].data==v)
        return i;
        return -1;
}

int FirstAdjVex(const Graph &g,int v)
{
    if(g.vertices[v].firstarc==NULL)
    return -1;
    else
    {
        return g.vertices[v].firstarc->adjvex;
    }
}

int NextAdjVex(const Graph &g,int v,int w)
{
    ArcNode *p=g.vertices[v].firstarc;
    while(p!=NULL)
    {
        if(p->adjvex==w)
        {
            if(p->nextarc==NULL)
            return -1;
            else
            return p->nextarc->adjvex;
        }
        else 
        p=p->nextarc;
    }
}
void sort(ArcNode  *arclist)
{
    ArcNode *p=arclist;
    ArcNode *q=arclist;
    while(q!=NULL)
    {
        q=p->nextarc;
        if(p->adjvex>q->adjvex)
        {int temp=p->adjvex;
        p->adjvex=q->adjvex;
        q->adjvex=temp;}
        q=q->nextarc;

    }
    p=p->nextarc;

}

int CreateUDG(Graph &g)
{
    cin>>g.vexnum>>g.arcnum;
    for(int i=0;i<g.vexnum;i++)
    {
        cin>>g.vertices[i].data;
        g.vertices[i].firstarc=NULL;
    }
    for(int i=0;i<g.arcnum;i++)
    {
        string v1,v2;
        int a,b;
        cin>>v1>>v2;
        a=LocateVex(g,v1);
        b=LocateVex(g,v2);
        ArcNode *p=new ArcNode;
        p->adjvex=b;
        p->nextarc=g.vertices[a].firstarc;
        g.vertices[a].firstarc=p;
        ArcNode *q=new ArcNode;
        q->adjvex=a;
        q->nextarc=g.vertices[b].firstarc;
        g.vertices[b].firstarc=q;
    }
    int i;
    for(i=0;i<g.vexnum;i++)
    sort(g.vertices[i].firstarc);
    return OK;
}

int main()
{
    Graph g;
    CreateUDG(g);
    for(int i=0;i<g.vexnum;i++)
    {
        cout<<Vertexdata(g,i)<<":";
        for(int w=FirstAdjVex(g,i);w>=0;w=NextAdjVex(g,i,w))
        cout<<' '<<Vertexdata(g,w);
        cout<<endl;
    }
    return 0;
}