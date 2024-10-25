#pragma once
#include <list>
#include "Queue.h"

template <typename T>
T peek_and_pop(Queue<T>& q)
/*
    Function to peek at front and pop
    Parameters:
        Queue<type T>& q: queue to peek/pop
    
    Returns:
        type T data
*/
{
    if (q.empty()) throw std::runtime_error("Queue is empty");
    T value = q.front();
    q.pop();
    return value;
}

template <typename T>
void insert_in_queue_sorted(Queue<T>& sorted_q, T data)
/*
    Inserts data into queue in sorted order
    Parameters:
        Queue<type T>& sorted_q: Sorted queue
        T data: type T data to insert
    
    Returns:
        None
*/
{
    Queue<T> temp_q;

    // Peek and pop until either sorted_q is empty or next value is 
    while (!sorted_q.empty() && sorted_q.front() <= data)
    {
        temp_q.push(peek_and_pop(sorted_q));
    }

    temp_q.push(data);
    while (!sorted_q.empty())
    {
        temp_q.push(peek_and_pop(sorted_q));
    }

    while (!temp_q.empty())
    {
        sorted_q.push(peek_and_pop(temp_q));
    }
}

template <typename T>
void insertion_sort(Queue<T>& q)
/*
    Insertion Sort Implementation for User Defined Queue
    Pops one by one from queue and inserts into temp queue
    in order. After, repopulate queue with temp queue values;
    Parameters:
        Queue<T> q: Queue to sort
    
    Returns:
        None
*/
{
    Queue<T> sorted_q;

    while (!q.empty())
    {
        T data = peek_and_pop(q);
        insert_in_queue_sorted(sorted_q, data);
    }
    while (!sorted_q.empty())
    {
        q.push(peek_and_pop(sorted_q));
    }
}


template <typename T>
void insertion_sort(std::vector<T> &num)
{
    int i, j, key;
    bool insertionNeeded = false;
    for (j = 1; j < num.size(); j++)
    {
        key = num[j];
        insertionNeeded = false;
        for (i = j -1; i >= 0; i--)
        {
            if (key < num[i]) 
            {
                num[i + 1] = num[i];
                insertionNeeded = true;
            }
            else break;
        }
        if (insertionNeeded) num[i + 1] = key;
    }
}


template <typename T>
void insertion_sort_the_easy_way(Queue<T>& q)
{
    std::vector<T> vec;
    while (!q.empty())
    {
        vec.push_back(peek_and_pop(q));
    }
    insertion_sort(vec);
    for (auto i = vec.begin(); i != vec.end(); ++i)
    {
        q.push(*i);
    }
}