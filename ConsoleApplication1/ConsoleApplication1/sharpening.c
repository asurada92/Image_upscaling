#include<stdlib.h>

void sharpening_filter(unsigned char *pImg, int rowsize, int colsize)
{
	char Mask_Sharp[3][3] = {
		0,-1,0,
		-1,8,-1,
		0,-1,0
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
					else if (sum > 255)
						a = 1;
				}
			}
			//sum = abs(sum);
			sum = sum / 4;
			if ((sum % 4) > 2)
				sum = sum + 1;
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



void sharpening_filter_bilinear(unsigned char *pImg, unsigned char *poImg, int rowsize, int colsize)
{
	char Mask_Sharp[3][3] = {
		0,-1,0,
		-1,8,-1,
		0,-1,0
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
			sum = sum / 4;
			if (sum > 255)
				sum = 255;
			else if (sum < 0)
				sum = 0;
			*(ptImg + ((i + 1)*rowsize) + j + 1) = sum;
		}
	}

	for (i = 1; i < colsize - 1; i++) {
		for (j = 1; j < rowsize - 1; j++) {

			*(poImg + (i*rowsize) + j) = *(ptImg + (i*rowsize) + j);
		}
	}

	free(ptImg);

	return 0;

}



void sharpening_filter2(unsigned char *pImg,unsigned char *poImg, int rowsize, int colsize)
{
	unsigned char Mask_Sharp[3][3] = {
		0,-0.25,0,
		-0.25,2,-0.25,
		0,-0.25,0
	};


	unsigned char *ptImg = (unsigned char*)malloc(sizeof(unsigned char) * rowsize * colsize);//temp
	if ((memset(ptImg, 0, sizeof(unsigned char)*rowsize*colsize)) == NULL)
		printf("memory setting error!!\n");

	int i = 0;
	int j = 0;

	int m = 0;
	int r = 0;

	unsigned char sum = 0;

	for (i = 0; i < colsize - 1; i++) {
		for (j = 0; j < rowsize - 1; j++) {
			sum = 0;
			for (m = 0; m < 3; m++) {
				for (r = 0; r < 3; r++) {
					sum = sum + (*(pImg + (i*rowsize) + j + r + (m*rowsize)))*(Mask_Sharp[m][r]);
				}
			}
			//sum = abs(sum);
			sum = sum / 2;
			if (sum > 255)
				sum = 255;
			*(ptImg + ((i + 1)*rowsize) + j + 1) = sum;
		}
	}

	
	for (i = 0; i < colsize; i++) {
	for (j = 0; j < rowsize; j++) {

	*(poImg + (i*rowsize) + j) = *(pImg + (i*rowsize) + j);
	}
	}

	for (i = 1; i < colsize - 1; i++) {
		for (j = 1; j < rowsize - 1; j++) {

			*(poImg + (i*rowsize) + j) = *(ptImg + (i*rowsize) + j);
		}
	}

	free(ptImg);

	return 0;

}








void sharpening_filter3(unsigned char *pImg, int rowsize, int colsize)
{
	char Mask_Sharp[3][3] = {
		0,-0.25,0,
		-0.25,2,-0.25,
		0,-0.25,0
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


	for (i = 1; i < colsize - 1; i++) {
		for (j = 1; j < rowsize - 1; j++) {
			sum = 0;
			//for (m = 0; m < 3; m++) {
				//for (r = 0; r < 3; r++) {
					sum = 2 * *(pImg + (i)*(rowsize)+j) - 0.25*(
						 *(pImg + (i - 1)*(rowsize)+j)
						+ *(pImg + (i)*(rowsize)+j - 1) + *(pImg + (i)*(rowsize)+j+1)
						+ *(pImg + (i + 1)*(rowsize)+j));
					if (2 * *(pImg + (i)*(rowsize)+j) < 0.25*(*(pImg + (i - 1)*(rowsize)+j) + *(pImg + (i)*(rowsize)+j - 1) + *(pImg + (i)*(rowsize)+j + 1) + *(pImg + (i + 1)*(rowsize)+j)))
						sum = 0;
					else if ((2 * *(pImg + (i)*(rowsize)+j) - 0.25*(
						*(pImg + (i - 1)*(rowsize)+j)
						+ *(pImg + (i)*(rowsize)+j - 1) + *(pImg + (i)*(rowsize)+j + 1)
						+ *(pImg + (i + 1)*(rowsize)+j)))>255)
						sum = 255;

					//sum = sum + (*(pImg + (i*rowsize) + j + r + (m*rowsize)))*(Mask_Sharp[m][r]);
				//}
			//}
			//sum = abs(sum);
			//sum = sum / 4;
			if (sum > 255)
				sum = 255;
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





void sharpening_filter4(unsigned char *pImg, int rowsize, int colsize)
{
	char Mask_Sharp_UP[2][3] = {
		-1,8,-1,
		0,-1,0
	};
	char Mask_Sharp_DOWN[2][3] = {
		0,-1,0,
		-1,8,-1
	};
	char Mask_Sharp[3][3] = {
		0,-1,0,
		-1,8,-1,
		0,-1,0
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
	//Bottom sharpening
	i = 0;
		for (j = 0; j < rowsize - 1; j++) {
			sum = 0;
			for (m = 0; m < 2; m++) {
				for (r = 0; r < 3; r++) {
					sum = sum + (*(pImg + (i*rowsize) + j + r + (m*rowsize)))*(Mask_Sharp_DOWN[m][r]);
					if (sum < 0)
						a = 1;
					else if (sum == 0)
						a = 1;
				}
			}
			//sum = abs(sum);
			sum = sum / 4;
			if (sum > 255)
				sum = 255;
			else if (sum < 0)
				sum = 0;
			*(ptImg + ((i + 1)*rowsize) + j + 1) = sum;
		}
	

	//Top sharpening
	i = colsize - 1;
		for (j = 0; j < rowsize - 1; j++) {
			sum = 0;
			for (m = 0; m < 2; m++) {
				for (r = 0; r < 3; r++) {
					sum = sum + (*(pImg + (i*rowsize) + j + r + (m*rowsize)))*(Mask_Sharp_UP[m][r]);
					if (sum < 0)
						a = 1;
					else if (sum == 0)
						a = 1;
				}
			}
			//sum = abs(sum);
			sum = sum / 4;
			if (sum > 255)
				sum = 255;
			else if (sum < 0)
				sum = 0;
			*(ptImg + ((i + 1)*rowsize) + j + 1) = sum;
		}
	



	//middle sharpening
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
			sum = sum / 4;
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