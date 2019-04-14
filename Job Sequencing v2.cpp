/*Given n tasks with durations and deadlines and our task is to choose an order to
perform the tasks.For each task, we earn (d-x) points where d is the task’s deadline
and x is the moment when we finished the task. What is the largest possible total
score we can obtain? 
i/p
n
id duration deadline

4
1 4 2
2 3 5
3 2 7
4 4 5

o/p
3 2 1 4

0	1	2	3	4	5	6	7	8	9	10	11	12	13	14	15
------------------------------------------		optimal schedule
3		2			1				4

Idea: correct greedy strategy is to simply perform the tasks sorted by their durations 
in increasing order. Because the first task takes longer than the second task, we can 
obtain a better solution if we swap the tasks. see competitive programmer's hand book for better 
*/

#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 100005
typedef struct Job {
	int id;
	int duration;
	int deadline;
};

int n;
Job jobs[MAX];

bool myfunc(Job a, Job b) {
	return a.duration < b.duration;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(false);

	cin >> n;
	int Id, dura, dead;
	for (int i = 0; i < n; i++) {
		cin >> Id >> dura >> dead;
		jobs[i].id = Id;
		jobs[i].duration = dura;
		jobs[i].deadline = dead;
	}

	// now sort in increasing order
	sort(jobs, jobs + n, myfunc);

	// print sequence

	for (int i = 0; i < n; i++)
		cout << jobs[i].id << " ";
	return 0;
}