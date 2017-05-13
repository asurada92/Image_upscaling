int x3largrange(unsigned char *pImg, unsigned char *poImg, int rowsize, int colsize)
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

	
	//row-wise interpolation
	for (j = 0; j < colsize * 3; j++) {
		for (i = 4; i < rowsize * 3 - 7; i = i + 3) {
			*(poImg + (j*rowsize * 3) + i) = -0.0625*(*(poImg + (j*rowsize * 3) + i - 4)) + 0.7421875*(*(poImg + (j*rowsize * 3) + i -1)) + 0.37109375*(*(poImg + (j*rowsize * 3) + i +2)) - 0.048828125*(*(poImg + (j*rowsize * 3) + i + 5));
		}
	}

	for (j = 0; j < colsize * 3; j++) {
		for (i = 5; i < rowsize * 3 - 6; i = i + 3) {
			*(poImg + (j*rowsize * 3) + i) = -0.0625*(*(poImg + (j*rowsize * 3) + i - 5)) + 0.7421875*(*(poImg + (j*rowsize * 3) + i - 2)) + 0.37109375*(*(poImg + (j*rowsize * 3) + i + 1)) - 0.048828125*(*(poImg + (j*rowsize * 3) + i + 4));
		}
	}


	//column-wise interpolation
	for (j = 0; j < rowsize * 3; j++) {
		for (i = 4; i < colsize * 3 - 7; i = i = i + 3) {
			*(poImg + (i*rowsize * 3) + j) = -0.0625*(*(poImg + j + (i - 4)*rowsize * 3)) + 0.7421875*(*(poImg + j + (i - 1)*rowsize * 3)) + 0.37109375*(*(poImg + j + (i + 2)*rowsize * 3)) -0.048828125*(*(poImg + j + (i + 5)*rowsize * 3));
		}
	}

	for (j = 0; j < rowsize * 3; j++) {
		for (i = 5; i < colsize * 3 - 6; i = i = i + 3) {
			*(poImg + (i*rowsize * 3) + j) = -0.0625*(*(poImg + j + (i - 5)*rowsize * 3)) + 0.7421875*(*(poImg + j + (i - 2)*rowsize * 3)) + 0.37109375*(*(poImg + j + (i + 1)*rowsize * 3)) - 0.048828125*(*(poImg + j + (i + 4)*rowsize * 3));
		}
	}
	

	return 0;

}

