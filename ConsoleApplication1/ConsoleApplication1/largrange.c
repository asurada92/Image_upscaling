int x2largrange(unsigned char *pImg, unsigned char *poImg, int rowsize, int colsize)
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

	int a = 1;
	 //row-wise interpolation
	for (j = 0; j < colsize * 2; j++) {
		for (i = 3; i < rowsize * 2 - 4; i = i + 2) {
			*(poImg + (j*rowsize * 2) + i) = 0.5625*(*(poImg + (j*rowsize * 2) + i - 1) + *(poImg + (j*rowsize * 2) + i + 1)) - 0.0625*(*(poImg + (j*rowsize * 2) + i - 3) + *(poImg + (j*rowsize * 2) + i + 3));
			if (0.5625*(*(poImg + (j*rowsize * 2) + i - 1) + *(poImg + (j*rowsize * 2) + i + 1)) - 0.0625*(*(poImg + (j*rowsize * 2) + i - 3) + *(poImg + (j*rowsize * 2) + i + 3)) > 255)
				*(poImg + (j*rowsize * 2) + i) = 255;
			else if (0.5625*(*(poImg + (j*rowsize * 2) + i - 1) + *(poImg + (j*rowsize * 2) + i + 1)) - 0.0625*(*(poImg + (j*rowsize * 2) + i - 3) + *(poImg + (j*rowsize * 2) + i + 3)) < 0)
				*(poImg + (j*rowsize * 2) + i) = 0;
			/*else if (*(poImg + (j*rowsize * 2) + i) < 10)
				a = 1;*/
			//else if()
		}
	}


	//column-wise interpolation
	for (j = 0; j < rowsize * 2; j++) {
		for (i = 3; i < colsize * 2 - 4; i = i = i + 2) {
			*(poImg + (i*rowsize * 2) + j) = 0.5625*(*(poImg + j + (i - 1)*rowsize * 2) + *(poImg + j + (i + 1)*rowsize * 2)) - 0.0625*(*(poImg + j + (i - 3)*rowsize * 2) + *(poImg + j + (i + 3)*rowsize * 2));
			if (0.5625*(*(poImg + j + (i - 1)*rowsize * 2) + *(poImg + j + (i + 1)*rowsize * 2)) - 0.0625*(*(poImg + j + (i - 3)*rowsize * 2) + *(poImg + j + (i + 3)*rowsize * 2)) > 255)
				*(poImg + (i*rowsize * 2) + j) = 255;
			else if (0.5625*(*(poImg + j + (i - 1)*rowsize * 2) + *(poImg + j + (i + 1)*rowsize * 2)) - 0.0625*(*(poImg + j + (i - 3)*rowsize * 2) + *(poImg + j + (i + 3)*rowsize * 2)) < 0)
				*(poImg + (i*rowsize * 2) + j) = 0;
		}
	}
	

	return 0;

}



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

	int a = 0;
	 //row-wise interpolation
	for (j = 0; j < colsize * 3; j++) {
		for (i = 4; i < rowsize * 3 - 7; i = i + 3) {
			*(poImg + (j*rowsize * 3) + i) = -0.0625*(*(poImg + (j*rowsize * 3) + i - 4)) + 0.7421875*(*(poImg + (j*rowsize * 3) + i - 1)) + 0.37109375*(*(poImg + (j*rowsize * 3) + i + 2)) - 0.048828125*(*(poImg + (j*rowsize * 3) + i + 5));
			if ((-0.0625*(*(poImg + (j*rowsize * 3) + i - 4)) + 0.7421875*(*(poImg + (j*rowsize * 3) + i - 1)) + 0.37109375*(*(poImg + (j*rowsize * 3) + i + 2)) - 0.048828125*(*(poImg + (j*rowsize * 3) + i + 5))) > 255)
				*(poImg + (j*rowsize * 3) + i) = 255;
			else if ((-0.0625*(*(poImg + (j*rowsize * 3) + i - 4)) + 0.7421875*(*(poImg + (j*rowsize * 3) + i - 1)) + 0.37109375*(*(poImg + (j*rowsize * 3) + i + 2)) - 0.048828125*(*(poImg + (j*rowsize * 3) + i + 5))) < 0)
				*(poImg + (j*rowsize * 3) + i) = 0;
			if ((i==14)&&(*(poImg + (j*rowsize * 3) + i) == 0))
				a = 1;
		}
	}


	for (j = 0; j < colsize * 3; j++) {
		for (i = 5; i < rowsize * 3 - 6; i = i + 3) {
			if ((i == 14) && (j == 30))
				a = 1;
			*(poImg + (j*rowsize * 3) + i) = -0.0625*(*(poImg + (j*rowsize * 3) + i - 5)) + 0.7421875*(*(poImg + (j*rowsize * 3) + i - 2)) + 0.37109375*(*(poImg + (j*rowsize * 3) + i + 1)) - 0.048828125*(*(poImg + (j*rowsize * 3) + i + 4));
			if ((-0.0625*(*(poImg + (j*rowsize * 3) + i - 5)) + 0.7421875*(*(poImg + (j*rowsize * 3) + i - 2)) + 0.37109375*(*(poImg + (j*rowsize * 3) + i + 1)) - 0.048828125*(*(poImg + (j*rowsize * 3) + i + 4))) > 255)
				*(poImg + (j*rowsize * 3) + i) = 255;
			else if ((-0.0625*(*(poImg + (j*rowsize * 3) + i - 5)) + 0.7421875*(*(poImg + (j*rowsize * 3) + i - 2)) + 0.37109375*(*(poImg + (j*rowsize * 3) + i + 1)) - 0.048828125*(*(poImg + (j*rowsize * 3) + i + 4))) > 255)
				*(poImg + (j*rowsize * 3) + i) = 0;
			if ((*(poImg + (j*rowsize * 3) + i) == 0))
				a = 1;

		}
	}

	
	//column-wise interpolation
	for (j = 0; j < rowsize * 3; j++) {
		for (i = 4; i < colsize * 3 - 7; i = i = i + 3) {
			*(poImg + (i*rowsize * 3) + j) = -0.0625*(*(poImg + j + (i - 4)*rowsize * 3)) + 0.7421875*(*(poImg + j + (i - 1)*rowsize * 3)) + 0.37109375*(*(poImg + j + (i + 2)*rowsize * 3)) - 0.048828125*(*(poImg + j + (i + 5)*rowsize * 3));
			if ((-0.0625*(*(poImg + j + (i - 4)*rowsize * 3)) + 0.7421875*(*(poImg + j + (i - 1)*rowsize * 3)) + 0.37109375*(*(poImg + j + (i + 2)*rowsize * 3)) - 0.048828125*(*(poImg + j + (i + 5)*rowsize * 3))) > 255)
				*(poImg + (i*rowsize * 3) + j) = 255;
			else if ((-0.0625*(*(poImg + j + (i - 4)*rowsize * 3)) + 0.7421875*(*(poImg + j + (i - 1)*rowsize * 3)) + 0.37109375*(*(poImg + j + (i + 2)*rowsize * 3)) - 0.048828125*(*(poImg + j + (i + 5)*rowsize * 3))) < 0)
				*(poImg + (i*rowsize * 3) + j) = 0;

		}
	}

	for (j = 0; j < rowsize * 3; j++) {
		for (i = 5; i < colsize * 3 - 6; i = i = i + 3) {
			if ((i == 14) && (j == 30))
				a = 1;
			*(poImg + (i*rowsize * 3) + j) = -0.0625*(*(poImg + j + (i - 5)*rowsize * 3)) + 0.7421875*(*(poImg + j + (i - 2)*rowsize * 3)) + 0.37109375*(*(poImg + j + (i + 1)*rowsize * 3)) - 0.048828125*(*(poImg + j + (i + 4)*rowsize * 3));
			if ((-0.0625*(*(poImg + j + (i - 5)*rowsize * 3)) + 0.7421875*(*(poImg + j + (i - 2)*rowsize * 3)) + 0.37109375*(*(poImg + j + (i + 1)*rowsize * 3)) - 0.048828125*(*(poImg + j + (i + 4)*rowsize * 3))) > 255)
				*(poImg + (i*rowsize * 3
				) + j) = 255;
			else if ((-0.0625*(*(poImg + j + (i - 5)*rowsize * 3)) + 0.7421875*(*(poImg + j + (i - 2)*rowsize * 3)) + 0.37109375*(*(poImg + j + (i + 1)*rowsize * 3)) - 0.048828125*(*(poImg + j + (i + 4)*rowsize * 3))) < 0)
				*(poImg + (i*rowsize * 3) + j) = 0;

		}
	}
	

	return 0;

}


