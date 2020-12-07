#include "priorityQueue.h"

void init_id_to_dist() {
    id_to_dist.resize(VECTOR_MAX_SIZE);
}

void resizeArray() {
    unsigned newAfhSize = afhSize * 2;
    int * newArr = new int[newAfhSize];
    for (unsigned i = 0; i <= afhSize; i++) {
        newArr[i] = arr_for_heap_[i];
    }
    delete [] arr_for_heap_;
    arr_for_heap_ = newArr;
    afhSize = newAfhSize;
}