/*	Given n classes and their duration(start point and end point). When you enter in a class
	you can't go out from the class until it finishes. 
	How many classes you can attend?
	n <= 10^5
	i/p
6
1 2
3 8
1 5
7 9
6 7
4 8
	
	o/p
	2

	idea: sort the input on the basis of class end time and perform which class can be attend 
	next
*/
#include<iostream>
using namespace std;
#define MAX 100005
typedef struct Class {
	int startPoint;
	int endPoint;
};
int n;
Class classes[MAX];

void merge(int le, int ri) {
	if (le < ri) {
		int mid = le + ((ri - le) >> 1);
		merge(le, mid);
		merge(mid + 1, ri);

		int l = mid - le + 1;
		int r = ri - mid;

		Class *a = (Class *)malloc(l * sizeof(Class));
		Class *b = (Class *)malloc(r * sizeof(Class));

		int i, j, k;
		for (i = 0, j = le; i < l; i++, j++)
			a[i] = classes[j];
		for (i = 0, j = mid + 1; i < r; i++, j++)
			b[i] = classes[j];

		i = 0, j = 0, k = le;
		while (i < l && j < r)
		{
			if (a[i].endPoint <= b[j].endPoint)
				classes[k++] = a[i++];
			else
				classes[k++] = b[j++];
		}

		while (i < l)
		{
			classes[k++] = a[i++];
		}

		while (j < r)
		{
			classes[k++] = b[j++];
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(false);

	cin >> n;
	int s, e;
	for (int i = 0; i < n; i++) {
		cin >> s >> e;
		classes[i].startPoint = s;
		classes[i].endPoint = e;
	}

	merge(0, n - 1);

	int cnt = 1;
	int en_point = classes[0].endPoint;
	for (int i = 1; i < n; i++) {
		if (classes[i].startPoint > en_point) {
			cnt++;
			en_point = classes[i].endPoint;
		}
	}

	cout << "Max classes can be attend = " << cnt << "\n";
	return 0;
}