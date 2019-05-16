//Del'Juan Jackson
//Homework 6 -- Table of Numbers
//Intro to C++


#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

//Function Prototypes
double rootFunc(int sqrtArray);
double squarefunction(int sqrtArray);
double cubeFunc(int array);
double cubeRootFunc(int array);
bool evenOdd(int array);
bool isPrime(int array);






int main() {

//Array Declarations
    int testArray[25];
    int squared[25];
    double squareRootArray[25];
    int cubedArray[25];
    double cubedRootArray[25];
    string evenArray[25];
    string isPrimeArray[25];


//User Input Variables
    int rows;
    int num;
    int increment;


    //User Input
    cout << "Enter the amount of rows you would like to output." << endl;
    cin >> rows;
    while (rows < 1 || rows > 25) {
        cout << "Please try again.  Enter a number between 1 and 25." << endl;
        cin >> rows;
    }

    cout << "Enter the starting number." << endl;
    cin >> num;
    while (num < -1000 || num > 1000) {
        cout << "Please try again.  Enter a number between -1000 and 1000." << endl;
        cin >> num;
    }

    cout << "Enter the increment value." << endl;
    cin >> increment;
    while (increment < 1 || increment > 20) {
        cout << "Please try again.  Enter a number between 1 and 20." << endl;
        cin >> increment;
    }


    //Array Initialization
    testArray[0] = num;
    squared[0] = num;
    squareRootArray[0] = num;
    cubedArray[0] = num;
    cubedRootArray[0] = num;
    evenArray[0] = "True";
    isPrimeArray[0] = "True";




//Reading User Input Result into Test Array which is the "Base" of the table
    for (int counter = 1; counter < rows; counter++) {
        testArray[counter] = testArray[counter - 1] + increment;
    }


    //The calling of functions to population corresponding arrays
    for (int index = 0; index < rows; index++)
    {
        squared[index] = squarefunction(testArray[index]);
        squareRootArray[index] = rootFunc(testArray[index]);
        cubedArray[index] = cubeFunc(testArray[index]);
        cubedRootArray[index] = cubeRootFunc(testArray[index]);
        evenOdd(testArray[index]);
        if(evenOdd(testArray[index]) == true)
        {
            evenArray[index] = "True";
        }
        else
        {
            evenArray[index] = "False";
        }
        isPrime(testArray[index]);
        if((isPrime(testArray[index])) == true)
        {
            isPrimeArray[index] = "True";
        }
        else
        {
            isPrimeArray[index] = "False";
        }

    }


//Heading Output for Table of Numbers
cout << setw(6) << "Base" <<  setw(10) << "Square" <<  setw(13) << "Sqr. Root" <<  setw(8) <<  "Cube" <<  setw(13)
<< "Cube Root" <<  setw(10) <<  "Even" <<  setw(10) << "Prime" << endl;
    cout << setw(6) << "----" <<  setw(10) << "------" <<  setw(13) << "---------" <<  setw(8) <<  "----" <<  setw(13)
    << "---------" <<  setw(10) <<  "----" <<  setw(10) << "-----" << endl;

    //Loop to format the output of the results of functions being called
    for (int index = 0; index < rows; index++) {
        cout << setw(7)  << testArray[index] << setw(8)  << squared[index] << setw(14);


        //Conditional Statement the Square Root Value.  If value less than Zero -- "N/A" will be output
        if ((testArray[index]) < 0)
        {
            cout << "N/A";
        }
            else
        {
                cout << setprecision(5) << squareRootArray[index];

        }


           cout << setw(8) << cubedArray[index] << setw(12);

        //Conditional Statement the Cubed Root Value.  If value less than Zero -- "N/A" will be output
        if ((testArray[index]) < 0)
        {
            cout << "N/A";
        }
        else
        {
            cout << setprecision(5) << cubedRootArray[index];

        }

        cout << setw(11) << evenArray[index] << setw(10) << isPrimeArray[index] <<  endl;
}


    return 0;
}



//Squaring Function
double squarefunction(int sqrtArray)
{
    double result;
    result = sqrtArray * sqrtArray;
    return result;
}


//Square Root Function
double rootFunc(int sqrtArray)
{
    double result;
    result = sqrt(sqrtArray);
    return result;
}


//Cube Function
double cubeFunc(int array)
{
    double result;
    result = (array *array) *array;
    return result;
}


//Cube Root Function
double cubeRootFunc(int array)
{
    double result;
    result = cbrt(array);
    return result;
}


//Even Or Odd Function
bool evenOdd(int array)
{
    bool evenOddFlag = false;
array = array % 2;

    if (array % 2 == 0) {
        evenOddFlag = true;

    }
    return evenOddFlag;
}


//Function to test number's primeness
bool isPrime(int array)
{
    if (array <= 1)
        return false;

    for (int i = 2; i < array; i++)
        if (array % i == 0)
            return false;

    return true;
}
