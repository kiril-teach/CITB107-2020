#include <iostream>
#include <fstream>
#include <sstream>
#include <cassert>
#include <cmath>
#include <vector>

using namespace std;

class Course
{
public:
    Course(string id, vector<float> grades)
    {
        this->id = id;
        this->grades = grades;
    }

    string id;
    vector<float> grades;
};

float sum(const vector<float> &numbers)
{
    float sum = 0;
    for (int i = 0; i < numbers.size(); i++)
    {
        sum += numbers[i];
    }
    return sum;
}

float avg(const vector<float> &numbers)
{
    return sum(numbers) / numbers.size();
}

bool parseLine(string line, string &courseID, vector<float> &grades)
{
    stringstream values(line);
    string id;
    getline(values, courseID, ',');
    courseID = courseID.substr(0, 7);

    string noop;
    float grade;
    while (values >> grade)
    {
        grades.push_back(grade);
        getline(values, noop, ',');
    }

    return true;
}

string fileForStudent(const string &student)
{
    string path = "lab10/data/";
    path.append(student);
    path.append(".csv");
    return path;
}

vector<Course> readGrades(const string &student, string &error)
{
    vector<Course> courses;

    ifstream fin(fileForStudent(student));
    if (fin.fail())
    {
        error = "cannot open file";
        return {};
    }

    string line;
    while (getline(fin, line))
    {
        string courseID;
        vector<float> grades;

        bool ok = parseLine(line, courseID, grades);
        if (!ok)
        {
            error = "cannot parse course grades";
            return {};
        }
        courses.push_back(Course(courseID, grades));
    }

    return courses;
}

bool testParseLine(string line, string expectedCourseID, vector<float> expectedGrades)
{
    string courseID;
    vector<float> grades;

    parseLine(line, courseID, grades);

    if (courseID != expectedCourseID)
    {
        return false;
    }

    if (grades.size() != expectedGrades.size())
    {
        return false;
    }

    for (int i = 0; i < grades.size(); i++)
    {
        if (grades[i] != expectedGrades[i])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    assert(sum({1, 2, 3, 4, 5}) == 15);
    assert(sum({}) == 0);
    assert(avg({1, 2}) == 1.5);

    assert(testParseLine("CITB110,5,6", "CITB110", {5, 6}));
    assert(testParseLine("CITB110   , 5   ,   6, 4", "CITB110", {5, 6, 4}));

    assert(fileForStudent("f12345") == "lab10/data/f12345.csv");

    // Read Input
    vector<vector<Course>> coursesByStudent;
    string student;
    while (cin >> student)
    {
        string error;
        vector<Course> courses = readGrades(student, error);
        if (error.length())
        {
            cout << "ERROR: cannot read grades for student " << student << ": " << error << endl;
        }
        else
        {
            coursesByStudent.push_back(courses);
        }
    }

    cerr << "DEBUG: coursesByStudent count=" << coursesByStudent.size() << endl;

    // Computation/Logic
    vector<float> averagePerStudent;
    for (int i = 0; i < coursesByStudent.size(); i++)
    {
        vector<Course> courses = coursesByStudent[i];
        vector<float> averagePerCourse(courses.size());
        for (int k = 0; k < courses.size(); k++)
        {
            averagePerCourse[k] = avg(courses[k].grades);
        }
        averagePerStudent.push_back(avg(averagePerCourse));
    }

    float result = avg(averagePerStudent);

    // Output
    cout << result << endl;

    return 0;
}