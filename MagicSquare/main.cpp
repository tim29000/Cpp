#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void arrayFiller(int arr[3][3]);
bool isMagicSquare(int arr[3][3], int magicNum);
void printArray(int arr[3][3]);
int summator(int arr[3][3]);

int main()
{
    int stime;
    long itime;
    itime = time(0);
    stime = (int) itime/2;
    srand(stime);
    int arr[3][3];
    int sum = 0, counter = 0;
    int magicNum;
    int k;
    for(k = 0; k < 10000000; k++)                 //  10000 is too little, but if we do 10000000 can be seen result
    {
        arrayFiller(arr);
        sum = summator(arr);
        magicNum = sum/3;
        if(isMagicSquare(arr, magicNum))
        {
            printArray(arr);
            cout << endl;
            counter++;
        }
    }
    cout << endl << "Totally Magic Squares found : " << counter;
    return 0;
}


void arrayFiller(int arr[3][3])
{
    int i, j;
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            arr[i][j] = rand() % 9 + 1;
        }
    }
}


bool isMagicSquare(int arr[3][3], int magicNum)
{
    int sumRow_1 = arr[0][0] + arr[0][1] + arr[0][2];
    int sumRow_2 = arr[1][0] + arr[1][1] + arr[1][2];
    int sumRow_3 = arr[2][0] + arr[2][1] + arr[2][2];
    int sumColumn_1 = arr[0][0] + arr[1][0] + arr[2][0];
    int sumColumn_2 = arr[0][1] + arr[1][1] + arr[2][1];
    int sumColumn_3 = arr[0][2] + arr[1][2] + arr[2][2];
    int sumDiagonal_1 = arr[0][0] + arr[1][1] + arr[2][2];
    int sumDiagonal_2 = arr[0][2] + arr[1][1] + arr[2][0];
    if(sumRow_1 == sumRow_2 && sumRow_1 == sumRow_3 &&
        sumRow_1 == sumColumn_1 && sumRow_1 == sumColumn_2 &&
         sumRow_1 == sumColumn_3 && sumRow_1 == sumDiagonal_1 &&
          sumRow_1 == sumDiagonal_2)
        return true;
    else
        return false;
}

void printArray(int arr[3][3])
{
    int i, j;
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            cout << " " << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int summator(int arr[3][3])
{
    int sum, i, j;
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            sum += arr[i][j];
        }
    }
    return sum;
}
