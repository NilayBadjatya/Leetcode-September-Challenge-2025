class Solution {
public:

    bool isVowel(char a){return a == 'a' || a == 'e' || a == 'i' || a == 'o' ||
                                a == 'u' || a == 'A' || a == 'E' || a == 'I' ||
                                a == 'O' || a == 'U';}

    bool doesAliceWin(string s) {
        int count = 0;
        for(auto& ch : s){
            if(isVowel(ch)){
                count++;
            }
        }

        if(count == 0) return false;
        return true;
    }
};
