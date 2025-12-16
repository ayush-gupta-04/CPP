class DisjointSet{
public:
    vector<int> parent;
    vector<int> size;

    DisjointSet(int n){
        parent.resize(n + 1);
        size.resize(n + 1);
        for(int i = 0;i <= n; i++){
            parent[i] = i;
            size[i] = 1;
        }   
    }

    void join(int u, int v){
        int pu = findParent(u);
        int pv = findParent(v);
        if(pu == pv) return;

        if(size[pu] > size[pv]){
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        else{
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }

    int findParent(int u){
        if(parent[u] == u){
            return u;
        }
        int p = findParent(parent[u]);
        parent[u] = p;
        return p;
    }
};
