#include <iostream>


const char* find_first_break_symbol(const char* begin, const char* end) {
    if (end < begin) {
        return begin;
    }

    if(*end <= 32) {
        return end;
    }
    else {
        return find_first_break_symbol(begin, end-1);
    }
}

void print_forwards(const char* begin, const char* end) {
    if(begin > end) {
        std::cout << " ";
        return ;
    }

    if(*begin > 32) {
        std::cout << *begin;
    }

    print_forwards(begin + 1, end);
}
void print_backwards(const char* begin, const char* end) {
    if (end < begin) {
        return ;
    }

    const char* i = find_first_break_symbol(begin, end - 1);
    print_forwards(i, end); 

    print_backwards(begin, i - 1);
}

void print_backwards(const char* string) {
    const char* end = string;
    while (*end != '\0') {
        end++;
    }
    print_backwards(string, end - 1);
}
int main() {
    print_backwards("I\tneed a break!");
    return 0;
}