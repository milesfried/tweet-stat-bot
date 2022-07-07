//
// Created by Miles Friedman on 6/10/21.
//

#ifndef PA01_SENTIMENT_DSVECTOR_H
#define PA01_SENTIMENT_DSVECTOR_H
#include <iostream>
using namespace std;
template<typename T>
class DSVector {
private:
    T* data;
    int length = 0; //# of used spaces
    int capacity = 10;//max # of spaces
 /**
  * doubles the current capacity of the vector
  */
    void increase_cap(){
            T* temp = new T[capacity*2];
            for (int i = 0; i < length; i++){
                temp[i] = data[i];
            }
            capacity *= 2;
            delete[] data;
            data = temp;
        }
public:
    /**
     * Empty Constructor for Object of type DSVector
     */
    DSVector(){
        data = new T[10];
    }
    /**
     * Copy Constructor
     * @param arg
     */
    DSVector(const DSVector& arg){
        length = arg.length;
        capacity = arg.capacity;
        data = new T[capacity];
        for (int i = 0; i < length; i++){
            data[i] = arg.data[i];
        }
    }
    /**
     * Destructor
     */
    ~DSVector(){
        clear();
    }
    /**
     * Copy Assignment Operator
     * @param arg
     * @return
     */
DSVector& operator=(const DSVector& arg){
        delete[] data;
        length = arg.length;
        capacity = arg.capacity;
        data = new T[capacity];
        for (int i = 0; i < length; i++){
            data[i] = arg.data[i];
        }
        return *this;
    }
    /**
     * @param in is added to the end of the data array
     */
    void push_back(const T& in){
        if(length == capacity){
            increase_cap();
        }
        data[length] = in;
        length++;
    }
    /**
     *
     * @param in is added to the front of the data array
     */
    void push_front(const T& in){
        if(length == capacity){
            increase_cap();
        }
        for(int i = length - 1; i >= 0; --i){
            data[i + 1] = data[i];
        }
        data[0] = in;
        length++;
    }
    /**
     *.
     * @param location the index to which the data should be inserted
     * @param item the data to be inserted
     */
    void insert(int location, const T& item){
        if (location > length - 1){
            cout << "Invalid Index" << endl;
        }
        if(length == capacity){
            increase_cap();
        }
        for(int i = length - 1; i >= location; --i){
            data[i + 1] = data[i];
        }
        data[location] = item;
        length++;
    }
    /**
     * clears all data from the vector/resets the length and capacity
     */
    void clear(){
        delete[] data;
        data = new T[10];
        length = 0;
        capacity = 10;
    }
    /**
     *
     * @return the size of the vector
     */
    int size(){
        return length;
    }
    void swap(T* a, T* b){
        T t = *a;
        *a = *b;
        *b = t;
    }
    int partition(T* list, int low, int high){
        T pivot = list[high];
        int i = (low - 1);
        for (int j = low; j <= high - 1; ++j){
            if (list[j] < pivot){
                ++i;
                swap(&list[i], &list[j]);
            }
        }
        swap(&list[i + 1], &list[high]);
        return (i + 1);
    }
    /**
     * sorts the vector according to the < operator
     */
    void sort(int low, int high) {
        if (low < high) {
            int par = partition(data, low, high);
            sort(low, par - 1);
            sort(par + 1, high);
        }
    }


    /**
     *
     * @param in the data to be searched for
     * @return the index of
     */
   T find(const T& in) {
        for (int i = 0; i < size(); ++i) {
            if (data[i] == in) {
                return data[i];
            }
        }
        cout << "No match found" << endl;
        return -9999;
    }
    /**
     * @param num is input as the index of the vector element desired
     * @return the value at index num
     */
    T& at(const int num){
        return data[num];
    }
    /**
     *
     * @param num is input as the index of the vector element desired
     * @return the value at index num
     */
    T& operator[](const int num){
        return data[num];
    }





};



#endif //PA01_SENTIMENT_DSVECTOR_H
