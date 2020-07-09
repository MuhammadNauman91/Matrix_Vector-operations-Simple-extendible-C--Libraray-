/*
***********************************************************************************
*	Author: 			Muhammad Nauman Nasir
*	Creation Date:      20.06.2020
*	Last Edit Date:     21.06.2020
*	Revision:			0
*	Version:			1
*	File   :            Matrix_Vector_Multiplication_main.cpp
**********************************************************************************/

#include "Matrix_Vector_Multiplication.h"
#include <iostream>
#include "Vector.h"

using namespace std;
using namespace algorithm;

int main()
{
	///< Matrix initialization based on dimensions needed e.g 3*3 or 2*2
    int srcA[]= {2,4,3,1,5,7,0,2,3};
    ///< Creation of Object and assigning dimensions of matrix e.g (3*3 or 3*2 or 2*2 etc)
    algorithm::Matrix<int> matA(3,3);
    ///< Calling member functions change size of matrix in our case we have 9 elements in srcA so placed nine
    matA.PopulateMatrix (srcA,9);
    matA.Print();

    ///< Vector initialization based on dimensions needed e.g 3*1 or 3*3
	std::vector<std::vector<int>> v {{2}, {5}, {6}};
	std::vector<std::vector<int> > x{{2,3,4}, {5,6,7}, {6,5,8}};
	///< Creation of Object and assigning dimensions of Vector e.g (3*1 or 3*2 or 3*3 etc)
	algorithm::VectorImp<int> p;
	///< Calling member functions
	p.Populate_Vector1D(v);
	p.Populate_Vector3D(x);
	p.Print_1D(v);
	p.Print_3D(x);

	///< Calling Matrix Vector Multiplication function
	matA.MultiplyMatVec(matA,p);
	///< Calling Matrix Vector Addition function
    matA.MatVecAddition_3D(matA,p);

    std::cout <<std::endl;
    cout << "Vector size = "
    << p.Get_Capacity(x) << endl;
    return 0;

}
