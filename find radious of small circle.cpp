/*Given 3 toucing each other circle's radious r1, r2, and r3.
find the inner touching circle's radious of them

Idea: binary search. ABC is the triangle of the centre points where AB = r1+r3
AC = r1+r2, BC = r2+r3
Again, let's D is the centre point of small circle. So add A, D; B,D and C,D 
so ABC = ABD + BCD + ACD. now binary search on radious r4*/

#include<iostream>
#include<cmath>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
#define precision 0.000001
double r1, r2, r3, r4;

double area(double a, double b, double c) {
	double s = (a + b + c) / 2;
	return sqrt(s*(s - a)*(s - b)*(s - c));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(false);

	cin >> r1 >> r2 >> r3;

	double abc = area(r1 + r2, r2 + r3, r3 + r1);

	double low = 0, high = max(max(r1, r2), r3);
	double mid;
	double r4 = 0;
	while (true)	// or iterate 60 or 100 times
	{
		mid = (low + high) / 2.0;

		double abd = area(r1 + r3, r3 + mid, mid + r1);
		double bcd = area(mid + r3, r3 + r2, r2 + mid);
		double acd = area(mid + r2, r2 + r1, r1 + mid);
		if (fabs(abc - abd - bcd - acd) < precision) {
			r4 = mid;
			break;
		}
		else if (abd + bcd + acd > abc)
			high = mid;
		else if (abd + bcd + acd < abc)
			low = mid;
	}
	cout << r4 << "\n";
	return 0;
}