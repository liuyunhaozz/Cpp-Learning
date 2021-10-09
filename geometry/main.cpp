#include <iostream>
#define PI 3.14;
using namespace std;
class shape
{public:
    virtual double area(){return 0;}
};


class Point{
	private:
		double a;
		double b;
    public:
    	Point(const double a,const double b){
    		this->a=a;
    		this->b=b;
		}
		double getX(){
			return a;
		}
	    double getY(){
		return b;
		}
		
}; 

class circle:public shape
{public:
    circle(double rad, double r_x, double r_y):r(rad), x(r_x), y(r_y) {};
    virtual double area(){return 3.14*r*r;};
private:
    double r;
    double x,y;
};
//class circle:public point
//{public:
    //circle1(double x,double y,double r)
//private:
    //double x,y,r;
//};
class rectangle:public shape
{public:
   rectangle(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4):x1(x1),y1(y1), x2(x2),y2(y2),
   x3(x3), y3(y3), x4(x4), y4(y4){
       if(x1 >= x2 || x4 >= x3 || x1 != x4 || x2 != x3 || y4 >= y1 || y3 >= y2 || y1 != y2 || y3 != y4)
            cout << "Error" << endl;


   };
   virtual double area(){return (x2 - x1) * (y1 - y4);};
private:
    double x1,x2,x3,x4,y1,y2,y3,y4;
};
class triangle:public shape
{public:
    triangle(double x1,double y1, double x2, double y2, double x3, double y3):x1(x1),y1(y1),x2(x2),y2(y2), x3(x3), y3(y3){
        


    };
    virtual double area(){
        return (x3 - x2) * (y1 - y2) / 2; 

    };
private:
    double x1,x2,x3,y1,y2,y3;
};

int main()
{

    Point A(1.2, 2.5);
    circle sql(1.5, A.getX(), A.getY());
    // blablabla



    circle c(4.5);
    rectangle r(4.66,6.75);
    triangle t(6.9,8.34);
    shape *pt;
    pt=&c;
    cout<<"S of circle is"<<" "<<pt->area()<<endl;
    pt=&r;
    cout<<"S of rectangle is"<<" "<<pt->area()<<endl;
    pt=&t;
    cout<<"S of triangle is"<<" "<<pt->area()<<endl;
    double S=0;
    shape *p[3]={&c,&r,&t};
    for(int i=0;i<3;i++)
    {
        S=S+p[i]->area();
    }
    cout<<"the total of areas is"<<" "<<S<<endl;
    return 0;
}
