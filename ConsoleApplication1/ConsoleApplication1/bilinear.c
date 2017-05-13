//#include "./sharpening.c"
//void sharpening_filter_bilinear(unsigned char *pImg, int rowsize, int colsize);

#include<math.h>
void x2sharpening_linear(unsigned char *pImg, unsigned char *poImg, int rowsize, int colsize) {
	int i, j;

	unsigned char *ptImg;
	unsigned char *pt2Img;
	ptImg = (unsigned char*)malloc(sizeof(unsigned char) * rowsize * colsize);
	//pt2Img = (unsigned char*)malloc(sizeof(unsigned char) * rowsize * colsize);
	sharpening_filter_bilinear(pImg,ptImg, rowsize, colsize);
	//poImg = ptImg;
	/*
	for (i = 0; i < colsize; i++) {
	for (j = 0; j < rowsize; j++) {

	*(pt2Img + (i*rowsize) + j) = *(pImg + (i*rowsize) + j);
	}
	}*/
	
	//adaptive filtering
	for (i = 0; i < colsize-1; i++) {
		for (j = 0; j < rowsize-1; j++) {
			if (abs((*(ptImg + j + i*(rowsize)) - *(ptImg + j + (i+1)*rowsize))) > abs((*(ptImg + j+1 + i*(rowsize)) - *(ptImg + j + 1 + (i + 1)*rowsize))))
			{
				*(pImg + j + 1 + i*(rowsize)) = *(ptImg + j + 1 + i*(rowsize));
				*(pImg + j + 1 + (i + 1)*rowsize) = *(ptImg + j + 1 + (i + 1)*rowsize);
			}
			else if (abs((*(ptImg + j + i*(rowsize)) - *(ptImg + j + (i + 1)*rowsize))) < abs((*(ptImg + j + 1 + i*(rowsize)) - *(ptImg + j + 1 + (i + 1)*rowsize))))
			{
				*(pImg + j + i*(rowsize)) = *(ptImg + j + i*(rowsize));
				*(pImg + j + (i + 1)*rowsize) = *(ptImg + j + (i + 1)*rowsize);

			}
			else
				continue;

		}
	}
	//poImg = ptImg;
	free(ptImg);
	//*poImg = pImg;
	
	//bilienar interpolation
	for (j = 0; j < colsize; j++) {
		for (i = 0; i < rowsize; i++) {
			//if ((i * 2 + (j * 2 * rowsize)) > 1024 * 511)
			//pause = 25;
			*(poImg + i * 2 + (j * 2 * rowsize) * 2) = *(pImg + i + j*rowsize);
		}
	}//2x img scaling 
	
	
	//rowise interpolation
	for (i = 0; i < 2 * colsize - 2; i=i+2) {
		for (j = 1; j < 2 * rowsize - 2; j=j+2) {
			*(poImg + i*2*rowsize + j) = (*(poImg + i*2*rowsize + j - 1)+ *(poImg + i * 2 * rowsize + j + 1)) / 2;
			//*(poImg + i*2*rowsize + j-1) = (*(poImg + (i - 1)*2*rowsize + j - 1) + *(poImg + (i + 1)*2*rowsize + j - 1))/2;
			//*(poImg + (i+1)*2*rowsize + j) = (*(poImg + (i - 1)*2*rowsize + j - 1) + *(poImg + (i + 1)*2*rowsize + j - 1)) / 2;
			//*(poImg + (i-1)*2*rowsize + j) = (*(poImg + (i + 1)*2*rowsize + j - 1) + *(poImg + (i + 1)*2*rowsize + j + 1)) / 2;

		}
	}
	

	//colwise interpolation
	for (i = 1; i < 2 * colsize - 2; i = i + 2) {
		for (j = 0; j < 2 * rowsize - 2; j++) {
			*(poImg + i * 2 * rowsize + j) = (*(poImg + (i-1) * 2 * rowsize + j) + *(poImg + (i+1) * 2 * rowsize + j)) / 2;
			//*(poImg + i*2*rowsize + j-1) = (*(poImg + (i - 1)*2*rowsize + j - 1) + *(poImg + (i + 1)*2*rowsize + j - 1))/2;
			//*(poImg + (i+1)*2*rowsize + j) = (*(poImg + (i - 1)*2*rowsize + j - 1) + *(poImg + (i + 1)*2*rowsize + j - 1)) / 2;
			//*(poImg + (i-1)*2*rowsize + j) = (*(poImg + (i + 1)*2*rowsize + j - 1) + *(poImg + (i + 1)*2*rowsize + j + 1)) / 2;

		}
	}
	
	return;


}

