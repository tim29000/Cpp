#include <iostream>
#include <stdlib.h>
#include <vector>
#include <windows.h>

using namespace std;


//////////////////////////BUBBLE SORT FUNCTION///////////////////////////

template <typename T>

vector<T> BubbleSort(vector<T> vectorToSort)
{
    int i;
    int j;
    int n = vectorToSort.size();

    for(i = 0; i < n; ++i)
    {
        for(j = 0; j < n - 1; ++j)
        {
            if(vectorToSort[j] > vectorToSort[j+1])
                swap(vectorToSort[j], vectorToSort[j+1]);
        }
    }
    return vectorToSort;
}


/////////////////////////SELECT SORT FUNCTION///////////////////////////

template <typename T>

vector<T> SelectSort(vector<T> vectorToSort)
{
    int i;
    int j;
    int minimal;
    int n = vectorToSort.size();

    for(i = 0; i < n; ++i)
    {
        minimal = i;
        for(j = i+1; j < n ; ++j)
        {
            if(vectorToSort[j] < vectorToSort[minimal])
                minimal = j;
        }
        if(vectorToSort[minimal] < vectorToSort[i])
            swap(vectorToSort[minimal], vectorToSort[i]);
    }
    return vectorToSort;
}

///////////////////////LINEAR SEARCH FUNCTION//////////////////////////////

template <typename T>

int LinearSearch(vector<T> vectorToSearch, T valueToFind, int startPos)
{
    int i;
    int n = vectorToSearch.size();
    if(startPos == 0)
    {
        for(i = 0; i <= n; ++i)
        {
            if(vectorToSearch[i] == valueToFind)
                return i;
        }
    }
    else
        for(i = n - 1; i >= 0; --i)
        {
            if(vectorToSearch[i] == valueToFind)
                return i;
        }

    cout << "The stated value wasn't found!" << endl;
    return -1;
}

//////////////////////SUPPORTIVE FUNTION TO LINEAR SEARCH FUNCTION///////////////////////////

template <typename T>

void PrintLinearSearchResult(vector<T> tVector)
{
    system("cls");
    cout << "Enter, please, the value you want to find and the side(0 - head, 1 - tail) from where we will begin searching: ";
    T value;
    int side;
    cin >> value >> side;
    int position = LinearSearch(tVector, value, side);
    if(position != -1)
        cout << "The value we were searching was on the " << position << " position " ;
    Sleep(4000);
}



///////////////////////BINARY SEARCH FUNCTION////////////////////////////////////////////


template <typename T>

int BinarySearch(vector<T> vectorToSearch, T valueToFind)
{
    int n = vectorToSearch.size();
    int left = 0;
    int right = n - 1;
    int middle;
    while(left <= right)
    {
        middle = (right + left)/2;
        if(vectorToSearch[middle] == valueToFind)
            return middle;
        else if(vectorToSearch[middle] < valueToFind)
            left = middle + 1;
        else
            right = middle - 1;
    }
    cout << "The stated value wasn't found!" << endl;
    return -1;
}


template <typename T>

void PrintBinarySearchResult(vector<T> tVector)
{
    system("cls");
    cout << "Enter, please, the value you want to find: ";
    T value;
    cin >> value;
    int position = BinarySearch(tVector, value);
    if(position != -1)
        cout << "The value we were searching was on the " << position << " position " ;
    Sleep(3000);
}

//////////////////////FUNCTION THAT PRINTS VECTOR////////////////////////////////


template <typename T>

void PrintVector(vector<T> vectorToPrint)
{
    system("cls");
    int i = 0;
    int n = vectorToPrint.size();
    while(i < n)
    {
        cout << " " << vectorToPrint[i] << " ";
        ++i;
    }
    cout << endl;
    Sleep(3000);
}


//////////////////////////FUCTION THAT FILLS VECTOR WITH THE VALUES///////////////////////


template <typename T>

vector<T> FillVector(vector<T> vectorToFill)
{
    int i;
    int n;
    T value;
    system("cls");
    cout << "Please, enter the number of elements in vector you wish : ";
    cin >> n;
    for( i = 0; i < n; ++i)
    {
        system("cls");
        cout << "Enter the value " << i + 1 << ": ";
        cin >> value;
        vectorToFill.push_back(value);
    }
    return vectorToFill;
}



