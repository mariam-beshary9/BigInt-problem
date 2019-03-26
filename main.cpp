#include <iostream>
#include <valarray>

using namespace std;

class BigDecimalInt {

    private:
        string num ;
        valarray <int> digits ;
    public:

       /// constructor to make it from string
        BigDecimalInt (int number){
        num= to_string(number);

            if (num[0]=='-')
                {  digits.resize(num.length()-1);  /// we will load from the second element if the first was a "-" sign
                   for (int i=0 ; i<num.size()-1; i++)
                   {
                        digits[i] = num[i+1] -'0';
                   }
                }

            else   {  digits.resize(num.length());
                    for (int i=0 ; i<num.size(); i++)
                {
                        digits[i] = num[i]-'0' ;
                }
                   }

        }

        BigDecimalInt (string decStr)
        {
            num = decStr ;
            if (num[0]=='-')
                {  digits.resize(num.length()-1);  /// we will load from the second element if the first was a "-" sign
                   for (int i=0 ; i<num.size()-1; i++)
                   {
                        digits[i] = num[i+1] -'0';
                   }
                }

            else   {  digits.resize(num.length());
                    for (int i=0 ; i<num.size(); i++)
                {
                        digits[i] = num[i]-'0' ;
                }
                   }
        }

       BigDecimalInt operator+ (BigDecimalInt o2)
        {
        bool greater1 ;
        bool greater2 ;
        bool equall;

        int size1= digits.size();
        int size2=o2.digits.size();
        int size11=size1;
        int size22=size2;

        /// it shows who is the greatest if the size is equal
            if (size1==size2)
            {
                for (int i =0 ; i<size1 ; i++)
                {
                    if (digits[i] > o2.digits[i]) {greater1 =1 ; break;}
                    else if (digits[i] < o2.digits[i]){ greater2 =1 ; break;}

                } if (greater1==0 && greater2==0) equall=1 ;
            }
            /// Adding two positive
            if ((num[0]!='-')&&( o2.num[0]!='-'))
            {
                ///if the first is the greater
                if ((size1>size2)|| greater1 ||equall)
                {
                    BigDecimalInt o = BigDecimalInt (num) ;
                    o.digits.resize(size1);

                    for (int i=0 ; i<size1 ;i++)
                    {
                        o.digits[i]=  digits[i];
                    }
                    for (int i=0 ; i<size2;i++)
                    {
                        o.digits[size11-1] += o2.digits[size22-1];
                        size11-=1;
                        size22-=1;
                    }for (int i=o.digits.size()-1 ; i>0; i--)
             {
                    if (o.digits[i]>9)
                    {

                            o.digits[i]-=10;
                            o.digits[i-1] +=1 ;


                    }
                   else if (o.digits[i]<0)
                    {
                            o.digits[i]+=10 ;
                            o.digits[i-1]-=1;

                }
             }

            return o ;
                } /// same for the second
                else if ((size2>size1)|| greater2)
                {
                    BigDecimalInt o =o2;
                     o.digits.resize(size2);
                    for (int i=0 ; i<size2 ;i++)
                    {
                        o.digits[i]=  o2.digits[i];
                    }
                    for (int i=0 ; i<size1;i++)
                    {
                        o.digits[size22-1] += digits[size11-1];
                        size11-=1;
                        size22-=1;
                    }for (int i=o.digits.size()-1 ; i>0; i--)
             {
                    if (o.digits[i]>9)
                    {

                            o.digits[i]-=10;
                            o.digits[i-1] +=1 ;


                    }
                   else if (o.digits[i]<0)
                    {
                            o.digits[i]+=10 ;
                            o.digits[i-1]-=1;

                }

             }

            return o ;
                }
            }



            ///If the sign of the two numbers are negative
            else if((num[0]=='-')&&(o2.num[0]=='-'))
            {
                    ///if the first is the greater
                if ((size1>size2)||greater1 ||equall)
                {
                    BigDecimalInt o = BigDecimalInt (num) ;
                    o.digits.resize(size1);
                    for (int i=0 ; i<size1 ;i++)
                    {
                        o.digits[i]=  digits[i];
                    }
                    for (int i=0 ; i<size2;i++)
                    {
                        o.digits[size11-1] += o2.digits[size22-1];
                        size11-=1;
                        size22-=1;
                    }for (int i=o.digits.size()-1 ; i>0; i--)
             {
                    if (o.digits[i]>9)
                    {

                            o.digits[i]-=10;
                            o.digits[i-1] +=1 ;


                    }
                   else if (o.digits[i]<0)
                    {
                            o.digits[i]+=10 ;
                            o.digits[i-1]-=1;

                }

             } o.digits[0]*=-1 ;

            return o ;
                }
                else if((size2>size1)|| greater2)
                {   BigDecimalInt o =o2;
                     o.digits.resize(size2);
                    for (int i=0 ; i<size2 ;i++)
                    {
                        o.digits[i]=  o2.digits[i];
                    }
                    for (int i=0 ; i<size1;i++)
                    {
                        o.digits[size22-1] += digits[size11-1];
                        size11-=1;
                        size22-=1;
                    }for (int i=o.digits.size()-1 ; i>0; i--)
             {
                    if (o.digits[i]>9)
                    {

                            o.digits[i]-=10;
                            o.digits[i-1] +=1 ;


                    }
                   else if (o.digits[i]<0)
                    {
                            o.digits[i]+=10 ;
                            o.digits[i-1]-=1;

                }

             }  o.digits[0]*=-1 ;

            return o ;
                }   //o2.digits[0]*=-1 ;

            }


            ///If the first is positive and the second is negative.

           else if ((num[0]!='-')&& o2.num[0]=='-')
           {

           if ((size1> size2) || greater1 || equall )
           {
                    BigDecimalInt o = BigDecimalInt (num) ;
                    o.digits.resize(size1);
                for (int i=0 ; i<size1 ;i++)
                {
                    o.digits[i]= digits[i];
                }
                for (int i=0 ; i<size2;i++)
                {
                            o.digits[size11-1]-=o2.digits[size22-1] ;
                            size11-=1;
                            size22-=1;
                }for (int i=o.digits.size()-1 ; i>0; i--)
             {
                    if (o.digits[i]>9)
                    {

                            o.digits[i]-=10;
                            o.digits[i-1] +=1 ;


                    }
                   else if (o.digits[i]<0)
                    {
                            o.digits[i]+=10 ;
                            o.digits[i-1]-=1;

                }

             }

            return o ;
            }
                else if ((size1<size2)|| greater2)
                {   BigDecimalInt o =o2;
                     o.digits.resize(size2);
                    for (int i=0 ; i<size2 ;i++)
                    {
                    o.digits[i]=  o2.digits[i];
                    }
                    for (int i=0 ; i<size1;i++)
                    {
                            o.digits[size22-1]-= digits[size11-1]  ;
                            size11-=1;
                            size22-=1;
                       //o2.digits[0]*=-1 ;for (int i=o.digits.size()-1 ; i>0; i--)
             {
                    if (o.digits[i]>9)
                    {

                            o.digits[i]-=10;
                            o.digits[i-1] +=1 ;


                    }
                   else if (o.digits[i]<0)
                    {
                            o.digits[i]+=10 ;
                            o.digits[i-1]-=1;

                }}}

            o.digits[0]*=-1 ;

            return o ;
                }
            }
            /// If the first is negative and the second is positive
            else if  ((num[0]=='-')&& (o2.num[0]!='-'))
             {
                 if ((size1>size2)||greater1||equall )
                 {
                    BigDecimalInt o = BigDecimalInt (num) ;
                    o.digits.resize(size1);

                    for (int i=0 ; i<size1 ;i++)
                    {
                        o.digits[i]= digits[i];
                    }
                    for (int i=0 ; i<size2;i++)
                            {
                                o.digits[size11-1]-= o2.digits[size22-1]  ;

                                size11-=1;
                                size22-=1;
                                }for (int i=o.digits.size()-1 ; i>0; i--)
             {
                    if (o.digits[i]>9)
                    {

                            o.digits[i]-=10;
                            o.digits[i-1] +=1 ;


                    }
                   else if (o.digits[i]<0)
                    {
                            o.digits[i]+=10 ;
                            o.digits[i-1]-=1;

                }

             } o.digits[0]*=-1 ;

            return o ;
                } //o2.digits[0]*=-1 ;
                else if ((size1<size2)||greater2)
                {   BigDecimalInt o =o2;
                     o.digits.resize(size2);
                    for (int i=0 ; i<size2 ;i++)
                        {
                        o.digits[i]=  o2.digits[i];
                        }
                    for (int i=0 ; i<size1;i++)
                    {
                                o.digits[size22-1]-= digits[size11-1]  ;
                                size11-=1;
                                size22-=1;
                    }for (int i=o.digits.size()-1 ; i>0; i--)
             {
                    if (o.digits[i]>9)
                    {

                            o.digits[i]-=10;
                            o.digits[i-1] +=1 ;


                    }
                   else if (o.digits[i]<0)
                    {
                            o.digits[i]+=10 ;
                            o.digits[i-1]-=1;

                }

             }

            return o ;
                }

            }



        }

