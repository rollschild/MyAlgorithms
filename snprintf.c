#include <stdio.h>

int main(int argc, char** argv) {
	char buf[20];
	int pos, x = 0;
	snprintf(buf, sizeof(buf), "%.100d%n", x, &pos);
	printf("position: %d\n", pos);
	puts(buf);
	return 0;
}
