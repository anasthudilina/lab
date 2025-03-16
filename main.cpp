#include <iostream>
#include <fstream>
#include <string>
#include "price.cpp"  
using namespace ::std;

int main() {
    setlocale(LC_ALL, "en_US.utf8");
    std::ifstream inputFile("C:\\fistlaboop\\price.txt"); 
if (!inputFile) {
    std::cerr << "trouble" << std::endl;
    return 1;
}

    int grn;
    short int kop;
    int quantity;
    struct Money initial = { 0,0 };  

    
    while (inputFile >> grn >> kop >> quantity) {
      Money before = { grn, kop };  
      Money result = {0, 0};  
      multi(result, before, quantity); 
      add(initial, result);  
  }
  

    inputFile.close();

    printAmount(initial);  

    return 0;
}
