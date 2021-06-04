//
//

#ifndef TASK3_CODE_SEARCH_H
#define TASK3_CODE_SEARCH_H
#include <algorithm>
#include <vector>
#include <fstream>
#include <chrono>
#include <list>


using namespace std;
using namespace std::chrono;

template<class T>
class Search {
private:
    vector<T> data ;
    list<T> list_data;


public:
    Search()= default;
    bool loadData(ifstream &file);
    void sortData(ifstream &file);
    vector<T> getData();

    int binarySearch(T key);
    int binarySearchNumberOfComp(T key, int elementNum);

    int linearSearch(T key);
   int linearSearchNumberOfComp(T key, int elementNum);
    vector<int> generateRandInRange(int min,int max, int size=10);

    pair<float , float> testPerformance( const int &wordsNumber,const string &algo,const string &performance,int X=0, int Y=10 );












};



#endif //TASK3_CODE_SEARCH_H
