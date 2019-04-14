/*Given n classes and their duration(start, end) of a coaching
find the min teachers are required to operate the coaching
n <= 10^5
idea: find out the maximum overlapping portion
ক্লাসে প্রবেশ করলে +১ এবং ক্লাস থেকে বের হয়ে অন্য ক্লাসে প্রবেশ করলে অন্য ক্লাসের ইনডেক্সে -১ 
used অ্যারের কিউমিলিটিভ সাম সর্বোচ্চ যেটা হবে সেটাই উত্তর
i/p
6
1 2
1 5
4 8
6 7
3 7
7 9
o/p
4
*/
#include<iostream>
using namespace std;
#define MAX 100005
#define max(a,b) ((a)>(b)?(a):(b))

int n;
int used[MAX] = { 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(false);
	cin >> n;
	int s, e;
	int max_end_point = -1;
	for (int i = 0; i < n; i++) {
		cin >> s >> e;
		max_end_point = max(e, max_end_point);
		used[s]++;
		used[e + 1]--;
	}

	int cnt = 0;
	int mx = 0;
	for (int i = 0; i <= max_end_point+1; i++) {
		cnt += used[i];
		mx = max(mx, cnt);
	}
	cout << "Min teacher required is = " << mx << "\n";
	return 0;
}