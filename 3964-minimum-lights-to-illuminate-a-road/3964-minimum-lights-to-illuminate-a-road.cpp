class Solution {
public:
    int minLights(vector<int>& lights) {
        int n=lights.size();
        vector<int>diff(n+1,0);
        for(int i=0;i<n;i++){
            int v=lights[i];
            if(v>0){
                int left=max(0,i-v);
                int right=min(n-1,i+v);
                diff[left]++;
                diff[right+1]--;
            }
        }
        int dark_len=0;
        int cnt=0;
        int curr=0;
        for(int i=0;i<n;i++){
            curr+=diff[i];
            if(curr==0){
                dark_len++;
            }
            else{
                if(dark_len>0){
                cnt+=(dark_len+2)/3;
                dark_len=0;
                }
            }
        }
        if(dark_len>0){
            cnt+=(dark_len+2)/3;
        }
        return cnt;
        
    }
};