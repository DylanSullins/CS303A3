#include <iostream>
#include "Queue.h"
#include "Search.h"
#include "Sort.h"

template <typename T>
void display(Queue<T>& q)
{
    for (int i = 0; i < q.getSize(); ++i)
    {
        T data = q.front();
        std::cout << "\t\t--" << data << std::endl;
        q.pop();
        q.push(data);
    }
}

int main()
{
    // Question One
    std::cout << "Question 1. Queue Implementation" << std::endl;
    std::cout << "\tInitializing Empty Queue" << std::endl;
    Queue<int> q;
    std::cout << "\tAdding 0-9 in order" << std::endl;
    q.push(0);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    q.push(9);
    std::cout << "\tDisplaying Queue" << std::endl;
    display(q);
    std::cout << "\tMoving front to rear:" << std::endl;
    q.move_to_rear();
    std::cout << "\t\tNew front: " << q.front() << std::endl;
    std::cout << std::endl;

    // Question Two
    std::cout << "Question 2. Reverse Linear Search" << std::endl;
    std::cout << "\tInitializing vector 0-9" << std::endl;
    std::vector<int> items = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << "\tDisplaying vector: " << std::endl;
    for (int i = 0; i < items.size(); ++i)
    {
        std::cout << "\t\t--" << items.at(i) << std::endl;
    }
    std::cout << "\tSearching vector for last occurrence of 2: " << std::endl;
    int pos = last_occurrence_linear_search(items, 2, items.size());
    std::cout << "\t\t2 found at index " << pos << std::endl;

    std::cout << "\tInitializing vector 0-9" << std::endl;
    std::vector<int> itemsRepeats = {0, 0, 1, 1, 2, 2, 3, 3, 3, 4, 5, 5, 6};
    std::cout << "\tDisplaying vector: " << std::endl;
    for (int i = 0; i < itemsRepeats.size(); ++i)
    {
        std::cout << "\t\t--" << itemsRepeats.at(i) << std::endl;
    }
    std::cout << "\tSearching vector for last occurrence of 3: " << std::endl;
    pos = last_occurrence_linear_search(itemsRepeats, 3, items.size());
    std::cout << "\t\t3 found at index " << pos << std::endl;
    std::cout << std::endl;
    
    // Question 3
    std::cout << "Question 3. Sorting a Queue" << std::endl;
    std::cout << "\tInitializing random queue" << std::endl;
    Queue<int> sortingQ;
    for (int i = 0; i < 10; i++)
    {
        sortingQ.push(rand() % 10);
    }

    std::cout << "\tDisplaying Queue" << std::endl;
    display(sortingQ);
    std::cout << "\tSorting Queue:" << std::endl;
    insertion_sort<int>(sortingQ);
    display(sortingQ);
}