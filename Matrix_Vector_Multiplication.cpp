/*
***********************************************************************************
*	Author: 			Muhammad Nauman Nasir
*	Creation Date:      20.06.2020
*	Last Edit Date:     21.06.2020
*	Revision:			0
*	Version:			1
*	File   :            Matrix_Vector_Multiplication.cpp
**********************************************************************************/
#include "Matrix_Vector_Multiplication.h"
#include <omp.h>
#include  <stdio.h>
#include <iostream>
#include "Vector.h"


using namespace std;
using namespace algorithm;

/*!
    Default Destructor
*/
template <class T>
algorithm::Matrix<T>::Matrix (T m_rows , T m_cols) : m_rows(m_rows),m_cols(m_cols)
{
	this ->m_mat = CreateMatrix(this ->m_rows ,this ->m_cols );
}


/*!
    * Default Destructor
    * Delete matrix from memory from Heap
    * Delete Rows
    * Delete Main Pointer
    * Avoid memory Leakage
*/
template <class T>
algorithm::Matrix<T>::~Matrix()
{
    for(int i=0; i< this->m_rows; i++)
    {
        delete[] this ->m_mat[i];
    }
}


/*!
    * This function is used to store the values of matrix in memory under heap
    * Allocate memory for Rows and Columns
    * @param m_rows [in]  Number of Rows of Input Matrices
    * @param m_cols [in]  Number of Column of Input Matrices
    * @return temp [out] Memory for rows and columns in heap for matrices
*/
template <class T>
T **algorithm::Matrix<T> ::CreateMatrix (int m_rows, int m_cols)
{
    T **temp = new int*[m_rows];

    for(int i =0; i< m_rows; i++)
    {
        temp[i] = new int[m_cols];
    }

    return temp;
}


template <class T>
void algorithm::Matrix<T> ::Print()
{
	std::cout << "Output of Matrices (3*3) =  "<<std::endl;
	for(int i=0;i<m_rows;i++)
	{
		for(int j =0; j<m_cols; j++)
		{
			std::cout<<m_mat[i][j]<<" ";
		}
		cout<<endl;
	}
}


/*!
    * This functions reads elements from array and populate the elements of matrix with those values
    * @param  src [in]  Pointer to Source array
    * @param  size [in]  Size of source
    * @Output m_mat[i][j] [out] Populated matrix with the desired Input values
*/
template <class T>
void algorithm::Matrix<T>::PopulateMatrix(T *src, T size)
{
    if (m_rows * m_cols !=size)
    {
        cout<<"size of matrix is not equal to size of array"<< endl;
        exit(-1);
    }

    int pos =0;
    for(int i=0;i<m_rows; i++)
    {
        for(int j=0;j<m_cols; j++)
        {
            this->m_mat[i][j]=src[pos++];
        }
    }
}


/*!
    * This functions is used to Multiply the matrices 3*3 and Vector 3*1 and give the results
    * @param  Matrix<T>& [in] 3*3 Matrix
    * @param  VectorImp<T> [in] 3*1 Vector
    * @Output g[i] [out] 3*1 Multiplied Output
*/
template <class T>
void algorithm::Matrix<T>:: MultiplyMatVec (Matrix<T>& p, VectorImp<T>& v)
{
    #pragma omp parallel
    int g[LENGTH];
    for (int i=0;i<m_rows;i++)
    {
        g[i]=0;
    }

    clock_t start = clock();
    #pragma omp for
    std::cout << "Output of Matrices (3*3) and Vector (3*1) multiplication =  "<<std::endl;
    for(int i=0;i<m_rows;i++)
    {
        for(int j=0;j<m_cols;j++)
        {
            g[i] = g[i]+( p.m_mat[i][j] * v.m_vec[j]);
        }

        std::cout <<g[i]<<std::endl;
    }

    clock_t stop = clock();
    std::cout <<std::endl;
    std::cout<< "Comuting time claculation ~~ " << std::endl;
    printf("Computing time = %0.9fus\n",
    double(stop - start)/CLOCKS_PER_SEC);
    printf("Computing time = %0.9fus\n",
    double(stop - start));
}


/*!
    * This functions is used to ADD the matrices 3*3 and Vector 3*3 and give the results
    * @param  Matrix<T>& [in]  3*3 Matrix
    * @param  VectorImp<T> [in]  3*3 Vector
    * @Output sum[i][j] [out] 3*3 Added Output
*/
template <class T>
void algorithm::Matrix<T>::MatVecAddition_3D(Matrix<T>& p, VectorImp<T>& v)
{
    int sum[LENGTH][WIDTH];
	for (unsigned i=0;i<LENGTH;i++)
    {
        for(unsigned j = 0; j < WIDTH; ++j)
		{
            sum[i][j] = 0;
	    }
	}

    ///< Addition of Matrices (3*3) and Vector (3*3).
	std::cout <<std::endl;
	std::cout << "Output of Matrices (3*3) and Vector (3*3) addition =  "<<std::endl;
    for(unsigned i=0;i<LENGTH;i++)
    {
		for(unsigned j=0;j<WIDTH;j++)
        {
            sum[i][j] = p.m_mat[i][j] + v.m_vec3D[i][j];
            std::cout << sum[i][j]<<" ";
        }

        std::cout <<std::endl;
    }
}

template class Matrix<int>;
