class Solution {
public:

    long long findMinimumOps(int l, int r){
        long long ops = 0;
        vector<int> a;
        for(int i = l; i <= r; i++){
            a.push_back(i);
        }
        int n = a.size();
        int i = 0, j = n-1;
        while(i <= j){
            while(a[i] > 0 && a[j] > 0){
                a[i] /= 4;
                a[j] /= 4;
                ops++;
            }
            if(a[i] == 0) i++;
            if(a[j] == 0) j--;
        }
        return ops;
    }

    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;
        for(auto& q : queries){
            int u = q[0];
            int v = q[1];
            ans += findMinimumOps(u, v);
        }
        return ans;
    }
};
