#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Edge{
    int v1;
    int v2;
    int cost;

    Edge(){
        v1 = -1;
        v2 = -1;
        cost = -1;
    }

    Edge(int _v1, int _v2, int _cost){
        v1 = _v1;
        v2 = _v2;
        cost = _cost;
    }
};

struct Subset{
    int represent;
    int rank;

    Subset(){
        represent = -1;
        rank = 0;
    }

    Subset(int _represent){
        represent = _represent;
        rank = 0;
    }
};

bool compareEdges(Edge e1, Edge e2){
    return e1.cost > e2.cost;
}

int Find(Subset unia[], int i){
    while(unia[i].represent != i){
        i = unia[i].represent;
    }
    return i;
}

void Union(Subset unia[], int x, int y){
    int representX = Find(unia, x);
    int representY = Find(unia, y);

    if(unia[representX].rank == unia[representY].rank){
        unia[representX].represent = representY;
        unia[representY].rank += 1;
    }
    else if(unia[representX].rank > unia[representY].rank){
        unia[representY].represent = representX;
    }
    else {
        unia[representX].represent = representY;
    }    
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    Subset unia[n];
    Edge edges[m];

    for(int i = 0; i < n; i++){
        unia[i] = Subset(i);
    }

    int a,b,c;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        edges[i] = Edge(a-1,b-1,c);
    }

    sort(edges, edges+m, compareEdges);

    int min = INT_MAX;
    int i = 0;
    int numberEdges = 0;

    while(numberEdges < n && i < m){
        Edge next = edges[i];
        int A = Find(unia, next.v1);
        int B = Find(unia, next.v2);
        if(A != B){
            Union(unia, A, B);
            numberEdges+=1;
            min = next.cost;
        }
        i+=1;
    }
    cout<<min<<endl;
    
    return 0;
}