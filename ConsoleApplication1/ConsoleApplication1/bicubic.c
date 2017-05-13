#define vs 0.5
#define vs1 0.3
#define vs2 0.6
void x2bicubic(unsigned char *pImg, unsigned char *poImg, int rowsize, int colsize)
{

	int i=0;
	int j=0;
	/*
	unsigned char vc0;
	unsigned char vc1;
	unsigned char vc2;
	unsigned char vc3;
	*/

	float vc0;
	float vc1;
	float vc2;
	float vc3;



	for (j = 0; j < colsize; j++) {
		for (i = 0; i < rowsize; i++) {
			//if ((i * 2 + (j * 2 * rowsize)) > 1024 * 511)
			//pause = 25;
			*(poImg + i * 2 + (j * 2 * rowsize) * 2) = *(pImg + i + j*rowsize);
		}
	}//2x img scaling

	vc0 = 4 - 8 * (1 + vs) + 5 * (1 + vs)*(1 + vs) - (1 + vs)*(1 + vs)*(1 + vs);
	vc1 = 1 - 2 * vs*vs + vs*vs*vs;
	vc2 = 1 - 2 * (1 - vs)*(1 - vs) + (1 - vs)*(1 - vs)*(1 - vs);
	vc3 = 4 - 8 * (2 - vs) + 5 * (2 - vs)*(2 - vs) - (2 - vs)*(2 - vs)*(2 - vs);

	
	 //row-wise interpolation
	for (j = 0; j < colsize * 2; j++) {
		for (i = 3; i < rowsize * 2 - 4; i = i + 2) {
			*(poImg + (j*rowsize * 2) + i) =vc0**(poImg + (j*rowsize * 2) + i - 3) + vc1**(poImg + (j*rowsize * 2) + i - 1) + vc2**(poImg + (j*rowsize * 2) + i + 1) + vc3**(poImg + (j*rowsize * 2) + i + 3);
			if (vc0**(poImg + (j*rowsize * 2) + i - 3) + vc1**(poImg + (j*rowsize * 2) + i - 1) + vc2**(poImg + (j*rowsize * 2) + i + 1) + vc3**(poImg + (j*rowsize * 2) + i + 3) > 255)
				*(poImg + (j*rowsize * 2) + i) = 255;
			else if(vc0**(poImg + (j*rowsize * 2) + i - 3) + vc1**(poImg + (j*rowsize * 2) + i - 1) + vc2**(poImg + (j*rowsize * 2) + i + 1) + vc3**(poImg + (j*rowsize * 2) + i + 3) <0)
				*(poImg + (j*rowsize * 2) + i) = 0;
		}
	}


	//column-wise interpolation
	for (j = 0; j < rowsize * 2; j++) {
		for (i = 3; i < colsize * 2 - 4; i = i = i + 2) {
			*(poImg + (i*rowsize * 2) + j) = vc0**(poImg + j + (i - 3)*rowsize * 2) + vc1**(poImg + j + (i - 1)*rowsize * 2) + vc2**(poImg + j + (i + 1)*rowsize * 2) + vc3**(poImg + j + (i + 3)*rowsize * 2);
			if (vc0**(poImg + j + (i - 3)*rowsize * 2) + vc1**(poImg + j + (i - 1)*rowsize * 2) + vc2**(poImg + j + (i + 1)*rowsize * 2) + vc3**(poImg + j + (i + 3)*rowsize * 2) > 255)
				*(poImg + (i*rowsize * 2) + j) = 255;
			else if (vc0**(poImg + j + (i - 3)*rowsize * 2) + vc1**(poImg + j + (i - 1)*rowsize * 2) + vc2**(poImg + j + (i + 1)*rowsize * 2) + vc3**(poImg + j + (i + 3)*rowsize * 2) < 0)
				*(poImg + (i*rowsize * 2) + j) = 0;
		}
	}
	

	return 0;


}


