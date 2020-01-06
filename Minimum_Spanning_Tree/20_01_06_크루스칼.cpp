#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int num_nodes = 7; 
int num_edges = 11;

/*
Parent == Node라고 보아도 무방
*/

int getParent(int parent [], int node){
    if(parent[node] == node){
        return node;
    }
    
    return getParent(parent, parent[node]);
}

int findParent(int parent[],int x, int y){
    x = getParent(parent, x);
    y = getParent(parent, y);

    if (x==y){
        return 1;
    }
    else{
        return 0;
    }
}

int unionParent(int parent [], int x, int y){
    x = getParent(parent, x);
    y = getParent(parent, y);
    

    if (x < y){
        parent[y] =x;
        return x;
    }
    else{
        parent[x] = y;
        return y;
    }
}

class Edge{
    public:
    int node[2];
    int distance;
    
    Edge(int x, int y, int distance){
        this -> node[0] = x;
        this -> node[1] = y;
        this -> node[2] = distance;
    }

    bool operator <(Edge &edge){
        return this -> distance -> edge.distance;
    }
};

int main(int argc, char* argv[]){
    vector<Edge> v;
    v.push_back(Edge(1,7,12));
    v.push_back(Edge(4, 7, 13)); // 2 
    v.push_back(Edge(1, 4, 18)); // 3 
    v.push_back(Edge(1, 2, 67)); // 4 
    v.push_back(Edge(1, 5, 17)); // 5 
    v.push_back(Edge(2, 4, 24)); // 6 
    v.push_back(Edge(2, 5, 62)); // 7 
    v.push_back(Edge(3, 5, 20)); // 8 
    v.push_back(Edge(3, 6, 37)); // 9 
    v.push_back(Edge(5, 6, 45)); // 10 
    v.push_back(Edge(5, 7, 73)); // 11

    // 1. Edge를 오름차순으로 정렬
    sort(v.begin(, v.end()));

    int parent[num_nodes];
    for (i=0; i<num_nodes; i++){
        parent[i] =i
    }

    int sum =0;
    for (i=0; i< v.size(); i++){
        if (!findParent(parent, v[i].node[0]-1, v[i].node[1]-1 ){
            sum += v[i].distance; // 연결을 하고 나면, 같은 부모를 갖게 되므로... 
            unionParent(parent, v[i].node[0]-1, v[i].node[1]-1);
        })
    }
    
    cout<<sum<<endl;
    return 0;
}

//https://hongku.tistory.com/159 참조