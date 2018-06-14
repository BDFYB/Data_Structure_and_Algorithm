#include <iostream>
#include <vector>

using std::vector;

void swap_int(int& a, int& b) {
    int tmp = b;
    b = a;
    a = tmp;
};

void bubble_sort(vector<int>& inputs) {
    int last_change_pos = inputs.size();
    for (int i = 0; i < inputs.size(); i++) {
        int tmp_flag = last_change_pos;
        for (int j = 1; j < tmp_flag; j ++) {
            if (inputs[j - 1] > inputs[j]) {
                swap_int(inputs[j], inputs[j - 1]);
                last_change_pos = j;
            }
        }
    }
};


void print_vector(vector<int>& data) {
    for (int i = 0; i< data.size(); i++) {
        std::cout << data[i] << ' ';
    }
    std::cout << std::endl;
};

int main(int argv, char* argc[]) {
    int data[] = {23, 85, 49, 98, 97, 76, 34};
    vector<int> inputs(data, data+sizeof(data)/sizeof(data[0]));
    print_vector(inputs);
    bubble_sort(inputs);
    print_vector(inputs);
}
