#include<iostream>
using namespace std;
typedef struct
{
int price;
int weight;
float max;
}ob;

void __swap(ob *a,ob* b)
{
  ob temp=*a;
  *a=*b;
  *b=temp;
}



int main()
{

cout<<"enter the no of elements"<<endl;
int n;
cin>>n;
ob object[n];


for(int i=0;i<n;i++)
{
   cout<<"enter the price "<<endl;
   cin>>object[i].price;
     cout<<"now enter crossponding weight"<<endl;
   cin>>object[i].weight;
   object[i].max=object[i].price/(float)object[i].weight;
}
//fixing the objects in decending order of pi/wi
//sorting
  for(int i=0;i<n-1;i++)
  {
   for(int j=i;j<n;j++)
   {
     if(object[j].max<object[j+1].max)
     {

        __swap(&object[j],&object[j+1]);

     }
   }
  }

  cout<<"enter size of bag"<<endl;
  int w;
  cin>>w;

int p=0,i=0;
//greddy algorithm
for(i=0;i<n;i++)
{

if(w>0&&object[i].weight<=w)
{
   w=w-object[i].weight;
   p+=object[i].price;
}
else
break;
}

if(w>0)
{
  p+=object[i].price*(w/(float)object[i].weight);
}
cout<<"total profit ="<<p<<endl;


  return 0;
}
