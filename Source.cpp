#include "precompiled.h"
#include "Array.h"
#include "data.h"
#include "read_binary.h"

int main() {		

	FILE *fp = fopen("int.int", "wb");
	fseek(fp, 0, SEEK_END);
	int p = ftell(fp);


	return 0;
};













