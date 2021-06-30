#include <iostream>
#include <cstring>


bool is_subordinate_recursive(const char* employee, const char* manager, const char* leaders[][2], size_t current, size_t n, size_t depth) {
    if(current >= n || depth > 2) {
        return false;
    }

    if(strcmp(leaders[current][0], employee) == 0 && strcmp(leaders[current][1], manager) == 0) {
        return true;
    }
    else if(strcmp(leaders[current][0], employee) != 0 && strcmp(leaders[current][1], manager) == 0) {
        return is_subordinate_recursive(employee, leaders[current][0], leaders, 0, n, depth + 1);
    }
    else {
        return is_subordinate_recursive(employee, manager, leaders, current + 1, n, depth);
    }   
}
bool is_subordinate(const char* employee, const char* manager, const char* leaders[][2], size_t n) {
    return is_subordinate_recursive(employee, manager, leaders, 0, n, 1);
}


bool is_person_the_big_boss(const char* person, const char* leaders[][2], size_t n) {
    for(int i = 0; i < n; i++) {
        if(strcmp(person, leaders[i][0]) == 0) {
            return false;
        }
    }
    return true;
}
const char* the_big_boss(const char* leaders[][2], size_t n) {
    for(int i = 0; i < n; i++) {
        if(is_person_the_big_boss(leaders[i][1], leaders, n)) {
            return leaders[i][1];
        }
    }
    return "Invalid relation";
}
int main() {
    const char* leaders[3][2] = {
        {"A", "B"},
        {"B", "C"},
        {"C", "D"}
    };

    std::cout << is_subordinate("A", "C", leaders, 3) << std::endl;
    std::cout << the_big_boss(leaders, 3) << std::endl;
    return 0;
}