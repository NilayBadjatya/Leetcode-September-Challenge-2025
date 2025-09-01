class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extra) {
        int n = classes.size();
        priority_queue<pair<double, vector<int>>> pq;
        for(int i = 0; i < n; i++){
            int pass = classes[i][0];
            int total = classes[i][1];
            double init = pass / (total * 1.0);
            double adding = (pass + 1) / ((total + 1) * 1.0);
            double diff = adding - init;
            pq.push({diff, {pass, total}});
        }

        while(extra--){
            int pass = pq.top().second[0]+1;
            int total = pq.top().second[1]+1;
            pq.pop();
            double init = pass / (total * 1.0);
            double adding = (pass + 1) / ((total + 1) * 1.0);
            double diff = adding - init;
            pq.push({diff, {pass, total}});
        }
        double ans = 0;
        while(!pq.empty()){
            int pass = pq.top().second[0];
            int total = pq.top().second[1];
            double init = pass / (total * 1.0);
            ans += init;
            pq.pop();
        }
        return ans / n;
    }
};
