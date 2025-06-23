#include <stdio.h>

void flipLeftRight(int square[][10], int size, int index)
{
	int a = size - 2*index;
	int temp = 0;
	for (int i = index; i < a+index; i++)
	{
		if(i == index || i == a+index-1)
		{
			for(int j = index; j <= index + a/2; j++)
			{
				temp = square[i][j];
				square[i][j] = square[i][size-j-1];
				square[i][size-j-1] = temp;
			}
		}
		else
		{
			temp = square[i][index];
			square[i][index] = square[i][a+index-1];
			square[i][a+index-1] = temp;
		}
	}
}

void printSquare(int square[][10], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%3d ", square[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(void) {
    int square[10][10];
    int size = 4;

    // Fill square with numbers 1 to 16
    int value = 1;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            square[i][j] = value++;
        }
    }

    printf("Original Squarelotron:\n");
    printSquare(square, size);

    flipLeftRight(square, size, 0); // Flip outer ring (ring 0)

    printf("After flipping ring 0 left to right:\n");
    printSquare(square, size);

    return 0;
}