
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "Maxfiles.h"
#include "MaxSLiCInterface.h"

int check(int32_t *input, int32_t *expected, int size){
    	int status = 0;
		for(int i = 0; i < size; i++) {
			if(abs(input[i] - expected[i])>3) {
				fprintf(stderr, "Output data @ %d = %d (expected %d)\n",
					i, input[i], expected[i]);
				status = 1;
			}
		}

	return status;
}

int main(void)
{
	printf("Loading image.\n");
	int32_t *inImage;
	int width = 0, height = 0;
	loadImage("lena.ppm", &inImage, &width, &height, 1);

	int dataSize = width * height * sizeof(int);
	// Allocate a buffer for the output image
	int32_t *outImage = malloc(dataSize);
	
	printf("Running Kernel.\n");
	
	//The more iterations, the more it gets blurred
	int numIterations = 3;
	
	for(int i=0; i<numIterations; i++){
	    GaussBlur(width * height, inImage, outImage);
	    inImage = outImage;
	}

	printf("Saving image.\n");
	writeImage("lena_blurred.ppm", outImage, width, height, 1);
	
	int32_t *expected;
	int32_t *input;
	loadImage("lena_blurred_expected.ppm", &expected, &width, &height, 1);
	loadImage("lena_blurred.ppm", &input, &width, &height, 1);
	int status = check(outImage, expected, width*height);
	if (status)
		printf("Test failed.\n");
	else
		printf("Test passed OK!\n");
	return status;
}

