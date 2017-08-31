//
// Created by wbl on 2017/8/29.
//

#include <stdio.h>
#include <malloc.h>


//int main()
//{
//    int rows = 0, cols = 0;
//    int Ax = 0, Ay = 0, Bx = 0, By = 0, Cx = 0, Cy = 0;
//    int A[3][2];
//    int index = 0;
//    char x;
//    scanf("%d,%d\n", &rows,&cols);
//
//    char position[rows][cols];
//    for(int i = 0; i < rows; i++) {
//        for (int j = 0; j < cols; j++) {
//            scanf("%c", &position[i][j]);
//            if (position[i][j] == '+') {
//                A[index][0] = i + 1;
//                A[index][1] = j + 1;
//                index++;
//
//            }
//        }
//        getchar();
//    }
//
//    scanf("%d,%d,%d,%d", &Ax, &Ay, &Bx, &By);
//    getchar();
//
//    int flag = 0;
//
//    for(int i = 0 ; i < index ;i++)
//    {
//        if(!((A[i][0] == Ax && A[i][1] == Ay )|| (A[i][0] == Bx && A[i][1] == By)))
//            flag = i;
//    }
//    Cx = A[flag][0];
//    Cy = A[flag][1];
//
//    printf("%d %d\n", Cx, Cy);
//    int Dx = 0, Dy = 0;
//    Dx = Ax - (Cx - Bx);
//    Dy = Ay - (Cy - By);
//    if(Dx > rows || Dy > cols)
//        printf("0");
//    else
//        printf("%d %d\n", Dx, Dy);
//}


int* toCompleteParallelogram(int rows, int cols, char ** positionsInPark, int euclidX, int euclidY, int monteX, int monteY)
{
    int* result = (int*)malloc(sizeof(int)*2);
    int A[3][2];
    int index = 0;
    for(int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {

            if (positionsInPark[i][j] == '+') {
                A[index][0] = i + 1;
                A[index][1] = j + 1;
            }
        }
    }

    int flag = 0;
    for(int i = 0 ; i < index ;i++)
    {
        if(!((A[i][0] == euclidX && A[i][1] == euclidY )|| (A[i][0] == monteX && A[i][1] == monteY)))
            flag = i;
    }
    int Cx = A[flag][0];
    int Cy = A[flag][1];
    int Dx = euclidX - (Cx - monteX);
    int Dy = euclidY - (Cy - monteY);
    if(Dx <= rows && Dy <= cols)
    {
        result[0] = Dx;
        result[1] = Dy;
    }
    return result;
}


