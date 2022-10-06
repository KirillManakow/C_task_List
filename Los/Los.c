#include <malloc.h>
#include <stdio.h>

struct list
{
	int a;
	struct list* next;
};


typedef struct list* LOS;


LOS create(int n)
{
	LOS los = calloc(1, sizeof(LOS));
	LOS p1 = los, p2;
	p1->a = 1;
	for (size_t i = 0; i < n-1; i++)
	{
		p2 = calloc(1, sizeof(LOS));
		p1->next = p2;
		p2->a = p1->a + 1;
		p1 = p2;
	}
	p1->next = NULL;
	return los;	
}

void Print_Los(LOS los)
{
	while (los)
	{
		printf("%d ", los->a);
		los = los->next;
	}
	printf("\n");
}



void Delete_Los(LOS los, unsigned  n)
{
	LOS i;
	while (los)
	{
		i = los->next;
		los = i;
	}
}


void Delete_element(LOS los, unsigned k)
{
	for (size_t i = 0; i < k-2; i++)
	{
		los = los->next;
	}
	LOS p1 = los;
	los->next = los->next->next;
	/*free(p1);*/
}

void Swap_element(LOS los, unsigned k, const int index1, const int index2)
{
	// найти элемент #1
	los	* element1 = Head;
	for (int i = 0; i < k; i++)
		element1 = element1->Next;

	// найти элемент #2
	element* element2 = Head;
	for (int i = 0; i < k; i++)
		element2 = element2->Next;

	// поменять местами значения найденных элементов
	const int tmp element2->x;
	element1->x = element2->x;
	element2->x = tmp;
}

void Insert_Into_LOS(LOS los,LOS item, int k)
{
	
	for (size_t i = 1; i < k-1; i++)
	{
		los = los->next;
	}
	item->next = los->next;
	los->next = item;
}

int main()
{
	LOS los = create(10);
	Print_Los(los);

	Delete_element(los,5);
	Print_Los(los);
	free(los);

	LOS item = calloc(1, sizeof(LOS));
	item->a = 20;
	item->next = 0;
	Insert_Into_LOS(los, item, 3);
	Print_Los(los);

	//Delete_Los(los, 2);
	//Print_Los(los);
	return 0;
}
