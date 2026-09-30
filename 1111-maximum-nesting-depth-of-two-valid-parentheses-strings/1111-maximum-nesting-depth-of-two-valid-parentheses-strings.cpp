class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int balance=0;
        vector<int>ans;
        for(char& c:seq){
            if(c=='('){
                balance++;
                ans.push_back(balance%2);
            }
            else{
                ans.push_back(balance%2);
                balance--;
            }
        }
        return ans;
    }
};