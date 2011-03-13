#ifndef _FUNCS_H_
#define _FUNCS_H_
#include "asmlibrary.h"
#include <string>

using namespace std;

//prints how to enter the command line arguments
static void usage_fit()		//gerektiðinde deðiþtir
{
	printf("Usage: fit -m model_file -h cascade_file "		//shape model falan eklenmesi lazým
		"{-i image_file | -v video_file | -c } -n n_iteration -S shape_output_file -P pose_output_file -g show_tracker_gui -e show_processed_gui -r show_regions_on_gui -f show_features -t show_shape -x max_components\n\n\n");
	exit(0);
}

/* 
Save a shape to a pts file
@param shape shape to save
@param filename path of the file to write the shape in 
*/
void save_shape(asm_shape shape, char* filename) {

	FILE *fp;
	fopen_s(&fp, filename, "w");
	
	if (fp == NULL) {
		fprintf(stderr, "Can't open output file %s!\n", filename);
		exit(1);
	}

	fprintf(fp, "version: 1\nn_points: %d\n{\n", shape.NPoints());
	for(int i=0; i<shape.NPoints(); i++)
		fprintf(fp, "    %f %f\n", shape[i].x, shape[i].y);
	fprintf(fp, "}");
	fclose(fp);


}

int compare (const void * a, const void * b)
{
  return (int)( *(float*)a - *(float*)b );
}

/*
return median of an array
@param arr array to get median of
@param size size of array
@return median value
*/
float get_median(float arr[], int size)
{
	int middle = size/2;
	float median;
	if (size%2==0) median = static_cast<float>(arr[middle-1]+arr[middle])/2;
	else median = static_cast<float>(arr[middle]);

	return median;
}

/*
calculate median shape by using float get_median() function
@param shapes array of shapes to get median of
@param nShapes size of the array of shapes
@return median shape
*/
asm_shape get_median(asm_shape shapes[], int nShapes) {
	asm_shape shape = shapes[nShapes-1];
	int i, j;
	float *xs, *ys;

	xs = new float[nShapes];
	ys = new float[nShapes];

	for(i=0; i<shape.NPoints(); i++) {
		for(j=0; j<nShapes; j++) {
			xs[j] = shapes[j][i].x;
			ys[j] = shapes[j][i].y;
		}
		qsort(xs, nShapes, sizeof(float), compare);
		qsort(ys, nShapes, sizeof(float), compare);
		
		shape[i].x = get_median(xs, nShapes);
		shape[i].y = get_median(ys, nShapes);
	}


	return shape;
}

/*
calculate mean shape
@param shapes array of shapes to get mean of
@param nShapes size of the array of shapes
@return mean shape
*/
asm_shape get_mean(asm_shape shapes[], int nShapes) {
	asm_shape shape = shapes[nShapes-1];
	int i, j;

	for(i=0; i<shape.NPoints(); i++) {
		shape[i].x = 0;
		shape[i].y = 0;
		for(j=0; j<nShapes; j++) {
			shape[i].x += shapes[j][i].x;
			shape[i].y += shapes[j][i].y;
		}
		shape[i].x /= nShapes;
		shape[i].y /= nShapes;
	}


	return shape;
}

/*
calculate weighted mean shape, last shapes have more weights
@param shapes array of shapes to get mean of
@param nShapes size of the array of shapes
@return weighted mean shape
*/
asm_shape get_weighted_mean(asm_shape shapes[], int nShapes) {
	asm_shape shape = shapes[nShapes-1];
	int i, j;
	double w, wSum;

	for(i=0; i<shape.NPoints(); i++) {
		wSum = 0;
		shape[i].x = 0;
		shape[i].y = 0;
		for(j=0; j<nShapes; j++) {
			w = pow(2.0,i);
			wSum += w;
			shape[i].x += (float)w*shapes[j][i].x;
			shape[i].y += (float)w*shapes[j][i].y;
		}
		shape[i].x /= (float)wSum;
		shape[i].y /= (float)wSum;
	}

	return shape;
}

/*
write shape to a file
@param shape shape to write to a file
@param fp pointer to the file to write the shape on
*/
void write_shape(asm_shape shape, FILE* fp) {
	if (fp == NULL) {
		fprintf(stderr, "Can't process output file %s!\n");
		exit(1);
	}
	for(int i=0; i<shape.NPoints(); i++)
		fprintf(fp, "%.2f,%.2f,", shape[i].x, shape[i].y);
	fprintf(fp, "\n");

}

/*
write a row vector to a file
@param mat row vector to write to a file
@param fp pointer to the file to write the row vector on
*/
void write_vector(cv::Mat mat, FILE* fp) {
	int i;
	if (fp == NULL) {
		fprintf(stderr, "Can't process output file %s!\n");
		exit(1);
	}
	if(mat.rows != 1 || mat.type() != CV_32FC1)  {
		fprintf(stderr, "The variable is not a row vector or the type is not float\n");
		exit(1);
	}
	for(i=0; i<mat.cols-1; i++)
		fprintf(fp, "%.3f,", mat.at<float>(0,i));
	fprintf(fp, "%.3f\n", mat.at<float>(0,i));
}

/*
write weights of expression classes for a frame to a file
@param mat expression vector to write to a file
@param fp pointer to the file to write the row vector on
@param frameNo number of frame
*/
void write_expressions(cv::Mat mat, FILE* fp, int frameNo) {
	int i;
	if (fp == NULL) {
		fprintf(stderr, "Can't process output file %s!\n");
		exit(1);
	}
	fprintf(fp, "%.5d: ", frameNo);
	for(i=0; i<N_EXPRESSIONS-1; i++){
		fprintf(fp, "       %.2f", mat.at<double>(0,i));
	}
	fprintf(fp, "       %.2f\n", mat.at<double>(0,i));

}

#endif