#include "priorityQueue.h"

priorityQueue::priorityQueue(const vector<Vertex> & vec, const map<int, int> & dist_map) {
    id_to_dist_.resize(VECTOR_MAX_SIZE);
    for (auto v : vec) {
        id_to_dist_[v.id] = dist_map.at(v.id);
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
        arr_for_heap_[i + 1] = vec[i].id;
    }
    currentHeapSize = vec.size();
    for (unsigned i = 2; i <= currentHeapSize; i++) {
        heapifyUp(i);
    }
}

void priorityQueue::heapifyUp(unsigned currIdx) {
    if (currIdx > 1) {
        unsigned parentIdx = findParent(currIdx);
        if (arr_for_heap_[currIdx] < arr_for_heap_[parentIdx]) {
            swap(currIdx, parentIdx);
            heapifyUp(parentIdx);
        }
    }
}

void priorityQueue::swap(unsigned first, unsigned sec) {
    int temp = arr_for_heap_[first];
    arr_for_heap_[first] = arr_for_heap_[sec];
    arr_for_heap_[sec] = temp;
}

bool priorityQueue::hasAChild(unsigned currIdx) {
    return (currentHeapSize > currIdx * 2);
}

int priorityQueue::highestPriorityChild(unsigned currIdx) {
    if (hasAChild(currIdx)) {
        unsigned leftChildIdx = findLeftChild(currIdx);
        unsigned rightChildIdx = findRightChild(currIdx);
        if (rightChildIdx >= currentHeapSize) {
            return leftChildIdx;
        } else {
            return arr_for_heap_[leftChildIdx] < arr_for_heap_[rightChildIdx] ? leftChildIdx : rightChildIdx;
        }
    }
    return 0;
}

unsigned priorityQueue::findLeftChild(unsigned currIdx) {
    return currIdx * 2;
}

unsigned priorityQueue::findRightChild(unsigned currIdx) {
    return (currIdx * 2) + 1;
}