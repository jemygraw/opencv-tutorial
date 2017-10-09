//
// Created by jemy on 30/09/2017.
//

#include "examples.h"

void ex7_matrix_operations() {
    CvMat *matrix = cvCreateMat(2, 2, CV_32FC1);
    int sizes;
    cvGetDims(matrix, &sizes);
    printf("%d\n", sizes);

    float element_3_2 = CV_MAT_ELEM(*matrix, float, 3, 2);
    printf("%f\n", element_3_2);
    printf("%d\n", cvGetElemType(matrix));

}

void print_matrix(CvMat *matrix) {
    for (int row = 0; row < matrix->height; row++) {
        for (int col = 0; col < matrix->width; col++) {
            printf("%f,", CV_MAT_ELEM(*matrix, float, row, col));
        }
        printf("\n");
    }
}

void ex7_matrix_abs() {
    CvMat *matrix = cvCreateMat(4, 4, CV_32FC1);
    for (int i = 0; i < matrix->height; i++) {
        for (int j = 0; j < matrix->width; j++) {
            cvSet2D(matrix, i, j, cvScalar(-i * j));
        }
    }
    //src
    print_matrix(matrix);
    //clone one
    CvMat *newMatrix=cvCloneMat(matrix);

    //abs
    cvAbs(matrix, matrix);
    print_matrix(matrix);

    cvAbsDiff(matrix,newMatrix,matrix);
    print_matrix(matrix);

    cvAbsDiffS(matrix,newMatrix,cvScalar(10));
    print_matrix(newMatrix);
}

