#include <iostream>
#include < vector>
#include<string >
using namespace std;

vector <int> age;
vector<int> application_number;
vector <string> name; 
//
//
//
//
//
//
//
int main()
{
    vector <int> age;
    vector<int> application_number;
    vector <string> name;
    int number;
    cout << " how many data sets you want to enter"<<endl;
    cin >> number;
    for (int i = 0;i<number;i++)
    {
        cout << "enter the date of member\t:" << i+1 << endl;
        
        {
            int aged;
            cout << "enter your age" << endl;
            cin >> aged;
            age.push_back(aged);
            //cin.ignore();
            cout << endl;

        }
       // void application_number_enter()
        {
            int temp;
            cout << "enter your application number \n" << endl;
            cin >> temp;
            application_number.push_back(temp);

        }
        //
        //

       // void name_enter()
        {
            cin.ignore();
            string temp;
            cout << "enter your name" << endl;
            getline(cin, temp);
            name.push_back(temp);
            
        }
        cout << "----------------------------------------------------------------------------------------------------------" << endl;

    }
    for (int i = 0;i < number;i++)
    {
        /* << age[i] << endl;
        cout << name[i] << endl;
        cout << application_number[i] << endl;*/
        cout << "age of\t " << name[i] << "\twhose application number is\t " << application_number[i] << "\t is\t" << age[i]<<endl;
        cout <<endl;
    }
    cout << "Hello World!\n" << endl;
}

