#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libgen.h>

#include "answer05.h"

#define FALSE 0
#define TRUE 1

Image * Image_load(const char * filename)
{
	FILE *fptr; 
	int error = FALSE; //error indicator: 0 = not fail, 1 = fail
	size_t read;
	size_t readcomment;
	size_t readdata; 
	ImageHeader header;
	Image *image = NULL; //image
	Image *image_t = NULL; //temp image

	if(!error) //#1
	{
		fptr = fopen(filename, "rb");
		if(fptr == NULL)
		{	
			fprintf(stderr, "Failed to read header from '%s' \n", filename);
			error = TRUE;
		}
	}

	if(!error) //#2
	{
		read = fread(&header, sizeof(ImageHeader), 1, fptr); 
		if(read != 1)
		{
			fprintf(stderr, "Failed to read header from '%s' \n", filename);
			error = TRUE;
		}
		if(header.magic_number != ECE264_IMAGE_MAGIC_NUMBER)
		{
			fprintf(stderr, "Magic Number in header is not correct\n");
			error = TRUE;
		}
		if((header.width * header.height) == 0)
		{
			fprintf(stderr, "Either header width or height are zero\n");
			error = TRUE;
		}
		if(header.comment_len < 2) 
		{
			fprintf(stderr, "Header comment is empty\n");
			error = TRUE;
		}
	}
	
	if(!error) //#3
	{
		image_t = malloc(sizeof(Image)); 
		if(image_t == NULL)
		{
			fprintf(stderr, "Failed to allocated image strucutre \n");
			error = TRUE;
		}			
		image_t->comment = malloc(sizeof(char) * header.comment_len);
		if(image_t == NULL)
		{
			fprintf(stderr, "Failed to allocate image comment \n");
			error = TRUE;
		}
		image_t->data = malloc(sizeof(char) * header.height * header.width);
		if(image_t->data == NULL)
		{
			fprintf(stderr, "Failed to allocate image pixels \n");
			error = TRUE;
		}
	}
	
	if(!error) //#4
	{
		image_t->width = header.width;
		image_t->height = header.height;
	
		readcomment = fread(image_t->comment, sizeof(char), header.comment_len, fptr);
		if(readcomment != header.comment_len)
		{
			fprintf(stderr, "Failed to read header comment from '%s' \n", filename);
			error = TRUE;
		}
		int i;
		i = header.comment_len - 1;
		if(image_t->comment[i] != '\0')
		{
			fprintf(stderr, "Image comment does not end with a null byte");
			error = TRUE;
		}
	}
	
	if(!error) //#5
	{
		readdata = fread(image_t->data, sizeof(char), ((image_t->width) * (image_t->height)), fptr);
		if(readdata != ((image_t->width) * (image_t->height)))
		{
			fprintf(stderr, "Failed to read header data from '%s' \n", filename);
			error = TRUE;
		}
		uint8_t byte;
		read = fread(&byte, sizeof(char), 1, fptr);
		if(read != 0)
		{
			fprintf(stderr, "Stray bytes at the end of file '%s'\n", filename);
			error = TRUE;
		}
	}
	
	if(!error)
	{
		image = image_t;
		image_t = NULL;
	}
	
	if(image_t != NULL)
	{
		free(image_t->comment);
		free(image_t->data);
		free(image_t);
	}
	if(fptr)
	{
		fclose(fptr);
	}
	return image;
}

int Image_save(const char * filename, Image * image)
{
	FILE * fptr = NULL;
	int error = FALSE;
	size_t w_header = 0;
	size_t w_comment = 0;
	size_t w_data = 0;
	int comment_l = strlen(image->comment) + 1;
	int A;

	ImageHeader header;
	header.magic_number = ECE264_IMAGE_MAGIC_NUMBER;
	header.width = image->width;
	header.height = image->height;
	header.comment_len = comment_l;

	fptr = fopen(filename, "wb");
	if(fptr == NULL)
	{
		fprintf(stderr, "Failed to open '%s' for writing\n", filename);
		return FALSE;
	}
	
	if(error == TRUE)
	{
		w_header = fwrite(&header, sizeof(ImageHeader), 1, fptr);
		if(w_header != 1)
		{
			fprintf(stderr, "Failed to write image header from '%s'\n", filename);
			error = TRUE;
		}
	}
	
	if(error == TRUE)
	{
		w_comment = fwrite(image->comment, sizeof(uint8_t), header.comment_len, fptr);
		if(w_comment != header.comment_len)
		{
			fprintf(stderr, "Failed to write image comment from '%s'\n",filename);
			error = TRUE;
		}
	}

	if(error == TRUE)
	{
		A = header.width * header.height;
		w_data = fwrite(image->data, sizeof(uint8_t), A, fptr);
		if(w_data != A)
		{
			fprintf(stderr, "Failed to write image data from '%s'\n", filename);
			error = TRUE;
		}
	}

	if(fptr)
	{
		fclose(fptr);
	}
	return !error;
}

void Image_free(Image * image)
{
	if(image != NULL)
	{
		free(image->data);
		free(image->comment);
		free(image);
	}
}

void linearNormalization(int width, int height, uint8_t * intensity)
{
	int i;
	int j;
	int k;
	int x = 0;
	int y = 0;
	int min;
	int max;
	int A = width * height;
	
	for(i = 0; i < A; i++)
	{
		if(x == 0)
		{
			min = intensity[i];
			x = 1;
		}
		else //if(x == 1)
		{
			if(intensity[i] <= min)
			{
				min = intensity[i];
			}
		}
	}
	for(j = 0; j < A; j++)
	{
		if(y == 0)
		{
			max = intensity[j];
			y = 1;
		}
		else //if (y == 1)
		{
			if(intensity[j] >= max)
			{
				max = intensity[j];
			}
		}
	}
	for(k = 0; k < A; k++)
	{
		intensity[k] = (((intensity[k] - min) * 255.0) / (max - min));
	}
}

