#include "priorityQueue.h"

priorityQueue::priorityQueue(const vector<Vertex> & vec, const map<int, int> & dist_map) {
    id_to_dist_.resize(VECTOR_MAX_SIZE);
    for (auto v : vec) {
        id_to_dist_[v.id] = dist_map.at(v.id);
    }
    arr_for_heap_ = new int[HEAP_MAX_SIZE];
    arr_for_heap_[0] = -100;
    afhSize = 0;
    buildHeap(vec);
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
    for (unsigned i = findParent(currentHeapSize); i >= 1; i--) {
        heapifyDown(i);
    }
}

void priorityQueue::heapifyUp(unsigned currIdx) {
    if (currIdx > 1) {
        unsigned parentIdx = findParent(currIdx);
        if (firstShorterThanSec(currIdx, parentIdx)) {
            swap(currIdx, parentIdx);
            heapifyUp(parentIdx);
        }
    }
}


void priorityQueue::heapifyDown(unsigned currIdx) {
    if (hasAChild(currIdx)) {
        unsigned hpChildIdx = highestPriorityChild(currIdx);
        if (firstShorterThanSec(hpChildIdx, currIdx)) {
            swap(hpChildIdx, currIdx);
            heapifyDown(hpChildIdx);
        }
    }
}

void priorityQueue::swap(unsigned first, unsigned sec) {
    int temp = arr_for_heap_[first];
    arr_for_heap_[first] = arr_for_heap_[sec];
    arr_for_heap_[sec] = temp;
}

bool priorityQueue::hasAChild(unsigned currIdx) {
    return ((currentHeapSize + 1) > currIdx * 2);
}

unsigned priorityQueue::highestPriorityChild(unsigned currIdx) {
    if (hasAChild(currIdx)) {
        unsigned leftChildIdx = findLeftChild(currIdx);
        unsigned rightChildIdx = findRightChild(currIdx);
        if (rightChildIdx >= (currentHeapSize + 1)) {
            return leftChildIdx;
        } else {
            return firstShorterThanSec(leftChildIdx, rightChildIdx) ? leftChildIdx : rightChildIdx;
        }
    }
    return 0;
}

bool priorityQueue::firstShorterThanSec(int firstIdx, int secondIdx) {
    return fSTHelper(id_to_dist_[arr_for_heap_[firstIdx]], id_to_dist_[arr_for_heap_[secondIdx]]);
}

bool priorityQueue::fSTHelper(int dist1, int dist2) {
    if (dist1 < 0 && dist2 < 0) {
        return true;
    }
    if (dist1 < 0) {
        return false;
    }
    if (dist2 < 0) {
        return true;
    }
    return dist1 < dist2;
}

unsigned priorityQueue::findParent(unsigned currIdx) {
    return (currIdx / 2);
}

unsigned priorityQueue::findLeftChild(unsigned currIdx) {
    return currIdx * 2;
}

unsigned priorityQueue::findRightChild(unsigned currIdx) {
    return (currIdx * 2) + 1;
}

void priorityQueue::updateDistance(int id, int newDis) {
    int originalDist = id_to_dist_[id];
    id_to_dist_[id] = newDis;
    if (fSTHelper(newDis, originalDist)) {
        heapifyUp(findIndex(id));
    } else {
        heapifyDown(findIndex(id));
    }
}

int priorityQueue::removeMin() {
    int toRet = arr_for_heap_[1];
    swap(1, currentHeapSize);
    arr_for_heap_[currentHeapSize] = -1;
    currentHeapSize--;
    heapifyDown(1);
    return toRet;
}

int priorityQueue::peek() const {
    return arr_for_heap_[1];
}

bool priorityQueue::empty() const {
    return (currentHeapSize == 0);
}

unsigned priorityQueue::findIndex(int id) {
    unsigned i;
    for (i = 0; i <= currentHeapSize; i++) {
        if (arr_for_heap_[i] == id) {
            break;
        }
    }
    return i;
}