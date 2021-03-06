#include <vector>
#include <iostream>
#include <time.h>

using std::vector;

void print_arry(vector<int> &data) {
    for (int count = 0; count < data.size(); count ++) {
        std::cout << data[count] << ' ';
    }
    std::cout << std::endl;
};

void shell_sort(vector<int> &inputs) {
    for (int gap = inputs.size()/2; gap > 0; gap /= 2) {
        for (int i = gap; i < inputs.size(); i++) {
            int current = inputs[i];
            int j = i - gap;
            for (; j >= 0; j -= gap) {
                if (inputs[j] > current) {
                    inputs[j + gap] = inputs[j];
                } else {
                    break;
                }
            }
            inputs[j + gap] = current;
        }
    }
};


int main(int argv, char* argc[]) {
    clock_t start = clock();
    //int number[] = {95, 45, 15, 78, 84, 51, 24, 12};
    int number[1000]={
1,3,20,43,2,7,4,87,34,65,12,77,11,34,6,7,8,53,2,23,199,55,43,4,34,76,433,6,4,3,2,55,6,3,66,32,5,67,32,2,6,66,7,8,7,9,0,8,7,62,3,4,5,6,7,9,3,4,5,6,2,45,6,7,98,5,34,2,4,6,78,9,67,59,64,22,4,5,60,70,89,61,4,322,23,226,744,8,6,65,533,422,344,264,233,367,434,444,55,534
,1,3,20,43,2,7,4,87,34,65,12,77,11,34,6,7,8,53,2,23,199,55,43,4,34,76,433,6,4,3,2,55,6,3,66,32,5,67,32,2,6,66,7,8,7,9,0,8,7,62,3,4,5,6,7,9,3,4,5,6,2,45,6,7,98,5,34,2,4,6,78,9,67,59,64,22,4,5,60,70,89,61,4,322,23,226,744,8,6,65,533,422,344,264,233,367,434,444,55,534
,1,3,20,43,2,7,4,87,34,65,12,77,11,34,6,7,8,53,2,23,199,55,43,4,34,76,433,6,4,3,2,55,6,3,66,32,5,67,32,2,6,66,7,8,7,9,0,8,7,62,3,4,5,6,7,9,3,4,5,6,2,45,6,7,98,5,34,2,4,6,78,9,67,59,64,22,4,5,60,70,89,61,4,322,23,226,744,8,6,65,533,422,344,264,233,367,434,444,55,534
,1,3,20,43,2,7,4,87,34,65,12,77,11,34,6,7,8,53,2,23,199,55,43,4,34,76,433,6,4,3,2,55,6,3,66,32,5,67,32,2,6,66,7,8,7,9,0,8,7,62,3,4,5,6,7,9,3,4,5,6,2,45,6,7,98,5,34,2,4,6,78,9,67,59,64,22,4,5,60,70,89,61,4,322,23,226,744,8,6,65,533,422,344,264,233,367,434,444,55,534
,1,3,20,43,2,7,4,87,34,65,12,77,11,34,6,7,8,53,2,23,199,55,43,4,34,76,433,6,4,3,2,55,6,3,66,32,5,67,32,2,6,66,7,8,7,9,0,8,7,62,3,4,5,6,7,9,3,4,5,6,2,45,6,7,98,5,34,2,4,6,78,9,67,59,64,22,4,5,60,70,89,61,4,322,23,226,744,8,6,65,533,422,344,264,233,367,434,444,55,534
,1,3,20,43,2,7,4,87,34,65,12,77,11,34,6,7,8,53,2,23,199,55,43,4,34,76,433,6,4,3,2,55,6,3,66,32,5,67,32,2,6,66,7,8,7,9,0,8,7,62,3,4,5,6,7,9,3,4,5,6,2,45,6,7,98,5,34,2,4,6,78,9,67,59,64,22,4,5,60,70,89,61,4,322,23,226,744,8,6,65,533,422,344,264,233,367,434,444,55,534
,1,3,20,43,2,7,4,87,34,65,12,77,11,34,6,7,8,53,2,23,199,55,43,4,34,76,433,6,4,3,2,55,6,3,66,32,5,67,32,2,6,66,7,8,7,9,0,8,7,62,3,4,5,6,7,9,3,4,5,6,2,45,6,7,98,5,34,2,4,6,78,9,67,59,64,22,4,5,60,70,89,61,4,322,23,226,744,8,6,65,533,422,344,264,233,367,434,444,55,534
,1,3,20,43,2,7,4,87,34,65,12,77,11,34,6,7,8,53,2,23,199,55,43,4,34,76,433,6,4,3,2,55,6,3,66,32,5,67,32,2,6,66,7,8,7,9,0,8,7,62,3,4,5,6,7,9,3,4,5,6,2,45,6,7,98,5,34,2,4,6,78,9,67,59,64,22,4,5,60,70,89,61,4,322,23,226,744,8,6,65,533,422,344,264,233,367,434,444,55,534
,1,3,20,43,2,7,4,87,34,65,12,77,11,34,6,7,8,53,2,23,199,55,43,4,34,76,433,6,4,3,2,55,6,3,66,32,5,67,32,2,6,66,7,8,7,9,0,8,7,62,3,4,5,6,7,9,3,4,5,6,2,45,6,7,98,5,34,2,4,6,78,9,67,59,64,22,4,5,60,70,89,61,4,322,23,226,744,8,6,65,533,422,344,264,233,367,434,444,55,534
,1,3,20,43,2,7,4,87,34,65,12,77,11,34,6,7,8,53,2,23,199,55,43,4,34,76,433,6,4,3,2,55,6,3,66,32,5,67,32,2,6,66,7,8,7,9,0,8,7,62,3,4,5,6,7,9,3,4,5,6,2,45,6,7,98,5,34,2,4,6,78,9,67,59,64,22,4,5,60,70,89,61,4,322,23,226,744,8,6,65,533,422,344,264,233,367,434,444,55,20
};
    vector<int> data(number, number + sizeof(number)/sizeof(number[0]));
    print_arry(data);
    shell_sort(data);
    print_arry(data);
    clock_t end = clock();
    std::cout<<(float)(end-start)/CLOCKS_PER_SEC<<"s"<<std::endl;
}
