class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int total=requests[0];
        int k=requests.size();
        for(int i=1;i<k;i++){
            total+=(abs(requests[i]-requests[i-1]));
        }
        return total;
    }
};