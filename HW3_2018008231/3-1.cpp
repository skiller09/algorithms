#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

typedef struct node* nodeptr;
typedef nodeptr* Graph;
int Time = 0;
queue<int> q;

enum color{
        white,
        gray,
        black
};

struct node{
        color stat;
        int n; //# of adjacent node
        int* Adj; //adjacent list
        int pre; //predecessor
        int d; //discovery time
        int f; //finished time
};

Graph Build_Graph(int l, ifstream &infile){
	int i, j, cnt, x;
        int** adj_matrix = new int*[l+1];
        Graph G = new nodeptr[l+1];
        for(i=0;i<l;i++){
		G[i] = new struct node;
                adj_matrix[i] = new int[l];
                cnt = 0;
                for(j=0;j<l;j++){
                        infile >> adj_matrix[i][j];
                        if(adj_matrix[i][j]==1)
                                cnt++;
                }
                G[i]->Adj = new int[cnt+1];
		G[i]->n = cnt;
                x=0;
                for(j=0;j<l;j++){
                        if(adj_matrix[i][j]==1){
                                G[i]->Adj[x++] = j;
                        }
                }
		free(adj_matrix[i]);
        }
	free(adj_matrix);
	return G;
}

void DFS_visit(Graph G, int u);
//G: adjacency graph, n: # of nodes
void DFS(Graph G, int n){
        int i;
        for(i=0;i<n;i++){
                G[i]->stat = white;
                G[i]->pre = -1;
        }
        for(i=0;i<n;i++){
                if(G[i]->stat==white)
                        DFS_visit(G, i);
        }
}

void DFS_visit(Graph G, int u){
        ++Time;
        G[u]->d = Time;
        G[u]->stat = gray;
	q.push(u+1);
        int i, j;
        for(i=0;i<G[u]->n;i++){
                j = G[u]->Adj[i];
                nodeptr v = G[j];

                cout << "(" << u+1 << ", " << j+1 << ") ";
                if(v->stat==white){
                        cout << "tree edge" << endl;
                        v->pre = u;
                        DFS_visit(G, j);
                }
                else if(v->stat==gray)
                        cout << "back edge" << endl;
                else if(v->d > G[u]->d)
                        cout << "forward edge" << endl;
                else cout << "cross edge" << endl;
        }
        G[u]->stat = black;
        G[u]->f = ++Time;
}

int main(void){
        int l, i;
        ifstream infile("input3-1.txt");
        infile >> l;

	Graph G = Build_Graph(l, infile);

        DFS(G, l);

	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}
	cout<<endl;

	infile.close();
	for(i=0;i<l;i++){
		free(G[i]->Adj);
		free(G[i]);
	}
	free(G);
}