int x2largrange_for_6p(unsigned char *pImg, unsigned char *poImg, int rowsize, int colsize)
{
	int i = 0;



	i = 0;
	int j = 0;

	for (j = 0; j < colsize; j++) {
		for (i = 0; i < rowsize; i++) {
			//if ((i * 2 + (j * 2 * rowsize)) > 1024 * 511)
			//pause = 25;
			*(poImg + i * 2 + (j * 2 * rowsize) * 2) = *(pImg + i + j*rowsize);
		}
	}//2x img scaling

	int a = 1;
	/*
	//row-wise interpolation
	for (j = 0; j < colsize * 2; j=j+2) {
		for (i = 5; i < rowsize * 2 - 6; i = i + 2) {
			*(poImg + (j*rowsize * 2) + i) = 0.01171875**(poImg + (j*rowsize * 2) + i - 5) + (L1u/L1d)**(poImg + (j*rowsize * 2) + i - 3) + (L2u / L2d)**(poImg + (j*rowsize * 2) + i - 1) + (L3u / L3d)**(poImg + (j*rowsize * 2) + i + 1)+ (L4u / L4d)**(poImg + (j*rowsize * 2) + i + 3)+ (L5u / L5d)**(poImg + (j*rowsize * 2) + i + 5);



			if ((0.01171875**(poImg + (j*rowsize * 2) + i - 5) + (-1 * 0.09765625)**(poImg + (j*rowsize * 2) + i - 3) + (0.1953125)**(poImg + (j*rowsize * 2) + i - 1) + (0.1953125)**(poImg + (j*rowsize * 2) + i + 1) + (-1 * 0.09765625)**(poImg + (j*rowsize * 2) + i + 3) + 0.01171875**(poImg + (j*rowsize * 2) + i + 5)) > 255)
				*(poImg + (j*rowsize * 2) + i) = 255;
			else if ((0.01171875**(poImg + (j*rowsize * 2) + i - 5) + (-1 * 0.09765625)**(poImg + (j*rowsize * 2) + i - 3) + (0.1953125)**(poImg + (j*rowsize * 2) + i - 1) + (0.1953125)**(poImg + (j*rowsize * 2) + i + 1) + (-1 * 0.09765625)**(poImg + (j*rowsize * 2) + i + 3) + 0.01171875**(poImg + (j*rowsize * 2) + i + 5)) < 0)
				*(poImg + (j*rowsize * 2) + i) = 0;
		
			//else if()
		}
	}*/
	
	//row-wise interpolation
	for (j = 0; j < colsize * 2; j = j + 2) {
		for (i = 5; i < rowsize * 2 - 6; i = i + 2) {
			*(poImg + (j*rowsize * 2) + i) = 0.01171875**(poImg + (j*rowsize * 2) + i - 5) + (-1 * 0.09765625)**(poImg + (j*rowsize * 2) + i - 3) + (0.1953125)**(poImg + (j*rowsize * 2) + i - 1) + (0.1953125)**(poImg + (j*rowsize * 2) + i + 1) + (-1 * 0.09765625)**(poImg + (j*rowsize * 2) + i + 3) + 0.01171875**(poImg + (j*rowsize * 2) + i + 5);
	
			if ((0.01171875**(poImg + (j*rowsize * 2) + i - 5) + (-1 * 0.09765625)**(poImg + (j*rowsize * 2) + i - 3) + (0.1953125)**(poImg + (j*rowsize * 2) + i - 1) + (0.1953125)**(poImg + (j*rowsize * 2) + i + 1) + (-1 * 0.09765625)**(poImg + (j*rowsize * 2) + i + 3) + 0.01171875**(poImg + (j*rowsize * 2) + i + 5)) > 255)
				*(poImg + (j*rowsize * 2) + i) = 255;
			else if ((0.01171875**(poImg + (j*rowsize * 2) + i - 5) + (-1 * 0.09765625)**(poImg + (j*rowsize * 2) + i - 3) + (0.1953125)**(poImg + (j*rowsize * 2) + i - 1) + (0.1953125)**(poImg + (j*rowsize * 2) + i + 1) + (-1 * 0.09765625)**(poImg + (j*rowsize * 2) + i + 3) + 0.01171875**(poImg + (j*rowsize * 2) + i + 5)) < 0)
				*(poImg + (j*rowsize * 2) + i) = 0;

			//else if()
		}
	}
	
	
	//column-wise interpolation
	for (j = 0; j < rowsize * 2; j++) {
		for (i = 5; i < colsize * 2 - 6; i = i = i + 2) {
			*(poImg + (i*rowsize * 2) + j) = 0.01171875**(poImg + j + (i - 5)*rowsize * 2)+ (-1 * 0.09765625)**(poImg + j + (i - 3)*rowsize * 2)+ (0.1953125)**(poImg + j + (i - 1)*rowsize * 2)+ (0.1953125)**(poImg + j + (i + 1)*rowsize * 2)+ (-1 * 0.09765625)**(poImg + j + (i +  3)*rowsize * 2)+ 0.01171875**(poImg + j + (i + 5)*rowsize * 2);


			if ((0.01171875**(poImg + j + (i - 5)*rowsize * 2) + (-1 * 0.09765625)**(poImg + j + (i - 3)*rowsize * 2) + (0.1953125)**(poImg + j + (i - 1)*rowsize * 2) + (0.1953125)**(poImg + j + (i + 1)*rowsize * 2) + (-1 * 0.09765625)**(poImg + j + (i + 3)*rowsize * 2) + 0.01171875**(poImg + j + (i + 5)*rowsize * 2)) > 255)
				*(poImg + (i*rowsize * 2) + j) = 255;
			else if ((0.01171875**(poImg + j + (i - 5)*rowsize * 2) + (-1 * 0.09765625)**(poImg + j + (i - 3)*rowsize * 2) + (0.1953125)**(poImg + j + (i - 1)*rowsize * 2) + (0.1953125)**(poImg + j + (i + 1)*rowsize * 2) + (-1 * 0.09765625)**(poImg + j + (i + 3)*rowsize * 2) + 0.01171875**(poImg + j + (i + 5)*rowsize * 2)) < 0)
				*(poImg + (i*rowsize * 2) + j) = 0;
		}
	}
	
	
	return 0;

}



