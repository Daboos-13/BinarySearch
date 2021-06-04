//
//
#include <random>
#include "Search.h"
#include <string>
#include <ctime>
#include <ratio>
#include <iostream>
#include <chrono>
#include <time.h>
using namespace std::chrono;
using namespace std;
template<class T>
bool Search<T>::loadData(ifstream &file) {
    string line;
    while (getline(file,line)){
        data.push_back(line);
    }
    data.shrink_to_fit();
    return true;
}


template<class T>
vector<T> Search<T>::getData() {
    return data;
}

template<class T>
int Search<T>::binarySearch(T key) {
    int l=0;
    int r= data.size()-1;
    while (l<=r){
        int m = l +(r-l)/2;
        if (data.at(m)==key)
            return m;
        if (data.at(m)<key)
            l=m+1;
        else
            r=m-1;

    }
    return -1;


}


template<class T>
int Search<T>::linearSearch(T key) {

    if (data.empty())
        return -1;


    for (int i = 0; i <data.size() ; ++i) {
        if (key==data.at(i))
            return i;

    }
    return -1;



}

template<class T>
void Search<T>::sortData(ifstream &file) {
    string line;
    while (getline(file,line)){
        list_data.push_back(line);
    }
    list_data.sort();
    ofstream newFile("sortedWords.txt");
    for (const auto &i :list_data){
        newFile<<i<<endl;
    }

}

template<class T>
pair<float , float > Search<T>::testPerformance(const int &wordsNumber, const string &algo, const string& performance , int X,  int Y) {
//    pair<double,int>*pair = new std::pair<double,int>;
    vector<int> randomNums=generateRandInRange(X,Y,10);

    float avgCompNum{};
    float x;
    int n=10;
   float avgTime{};
    if (algo=="binary"){
        pair<float,float>P;

            for (int i = 0; i < n; i++) {

                auto startTime = high_resolution_clock::now();
                if (performance=="average") {
                    avgCompNum = binarySearchNumberOfComp(data.at(randomNums.at(i)), wordsNumber);
                }else {
                    avgCompNum = binarySearchNumberOfComp("data.at(randomNums.at(i))", wordsNumber);

                }
                auto endTime = high_resolution_clock::now();
//            duration<double, milli> elapsed = (endTime - startTime);
                auto elapsed = duration_cast<nanoseconds>(endTime - startTime);

                 avgTime += elapsed.count();
                avgCompNum += avgCompNum;
            }
            avgTime = avgTime /(float ) n;
            avgCompNum = avgCompNum / (float )n;
            P.first = avgTime;
            P.second = avgCompNum;
        return P;




    }else if(algo=="linear"){
        pair<float ,float> P;


            for (int i = 0; i < n; i++) {
//                vector<int> randomNums=generateRandInRange(X,Y,100);

                auto startTime = high_resolution_clock::now();
                if (performance=="average") {
                    avgCompNum = linearSearchNumberOfComp(data.at(randomNums.at(i)), wordsNumber);
                }else {
                    avgCompNum = linearSearchNumberOfComp("data.at(randomNums.at(i))", wordsNumber);

                }
                auto endTime = high_resolution_clock::now();
//            duration<double, milli> elapsed = (endTime - startTime);
                auto elapsed = duration_cast<microseconds>(endTime - startTime);


                avgTime += elapsed.count();
                avgCompNum += avgCompNum;
            }
            avgTime = avgTime / (float )n;
            avgCompNum = avgCompNum / (float )n;
            P.first = avgTime;
            P.second = avgCompNum;
        return P;

        }






    }






template<class T>
int  Search<T>::binarySearchNumberOfComp(T key,int elementsNum) {
    pair<int ,int >P;

    int l=0;
    int comparisonNum = 0;
    int r= elementsNum;
    while (l<=r){
        comparisonNum++;

        int m = l +(r-l)/2;
        if (data[m]==key) {


            return comparisonNum;
        }
        if (data.at(m)<key)
            l=m+1;
        else
            r=m-1;
    }

    return comparisonNum;

}

template<class T>
int Search<T>::linearSearchNumberOfComp(T key, int elementNum) {
    int comparisonNum{0};
    for (int i = 0; i <elementNum ; ++i) {
        comparisonNum++;
        if (key==data[i]) {

            return comparisonNum;
        }
    }

    return comparisonNum;
}

template<class T>
vector<int> Search<T>::generateRandInRange(int min, int max, int size) {
    vector<int> vec;
    unsigned seed  = std::chrono::steady_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    uniform_int_distribution<int> distribution(min,max);

    for (int i = 0; i < size; ++i) {

        int dice_roll = distribution(generator);

        vec.push_back(dice_roll);
//        cout<<vec.at(i)<<"  ";
    }
//    cout<<"\n ---------------------------------------------------------"<<endl;


    return vec;
}
