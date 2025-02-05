#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<time.h>
#include<string.h>


# define ANSI_COLOR_RED "\xlb[31m"
# define ANSI_COLOR_GREEN "\xlb[32m"
# define ANSI_COLOR_YELLOW "\xlb[33m"
# define ANSI_COLOR_BLUE "\xlb[34m"
# define ANSI_COLOR_MAGENTA "\xlb[35m"
# define ANSI_COLOR_CYAN "\xlb[36m"
# define ANSI_COLOR_RESET "\xlb[0m"


// creating matrix 4*4
void createMatrix(int arr[][4])
{
    int n = 15;
    int num[n], i, j;
    for (i = 0; i < 15; i++)
        num[i] = i + 1; //these 1 - 15 number will be in the matrix
    srand(time(NULL));
    int lastIndex = n - 1, index;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j ++) 
        {
            if (lastIndex >= 0)
            {
                index = rend() % (lastIndex + 1); // idea: performing % operation by (lastIndex + 1)
                arr[i][j] = num[index]; // Linear Congruential Generator (LCG) while given index, so put the num[index] number in matrix.
                num[index] = num[lastIndex--]; // and replace last number with this index positioned index
            }//finilized lastIndex
        }
    }
    arr[i - 1][j - 1] = 0;
}



// showing matrix

void showMatrix(int arr[][4])
{
    int i, j;
    printf("----------------\n");
    for (i = 0; i < 4; i ++) {
        printf("|");
        for (j = 0; j < 4; j ++) {
            if (arr[i][j] != 0){
                printf("%2d | ", arr[i][j]);
            }
            else{
                printf("  | ");
            }
        }
        printf("\n");
    }
    printf("---------------\n");
}


// winitng check by this function

int winning(int arr[][4])
{
    int i, j, k = 1;
    for (i = 0; i < 4; i ++) {
        for (j = 0; j < 4; j++, k++) {
            if (arr[i][j] != k && k != 16){
                break;
            }

        }
        if (j < 4) {
            break;
        }

    }
    if (j < 4){
        return 0;
    }
    return 1;
}

// swaping the number 

void swap(int *x, int *y) {
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
    printf("");
}


// read the input value from the user and return the ascii value of that
int ReadEnteredKey(){
    char c;
    c = _getch();
    if (c == -32){
        c = _getch();
    }
    return c;
}

// shift up function

int shiftUp(int arr[][4])
{
    int i, j;
    for (i= 0; i < 4; i++){
        for(j = 0; j < 4; j++ ) {
            if (arr[i][j] == 0){
                break;
            }
        }
        if(j < 4){
            break;
        }

    }
    if(i == 3)//shifting not possible
        return 0;
    //sussfully swap two number
    swap(&arr[i][j], &arr[i + 1][j]);
    return 1; // success
}

swapDown(int arr[][4])
{
    int i, j;
    for (i= 0; i < 4; i++){
        for(j = 0; j < 4; j++ ) {
            if (arr[i][j] == 0){
                break;
            }
        }
        if(j < 4){
            break;
        }

    }
    if(i == 0)//shifting not possible
        return 0;
    //sussfully swap two number
    swap(&arr[i][j], &arr[i - 1][j]);
    return 1; // success
}

shiftRight(int arr[][4])
{
    int i, j;
    for (i= 0; i < 4; i++){
        for(j = 0; j < 4; j++ ) {
            if (arr[i][j] == 0){
                break;
            }
        }
        if(j < 4){
            break;
        }

    }
    if(i == 3)//shifting not possible
        return 0;
    //sussfully swap two number
    swap(&arr[i][j], &arr[i][j - 1]);
    return 1; // success
}

shiftLeft(int arr[][4])
{
    int i, j;
    for (i= 0; i < 4; i++){
        for(j = 0; j < 4; j++ ) {
            if (arr[i][j] == 0){
                break;
            }
        }
        if(j < 4){
            break;
        }

    }
    if(i == 3)//shifting not possible
        return 0;
    //sussfully swap two number
    swap(&arr[i][j], &arr[i][j + 1]);
    return 1; // success
}

// game Rule

void gameRule(int arr[][4]) {
    system("cls");
    int i, j, k = 1;
    printf("\t\t  MATRIX PUZZLE\n");
    printf("\n");
    printf(ANSI_COLOR_RED "         Rule of The GAME            \n"ANSI_COLOR_RESET);
    printf(ANSI_COLOR_RED"\nyou can move only 1 stape at a time, by Arrow Key"ANSI_COLOR_RESET);
    printf("\n\tMove Up    : by Up arrow Key.")
    printf("\n\tMove Down  : by Down arrow Key.")
    printf("\n\tMove Left  : by Left arrow Key.")
    printf("\n\tMove Right : by Right arrow Key.")
}




int main() {
    int arr[4][4];
    int maxTry = 4;
    char name[20];
    for (int i = 0; i < 3; i++) {
        printf("\n");
    }
    printf("Player Name: ");
    scanf("%s", name);

    // while (1)
    // {
        createMatrix(arr);
        gameRule(arr);
    // }
}