void x3sharpening_linear(unsigned char *pImg, unsigned char *poImg, int rowsize, int colsize) {
	int i, j;

	unsigned char *ptImg;
	unsigned char *pt2Img;
	ptImg = (unsigned char*)malloc(sizeof(unsigned char) * rowsize * colsize);

	sharpening_filter_bilinear(pImg, ptImg, rowsize, colsize);

	//adaptive filtering
	for (i = 0; i < colsize - 1; i++) {
		for (j = 0; j < rowsize - 1; j++) {
			if (abs((*(ptImg + j + i*(rowsize)) - *(ptImg + j + (i + 1)*rowsize))) > abs((*(ptImg + j + 1 + i*(rowsize)) - *(ptImg + j + 1 + (i + 1)*rowsize))))
			{
				*(pImg + j + 1 + i*(rowsize)) = *(ptImg + j + 1 + i*(rowsize));
				*(pImg + j + 1 + (i + 1)*rowsize) = *(ptImg + j + 1 + (i + 1)*rowsize);
			}
			else if (abs((*(ptImg + j + i*(rowsize)) - *(ptImg + j + (i + 1)*rowsize))) < abs((*(ptImg + j + 1 + i*(rowsize)) - *(ptImg + j + 1 + (i + 1)*rowsize))))
			{
				*(pImg + j + i*(rowsize)) = *(ptImg + j + i*(rowsize));
				*(pImg + j + (i + 1)*rowsize) = *(ptImg + j + (i + 1)*rowsize);

			}
			else
				continue;

		}
	}

	free(ptImg);


	for (j = 0; j < colsize; j++) {
		for (i = 0; i < rowsize; i++) {
			//if ((i * 2 + (j * 2 * rowsize)) > 1024 * 511)
			//pause = 25;
			*(poImg + i * 3 + (j * 3 * rowsize) * 3) = *(pImg + i + j*rowsize);
		}
	}//3x img scaling

	 //rowise interpolation
	for (i = 0; i < 3 * colsize - 2; i = i + 3) {
		for (j = 1; j < 3 * rowsize - 4; j = j + 3) {
			*(poImg + i * 3 * rowsize + j) = *(poImg + i * 3 * rowsize + j - 1) + ((-1 * *(poImg + i * 3 * rowsize + j - 1) + *(poImg + i * 3 * rowsize + j + 2)) / 3);
		}
	}
	for (i = 0; i < 3 * colsize - 2; i = i + 3) {
		for (j = 2; j < 3 * rowsize - 3; j = j + 3) {
			*(poImg + i * 3 * rowsize + j) = *(poImg + i * 3 * rowsize + j - 2) + ((-1 * *(poImg + i * 3 * rowsize + j - 2) + *(poImg + i * 3 * rowsize + j + 1)) / 3) * 2;
		}
	}


	//colwise interpolation
	for (i = 1; i < 3 * colsize - 4; i = i + 3) {
		for (j = 0; j < 3 * rowsize - 2; j++) {
			*(poImg + i * 3 * rowsize + j) = *(poImg + (i - 1) * 3 * rowsize + j) + (-1 * *(poImg + (i - 1) * 3 * rowsize + j) + *(poImg + (i + 2) * 3 * rowsize + j)) / 3;
		}
	}

	for (i = 2; i < 3 * colsize - 3; i = i + 3) {
		for (j = 0; j < 3 * rowsize - 2; j++) {
			*(poImg + i * 3 * rowsize + j) = *(poImg + (i - 2) * 3 * rowsize + j) + (((-1 * *(poImg + (i - 2) * 3 * rowsize + j) + *(poImg + (i + 1) * 3 * rowsize + j)) / 3) * 2);


		}
	}
	return;


}


