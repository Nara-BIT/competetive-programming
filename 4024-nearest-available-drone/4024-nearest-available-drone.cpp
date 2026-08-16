class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int n=drones.size();
        int ans=1e9;
        int index=-1;
        for(int i=n-1;i>=0;i--){
            int man_dist=abs(drones[i][0]-target[0])+abs(drones[i][1]-target[1]);
            int range=drones[i][2];
            if(man_dist<=ans && man_dist<=range){
                ans=man_dist;
                index=i;
            }
        }
        return index;
    }
};