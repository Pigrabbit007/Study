#include <stdio.h>

union data{
	char byte[4];
};

int main()
{
	int i = 0, k, Case_num;
	union data input_num;

	k = 4;

	scanf("%d", &Case_num);

	while (i++ < Case_num)
	{
		unsigned int num_bf;
		unsigned int num_af;
		union data *bf = (union data *)&num_bf;
		union data *af = (union data *)&num_af;

		scanf("%u", &num_bf);

		af->byte[0] = bf->byte[3];
		af->byte[1] = bf->byte[2];
		af->byte[2] = bf->byte[1];
		af->byte[3] = bf->byte[0];

		printf("%u\n", num_af);
	}
	return 0;
}