int x2largrange_for_ad_6p_4p_2p(unsigned char *pImg, unsigned char *poImg, int rowsize, int colsize)
{
	int i = 0;

	int pause;

	int x, x0, x1, x2, x3, x4, x5;

	x = 6;
	x0 = 1;
	x1 = 3;
	x2 = 5;
	x3 = 7;
	x4 = 9;
	x5 = 11;

	int L1u;
	int L1d;
	int L2u;
	int L2d;
	int L3u;
	int L3d;
	int L4u;
	int L4d;
	int L5u;
	int L5d;

	L1u = (x - x0)*(x - x2)*(x - x3)*(x - x4)*(x - x5);
	L1d = (x1 - x0)*(x1 - x2)*(x1 - x3)*(x1 - x4)*(x1 - x5);

	L2u = (x - x0)*(x - x1)*(x - x3)*(x - x4)*(x - x5);
	L2d = (x2 - x0)*(x2 - x1)*(x2 - x3)*(x2 - x4)*(x2 - x5);

	L3u = (x - x0)*(x - x1)*(x - x2)*(x - x4)*(x - x5);
	L3d = (x3 - x0)*(x3 - x1)*(x3 - x2)*(x3 - x4)*(x3 - x5);

	L4u = (x - x0)*(x - x1)*(x - x2)*(x - x3)*(x - x5);
	L4d = (x4 - x0)*(x4 - x1)*(x4 - x2)*(x4 - x3)*(x4 - x5);

	L5u = (x - x0)*(x - x1)*(x - x2)*(x - x3)*(x - x4);
	L5d = (x5 - x0)*(x5 - x1)*(x5 - x2)*(x5 - x3)*(x5 - x4);


	i = 0;
	int j = 0;

	for (j = 0; j < colsize; j++) {
		for (i = 0; i < rowsize; i++) {
			//if ((i * 2 + (j * 2 * rowsize)) > 1024 * 511)
			//pause = 25;
			*(poImg + i * 2 + (j * 2 * rowsize) * 2) = *(pImg + i + j*rowsize);
		}
	}//2x img scaling

	int a = 1;
	int b = 0;
	int c = 0;
	int k = 0;

	//row-wise interpolation
	for (j = 0; j < colsize * 2; j = j + 2) {
		for (i = 5; i < rowsize * 2 - 6; i = i + 2) {
			k = k + 1;
			*(poImg + (j*rowsize * 2) + i) = 0.01171875**(poImg + (j*rowsize * 2) + i - 5) + (-1 * 0.09765625)**(poImg + (j*rowsize * 2) + i - 3) + (0.1953125)**(poImg + (j*rowsize * 2) + i - 1) + (0.1953125)**(poImg + (j*rowsize * 2) + i + 1) + (-1 * 0.09765625)**(poImg + (j*rowsize * 2) + i + 3) + 0.01171875**(poImg + (j*rowsize * 2) + i + 5);
			if ((0.01171875**(poImg + (j*rowsize * 2) + i - 5) + (-1 * 0.09765625)**(poImg + (j*rowsize * 2) + i - 3) + (0.1953125)**(poImg + (j*rowsize * 2) + i - 1) + (0.1953125)**(poImg + (j*rowsize * 2) + i + 1) + (-1 * 0.09765625)**(poImg + (j*rowsize * 2) + i + 3) + 0.01171875**(poImg + (j*rowsize * 2) + i + 5) < *(poImg + (j*rowsize * 2) + i - 1) && 0.01171875**(poImg + (j*rowsize * 2) + i - 5) + (-1 * 0.09765625)**(poImg + (j*rowsize * 2) + i - 3) + (0.1953125)**(poImg + (j*rowsize * 2) + i - 1) + (0.1953125)**(poImg + (j*rowsize * 2) + i + 1) + (-1 * 0.09765625)**(poImg + (j*rowsize * 2) + i + 3) + 0.01171875**(poImg + (j*rowsize * 2) + i + 5) < *(poImg + (j*rowsize * 2) + i + 1)) || (0.01171875**(poImg + (j*rowsize * 2) + i - 5) + (-1 * 0.09765625)**(poImg + (j*rowsize * 2) + i - 3) + (0.1953125)**(poImg + (j*rowsize * 2) + i - 1) + (0.1953125)**(poImg + (j*rowsize * 2) + i + 1) + (-1 * 0.09765625)**(poImg + (j*rowsize * 2) + i + 3) + 0.01171875**(poImg + (j*rowsize * 2) + i + 5) > *(poImg + (j*rowsize * 2) + i - 1) && 0.01171875**(poImg + (j*rowsize * 2) + i - 5) + (-1 * 0.09765625)**(poImg + (j*rowsize * 2) + i - 3) + (0.1953125)**(poImg + (j*rowsize * 2) + i - 1) + (0.1953125)**(poImg + (j*rowsize * 2) + i + 1) + (-1 * 0.09765625)**(poImg + (j*rowsize * 2) + i + 3) + 0.01171875**(poImg + (j*rowsize * 2) + i + 5) > *(poImg + (j*rowsize * 2) + i + 1)))
			{	
				b = b + 1;
				*(poImg + (j*rowsize * 2) + i) = 0.5625*(*(poImg + (j*rowsize * 2) + i - 1) + *(poImg + (j*rowsize * 2) + i + 1)) - 0.0625*(*(poImg + (j*rowsize * 2) + i - 3) + *(poImg + (j*rowsize * 2) + i + 3));
				if ((0.5625*(*(poImg + (j*rowsize * 2) + i - 1) + *(poImg + (j*rowsize * 2) + i + 1)) - 0.0625*(*(poImg + (j*rowsize * 2) + i - 3) + *(poImg + (j*rowsize * 2) + i + 3)) < *(poImg + (j*rowsize * 2) + i - 1)) && (0.5625*(*(poImg + (j*rowsize * 2) + i - 1) + *(poImg + (j*rowsize * 2) + i + 1)) - 0.0625*(*(poImg + (j*rowsize * 2) + i - 3) + *(poImg + (j*rowsize * 2) + i + 3)) < *(poImg + (j*rowsize * 2) + i + 1)) || (0.5625*(*(poImg + (j*rowsize * 2) + i - 1) + *(poImg + (j*rowsize * 2) + i + 1)) - 0.0625*(*(poImg + (j*rowsize * 2) + i - 3) + *(poImg + (j*rowsize * 2) + i + 3)) > *(poImg + (j*rowsize * 2) + i - 1) && 0.5625*(*(poImg + (j*rowsize * 2) + i - 1) + *(poImg + (j*rowsize * 2) + i + 1)) - 0.0625*(*(poImg + (j*rowsize * 2) + i - 3) + *(poImg + (j*rowsize * 2) + i + 3)) > *(poImg + (j*rowsize * 2) + i + 1)))
				{
					*(poImg + (j*rowsize * 2) + i) = (*(poImg + (j*rowsize * 2) + i - 1) + *(poImg + (j*rowsize * 2) + i + 1)) / 2;
					c = c + 1;
				}
			}


			//else if()
		}
	}
	printf("%d, %d, %d", b, c,k);

	
	//column-wise interpolation
	for (j = 0; j < rowsize * 2; j++) {
	for (i = 5; i < colsize * 2 - 6; i = i = i + 2) {
	*(poImg + (i*rowsize * 2) + j) = 0.01171875**(poImg + j + (i - 5)*rowsize * 2)+ (-1 * 0.09765625)**(poImg + j + (i - 3)*rowsize * 2)+ (0.1953125)**(poImg + j + (i - 1)*rowsize * 2)+ (0.1953125)**(poImg + j + (i + 1)*rowsize * 2)+ (-1 * 0.09765625)**(poImg + j + (i +  3)*rowsize * 2)+ 0.01171875**(poImg + j + (i + 5)*rowsize * 2);
	if ((((0.01171875**(poImg + j + (i - 5)*rowsize * 2) + (-1 * 0.09765625)**(poImg + j + (i - 3)*rowsize * 2) + (0.1953125)**(poImg + j + (i - 1)*rowsize * 2) + (0.1953125)**(poImg + j + (i + 1)*rowsize * 2) + (-1 * 0.09765625)**(poImg + j + (i + 3)*rowsize * 2) + 0.01171875**(poImg + j + (i + 5)*rowsize * 2)) < (*(poImg + j + (i - 1)*rowsize * 2))) && ((0.01171875**(poImg + j + (i - 5)*rowsize * 2) + (-1 * 0.09765625)**(poImg + j + (i - 3)*rowsize * 2) + (0.1953125)**(poImg + j + (i - 1)*rowsize * 2) + (0.1953125)**(poImg + j + (i + 1)*rowsize * 2) + (-1 * 0.09765625)**(poImg + j + (i + 3)*rowsize * 2) + 0.01171875**(poImg + j + (i + 5)*rowsize * 2)) < (*(poImg + j + (i + 1)*rowsize * 2)))) || (((0.01171875**(poImg + j + (i - 5)*rowsize * 2) + (-1 * 0.09765625)**(poImg + j + (i - 3)*rowsize * 2) + (0.1953125)**(poImg + j + (i - 1)*rowsize * 2) + (0.1953125)**(poImg + j + (i + 1)*rowsize * 2) + (-1 * 0.09765625)**(poImg + j + (i + 3)*rowsize * 2) + 0.01171875**(poImg + j + (i + 5)*rowsize * 2)) > (*(poImg + j + (i - 1)*rowsize * 2))) && ((0.01171875**(poImg + j + (i - 5)*rowsize * 2) + (-1 * 0.09765625)**(poImg + j + (i - 3)*rowsize * 2) + (0.1953125)**(poImg + j + (i - 1)*rowsize * 2) + (0.1953125)**(poImg + j + (i + 1)*rowsize * 2) + (-1 * 0.09765625)**(poImg + j + (i + 3)*rowsize * 2) + 0.01171875**(poImg + j + (i + 5)*rowsize * 2)) > (*(poImg + j + (i + 1)*rowsize * 2)))))
	{
		*(poImg + (i*rowsize * 2) + j) = 0.5625*(*(poImg + j + (i - 1)*rowsize * 2) + *(poImg + j + (i + 1)*rowsize * 2)) - 0.0625*(*(poImg + j + (i - 3)*rowsize * 2) + *(poImg + j + (i + 3)*rowsize * 2));
		if ((((0.5625*(*(poImg + j + (i - 1)*rowsize * 2) + *(poImg + j + (i + 1)*rowsize * 2)) - 0.0625*(*(poImg + j + (i - 3)*rowsize * 2) + *(poImg + j + (i + 3)*rowsize * 2))) < (*(poImg + j + (i - 1)*rowsize * 2))) && ((0.5625*(*(poImg + j + (i - 1)*rowsize * 2) + *(poImg + j + (i + 1)*rowsize * 2)) - 0.0625*(*(poImg + j + (i - 3)*rowsize * 2) + *(poImg + j + (i + 3)*rowsize * 2))) < (*(poImg + j + (i + 1)*rowsize * 2)))) || (((0.5625*(*(poImg + j + (i - 1)*rowsize * 2) + *(poImg + j + (i + 1)*rowsize * 2)) - 0.0625*(*(poImg + j + (i - 3)*rowsize * 2) + *(poImg + j + (i + 3)*rowsize * 2))) > (*(poImg + j + (i - 1)*rowsize * 2))) && ((0.5625*(*(poImg + j + (i - 1)*rowsize * 2) + *(poImg + j + (i + 1)*rowsize * 2)) - 0.0625*(*(poImg + j + (i - 3)*rowsize * 2) + *(poImg + j + (i + 3)*rowsize * 2))) > (*(poImg + j + (i + 1)*rowsize * 2)))))
		{
			*(poImg + (i*rowsize * 2) + j) = (*(poImg + j + (i - 1)*rowsize * 2) + *(poImg + j + (i + 1)*rowsize * 2)) / 2;
		}
	}

	}
	}

	
	return 0;

}


