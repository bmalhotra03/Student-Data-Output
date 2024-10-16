// Brij Malhotra
// lab9.cpp
// Input: techincally is not there
// Output: prints data in tables 
// Example, file xyz, data printed out and sorted

#include<iostream>
#include<iomanip>
#include<fstream>

using namespace std;

// Student structure

struct student
{
    string name;
    string ID;
    int credits;
    double GPA;
};

int main()
{
    ifstream infile;
    student stud[150];
    int i, j, rec = 0, creds;
    string temporary;
    double maxGPA, gpa1;
    
    
    infile.open("lab9input.dat");
    if(!infile)
    {
       cout << "File did not open properly";
       return 0;
   }
   
   while(!infile.eof())
   {
      // read the data
     
      infile >> stud[rec].name;
      infile >> stud[rec].ID;
      infile >> stud[rec].credits;
      infile >> stud[rec].GPA;
      rec++;
   }
   
   // assigning a variable to the student with the max GPA

   maxGPA = 0;
   
   for(i = 0; i < rec; i++)
   {
       if(maxGPA < stud[i].GPA)
       {
          maxGPA = stud[i].GPA;
          j = i;
           }
       }
       
   // Printing out details of student with highest GPA
   
   cout<< endl << "Student with the highest GPA :";
   cout<< endl <<"Name : " << stud[j].name;
   cout<< endl <<"ID : " << stud[j].ID;
   cout<< endl <<"Credits : " << stud[j].credits;
   cout<< endl <<"GPA : " <<stud[j].GPA;
   cout<<fixed<<setprecision(2);
   
   cout << endl << endl << endl;
   
   // Printing out all student details
   

   cout << "STUDENT DETAILS";
   
   for(i = 0; i < rec; i++)
   {
      cout<<endl<<stud[i].name<<"\t"<<stud[i].ID<<"\t"<<stud[i].credits<<"\t"<<stud[i].GPA;
       }  

for(i = 0; i < rec; i++)
{
    for(j = i+1; j < rec; j++)
    {
       if(stud[i].name > stud[j].name)
       {
          
          temporary = stud[i].name;
          stud[i].name = stud[j].name;
          stud[j].name = temporary;
          temporary.erase();
          
          temporary = stud[i].ID;
          stud[i].ID = stud[j].ID;
          stud[j].ID = temporary;
          temporary.erase();
          
          creds = stud[i].credits;
          stud[i].credits = stud[j].credits;
          stud[j].credits = creds;
          
          gpa1 = stud[i].GPA;
          stud[i].GPA = stud[j].GPA;
          stud[j].GPA = gpa1;
         
       }
   }
       }         
       
   cout << endl << endl << endl;
   cout << "Sorted details for students- ";
   
   for(i = 0; i < rec; i++)
   {
      cout << endl << endl;
      cout << stud[i].name << "\t" <<stud[i].ID << "\t" << stud[i].credits << "\t" << stud[i].GPA;
       }      
      
}

// usage of /t taken from the internet because I wanted to see how I could add space to make it look like a table. 