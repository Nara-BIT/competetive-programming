class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curr_sum=0;
        int total_sum=0;
        int n=gas.size();
        int start=0;
        for(int i=0;i<n;i++){
            curr_sum+=gas[i]-cost[i];
            total_sum+=gas[i]-cost[i];
            if(curr_sum<0){
                start=(i+1);
                curr_sum=0;
            }
        }
        if(total_sum>=0)
            return start;
        return -1;
    }
};