int x2largrange_for_ad_6p_2p(unsigned char *pImg, unsigned char *poImg, int rowsize, int colsize)
{
	int i = 0;

	int pause;

	int x, x0, x1, x2, x3, x4, x5;

	x = 6;
	x0 = 1;
	x1 = 3;
	x2 = 5;
	x3 = 7;
	x4 = 9;
	x5 = 11;

	int L1u;
	int L1d;
	int L2u;
	int L2d;
	int L3u;
	int L3d;
	int L4u;
	int L4d;
	int L5u;
	int L5d;

	L1u = (x - x0)*(x - x2)*(x - x3)*(x - x4)*(x - x5);
	L1d = (x1 - x0)*(x1 - x2)*(x1 - x3)*(x1 - x4)*(x1 - x5);

	L2u = (x - x0)*(x - x1)*(x - x3)*(x - x4)*(x - x5);
	L2d = (x2 - x0)*(x2 - x1)*(x2 - x3)*(x2 - x4)*(x2 - x5);

	L3u = (x - x0)*(x - x1)*(x - x2)*(x - x4)*(x - x5);
	L3d = (x3 - x0)*(x3 - x1)*(x3 - x2)*(x3 - x4)*(x3 - x5);

	L4u = (x - x0)*(x - x1)*(x - x2)*(x - x3)*(x - x5);
	L4d = (x4 - x0)*(x4 - x1)*(x4 - x2)*(x4 - x3)*(x4 - x5);

	L5u = (x - x0)*(x - x1)*(x - x2)*(x - x3)*(x - x4);
	L5d = (x5 - x0)*(x5 - x1)*(x5 - x2)*(x5 - x3)*(x5 - x4);


	i = 0;
	int j = 0;

	for (j = 0; j < colsize; j++) {
		for (i = 0; i < rowsize; i++) {
			//if ((i * 2 + (j * 2 * rowsize)) > 1024 * 511)
			//pause = 25;
			*(poImg + i * 2 + (j * 2 * rowsize) * 2) = *(pImg + i + j*rowsize);
		}
	}//2x img scaling

	int a = 1;
	int b = 0;
	int c = 0;
	int k = 0;

	//row-wise interpolation
	for (j = 0; j < colsize * 2; j = j + 2) {
		for (i = 5; i < rowsize * 2 - 6; i = i + 2) {
			k = k + 1;
			*(poImg + (j*rowsize * 2) + i) = 0.01171875**(poImg + (j*rowsize * 2) + i - 5) + (-1 * 0.09765625)**(poImg + (j*rowsize * 2) + i - 3) + (0.1953125)**(poImg + (j*rowsize * 2) + i - 1) + (0.1953125)**(poImg + (j*rowsize * 2) + i + 1) + (-1 * 0.09765625)**(poImg + (j*rowsize * 2) + i + 3) + 0.01171875**(poImg + (j*rowsize * 2) + i + 5);
			if ((0.01171875**(poImg + (j*rowsize * 2) + i - 5) + (-1 * 0.09765625)**(poImg + (j*rowsize * 2) + i - 3) + (0.1953125)**(poImg + (j*rowsize * 2) + i - 1) + (0.1953125)**(poImg + (j*rowsize * 2) + i + 1) + (-1 * 0.09765625)**(poImg + (j*rowsize * 2) + i + 3) + 0.01171875**(poImg + (j*rowsize * 2) + i + 5) < *(poImg + (j*rowsize * 2) + i - 1) && 0.01171875**(poImg + (j*rowsize * 2) + i - 5) + (-1 * 0.09765625)**(poImg + (j*rowsize * 2) + i - 3) + (0.1953125)**(poImg + (j*rowsize * 2) + i - 1) + (0.1953125)**(poImg + (j*rowsize * 2) + i + 1) + (-1 * 0.09765625)**(poImg + (j*rowsize * 2) + i + 3) + 0.01171875**(poImg + (j*rowsize * 2) + i + 5) < *(poImg + (j*rowsize * 2) + i + 1)) || (0.01171875**(poImg + (j*rowsize * 2) + i - 5) + (-1 * 0.09765625)**(poImg + (j*rowsize * 2) + i - 3) + (0.1953125)**(poImg + (j*rowsize * 2) + i - 1) + (0.1953125)**(poImg + (j*rowsize * 2) + i + 1) + (-1 * 0.09765625)**(poImg + (j*rowsize * 2) + i + 3) + 0.01171875**(poImg + (j*rowsize * 2) + i + 5) > *(poImg + (j*rowsize * 2) + i - 1) && 0.01171875**(poImg + (j*rowsize * 2) + i - 5) + (-1 * 0.09765625)**(poImg + (j*rowsize * 2) + i - 3) + (0.1953125)**(poImg + (j*rowsize * 2) + i - 1) + (0.1953125)**(poImg + (j*rowsize * 2) + i + 1) + (-1 * 0.09765625)**(poImg + (j*rowsize * 2) + i + 3) + 0.01171875**(poImg + (j*rowsize * 2) + i + 5) > *(poImg + (j*rowsize * 2) + i + 1)))
			{
				b = b + 1;
				
					*(poImg + (j*rowsize * 2) + i) = (*(poImg + (j*rowsize * 2) + i - 1) + *(poImg + (j*rowsize * 2) + i + 1)) / 2;
					c = c + 1;
				
			}


			//else if()
		}
	}
	printf("%d, %d, %d", b, c, k);


	//column-wise interpolation
	for (j = 0; j < rowsize * 2; j++) {
		for (i = 5; i < colsize * 2 - 6; i = i = i + 2) {
			*(poImg + (i*rowsize * 2) + j) = 0.01171875**(poImg + j + (i - 5)*rowsize * 2) + (-1 * 0.09765625)**(poImg + j + (i - 3)*rowsize * 2) + (0.1953125)**(poImg + j + (i - 1)*rowsize * 2) + (0.1953125)**(poImg + j + (i + 1)*rowsize * 2) + (-1 * 0.09765625)**(poImg + j + (i + 3)*rowsize * 2) + 0.01171875**(poImg + j + (i + 5)*rowsize * 2);
			if ((((0.01171875**(poImg + j + (i - 5)*rowsize * 2) + (-1 * 0.09765625)**(poImg + j + (i - 3)*rowsize * 2) + (0.1953125)**(poImg + j + (i - 1)*rowsize * 2) + (0.1953125)**(poImg + j + (i + 1)*rowsize * 2) + (-1 * 0.09765625)**(poImg + j + (i + 3)*rowsize * 2) + 0.01171875**(poImg + j + (i + 5)*rowsize * 2)) < (*(poImg + j + (i - 1)*rowsize * 2))) && ((0.01171875**(poImg + j + (i - 5)*rowsize * 2) + (-1 * 0.09765625)**(poImg + j + (i - 3)*rowsize * 2) + (0.1953125)**(poImg + j + (i - 1)*rowsize * 2) + (0.1953125)**(poImg + j + (i + 1)*rowsize * 2) + (-1 * 0.09765625)**(poImg + j + (i + 3)*rowsize * 2) + 0.01171875**(poImg + j + (i + 5)*rowsize * 2)) < (*(poImg + j + (i + 1)*rowsize * 2)))) || (((0.01171875**(poImg + j + (i - 5)*rowsize * 2) + (-1 * 0.09765625)**(poImg + j + (i - 3)*rowsize * 2) + (0.1953125)**(poImg + j + (i - 1)*rowsize * 2) + (0.1953125)**(poImg + j + (i + 1)*rowsize * 2) + (-1 * 0.09765625)**(poImg + j + (i + 3)*rowsize * 2) + 0.01171875**(poImg + j + (i + 5)*rowsize * 2)) > (*(poImg + j + (i - 1)*rowsize * 2))) && ((0.01171875**(poImg + j + (i - 5)*rowsize * 2) + (-1 * 0.09765625)**(poImg + j + (i - 3)*rowsize * 2) + (0.1953125)**(poImg + j + (i - 1)*rowsize * 2) + (0.1953125)**(poImg + j + (i + 1)*rowsize * 2) + (-1 * 0.09765625)**(poImg + j + (i + 3)*rowsize * 2) + 0.01171875**(poImg + j + (i + 5)*rowsize * 2)) > (*(poImg + j + (i + 1)*rowsize * 2)))))
			{
				
					*(poImg + (i*rowsize * 2) + j) = (*(poImg + j + (i - 1)*rowsize * 2) + *(poImg + j + (i + 1)*rowsize * 2)) / 2;
				
			}

		}
	}


	return 0;

}


