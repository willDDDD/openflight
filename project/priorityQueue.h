#pragma once
#include <map>
#include "vertex.h"
#include <vector>
#define VECTOR_MAX_SIZE 14111
#define HEAP_MAX_SIZE 16385

using std::pair;

/*
 * Reference: xinlong3 lab_heap
 */
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
        // int* arr_for_heap_;
        /*
         * The array that represents the heap
         * the first int is the airport id
         * the second int is the distance of that airport to the current center airport
         */
        vector<pair<int, int>> vec_for_heap_;
        /*
         * the current size of arr_for_heap_
         */
        unsigned afhSize;
        /*
         * the current number of elements in the heap
         * excluding the thing on the 0th index
         */
        unsigned currentHeapSize;

        /*
         * resize arr_for_heap_
         */
        // void resizeArray(); // I realized that we do not actually need this
        void buildHeap();
        bool hasAChild(unsigned currIdx);
        /*
         * Compare the first distance to the second distance
         * break tie by returning false
         */
        bool firstShorterThanSec(int firstId, int secondId);
        unsigned findLeftChild(unsigned currIdx);
        unsigned findRightChild(unsigned currIdx);
        unsigned findParent(unsigned currIdx);
        void heapifyUp(unsigned currIdx);
        void heapifyDown(unsigned currIdx);
        void swap(unsigned first, unsigned sec);
        bool empty() const;
        /*
         * Returns the index of child of the highest priority.
         */
        unsigned highestPriorityChild(unsigned currIdx);
        /*
         * The helper function for firstShorterThanSec()
         * break tie by returning false
         */
        bool fSTHelper(int dist1, int dist2);
        /*
         * find the index of the airport id in the heap
         */
        unsigned findIndex(int id);
    public:
        /*
         * This function is supposed to be called only once per instance
         */
        priorityQueue(const vector<Vertex> & vec, const map<int, int> & dist_map);
        void updateDistance(int id, int newDis);
        int removeMin();
        /*
         * See what is now at the top of the heap
         */
        int peek() const;
};