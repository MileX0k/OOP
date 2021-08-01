#include <vector>
#include <iostream>
#include <cassert>
using namespace std;

class ArrayInt
{
private:
    int m_lenght;
    int* m_data;

public:
    ArrayInt() : m_lenght(0), m_data(nullptr) {}

    ArrayInt(int lenght)
        : m_lenght(lenght)
    {
        assert(lenght >= 0);

        if (lenght > 0)
            m_data = new int[lenght];
        else
            m_data = nullptr;
    }

    ~ArrayInt()
    {
        delete[] m_data;
    }

    void erase() //Очистка массива( clear() ) 
    {
        delete[] m_data;
        m_data = nullptr;
        m_lenght = 0;
    }

    int getLenght() const { return m_lenght; }

    int& operator[] (int index) //Доступ к элементам массива
    {
        assert(index >= 0 && index < m_lenght);
        return m_data[index];
    }

    void resize(int newLenght) //Изменяет длину массива (resize())
    {
        if (newLenght == m_lenght)
            return;

        if (newLenght <= 0)
        {
            erase();
            return;
        }

        int* data = new int[newLenght];

        if (m_lenght > 0)
        {
            int elementsToCopy = (newLenght > m_lenght) ? m_lenght : newLenght;

            for (int index = 0; index < elementsToCopy; index++)
            {
                data[index] = m_data[index];
            }

        }
        delete[] m_data;
        m_data = data;
        m_lenght = newLenght;
    }

    void insertBefore(int value, int index) //Добавление нового элемента в массив
    {
        assert(index >= 0 && index <= m_lenght);
        int* data = new int[m_lenght + 1];

        for (int before = 0; before < index; before++)
            data[before] = m_data[before];

        data[index] = value;

        for (int after = index; after < m_lenght; after++)
            data[after + 1] = m_data[after];

        delete[] m_data;
        m_data = data;
        ++m_lenght;
    }

    void push_back(int value) { insertBefore(value, m_lenght); }

    //===========================================TASK 1================================================

    void pop_back() { resize(m_lenght - 1); } //Сокращает исходный массив на 1, тем самым удаляет последний элемент в исходном массиве (pop_back())

    void deleteAfter(int index) //Удаление элемента по индексу
    {
        assert(index >= 0 && index <= m_lenght);

        int* data = new int[m_lenght - 1];

        for (int front = 0; front < index; front++)
            data[front] = m_data[front];

        for (int after = index; after < m_lenght - 1; after++)
            data[after] = m_data[after + 1];

        delete[] m_data;
        m_data = data;
        --m_lenght;
    }

    void pop_front() { deleteAfter(0); } //Удаляет первый элемент (pop_front())

    void sortBubbleArray() //Самая обычная сортировка пузырьком
    {
        for (int i = 0; i < m_lenght; i++)
        {
            for (int j = 0; j < m_lenght - 1; j++)
            {
                if (m_data[j] > m_data[j + 1])
                {
                    int temp = m_data[j];
                    m_data[j] = m_data[j + 1];
                    m_data[j + 1] = temp;
                }
            }
        }

    }

    void const print() //Выводит на экран элементы массива
    {
        cout << "Array: " << endl;

        for (int index = 0; index < m_lenght; index++)
        {
            cout << m_data[index] << " ";
        }

        cout << endl;
    }
};

void testTask1()
{
    ArrayInt myArr{};
    myArr.push_back(66);
    myArr.push_back(55);
    myArr.push_back(44);
    myArr.push_back(33);
    myArr.push_back(22);
    myArr.push_back(11);
    myArr.print();

    myArr.pop_back();
    myArr.print();

    myArr.pop_front();
    myArr.print();

    myArr.sortBubbleArray();
    myArr.print();

}

//===========================================TASK 2================================================

void print(vector <int> const v1)
{
    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << " ";
    }
    cout << endl;
}

void sortAndDelete(vector <int> v1)
{
    vector <int> copy = v1;
    vector<int>::iterator it = copy.begin();
    for (int i = 0; i < copy.size(); i++)
    {
        for (int j = 0; j < copy.size() - 1; j++)
        {
            if (copy[j] > copy[j + 1])
            {
                int boo = copy[j];
                copy[j] = copy[j + 1];
                copy[j + 1] = boo;
            }
        }
    }

    while (it != copy.end())
    {
        for (int i = 0; i < copy.size() - 1; i++)
        {
            int temp = copy[i];
            if (temp == copy[i + 1])
                copy.erase(it + 1);
        }
        it++;
    }
    cout << "Sorted array: " << endl;
    print(copy);
    cout << "Unique numbers: " << copy.size() << endl;
}


int main()
{
    //===========================================TASK 1================================================
    cout << "   TASK 1:" << endl;
    testTask1();
    cout << endl;

    //===========================================TASK 2================================================
    cout << "   TASK 2:" << endl;
    vector <int> example{ 2, 4, 4, 5, 2, 15, 23, 2, 9 };
    cout << "Default array: " << endl;
    print(example);
    sortAndDelete(example);
    cout << endl;


    return 0;
}