int x2largrange_for_ad_4p_2p(unsigned char *pImg, unsigned char *poImg, int rowsize, int colsize)
{
	int i = 0;
	long time_s;
	long time_e;

	int pause;

	int x, x0, x1, x2, x3, x4, x5;

	x = 6;
	x0 = 1;
	x1 = 3;
	x2 = 5;
	x3 = 7;
	x4 = 9;
	x5 = 11;

	int L1u;
	int L1d;
	int L2u;
	int L2d;
	int L3u;
	int L3d;
	int L4u;
	int L4d;
	int L5u;
	int L5d;

	L1u = (x - x0)*(x - x2)*(x - x3)*(x - x4)*(x - x5);
	L1d = (x1 - x0)*(x1 - x2)*(x1 - x3)*(x1 - x4)*(x1 - x5);

	L2u = (x - x0)*(x - x1)*(x - x3)*(x - x4)*(x - x5);
	L2d = (x2 - x0)*(x2 - x1)*(x2 - x3)*(x2 - x4)*(x2 - x5);

	L3u = (x - x0)*(x - x1)*(x - x2)*(x - x4)*(x - x5);
	L3d = (x3 - x0)*(x3 - x1)*(x3 - x2)*(x3 - x4)*(x3 - x5);

	L4u = (x - x0)*(x - x1)*(x - x2)*(x - x3)*(x - x5);
	L4d = (x4 - x0)*(x4 - x1)*(x4 - x2)*(x4 - x3)*(x4 - x5);

	L5u = (x - x0)*(x - x1)*(x - x2)*(x - x3)*(x - x4);
	L5d = (x5 - x0)*(x5 - x1)*(x5 - x2)*(x5 - x3)*(x5 - x4);


	i = 0;
	int j = 0;
	time_s = clock();
	for (j = 0; j < colsize; j++) {
		for (i = 0; i < rowsize; i++) {
			//if ((i * 2 + (j * 2 * rowsize)) > 1024 * 511)
			//pause = 25;
			*(poImg + i * 2 + (j * 2 * rowsize) * 2) = *(pImg + i + j*rowsize);
		}
	}//2x img scaling
	time_e = clock();
	printf("\n2xscaling time : %d\n" ,time_e - time_s);

	int a = 1;
	int b = 0;
	int c = 0;
	int k = 0;

	//row-wise interpolation
	for (j = 0; j < colsize * 2; j = j + 2) {
		for (i = 5; i < rowsize * 2 - 4; i = i + 2) {
			k = k + 1;

				*(poImg + (j*rowsize * 2) + i) = 0.5625*(*(poImg + (j*rowsize * 2) + i - 1) + *(poImg + (j*rowsize * 2) + i + 1)) - 0.0625*(*(poImg + (j*rowsize * 2) + i - 3) + *(poImg + (j*rowsize * 2) + i + 3));
				if ((0.5625*(*(poImg + (j*rowsize * 2) + i - 1) + *(poImg + (j*rowsize * 2) + i + 1)) - 0.0625*(*(poImg + (j*rowsize * 2) + i - 3) + *(poImg + (j*rowsize * 2) + i + 3)) < *(poImg + (j*rowsize * 2) + i - 1)) && (0.5625*(*(poImg + (j*rowsize * 2) + i - 1) + *(poImg + (j*rowsize * 2) + i + 1)) - 0.0625*(*(poImg + (j*rowsize * 2) + i - 3) + *(poImg + (j*rowsize * 2) + i + 3)) < *(poImg + (j*rowsize * 2) + i + 1)) || (0.5625*(*(poImg + (j*rowsize * 2) + i - 1) + *(poImg + (j*rowsize * 2) + i + 1)) - 0.0625*(*(poImg + (j*rowsize * 2) + i - 3) + *(poImg + (j*rowsize * 2) + i + 3)) > *(poImg + (j*rowsize * 2) + i - 1) && 0.5625*(*(poImg + (j*rowsize * 2) + i - 1) + *(poImg + (j*rowsize * 2) + i + 1)) - 0.0625*(*(poImg + (j*rowsize * 2) + i - 3) + *(poImg + (j*rowsize * 2) + i + 3)) > *(poImg + (j*rowsize * 2) + i + 1)))
				{
					*(poImg + (j*rowsize * 2) + i) = (*(poImg + (j*rowsize * 2) + i - 1) + *(poImg + (j*rowsize * 2) + i + 1)) / 2;
					c = c + 1;
				}
			


			//else if()
		}
	}
	printf("%d, %d, %d", b, c, k);


	//column-wise interpolation
	for (j = 0; j < rowsize * 2; j++) {
		for (i = 5; i < colsize * 2 -4; i = i = i + 2) {
				*(poImg + (i*rowsize * 2) + j) = 0.5625*(*(poImg + j + (i - 1)*rowsize * 2) + *(poImg + j + (i + 1)*rowsize * 2)) - 0.0625*(*(poImg + j + (i - 3)*rowsize * 2) + *(poImg + j + (i + 3)*rowsize * 2));
				if ((((0.5625*(*(poImg + j + (i - 1)*rowsize * 2) + *(poImg + j + (i + 1)*rowsize * 2)) - 0.0625*(*(poImg + j + (i - 3)*rowsize * 2) + *(poImg + j + (i + 3)*rowsize * 2))) < (*(poImg + j + (i - 1)*rowsize * 2))) && ((0.5625*(*(poImg + j + (i - 1)*rowsize * 2) + *(poImg + j + (i + 1)*rowsize * 2)) - 0.0625*(*(poImg + j + (i - 3)*rowsize * 2) + *(poImg + j + (i + 3)*rowsize * 2))) < (*(poImg + j + (i + 1)*rowsize * 2)))) || (((0.5625*(*(poImg + j + (i - 1)*rowsize * 2) + *(poImg + j + (i + 1)*rowsize * 2)) - 0.0625*(*(poImg + j + (i - 3)*rowsize * 2) + *(poImg + j + (i + 3)*rowsize * 2))) > (*(poImg + j + (i - 1)*rowsize * 2))) && ((0.5625*(*(poImg + j + (i - 1)*rowsize * 2) + *(poImg + j + (i + 1)*rowsize * 2)) - 0.0625*(*(poImg + j + (i - 3)*rowsize * 2) + *(poImg + j + (i + 3)*rowsize * 2))) > (*(poImg + j + (i + 1)*rowsize * 2)))))
				{
					*(poImg + (i*rowsize * 2) + j) = (*(poImg + j + (i - 1)*rowsize * 2) + *(poImg + j + (i + 1)*rowsize * 2)) / 2;
				}
			

		}
	}


	return 0;

}

//////////for woman pic

int x2largrange_for_ad_6p_w(unsigned char *pImg, unsigned char *poImg, int rowsize, int colsize)
{
	int i = 0;

	int pause;

	int x, x0, x1, x2, x3, x4, x5;

	x = 6;
	x0 = 1;
	x1 = 3;
	x2 = 5;
	x3 = 7;
	x4 = 9;
	x5 = 11;

	int L1u;
	int L1d;
	int L2u;
	int L2d;
	int L3u;
	int L3d;
	int L4u;
	int L4d;
	int L5u;
	int L5d;

	L1u = (x - x0)*(x - x2)*(x - x3)*(x - x4)*(x - x5);
	L1d = (x1 - x0)*(x1 - x2)*(x1 - x3)*(x1 - x4)*(x1 - x5);

	L2u = (x - x0)*(x - x1)*(x - x3)*(x - x4)*(x - x5);
	L2d = (x2 - x0)*(x2 - x1)*(x2 - x3)*(x2 - x4)*(x2 - x5);

	L3u = (x - x0)*(x - x1)*(x - x2)*(x - x4)*(x - x5);
	L3d = (x3 - x0)*(x3 - x1)*(x3 - x2)*(x3 - x4)*(x3 - x5);

	L4u = (x - x0)*(x - x1)*(x - x2)*(x - x3)*(x - x5);
	L4d = (x4 - x0)*(x4 - x1)*(x4 - x2)*(x4 - x3)*(x4 - x5);

	L5u = (x - x0)*(x - x1)*(x - x2)*(x - x3)*(x - x4);
	L5d = (x5 - x0)*(x5 - x1)*(x5 - x2)*(x5 - x3)*(x5 - x4);


	i = 0;
	int j = 0;

	for (j = 0; j < colsize; j++) {
		for (i = 0; i < rowsize; i++) {
			//if ((i * 2 + (j * 2 * rowsize)) > 1024 * 511)
			//pause = 25;
			*(poImg + i * 2 + (j * 2 * rowsize) * 2) = *(pImg + i + j*rowsize);
		}
	}//2x img scaling

	int a = 1;
	/*
	//row-wise interpolation
	for (j = 0; j < colsize * 2; j = j + 2) {
		for (i = 5; i < rowsize * 2 - 6; i = i + 2) {
			*(poImg + (j*rowsize * 2) + i) = 0.01171875**(poImg + (j*rowsize * 2) + i - 5) + (L1u / L1d)**(poImg + (j*rowsize * 2) + i - 3) + (L2u / L2d)**(poImg + (j*rowsize * 2) + i - 1) + (L3u / L3d)**(poImg + (j*rowsize * 2) + i + 1) + (L4u / L4d)**(poImg + (j*rowsize * 2) + i + 3) + (L5u / L5d)**(poImg + (j*rowsize * 2) + i + 5);



			if ((0.01171875**(poImg + (j*rowsize * 2) + i - 5) + (-1 * 0.09765625)**(poImg + (j*rowsize * 2) + i - 3) + (0.1953125)**(poImg + (j*rowsize * 2) + i - 1) + (0.1953125)**(poImg + (j*rowsize * 2) + i + 1) + (-1 * 0.09765625)**(poImg + (j*rowsize * 2) + i + 3) + 0.01171875**(poImg + (j*rowsize * 2) + i + 5)) > 255)
				*(poImg + (j*rowsize * 2) + i) = 255;
			else if ((0.01171875**(poImg + (j*rowsize * 2) + i - 5) + (-1 * 0.09765625)**(poImg + (j*rowsize * 2) + i - 3) + (0.1953125)**(poImg + (j*rowsize * 2) + i - 1) + (0.1953125)**(poImg + (j*rowsize * 2) + i + 1) + (-1 * 0.09765625)**(poImg + (j*rowsize * 2) + i + 3) + 0.01171875**(poImg + (j*rowsize * 2) + i + 5)) < 0)
				*(poImg + (j*rowsize * 2) + i) = 0;

			//else if()
		}
	}*/

	//row-wise interpolation
	for (j = 0; j < colsize * 2; j = j + 2) {
		for (i = 5; i < rowsize * 2-6; i = i + 2) {
			*(poImg + (j*rowsize * 2) + i) = 0.01171875**(poImg + (j*rowsize * 2) + i - 5) + (-1 * 0.09765625)**(poImg + (j*rowsize * 2) + i - 3) + (0.1953125)**(poImg + (j*rowsize * 2) + i - 1) + (0.1953125)**(poImg + (j*rowsize * 2) + i + 1) + (-1 * 0.09765625)**(poImg + (j*rowsize * 2) + i + 3) + 0.01171875**(poImg + (j*rowsize * 2) + i + 5);

			if ((0.01171875**(poImg + (j*rowsize * 2) + i - 5) + (-1 * 0.09765625)**(poImg + (j*rowsize * 2) + i - 3) + (0.1953125)**(poImg + (j*rowsize * 2) + i - 1) + (0.1953125)**(poImg + (j*rowsize * 2) + i + 1) + (-1 * 0.09765625)**(poImg + (j*rowsize * 2) + i + 3) + 0.01171875**(poImg + (j*rowsize * 2) + i + 5)) > 255)
				*(poImg + (j*rowsize * 2) + i) = 255;
			else if ((0.01171875**(poImg + (j*rowsize * 2) + i - 5) + (-1 * 0.09765625)**(poImg + (j*rowsize * 2) + i - 3) + (0.1953125)**(poImg + (j*rowsize * 2) + i - 1) + (0.1953125)**(poImg + (j*rowsize * 2) + i + 1) + (-1 * 0.09765625)**(poImg + (j*rowsize * 2) + i + 3) + 0.01171875**(poImg + (j*rowsize * 2) + i + 5)) < 0)
				*(poImg + (j*rowsize * 2) + i) = 0;

			//else if()
		}
	}


	//column-wise interpolation
	for (j = 0; j < rowsize * 2; j++) {
		for (i = 5; i < colsize * 2-6; i = i = i + 2) {
			*(poImg + (i*rowsize * 2) + j) = 0.01171875**(poImg + j + (i - 5)*rowsize * 2) + (-1 * 0.09765625)**(poImg + j + (i - 3)*rowsize * 2) + (0.1953125)**(poImg + j + (i - 1)*rowsize * 2) + (0.1953125)**(poImg + j + (i + 1)*rowsize * 2) + (-1 * 0.09765625)**(poImg + j + (i + 3)*rowsize * 2) + 0.01171875**(poImg + j + (i + 5)*rowsize * 2);


			if ((0.01171875**(poImg + j + (i - 5)*rowsize * 2) + (-1 * 0.09765625)**(poImg + j + (i - 3)*rowsize * 2) + (0.1953125)**(poImg + j + (i - 1)*rowsize * 2) + (0.1953125)**(poImg + j + (i + 1)*rowsize * 2) + (-1 * 0.09765625)**(poImg + j + (i + 3)*rowsize * 2) + 0.01171875**(poImg + j + (i + 5)*rowsize * 2)) > 255)
				*(poImg + (i*rowsize * 2) + j) = 255;
			else if ((0.01171875**(poImg + j + (i - 5)*rowsize * 2) + (-1 * 0.09765625)**(poImg + j + (i - 3)*rowsize * 2) + (0.1953125)**(poImg + j + (i - 1)*rowsize * 2) + (0.1953125)**(poImg + j + (i + 1)*rowsize * 2) + (-1 * 0.09765625)**(poImg + j + (i + 3)*rowsize * 2) + 0.01171875**(poImg + j + (i + 5)*rowsize * 2)) < 0)
				*(poImg + (i*rowsize * 2) + j) = 0;
		}
	}


	return 0;

}



