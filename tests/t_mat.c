#include <stdio.h>
#include "lib3d.h"

void print_mat(t_mat m, char *label)
{
	printf("%s:\n", label);
	printf("%.5f %.5f %.5f %.5f\n", m[0][0], m[0][1], m[0][2], m[0][3]);
	printf("%.5f %.5f %.5f %.5f\n", m[1][0], m[1][1], m[1][2], m[1][3]);
	printf("%.5f %.5f %.5f %.5f\n", m[2][0], m[2][1], m[2][2], m[2][3]);
	printf("%.5f %.5f %.5f %.5f\n", m[3][0], m[3][1], m[3][2], m[3][3]);
}

int main()
{
	t_mat m;
	mat_look_at(m, (t_p3d){50, 50, 50}, (t_p3d){0, 0, 0});

	print_mat(m, "h");

	return 0;
}
