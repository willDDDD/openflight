#pragma once
#include <map>
#include "vertex.h"
#include <vector>
#include <iostream>
#define VECTOR_MAX_SIZE 14111
#define HEAP_MAX_SIZE 16385

using std::pair;

/*
 * Reference: xinlong3 lab_heap
 * The priority queue data structure implemented by heap
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
         * the first int is the airport id
         * the second int is the distance of that airport to the current center airport
         */
        vector<pair<int, int>> vec_for_heap_;
        /*
         * builds the heap using heapifyDown
         */
        void buildHeap();
        /*
         * Tells if an element has a child
         * @param currIdx the index of the element
         * @return true if the element has a child, false otherwise
         */
        bool hasAChild(unsigned currIdx);
        /*
         * Compare the first distance of an airport to the second distance of another
         * break tie by returning true
         * @param the id of the first airport
         * @param the id of the second airport
         * @return true if the first distance is shorter than the second one by our definition
         */
        bool firstShorterThanSec(int firstId, int secondId);
        /*
         * Find the left child of an element
         * @param currIdx the index of the element
         * @return the index of its left child
         */
        unsigned findLeftChild(unsigned currIdx);
        /*
         * Find the right child of an element
         * @param currIdx the index of the element
         * @return the index of its right child
         */
        unsigned findRightChild(unsigned currIdx);
        /*
         * Find the parent of an element in the heap
         * @param currIdx the index of the element
         * @return the index of its parent
         */
        unsigned findParent(unsigned currIdx);
        /*
         * the standard heapify-up operation on an element in a heap
         * @param currIdx the index of the element
         */
        void heapifyUp(unsigned currIdx);
        /*
         * the standard heapify-down operation on an element in a heap
         * @param currIdx the index of the element
         */
        void heapifyDown(unsigned currIdx);
        /*
         * swap two elements in vec_for_heap_
         * @param first the index of the first element to be swapped
         * @param sec the index of the second element to be swapped
         */
        void swap(unsigned first, unsigned sec);
        /*
         * Tells if the heap is now empty
         * @return true if the heap is empty
         */
        bool empty() const;
        /*
         * Returns the index of child of the highest priority.
         */
        unsigned highestPriorityChild(unsigned currIdx);
        /*
         * The helper function for firstShorterThanSec()
         * break tie by returning true
         */
        bool fSTHelper(int dist1, int dist2);
        /*
         * find the index of the airport id in the heap
         */
        unsigned findIndex(int id);
    public:
        /*
         * The constructor of the priority Queue class
         */
        priorityQueue(const vector<Vertex> & vec, const map<int, int> & dist_map);
        /*
         * Update the distance of a element in the heap and adjust its position
         * in the heap accordingly
         * @param dist_map the map that map a airport id to its distance to the
         *        current source airport
         * @param id the id of the airport whose distance needs to be updated
         * @param newDis the updated distance
         */
        void updateDistance(const map<int, int> & dist_map, int id, int newDis);
        /*
         * Standard removeMin() method for a priority queue to pop out the
         * id of the airport that is currently the closest to the source airport
         * @return the id of the currently closest airport
         */
        int removeMin();
        /*
         * For debugging purpose, prints out all the elements in the heap by their
         * order in vec_for_heap_
         */
        void printElements();
        /*
         * See what is now at the top of the heap but does not pop out the
         * smallest element
         * @return the current smallest element
         */
        int peek() const;
};