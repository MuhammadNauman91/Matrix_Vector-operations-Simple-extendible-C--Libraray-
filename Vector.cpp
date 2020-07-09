/*
***********************************************************************************
*	Author: 			Muhammad Nauman Nasir
*	Creation Date:      20.06.2020
*	Last Edit Date:     21.06.2020
*	Revision:			0
*	Version:			1
*	File   :            Vector.cpp
**********************************************************************************/

#include "Vector.h"
#include <iostream>

using namespace std;
using namespace algorithm;

/*!
    This is Default Constructor with initialized Parameter
*/
template <class T>
algorithm::VectorImp<T>::VectorImp()
{
	m_recent =0;
}


/*!
    This is Default Destructor
*/
template <class T>
algorithm::VectorImp<T>::~VectorImp()
{

}


/*!
    * This function is used to to get size of the vector
    * @param  data [in]  Input Vector values
    * @return  m_recent [out] size of the vector
*/
template <class T>
int algorithm::VectorImp<T>::Get_Capacity(std::vector <std::vector<T>> &data)
{
    m_recent =  data.size();
    return m_recent;
}


/*!
    * This functions reads elements from Vector 3*1 and populate the elements of Vector with those values
    * @param  data [in]  Input Vector values [3*1]
    * @Output m_vec[i] [out] Populated vector with the desired Input values
*/
template <class T>
void algorithm::VectorImp<T>::Populate_Vector1D(std::vector <std::vector<T>> &data)
{
    for (unsigned int i = 0; i < data.size(); i++)
    {
        ///< printing the 2D vector.
        for (unsigned int j = 0; j < data[i].size(); j++)
        {
    	    m_vec [i]   = data[i][j];
        }
    }
}


/*!
    This functions is used to print out the values for 3*1 Vector
*/
template <class T>
void algorithm::VectorImp<T>::Print_1D(std::vector <std::vector<int>> &data)
{
    std::cout << "Output of Vector  (3*1)  =  "<<std::endl;
    for (unsigned int i = 0; i < data.size(); i++)
    {
        ///< printing the 2D vector.
        for (unsigned int j = 0; j < data[i].size(); j++)
        {
            std::cout<<  m_vec[i]<<" " ;
        }
       std::cout<< endl;
    }

    std::cout << endl;
}


/*!
    * This functions reads elements from Vector 3*3 and populate the elements of Vector with those values
    * @param  data [in] Input Vector values [3*3]
    * @Output m_vec3D[i][j] [out] Populated vector with the desired Input values
*/
template <class T>
void algorithm::VectorImp<T>::Populate_Vector3D(std::vector <std::vector<T>> &data)
{
    for (unsigned i = 0; i < data.size(); i++)
    {
        ///< printing the 2D vector.
        for (unsigned j = 0; j < data[i].size(); j++)
        {
    	    m_vec3D[i][j]   = data[i][j];
        }
    }
}


/*!
    This functions is used to print out the values for 3*3 Vector
*/
template <class T>
void algorithm::VectorImp<T>::Print_3D(std::vector <std::vector<int>> &data)
{
	std::cout << "Output of Vector  (3*3)  =  "<<std::endl;
    for (unsigned i = 0; i < data.size(); i++)
    {
        ///< printing the 2D vector.
        for (unsigned j = 0; j < data[i].size(); j++)
        {
            std::cout<<  m_vec3D[i][j]<<" " ;
        }

        std::cout<< endl;
    }

    std::cout << endl;
}

template class VectorImp <int>;
