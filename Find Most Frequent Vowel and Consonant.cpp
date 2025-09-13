class Solution {
public:

    bool isVowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    int maxFreqSum(string s) {
        vector<int> freq(26, 0);
        int v = 0, c = 0;
        for(auto& ch : s){
            freq[ch - 'a']++;
            if(isVowel(ch)){
                v = max(v, freq[ch - 'a']);
            }else{
                c = max(c, freq[ch - 'a']);
            }
        }
        return c+v;
    }
};
