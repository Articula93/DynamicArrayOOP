#include <iostream>
#include <cassert>
using namespace std;
class DynArray
{
	int* arr;
	int size;

public:
	DynArray(int sizeP)
		: arr{ new int[sizeP] {} }, size{ sizeP }
	{
		std::cout << "DynArr constructed for " << size
			<< " elements, for " << this << '\n';
	}
	DynArray() : DynArray(5) {}
	DynArray(DynArray& object) = delete;
	DynArray& operator=(DynArray& object) = delete;
	DynArray(DynArray&& object)
		: arr{ object.arr }, size{ object.size }
	{
		object.arr = nullptr;
		object.size = 0;
		std::cout << "DynArr move constructed for "
			<< size << " elements, for " << this
			<< '\n';
	}
	DynArray& operator=(DynArray&& object)
	{
		if (!(this == &object))
		{
			delete arr;
			arr = object.arr;
			size = object.size;
			object.arr = nullptr;
			object.size = 0;
		}
		std::cout << "DynArr move assigned for "
			<< size << " elements, for " << this
			<< '\n';
		return *this;
	}
	
	int operator[](int idx)const
	{
		assert(idx >= 0 and idx < size and "Index is out "
			"of range!");
		return arr[idx];
	}
	int& operator[](int idx)
	{
		assert(idx >= 0 and idx < size and "Index is out"
			"of range!");
		return arr[idx];
	}
	void enterCount();
	void print()const;
	void randomize();
	void Sort();
	void delElem();
	int Sum();
	~DynArray()
	{
		std::cout << "Try to free memory from DynArray for"
			<< arr << " pointer\n";
		delete[] arr;
		std::cout << "DynArr destructed for " << size
			<< " elements, for " << this << '\n';
	}
};
void DynArray::enterCount()
{
	cin >> this->size;
}
void DynArray::print()const
{
	for (int i{ 0 }; i < size; ++i)
	{
		std::cout << arr[i] << ' ';
	}
	std::cout << '\n';
}
void DynArray::randomize()
{
	for (int i{ 0 }; i < size; ++i)
	{
		arr[i] = rand() % 10;
	}
}
void DynArray::Sort()
{
	for (int i = 0; i < size; i++)
	{
		int min = arr[0];
		for (int j = i + 1; j < size; j++)
		{

			if (arr[j] < arr[i])
			{
				int buffer = arr[i];
				arr[i] = arr[j];
				arr[j] = buffer;
			}
		}
	}
}
void DynArray::delElem()
{
	for (auto i = 0; i < size; i++)
	{
		for (auto j = 0; j < size; j++)
		{
			if (i != j)
			{
				if (arr[i] == arr[j])
				{
					int buffer = arr[i];
					arr[i] = arr[j];
					arr[j] = buffer;
					size--;
				}
			}
		}
	}
}
int DynArray::Sum()
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
	   arr += arr[i];
	}
	return sum;
}
DynArray arrayFactory(int arrSize)
{
	DynArray arr{ arrSize };
	arr.randomize();
	return arr;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	const int arrSize{10};
	DynArray ar1{ arrayFactory(arrSize) };
	std::cout << "ar1 elements : ";
	ar1.print();
	std::cout << "\nChange every ar1 element to its "
		"square:\n";
	for (int i{ 0 }; i < arrSize; ++i)
	{
		ar1[i] *= ar1[i];
		std::cout << "ar1[" << i << "] = " << ar1[i] << '\n';
	}
	const DynArray ar2{ arrayFactory(arrSize) };
	std::cout << "ar2 elements :\n";
	for (int i{ 0 }; i < arrSize; ++i)
	{
		std::cout << "ar2[" << i << "] = " << ar2[i] << '\n';
	}
	
	cout << "Удаление повторяющихся элементов массива: "; ar1.delElem();
    ar1.print();
	cout << "Сортировка нашего массива: "; ar1.Sort();
	ar1.print();
	cout << "Введите количество элементов массива: "; ar1.enterCount();
    ar1.print();
	cout << "Сумма всех элементов массива:";
    cout << ar1.Sum();
	cout << endl;
	ar1.print();
	return 0;
}