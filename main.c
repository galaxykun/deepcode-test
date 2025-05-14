#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void greet(const char *name)
{
	char buf[8];
	strcpy(buf, name); // 潛在緩衝區溢位
	printf("Hello, %s!\n", buf);
}

void memory_leak_example()
{
	int *ptr = malloc(sizeof(int) * 10);
	// 忘記釋放記憶體
	ptr[0] = 123;
}

void buffer_overflow_example()
{
	char buf[5];
	strcpy(buf, "This is too long!");  // 字串超過緩衝區大小
}

void uninitialized_variable_example()
{
	int x;
	printf("%d\n", x); // x 未初始化
}

void null_pointer_example()
{
	int *ptr = NULL;
	*ptr = 10; // 解引用空指標
}

void unchecked_return_example()
{
	FILE *fp = fopen("nofile.txt", "r");
	// 沒有檢查 fp 是否為 NULL
	fread(NULL, 1, 10, fp);
	fclose(fp);
}

int add(int a, int b)
{
	return a + b;
}

int main()
{
	printf("1+2=%d\n", add(1, 2));
	memory_leak_example();
	buffer_overflow_example();
	uninitialized_variable_example();
	null_pointer_example();
	unchecked_return_example();
	greet("PerplexityUser123456"); // 傳入超過 8 字元的字串
	return 0;
}