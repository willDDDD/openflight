#include "priorityQueue.h"

priorityQueue::priorityQueue(const vector<Vertex> & vec, const map<int, int> & dist_map) {
    // id_to_dist_.resize(VECTOR_MAX_SIZE);
    vec_for_heap_.push_back(pair<int, int>(-100, -100));
    for (unsigned i = 0; i < vec.size(); i++) {
        vec_for_heap_.push_back(pair<int, int>(vec[i].id, dist_map.at(vec[i].id)));
        // id_to_dist_[vec[i].id] = dist_map.at(vec[i].id);
    }
    // arr_for_heap_ = new int[HEAP_MAX_SIZE];
    // arr_for_heap_[0] = -100;
    // afhSize = 0;
    buildHeap();
}

// void priorityQueue::resizeArray() {
//     unsigned newAfhSize = afhSize * 2;
//     int * newArr = new int[newAfhSize];
//     for (unsigned i = 0; i <= afhSize; i++) {
//         newArr[i] = arr_for_heap_[i];
//     }
//     delete [] arr_for_heap_;
//     arr_for_heap_ = newArr;
//     afhSize = newAfhSize;
// }

void priorityQueue::buildHeap() {
    // for (unsigned i = 0; i < vec.size(); i++) {
    //     arr_for_heap_[i + 1] = vec[i].id;
    // }
    // currentHeapSize = vec.size();
    for (unsigned i = findParent(vec_for_heap_.size() - 1); i >= 1; i--) {
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
    pair<int, int> temp = vec_for_heap_[first];
    vec_for_heap_[first] = vec_for_heap_[sec];
    vec_for_heap_[sec] = temp;
}

bool priorityQueue::hasAChild(unsigned currIdx) {
    return (vec_for_heap_.size() > currIdx * 2);
}

unsigned priorityQueue::highestPriorityChild(unsigned currIdx) {
    if (hasAChild(currIdx)) {
        unsigned leftChildIdx = findLeftChild(currIdx);
        unsigned rightChildIdx = findRightChild(currIdx);
        if (rightChildIdx >= vec_for_heap_.size()) {
            return leftChildIdx;
        } else {
            return firstShorterThanSec(leftChildIdx, rightChildIdx) ? leftChildIdx : rightChildIdx;
        }
    }
    return 0;
}

bool priorityQueue::firstShorterThanSec(int firstIdx, int secondIdx) {
    return fSTHelper(vec_for_heap_[firstIdx].second, vec_for_heap_[secondIdx].second);
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
    return (currIdx / 2); // notice that this is unsigned not size_t
}

unsigned priorityQueue::findLeftChild(unsigned currIdx) {
    return currIdx * 2;
}

unsigned priorityQueue::findRightChild(unsigned currIdx) {
    return (currIdx * 2) + 1;
}

void priorityQueue::updateDistance(const map<int, int> & dist_map, int id, int newDis) {
    int originalDist = dist_map.at(id);
    // id_to_dist_[id] = newDis;
    if (fSTHelper(newDis, originalDist)) {
        unsigned updatedAPid = findIndex(id);
        vec_for_heap_[updatedAPid].second = newDis;
        heapifyUp(updatedAPid);
    }
}

int priorityQueue::removeMin() {
    int toRet = vec_for_heap_[1].first;
    vec_for_heap_[1] = vec_for_heap_[vec_for_heap_.size() - 1];
    vec_for_heap_.pop_back();
    heapifyDown(1);
    return toRet;
}

int priorityQueue::peek() const {
    return vec_for_heap_[1].first;
}

bool priorityQueue::empty() const {
    return (vec_for_heap_.size() == 1);
}

unsigned priorityQueue::findIndex(int id) {
    unsigned i;
    for (i = 0; i < vec_for_heap_.size(); i++) {
        if (vec_for_heap_[i].first == id) {
            break;
        }
    }
    return i;
}

void priorityQueue::printElements() {
    for (unsigned i = 0; i < vec_for_heap_.size(); i++) {
        std::cout << "Element " << i << " id and distance: " << vec_for_heap_[i].first << "  "<< vec_for_heap_[i].second << std::endl;
    }
}