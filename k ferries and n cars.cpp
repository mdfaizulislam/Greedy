/*প্রবলেমটা এরকম k সংখ্যক ফেরি ও n সংখ্যক গাড়ি লাইনে দাড়িয়ে আছে। গাড়ি গুলোর ভর দেয়া আছে। গাড়ি গুলোকে 
পরপর ফেরিতে পার করতে হবে। বের করতে হবে ফেরি গুলোর মিনিমাম ভরধারণ ক্ষমতা কত হলে গাড়ি গুলো পার করা যাবে। 
প্রতিটা গাড়ির ভরধারণ ক্ষমতা সমান হতে হবে। 

আবার, এভাবেও বলা যায়, k সংখ্যক ড্রাম ও n সংখ্যক বোতলে পানি দেয়া আছে। বোতলে পানির পরিমাণ দেয়া আছে। ড্রামের 
মিনিমাম পানি ধারণ ক্ষমতা কত হতে হবে?

Idea: use binary search
i/p
k n
3 9
3 5 1 4 3 7 2 9 6
o/p
15

3 8
3 5 1 4 3 7 2 9
o/p
13
*/
#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 100005
int n, k;
int arr[MAX];

bool canBeSolve(int ContainerSize) {
	int cnt = 0;
	int container = 0;
	bool f = false;
	for (int i = 0; i < n; i++) {
		container += arr[i];
		if (container > ContainerSize) {
			cnt++;
			container = arr[i];
			f = true;	// if flooded or remains extra
		}
		else if (container == ContainerSize) {
			cnt++;
			container = 0;
			f = false;
		}
		
		if (cnt > k)
			return false;
		else if (cnt == k && f)
			return false;
	}

	return true;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(false);

	cin >> k >> n;
	
	int total = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		total += arr[i];
	}
	//cout << canBeSolve(3) << "\n";
	// /*
	int ans = 0;
	int low = 1, high = total, mid;

	while (  high-low > 1)
	{
		mid = low + ((high - low) >> 1);
		if (canBeSolve(mid)) {
			ans = mid;
			high = mid;
		}
		else
			low = mid;
	}
	cout << "Required ferry size : " << ans << "\n";
	// */
	return 0;
}