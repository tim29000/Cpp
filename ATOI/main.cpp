#include <iostream>
#include <string>

using namespace std;

int myAtoi(string str);


int main()
{
    string str = "-99999999999";

    int a = myAtoi(str);

    cout << a << endl;

    return 0;
}

int myAtoi(string str)
    {
        long long result = 0;
        int sign = 1;
        int i = str.find_first_not_of(' ');


            if(str[i] == '-' || str[i] == '+')
            {
                sign = (str[i] == '-')? -1 : 1;
                i++;
            }

            while(str[i] >= '0' && str[i] <= '9')
            {
                result = result * 10 + (str[i] - '0');
                if(result * sign <= INT_MIN)
                return INT_MIN;

                else if(result * sign >= INT_MAX)
                return INT_MAX;
                i++;
            }

     return  result * sign;

    }