void x2bilinear(unsigned char *pImg, unsigned char *poImg, int rowsize, int colsize) {
	int i, j;


	//bilienar interpolation
	for (j = 0; j < colsize-1; j++) {
		for (i = 1; i < rowsize-2; i++) {
			//if ((i * 2 + (j * 2 * rowsize)) > 1024 * 511)
			//pause = 25;
			*(poImg + i * 2 + (j * 2 * rowsize) * 2) = *(pImg + i + j*rowsize);
		}
	}//2x img scaling 


	 //rowise interpolation
	for (i = 0; i < 2 * colsize - 1; i = i + 2) {
		for (j = 1; j < 2 * rowsize - 2; j = j + 2) {
			*(poImg + i * 2 * rowsize + j) = (*(poImg + i * 2 * rowsize + j - 1) + *(poImg + i * 2 * rowsize + j + 1)) / 2;


		}
	}


	//colwise interpolation
	for (i = 1; i < 2 * colsize-2; i = i + 2) {
		for (j = 0; j < 2 * rowsize - 2; j++) {
			*(poImg + i * 2 * rowsize + j) = (*(poImg + (i - 1) * 2 * rowsize + j) + *(poImg + (i + 1) * 2 * rowsize + j)) / 2;


		}
	}

	return;


}


void x3bilinear(unsigned char *pImg, unsigned char *poImg, int rowsize, int colsize) {
	int i, j;


	//bilienar interpolation
	for (j = 0; j < colsize; j++) {
		for (i = 0; i < rowsize; i++) {
			//if ((i * 2 + (j * 2 * rowsize)) > 1024 * 511)
			//pause = 25;
			*(poImg + i * 3 + (j * 3 * rowsize) * 3) = *(pImg + i + j*rowsize);
		}
	}//3x img scaling

	
	 //rowise interpolation
	for (i = 0; i < 3 * colsize - 2; i = i + 3) {
		for (j = 1; j < 3 * rowsize - 4; j = j + 3) {
			*(poImg + i * 3 * rowsize + j) = *(poImg + i * 3 * rowsize + j - 1) + ((-1**(poImg + i * 3 * rowsize + j - 1) + *(poImg + i * 3 * rowsize + j + 2)) / 3);
		}
	}
	for (i = 0; i < 3 * colsize-2; i = i + 3) {
		for (j = 2; j < 3 * rowsize - 3; j = j + 3) {
			*(poImg + i * 3 * rowsize + j) = *(poImg + i * 3 * rowsize + j - 2)+ ((-1**(poImg + i * 3 * rowsize + j - 2) + *(poImg + i * 3 * rowsize + j + 1)) / 3)*2;
		}
	}
	
	
	//colwise interpolation
	for (i = 1; i < 3 * colsize-4; i = i + 3) {
		for (j = 0; j < 3 * rowsize-2; j++) {
			*(poImg + i * 3 * rowsize + j) = *(poImg + (i - 1) * 3 * rowsize + j)+ (-1**(poImg + (i - 1) * 3 * rowsize + j) + *(poImg + (i + 2) * 3 * rowsize + j)) / 3;
		}
	}

	for (i = 2; i < 3 * colsize - 3; i = i + 3) {
		for (j = 0; j < 3 * rowsize - 2; j++) {
			*(poImg + i * 3 * rowsize + j) = *(poImg + (i - 2) * 3 * rowsize + j)+(((-1**(poImg + (i - 2) * 3 * rowsize + j) + *(poImg + (i + 1) * 3 * rowsize + j)) / 3)*2);


		}
	}
	//*(poImg+3*rowsize) = 255;
	
	return;


}