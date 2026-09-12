#include "hybridSort.hpp"
#include <iostream>
#include <vector>
#include <fstream>   
#include <string>    
#include <chrono>    

using ll = long long;
using namespace std;

int main(int argc, char* argv[]) {
    // This program expects 3 arguments:
    // 1. The program name (e.g., my_sorter.exe)
    // 2. The input file name (e.g., dataset_10000.txt)
    // 3. The threshold value 'S' (e.g., 32)

    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <input_filename> <S_value>" << endl;
        return 1; //Exit with an error
    }

    string filename = argv[1];
    int s = stoi(argv[2]); //Convert the S value argument from string to int

    //Read integers from the file into a vector
    vector<int> data;
    ifstream inputFile(filename);
    if (!inputFile) {
        cerr << "Error: Could not open file " << filename << endl;
        return 1;
    }
    int number;
    while (inputFile >> number) {
        data.push_back(number);
    }
    inputFile.close();

    //Prepare for sorting
    ll comparisons = 0;

    //Measure the time
    auto start = chrono::high_resolution_clock::now();

    //Run the hybrid sort algorithm
    hybridSort(data, 0, data.size() - 1, comparisons, s);

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start; //Duration in milliseconds

    //Print the results
    //Format: "S,n,comparisons,time_ms"
    cout << s << "," << data.size() << "," << comparisons << "," << duration.count() << endl;

    return 0;
}