        bool operator= (BigDecimalInt o2)
        {

             int x;

             if (num.size()!= o2.num.size())  return false;
             if (num[0]!= o2.num[0])  return false;

             if (num[0]=='-'&& o2.num[0]=='-')
             {      x = num.size()-1;
             }
             else
             {      x= num.size();
             }


             for (int i=0 ; i<x;i++)
            {
                    if ( digits[i] != o2.digits[i])  return false ;
            }
             return true ;

        }

        friend ostream& operator << (ostream& out, BigDecimalInt b){
        int x;
         if (b.num[0]=='-')
             {      x = b.num.size()-1;
             }
             else
             {      x=b.num.size();
             }

        for (int i=0 ; i<x;i++){
            out<<b.digits[i];

            }
        return out;
        }
};

int main()
{
string x,y;
int c ;
while (true)
{
cout<<"Enter the number of operation you want to make .\n1)Add two numbers.\n2)vertify if they are equal.\n3)Exit"<<endl;
cin>>c;
 if (c==3) return 0;
cout<<"Enter the first number :  ";
cin>>x;
cout<<endl<<"Enter the second number : ";
cin>>y;
   BigDecimalInt o1(x);
   BigDecimalInt o2(y);


    if (c==1)
    {
        if (x.size()>y.size ())
             cout<<endl<<"The sum = "<<o1+o2<<endl<<endl;
        else cout<<endl<<"The sum = "<<o2+o1 <<endl<<endl;
    }
    else if (c==2){
    if(o1=o2) cout<<"They are equal"<<endl;
    else cout<<"They are not equal"<<endl;

    }

    else {
    cout<<"You have entered a wrong choice . Enter the number of operation!"<<endl;
    }
}
    return 0;
}
