class Solution {
public:

    vector<int> converted(string& version){
        stringstream ss(version);
        string word;
        vector<int> ver;
        while(getline(ss, word, '.')){
            int x = stoi(word);
            ver.push_back(x);
        }
        return ver;
    }

    int compareVersion(string version1, string version2) {
        vector<int> ver1 = converted(version1);
        vector<int> ver2 = converted(version2);

        int n = ver1.size(), m = ver2.size();
        int i = 0, j = 0;
        while(i < n && j < m){
            if(ver1[i] > ver2[j]){
                return 1;
            }else if(ver1[i] < ver2[j]){
                return -1;
            }
            i++;
            j++;
        }

        while(i < n){
            if(ver1[i] > 0){
                return 1;
            }
            i++;
        }

        while(j < m){
            if(ver2[j] > 0){
                return -1;
            }
            j++;
        }

        return 0;
    }
};
