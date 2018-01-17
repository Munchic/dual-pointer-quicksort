//
//  main.cpp
//  F5
//
//  Created by Munchic Fam on 2/12/17.
//  Copyright © 2017 Munchic. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

template <typename It>
It my_partition(It begin, It end, int pred) {
    auto mid = begin;

    {
        if (*begin < pred)
            std::swap(*begin, *mid++);
    } while (begin++ != end);

    return mid;
}

template <typename It>
void my_quicksort(It begin, It end) {
    int size = end - begin;
    if (size <= 1)
        return;

    auto mid = my_partition(begin, end, 1);

    if (begin == mid || mid == end)
        return;

    my_quicksort(begin, mid);
    my_quicksort(mid, end);
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i)
        std::cin >> nums[i];

    my_quicksort(nums.begin(), nums.end());

    for (auto elem : nums)
        std::cout << elem << " ";
}
