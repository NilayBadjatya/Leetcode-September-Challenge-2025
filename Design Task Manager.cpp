class TaskManager {
public:
    unordered_map<int, vector<int>> mp;
    unordered_map<int, set<int>> prio;
    TaskManager(vector<vector<int>>& tasks) {
        for(auto& t : tasks){
            int u = t[0];
            int task = t[1];
            int pr = t[2];
            mp[task] = {u, pr};
            prio[pr].insert(task);
        }
    }
    
    void add(int userId, int taskId, int p) {
        mp[taskId] = {userId, p};
        prio[p].insert(taskId);
    }
    
    void edit(int taskId, int newPriority) {
        int oldP = mp[taskId][1];
        mp[taskId][1] = newPriority;
        prio[oldP].erase(taskId);
        if(prio[oldP].size() == 0){
            prio.erase(oldP);
        }
        prio[newPriority].insert(taskId);
    }
    
    void rmv(int taskId) {
        int p = mp[taskId][1];
        mp.erase(taskId);
        prio[p].erase(taskId);
        if(prio[p].size() == 0){
            prio.erase(p);
        }
    }
    
    int execTop() {
        int p = INT_MIN;
        for(auto& x : prio){
            p = max(p, x.first);
        }
        if(p == INT_MIN) return -1;
        int task = *prio[p].rbegin();
        prio[p].erase(task);
        if(prio[p].size() == 0){
            prio.erase(p);
        }
        int user = mp[task][0];
        mp.erase(task);
        return user;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
