/**********************************************************************************
**	 Implementation of a class generating simple vector [3*1]
***********************************************************************************
*	Author: 			Muhammad Nauman Nasir
*	Creation Date:      20.06.2020
*	Last Edit Date:     21.06.2020
*	Revision:			0
*	Version:			1
*	File   :            Matrix_Vector_Multiplication.h
**********************************************************************************/
/****************************************************************************
**	DESCRIPTION
*****************************************************************************
**	Problem Statement:
**	2 Classes 1 matrix class and other vector class.
**	Addition and multiplication of vectors and matrices shall be supported.
**
**  Proposed Solution:
**  2 Template classes with extensible functional space.
**  - -	Multiply function for 3*3 matrix and 3*1 vector multiplication.
**  - -	Addition of matrices and vector 3*3 and 3*3.
**      (This is quite flexible if you follow the rules of matrix addition means it will also work
**       for 2*2 matrix and 2*2 vector).
**
** Idea:
** - - To make Extensible class with flexibility to extend the methods based upon needs e.g transpose ,
**	   subtraction, rotation and translation etc.
**
**	   This file contains Simple Template Class with functions for Generation of [3*3] or [3*1] etc
**	   matrices based upon needs and considerable functions to support the actions
****************************************************************************/
#ifndef MATRIX_VECTOR_MULTIPLICATION_H_
#define MATRIX_VECTOR_MULTIPLICATION_H_

#pragma once
#include <iostream>
#include<vector>
#include <time.h>
#include <ostream>
#include "Vector.h"
#define LENGTH 3
#define WIDTH  3

namespace algorithm
{
    template <typename T>
    class VectorImp;
    template <typename T>
    class Matrix
    {
        private:
            T m_rows;
            T m_cols;
            T g[LENGTH];
            T **m_mat;

        public:
            ///< Default constructor
	         Matrix (T m_rows , T m_cols);
	        ///<Default destructor
            ~Matrix();
            ///< This function is used to store the values of matrix in memory under heap
            ///< Allocate memory for Rows and Columns
            T **CreateMatrix(int m_rows, int m_cols);
            ///< This functions reads elements from array and populate the elements of matrix with those values
            void PopulateMatrix(T *src, T size);
            ///< This functions is used to print out the values for 3*3 Input Matrices
            void Print();
            ///< This functions is used to Multiply the matrices 3*3 and Vector 3*1 and give the results
            void MultiplyMatVec (Matrix<T>& p, VectorImp<T>& v);
            ///< This functions is used to Add the matrices 3*3 and Vector 3*3 and give the results
            void MatVecAddition_3D  (Matrix<T>& p, VectorImp<T>& v);
    };
}

#endif
