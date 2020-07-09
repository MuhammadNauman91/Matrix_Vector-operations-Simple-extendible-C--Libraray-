/**********************************************************************************
**	 Implementation of a class generating simple vector [3*1],[3*3] etc
***********************************************************************************
*	Author: 			Muhammad Nauman Nasir
*	Creation Date:      16.06.2020
*	Last Edit Date:     17.06.2020
*	Revision:			0
*	Version:			1
*	File   :            Vector.h
**********************************************************************************/
/****************************************************************************
**	DESCRIPTION
*****************************************************************************
**	Problem :
**	Simple Template Class with functions for Generation of [3*1] or [3*3]Vector
**
**	Idea:
**	To make Extensible class with flexibility to extend the methods based upon needs e.g transpose ,
**	subtraction, rotation and translation etc.
**	****************************************************************************/
#ifndef VECTOR_H_
#define VECTOR_H_
#pragma once
#include <iostream>
#include<vector>
#include "Matrix_Vector_Multiplication.h"
#define LEN 3
#define WID 3

namespace algorithm
{

    template <typename T>
    class matrix;
    template <typename T>
    class VectorImp
    {
        private:

	        int m_recent;

        public:

            T m_vec3D[LEN][WID];
            T m_vec[LEN];
            ///<Default constructor
            VectorImp();
            ///< Destructor
            ~VectorImp();
            ///< function to get size of the vector
            int Get_Capacity( std::vector <std::vector<T> > &data);
            ///< function to get assign desired values to the vector for [3*1 vector]
            void Populate_Vector1D(std::vector <std::vector<T> > &data);
            ///< function to get assign desired values to the vector for [3*3 vector]
            void Populate_Vector3D(std::vector <std::vector<T> > &data);
            ///< function to print values of [3*1] vector]
            void Print_1D(std::vector <std::vector<int> > &data);
            ///< function to print values of [3*3] vector]
            void Print_3D(std::vector <std::vector<int> > &data);
	};
}
#endif
