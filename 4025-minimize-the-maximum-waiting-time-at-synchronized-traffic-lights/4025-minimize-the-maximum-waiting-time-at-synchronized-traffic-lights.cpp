class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int max_light=0;
        for(int light:lights){
            max_light=max(max_light,light);
        }
        int max_penalty=0;
        for(int t:arrivalTime){
            int r=t%period;
            if(r>=max_light){
                max_penalty=max(max_penalty,period-r);
            }
        }
        return max_penalty;
    }
};