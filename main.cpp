/******************************************************************************

Austin Kinnear
Chapter 6 & 7 REVIEW Programming Assignment
09/26/2023 & 09/27/2023

*******************************************************************************/
#include <iostream>
using namespace std;

const int MATRIX_SIZE = 4; //Size of Matrix constant declared 

void displayMatrix(int matrix[MATRIX_SIZE][MATRIX_SIZE]); // each of the four required function prototypes
void findInt(int matrix[MATRIX_SIZE][MATRIX_SIZE], int value); //finds the integer given
void swapColumns(int matrix[MATRIX_SIZE][MATRIX_SIZE]); //swaps the columns
void displayMenu(); 
void functionExitCode();

int main()
{
    int matrix[MATRIX_SIZE][MATRIX_SIZE] = { //matrix given in assignemnt 
         {1, 3, 5, 7},
         {9, 11, 13, 15},
         {17, 19, 21, 23},
         {25, 27, 29, 31}
    };
    
    int choice = 0;
    
    do{
        displayMenu();
        cin >> choice;
        
        switch(choice){
        case 1: //displays matrix 
            cout << "\nHere is your array:\n";
            displayMatrix(matrix);
            break;
            
        case 2: //locates integer
            cout << "\nEnter an integer to locate: ";
            int value;
            cin >> value;
            findInt(matrix, value);
            break;
            
        case 3: //swaps columns 1 & 3, used sample output for text
            swapColumns(matrix);
            cout << "\nGot it! Column 1 and Column 3 have been swapped.";
            break;
        
        case 4: //Exit created
            functionExitCode();
            break;
        }
    } while (choice != 4);
    return 0; 
}

void displayMatrix(int matrix[MATRIX_SIZE][MATRIX_SIZE]){ //displays matrix for each input
    for (int row = 0; row < MATRIX_SIZE; row++){ //using row instead of the standard i so I can read it easier
        for(int col = 0; col < MATRIX_SIZE; col++){ //using col instead of j so I can read it easier
            cout << matrix[row][col] << "\t";
        }
        cout << endl;
    }
}

void findInt(int matrix[MATRIX_SIZE][MATRIX_SIZE],int value){ //finds specific int in matrix
    bool intFound = false; //Assume the integer has not been found yet
    for(int row = 0; row < MATRIX_SIZE; row++){ 
        for(int col = 0; col < MATRIX_SIZE; col++){ 
            if(matrix[row][col] == value){ //basic print for found integer
                cout << value << " is located on row " << row+1 << ", column "<< col+1 << ".\n";
                intFound = true;
                return;
            }
        }
    }
    if (!intFound){ //if the integer is not found within the matrix
        cout << value << " is not in the array.\n";
    }
}

void swapColumns(int matrix[MATRIX_SIZE][MATRIX_SIZE]){ //swaps two columns in matrix
    for (int row = 0; row < MATRIX_SIZE; row++){
        int tempVariable = matrix[row][0]; 
        matrix[row][0] = matrix[row][2]; //assigns 3rd column to 1st
        matrix[row][2] = tempVariable; //uses temp variable to assign 1st column to the 3rd
        
    }
}

void displayMenu(){ //displays physical menu
    cout << "\n***Menu***\n";
    cout << "\n1. Display Array \n";
    cout << "2. Find My Integer\n";
    cout << "3. Swap Column 1 with Column 3\n";
    cout << "4. Exit\n";
    cout << "\nPlease enter your choice: ";
}

void functionExitCode(){ //Displays message upon exit
    cout << "\nThanks for playing!\n";
}
