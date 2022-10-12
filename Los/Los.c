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
	LOS los = calloc(1, sizeof(los));
	LOS p1 = los, p2;
	p1->a = 1;
	los->next = NULL;
	for (size_t i = 0; i < n-1; i++)
	{
		p2 = calloc(1, sizeof(los));
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


LOS Delete_element(LOS los, unsigned k)
{
	for (size_t i = 0; i < k-2; i++)
	{
		los = los->next;
	}
	LOS p1 = los;
	los->next = los->next->next;

	//free(p1);
}

void Swap_element(LOS los,int a, int m)
{
	LOS min = los;
	LOS max = los;
	LOS _max = los;
	if (a != 0) {
		for (size_t n = 0; n < a - 2; n++)
		{
			min = min->next;
		}
		for (size_t n = 0; n < m - 2; n++)
		{
			_max = _max->next;
		}
		LOS l2 = _max->next;
		max = l2->next;
		LOS l1 = min->next;
		min->next = l2;
		_max->next = l1;
		l2->next = l1->next;
		l1->next = max;
		return los;
	}
	else {
		for (size_t n = 0; n < m - 2; n++)
		{
			_max = _max->next;
		}
		LOS l2 = _max->next;
		max = l2->next;
		LOS l1 = min->next;
		l2->next = l1;
		_max->next = min;
		min->next = max;
		return l2;
	}
}	
	

LOS Insert_Into_LOS(LOS los, LOS item, int k)
{
	LOS el = malloc(sizeof(LOS));
	el->a = item->next;
	if (k == 1)
	{
		el->next = los;
		los = el;
	}
	else
	{
		for (size_t i = 1; i < k-1; i++)
		{
			los = los->next;
			if (!(los->next))
			{
				printf("Превышен размер");
				break;
			}
		}
		void* temp = los->next;
		los->next = el;
		el->next = temp;
	}
	return los;
}

int main()
{
	system("chcp 1251 >null");
	LOS los = create(10);
	Print_Los(los);

	LOS item = malloc(1, sizeof(LOS));
	item->next= 18,NULL;
	los = Insert_Into_LOS(los, item, 1);
	Print_Los(los);

	Delete_element(los,5);
	Print_Los(los);
	//free(los);

	LOS item1 = malloc(1, sizeof(LOS));
	Swap_element(los, 1,2);
	Print_Los(los);

	//printf("Списка нет");
	//Print_Los(Delete_element(los, N ));
	return 0;
}
