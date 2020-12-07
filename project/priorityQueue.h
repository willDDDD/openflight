#pragma once
#include <map>
#include "vertex.h"
#define VECTOR_MAX_SIZE 14111
#define HEAP_MAX_SIZE 16385

class priorityQueue {
    private:
        /*
         * id_to_dist_ map the airport id to the its distance to the source airport
         * distances recorded here are subject to change
         */
        vector<int> id_to_dist_;
        /*
         * The array that represents the heap
         */
        int* arr_for_heap_;
        /*
         * the current size of arr_for_heap_
         */
        unsigned afhSize;
        unsigned currentEnd;

        /*
         * resize arr_for_heap_
         */
        void resizeArray(); // I realized that we do not actually need this
        void buildHeap(const vector<Vertex> & vec);
        bool hasAChild(unsigned currIdx);
        /*
         * Compare the first distance to the second distance
         */
        bool firstShorterThanSec(int firstId, int secondId);
        unsigned findLeftChild(unsigned currIdx);
        unsigned findRightChild(unsigned currIdx);
        unsigned findParent(unsigned currIdx);
        void heapifyUp(unsigned currIdx);
        void heapifyDown(unsigned currIdx);
        /*
         * Returns the child's airport id of the highest priority.
         */
        int highestPriorityChild();
    public:
        /*
         * This function is supposed to be called only once per instance
         */
        priorityQueue(const vector<Vertex> & vec, const map<int, int> & dist_map);
};