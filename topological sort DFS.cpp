/*  In topological sorting, we use a temporary stack. 
We first recursively call topological sorting for all its adjacent vertices, then push it to a stack. 
Finally, print contents of the stack. 
Note that a vertex is pushed to stack only when all of its adjacent vertices (and their adjacent vertices and so on) 
are already in the stack.  */

#include <iostream>

#include <list>

#include<stack>

using namespace std;

class Graph

{

int v;

list<int> *l;

public:

Graph(int v)

{

this->v = v;

l = new list<int>[v];

}

void addEdge(int a, int b)

{

l[a].push_back(b);

}

void sort(int i, bool visited[], stack <int> &s)

{

visited[i] = true;

list<int>::iterator j;

for(j=l[i].begin(); j!=l[i].end();j++) {

if(!visited[*j])

sort(*j,visited,s);

}

s.push(i);

}

void topological()

{

stack <int> s;

bool *visited = new bool[v];

for (int i = 0; i < v; i++)

visited[i] = false;

for (int i = 0; i < v; i++)

{

if(visited[i]==false)

sort(i,visited,s);

}

while(s.empty()==false)

{

cout<<s.top()<<" ";

s.pop();

}

}

};

int main()

{

Graph g(6);

g.addEdge(5, 2);

g.addEdge(5, 0);

g.addEdge(4, 0);

g.addEdge(4, 1);

g.addEdge(2, 3);

g.addEdge(3, 1);

g.topological();

}
