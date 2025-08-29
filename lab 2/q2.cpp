#include <iostream>
#include<limits>
using namespace std;

int main()
{
    int departments;
    cout << "Enter number of departments: ";
    cin >> departments;

    int *students = new int[departments];   // store student count for each dept
    int ***marks = new int **[departments]; // 3D: dept,student, subject

    // input number of students in each department
    for (int i = 0; i < departments; i++)
    {
        cout << "Enter number of students in department " << i + 1 << ":";
        cin >> students[i];

        marks[i] = new int *[students[i]]; // allocate students for dept
        for (int j = 0; j < students[i]; j++)
        {
            marks[i][j] = new int[5]; 
        }
    }

    // Input marks
    cout << "\nEnter marks (5 subjects per student):\n";
    for (int i = 0; i < departments; i++)
    {
        cout << "Department " << i + 1 << ":\n";
        for (int j = 0; j < students[i]; j++)
        {
            cout << "  Student " << j + 1 << ":";
            for (int k = 0; k < 5; k++)
            {
                cin >> marks[i][j][k];
            }
        }
    }

    // Processing each department
    for (int i = 0; i < departments; i++)
    {
        double total = 0;
        int count = 0;
        double highest =INT_MIN, lowest = INT_MAX;

        for (int j = 0; j < students[i]; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                double m = marks[i][j][k];
                total += m;
                count++;
                if (m > highest)
                    highest = m;
                if (m < lowest)
                    lowest = m;
            }
        }

        double avg = (double)total / count;
        cout << "\nDepartment"<< i + 1 << ":\n";
        cout << "Highest="<< highest << "\n";
        cout << "Lowest="<< lowest << "\n";
        cout << "Average="<< avg << "\n";
    }

    // free memory
    for (int i = 0; i < departments; i++)
    {
        for (int j = 0; j < students[i]; j++)
        {
            delete[] marks[i][j];
        }
        delete[] marks[i];
    }
    delete[] marks;
    delete[] students;

    return 0;
}
