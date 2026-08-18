class Solution {
public:
    int maximumGap(string skill, string station) {
        int n=skill.size();
        int m=station.size();
        if(n<=1){
            return 0;
        }
        vector<int>left_pos(n);
        vector<int>right_pos(n);
        int worker_idx=0;
        for(int i=0;i<m && worker_idx<n;i++){
            if(skill[worker_idx]==station[i]){
                left_pos[worker_idx]=i;
                worker_idx++;
            }
        }
        worker_idx=n-1;
        for(int j=m-1;j>=0 && worker_idx>=0;j--){
            if(skill[worker_idx]==station[j]){
                right_pos[worker_idx]=j;
                worker_idx--;
            }
        }
        int max_gap=0;
        for(int i=1;i<n;i++){
            int curr_gap=right_pos[i]-left_pos[i-1];
            max_gap=max(curr_gap,max_gap);
        }
        return max_gap;
    }
};