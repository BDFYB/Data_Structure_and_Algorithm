#include <iostream>
#include <vector>

using std::vector;
void bubble_sort(vector<int> &inputs) {
    int size = inputs.size();
    for (int outer_count = 0; outer_count < size; outer_count++) {
        for (int inner_count = 1; inner_count < size - outer_count; inner_count++) {
            if (inputs[inner_count] < inputs[inner_count - 1]) {
                int tmp = inputs[inner_count - 1];
                inputs[inner_count - 1] = inputs[inner_count];
                inputs[inner_count] = tmp;
            }
        }
    }
    std::cout << "bubble sort finished!" << std::endl;
};

void print_arry(vector<int> &data) {
    for (int count = 0; count < data.size(); count ++) {
        std::cout << data[count] << ' ';
    }
    std::cout << std::endl;
};

int main(int argv, char* argc[]) {
    int number[] = {95, 45, 15, 78, 84, 51, 24, 12};
    vector<int> data(number, number + sizeof(number)/sizeof(number[0]));
    print_arry(data);
    bubble_sort(data);
    print_arry(data);
}
