// this file is for you for testing purposes, it won't be included in evaluation.

#include <iostream>
#include <random>
#include <ctime>
#include <utility>      // for pair
#include "the6.h"


using namespace std;


// comment below line to stop DEBUG
#define DEBUG
#define DEBUG_STDERR(x) do { std::cerr << (x) << endl; } while(0)
#define DEBUG_ARRAY(a, n) do { for (int i = 0; i < n; i++) std::cerr << a[i] << " ";  std::cerr << endl; } while(0)


void randomArray(int*& array, int size, int min, int interval)
{

  for (int i = 0; i < size; i++)
  {
    array[i] = min + (random() % interval);
  }
}

void measureTime(){

  clock_t begin;
  clock_t end;
  double duration;

  // maybe data generation here

  if ((begin = clock ()) == -1)
    std::cerr << "clock err" << std::endl;

  // call your function here instead of the loop
  for (int i = 0; i < 1<<30; i++)
    ;
  //

  if ((end = clock ()) == -1)
    std::cerr << "clock err" << std::endl;
  duration = ((double)end-begin) / CLOCKS_PER_SEC * 1000000;

  std::cerr << "Times: " << begin <<" "<< end << " " << end-begin << " "<< duration <<" microsecs " << std::endl;
}



//void SCC_TopSort (int**& graph, int n, vector<vector<int>>& scc, vector<int>& topSort)



int main()
{
    srandom(time(0));

    int n;

    vector<vector<int>> scc;
    vector<int> topSort;

    int arr0[][7] = {{0, 1 ,0, 1, 0, 0, 0 }, { 0, 0, 1, 0, 0, 0, 0 }, { 1, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 1, 0, 0 }, { 0, 0, 0, 0, 0, 1, 0 }, { 0, 0, 0, 0, 0, 0, 1 }, { 0, 0, 0, 0, 1, 0, 0}};
    int arr1[][7] = {{0, 0 ,0, 0, 0, 0, 0 }, { 1, 0, 0, 0, 0, 0, 0 }, { 1, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0 }, { 0, 1, 0, 1, 0, 0, 0 }, { 0, 0, 1, 1, 0, 0, 0 }, { 0, 0, 0, 0, 1, 1, 0}};
    int arr2[][8] = {{0, 1, 0, 1, 1, 0, 0, 0}, { 0, 0, 1, 0, 1, 0, 0, 0}, { 1, 0, 0, 0, 0, 0, 0, 0}, { 0, 0, 0, 0, 1, 1, 0, 0}, { 0, 0, 1, 0, 0, 0, 0, 0}, { 0, 0, 0, 0, 1, 0, 0, 0}, { 0, 0, 0, 1, 0, 1, 0, 1}, { 0, 0, 0, 0, 1, 0, 0, 0}};
    int arr3[][10]= {{0, 1, 0, 0, 0, 1, 0, 0, 0, 0}, { 0, 0, 1, 0, 0, 0, 1, 0, 0, 0}, { 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}, { 0, 0, 0, 0, 1, 0, 0, 1, 1, 0}, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, { 0, 0, 0, 0, 0, 0, 1, 0, 0, 0}, { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0}, { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}};
    int arr4[][13]= {{0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    n=7;
    int** graph = new int*[n];
    for (int j=0 ; j<n ; j++){
        graph[j] = new int[n];
        graph[j] = arr0[j];
    }

    SCC_TopSort (graph, n, scc, topSort);

    for(unsigned i=0 ; i<scc.size() ; i++){
        std::cout << "{";
        for(unsigned j=0 ; j<scc[i].size() ; j++){
            std::cout << scc[i][j] << " ";
        }
        std::cout << "} ";
    }
    std::cout << std::endl;

    n=7;
    delete graph;
    scc.clear() ; topSort.clear();
    graph = new int*[n];
    for (int j=0 ; j<n ; j++){
        graph[j] = new int[n];
        graph[j] = arr1[j];
    }

    SCC_TopSort (graph, n, scc, topSort);

    std::cout << "{";
    for(unsigned i=0 ; i<topSort.size() ; i++){
        std::cout << topSort[i] << " ";
    }
    std::cout << "} ";
    std::cout << std::endl;

    n=8;
    delete graph;
    scc.clear() ; topSort.clear();
    graph = new int*[n];
    for (int j=0 ; j<n ; j++){
        graph[j] = new int[n];
        graph[j] = arr2[j];
    }

    SCC_TopSort (graph, n, scc, topSort);

    for(unsigned i=0 ; i<scc.size() ; i++){
        std::cout << "{";
        for(unsigned j=0 ; j<scc[i].size() ; j++){
            std::cout << scc[i][j] << " ";
        }
        std::cout << "} ";
    }
    std::cout << std::endl;

    n=10;
    delete graph;
    scc.clear() ; topSort.clear();
    graph = new int*[n];
    for (int j=0 ; j<n ; j++){
        graph[j] = new int[n];
        graph[j] = arr3[j];
    }

    SCC_TopSort (graph, n, scc, topSort);

    for(unsigned i=0 ; i<scc.size() ; i++){
        std::cout << "{";
        for(unsigned j=0 ; j<scc[i].size() ; j++){
            std::cout << scc[i][j] << " ";
        }
        std::cout << "} ";
    }
    std::cout << std::endl;

    n=13;
    delete graph;
    scc.clear() ; topSort.clear();
    graph = new int*[n];
    for (int j=0 ; j<n ; j++){
        graph[j] = new int[n];
        graph[j] = arr4[j];
    }

    SCC_TopSort (graph, n, scc, topSort);

    std::cout << "{";
    for(unsigned i=0 ; i<topSort.size() ; i++){
        std::cout << topSort[i] << " ";
    }
    std::cout << "} ";
    std::cout << std::endl;

    return 0;
}
