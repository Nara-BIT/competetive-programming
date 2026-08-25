class LockingTree {
public:
    vector<vector<int>>adj;
    vector<int>locked;
    vector<int>parent;
    LockingTree(vector<int>& parent) {
        this->parent=parent;
        int n=parent.size();
        adj.resize(n);
        for(int i=1;i<n;i++){
            adj[parent[i]].push_back(i);
        }
        locked.assign(n,-1);
        this->adj=adj;
        this->locked=locked;
    }
    
    bool lock(int num, int user) {
        if(locked[num]==-1){
            locked[num]=user;
            return true;
        }
        return false;
    }
    
    bool unlock(int num, int user) {
        if(locked[num]==user){
            locked[num]=-1;
            return true;
        }
        return false;
    }
    
    bool upgrade(int num, int user) {
        int i=num;
        if(locked[num]!=-1)
            return false;
        while(i!=-1){
            if(locked[i]!=-1){
                return false;
            }
            i=parent[i];
        }
        int cnt=0;
        queue<int>q;
        q.push(num);

        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int nbr:adj[node]){
                if(locked[nbr]!=-1){
                    locked[nbr]=-1;
                    cnt++;
                }
                q.push(nbr);
            }
        }

        if(cnt>0){
            locked[num]=user;
            return true;
        }
        return false;

    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */