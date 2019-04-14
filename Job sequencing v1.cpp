/*Given an array of n jobs where every job has a deadline and associated profit 
if the job is finished before the deadline. It is also given that every job takes 
single unit of time, so the minimum possible deadline for any job is 1. 
How to maximize total profit if only one job can be scheduled at a time.
n <= 10^5
Idea: Sort the jobs reverse order according to profit then for each job find a free slot
from it's deadline slot to earlier slot and if found then add it to the job list  

O(n*n)		but it can solve in O(n) using union find data structure
i/p and o/p are given below
*/

#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 100005

typedef struct Job {
	int id;
	int deadline;
	int profit;
};

int n;
Job jobs[MAX];
bool slot[MAX] = { false };
int seq[MAX];

bool myfunc(Job a, Job b) {
	return a.profit > b.profit;
}

void job_sequence() {
	// for each job find it's slot

	for (int i = 0; i < n; i++) {
		// for job i, from it's last slot to earlier slot find free slot
		for (int j = min(n, jobs[i].deadline) - 1; j >= 0; j--) {
			if (slot[j] == false) {
				slot[j] = true;
				seq[j] = i;
				break;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(false);

	cin >> n;
	int id, dead, prof;

	for (int i = 0; i < n; i++) {
		cin >> id >> dead >> prof;
		jobs[i].id = id;
		jobs[i].deadline = dead;
		jobs[i].profit = prof;
	}

	sort(jobs, jobs + n, myfunc);

	job_sequence();

	// print the sequence
	cout << "Job sequence: ";
	int profit = 0;
	for (int i = 0; i < n; i++) {
		if (slot[i]) {
			cout << jobs[seq[i]].id << " ";
			profit += jobs[seq[i]].profit;
		}
	}

	cout << "\nTotal profit = " << profit << "\n";
	return 0;
}

/*
i/p
n
id deadline profit
4
1 4 20
2 1 10
3 1 40
4 1 30
o/p
3 1

i/p
5
1 2 100
2 1 19
3 2 27
4 1 25
5 3 15
o/p
3 1 5

i/p
5
1 5 100
2 2 70
3 1 20
4 4 100
5 5 150

*/