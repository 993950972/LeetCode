/*
You are given a data structure of employee information, which includes the employee's unique id, his importance value and his direct subordinates' id.

For example, employee 1 is the leader of employee 2, and employee 2 is the leader of employee 3. They have importance value 15, 10 and 5, respectively. Then employee 1 has a data structure like [1, 15, [2]], and employee 2 has [2, 10, [3]], and employee 3 has [3, 5, []]. Note that although employee 3 is also a subordinate of employee 1, the relationship is not direct.

Now given the employee information of a company, and an employee id, you need to return the total importance value of this employee and all his subordinates.

Example 1:
	Input: [[1, 5, [2, 3]], [2, 3, []], [3, 3, []]], 1
	Output: 11
	Explanation:
	Employee 1 has importance value 5, and he has two direct subordinates: employee 2 and employee 3. They both have importance value 3. So the total importance value of employee 1 is 5 + 3 + 3 = 11.
Note:
	1.One employee has at most one direct leader and may have several subordinates.
	2.The maximum number of employees won't exceed 2000.
*/

/*
算法思想：使用广度优先遍历。使用队列来实现。每次遍历当前人员，将其管理的下属放入队列中。
*/
/*
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
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int ans = 0;
        int sz = employees.size();
        Employee* employee;
        for(int i = 0;i < sz;i++)
        {
            if((employees[i])->id == id)
            {
                 employee = employees[i];
                 break;
            }
        } 
        queue<Employee*> Q;
        Q.push(employee);
        while(!Q.empty())
        {
            employee = Q.front();
            ans += employee->importance;
            Q.pop();
            for(int i = 0;i < (employee->subordinates).size();i++)
            {
                for(int j = 0;j < sz;j++)
                {
                    if((employees[j])->id == (employee->subordinates)[i])
                    {
                         Q.push(employees[j]);
                         break;
                    }
                } 
            }
        }
        return ans;
    }
};

/*
discuss：方法值得借鉴。算法思想也是广度优先遍历，但是在搜索查找id的员工时，使用了hash map，非常好，大大缩短了搜索的时长。
*/

class Solution {
    public int getImportance(List<Employee> employees, int id) {
        int total = 0;
        Map<Integer, Employee> map = new HashMap<>();
        for (Employee employee : employees) {
            map.put(employee.id, employee);
        }
        Queue<Employee> queue = new LinkedList<>();
        queue.offer(map.get(id));
        while (!queue.isEmpty()) {
            Employee current = queue.poll();
            total += current.importance;
            for (int subordinate : current.subordinates) {
                queue.offer(map.get(subordinate));
            }
        }
        return total;
    }
}




class Solution {
    public int getImportance(List<Employee> employees, int id) {
        Map<Integer, Employee> map = new HashMap<>();
        for (Employee employee : employees) {
            map.put(employee.id, employee);
        }
        return getImportanceHelper(map, id);
    }
    
    private int getImportanceHelper(Map<Integer, Employee> map, int rootId) {
        Employee root = map.get(rootId);
        int total = root.importance;
        for (int subordinate : root.subordinates) {
            total += getImportanceHelper(map, subordinate);
        }
        return total;
    }
}