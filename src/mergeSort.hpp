#ifndef MERGE_SORT_HPP
#define MERGE_SORT_HPP

#include <vector>
using ll = long long;

void mergeSortedArrs(std::vector<int> &arr, int l1, int r1, int l2, int r2, ll &comparisons);

void mergeSort(std::vector<int> &arr, int l, int r, ll &comparisons);
#endif