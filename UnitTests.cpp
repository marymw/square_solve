#pragma once
#include "SolveSq.h"



void Test_GetQuad_sol(int *TestCount,double a,
                                     double b,
                                     double c,
                                     double *Solution_matrix_forTest,
                                     double RightX1,
                                     double RightX2,
                                     int RightRootsNumber){

    int RootsNumber = GetQuadSolutions(a, b, (double)c, Solution_matrix_forTest);

    #ifdef DEBAG 
        printf ("\nЗначение TestCount = %d\n", *TestCount);
    #endif

    if (RootsNumber != RightRootsNumber){
        printf("\nTest %d is failed.\n", *TestCount);
        printf("Right answer is RightRootsNumber = %d\nYour answer is RootsNumber = %d", RightRootsNumber, RootsNumber);
    }

    #ifdef DEBAG
        printf("%lf\n", Solution_matrix_forTest[0]);
        printf("%lf\n", RightX1);
        printf("%d\n", IsZero(Solution_matrix_forTest[0], RightX1));
        if ((!IsZero(Solution_matrix_forTest[0], RightX1)))
            printf("Here!!!!");
        if (RightRootsNumber == 1 || RightRootsNumber == 2)
            printf("No, HERE!!!!");
        if (((!IsZero(Solution_matrix_forTest[0], RightX1))) && (RightRootsNumber == 1 || RightRootsNumber == 2))
            printf("wow!!!");
    #endif


    if((!IsZero(Solution_matrix_forTest[0], RightX1)) && (RightRootsNumber == 1 || RightRootsNumber == 2)){
        printf("\nTest %d is failed.", *TestCount);
        printf("\nRight answer is x_1 = %lf\nYour answer is x_1 = %lf", RightX1, Solution_matrix_forTest[0]);
    }
    if((!IsZero(Solution_matrix_forTest[1], RightX2)) && RightRootsNumber == 2){
        printf("\nTest %d is failed.", *TestCount);
        printf("\nRight answer is x_2 = %lf\nYour answer is x_2 = %lf", RightX2, Solution_matrix_forTest[1]);
    }
    else printf("Test %d is OK\n", *TestCount);

    #ifdef DEBAG 
        printf ("\nЗначение TestCount = %d\n", *TestCount);
    #endif

    (*TestCount)++;

    #ifdef DEBAG 
        printf ("\nЗначение TestCount = %d\n", *TestCount);
        printf("я пришел\n");
    #endif

}


void Test_GetLin_sol(int *TestCount,double b,
                                    double c,
                                    double *Solution_matrix_forTest,
                                    double RightX1, 
                                    int RightRootsNumber){

    int RootsNumber = GetLinSolutions(b, c, Solution_matrix_forTest);

    if (RootsNumber != RightRootsNumber){
        printf("\nTest %d is failed.\n", *TestCount);
        pritnf("Right answer is RightRootsNumber = %d\nYour answer is RootsNumber = %d", RightRootsNumber, RootsNumber);
    }

    if((!IsZero(Solution_matrix_forTest[0], RightX1)) && RightRootsNumber == 1){
        printf("\nTest %d is failed.", *TestCount);
        printf("\nRight answer is x_1 = %lf\nYour answer is x_1 = %lf", RightX1, Solution_matrix_forTest[0]) ;
    }

    else printf("Test %d is OK\n", *TestCount);

    (*TestCount)++;
}

void Unit_Test(const int MAX_ROOTS) {
        int TestCount = 1;
        double *Solution_matrix_forTest = (double *)calloc(MAX_ROOTS, sizeof(double));

        Test_GetQuad_sol(&TestCount,   1,       2,   2, Solution_matrix_forTest,        0,        0, 0);
        Test_GetQuad_sol(&TestCount,   1,       2,   1, Solution_matrix_forTest,       -1,        0, 1);
        Test_GetQuad_sol(&TestCount,   1,       2, 1.1, Solution_matrix_forTest,        0,        0, 0);
        Test_GetQuad_sol(&TestCount,   1,       1,   1, Solution_matrix_forTest,        0,        0, 0);
        Test_GetQuad_sol(&TestCount,   1,       2,  -1, Solution_matrix_forTest, 0.414214,-2.414214, 2);
        Test_GetQuad_sol(&TestCount, eps, 2 * eps, eps, Solution_matrix_forTest,       -1,        0, 1);
        Test_GetLin_sol (&TestCount,   0,       0,      Solution_matrix_forTest,        0,           3);

        free(Solution_matrix_forTest);
}
