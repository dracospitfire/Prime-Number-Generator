/*
  main.cpp
  Prime-Number-Generator

  Created by Austin Cooper on 3/19/14.
  Copyright (c) 2014 Austin Cooper. All rights reserved.
*/

#include <iostream>        //required for display output
#include <string>          //required for string class
#include <cmath>           //required for pow and sqrt
#include <fstream>         //required to open files for reading, writing, or both
#include <iomanip>         //required for setw or setprecision

using namespace std;       //requred to access entities with namespace std

struct number
{
    long double *factor;           //dynamically allocated array
};

int main()
{
    
    long int MAX = 42;
    long int count;
    long double primeNumber;
    long int value;
    long int coefficients;
    
    //dynamically allocate structure large enough to hold all numbers
    number *testvalue = new number[MAX];
        
    //dynamically allocate array large enough to hold the number of test scores
    for(count = 3; count < MAX ; count++)
    {
        coefficients = (count - 1);
        testvalue[count].factor = new long double[coefficients];
        
        value = 0;
        do
        {
            if (value == 0 || value == (coefficients - 1))
                testvalue[count].factor[value]= count;
            else
                testvalue[count].factor[value] = testvalue[(count - 1)].factor[(value - 1)] + testvalue[(count - 1)].factor[(value)];
            value++;
        } while (value < coefficients);
    }
    
    for(count = 3; count < MAX ; count++)
    {
        bool isInt;
        int NO = 0;
        for( value = 0; value < (count - 1) ; value++)
        {
            primeNumber = testvalue[count].factor[value]/count;
            isInt = primeNumber ==(int)primeNumber;
            if (!isInt)
            {
                NO = 1;
            }
        }
        if (!NO)
        {
            cout << testvalue[count].factor[0];
            cout << " ";
        }
    }
    cout << "\n\n\t";
    return 0;
}
