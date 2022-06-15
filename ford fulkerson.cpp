#include<bits/stdc++.h>
using namespace std;
#define n 6

bool bfs(int rgraph[n][n],int parent[],int s,int t) {
	bool visited[n];
	for(int i=0;i<n;i++) {
		visited[i]=false;
	}
	queue<int> q;
	q.push(s);
	parent[s]=-1;
	visited[s]=true;
	
	while(!q.empty()) {
		int u=q.front();
		q.pop();
		for(int v=0;v<n;v++) {
			if(visited[v]==false && rgraph[u][v]>0) {
				if(v==t) {
					parent[v]=u;
				    return true;
				}
				q.push(v);
			    parent[v]=u;
			    visited[v]=true;
			}
			
		}
	}
	return false;
}

int ford_fulkerson(int graph[n][n],int s,int t) {
	int parent[n];
	int rgraph[n][n];
	for(int u=0;u<n;u++) {
		for(int v=0;v<n;v++) {
			rgraph[u][v]=graph[u][v];
		}
	}
	int max_flow=0;
	int u;
	while(bfs(rgraph,parent,s,t)) {
		int path_flow=INT_MAX;
		for(int v=t;v!=s;v=parent[v]) {
			u=parent[v];
			path_flow=min(path_flow,rgraph[u][v]);
		}
		for(int v=t;v!=s;v=parent[v]) {
			u=parent[v];
			rgraph[u][v] = rgraph[u][v] - path_flow;
			rgraph[v][u] = rgraph[v][u] + path_flow;
		}
		max_flow=max_flow+path_flow;
	}
	return max_flow;
}

int main() {
	int graph[n][n] = { { 0, 16, 13, 0, 0, 0 }, { 0, 0, 10, 12, 0, 0 },
            { 0, 4, 0, 0, 14, 0 },  { 0, 0, 9, 0, 0, 20 },
            { 0, 0, 0, 7, 0, 4 },   { 0, 0, 0, 0, 0, 0 } };
    cout<<ford_fulkerson(graph,0,5);
    return 0;
}
