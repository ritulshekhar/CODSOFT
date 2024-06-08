//Student Grading System

#include <iostream>
#include <vector>                                                       //To insert the grades in Vector
#include <algorithm>                                                    //To use min_element and max_element
using namespace std;
int main()
{
    int n;
    cout << "Enter Number of Entries: " << endl;                        //For Number of Students
    cin >> n;
    while (n != 0)
    {

        string StudentName;
        int RegNo;
        cout << "Enter Registration Number: " << endl;
        cin >> RegNo;
        cout << "Enter Student Name: " << endl;
        cin >> StudentName;
        vector<int> grades;                                             //Creating a vector of 'int' type
        int English, Mathematics, Physics, Chemistry, Biology;
        cout << "Enter English Grades: " << endl;
        cin >> English;
        cout << "Enter Mathematics Grades: " << endl;
        cin >> Mathematics;
        cout << "Enter Physics Grades: " << endl;
        cin >> Physics;
        cout << "Enter Chemistry Grades: " << endl;
        cin >> Chemistry;
        cout << "Enter Biology Grades: " << endl;
        cin >> Biology;
        if (n > 1)                                                      //If the number of entries is more than 1
        {
            cout << "Grades of the Students are: " << endl;
            cout << "English: " << English << endl;
            cout << "Mathematics: " << Mathematics << endl;
            cout << "Physics: " << Physics << endl;
            cout << "Chemistry: " << Chemistry << endl;
            cout << "Biology: " << Biology << endl;
        }
        else                                                           //If the number of entries is just 1
        {
            cout << "Grades of the Student is: " << endl;
            cout << "English: " << English << endl;
            cout << "Mathematics: " << Mathematics << endl;
            cout << "Physics: " << Physics << endl;
            cout << "Chemistry: " << Chemistry << endl;
            cout << "Biology: " << Biology << endl;
        }
        grades.push_back(English);                                      //Inserting elements in the vector
        grades.push_back(Mathematics);
        grades.push_back(Physics);
        grades.push_back(Chemistry);
        grades.push_back(Biology);
        auto max_grade = max_element(grades.begin(), grades.end());     //Printing Maximum Grades
        auto min_grade = min_element(grades.begin(), grades.end());     //Printing Minimum Grades
        cout << "Maximum grade: " << *max_grade << endl;
        cout << "Minimum grade: " << *min_grade << endl;
        n--;
    }
    return 0;
}
    