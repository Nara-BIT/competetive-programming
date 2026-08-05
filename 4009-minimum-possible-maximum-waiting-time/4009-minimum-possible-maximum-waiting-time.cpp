class Solution {
public:
    unordered_map<long long,pair<int,int>>memo;
    long long compressState(int car_idx,int f0,int f1,int rel_t0,int rel_t1){
        long long key=car_idx;
        key=(key<<10)|f0;
        key=(key<<10)|f1;
        key=(key<<10)|rel_t0;
        key=(key<<10)|rel_t1;
        return key;
    }
    pair<int,int>chooseBestOutcome(pair<int,int>choice1,pair<int,int>choice2){
        if(choice1.first>choice2.first)return choice1;
        if(choice2.first>choice1.first)return choice2;
        return(choice1.second<choice2.second)?choice1:choice2;
    }
    pair<int,int>solve(int car_idx,const vector<int>&demand,int f0,int f1,int t0,int t1,int allowed_time){
        int n=demand.size();
        if(car_idx==n)return{car_idx,0};
        int rel_t0=max(0,t0-allowed_time);
        int rel_t1=max(0,t1-allowed_time);
        long long key=compressState(car_idx,f0,f1,rel_t0,rel_t1);
        if(memo.count(key))return memo[key];
        int demand_i=demand[car_idx];
        pair<int,int>choice0={car_idx,0};
        pair<int,int>choice1={car_idx,0};
        bool can_serve_any=false;
        if(f0>=demand_i){
            can_serve_any=true;
            int start_time=max(allowed_time,t0);
            int wait_time=start_time-allowed_time;
            int next_t0=start_time+demand_i;
            auto next_outcome=solve(car_idx+1,demand,f0-demand_i,f1,next_t0,t1,start_time);
            choice0={next_outcome.first,max(wait_time,next_outcome.second)};
        }
        if(f1>=demand_i){
            can_serve_any=true;
            int start_time=max(allowed_time,t1);
            int wait_time=start_time-allowed_time;
            int next_t1=start_time+demand_i;
            auto next_outcome=solve(car_idx+1,demand,f0,f1-demand_i,t0,next_t1,start_time);
            choice1={next_outcome.first,max(wait_time,next_outcome.second)};
        }
        pair<int,int>best_outcome=can_serve_any?chooseBestOutcome(choice0,choice1):pair<int,int>{car_idx,0};
        return memo[key]=best_outcome;
    }

    int minMaxWaitingTime(vector<int>& demand, vector<int>& fuel) {
        memo.clear();
        auto result=solve(0,demand,fuel[0],fuel[1],0,0,0);
        return(result.first==0)?-1:result.second;

    }
};