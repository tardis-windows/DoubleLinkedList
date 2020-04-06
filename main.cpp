// TESTER PROGRAM


#include <iostream>
#include <cstdlib>
#include <string>
#include <cassert>
#include <ctime>
#include "Node.h"
#include "SortedBag.h"
#include "Student.h"

using namespace std;

int main()
{
    srand(time(NULL));
    cout << "TESTER PROGRAM" << endl;


    SortedBag<Student> L1, L2;

    for(int i = 0; i<1; i++){

            Student s;
            L1.insert(s);
    }


// test iterator to print the item in the bag

    cout << "--------------PRINTING BAG L1: \n\n"<<endl;

    int list_itemsL1 = 1;
    for(L1.begin(true);!L1.end();++L1){

        cout << list_itemsL1 << ". ";
        cout << L1.get()<< endl;

        list_itemsL1++;
}

cout<<"Number of Items in L1: " << L1.size()<< endl;




//inserting copy

int items_inserted = 0;
for(L1.begin();!L1.end();++L1){
    L2.insert(L1.get());
    items_inserted++;
}


cout <<"\n\n-----------------PRINTING BAG L2 (copy bag)" <<endl;
int items_L2 =1;
for(L2.begin();!L2.end();++L2){
cout << items_L2 <<". ";
    cout << L2.get()<< endl;
    items_L2++;

}
cout << "\n\nItems copied and inserted in L2: "<<items_inserted<< endl;

cout<<"\n\nNumber of Items in L2: " << L2.size()<< endl;

L2.~SortedBag();
L1.~SortedBag();

cout << "Empty bag: "<< L1.size()<<endl;

    return 0;
}
