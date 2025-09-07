class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        if(n % 2 != 0){
            ans.push_back(0);
        }
        int ele = 1;
        while(ele <= n/2){
            ans.push_back(ele);
            ans.push_back(-ele);
            ele++;
        }
        return ans;
    }
};
