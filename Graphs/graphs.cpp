/*
G = (V,E)

Directed Graph
Undirected Graph

Indegree 
Outdegree
Degree

Non-connected Graph
Articulation points

Parallel Edges 
Adjacent Edges

Path
Cycle
*/

/*
Representation of Undirected Graphs           1-----2
                                              |  \  |
G = (V,E)                                     4-----3
|V| = n = 5                                    \   /                       
|E| = e = 7                                      5

Adjancy Matrix                  Instead of 1 we can use weights(Cost Adjancy Matrix)
    1   2   3   4   5
1   0   1   1   1   0
2   1   0   1   0   0
3   1   1   0   1   1
4   1   0   1   0   1
5   0   0   1   1   0 

Adjancy List                    In nodes along with Weights(Cost Adjancy List)
1| -> 2 -> 3 -> 4
2| -> 1 -> 3
3| -> 1 -> 2 -> 4 -> 5 
4| -> 1 -> 3 -> 5
5| -> 3 -> 4
*/

/*
Representation of Directed Graphs
1 -> 2
⬇ ↖ ⬇
4 -> 3

|V| =  4
|E| =  5

Adjancy Matrix
    1  2  3  4
1   0  1  0  1
2   0  0  1  0
3   1  0  0  0
4   0  0  1  0

Adjancy List
Outward AL
1| -> 2 -> 4 
2| -> 3
3| -> 1
4| -> 3
Inward AL
1| -> 3
2| -> 1
3| -> 2 -> 4
4| -> 1
*/

/*
BFS
Visited
Exploring
*/

/*
DFS
Visited
Exploring
*/

#include <iostream>
#include <queue>
using namespace std;
void bfs(int G[][7], int start,int n){
    int i = start;
    queue<int> q;
    int visited[7] = {0};
    cout << " " << i << " ";
    visited[i] = 1;
    q.push(i);

    while (!q.empty())
    {
        i = q.front();
        q.pop();
        for (int j = 1; j < n; j++)
        {
            if(G[i][j] == 1 && visited[j] == 0){
                cout << " " << j << " ";
                visited[j] = 1;
                q.push(j);
            }
        }
    }
    
}
void dfs(int G[][7],int start,int n){
    static int visited[7] = {0};
    if(visited[start] == 0){
        cout << " " << start << " ";
        visited[start] = 1;
        
        for(int j = 1; j < n; j++){
            if(G[start][j] == 1 && visited[j] == 0){
                dfs(G,j,n);
            }
        }
    }
}

int main(){
    int graph[7][7] = {{0,0,0,0,0,0,0},
                       {0,0,1,1,0,0,0},
                       {0,1,0,0,1,0,0},
                       {0,1,0,0,1,0,0},
                       {0,0,1,1,0,1,1},
                       {0,0,0,0,1,0,0},
                       {0,0,0,0,1,0,0}};

    // bfs(graph,3,7);
    // dfs(graph,1,7);
    
    cout << endl;
    return 0;
}