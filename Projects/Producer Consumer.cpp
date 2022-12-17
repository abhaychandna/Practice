#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

int bfr_size = 4;
int mutex = 1, full = 0, empty = bfr_size, item_no = 0;

int wait(int s)
{
	return (--s);
}

int signal(int s)
{
	return(++s);
}

void producer()
{
	mutex = wait(mutex);
	full = signal(full);
	empty = wait(empty);
	item_no++;
	printf("\nProducer produces the item %d", item_no);
	mutex = signal(mutex);
}

void consumer()
{
	mutex = wait(mutex);
	full = wait(full);
	empty = signal(empty);
	printf("\nConsumer consumes item %d", item_no);
	item_no--;
	mutex = signal(mutex);
}

int main()
{
	int n;
	printf("\nEnter Buffer Size - ");
	scanf("%d", &n);
	bfr_size = n;
	empty = bfr_size;
	printf("\n1.Producer\n2.Consumer\n3.Exit");
	while (1)
	{
		printf("\nEnter your choice:");
		scanf("%d", &n);
		switch (n)
		{
		case 1:	if ((mutex == 1) && (empty != 0))
			producer();
			  else
			printf("Buffer is full!!\n");
			break;
		case 2:	if ((mutex == 1) && (full != 0))
			consumer();
			  else
			printf("Buffer is empty!!\n");
			break;
		case 3:
			exit(0);
			break;
		}
	}

	return 0;
}
