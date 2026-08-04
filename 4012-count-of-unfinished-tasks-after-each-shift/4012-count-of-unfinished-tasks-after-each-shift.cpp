class Solution {
public:
    int UB(vector<long long>& prefix, long long target){
        int low=0;
        int high=prefix.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(prefix[mid]<=target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
           int n=tasks.size();
           int m=shifts.size();
           long long t_sum=0;
           int rem=n;
           vector<long long>prefix(n,0);
           vector<int>ans(m);
           prefix[0]=tasks[0];
           for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+tasks[i];
           }
           long long sum=prefix[n-1];
           for(int i=0;i<m;i++){
            t_sum+=shifts[i];
            if(t_sum>=sum){
                ans[i]=0;
                t_sum=0;
            }
            else{
                int idx=UB(prefix,t_sum);
                ans[i]=n-idx;
            }
           }
           return ans;
    }
};