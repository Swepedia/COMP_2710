//This generates some files for hw4
//large1, large2


#include<fstream>
#include<cstdlib>
using namespace std;

int main() {
    ofstream large1;
    ofstream large2;
    ofstream large;

    large1.open("large1.txt");
    large2.open("large2.txt");
    large.open("large.txt");

    for(int i = 0; i < 1000; i += 2) {
        large1 << i << endl;
    }
    large1.close();

    for(int i = 1; i < 1001; i += 2) {
        large2 << i << endl;
    }
    large2.close();

    for(int i = 0; i < 1000; i++) {
        large << i << endl;
    }
    large.close();
}
