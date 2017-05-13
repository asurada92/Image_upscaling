#include<stdlib.h>

void gaussian_filter(unsigned char *pImg, int rowsize, int colsize)
{
	char Mask_Sharp[3][3] = {
		1,2,1,
		2,4,2,
		1,2,1
	};


	unsigned char *ptImg = (unsigned char*)malloc(sizeof(unsigned char) * rowsize * colsize);//temp
	if ((memset(ptImg, 0, sizeof(unsigned char)*rowsize*colsize)) == NULL)
		printf("memory setting error!!\n");

	int i = 0;
	int j = 0;

	int m = 0;
	int r = 0;

	int sum = 0;
	int a = 0;

	for (i = 0; i < colsize - 1; i++) {
		for (j = 0; j < rowsize - 1; j++) {
			sum = 0;
			for (m = 0; m < 3; m++) {
				for (r = 0; r < 3; r++) {
					sum = sum + (*(pImg + (i*rowsize) + j + r + (m*rowsize)))*(Mask_Sharp[m][r]);
					if (sum < 0)
						a = 1;
					else if (sum == 0)
						a = 1;
				}
			}
			//sum = abs(sum);
			sum = sum / 16;
			if (sum > 255)
				sum = 255;
			else if (sum < 0)
				sum = 0;
			*(ptImg + ((i + 1)*rowsize) + j + 1) = sum;
		}
	}

	for (i = 1; i < colsize - 1; i++) {
		for (j = 1; j < rowsize - 1; j++) {

			*(pImg + (i*rowsize) + j) = *(ptImg + (i*rowsize) + j);
		}
	}

	free(ptImg);

	return 0;

}