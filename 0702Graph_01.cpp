#include <iostream>
#include <vector>
#include <queue>

#define INF 99999

using namespace std;

int main(){
    int num_of_cases, wh, cur_x, cur_y, dest_x, dest_y = 0;

    cin >> num_of_cases;

    for(int i = 0; i < num_of_cases; i ++){
        cin >> wh;
        cin >> cur_x >> cur_y;
        cin >> dest_x >> dest_y;
        int start = cur_x + (cur_y * wh) + 1; 
        int dest = dest_x + (dest_y * wh) + 1;
        int V = wh * wh;
        int E = 2*4 + 3*8 + 4*4*(wh-4+1) + 6*4*(wh-5+1) + 8*(wh-4)*(wh-4);        
        
        vector<pair<int,int> > arr[V+1];

        for(int i = 1; i <= E; i++){            
            if(((wh-(i%wh)) >= 2) && ((i+2) + wh < V)){
                arr[i].push_back( {i+2+wh, 1} );
            }
            if(((wh-(i%wh)) >= 2) && ((i+2) - wh > 1)){
                arr[i].push_back( {i+2-wh,1} );
            }
            if((i%wh > 2) && ((i-2) + wh < V)){
                arr[i].push_back( {i-2+wh,1} );
            }
            if((i%wh > 2) && ((i-2) - wh > 1)){
                arr[i].push_back( {i-2-wh,1} );
            }
            if(((wh-(i%wh)) >= 1) && ((i+1) + wh + wh < V)){
                arr[i].push_back( {i+1+wh+wh,1} );
            }
            if(((wh-(i%wh)) >= 1) && ((i+1) - wh - wh > 1)){
                arr[i].push_back( {i+1-wh-wh,1} );
            }
            if((i%wh > 1) && ((i-1) + wh + wh < V)){
                arr[i].push_back( {i-1+wh+wh,1} );
            }
            if((i%wh > 1) && ((i-1) - wh - wh > 1)){
                arr[i].push_back( {i-1-wh-wh,1} );
            }            
        }        

        int dist[V + 1];
        fill(dist, dist + V + 1, INF);        
        priority_queue<pair<int,int> > qu;

        qu.push( {0, start} );
        dist[start] = 0;

        while(!qu.empty()){
            int cost = -qu.top().first;
            int here = qu.top().second;

            qu.pop();

            for(int i = 0 ; i < arr[here].size(); i ++){
                int next = arr[here][i].first;
                int nextcost = arr[here][i].second;

                if(dist[next] > dist[here] + nextcost){
                    dist[next] = dist[here] + nextcost;
                    qu.push( {-dist[next],next} );
                }
            }
        }
        
        printf("%d\n", dist[dest]);
        
    }

}