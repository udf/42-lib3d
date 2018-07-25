#include <stdio.h>
#include "lib3d.h"

void print_mat(t_mat m, char *label)
{
	printf("%s:\n", label);
	printf("%.2f %.2f %.2f %.2f\n", m[0][0], m[0][1], m[0][2], m[0][3]);
	printf("%.2f %.2f %.2f %.2f\n", m[1][0], m[1][1], m[1][2], m[1][3]);
	printf("%.2f %.2f %.2f %.2f\n", m[2][0], m[2][1], m[2][2], m[2][3]);
	printf("%.2f %.2f %.2f %.2f\n", m[3][0], m[3][1], m[3][2], m[3][3]);
}

int main()
{
	t_mat m;
	mat_set_identity(m);

	print_mat(m, "from func");

	return 0;
}
