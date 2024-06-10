#include <iostream>
#include <algorithm>

const int markSize = 4;

struct Student
{
    std::string name;
    double averageMark;
    int marks[markSize] = { 0, 0, 0, 0 };
};

double GetAverageMark(const Student& student);
Student* GetTopStudent(Student students[], int size);
int CountStudentsWithAverageAbove(Student students[], int size, double N);
Student* GetTopPercentStudents(Student students[], int size, double percent, int& topSize);
void getBestStudents(Student* inStudents, unsigned inSize, Student* outStudents, unsigned& outSize, unsigned percent);

bool CompareStudents(const Student& st_1, const Student& st_2)
{
    return st_1.averageMark > st_2.averageMark;
}

int main()
{
    // Task 1
    Student student = { "Leonid", 0, {5, 4, 3, 3} };
    student.averageMark = GetAverageMark(student);

    std::cout << "Student: " << student.name << std::endl;
    std::cout << "Average mark: " << student.averageMark << std::endl;

    // Task 2
    Student arr_students[markSize] =
    {
        {"Leonid", 0, {5, 4, 3, 3}},
        {"Ivan", 0, {4, 3, 5, 4}},
        {"Oksana", 0, {3, 4, 5, 3}},
        {"Anton", 0, {5, 5, 4, 4}}
    };

    for (int i = 0; i < markSize; i++)
    {
        arr_students[i].averageMark = GetAverageMark(arr_students[i]);
    }

    // Task 3
    std::sort(arr_students, arr_students + markSize, CompareStudents);

    for (int i = 0; i < markSize; i++)
    {
        std::cout << "Student: " << arr_students[i].name << ", Average mark: " << arr_students[i].averageMark << std::endl;
    }

    // Task 4
    Student* topStudent = GetTopStudent(arr_students, markSize);
    if (topStudent)
    {
        std::cout << "Top Student: " << topStudent->name << ", Average mark: " << topStudent->averageMark << std::endl;
    }

    // Task 5
    double N = 4.0;
    int count = CountStudentsWithAverageAbove(arr_students, markSize, N);
    std::cout << "Number of students with average mark above " << N << ": " << count << std::endl;

    // Task 6
    double percent = 50.0;
    int topSize;
    Student* topPercentStudents = GetTopPercentStudents(arr_students, markSize, percent, topSize);
    std::cout << percent << "% Top Students:" << std::endl;
    for (int i = 0; i < topSize; i++)
    {
        std::cout << "Student: " << topPercentStudents[i].name << ", Average mark: " << topPercentStudents[i].averageMark << std::endl;
    }

    delete[] topPercentStudents;

    // Task 7
    Student bestStudents[markSize];
    unsigned bestStudentsSize = 0;
    unsigned requiredPercent = 50;

    getBestStudents(arr_students, markSize, bestStudents, bestStudentsSize, requiredPercent);
    std::cout << "Best " << requiredPercent << "% students:" << std::endl;
    for (unsigned i = 0; i < bestStudentsSize; ++i)
    {
        std::cout << "Student: " << bestStudents[i].name << ", Average mark: " << bestStudents[i].averageMark << std::endl;
    }

    return 0;
}

double GetAverageMark(const Student& student)
{
    int sum = 0;
    for (int i = 0; i < markSize; i++)
    {
        sum += student.marks[i];
    }

    double averageMark = static_cast<double>(sum) / markSize;

    return averageMark;
}

Student* GetTopStudent(Student students[], int size)
{
    if (size == 0) return nullptr;

    // The most successful student will be first in the sorted array
    return &students[0];
}

int CountStudentsWithAverageAbove(Student students[], int size, double N)
{
    int count = 0;
    for (int i = 0; i < size; ++i)
    {
        if (students[i].averageMark > N)
        {
            ++count;
        }
    }
    return count;
}

Student* GetTopPercentStudents(Student students[], int size, double percent, int& topSize)
{
    topSize = static_cast<int>(size * (percent / 100.0));
    Student* topStudents = new Student[topSize];
    for (int i = 0; i < topSize; ++i)
    {
        topStudents[i] = students[i];
    }
    return topStudents;
}

void getBestStudents(Student* inStudents, unsigned inSize, Student* outStudents, unsigned& outSize, unsigned percent)
{
    outSize = static_cast<unsigned>(inSize * percent / 100.0);
    for (unsigned i = 0; i < outSize; ++i)
    {
        outStudents[i] = inStudents[i];
    }
}