int x2largrange_for_ad_6p_4p_2p_w(unsigned char *pImg, unsigned char *poImg, int rowsize, int colsize)
{
	int i = 0;

	int pause;

	int x, x0, x1, x2, x3, x4, x5;

	x = 6;
	x0 = 1;
	x1 = 3;
	x2 = 5;
	x3 = 7;
	x4 = 9;
	x5 = 11;

	int L1u;
	int L1d;
	int L2u;
	int L2d;
	int L3u;
	int L3d;
	int L4u;
	int L4d;
	int L5u;
	int L5d;

	L1u = (x - x0)*(x - x2)*(x - x3)*(x - x4)*(x - x5);
	L1d = (x1 - x0)*(x1 - x2)*(x1 - x3)*(x1 - x4)*(x1 - x5);

	L2u = (x - x0)*(x - x1)*(x - x3)*(x - x4)*(x - x5);
	L2d = (x2 - x0)*(x2 - x1)*(x2 - x3)*(x2 - x4)*(x2 - x5);

	L3u = (x - x0)*(x - x1)*(x - x2)*(x - x4)*(x - x5);
	L3d = (x3 - x0)*(x3 - x1)*(x3 - x2)*(x3 - x4)*(x3 - x5);

	L4u = (x - x0)*(x - x1)*(x - x2)*(x - x3)*(x - x5);
	L4d = (x4 - x0)*(x4 - x1)*(x4 - x2)*(x4 - x3)*(x4 - x5);

	L5u = (x - x0)*(x - x1)*(x - x2)*(x - x3)*(x - x4);
	L5d = (x5 - x0)*(x5 - x1)*(x5 - x2)*(x5 - x3)*(x5 - x4);


	i = 0;
	int j = 0;

	for (j = 0; j < colsize; j++) {
		for (i = 0; i < rowsize; i++) {
			//if ((i * 2 + (j * 2 * rowsize)) > 1024 * 511)
			//pause = 25;
			*(poImg + i * 2 + (j * 2 * rowsize) * 2) = *(pImg + i + j*rowsize);
		}
	}//2x img scaling

	int a = 1;
	int b = 0;
	int c = 0;
	int k = 0;

	//row-wise interpolation
	for (j = 0; j < colsize * 2; j = j + 2) {
		for (i = 5; i < rowsize * 2-6; i = i + 2) {
			k = k + 1;
			*(poImg + (j*rowsize * 2) + i) = 0.01171875**(poImg + (j*rowsize * 2) + i - 5) + (-1 * 0.09765625)**(poImg + (j*rowsize * 2) + i - 3) + (0.1953125)**(poImg + (j*rowsize * 2) + i - 1) + (0.1953125)**(poImg + (j*rowsize * 2) + i + 1) + (-1 * 0.09765625)**(poImg + (j*rowsize * 2) + i + 3) + 0.01171875**(poImg + (j*rowsize * 2) + i + 5);
			if ((0.01171875**(poImg + (j*rowsize * 2) + i - 5) + (-1 * 0.09765625)**(poImg + (j*rowsize * 2) + i - 3) + (0.1953125)**(poImg + (j*rowsize * 2) + i - 1) + (0.1953125)**(poImg + (j*rowsize * 2) + i + 1) + (-1 * 0.09765625)**(poImg + (j*rowsize * 2) + i + 3) + 0.01171875**(poImg + (j*rowsize * 2) + i + 5) < *(poImg + (j*rowsize * 2) + i - 1) && 0.01171875**(poImg + (j*rowsize * 2) + i - 5) + (-1 * 0.09765625)**(poImg + (j*rowsize * 2) + i - 3) + (0.1953125)**(poImg + (j*rowsize * 2) + i - 1) + (0.1953125)**(poImg + (j*rowsize * 2) + i + 1) + (-1 * 0.09765625)**(poImg + (j*rowsize * 2) + i + 3) + 0.01171875**(poImg + (j*rowsize * 2) + i + 5) < *(poImg + (j*rowsize * 2) + i + 1)) || (0.01171875**(poImg + (j*rowsize * 2) + i - 5) + (-1 * 0.09765625)**(poImg + (j*rowsize * 2) + i - 3) + (0.1953125)**(poImg + (j*rowsize * 2) + i - 1) + (0.1953125)**(poImg + (j*rowsize * 2) + i + 1) + (-1 * 0.09765625)**(poImg + (j*rowsize * 2) + i + 3) + 0.01171875**(poImg + (j*rowsize * 2) + i + 5) > *(poImg + (j*rowsize * 2) + i - 1) && 0.01171875**(poImg + (j*rowsize * 2) + i - 5) + (-1 * 0.09765625)**(poImg + (j*rowsize * 2) + i - 3) + (0.1953125)**(poImg + (j*rowsize * 2) + i - 1) + (0.1953125)**(poImg + (j*rowsize * 2) + i + 1) + (-1 * 0.09765625)**(poImg + (j*rowsize * 2) + i + 3) + 0.01171875**(poImg + (j*rowsize * 2) + i + 5) > *(poImg + (j*rowsize * 2) + i + 1)))
			{
				b = b + 1;
				*(poImg + (j*rowsize * 2) + i) = 0.5625*(*(poImg + (j*rowsize * 2) + i - 1) + *(poImg + (j*rowsize * 2) + i + 1)) - 0.0625*(*(poImg + (j*rowsize * 2) + i - 3) + *(poImg + (j*rowsize * 2) + i + 3));
				if ((0.5625*(*(poImg + (j*rowsize * 2) + i - 1) + *(poImg + (j*rowsize * 2) + i + 1)) - 0.0625*(*(poImg + (j*rowsize * 2) + i - 3) + *(poImg + (j*rowsize * 2) + i + 3)) < *(poImg + (j*rowsize * 2) + i - 1)) && (0.5625*(*(poImg + (j*rowsize * 2) + i - 1) + *(poImg + (j*rowsize * 2) + i + 1)) - 0.0625*(*(poImg + (j*rowsize * 2) + i - 3) + *(poImg + (j*rowsize * 2) + i + 3)) < *(poImg + (j*rowsize * 2) + i + 1)) || (0.5625*(*(poImg + (j*rowsize * 2) + i - 1) + *(poImg + (j*rowsize * 2) + i + 1)) - 0.0625*(*(poImg + (j*rowsize * 2) + i - 3) + *(poImg + (j*rowsize * 2) + i + 3)) > *(poImg + (j*rowsize * 2) + i - 1) && 0.5625*(*(poImg + (j*rowsize * 2) + i - 1) + *(poImg + (j*rowsize * 2) + i + 1)) - 0.0625*(*(poImg + (j*rowsize * 2) + i - 3) + *(poImg + (j*rowsize * 2) + i + 3)) > *(poImg + (j*rowsize * 2) + i + 1)))
				{
					*(poImg + (j*rowsize * 2) + i) = (*(poImg + (j*rowsize * 2) + i - 1) + *(poImg + (j*rowsize * 2) + i + 1)) / 2;
					c = c + 1;
				}
			}


			//else if()
		}
	}
	printf("%d, %d, %d", b, c, k);


	//column-wise interpolation
	for (j = 0; j < rowsize * 2; j++) {
		for (i = 5; i < colsize * 2-6; i = i = i + 2) {
			*(poImg + (i*rowsize * 2) + j) = 0.01171875**(poImg + j + (i - 5)*rowsize * 2) + (-1 * 0.09765625)**(poImg + j + (i - 3)*rowsize * 2) + (0.1953125)**(poImg + j + (i - 1)*rowsize * 2) + (0.1953125)**(poImg + j + (i + 1)*rowsize * 2) + (-1 * 0.09765625)**(poImg + j + (i + 3)*rowsize * 2) + 0.01171875**(poImg + j + (i + 5)*rowsize * 2);
			if ((((0.01171875**(poImg + j + (i - 5)*rowsize * 2) + (-1 * 0.09765625)**(poImg + j + (i - 3)*rowsize * 2) + (0.1953125)**(poImg + j + (i - 1)*rowsize * 2) + (0.1953125)**(poImg + j + (i + 1)*rowsize * 2) + (-1 * 0.09765625)**(poImg + j + (i + 3)*rowsize * 2) + 0.01171875**(poImg + j + (i + 5)*rowsize * 2)) < (*(poImg + j + (i - 1)*rowsize * 2))) && ((0.01171875**(poImg + j + (i - 5)*rowsize * 2) + (-1 * 0.09765625)**(poImg + j + (i - 3)*rowsize * 2) + (0.1953125)**(poImg + j + (i - 1)*rowsize * 2) + (0.1953125)**(poImg + j + (i + 1)*rowsize * 2) + (-1 * 0.09765625)**(poImg + j + (i + 3)*rowsize * 2) + 0.01171875**(poImg + j + (i + 5)*rowsize * 2)) < (*(poImg + j + (i + 1)*rowsize * 2)))) || (((0.01171875**(poImg + j + (i - 5)*rowsize * 2) + (-1 * 0.09765625)**(poImg + j + (i - 3)*rowsize * 2) + (0.1953125)**(poImg + j + (i - 1)*rowsize * 2) + (0.1953125)**(poImg + j + (i + 1)*rowsize * 2) + (-1 * 0.09765625)**(poImg + j + (i + 3)*rowsize * 2) + 0.01171875**(poImg + j + (i + 5)*rowsize * 2)) > (*(poImg + j + (i - 1)*rowsize * 2))) && ((0.01171875**(poImg + j + (i - 5)*rowsize * 2) + (-1 * 0.09765625)**(poImg + j + (i - 3)*rowsize * 2) + (0.1953125)**(poImg + j + (i - 1)*rowsize * 2) + (0.1953125)**(poImg + j + (i + 1)*rowsize * 2) + (-1 * 0.09765625)**(poImg + j + (i + 3)*rowsize * 2) + 0.01171875**(poImg + j + (i + 5)*rowsize * 2)) > (*(poImg + j + (i + 1)*rowsize * 2)))))
			{
				*(poImg + (i*rowsize * 2) + j) = 0.5625*(*(poImg + j + (i - 1)*rowsize * 2) + *(poImg + j + (i + 1)*rowsize * 2)) - 0.0625*(*(poImg + j + (i - 3)*rowsize * 2) + *(poImg + j + (i + 3)*rowsize * 2));
				if ((((0.5625*(*(poImg + j + (i - 1)*rowsize * 2) + *(poImg + j + (i + 1)*rowsize * 2)) - 0.0625*(*(poImg + j + (i - 3)*rowsize * 2) + *(poImg + j + (i + 3)*rowsize * 2))) < (*(poImg + j + (i - 1)*rowsize * 2))) && ((0.5625*(*(poImg + j + (i - 1)*rowsize * 2) + *(poImg + j + (i + 1)*rowsize * 2)) - 0.0625*(*(poImg + j + (i - 3)*rowsize * 2) + *(poImg + j + (i + 3)*rowsize * 2))) < (*(poImg + j + (i + 1)*rowsize * 2)))) || (((0.5625*(*(poImg + j + (i - 1)*rowsize * 2) + *(poImg + j + (i + 1)*rowsize * 2)) - 0.0625*(*(poImg + j + (i - 3)*rowsize * 2) + *(poImg + j + (i + 3)*rowsize * 2))) > (*(poImg + j + (i - 1)*rowsize * 2))) && ((0.5625*(*(poImg + j + (i - 1)*rowsize * 2) + *(poImg + j + (i + 1)*rowsize * 2)) - 0.0625*(*(poImg + j + (i - 3)*rowsize * 2) + *(poImg + j + (i + 3)*rowsize * 2))) > (*(poImg + j + (i + 1)*rowsize * 2)))))
				{
					*(poImg + (i*rowsize * 2) + j) = (*(poImg + j + (i - 1)*rowsize * 2) + *(poImg + j + (i + 1)*rowsize * 2)) / 2;
				}
			}

		}
	}


	return 0;

}


