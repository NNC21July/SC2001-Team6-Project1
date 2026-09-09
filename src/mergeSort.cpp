#include <vector>
#include <algorithm>
using ll = long long;

void mergeSortedArrs(std::vector<int> &arr, int l1, int r1, int l2, int r2, ll &comparisons)
{
    std::vector<int> ans;
    ans.reserve(r2 - l1 + 1);

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

void mergeSort(std::vector<int> &arr, int l, int r, ll &comparisons)
{
    if (l >= r)
        return;
    int m = (l + r) / 2;
    mergeSort(arr, l, m, comparisons);
    mergeSort(arr, m + 1, r, comparisons);
    mergeSortedArrs(arr, l, m, m + 1, r, comparisons);
}
