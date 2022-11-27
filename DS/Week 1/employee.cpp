#include <iostream>
using namespace std;

class Employee{
    public:
    int emp_no;
    char name[50];
    float basic;
    float da;
    float it;
    float net_sal;
    float gross_sal;
    void read_details() {
        cout<<"Enter employee number: ";
        cin>>emp_no;
        fflush(stdin);
        cout<<"Enter name: ";
        cin.get(name,50);
        cout<<"Enter basic: ";
        cin>>basic;
        cout<<"Enter da: ";
        cin>>da;
        cout<<"Enter IT: ";
        cin>>it;
    }
    void net_salary() {
        net_sal=gross_sal-it;
    }
    void gross_salary() {
        gross_sal=basic+da;
    }
    void display_data() {
        cout<<"Gross Salary is "<<gross_sal<<endl;
        cout<<"Net Salary is "<<net_sal<<endl;
    }
};

int main() {
    int n;
    cout<<"Enter the number of employees: ";
    cin>>n;
    Employee emp[n];
    for (int i=0;i<n;i++) {
        emp[i].read_details();
        emp[i].gross_salary();
        emp[i].net_salary();
        emp[i].display_data();
    }
}