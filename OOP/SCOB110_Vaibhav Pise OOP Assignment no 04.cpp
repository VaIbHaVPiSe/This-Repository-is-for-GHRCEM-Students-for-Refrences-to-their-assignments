#include<iostream>
#include<iomanip>
using namespace std;
class MAT
{
 float **M;
 int rs,cs;
 public:
 MAT(){}
 void creat(int r,int c);
 friend istream & operator >>(istream &,MAT &);
 friend ostream & operator <<(ostream &,MAT &);
 MAT operator+(MAT M2);
 MAT operator-(MAT M2);
 MAT operator*(MAT M2);
};
void MAT::creat(int r,int c)
{
 rs=r;
 cs=c;
 M=new float *[r];
 for(int i=0;i<r;i++)
 M[i]=new float;
}
istream & operator>>(istream &din, MAT &a)
{
 int r,c;
 r=a.rs;
 c=a.cs;
 for(int i=0;i<r;i++)
 {
 for(int j=0;j<c;j++)
 {
 din>>a.M[i][j];
 }
 }
 return (din);
}
ostream & operator<<(ostream &dout,MAT &a)
{
 int r,c;
 r=a.rs;
 c=a.cs;
 for(int i=0;i<r;i++)
 {
 for(int j=0;j<c;j++)
 {
 dout<<setw(5)<<a.M[i][j];
 }
 dout<<"\n";
 }
return (dout);
}
MAT MAT::operator+(MAT M2)
{
 MAT Mt;
 Mt.creat(rs,cs);
 for(int i=0;i<rs;i++)
 {
 for(int j=0;j<cs;j++)
 {
 Mt.M[i][j]=M[i][j]+M2.M[i][j];
 }
 }
 return Mt;
}
MAT MAT::operator-(MAT M2)
{
 MAT Mt;
 Mt.creat(rs,cs);
 for(int i=0;i<rs;i++)
 {
 for(int j=0;j<cs;j++)
 {
 Mt.M[i][j]=M[i][j]-M2.M[i][j];
 }
 }
 return Mt;
}
MAT MAT::operator*(MAT M2)
{
 MAT Mt;
 Mt.creat(rs,M2.cs);
 for(int i=0;i<rs;i++)
 {
 for(int j=0;j<M2.cs;j++)
 {
 Mt.M[i][j]=0;
 for(int k=0;k<M2.rs;k++)
 Mt.M[i][j]+=M[i][k]*M2.M[k][j];
 }
 }
 return Mt;
 }
int main()
{
 MAT m1,m2,m3,m4,m5;
 int r1,c1,r2,c2;
 cout<<" Enter first MATrix size : ";
 cin>>r1>>c1;
 m1.creat(r1,c1);
 cout<<"M1 = ";
 cin>>m1;
 cout<<" Enter second MATrix size : ";
 cin>>r2>>c2;
 m2.creat(r2,c2);
 cout<<"M2 = ";
 cin>>m2;
 cout<<" M1:"<<endl;
 cout<<m1;
 cout<<" M2: "<<endl;
 cout<<m2;
 cout<<endl<<endl;
 if(r1==r2 && c1==c2)
 {
 m3.creat(r1,c1);
 m3=m1+m2;
 cout<<" M1 + M2: "<<endl;
 cout<<m3<<endl;
 m4.creat(r1,c1);
 m4=m1-m2;
 cout<<" M1 - M2:"<<endl;
 cout<<m4<<endl<<endl;
 }
 else
 cout<<" SumMATion & substraction are not possible n"<<endl
 <<"Two MATrices must be same size for sumMATion & substraction "<<endl<<endl;
if(c1==r2)
{

 m5=m1*m2;
 cout<<" M1 x M2: "<<endl;
 cout<<m5;
}
else
cout<<" Multiplication is not possible "<<endl
<<" Column of first MATrix must be equal to the row of second MATrix ";
return 0;
}
