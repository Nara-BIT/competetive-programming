class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        int sum=0;
        //int i,j;
        vector<int>candies(n);
        
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            arr[i]=1;
            //R2L[i]=1;
        }
        if(n==1)
            return 1;
        
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                arr[i]=1+arr[i-1];
            }
        }
        for(int j=n-2;j>=0;j--){
            if(ratings[j]>ratings[j+1]){
                arr[j]=max(arr[j],arr[j+1]+1);
            }
        }
        for(int i=0;i<n;i++){
            sum=sum+arr[i];
        }
        return sum;
        
    }
};