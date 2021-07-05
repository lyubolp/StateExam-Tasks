#include <iostream>
#include <cstring>

bool find(int value, int* arr, size_t size) {
    if (size == 0) {
        return false;
    } 
    size_t mid = size / 2;
    if (value == arr[mid]) {
        return true;
    }

    if (value < arr[mid]) {
        return find(value, arr, mid);
    }
    else {
        return find(value, arr + mid + 1, mid);
    }
}


template <typename ReturnType, typename InputType, typename OpType>
ReturnType fold_left(InputType* arr, size_t size, OpType op, ReturnType nil) {
    ReturnType result = nil;
    for (size_t i = 0; i < size; ++i) {
        result = op(arr[i], result);
    }
    return result;
}

int op(char Digit, int Result) { 
    return (Result * 10) + (Digit - '0');
}

// Преобразува символен низ от десетични цифри до величина от тип int
int str_to_int(const char * str) {
    return (str == nullptr) ? 0 : fold_left(str, strlen(str), op, 0);
}


int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << find(6, arr, 9) << std::endl;


    std::cout << str_to_int("12345") << std::endl;

    return 0;
}