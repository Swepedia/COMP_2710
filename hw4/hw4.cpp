//@author: Maxwell Heeschen
//@AuburnUserID: mch0048
//@filename: hw4.cpp
//To compile:
//      g++ -o hw4 hw4.cpp
//
//resources:

#include<iostream>
#include<fstream>
#include<cassert>
#include<string>
using namespace std;

int readFile(int inputArray[], ifstream& instream);
//Input:
//      inputArray[] is the array to get the size of
//      instream is the stream to use with numbers in it
//Return:
//      the size of inputArray[]

int sort(int inputArray1[], int inputArray1_size, int inputArray2[], int inputArray2_size, int sorted[]);
//Input:
//      inputArray1[] is one of the arrays to be sorted
//      inputArray1_size is the size of the first array
//      inputArray2[] is second array to be sorted with the first
//      inputArray2_size is the size of the second array
//      sorted[] is the sorted array of both inputArray1[] and inputArray2[]
//Return:
//      the size of the sorted[] array
//      change a premade array to be sorted

void writeFile(int sorted[], int sorted_size);
//Input:
//      sorted[] is the sorted array of the two files
//      sorted_size is the size of sorted[]
//Return:
//      makes a file with the sorted numbers in it


const int MAX_ARRAY_SIZE = 1000;

int main() {
    ifstream file1;
    ifstream file2;
    ofstream outFile;
    int file1Next;
    int file2Next;

    return 0;
}

int readFile(int inputArray[], ifstream instream) {
    return -99999;
}

int sort(int inputArray1[], int inputArray1_size, int inputArray2[], int inputArray2_size, int sorted[]) {
    return -99999;
}

void writeFile(int sorted[], int sorted_size) {
}
