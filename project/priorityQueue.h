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

        void buildHeap();
        bool hasAChild(unsigned currIdx);
        /*
         * Compare the first distance to the second distance
         * break tie by returning true
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