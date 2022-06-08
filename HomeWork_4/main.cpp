
// 1. ��������� ����������� ������ 'inArray[]' �������� 100 ��������� ���������� ������ ������� � ��������� [-25, 25]
//	��������� https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution;
// 2. ������� ������������ ������ 'dynArray[]' �� ����� ������� ���������� �� ������� 'inArray[]';
// 3. �������� �������������� ������� 'dynArray[]':
//		- � ������ ������� �������� ��������� ������� �� ������ ������� �������� �� ���������;
//		- � ��������� ��������� ������� �� ������ ���������� �� ������;
//		- �� ������ ��������� ������� �� ������ ������� �� �������������;
//		- �� ������ ��������� ������� �� ������ ������� �� �������������;
//		- � �.�.;
// ***���� ������� �� ��������, �� ��������� �������, ��� ���� ��� ���������.
// ***���� ����� ��������� � ������������ ������� ��������, �� ������� ������� ��������, ��� ���� ��� ����������.
//		- ������� ��� �������� �� ������������� ������� ������� �������;
//		- � ���������� ������� ����� 'dynArray[]' ����� � ������� ����������� � ������������ �����;
//		- ������� �������� ������.
// ***�������� ������������ ������ ����� ����� �����������. 
// ***������������ ������ ���� ����������� � ���� ������������ �������.

#include <iostream>
#include <array>
#include <vector>
#include "MyHeader.h"

using namespace HomeWork4Func;

int main()
{
	std::array<int, 100>inputArray = { 0 };
	std::vector<int>dynArray;
   
    // 1. ��������� ����������� ������ 'inArray[]' �������� 100 ��������� ���������� ������ ������� � ��������� [-25, 25]
    for (int& val : inputArray)
    {
        val = RandomGeneration(-25, 25); 

        // 2. ������� ������������ ������ 'dynArray[]' �� ����� ������� ���������� �� ������� 'inArray[]'
        switch (val & 1) 
        {
        case 0:
            dynArray.push_back(val);
        }
    }

    PrintVector(dynArray, 0);


    // 3. �������� �������������� ������� 'dynArray[]'

    //- � ������ ������� �������� ��������� ������� �� ������ ������� �������� �� ���������;
    //- � ��������� ��������� ������� �� ������ ���������� �� ������;
    //- �� ������ ��������� ������� �� ������ ������� �� �������������;
    //- �� ������ ��������� ������� �� ������ ������� �� �������������;
    //- � �.�.;
    size_t size = dynArray.size();
    std::vector<int>::reverse_iterator itRevers = dynArray.rbegin();
    std::vector<int>::iterator it = dynArray.begin();
    for (; it != dynArray.begin() + (size / 2); ++it, ++itRevers)
    {
        int num = *it;

        if (*itRevers != 0)
            *it %= *itRevers;

        if (num !=0)
            *itRevers %=num;
    }

    PrintVector(dynArray, 1);

    //- ������� ��� �������� �� ������������� ������� ������� �������
    it = dynArray.begin();

    for (int& val : dynArray)
    {
        switch (*it % 4 == 0 && *it != 0)
        {
        case true:
            it = dynArray.erase(it);
            continue;
        }

        it++;
    }

    PrintVector(dynArray, 2);

    //- � ���������� ������� ����� 'dynArray[]' ����� � ������� ����������� � ������������ �����;
    FindeMinMaxVal(dynArray);

    //- ������� �������� ������.
    PrintArray(inputArray);
}