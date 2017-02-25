//@author: Maxwell Heeschen
//@AuburnUserID: mch0048
//@filename: hw4.cpp
//To compile:
//      g++ -o hw4 hw4.cpp
//
//resources:
//      I used Zhitao Gong's announcement on Canvas about reading from files in "a more C++-style way"
//      I used the assigned textbook to help with arrays and file IO

#include<iostream>
#include<fstream>
#include<cassert>
#include<string>
#include<cstdlib>
using namespace std;

int readFile(int inputArray[], ifstream& instream);
    //Input:
    //      inputArray[] is the array to get the size of
    //      instream is the stream to use with numbers in it
    //Return:
    //      the size of inputArray[]

int sort(int inputArray1[], int inputArray1_size, int inputArray2[], int inputArray2_size, int outputArray[]);
    //Input:
    //      inputArray1[] is one of the arrays to be sorted
    //      inputArray1_size is the size of the first array
    //      inputArray2[] is second array to be sorted with the first
    //      inputArray2_size is the size of the second array
    //Return:
    //      the size of the sorted array
    //      change a premade array to be sorted

void writeFile(int sorted[], int sorted_size, ofstream& output);
    //Input:
    //      sorted[] is the sorted array of the two files
    //      sorted_size is the size of sorted[]
    //Return:
    //      makes a file with the sorted numbers in it
    //

void getch(void);
    //Waits for user to press a key

void printArray(int print[], int size);
    //Prints out an array;

const int MAX_ARRAY_SIZE = 1000;

int main() {
    ifstream file1;
    ifstream file2;
    ofstream outFile;
    string fileToOpen1;
    string fileToOpen2;
    string fileOutput;
    int outputArray[MAX_ARRAY_SIZE];
    int Array1[MAX_ARRAY_SIZE];
    int Array2[MAX_ARRAY_SIZE];
    int Array1_size;
    int Array2_size;
    int outputArray_size;

    //==========
    //Test Cases
    //==========

        cout << "*** Unit Test Cases ***\n";

        //------
        //Case 1
        //------

            cout << "Unit Test Case 1: Function Name - readFile()\n";
            cout << "\tCase 1.1: Reading default input1.txt, expecting 5\n";
            file1.open("input1.txt");
            assert(6 == readFile(Array1, file1));
            file1.close();

            cout << "\tCase 1.2: Reading default input2.txt, expecting 4\n";
            file1.open("input2.txt");
            assert(5 == readFile(Array1, file1));
            file1.close();

            cout << "\tCase 1.3: Reading a large dataset from large.txt, expecting 1000\n";
            file1.open("large.txt");
            assert(1000 == readFile(Array1, file1));
            file1.close();

            cout << "\tCase 1.4: Reading a small dataset from smol1.txt, expecting 1\n";
            file1.open("smol1.txt");
            assert(1 == readFile(Array1, file1));
            file1.close();

            cout << "\tCase 1.5: Reading an empty file from empty.txt, expecting 0\n";
            file1.open("empty.txt");
            assert(0 == readFile(Array1, file1));
            file1.close();

        getch();

        //------
        //Case 2
        //------

            cout << "Unit Test Case 2: Function Name - sort()\n";
            cout << "\tCase 2.1: Sorting the default files input1.txt and input2.txt, expecting 11\n";
            file1.open("input1.txt");
            Array1_size = readFile(Array1, file1);
            file1.close();
            file2.open("input2.txt");
            Array2_size = readFile(Array2, file2);
            file2.close();
            file1.open("input1.txt");
            file2.open("input2.txt");
            assert(11 == sort(Array1, Array1_size, Array2, Array2_size, outputArray));
            file1.close();
            file2.close();

            cout << "\tCase 2.2: Sorting large file each with 500 numbers, expecting 1000\n";
            file1.open("large1.txt");
            Array1_size = readFile(Array1, file1);
            file1.close();
            file2.open("large2.txt");
            Array2_size = readFile(Array2, file2);
            file2.close();
            file1.open("large1.txt");
            file2.open("large2.txt");
            assert(1000 == sort(Array1, Array1_size, Array2, Array2_size, outputArray));
            file1.close();
            file2.close();

            cout << "\tCase 2.3: Sorting small files each with 1 number, expecting 2\n";
            file1.open("smol1.txt");
            Array1_size = readFile(Array1, file1);
            file1.close();
            file2.open("smol2.txt");
            Array2_size = readFile(Array2, file2);
            file2.close();
            file1.open("smol1.txt");
            file2.open("smol2.txt");
            assert(2 == sort(Array1, Array1_size, Array2, Array2_size, outputArray));
            file1.close();
            file2.close();

    getch();
    //Start

        cout << "*** Welcome to Maxwell's sorting program ***\n";
        cout << "Enter the first input file name: ";
        cin >> fileToOpen1;
        cout << "The list of numbers in file " << fileToOpen1 << " is:\n";
        
        file1.open((char*)fileToOpen1.c_str());

        if(file1.fail()) {
            cout << "Could not open file\n";
            exit(1);
        }

        Array1_size = readFile(Array1, file1);

        cout << "Enter the second input file name: ";
        cin >> fileToOpen2;
        cout << "The list of numbers in file " << fileToOpen2 << " is:\n";

        file2.open((char*)fileToOpen2.c_str());

        if(file2.fail()) {
            cout << "Could not open file\n";
            exit(1);
        }

        Array2_size = readFile(Array2, file2);

        outputArray_size = sort(Array1, Array1_size, Array2, Array2_size, outputArray);
        cout << "The sorted list of " << outputArray_size << " is: ";
        printArray(outputArray, outputArray_size);
        cout << "outputArray_size = " << outputArray_size << endl;
        cout << "Enter the output of the file name: ";
        cin >> fileOutput;
        outFile.open((char*)fileOutput.c_str());

        if(outFile.fail()) {
            cout << "Could not open file\n";
            exit(1);
        }
        writeFile(outputArray, outputArray_size, outFile);
        outFile.close();
        cout << "*** Please check the new file - " << fileOutput << endl;
        cout << "*** Goodbye ***\n";

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

int sort(int inputArray1[], int inputArray1_size, int inputArray2[], int inputArray2_size, int outputArray[]) {
    int j = 0;
    int i = 0;
    int index = 0;

    //Checks whether Array1 or Array2 is bigger and then implements a sorting method based on that
    if(inputArray1_size > inputArray2_size) {
        while(i < inputArray1_size) {
            if(j < inputArray2_size && inputArray1[i] <= inputArray2[j]) {
                outputArray[index] = inputArray1[i];
                index++;
                i++;
            } else if(j >= inputArray2_size) {
                for(; i < inputArray1_size; i++) {
                    outputArray[index] = inputArray1[i];
                    index++;
                }
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
        while(i < inputArray2_size) {
            if(j < inputArray1_size && inputArray2[i] <= inputArray1[j]) {
                outputArray[index] = inputArray2[i];
                index++;
                i++;
            } else if(j >= inputArray1_size) {
                for(; i < inputArray2_size; i++) {
                    outputArray[index] = inputArray2[i];
                    index++;
                }
            } else {
                for(; j < inputArray1_size; j++) {
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

void writeFile(int sorted[], int sorted_size, ofstream& output) {
    int i = 0;
    while(i < sorted_size) {
        output << sorted[i] << endl;
        i++;
    }
}

void getch(void) {
    cout << "Press any key to continue...\n";
    cin.ignore().get();
}

void printArray(int print[], int size) {
    for(int i = 0; i < size; i++) {
        cout << print[i] << "  ";
    }
    cout << "\n";
}
