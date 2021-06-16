#include <iostream>
#include <cmath>
#include <algorithm>

class Interval {
public:
    Interval(const int a = 0, const int k = 0): a(a), k(k), current(0) {}

    virtual int operator*() const {
        return a + current;
    }

    Interval& operator++() {
        this->current += 1;
        return *this;
    }

    Interval operator++(const int num) {
        this->current += num;
        return *this;
    }

    void reset() {
        this->current = 0;
    }

    bool last() {
        return current == k;
    }
protected:
    int a;
    int k;
    int current;
};


class SquaredInterval: public Interval {
public:
    SquaredInterval(const int a = 0, const int k = 0): Interval(a, k) {}
    int operator*() const override {
        return pow((double)Interval::operator*(), 2);
    }
};


int get_max_value(SquaredInterval& obj) {
    int max_val = 0;

    while(!obj.last()) {
        max_val = *obj;
        ++obj;
    }

    return max_val;
}

void sort_array(SquaredInterval arr[], int elems) {
    std::sort(arr, arr + elems, [](SquaredInterval first, SquaredInterval second) {return get_max_value(first) < get_max_value(second);});
}
int main() {
    SquaredInterval first(1, 10);
    SquaredInterval second(2, 20);
    SquaredInterval third(3, 15);
    SquaredInterval forth(4, 5);

    SquaredInterval arr[4] = {first, second, third, forth};

    for(int i = 0; i < 4; i++) {
        std::cout << *arr[i] << " ";
    }
    std::cout << std::endl;

    sort_array(arr, 4);

    for(int i = 0; i < 4; i++) {
        std::cout << *arr[i] << " ";
    }
}