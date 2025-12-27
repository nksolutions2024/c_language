#include<stdio.h>

void say_hello(){
	printf("hhello\n");
}

void say_bye(){
	printf("ggoodbye\n");
}

int main(){
	void (*func)();
	func = say_hello;

	func();


//	say_hello();

//	say_bye();
}
