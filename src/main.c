/* cmemalloc - simple memory allocator in C for linux
 * Copyright: Alexeev Bronislav (C) 2024 MIT LICENSE */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KB (1024)
#define MB (1024 * 1024)
#define GB (1024 * 1024 * 1024)
#define TB (1024 * 1024 * 1024 * 1024)
#define PB (1024 * 1024 * 1024 * 1024 * 1024)
#define EB (1024 * 1024 * 1024 * 1024 * 1024 * 1024)
#define ZB (1024 * 1024 * 1024 * 1024 * 1024 * 1024 * 1024)
#define YB (1024 * 1024 * 1024 * 1024 * 1024 * 1024 * 1024 * 1024)

typedef struct {
	unsigned char *data;
	size_t length;
	size_t offset;
} Distributor;


Distributor dalloc(size_t size) {
	unsigned char *memory = malloc(size);

	Distributor distr = {
		.data = memory,
		.length = size,
		.offset = 0
	};

	return distr;
}

void *dpush(Distributor *d, size_t size) {
	if (d->offset + size <= d->length) {
		void *push = &d->data[d->offset];
		d->offset += size;
		memset(push, 0, size);
		return push;
	}
	printf("\033[1;31mOut of memory\033[0\n");
	return NULL;
}

int main() {
	Distributor distr = dalloc(GB);

	while (1) {
		char *str = dpush(&distr, 8 * sizeof(char));

		memcpy(str, "Hello,  ", 7);
		str[7] = '\0';

		char *str2 = dpush(&distr, 7 * sizeof(char));

		memcpy(str2, "World!", 6);
		str2[6] = '\0';

		printf("%s%s", str, str2);
	}

	return 0;
}