void x3bicubic(unsigned char *pImg, unsigned char *poImg, int rowsize, int colsize)
{

	int i = 0;
	int j = 0;
    float vc10;
	float vc11;
	float vc12;
	float vc13;

	float vc20;
	float vc21;
	float vc22;
	float vc23;



	for (j = 0; j < colsize; j++) {
		for (i = 0; i < rowsize; i++) {
			//if ((i * 2 + (j * 2 * rowsize)) > 1024 * 511)
			//pause = 25;
			*(poImg + i * 3 + (j * 3 * rowsize) * 3) = *(pImg + i + j*rowsize);
		}
	}//3x img scaling
	
	//coefficient for first in order
	vc10 = 4 - 8 * (1 + vs1) + 5 * (1 + vs1)*(1 + vs1) - (1 + vs1)*(1 + vs1)*(1 + vs1);
	vc11 = 1 - 2 * vs1*vs1 + vs1*vs1*vs1;
	vc12 = 1 - 2 * (1 - vs1)*(1 - vs1) + (1 - vs1)*(1 - vs1)*(1 - vs1);
	vc13 = 4 - 8 * (2 - vs1) + 5 * (2 - vs1)*(2 - vs1) - (2 - vs1)*(2 - vs1)*(2 - vs1);
	//coefficient for second in order
	vc20 = 4 - 8 * (1 + vs2) + 5 * (1 + vs2)*(1 + vs2) - (1 + vs2)*(1 + vs2)*(1 + vs2);
	vc21 = 1 - 2 * vs2*vs2 + vs2*vs2*vs2;
	vc22 = 1 - 2 * (1 - vs2)*(1 - vs2) + (1 - vs2)*(1 - vs2)*(1 - vs2);
	vc23 = 4 - 8 * (2 - vs2) + 5 * (2 - vs2)*(2 - vs2) - (2 - vs2)*(2 - vs2)*(2 - vs2);


	//row-wise interpolation
	for (j = 0; j < colsize * 3; j++) {
		for (i = 4; i < rowsize * 3 - 7; i = i + 3) {
			*(poImg + (j*rowsize * 3) + i) = vc10*(*(poImg + (j*rowsize * 3) + i - 4)) + vc11*(*(poImg + (j*rowsize * 3) + i - 1)) + vc12*(*(poImg + (j*rowsize * 3) + i + 2)) + vc13*(*(poImg + (j*rowsize * 3) + i + 5));
		}
	}

	for (j = 0; j < colsize * 3; j++) {
		for (i = 5; i < rowsize * 3 - 6; i = i + 3) {
			*(poImg + (j*rowsize * 3) + i) = vc20*(*(poImg + (j*rowsize * 3) + i - 5)) + vc21*(*(poImg + (j*rowsize * 3) + i - 2)) + vc22*(*(poImg + (j*rowsize * 3) + i + 1)) + vc23*(*(poImg + (j*rowsize * 3) + i + 4));
		}
	}


	//column-wise interpolation
	for (j = 0; j < rowsize * 3; j++) {
		for (i = 4; i < colsize * 3 - 7; i = i = i + 3) {
			*(poImg + (i*rowsize * 3) + j) = vc10*(*(poImg + j + (i - 4)*rowsize * 3)) + vc11*(*(poImg + j + (i - 1)*rowsize * 3)) + vc12*(*(poImg + j + (i + 2)*rowsize * 3)) + vc13*(*(poImg + j + (i + 5)*rowsize * 3));
		}
	}

	for (j = 0; j < rowsize * 3; j++) {
		for (i = 5; i < colsize * 3 - 6; i = i = i + 3) {
			*(poImg + (i*rowsize * 3) + j) = vc20*(*(poImg + j + (i - 5)*rowsize * 3)) + vc21*(*(poImg + j + (i - 2)*rowsize * 3)) +vc22*(*(poImg + j + (i + 1)*rowsize * 3)) +vc23*(*(poImg + j + (i + 4)*rowsize * 3));
		}
	}
	

	return 0;


}