#include<stdio.h>

int say_hello(){
	printf("hhello void void\n");
	return 8;
}

void say_bye(){
	printf("ggoodbye\n");
}

struct Actions {
	int (*actionA)(void);
	void (*actionB)(void);
};

int main(){
//	void (*func[2])() = {say_hello, say_bye};
	struct Actions var_of_struct;
	var_of_struct.actionA = say_hello;
	var_of_struct.actionB = say_bye;

	var_of_struct.actionA();

//	func[0]();
//	say_hello();

//	func[1]();
//	say_bye();
}
