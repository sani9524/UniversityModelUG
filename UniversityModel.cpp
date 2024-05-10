#include <iostream>
using namespace std;

class university {
    private:
        string name;
        string description;
        string location;
    public:
        university(string name, string description, string location) {
            this->name = name;
            this->description = description;
            this->location = location;
        }
        string getname() {
            return name;
        }
        string getdescription() {
            return description;
        }
        string getlocation() {
            return location;
        }
        static int students;
};

int university::students = 0;

class course {
    private:
        string name;
        string description;
        string lecturers;
    public:
        course(string name, string description, string lecturers) {
            this->name = name;
            this->description = description;
            this->lecturers = lecturers;
        }
        string getname() {
            return name;
        }
        string getdescription() {
            return description;
        }
        string getlecturers() {
            return lecturers;
        }
};

class student {
    private:
        string name;
        int age;
        int ID;
        static int totalstudents;
    public:
        student(): name(""), age(0), ID(0) {}
        student(string name, int age, int ID) {
            this->name = name;
            this->age = age;
            this->ID = ID;
            totalstudents++;
            university::students++;
        }
        string getname() {
            return name;
        }
        int getage() {
            return age;
        }
        int getID() {
            return ID;
        }
        static int gettotalstudents() {
            return totalstudents;
        }
};

int student::totalstudents = 0;

class ITstudent : public student {
    private:
        string faculty;
    public:
        ITstudent(string name, int age, int ID, string faculty): student(name, age, ID) {
            this->faculty = faculty;
        }
        string getfaculty() {
            return faculty;
        }
};

class EngineeringStudent : public student {
    private:
        string faculty;
    public:
        EngineeringStudent(string name, int age, int ID, string faculty): student(name, age, ID) {
            this->faculty = faculty;
        }
        string getfaculty() {
            return faculty;
        }
};

int main() {
    university uni("UG", "Private", "Tbilisi");
    course c("Programming", "C++ Introduction", "Lecturer 1");
    ITstudent ITs("Student 1", 18, 123456, "Informatics");
    EngineeringStudent EngineeringS("Student 2", 18, 654321, "Engineering");
    student student3("Student 3", 18, 7890);
    student student4("Student 4", 18, 9737);
    student student5("John", 20, 5555); 
    
    int studentarray = 3;
    student students[studentarray] = {
        student("student 6", 19, 5234), 
        student("student 7", 20, 1246), 
        student("student 8", 21, 2134)
    };

    cout << "University: " << uni.getname() << " , " << uni.getdescription() << " , " << uni.getlocation() << endl;
    cout << "Course: " << c.getname() << " , " << c.getdescription() << " , " << c.getlecturers() << endl;
    
    cout << "IT Student: " << ITs.getname() << " , " << ITs.getage() << " , " << ITs.getID() << " , " << ITs.getfaculty() << endl;
    cout << "Engineering Student: " << EngineeringS.getname() << " , " << EngineeringS.getage() << " , " << EngineeringS.getID() << " , " << EngineeringS.getfaculty() << endl;
    
    cout << "Students: " << university::students << endl;
    cout << "Total Students: " << student::gettotalstudents() << endl;
    
    return 0;
}
