//
//  main.c
//  Classwork5
//
//  Created by Kate Polyakova on 11/9/14.
//  Copyright (c) 2014 Kate Polyakova. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printArray (const int len, int array[]);
int* reverseArray (const int len, int array[]);
int* absArrayElements (const int len, int array[]);
int searchIndexNum (const int len, int array[], int result[], int target);
int searchUniqueElements (const int len, int array[], int result[]);

int main()
{
    const int len=10;
    int array[len]={0, 4, 1, 5, -3, -5, 5, -7, 5, -2};
    printArray (len, array);
    
    int* result = reverseArray (len, array);
    printArray (len, result);
    
    result = absArrayElements (len, array);
    printArray (len, result);
    
    int target = 5;
    int newArray[len] = {};
    int newLen = searchIndexNum (len, array, newArray, target);
    printArray (newLen, newArray);
    
    int uniqueElements[len]= {0};
    int orderedArray[len]= {0, 1, 1, 2, 3, 4, 4, 5, 5, 19};
    int countOfUniqueElements = searchUniqueElements (len, orderedArray, uniqueElements);
    printArray (countOfUniqueElements, uniqueElements);
    
    
    return 0;
}

int* reverseArray (const int len, int array[])
{
    for (int i=0; i<len/2; i++)
    {
        int reverseIndex=len-1-i;
        int tmp = array[reverseIndex];
        
        array [reverseIndex] = array [i];
        
        array [i] = tmp;
    }
    return array;
}

int* absArrayElements (const int len, int array[])
{
    for (int i=0; i<len; i++)
    {
        if (array[i]<0)
        {
            array[i]=abs(array[i]);
        }
        
    }
    
    return array;
}
int searchIndexNum (const int len, int array[], int result[], int target)
{
    int resultIndex = 0;
    for (int i=0; i<len; i++)
    {
        if (array[i] == target)
        {
            result[resultIndex] = i;
            resultIndex++;
        }
    }
    return resultIndex;
}

int searchUniqueElements (const int len, int array[], int result[])
{
    int resultIndex = 0;
    for (int i=0; i<len; i++)
    {
        int a = (i==0 && array[i]<array[i+1]); // first element
        int b = (i==len-1 && array[i-1]<array[i]); // last element
        int c = (array[i-1]<array[i] && array[i]<array[i+1]); // the rest of elements
        
        if (a || b || c)
        {
            result[resultIndex]=array[i];
            resultIndex++;
        }
        
     }
        
    return resultIndex;
}

//utility
void printArray (const int len, int array[])
{
    for (int i=0; i<len; i++)
    {
        printf("%d\t", array[i]);
        
    }
    printf (" \n");
}

