#include<stdio.h>

void say_hello(){
	printf("hhello1\n");
}

void say_bye(){
	printf("ggoodbye\n");
}

int main(){
	void (*func[2])() = {say_hello, say_bye};

	func[0]();
//	say_hello();

	func[1]();
//	say_bye();
}
