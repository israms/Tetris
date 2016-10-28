#include "color.h"

Color::Color(){
}

Color::Color(int red,int green,int blue){
	r=red;
	g=green;
	b=blue;
}

Color::~Color(){
}

istream &operator>>(istream &is,Color &C){
	int num;
	is>>num;
	C.r=num;
	is>>num;
	C.g=num;
	is>>num;
	C.b=num;

	return is;
}

/*ostream & operator << (ostream &os,Color &C){
	os<<C.GetR()<<endl;
	os<<C.GetG()<<endl;
	os<<C.GetB()<<endl;
	return os;
}*/