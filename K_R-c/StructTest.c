#include <stdio.h>
#include <inttypes.h>
/*
** typedef unsigned char int8_t;
** typedef unsigned int int16_t;
** typedef unsigned long int32_t;
** typedef unsigned long long int64_t;
*/
#include <string.h>
struct st_task
{
	uint16_t id;
	uint32_t value;
	uint64_t timestamp;
};

int main()
{
	struct st_task task = {};
	uint64_t a = 0x00010001;

	memcpy(&task, &a, sizeof(uint64_t));

	printf("%11u, %11u, %llu\n", task.id, task.value, task.timestamp);

	return 0;
}
