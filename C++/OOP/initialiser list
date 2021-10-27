/* the following program illustrates a special syntax  */

#include <iostream>
using namespace std;

class Student{
  string name;

 public:                                 // we are mentioning the access specifier as public as by default access to members of c++ class is private 
   int average_marks;
   long roll_number;
   Student(long x , string y , int z): average_marks(z),roll_number(x),name(y){}    // same as : Student(int x) { average_marks=x; }
  
    // Note this syntax is valid only for constructors 
    
    string get_name(){
    return name;
    }
  
  };
  
  int main()
  {
    string n ;
    long r;
    int m;
   
   cout<<" Enter the name of a student : ";
   cin>>n;
   
   cout<<" Enter the roll number of the student (9 digit number) : ";
   cin>>r;
   
    cout<<" Enter the average mark of the student : ";
   cin>>m;
   
   
  
    Student s(r,n,m);                                                       
    cout<<"The student's average mark " << s.average_marks << endl;   
    cout<<"The student's roll number " << s.roll_number << endl;    
    
    // here if you directly try to access the name variable of s i.e. s.name it will result in an error because the access specifier of name variable is private
    
     cout << s.get_name(); // this will give the value in the name variable because members within the object can access the private variable 

    
    return 0;
  }
