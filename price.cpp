#include <iostream>
#include "price.h"  
using namespace ::std;

//функція для додавання суми до загальної
void add(Money& initial, const Money& amount) {
    initial.grn += amount.grn;
    initial.kop += amount.kop;
    if (initial.kop >= 100) { //перевірка на копійки більше 100
        initial.grn += initial.kop / 100;
        initial.kop %= 100; //копійки що залиш після ділення
    }
}

//функція для множення суми на кількість
void multi(Money& result, const Money& amount, int quintaty) {
    int kops = (amount.grn * 100 + amount.kop) * quintaty; //перевід грн у коп і * на ксть
    result.grn = kops / 100;
    result.kop = kops % 100;
}

//функція для округлення до найближчих 10 копійок
void round(Money& amount) {
    if (amount.kop % 10 >= 5) { //перевірка чи >=5
        amount.kop = (amount.kop / 10 + 1) * 10; //до 10
        if (amount.kop == 100) { //перевірка на 100коп
            amount.grn++; //додаємо 1грн
            amount.kop = 0;
        }
    } else {
        amount.kop = (amount.kop / 10) * 10;
    }
}

//функція для виведення суми
void printAmount(Money& initial) {
    cout << "initial amount: " << initial.grn << " grn " << initial.kop << " kop" << endl;
    round(initial); 
    cout << "amount after rounding: " << initial.grn << " grn " << initial.kop << " kop" << endl;
}
