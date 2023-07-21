#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
    unordered_map<int,list<pair<int,int>>> adj;
    for(int i=0;i<edges;i++){
        
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> dist(vertices);
    for(int i = 0;i<vertices;i++){
        dist[i] = INT_MAX;
    }
    
    dist[source] = 0;
    pq.push({0,source});
    
    while(!pq.empty()){
        int topDistance = pq.top().first;
        int node = pq.top().second;
        
        pq.pop();
        
        for(auto i : adj[node]){
            if(topDistance + i.second < dist[i.first]){
                dist[i.first] = topDistance + i.second;
                pq.push({dist[i.first],i.first}); 
            }
        }
    }
    return dist;
}

int main(){
    int v;
    cin >> v;
    int e;
    cin >> e;
    int s;
    cin >> s;
    vector<vector<int>> pairs;
    for(int i = 0; i<e;i++){
        for(int j = 0; j<3; j++){
            cin >> pairs[i][j];
        }
    }
    dijkstra(pairs,v,e,s);
    return 0;
}