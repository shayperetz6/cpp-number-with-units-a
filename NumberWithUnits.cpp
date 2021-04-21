#include "NumberWithUnits.hpp"
using namespace std;
namespace ariel{
        NumberWithUnits:: NumberWithUnits (double num,string str){
            value=num;
            type=str;
        }
         void NumberWithUnits:: read_units(std::ifstream &file){
            
        }
        // Arithmetic operators
        NumberWithUnits NumberWithUnits:: operator +=(const NumberWithUnits& num1)
        {
            this->value+=num1.value;
            return *this;

        }
        NumberWithUnits NumberWithUnits:: operator -=(const NumberWithUnits& num1)
        {
            this->value-=num1.value;
            return *this;

        }
        NumberWithUnits operator +(const NumberWithUnits& num1,const NumberWithUnits& num2)
        {
            double temp=num1.value+num2.value;
            NumberWithUnits x(temp,num1.type);
            return x;
        }
        NumberWithUnits operator -(const NumberWithUnits& num1,const NumberWithUnits& num2)
        {
             double temp=num1.value-num2.value;
            NumberWithUnits x(temp,num1.type);
            return x;
        }
        
        NumberWithUnits operator*(const NumberWithUnits& num1,double num2){
            double temp=num2*num1.value;
            return NumberWithUnits(temp,num1.type);
        }
        NumberWithUnits operator*(double num1,const NumberWithUnits& num2){
            double temp=num1*num2.value;
            return NumberWithUnits(temp,num2.type);
        }
        
        // compares operators

        bool operator ==(const NumberWithUnits& num1,const NumberWithUnits& num2){
            return((num1.value==num2.value)&&(num1.type==num2.type));
        }
        bool operator !=(const NumberWithUnits& num1,const NumberWithUnits& num2){
            return((num1.value!=num2.value)||(num1.type!=num2.type));
        }
        bool operator <=(const NumberWithUnits& num1,const NumberWithUnits& num2){
            return((num1.value<=num2.value)&&(num1.type==num2.type));
        }
        bool operator >=(const NumberWithUnits& num1,const NumberWithUnits& num2){
            return((num1.value>=num2.value)&&(num1.type==num2.type));
        }
        bool operator <(const NumberWithUnits& num1,const NumberWithUnits& num2){
            return((num1.value<num2.value)&&(num1.type==num2.type));
        }
        bool operator >(const NumberWithUnits& num1,const NumberWithUnits& num2){
            return((num1.value>num2.value)&&(num1.type==num2.type));
        }

        //output && input operators
    
        ostream& operator<< (std::ostream& os, const NumberWithUnits& num){
            os<<num.value<<"["<<num.type<<"]"<<endl;
            return os;
        }
        istream& operator>> (std::istream& input, NumberWithUnits& num){
            return input;
        }
}