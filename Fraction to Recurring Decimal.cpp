typedef long long ll;
class Solution {
public:
    string fractionToDecimal(int n1, int d1) {
        if(n1 == 0){
            return "0";
        }
        string result = "";
        if(1LL * n1 * d1 < 0){
            result += '-';
        }
        ll n = labs(n1);
        ll d = labs(d1);
        ll llDiv = n / d;
        result += to_string(llDiv);
        ll r = n % d;
        if(r == 0){
            return result;
        }
        result += '.';
        unordered_map<ll, ll> mp;
        while(r != 0){
            if(mp.count(r)){
                result.insert(mp[r], "(");
                result += ')';
                return result;
            }
            mp[r] = result.size();
            r *= 10;
            ll digit = r / d;
            result += to_string(digit);
            // cout << digit << " ";
            r = r % d;
        }
        return result;
    }
};
