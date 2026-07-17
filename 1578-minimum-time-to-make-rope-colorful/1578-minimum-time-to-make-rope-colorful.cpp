class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=colors.size();
        long long sum=0;
        int curr_max=neededTime[0];
       
        for(int i=1;i<n;i++){
            if(colors[i]==colors[i-1]){
                sum+=min(curr_max,neededTime[i]);
                curr_max=max(curr_max,neededTime[i]);
            }
            else{
                curr_max=neededTime[i];
            }
            
        }
        return sum;
    }
};