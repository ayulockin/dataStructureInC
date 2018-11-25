#include<stdio.h>

struct point{
	int x, y;
}p1 ; //structure defined; memory not yet allocated; 
      //variable declaration with structure declaration

int main(){
	// variable decralation like basic type
	//struct point p1 = {1,2}; //structure declared as vairable; memory allocated
	p1.x = 20; // accessing values of structure, here assigning value 
	p1.y = 44;
	printf("%d\n%d", p1.x, p1.y);
	
	printf("\nuse as pointer\n");
	
	struct point *p3; // here p3 is just some pointer of type struct
	p3 = &p1; // p3 is pointing to address of p1
	printf("%d\n%d", p3->x, p3->y); //-> is used to access the data of p1
	
}



