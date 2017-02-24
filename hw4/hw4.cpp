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

int sort(int inputArray1[], int inputArray1_size, int inputArray2[], int inputArray2_size);
    //Input:
    //      inputArray1[] is one of the arrays to be sorted
    //      inputArray1_size is the size of the first array
    //      inputArray2[] is second array to be sorted with the first
    //      inputArray2_size is the size of the second array
    //Return:
    //      the size of the sorted array
    //      change a premade array to be sorted

void writeFile(int sorted[], int sorted_size);
    //Input:
    //      sorted[] is the sorted array of the two files
    //      sorted_size is the size of sorted[]
    //Return:
    //      makes a file with the sorted numbers in it


const int MAX_ARRAY_SIZE = 1000;
int outputArray[MAX_ARRAY_SIZE];
ofstream outFile;

int main() {
    ifstream file1;
    ifstream file2;
    string fileToOpen;
    
    cout << "*** Unit Test Cases ***\n";

    cout << "Unit Test Case 1: Function Name - readFile()\n";
    cout << "\tCase 1.1: Reading default input1.txt, expecting 5\n";
    file1.open("input1.txt");
    int array1[MAX_ARRAY_SIZE];
    assert(5 == readFile(array1, file1));
    file1.close();

    return 0;
}

int readFile(int inputArray[], ifstream& instream) {
    int index = 0;

    while(instream >> inputArray[index]) {
        cout << inputArray[index] << endl;
        index++;
    }
    return index;
}

int sort(int inputArray1[], int inputArray1_size, int inputArray2[], int inputArray2_size) {
    int total = inputArray1_size + inputArray2_size;
    int j = 0;
    int index = 0;

    //Checks whether Array1 or Array2 is bigger and then implements a sorting method based on that
    if(inputArray1_size > inputArray2_size) {
        for(int i = 0; i < inputArray1_size; i++) {
            if(inputArray1[i] <= inputArray2[j]) {
                outputArray[index] = inputArray1[i];
                index++;
            } else {
                for(; j < inputArray2_size; j++) {
                    if(inputArray2[j] <= inputArray1[i]) {
                        outputArray[index] = inputArray2[j];
                        index++;
                    } else {
                        break;
                    }
                }
            }
        }
    } else {
        for(int i = 0; i < inputArray2_size; i++) {
            if(inputArray1[i] <= inputArray2[j]) {
                outputArray[index] = inputArray2[i];
                index++;
            } else {
                for(; j < inputArray2_size; j++) {
                    if(inputArray1[j] <= inputArray2[i]) {
                        outputArray[index] = inputArray1[j];
                        index++;
                    } else {
                        break;
                    }
                }
            }
        }
    }
    return index;
}

void writeFile(int sorted[], int sorted_size) {
    while(sorted_size > 0) {
        outFile << sorted[sorted_size - 1];
        sorted_size--;
    }
}
