#include "priorityQueue.h"

priorityQueue::priorityQueue(const vector<Vertex> & vec, const map<int, int> & dist_map) {
    id_to_dist_.resize(VECTOR_MAX_SIZE);
    for (auto v : vec) {
        id_to_dist_[v.id] = dist_map[v.id];
    }
    arr_for_heap_ = new int[HEAP_MAX_SIZE];
    arr_for_heap_[0] = (int) (vec.size());
    afhSize = 0;
}

void priorityQueue::resizeArray() {
    unsigned newAfhSize = afhSize * 2;
    int * newArr = new int[newAfhSize];
    for (unsigned i = 0; i <= afhSize; i++) {
        newArr[i] = arr_for_heap_[i];
    }
    delete [] arr_for_heap_;
    arr_for_heap_ = newArr;
    afhSize = newAfhSize;
}

void priorityQueue::buildHeap(const vector<Vertex> & vec) {
    for (unsigned i = 0; i < vec.size(); i++) {
        arr_for_heap_[i + 1] = vec[i];
    }
    
}