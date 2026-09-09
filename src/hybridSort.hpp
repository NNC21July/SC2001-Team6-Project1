#ifndef HYBRID_SORT_HPP
#define HYBRID_SORT_HPP

#include <vector>
#include "mergeSort.hpp"
#include "insertionSort.hpp"
using ll = long long;

void hybridSort(std::vector<int> &arr, int l, int r, ll &comparisons, int s);
#endif