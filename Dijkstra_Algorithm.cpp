// code by yctseng1227
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct edge{
    int e,w;
};
inline bool operator<(const edge &a,const edge &b){
    return a.w>b.w; //Notice!
}

vector<edge> V[10000];//Graph Data
int dist[10000]; //Save the distance from S
int N,M,S,E;
int main(){
    int a,b,w;
    while(~scanf("%d%d",&N,&M)){
        for(int i=0;i<N;++i) V[i].clear();
        memset(dist,0x3f,sizeof(dist)); //init to INF

        while(M--){
            //Add edge(a to b with w)
            scanf("%d%d%d",&a,&b,&w);
            V[a].push_back((edge){b,w});
            V[b].push_back((edge){a,w});
        }

        scanf("%d%d",&S,&E); //ask
        //Algorithm:Dijkstra with Priority Queue
        priority_queue<edge> pq;
        pq.push((edge){S,0});
        while(!pq.empty()){
            edge t=pq.top();pq.pop();
            if(t.e==E){
                dist[t.e]=t.w;
                break; //Find answer!
           }
            if(dist[t.e]!=0x3f3f3f3f)continue;
            dist[t.e]=t.w;
            for(edge &e:V[t.e])
                if(dist[e.e]>dist[t.e]+e.w)
                    pq.push((edge){e.e,dist[t.e]+e.w});
        }
        printf("%d\n",dist[E]);
    }
}
