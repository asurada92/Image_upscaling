void x2smallscaling(unsigned char *pImg, unsigned char *poImg, int rowsize, int colsize)
{
	int i = 0;

	int pause;


	i = 0;
	int j = 0;

	for (j = 0; j < colsize; j++) {
		for (i = 0; i < rowsize; i++) {
			*(poImg + i + j*rowsize) = *(pImg + i * 2 + (j * 2 * rowsize) * 2);
		}
	}//2x img small scaling

	return;
}


void x3smallscaling(unsigned char *pImg, unsigned char *poImg, int rowsize, int colsize)
{
	int i = 0;

	int pause;


	i = 0;
	int j = 0;

	for (j = 0; j < colsize; j++) {
		for (i = 0; i < rowsize; i++) {
			*(poImg + i + j*rowsize) = *(pImg + i * 3 + (j * 3 * rowsize) * 3);
		}
	}//3x small img scaling

	return;
}


