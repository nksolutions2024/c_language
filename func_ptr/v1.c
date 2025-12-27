#include<stdio.h>

int say_hello(){
	printf("hhello ; trying structure{....}\n");
	return 8;
}

void say_bye(){
	printf("ggoodbye\n");
}

struct Actions {
	int (*actionA)(void);
	void (*actionB)();
};

int main(){
	struct Actions var_of_struct;
	var_of_struct.actionA = say_hello;
	var_of_struct.actionB = say_bye;

	var_of_struct.actionA();

	say_hello();
	say_bye();
}
