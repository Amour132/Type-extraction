#pragma once

#include <iostream>
using namespace std;

struct TrueType//内置类型
{
	static bool Get()
	{
		return true;
	}
};

struct FalseType//自定义类型
{
	static bool Get()
	{
		return false;
	}
};

template<class T>
struct TypeTraits
{
	typedef FalseType IsPODType;
};

template<>
struct TypeTraits<char>
{
	typedef TrueType IsPODType;
};

template<>
struct TypeTraits<int>
{
	typedef TrueType IsPODType;
};

template<>
struct TypeTraits<double>
{
	typedef TrueType IsPODType;
};

template<>
struct TypeTraits<long>
{
	typedef TrueType IsPODType;
};

template<>
struct TypeTraits<short>
{
	typedef TrueType IsPODType;
};

template<class T>
void Copy(T* dest, const T* src, size_t size)
{
	if (TypeTraits<T>::IsPODType::Get())
	{
		memcpy(dest, src, size*sizeof(T));
	}
	else
	{
		for (size_t i = 0; i < size; i++)
		{
			dest[i] = src[i];
		}
	}
}

void Test()
{
	int a1[10] = { 0 };
	int a2[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	Copy(a1, a2, 10);
	for (const auto e : a1)
	{
		cout << e << " ";
	}
	cout << endl;

	string s1[] = {"hello","world","hehe","heihei"};
	string s2[4];
	Copy(s2, s1, 4);
	cout << endl;
}



