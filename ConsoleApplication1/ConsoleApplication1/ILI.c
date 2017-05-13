void x2ILI(unsigned char *pImg, unsigned char *poImg, int rowsize, int colsize)
{
	int i = 0;

	int pause;


	i = 0;
	int j = 0;

	for (j = 0; j < colsize; j++) {
		for (i = 0; i < rowsize; i++) {
			//if ((i * 2 + (j * 2 * rowsize)) > 1024 * 511)
			//pause = 25;
			*(poImg + i * 2 + (j * 2 * rowsize) * 2) = *(pImg + i + j*rowsize);
		}
	}//2x img scaling


	 //row-wise interpolation
	for (j = 0; j < colsize * 2; j++) {
		for (i = 3; i < rowsize * 2 - 4; i = i + 2) {
			*(poImg + (j*rowsize * 2) + i) = (*(poImg + (j*rowsize * 2) + i - 1) + *(poImg + (j*rowsize * 2) + i + 1) +0.25*(((*(poImg + (j*rowsize * 2) + i - 1)- *(poImg + (j*rowsize * 2) + i - 3))/2)     -      ((*(poImg + (j*rowsize * 2) + i + 3)-*(poImg + (j*rowsize * 2) + i + 1))/2)))/2;
		}
	}



	//column-wise interpolation
	for (j = 0; j < rowsize * 2; j++) {
		for (i = 3; i < colsize * 2 - 4; i = i = i + 2) {
			*(poImg + (i*rowsize * 2) + j) = (*(poImg + j + (i - 1)*rowsize * 2) + *(poImg + j + (i + 1)*rowsize * 2) + 0.25*(((*(poImg + j + (i - 1)*rowsize * 2) - *(poImg + j + (i - 3)*rowsize * 2)) / 2) - ((*(poImg + j + (i + 3)*rowsize * 2) - *(poImg + j + (i + 1)*rowsize * 2)) / 2)))/2;
		}
	}

	return;

}


void x3ILI(unsigned char *pImg, unsigned char *poImg, int rowsize, int colsize)
{
	int i = 0;

	int pause;


	i = 0;
	int j = 0;

	for (j = 0; j < colsize; j++) {
		for (i = 0; i < rowsize; i++) {
			//if ((i * 2 + (j * 2 * rowsize)) > 1024 * 511)
			//pause = 25;
			*(poImg + i * 3 + (j * 3 * rowsize) * 3) = *(pImg + i + j*rowsize);
		}
	}//3x img scaling

//	 sharpening_filter(poImg,1536 , 1536);

	 //row-wise interpolation
	for (j = 0; j < colsize * 3; j++) {
		for (i = 4; i < rowsize * 3 - 7; i = i + 3) {
			*(poImg + (j*rowsize * 3) + i) = ((*(poImg + (j*rowsize * 3) + i - 1)) + (*(poImg + (j*rowsize * 3) + i + 2)) + ((((*(poImg + (j*rowsize * 3) + i - 1)) - (*(poImg + (j*rowsize * 3) + i - 4))) / 3) - (((*(poImg + (j*rowsize * 3) + i + 5)) - (*(poImg + (j*rowsize * 3) + i - 1))) / 3)) / 3 - (((*(poImg + (j*rowsize * 3) + i + 2)) - (*(poImg + (j*rowsize * 3) + i - 1))) / 3)) / 2;
		}
	}

	for (j = 0; j < colsize * 3; j++) {
		for (i = 5; i < rowsize * 3 - 6; i = i + 3) {
			*(poImg + (j*rowsize * 3) + i) = ((*(poImg + (j*rowsize * 3) + i - 2)) + (*(poImg + (j*rowsize * 3) + i + 1)) + ((((*(poImg + (j*rowsize * 3) + i - 2)) - (*(poImg + (j*rowsize * 3) + i - 5))) / 3) - (((*(poImg + (j*rowsize * 3) + i + 4)) - (*(poImg + (j*rowsize * 3) + i - 2))) / 3)) / 3 + (((*(poImg + (j*rowsize * 3) + i + 1)) - (*(poImg + (j*rowsize * 3) + i - 2))) / 3)) / 2;
		}
	}


	//column-wise interpolation
	for (j = 0; j < rowsize * 3; j++) {
		for (i = 4; i < colsize * 3 - 7; i = i = i + 3) {
			*(poImg + (i*rowsize * 3) + j) = ((*(poImg + j + (i - 1)*rowsize * 3)) + (*(poImg + j + (i + 2)*rowsize * 3)) + ((((*(poImg + j + (i - 1)*rowsize * 3)) - (*(poImg + j + (i - 4 )*rowsize * 3)))/3)-(((*(poImg + j + (i + 5)*rowsize * 3)) - (*(poImg + j + (i - 1)*rowsize * 3)))/3))/3 - (((*(poImg + j + (i + 2)*rowsize * 3)) - (*(poImg + j + (i - 1)*rowsize * 3)))/3))/2;
		}
	}

	for (j = 0; j < rowsize * 3; j++) {
		for (i = 5; i < colsize * 3 - 6; i = i = i + 3) {
			*(poImg + (i*rowsize * 3) + j) = ((*(poImg + j + (i - 2)*rowsize * 3)) + (*(poImg + j + (i + 1)*rowsize * 3)) + ((((*(poImg + j + (i - 2)*rowsize * 3)) - (*(poImg + j + (i - 5)*rowsize * 3))) / 3) - (((*(poImg + j + (i + 4)*rowsize * 3)) - (*(poImg + j + (i - 2)*rowsize * 3))) / 3)) / 3 - (((*(poImg + j + (i + 1)*rowsize * 3)) - (*(poImg + j + (i - 2)*rowsize * 3))) / 3)) / 2;
		}
	}


	return;

}

