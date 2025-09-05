class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for(int k = 0; k < 61; k++){
            long long val = num1 - 1LL * k * num2;
            int bits = __builtin_popcountll(val);
            if(k >= bits && k <= val){
                return k;
            }
        }
        return -1;
    }
};
