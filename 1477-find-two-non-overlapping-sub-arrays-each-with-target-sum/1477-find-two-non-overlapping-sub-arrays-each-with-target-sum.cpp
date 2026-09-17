class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
       map<int,int>mpp;
       mpp[0]=-1;
       int n=arr.size();
       int sum=0;
       int ans=n+1;
       int min_length=n;
       for(int i=0;i<n;i++){
            sum+=arr[i];
            int diff=sum-target;
            if(mpp.find(diff)!=mpp.end()){
                int j=mpp[diff];
                int l=i-j;
                if(j!=-1){
                    ans=min(ans,l+arr[j]);
                }
                else{
                    ans=min(ans,l+n);
                }
                min_length=min(min_length,l);
            }
            arr[i]=min_length;
            mpp[sum]=i;
       }
        if(ans==n+1){
            return -1;
        }
        return ans;

    }
};