#include <unistd.h>
#include <ncurses.h>
#include <math.h>
#include <stdlib.h>

#define DIM 9     //better if ODD
#define FREQ 100


typedef struct{
    int rows;
    int columns;
    char **grid;
} Matrix; 



void test(Matrix *matrix)
{
    for(int x = 0; x < DIM; x ++)
    {
        for(int y = 0; y < DIM; y ++) printf("%c ", matrix->grid[x][y]);
        printf("\n");
    }
}

void rotate_coordinates(int *x, int *y, int frequency);

void convert_X(int x, int dimension);

void convert_Y(int y, int dimension);

int main(){
    Matrix *currentState;
    Matrix *nextState;
    int frequency = FREQ;
    
    //---- INITIALIZATION OF THE GRID ------
    
    currentState = malloc(sizeof(Matrix));
    currentState->rows = DIM;
    currentState->columns = DIM;
    currentState->grid = malloc(currentState->columns * sizeof(char *));
    for(int i = 0; i < currentState->columns; i ++) currentState->grid[i] = malloc(currentState->rows * sizeof(char));
    for(int i = 0; i < currentState->rows; i ++)
    {
        for(int j = 0; j < currentState->columns; j++)
        {
            if (i == 5 && j < 5) currentState->grid[j][i] = 'X';
            else currentState->grid[j][i] = ' ';
        }
    }
    nextState = malloc(sizeof(Matrix));
    nextState->rows = DIM;
    nextState->columns = dim;
    nextState->grid = malloc(nextState->columns * sizeof(char *));
    for(int i = 0; i < nextState->columns; i ++) nextState->grid[i] = malloc(nextState->rows *sizeof(char));
    test(currentState);
	/*initscr();
    mvprintw(5, 1, "Donut"); 
    refresh(); 
    endwin(); */
    return 0;
}

void convert_X(int x, int dimension)
{
    return x - ((dimension - 1)/2);
}

void convert_Y(int y, int dimension)
{
    return ((dimension - 1)/2) - y;
}

void rotate_coordinates(int *x, int *y, int arg)
{
    *x = x * sin(arg) + x * cos(arg);
    *y = -y + cos(arg) + y * sen(arg);
    return;
}

