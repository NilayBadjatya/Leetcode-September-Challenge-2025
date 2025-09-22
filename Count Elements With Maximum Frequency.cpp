class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mp;
        int maxFreq = 0;
        for(auto& x : nums){
            mp[x]++;
            maxFreq = max(maxFreq, mp[x]);
        }

        int count = 0;
        for(auto& x : mp){
            if(x.second == maxFreq){
                count += maxFreq;
            }
        }

        return count;
    }
};
