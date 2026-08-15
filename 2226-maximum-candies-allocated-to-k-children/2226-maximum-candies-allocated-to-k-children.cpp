class Solution {
    #define ll long long
public:
    bool canGetAll(vector<int>&candies,ll mid,ll k){
        ll cnt=0;
        for(ll elem:candies){
            if(elem>=mid){
                cnt+=elem/mid;
            }
        }
        return cnt>=k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        //sort(candies.begin(),candies.end());
        ll low=1;
        ll high=*max_element(candies.begin(),candies.end());
        ll mid;
        ll max_candies=0;

        while(low<=high){
            mid=low+(high-low)/2;
            if(canGetAll(candies,mid,k)){
                max_candies=mid;
                low=mid+1;
            }
            else
                high=mid-1;
        }
        return max_candies;



    }
};