int x2largrange_for_ad_6p_2p_w(unsigned char *pImg, unsigned char *poImg, int rowsize, int colsize)
{
	int i = 0;

	int pause;

	int x, x0, x1, x2, x3, x4, x5;

	x = 6;
	x0 = 1;
	x1 = 3;
	x2 = 5;
	x3 = 7;
	x4 = 9;
	x5 = 11;

	int L1u;
	int L1d;
	int L2u;
	int L2d;
	int L3u;
	int L3d;
	int L4u;
	int L4d;
	int L5u;
	int L5d;

	L1u = (x - x0)*(x - x2)*(x - x3)*(x - x4)*(x - x5);
	L1d = (x1 - x0)*(x1 - x2)*(x1 - x3)*(x1 - x4)*(x1 - x5);

	L2u = (x - x0)*(x - x1)*(x - x3)*(x - x4)*(x - x5);
	L2d = (x2 - x0)*(x2 - x1)*(x2 - x3)*(x2 - x4)*(x2 - x5);

	L3u = (x - x0)*(x - x1)*(x - x2)*(x - x4)*(x - x5);
	L3d = (x3 - x0)*(x3 - x1)*(x3 - x2)*(x3 - x4)*(x3 - x5);

	L4u = (x - x0)*(x - x1)*(x - x2)*(x - x3)*(x - x5);
	L4d = (x4 - x0)*(x4 - x1)*(x4 - x2)*(x4 - x3)*(x4 - x5);

	L5u = (x - x0)*(x - x1)*(x - x2)*(x - x3)*(x - x4);
	L5d = (x5 - x0)*(x5 - x1)*(x5 - x2)*(x5 - x3)*(x5 - x4);


	i = 0;
	int j = 0;

	for (j = 0; j < colsize; j++) {
		for (i = 0; i < rowsize; i++) {
			//if ((i * 2 + (j * 2 * rowsize)) > 1024 * 511)
			//pause = 25;
			*(poImg + i * 2 + (j * 2 * rowsize) * 2) = *(pImg + i + j*rowsize);
		}
	}//2x img scaling

	int a = 1;
	int b = 0;
	int c = 0;
	int k = 0;

	//row-wise interpolation
	for (j = 0; j < colsize * 2; j = j + 2) {
		for (i = 5; i < rowsize * 2-6; i = i + 2) {
			k = k + 1;
			*(poImg + (j*rowsize * 2) + i) = 0.01171875**(poImg + (j*rowsize * 2) + i - 5) + (-1 * 0.09765625)**(poImg + (j*rowsize * 2) + i - 3) + (0.1953125)**(poImg + (j*rowsize * 2) + i - 1) + (0.1953125)**(poImg + (j*rowsize * 2) + i + 1) + (-1 * 0.09765625)**(poImg + (j*rowsize * 2) + i + 3) + 0.01171875**(poImg + (j*rowsize * 2) + i + 5);
			if ((0.01171875**(poImg + (j*rowsize * 2) + i - 5) + (-1 * 0.09765625)**(poImg + (j*rowsize * 2) + i - 3) + (0.1953125)**(poImg + (j*rowsize * 2) + i - 1) + (0.1953125)**(poImg + (j*rowsize * 2) + i + 1) + (-1 * 0.09765625)**(poImg + (j*rowsize * 2) + i + 3) + 0.01171875**(poImg + (j*rowsize * 2) + i + 5) < *(poImg + (j*rowsize * 2) + i - 1) && 0.01171875**(poImg + (j*rowsize * 2) + i - 5) + (-1 * 0.09765625)**(poImg + (j*rowsize * 2) + i - 3) + (0.1953125)**(poImg + (j*rowsize * 2) + i - 1) + (0.1953125)**(poImg + (j*rowsize * 2) + i + 1) + (-1 * 0.09765625)**(poImg + (j*rowsize * 2) + i + 3) + 0.01171875**(poImg + (j*rowsize * 2) + i + 5) < *(poImg + (j*rowsize * 2) + i + 1)) || (0.01171875**(poImg + (j*rowsize * 2) + i - 5) + (-1 * 0.09765625)**(poImg + (j*rowsize * 2) + i - 3) + (0.1953125)**(poImg + (j*rowsize * 2) + i - 1) + (0.1953125)**(poImg + (j*rowsize * 2) + i + 1) + (-1 * 0.09765625)**(poImg + (j*rowsize * 2) + i + 3) + 0.01171875**(poImg + (j*rowsize * 2) + i + 5) > *(poImg + (j*rowsize * 2) + i - 1) && 0.01171875**(poImg + (j*rowsize * 2) + i - 5) + (-1 * 0.09765625)**(poImg + (j*rowsize * 2) + i - 3) + (0.1953125)**(poImg + (j*rowsize * 2) + i - 1) + (0.1953125)**(poImg + (j*rowsize * 2) + i + 1) + (-1 * 0.09765625)**(poImg + (j*rowsize * 2) + i + 3) + 0.01171875**(poImg + (j*rowsize * 2) + i + 5) > *(poImg + (j*rowsize * 2) + i + 1)))
			{
				b = b + 1;

				*(poImg + (j*rowsize * 2) + i) = (*(poImg + (j*rowsize * 2) + i - 1) + *(poImg + (j*rowsize * 2) + i + 1)) / 2;
				c = c + 1;

			}


			//else if()
		}
	}
	printf("%d, %d, %d", b, c, k);


	//column-wise interpolation
	for (j = 0; j < rowsize * 2; j++) {
		for (i = 5; i < colsize * 2-6; i = i = i + 2) {
			*(poImg + (i*rowsize * 2) + j) = 0.01171875**(poImg + j + (i - 5)*rowsize * 2) + (-1 * 0.09765625)**(poImg + j + (i - 3)*rowsize * 2) + (0.1953125)**(poImg + j + (i - 1)*rowsize * 2) + (0.1953125)**(poImg + j + (i + 1)*rowsize * 2) + (-1 * 0.09765625)**(poImg + j + (i + 3)*rowsize * 2) + 0.01171875**(poImg + j + (i + 5)*rowsize * 2);
			if ((((0.01171875**(poImg + j + (i - 5)*rowsize * 2) + (-1 * 0.09765625)**(poImg + j + (i - 3)*rowsize * 2) + (0.1953125)**(poImg + j + (i - 1)*rowsize * 2) + (0.1953125)**(poImg + j + (i + 1)*rowsize * 2) + (-1 * 0.09765625)**(poImg + j + (i + 3)*rowsize * 2) + 0.01171875**(poImg + j + (i + 5)*rowsize * 2)) < (*(poImg + j + (i - 1)*rowsize * 2))) && ((0.01171875**(poImg + j + (i - 5)*rowsize * 2) + (-1 * 0.09765625)**(poImg + j + (i - 3)*rowsize * 2) + (0.1953125)**(poImg + j + (i - 1)*rowsize * 2) + (0.1953125)**(poImg + j + (i + 1)*rowsize * 2) + (-1 * 0.09765625)**(poImg + j + (i + 3)*rowsize * 2) + 0.01171875**(poImg + j + (i + 5)*rowsize * 2)) < (*(poImg + j + (i + 1)*rowsize * 2)))) || (((0.01171875**(poImg + j + (i - 5)*rowsize * 2) + (-1 * 0.09765625)**(poImg + j + (i - 3)*rowsize * 2) + (0.1953125)**(poImg + j + (i - 1)*rowsize * 2) + (0.1953125)**(poImg + j + (i + 1)*rowsize * 2) + (-1 * 0.09765625)**(poImg + j + (i + 3)*rowsize * 2) + 0.01171875**(poImg + j + (i + 5)*rowsize * 2)) > (*(poImg + j + (i - 1)*rowsize * 2))) && ((0.01171875**(poImg + j + (i - 5)*rowsize * 2) + (-1 * 0.09765625)**(poImg + j + (i - 3)*rowsize * 2) + (0.1953125)**(poImg + j + (i - 1)*rowsize * 2) + (0.1953125)**(poImg + j + (i + 1)*rowsize * 2) + (-1 * 0.09765625)**(poImg + j + (i + 3)*rowsize * 2) + 0.01171875**(poImg + j + (i + 5)*rowsize * 2)) > (*(poImg + j + (i + 1)*rowsize * 2)))))
			{

				*(poImg + (i*rowsize * 2) + j) = (*(poImg + j + (i - 1)*rowsize * 2) + *(poImg + j + (i + 1)*rowsize * 2)) / 2;

			}

		}
	}


	return 0;

}


