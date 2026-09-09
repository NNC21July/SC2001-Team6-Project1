#include <vector>
#include <algorithm>
#include <iostream>
#define ll long long
using namespace std;

void mergeSortedArrs(vector<int> &arr, int l1, int r1, int l2, int r2, ll &comparisons)
{
    vector<int> ans;
    ans.reserve(l2 - r1 + 1);

    int i = l1, j = l2;
    while (i <= r1 && j <= r2)
    {
        comparisons++;
        if (arr[i] <= arr[j])
        {
            ans.push_back(arr[i]);
            i++;
        }
        else
        {
            ans.push_back(arr[j]);
            j++;
        }
    }
    while (i <= r1)
    {
        ans.push_back(arr[i]);
        i++;
    }
    while (j <= r2)
    {
        ans.push_back(arr[j]);
        j++;
    }
    for (int idx = l1; idx <= r2; idx++)
        arr[idx] = ans[idx - l1];
}

void divide(vector<int> &arr, int l, int r, ll &comparisons)
{
    if (l >= r)
        return;
    int m = (l + r) / 2;
    divide(arr, l, m, comparisons);
    divide(arr, m + 1, r, comparisons);
    mergeSortedArrs(arr, l, m, m + 1, r, comparisons);
}

void mergeSort(vector<int> &arr, int l, int r, ll &comparisons)
{
    if (!arr.empty())
        divide(arr, l, r, comparisons);
}

int main()
{
    vector<int> sample = {3, 6, 1, 7, 9, 8, 0, 2};
    ll comparisons;

    mergeSort(sample, 0, sample.size() - 1, comparisons);

    for (int num : sample)
        cout << num << " ";
    cout << endl
         << comparisons;

    return 0;
}