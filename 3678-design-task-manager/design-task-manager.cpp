#include <bits/stdc++.h>
using namespace std;

class TaskManager {
    struct Task {
        int priority;
        int taskId;
        int userId;
        bool operator<(const Task& other) const {
            if (priority == other.priority)
                return taskId < other.taskId; // higher taskId first if tie
            return priority < other.priority; // max-heap by priority
        }
    };

    priority_queue<Task> pq; 
    unordered_map<int, pair<int,int>> taskMap; 
    // taskId -> {priority, userId}

public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto &t : tasks) {
            int userId = t[0], taskId = t[1], priority = t[2];
            taskMap[taskId] = {priority, userId};
            pq.push({priority, taskId, userId});
        }
    }

    void add(int userId, int taskId, int priority) {
        taskMap[taskId] = {priority, userId};
        pq.push({priority, taskId, userId});
    }

    void edit(int taskId, int newPriority) {
        auto [oldPriority, userId] = taskMap[taskId];
        taskMap[taskId] = {newPriority, userId};
        pq.push({newPriority, taskId, userId}); 
        // old entry becomes stale, skipped later
    }

    void rmv(int taskId) {
        taskMap.erase(taskId); // mark as removed
    }

    int execTop() {
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            auto it = taskMap.find(top.taskId);
            if (it != taskMap.end() && it->second.first == top.priority) {
                int userId = it->second.second;
                taskMap.erase(it); // remove executed task
                return userId;
            }
            // otherwise skip stale entry
        }
        return -1; // no tasks available
    }
};
