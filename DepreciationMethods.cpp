/* Oct. 24, 2011
   Demonstrates the gradual value decline of an object using two methods*/
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

void straight_line(ofstream &,float, float, int);

void sum_of_digits(ofstream &, float, float, int);

int sumint(int); 
void print_headings (ofstream &, float, float, char);

int main()
{
    ifstream infile2;
    ofstream outfile2;
    infile2.open("infile2.txt");
    outfile2.open("outfile2.txt");
    
    float cost, junk_value;
    int years;
    char method;
     
    
    infile2 >> cost; // priming read
    
    while(infile2)
    {
    
    infile2 >> junk_value >> years >> method; //Read Inputs
    
    
    print_headings(outfile2,cost, junk_value,method);
    
    switch(method)
      {
      case 'S': straight_line(outfile2, cost, junk_value, years); break;               
      case 'D': sum_of_digits(outfile2 , cost, junk_value, years); break;
      default: outfile2 << "INVALID METHOD!\n\n\n"; break;
      }
    
    infile2 >> cost;
    }
    system("pause");
    return 0;
 
}
void straight_line(ofstream& output2, float cost, float junk_value, int years)
{
     float rate, accu,carry;
     rate =  (cost - junk_value)/years;
     
     for(int i = 1; i <= years; i++)
     {
     accu = i*rate;
     carry = cost - accu;
     
     output2 << " "<<i<< "\t\t\t "<< rate <<  "\t\t "<< accu <<"\t\t   " << carry << endl << endl;
     }
     
     return;
}
void sum_of_digits(ofstream & output2,  float cost, float junk_value, int years)
{
     int sum, i =0;
     float rate,depEx,carry,accu,depCost;
     
     depCost = cost - junk_value;
     sum  = sumint(years);
    
     for(int a = years; a >= 1; a--) 
     {
     depEx = (depCost*a)/sum;
     accu = accu + depEx;
     carry = cost - accu;
     i++;
     
     output2 << " "<<i<< "\t\t\t "<< depEx << "\t\t "<< accu <<"\t\t   "<< carry << endl << endl;
     
     }
    
}
int sumint(int n)
{
    
 int p;
  p = ((n*n) + n)/2;
  return p;
}
void print_headings(ofstream & output2, float cost, float junk_value, char method)
{
     switch(method)
    { case 'D': output2<< "Sum-of-digits method\n"<< endl; break;
      case 'S': output2<< "Straight-line method\n"<< endl; break;
      default:  output2 << "SOMETHING WENT WRONG"<< endl; break;
     } 
     output2 << "Original Cost =   "<<  fixed << setprecision(2) 
             << cost  <<"\t\tResidual Value =  "
             <<  setprecision(2) << junk_value <<endl << endl; 
     output2 << "Current Year" << "\tCurrent Deprec" << "\tAccum Depreciation" 
             << "\tCarry" << endl<<endl; 
     
}




