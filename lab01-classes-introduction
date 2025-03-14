#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Student {
    std::string name;
    std::string surname;
    std::vector<float> grades;
    float final_grade;
public:

    Student(string n, string s)
    {
        name = n;
        surname = s;
    }
    Student(string n)
    {
        name = n;
    }

    string get_name()
    {
        return name;
    }
    void set_name(string n)
    {
        name = n;
    }


    void calculate_grade() {
        float sum = std::accumulate(grades.begin(), grades.end(), 0.0f);
        final_grade =  sum / grades.size();
    }

    void print ()
    {
        cout << name << " " << surname << " " ;
        for (auto g : grades)
        {
            cout << g << ",";
        }
        cout << " Final: " << final_grade << endl;
    }
    bool add_grade(float grade) {
        if (grade >= 2.0 && grade <= 5.0) {
            // The grade is valid; let's add it and return true
            grades.push_back(grade);
            return true;
        }
        // The grade is invalid; let's return false
        return false;
    }
};

int main()
{

    Student student("Iman", "Esfandiyar"); //create object and give name an surname

    for(int i = 0; i < 10; i++) // add some grades
    {
        student.add_grade(i);
    }
    student.calculate_grade();

    student.print(); // To print name, surname, grades and final grade
    return 0;
}
