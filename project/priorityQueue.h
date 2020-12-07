#pragma once
#include <map>
#define VECTOR_MAX_SIZE 14111

class priorityQueue {
    public:
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
    private:
        void init_id_to_dist();
        void resizeArray();
};