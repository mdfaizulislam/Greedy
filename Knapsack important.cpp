/*Sometimes greedy method doesn't work for 0/1 knapsack. Then dp is to rescue. 
But if the valus max limit is 10^9 then we can't implement dp. In this case subset generation is
used. Here no of elements will not exceed 30. We will solve the problem in the following procedure
1. divide whole set into two eqaul subset
2. generate subset for the second part and for each subset calculate knapsack and store in a 
   array. after completion of above procedure, sort the array
3. Generate subset of the first part, and for each part calculate knapsack and subtract from from
   total knapsack and find largest matching value from the previous array using binary search
4. and keep track of the maximum ans

complexity: log(n)*2^n = n*2^n
It's has a nice name: meet in the middle
i/p	// weight = profit
n w
6 27
3 7 11 8 2 4
o/p
26
think: coin change problem can be solve in this way
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
#define MAX_N 31
#define MAX_SUB 40000
int n, w;
int arr[MAX_N];
queue<int>q, que;
int container[MAX_SUB];
int Size = 0;
void subset(int index, int length) {
	if (index == length) {
		int sum = 0;
		while (!q.empty())
		{
			sum += q.front();
			//cout << q.front() << " ";
			que.push(q.front());
			q.pop();
		}
		//cout << "\n";
		container[Size++] = sum;
		while (!que.empty())
		{
			q.push(que.front());
			que.pop();
		}
		return;
	}

	subset(index + 1,length);
	q.push(arr[index]);
	subset(index + 1,length);
	q.pop();
}

int binary_search(int k) {
	
	int l = 0, h = Size - 1, mid;
	int ans = 0;
	while (l < h)
	{
		mid = l + ((h - l) >> 1);
		if (container[mid] == k) {
			return container[mid];
		}
		else if (container[mid] > k) {
			h = mid - 1;
		}
		else {
			ans = container[mid];
			l = mid + 1;
		}
	}
	return ans;
}

int max_profit = -1;
void sub(int index, int length) {
	if (index == length) {
		int s = 0;
		while (!q.empty())
		{
			s += q.front();
			que.push(q.front());
			q.pop();
		}
		while (!que.empty())
		{
			q.push(que.front());
			que.pop();
		}

		max_profit = max(max_profit, s + binary_search(w - s));

		return;
	}

	sub(index + 1, length);
	q.push(arr[index]);
	sub(index + 1, length);
	q.pop();
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(false);
	cin >> n >> w;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	int mid = (n >> 1);
	subset(0, mid);
	sort(container, container + Size);


	sub(mid, n);

	cout << "max profit: " << max_profit << "\n";
	return 0;
}