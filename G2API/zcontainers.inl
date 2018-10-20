#pragma once

// [Moos] damit die MemPools als allererstes initialisiert werden
#pragma warning ( disable:4073)
#pragma init_seg(lib)

inline int zArraySortDefaultCompare (const void* ele1,const void* ele2)
{
	if (*((unsigned int*)ele1)<(*(unsigned int*)ele2))	return -1;
	if (*((unsigned int*)ele1)>(*(unsigned int*)ele2))	return +1;
	else												return  0;
};


// Sortierfunktion; interface fast kompatibel zu qsort [Moos]

#define MAXSIZE 24
#define d(i) (((char *)data)+(i)*size)

inline void insertionsort(void *data, size_t num, size_t size, int (__cdecl *compare)(const void *, const void *),bool falltoqs){
    char swapplace[MAXSIZE];

   // qsort(data,num,size,compare);
    
    if (size>MAXSIZE)
	{
        qsort(data,num,size,compare);
        return;
    }
     
    int swaps=0;
    for (int i=1;i<(int)num;i++)
	{
        void *lower=d(i);
        for (int j=i-1;j>=0;j--)
		{
            void *upper=lower;
            lower=d(j);
            if ((*compare)(upper,lower) < 0)
			{ // ok. Ist im Moment BubbleSort. Was solls...
                swaps++;
                memcpy(&swapplace,upper,size);
                memcpy(upper,lower,size);
                memcpy(lower,&swapplace,size);
            }
            else
                j=0; // hier kann man die innere Schleife schon abbrechen.
        }
        if (falltoqs && swaps > 5*i+5)
		{
            qsort(data,num,size,compare);
            return;
        }
    }

}

