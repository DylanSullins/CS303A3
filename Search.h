#pragma once
#include <vector>

template <typename T>
int last_occurrence_linear_search(std::vector<T>& items, T target, int pos)
/*
    Searches descending from pos for target in items
    Parameters:
        vector<T>& items: Vector to search
        T& target: Search key
        int pos: Current position
    
    Returns:
        int pos or -1 if not found
*/
{
    if (pos < 0) return -1;
    if (items[pos] == target) return pos;
    else return last_occurrence_linear_search(items, target, pos - 1);
}