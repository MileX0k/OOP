#include <stdio.h>
#include <stdlib.h>


//=================TASK 1====================================

#define T int
#define SIZE 100
#define true 1==1
#define false !true


typedef int boolean;
int cursor = -1;
T Stack[SIZE];

boolean push (T data)
{
    if (cursor < SIZE)
    {
        Stack[data] = 1;
        cursor++;
        return true;
    } else {
        printf("%s \n", "Stack overflow");
        return false;
    }
}

T pop() {
    if (cursor != -1) {
        return Stack[cursor--];
    } else {
    printf("%s \n", "Stack is empty");
    return -1;
    }
}

#define n 6
int matrix[n][n] = {
    {0, 1, 1, 0, 0, 1},
    {0, 0, 0, 1, 0, 0},
    {0, 1, 0, 0, 1, 1},
    {1, 0, 1, 0, 0, 0},
    {0, 0, 1, 0, 0, 1},
    {0, 1, 0, 0, 0, 0},
};

void depthTraves (int st)
{
    int r;
    printf ("%d ", st);
    push(st);

    for (r = 0; r < n; r++)
    {
        if (matrix[st][r] == 1 && !Stack[r])
        {
            depthTraves(r);
        }
    }
}

//===========================================================


//=================TASK 2====================================
#define k 5

int cycle[k][k] = {
    {0, 1, 0, 0, 1},
    {1, 0, 1, 1, 0},
    {0, 1, 0, 0, 1},
    {0, 1, 0, 0, 1},
    {1, 0, 1, 1, 0},
};

int visited[k] = {0};
int summ[k] = {0};

void calcCycle (int st)
{
    int r = 0;
    visited[st] = 1;
    for (r = 0; r < k; r++)
    {
        if (cycle[st][r] == 1)
            summ[r]++;
        if (cycle[st][r] == 1 && visited[r] != 1 )
            {
            calcCycle(r);
            }
    }
}

void resetArr()
{
    for (int i = 0; i < k; i++)
    {
        visited[i] = 0;
    }
}

    int m = 0;
    int arr[k] = {0};

void sortCalcMatrix (int *arr)
{
    for (int i = 0; i < k; i++)
    {
        for (int i = 1; i < k; i++)
        {
            if (arr[i-1] < arr[i])
            {
                int foo = arr[i-1];
                arr[i-1] = arr[i];
                arr[i] = foo;
            }
        }
    }
}

void calcMatrix()
{
    int link = 0;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if (cycle[j][i] == 1)
            link++;
        }
        arr[m] = link;
        m++;
        link = 0;
    }
    sortCalcMatrix(arr);
}

void printCalcMatrix (int *arr)
{
    for (int i = 0; i < k; i++)
    {
        printf ("%d ", arr[i]);
    }
  printf ("\n");
}



int main()
{
//=================TASK 1====================================

    printf ("Task 1 \n");
    depthTraves(1);
    printf ("\n");
    int count = cursor;
    for (int i = 0; i < count; i++)
    {
        pop();
    }
    printf ("\n");

//=================TASK 2====================================

    printf ("Task 2.1 \n");
    calcCycle(0);
    sortCalcMatrix(summ);
    printCalcMatrix(summ);
    resetArr();

    printf ("\n");

    printf ("Task 2.2 \n");
    calcMatrix();
    printCalcMatrix(arr);

    return 0;
}
