#include <iostream>
#include <map>
#include <vector>
#include <cassert>
using namespace std;
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};

// thanks dalao
class Solution {
public:
    int getImportance(vector<Employee*> em, int id) {
        unordered_map<int, Employee*> m;
        for (auto x : em) m[x->id] = x;
        
        int res = 0;
        // BFS
//         deque<Employee*> q;
//         q.push_back(m[id]);
//         while (!q.empty()) {
//             auto p = q.front();
//             q.pop_front();
//             for (auto x: p->subordinates) q.push_back(m[x]);
//             res += p->importance;
//         }
//         return res;
        DFS(m, id, res);
        return res;
    }

    void DFS(unordered_map<int, Employee*>& m, int id, int& sum){
        sum += m[id]->importance;
        for(auto x: m[id]->subordinates) DFS(m, x, sum);
    }
};

/* My useless trying... I was thinking doing some recursive search (turns out to be DFS)...
class Solution {
public:
    void print_vec(vector<int> v) {
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }
    // int findImportance(int id, int total, map<int, int> toIm, map<int, vector<int>> toSb) {
    //     vector<int> subs;
    //     cout << "id = " << id << ", total = " << total << endl;
    //     if (toSb.count(id) > 0)
    //         subs = toSb.at(id);
    //     else
    //         return total;

    //     total += toIm.at(id);
    //     cout << "subs: ";
    //     print_vec(subs);
    //     for (int i : subs)
    //         return total + findImportance(i, total, toIm, toSb);
    //     // return findImportance(-1, total, toIm, toSb);
    //     return total;
    // }

    int getImportance(vector<Employee*> em, int id) {
        int n = em.size();
        map<int, int> idToImportance;
        map<int, vector<int>> idToSubs; 
        for (int i = 0; i < n; i++) {
            idToImportance[em[i]->id] = em[i]->importance;
            idToSubs[em[i]->id]       = em[i]->subordinates;
        }
        
        for (auto it = idToImportance.begin(); it != idToImportance.end(); it++)
            cout << it->first << ", " << it->second << endl;
        
        cout << "=====================" << endl;
        for (auto it = idToSubs.begin(); it != idToSubs.end(); it++) {
            cout << it->first << ", ";
            print_vec(it->second);
        }
        cout << "=====================" << endl;
        // int res = findImportance(id, 0, idToImportance, idToSubs);
        int res = 0;
        for ()
        cout << "\t res = " << res << endl;
        return res;
    }
};
*/

int main() {
    Employee* e1 = new Employee();
    e1->id = 1;
    e1->importance = 5;
    e1->subordinates = {2,3};
    Employee* e2 = new Employee();
    e2->id = 2;
    e2->importance = 3;
    e2->subordinates = {};
    Employee* e3 = new Employee();
    e3->id = 3;
    e3->importance = 3;
    e3->subordinates = {};

    vector<Employee*> ems;
    ems.push_back(e1);
    ems.push_back(e2);
    ems.push_back(e3);
    int t1 = Solution().getImportance(ems, 1);
    assert(t1 == 11);
    return 0;
}
