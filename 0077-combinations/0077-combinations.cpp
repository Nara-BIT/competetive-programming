class Solution {
public:
    vector<vector<int>>res;
    vector<int>temp;
    void backtrack(int x,int n,int k){
        if(temp.size()==k){
            res.push_back(temp);
            return;
        }
        int left=x;
        int need=k-temp.size();
        if(left>need){
            backtrack(x-1,n,k);
        }
        temp.push_back(x);
        backtrack(x-1,n,k);
        temp.pop_back();
        return;

    }
    vector<vector<int>> combine(int n, int k) {
        backtrack(n,n,k);
        return res;
    }
};