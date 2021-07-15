#include "prj.h"

void	min_instructions(int *t, int nb)
{
	t[UPA] = t[FROMUPA];
	t[UPB] = t[FROMUPB];
	t[NBA] = t[NBRINSA];
	t[NBB] = nb;
	t[NBAB] = t[NBRINSAB];
}

void	number_of_instructions(int *t, int v, int nb)
{
	if (t[NBRINSA] > (t[LENA] / 2))
	{
		t[FROMUPA] = 0;
		t[NBRINSA] = t[LENA] - t[NBRINSA];
	}
	if (nb > (t[LENB] / 2))
	{	
		t[FROMUPB] = 0;
		nb = t[LENB] - nb;
	}
	t[NBRINSA] += v;
	if (t[FROMUPB] == t[FROMUPA])
	{
	 	if(t[NBRINSA] > nb)
	 		t[NBRINSAB] = t[NBRINSA];
	 	else
	 		t[NBRINSAB] = nb;
	 }
	else
		t[NBRINSAB] = t[NBRINSA] + nb;
	if (t[NBAB] > t[NBRINSAB])
		min_instructions(t, nb);
}