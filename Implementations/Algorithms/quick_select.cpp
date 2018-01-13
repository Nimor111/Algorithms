#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string>

class Person {
public:
    Person(float income, std::string name)
        : name(name)
        , income(income)
    {
    }

    bool operator<=(const Person& p)
    {
        return this->income <= p.income;
    }

    friend std::ostream& operator<<(std::ostream& os, const Person& p)
    {
        os << p.name << " " << p.income << "\n";
        return os;
    }

private:
    std::string name;
    float income;
};

template <typename T>
void swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
int partition(T* arr[], int low, int high, int pivot)
{
    Person p = *arr[pivot];
    int i = low - 1, j;

    for (j = low; j < high; ++j) {
        if (*arr[j] <= p) {
            swap(arr[j], arr[++i]);
        }
    }
    swap(arr[i + 1], arr[high]);

    return i + 1;
}

template <typename T>
T quick_select(T* arr[], int idx, int low, int high)
{
    if (low == high) {
        return *arr[low];
    }

    int pivot_index = high;

    int p = partition(arr, low, high, pivot_index);
    if (p == idx) {
        return *arr[p];
    } else if (p < idx) {
        return quick_select(arr, idx, p + 1, high);
    } else {
        return quick_select(arr, idx, low, p - 1);
    }
}

int main(int argc, char* argv[])
{
    Person p1(5, "Ivan");
    Person p2(10, "George");
    Person p3(15, "Peter");

    Person* p[] = { &p1, &p2, &p3 };
    for (int i = 0; i < 3; i++) {
        std::cout << *p[i];
    }

    Person res = quick_select<Person>(p, 0, 0, 2);
    std::cout << res;

    return 0;
}
