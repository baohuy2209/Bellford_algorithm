#include <iostream>
#include <vector>
#include <fstream>
#include "bellman.h"
#include "tsm.h"
#define INF 1000000
using namespace std;
int main(){
    int number_vertices = 6;
    int matrix[number_vertices][1000] = {
        {0, 10, 5, 18, 0, 0}, 
        {0, 0, 0, 12, 0, 0}, 
        {0, 0, 0, 5, 14, 5}, 
        {0, 0, 0, 0, 0, 8}, 
        {0, 0, 0, 0, 0, 7}, 
        {0, 0, 0, 0, 0, 0}, 
    }; 
    cout<<"================================================"<<endl; 
    cout<<"Exercise 1 : "<<endl; 
    int value[number_vertices] = {0, 10, 5, 18, INF, INF}; 
    int previous[number_vertices] = {-1, 0, 0, 0, -1, -1}; 
    BF(matrix, value, previous, number_vertices, 'A'); 
    cout<<"Value: "<<endl; 
    printarr(value, number_vertices); 
    cout<<"Previous: "<<endl; 
    printarr(previous, number_vertices); 
    cout<<"================================================"<<endl; 
    cout<<"================================================"<<endl; 
    cout<<"Exercise 2 : "<<endl; 
    string final = BF_path(matrix, number_vertices, 'A', 'F');
    cout<<final<<endl; 
    cout<<"================================================"<<endl; 
    cout<<"Exercise 3 : "<<endl; 
    int result = traveling(matrix, number_vertices, 'A'); 
    return 0;
}