#ifndef ptice_h
#define price_h

struct Money {
    int grn;
    short int kop;
};

void add(Money& initial, const Money& amount);
void multi(Money& initial, const Money& amount, int quintaty);
void round(Money& amount);
void printAmount(const Money& result);

#endif 