int main()
{
    cout << "Hello!  This is Sorting and searching project" << endl;
    Sleep(3000);
    while(true)
    {
        bool isSorted = false;
        system("cls");
        cout << "To choose the action you should write down the number and press Enter!" <<endl << endl;
        cout << "Choose the data type, please! Options: " << endl << endl;
        cout << "1 - int" << endl;
        cout << "2 - float" << endl;
        cout << "3 - string" << endl;
        cout << "0 - Quit" << endl;
        int dataChoice;
        cin >> dataChoice;
        switch(dataChoice)
        {
            case 1:
            {
                vector<int> intVector;
                intVector = FillVector(intVector);
                while(true)
                {
                    system("cls");
                    cout << "Choose the action, please! Options: " << endl << endl;
                    cout << "1 - Search with use of Linear Search algorithm" << endl;
                    cout << "2 - Sort with use of Bubble Sort algorithm" << endl;
                    cout << "3 - Sort with use of Select Sort algorithm" << endl;
                    cout << "4 - Search with use of Binary Search algorithm" << endl;
                    cout << "5 - Display data" << endl;
                    cout << "0 - Quit" << endl;
                    int actionChoice;
                    cin >> actionChoice;
                    switch(actionChoice)
                    {
                        case 1:

                            PrintLinearSearchResult(intVector);
                            break;

                        case 2:

                            intVector = BubbleSort(intVector);
                            system("cls");
                            cout << "Sorted Successfully!";
                            Sleep(3000);
                            isSorted = true;
                            break;

                        case 3:

                            intVector = BubbleSort(intVector);
                            system("cls");
                            cout << "Sorted Successfully!";
                            Sleep(3000);
                            isSorted = true;
                            break;

                        case 4:
                        {
                            if(isSorted)
                                PrintBinarySearchResult(intVector);
                            else
                            {
                                system("cls");
                                cout << "Sorry, you can't vector array wasn't sorted. Sort it firstly and try again! ";
                            }
                            break;
                        }

                        case 5:
                        {
                            PrintVector(intVector);
                            break;
                        }

                        default:
                            exit(0);
                    }
                }
            }

            case 2:
            {
                vector<float> floatVector;
                floatVector = FillVector(floatVector);
                while(true)
                {
                    system("cls");
                    cout << "Choose the action, please! Options: " << endl << endl;
                    cout << "1 - Search with use of Linear Search algorithm" << endl;
                    cout << "2 - Sort with use of Bubble Sort algorithm" << endl;
                    cout << "3 - Sort with use of Select Sort algorithm" << endl;
                    cout << "4 - Search with use of Binary Search algorithm" << endl;
                    cout << "5 - Display data" << endl;
                    cout << "0 - Quit" << endl;
                    int actionChoice;
                    cin >> actionChoice;
                    switch(actionChoice)
                    {
                        case 1:

                            PrintLinearSearchResult(floatVector);
                            break;

                        case 2:

                            floatVector = BubbleSort(floatVector);
                            system("cls");
                            cout << "Sorted Successfully!";
                            Sleep(3000);
                            isSorted = true;
                            break;


                        case 3:

                            floatVector = SelectSort(floatVector);
                            system("cls");
                            cout << "Sorted Successfully!";
                            Sleep(3000);
                            isSorted = true;
                            break;

                        case 4:
                        {
                            if(isSorted)
                                PrintBinarySearchResult(floatVector);
                            else
                            {
                                system("cls");
                                cout << "Sorry, you can't vector array wasn't sorted. Sort it firstly and try again! ";
                            }
                            break;
                        }

                        case 5:

                            PrintVector(floatVector);
                            break;

                        default:
                            exit(0);
                    }
                }
            }
            case 3:
            {
                vector<string> stringVector;
                stringVector = FillVector(stringVector);
                while(true)
                {
                    system("cls");
                    cout << "Choose the action, please! Options: " << endl << endl;
                    cout << "1 - Search with use of Linear Search algorithm" << endl;
                    cout << "2 - Sort with use of Bubble Sort algorithm" << endl;
                    cout << "3 - Sort with use of Select Sort algorithm" << endl;
                    cout << "4 - Search with use of Binary Search algorithm" << endl;
                    cout << "5 - Display data" << endl;
                    cout << "0 - Quit" << endl;
                    int actionChoice;
                    cin >> actionChoice;
                    switch(actionChoice)
                    {
                        case 1:
                        {
                            PrintLinearSearchResult(stringVector);
                            break;
                        }

                        case 2:
                        {
                            stringVector = BubbleSort(stringVector);
                            system("cls");
                            cout << "Sorted Successfully!";
                            Sleep(3000);
                            isSorted = true;
                            break;
                        }

                        case 3:
                        {
                            stringVector = SelectSort(stringVector);
                            system("cls");
                            cout << "Sorted Successfully!";
                            Sleep(3000);
                            isSorted = true;
                            break;
                        }

                        case 4:
                        {
                            if(isSorted)
                                PrintBinarySearchResult(stringVector);
                            else
                            {
                                system("cls");
                                cout << "Sorry, you can't vector array wasn't sorted. Sort it firstly and try again! ";
                            }
                            break;
                        }

                        case 5:
                        {
                            PrintVector(stringVector);
                            break;
                        }

                        default:
                            exit(0);
                    }
                }
            }
        default:
            exit(0);
        }
    }
    return 0;
}
