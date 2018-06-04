#include <iostream>
#include <vector>

using std::vector;

void print_arry(vector<int> &data) {
    for (int count = 0; count < data.size(); count ++) {
        std::cout << data[count] << ' ';
    }
    std::cout << std::endl;
};

void swap_int(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void bubble_sort(vector<int> &inputs) {
    int low_pos = 0;
    int high_pos = inputs.size() - 1;
    while (low_pos < high_pos) {
        //大的沉到底下
        for (int counts = low_pos; counts < high_pos; counts++) {
            if (inputs[counts] > inputs[counts + 1]) {
                swap_int(inputs[counts], inputs[counts + 1]);
            }
        }
        high_pos --;
        //小的浮到上面
        for (int counts = high_pos; counts > low_pos; counts--) {
            if (inputs[counts] < inputs[counts - 1]) {
                swap_int(inputs[counts], inputs[counts - 1]);
            }
        }
        low_pos ++;
    }
    std::cout << "bubble sort finished!" << std::endl;
};

int main(int argv, char* argc[]) {
    int number[] = {95, 45, 15, 78, 84, 51, 24, 12};
    vector<int> data(number, number + sizeof(number)/sizeof(number[0]));
    print_arry(data);
    bubble_sort(data);
    print_arry(data);
}
