/*Given a n length sequence of letters/digits/colors. find maximum consecutive portion of the
sequence which have exactly less or equal to k=2 letters/digits/colors
i/p
21
5 9 3 3 3 9 5 3 6 5 1 1 1 1 1 1 1 3 9 9 7
o/p
8
similar problem: spoj broken, cf pokemon go

idea: use two pointer technique
*/
#include<iostream>
using namespace std;
#define max(a,b) ((a)>(b)?(a):(b))
#define MAX 100005
int arr[MAX];
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(false);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int cnt = 1;
	int l = 0, r = 1;
	int diff = 1;
	int c=arr[0], d=arr[0];
	int ctype = 1;
	int dtype = 0;
	int mx = 1;
	while (r < n)
	{
		if (diff == 1 && c == arr[r]) {
			cnt++;
			ctype++;
			mx = max(cnt, mx);
		}
		else if (diff == 1 && c != arr[r]) {
			diff++;
			cnt++;
			mx = max(cnt, mx);
			d = arr[r];
			dtype++;
		}
		else if (diff == 2 && (c == arr[r] || d == arr[r])) {
			cnt++;
			if (arr[r] == c)
				ctype++;
			else
				dtype++;
			mx = max(cnt, mx);
		}
		else if (diff == 2 && c != arr[r] && d != arr[r]) {
			while (true)
			{
				if (arr[l] == c && ctype > 0)
				{
					ctype--;
				}
				else if(arr[l] == d && dtype > 0 ) {
					dtype--;
				}
				cnt--;
				l++;
				if (ctype == 0 ) {
					c = arr[r];
					ctype++;
					cnt++;
					break;
				}
				else if (dtype == 0) {
					d = arr[r];
					dtype++;
					cnt++;
					break;
				}
				
			}

		}
		r++;
	}

	cout << mx << "\n";
	return 0;
}

/*
i/p
5
1 2 3 4 5
o/p
2

5
1 1 1 1 1
5

5
1 1 1 2 2
5

5
1 2 2 1 1
5

5
1 2 3 2 1
3

*/