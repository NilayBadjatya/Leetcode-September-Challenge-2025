class Spreadsheet {
public:
    vector<vector<int>> a;
    Spreadsheet(int rows) {
        vector<vector<int>> temp(rows+1, vector<int> (26, 0));
        a = temp;
    }
    
    void setCell(string cell, int value) {
        int col = tolower(cell[0]) - 'a';
        int row = stoi(cell.substr(1));
        a[row][col] = value;
    }
    
    void resetCell(string cell) {
        int col = tolower(cell[0]) - 'a';
        int row = stoi(cell.substr(1));
        a[row][col] = 0;
    }
    
    int getValue(string formula) {
        string x = "", y = "";
        int i = 1;
        while(formula[i] != '+'){
            x += formula[i];
            i++;
        }
        i++;
        while(i < formula.size()){
            y += formula[i];
            i++;
        }
        int ans = 0;
        if(x[0] >= 65 && x[0] <= 90){
            int col = tolower(x[0]) - 'a';
            int row = stoi(x.substr(1));
            ans += a[row][col];
        }else{
            ans += stoi(x);
        }

        if(y[0] >= 65 && y[0] <= 90){
            int col = tolower(y[0]) - 'a';
            int row = stoi(y.substr(1));
            ans += a[row][col];
        }else{
            ans += stoi(y);
        }
        return ans;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
