#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//for 2x interpolation
#define vsmall 192
#define hsmall 192
#define vori 384
#define hori 384
#define vout 372
#define hout 372


//for 2x interpolation
/*
#define vori 2160
#define hori 3840
#define vout 2150
#define hout 3828
// horizental size have to be 4-multi
*/


#pragma pack(1) // 1바이트 단위로 저장
struct BITMAPFILEHEADER //FILE HEADER를 BITMAPFILEHEADER 이름의 구조체로 정의
{
	unsigned short bfType;
	unsigned int bfSize;
	unsigned short bfReserved1;
	unsigned short bfReserved2;
	unsigned int bfOffBits; //데이터 파일 시작 위치
};
struct BITMAPINFOHEADER //Image Header를 BITMAPINFOHEADER 이름의 구조체로 정의
{
	unsigned int biSize;
	int biiWidth;
	int biHeight;
	unsigned short biPlanes;
	unsigned short biBitCount;
	unsigned int biCompression;
	unsigned int biSizeImage;
	int biXPelsPerMeter;
	int biYpelsperMeter;
	unsigned int biClrUsed;
	unsigned int biClrImortant;
};
struct RGBQUAD
{
	unsigned char rgbBlue;
	unsigned char rgbGreen;
	unsigned char rgbRed;
	unsigned char rgbReserved;
};
#pragma pack()

