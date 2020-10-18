#include<iostream>
using namespace std;

class student
    {
        private:
        char name[20];int roll;char gender;

        public:
        void input(); void output();
    };

    void student:: input()
        {
            cout<<"Enter name:";  cin>>name;
            cout<<"Enter roll number:";  cin>>roll;
            cout<<"Enter gender(M/m or F/f):";cin>>gender;
        }

        void student :: output()
            {
                cout<<"Students Details:\n";
                cout<<"Name:"<<name<<"\tRoll Number:"<<roll<<"\tGender:"<<gender;
            }

            int main()
            {
                student std; std.input();std.output();return 0;
            }