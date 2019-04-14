#include <iostream>
#include <queue>
using namespace std;
/*
    given a array of n size arr[n]. and a window of k size.
    you have to slide the window from left to right and say the minimum or maximum value of the window.
    for example, given a row of n buildings; each building has different height h. you have to say maxi/min height when window is slided
*/

void max_window_elements()
{
	// idea: if greater element is found then pop all prev element
	// else push it in queue because it can be greater element later
    int arr[] = {4,1,2,3,0,6,7,8,3,2};
    // 4 3 3 6 7 8 8 8
    int n = sizeof arr / sizeof arr[0];
    unsigned int k = 3;
    queue<int>q;
    int Max = arr[0], i=1, left = 0;
    int max_index=0;
    q.push(arr[0]);
    while( i < n )
    {
        while( i - left + 1 <= k )
        {
            if( arr[i] > q.back() )
            {
                q.back()=arr[i];
                if( max_index < left )
                    Max = arr[i];
            }
            else
            {
                q.push(arr[i]);
            }
            if( q.size() >= k )
            {
                q.pop();
            }
            i++;
        }
        cout << Max << " ";
        left++;
    }
}

void min_window_elements()
{
	// idea: reverse of previous idea
    int arr[] = {4,1,2,3,0,6,7,8,3,2};
    // 1 1 0 0 0 6 3 2
    int n = sizeof arr / sizeof arr[0];
    unsigned int k = 3;
    queue<int>q;
    int Min = arr[0], i=1, left = 0,minIndex = 0;
    q.push(arr[0]);
    while( i < n )
    {
        while( i - left + 1 <= k )
        {
            if( q.front() > arr[i] )
            {
                q.pop();
                Min = arr[i];
                minIndex = i;
                q.push(arr[i]);
            }
            else
            {
                q.push(arr[i]);
            }
            if( q.size() > k )
            {
                q.pop();
                if( minIndex < left )
                    Min = q.front();
            }
            i++;
        }
        cout << Min << " ";
        left++;
    }
}
int main()
{   cout << "minimum elements of window of size k: \n";
    min_window_elements();
    cout << "\nmaximum elements of window of size k: \n";
    max_window_elements();
    return 0;
}
