# include <stdio.h>

void set_pointer(char** q);

int main(void) {
	char* p;
	set_pointer(&p);
	printf("%s", p);

}

void set_pointer(char** q) {
	*q = "ALL that glister is not gold";
}