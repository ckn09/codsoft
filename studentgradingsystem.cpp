#include<iostream>
#include<vector>
#include<string>

using namespace std;

class student {
    public:
    string name;
    double grade;

    student(const string &n, double g) : name(n), grade(g) {}
} ;

int main(){
    int n;
    vector<student> students;

    cout<<"How many students are there ?  ";
    cin>>n;
    cin.ignore();
    
    for(int i = 0; i < n; i++){
        string name;
        double grade;

        cout<<"Enter the name of student  "<< i+1 << " : ";
        getline(cin,name);
       
        cout<<"Enter the grade of "<< name << " : ";
        cin>>grade;
        cin.ignore();
        
        students.push_back(student(name, grade));
    }

    double totalGrades = 0;
    double highestGrade = students[0].grade;
    double lowestGrade = students[0].grade;

    for(const student &s : students){
        totalGrades += s.grade;
        if (s.grade > highestGrade){
            highestGrade = s.grade;
        }   
        if(s.grade < lowestGrade){
            lowestGrade = s.grade;
        }
    }
    double averageGrade = totalGrades/n;

    cout << "Average Grade : " << averageGrade << endl;
    cout << "Highest Grade : " << highestGrade << endl;
    cout << "Lowest Grade : " << lowestGrade << endl;

    return 0;
}