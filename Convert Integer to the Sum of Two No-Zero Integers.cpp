class Solution {
public:

    bool isValid(int n){
        while(n > 0){
            int r = n % 10;
            if(r == 0) return false;
            n /= 10;
        }
        return true;
    }

    vector<int> getNoZeroIntegers(int n) {
        for(int a = 1; a < n; a++){
            int b = n - a;
            if(isValid(a) && isValid(b)){
                return {a, b};
            }
        }
        return {};
    }
};