struct BITMAPFILEHEADER bf_header; // BITMAPFILEHEADER형 변수 bf_header선언
struct BITMAPINFOHEADER bi_header; // BITMAPINFOHEADER형 변수 bi_header선언
struct RGBQUAD bmp_pal[256];       // 비트맵 팔레트
int main()
{
	FILE *fbmp, *fgrey; // File형 포인터변수 *fbmp, *fred선언
	int i;              // int형 변수 i 선언
	unsigned char *bmp, *grey, *poImg, *piImg;
	unsigned char  red, green, blue;

	//	fbmp = fopen("8bit_grey_sample(512x512).bmp", "rb");
//	fbmp = fopen("ori.bmp", "rb");
	fbmp = fopen("6p_2p.bmp", "rb");
	//fbmp = fopen("stripe_grey1(500x376).bmp", "rb");
	
	fread(&bf_header, sizeof(bf_header), 1, fbmp);
	fread(&bi_header, sizeof(bi_header), 1, fbmp);
	fread(&bmp_pal, sizeof(bmp_pal), 1, fbmp); // 8bit bitmap grey에서는 헤더뒤에 팔레트가 위치해 있으므로 읽고나서 픽셀값이 존재한다.

											   //	poImg = (unsigned char*)malloc(sizeof(unsigned char) * 1024 * 1024);
											   //	poImg = (unsigned char*)malloc(sizeof(unsigned char) * 1536 * 1536);//for 3x
	poImg = (unsigned char*)malloc(sizeof(unsigned char) * vout * hout);
	//piImg = (unsigned char*)malloc(sizeof(unsigned char) * vori * hori);
	//	grey = (unsigned char*)malloc(sizeof(unsigned char) * 512 * 512);
	
	
	grey = (unsigned char*)malloc(sizeof(unsigned char) * vori * hori);


	//fread(grey, sizeof(unsigned char), sizeof(unsigned char) * 512 * 512, fbmp);
	fread(grey, sizeof(unsigned char), sizeof(unsigned char) * vori*hori, fbmp);

	fclose(fbmp);

	printf("-------------------------------\n");
	printf("%d\n", bf_header.bfOffBits);
	printf("%d\n", bf_header.bfReserved1);
	printf("%d\n", bf_header.bfReserved2);
	printf("%d\n", bf_header.bfSize);
	printf("%d\n", bf_header.bfType);
	printf("\n");
	printf("%d\n", bi_header.biBitCount);
	printf("%d\n", bi_header.biClrImortant);
	printf("%d\n", bi_header.biClrUsed);
	printf("%d\n", bi_header.biCompression);
	printf("%d\n", bi_header.biHeight);
	printf("%d\n", bi_header.biiWidth);
	printf("%d\n", bi_header.biPlanes);
	printf("%d\n", bi_header.biSize);
	printf("%d\n", bi_header.biSizeImage);
	printf("%d\n", bi_header.biXPelsPerMeter);
	printf("%d\n", bi_header.biYpelsperMeter);
	int j,a;

	//for UHD
	/*
	for (j = 4; j < vori-6; j++) {
		for (i = 4; i < hori-8; i++)
		{

			*(poImg + ((j - 4)*hout) + i - 4) = *(grey + (j*hori) + i);
			if (*(poImg + ((j - 4)*hout) + i - 4) != *(grey + (j*hori) + i))
				a = 1;
		}

	}*/
	//for 384x384
	for (j = 4; j < vori - 9; j++) {
		for (i = 4; i < hori - 9; i++)
		{
			*(poImg + ((j - 4)*hout) + i - 4) = *(grey + (j*hori) + i);
			if (*(poImg + ((j - 4)*hout) + i - 4) != *(grey + (j*hori) + i))
				a = 1;
		}

	}




	// 위에서의 헤더는 24비트 비트맵의 헤더입니다.
	// 그레이비트맵은 8비트 비트맵이므로 정보를 바꾸어주어야 합니다.
	// 8비트 이하의 비트맵은 팔레트라고 해서 색상값을 따로 저장하고
	// 있습니다. 그 팔레트를 만들어 주셔야 합니다.


	//	fbmp = fopen("man.bmp", "rb");
	//	fbmp = fopen("human_grey(384x384).bmp", "rb");
	//	fread(&bf_header, sizeof(bf_header), 1, fbmp);
	//	fread(&bi_header, sizeof(bi_header), 1, fbmp);
	//	fclose(fbmp);

	printf("-------------------------------\n");
	printf("%d\n", bf_header.bfOffBits);
	printf("%d\n", bf_header.bfReserved1);
	printf("%d\n", bf_header.bfReserved2);
	printf("%d\n", bf_header.bfSize);
	printf("%d\n", bf_header.bfType);
	printf("\n");
	printf("%d\n", bi_header.biBitCount);
	printf("%d\n", bi_header.biClrImortant);
	printf("%d\n", bi_header.biClrUsed);
	printf("%d\n", bi_header.biCompression);
	printf("%d\n", bi_header.biHeight);
	printf("%d\n", bi_header.biiWidth);
	printf("%d\n", bi_header.biPlanes);
	printf("%d\n", bi_header.biSize);
	printf("%d\n", bi_header.biSizeImage);
	printf("%d\n", bi_header.biXPelsPerMeter);
	printf("%d\n", bi_header.biYpelsperMeter);


	// 인포헤더 아래에 팔레트가 오므로 1024만큼 뒤에 비트맵 데이터 시작
	/*bf_header.bfOffBits += 1024;
	// 8비트 비트맵이므로 8로 수정
	bi_header.biBitCount = 8;

	printf("%d", bi_header.biiWidth);
	printf("%d", bi_header.biHeight);*/

	//bi_header.biiWidth = 1536;
	//bi_header.biHeight = 1536;
	bi_header.biiWidth = hout;
	bi_header.biHeight = vout;
	//	bi_header.biiWidth = 512;
	//	bi_header.biHeight = 512;

	// 팔레트 만들기
	for (i = 0; i < 256; i++)
	{
		bmp_pal[i].rgbBlue = i;
		bmp_pal[i].rgbGreen = i;
		bmp_pal[i].rgbRed = i;
		bmp_pal[i].rgbReserved = 0;
	}



	fgrey = fopen("grey1.bmp", "wb");
	fwrite(&bf_header, sizeof(bf_header), 1, fgrey);
	fwrite(&bi_header, sizeof(bi_header), 1, fgrey);
	// 팔레트를 저장
	fwrite(bmp_pal, sizeof(bmp_pal), 1, fgrey);
	//	fwrite(grey, sizeof(unsigned char), 384 * 384, fgrey);//for sharpening test
	//	fwrite(grey, sizeof(unsigned char), 512 * 512, fgrey);//for sharpening test
	//	fwrite(piImg, sizeof(unsigned char), vsmall * hsmall, fgrey);
	fwrite(poImg, sizeof(unsigned char), vout * hout, fgrey);
	//fwrite(poImg, sizeof(unsigned char), 1536 * 1536, fgrey);//for 3x
	fclose(fgrey);
}