int x2largrange_for_ad_4p_2p_w(unsigned char *pImg, unsigned char *poImg, int rowsize, int colsize)
{
	int i = 0;

	int pause;

	int x, x0, x1, x2, x3, x4, x5;

	x = 6;
	x0 = 1;
	x1 = 3;
	x2 = 5;
	x3 = 7;
	x4 = 9;
	x5 = 11;

	int L1u;
	int L1d;
	int L2u;
	int L2d;
	int L3u;
	int L3d;
	int L4u;
	int L4d;
	int L5u;
	int L5d;

	L1u = (x - x0)*(x - x2)*(x - x3)*(x - x4)*(x - x5);
	L1d = (x1 - x0)*(x1 - x2)*(x1 - x3)*(x1 - x4)*(x1 - x5);

	L2u = (x - x0)*(x - x1)*(x - x3)*(x - x4)*(x - x5);
	L2d = (x2 - x0)*(x2 - x1)*(x2 - x3)*(x2 - x4)*(x2 - x5);

	L3u = (x - x0)*(x - x1)*(x - x2)*(x - x4)*(x - x5);
	L3d = (x3 - x0)*(x3 - x1)*(x3 - x2)*(x3 - x4)*(x3 - x5);

	L4u = (x - x0)*(x - x1)*(x - x2)*(x - x3)*(x - x5);
	L4d = (x4 - x0)*(x4 - x1)*(x4 - x2)*(x4 - x3)*(x4 - x5);

	L5u = (x - x0)*(x - x1)*(x - x2)*(x - x3)*(x - x4);
	L5d = (x5 - x0)*(x5 - x1)*(x5 - x2)*(x5 - x3)*(x5 - x4);


	i = 0;
	int j = 0;

	for (j = 0; j < colsize; j++) {
		for (i = 0; i < rowsize; i++) {
			//if ((i * 2 + (j * 2 * rowsize)) > 1024 * 511)
			//pause = 25;
			*(poImg + i * 2 + (j * 2 * rowsize) * 2) = *(pImg + i + j*rowsize);
		}
	}//2x img scaling

	int a = 1;
	int b = 0;
	int c = 0;
	int k = 0;

	//row-wise interpolation
	for (j = 0; j < colsize * 2; j = j + 2) {
		for (i = 5; i < rowsize * 2-4; i = i + 2) {
			k = k + 1;

			*(poImg + (j*rowsize * 2) + i) = 0.5625*(*(poImg + (j*rowsize * 2) + i - 1) + *(poImg + (j*rowsize * 2) + i + 1)) - 0.0625*(*(poImg + (j*rowsize * 2) + i - 3) + *(poImg + (j*rowsize * 2) + i + 3));
			if ((0.5625*(*(poImg + (j*rowsize * 2) + i - 1) + *(poImg + (j*rowsize * 2) + i + 1)) - 0.0625*(*(poImg + (j*rowsize * 2) + i - 3) + *(poImg + (j*rowsize * 2) + i + 3)) < *(poImg + (j*rowsize * 2) + i - 1)) && (0.5625*(*(poImg + (j*rowsize * 2) + i - 1) + *(poImg + (j*rowsize * 2) + i + 1)) - 0.0625*(*(poImg + (j*rowsize * 2) + i - 3) + *(poImg + (j*rowsize * 2) + i + 3)) < *(poImg + (j*rowsize * 2) + i + 1)) || (0.5625*(*(poImg + (j*rowsize * 2) + i - 1) + *(poImg + (j*rowsize * 2) + i + 1)) - 0.0625*(*(poImg + (j*rowsize * 2) + i - 3) + *(poImg + (j*rowsize * 2) + i + 3)) > *(poImg + (j*rowsize * 2) + i - 1) && 0.5625*(*(poImg + (j*rowsize * 2) + i - 1) + *(poImg + (j*rowsize * 2) + i + 1)) - 0.0625*(*(poImg + (j*rowsize * 2) + i - 3) + *(poImg + (j*rowsize * 2) + i + 3)) > *(poImg + (j*rowsize * 2) + i + 1)))
			{
				*(poImg + (j*rowsize * 2) + i) = (*(poImg + (j*rowsize * 2) + i - 1) + *(poImg + (j*rowsize * 2) + i + 1)) / 2;
				c = c + 1;
			}



			//else if()
		}
	}
	printf("%d, %d, %d", b, c, k);


	//column-wise interpolation
	for (j = 0; j < rowsize * 2; j++) {
		for (i = 5; i < colsize * 2-4; i = i = i + 2) {
			*(poImg + (i*rowsize * 2) + j) = 0.5625*(*(poImg + j + (i - 1)*rowsize * 2) + *(poImg + j + (i + 1)*rowsize * 2)) - 0.0625*(*(poImg + j + (i - 3)*rowsize * 2) + *(poImg + j + (i + 3)*rowsize * 2));
			if ((((0.5625*(*(poImg + j + (i - 1)*rowsize * 2) + *(poImg + j + (i + 1)*rowsize * 2)) - 0.0625*(*(poImg + j + (i - 3)*rowsize * 2) + *(poImg + j + (i + 3)*rowsize * 2))) < (*(poImg + j + (i - 1)*rowsize * 2))) && ((0.5625*(*(poImg + j + (i - 1)*rowsize * 2) + *(poImg + j + (i + 1)*rowsize * 2)) - 0.0625*(*(poImg + j + (i - 3)*rowsize * 2) + *(poImg + j + (i + 3)*rowsize * 2))) < (*(poImg + j + (i + 1)*rowsize * 2)))) || (((0.5625*(*(poImg + j + (i - 1)*rowsize * 2) + *(poImg + j + (i + 1)*rowsize * 2)) - 0.0625*(*(poImg + j + (i - 3)*rowsize * 2) + *(poImg + j + (i + 3)*rowsize * 2))) > (*(poImg + j + (i - 1)*rowsize * 2))) && ((0.5625*(*(poImg + j + (i - 1)*rowsize * 2) + *(poImg + j + (i + 1)*rowsize * 2)) - 0.0625*(*(poImg + j + (i - 3)*rowsize * 2) + *(poImg + j + (i + 3)*rowsize * 2))) > (*(poImg + j + (i + 1)*rowsize * 2)))))
			{
				*(poImg + (i*rowsize * 2) + j) = (*(poImg + j + (i - 1)*rowsize * 2) + *(poImg + j + (i + 1)*rowsize * 2)) / 2;
			}


		}
	}


	return 0;

}