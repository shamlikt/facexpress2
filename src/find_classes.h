#ifndef _FIND_CLASSES_H_
#define _FIND_CLASSES_H_
#include "asmlibrary.h"
#include <string>
#include <fstream>

using namespace std;

const int N_FEATURES = 7;
int N_EXPRESSIONS;
int N_SAMPLES;
int N_POINTS;
char** EXP_NAMES;
int *classLabelArray;
double *classPointArray;
cv::Mat classLabels;
cv::Mat classPoints;
cv::Mat classDistances;
cv::Mat diff;


void read_config_from_file(string filename){
	ifstream file(filename, ios::in);
	if(!file.is_open()){
		cout << "error opening file: " << filename << endl;
		exit(1);
	}

	file >> N_EXPRESSIONS >> N_SAMPLES;
	N_POINTS = N_EXPRESSIONS * N_SAMPLES;

	EXP_NAMES = new char*[N_EXPRESSIONS];	//read expression names from file
	for(int i=0 ; i<N_EXPRESSIONS ; i++){
		EXP_NAMES[i] = new char[11];
		file >> EXP_NAMES[i];
	}

	classLabelArray = new int[N_POINTS];	//create classLabelArray (independent from file)
	for(int i=0 ; i<N_POINTS ; i++){
		classLabelArray[i] = i/N_SAMPLES;
	}

	classPointArray = new double[N_POINTS*N_FEATURES];	//read feature values for each class from file
	for(int i=0 ; i<N_POINTS*N_FEATURES ; i++){
		file >> classPointArray[i];
	}

	file.close();

	classLabels = cv::Mat(1, N_POINTS, CV_32SC1, classLabelArray);
	classPoints = cv::Mat(N_POINTS, N_FEATURES, CV_64FC1, classPointArray);
	classDistances = cv::Mat(N_POINTS, 1, CV_64FC1);
	diff = cv::Mat(1, N_FEATURES, CV_64FC1);
}

char * str2cca(string a){
	char* buf = new char[a.size()];
	sprintf(buf, "%100c", a);
	return buf;
}

void config(string filename, int n_expressions, int n_samples, string *exp_names){
	ofstream file(filename, ios::out);
	if(!file.is_open()){
		cout << "error opening file: " << filename << endl;
		exit(1);
	}

	N_EXPRESSIONS = n_expressions;
	N_SAMPLES = n_samples;
	file << N_EXPRESSIONS << endl << N_SAMPLES << endl;
	cout << N_EXPRESSIONS << endl << N_SAMPLES << endl;
	N_POINTS = N_EXPRESSIONS * N_SAMPLES;

	EXP_NAMES = new char*[N_EXPRESSIONS];
	for(int i=0 ; i<N_EXPRESSIONS ; i++){
		cout<< exp_names[i] << endl;
		cout<< strdup(exp_names[i].c_str()) << endl;
		
		EXP_NAMES[i] = strdup(exp_names[i].c_str());	
		file << EXP_NAMES[i] << endl;
	}
	
	file.close();
}

double get_distance(cv::Mat& p32, cv::Mat& p64) {
	for(int i=0; i<N_FEATURES; i++)
		diff.at<double>(0,i) = p32.at<float>(0,i) - p64.at<double>(0,i);
	return cv::norm(diff);
}

cv::Mat get_class_weights(cv::Mat instance) {
	cv::Mat weights = cv::Mat(1,N_EXPRESSIONS, CV_64FC1);
	cvZero(&(CvMat)weights);
	double dist;

	for(int i = 0; i<N_POINTS; i++) {
		dist = get_distance(instance, classPoints.row(i));
		// classDistances.at<double>(i,0) = dist;
		// printf("%d ", classLabels.at<int>(0,i));
		weights.at<double>(0, classLabels.at<int>(0,i)) += dist;
		//printf("%.2f ",dist);
	}
	//cout <<endl;
	// printf("%lf %lf\n", weights.at<double>(0,0), weights.at<double>(0,1));

	for(int i = 0; i < N_EXPRESSIONS; i++)
		weights.at<double>(0,i) = exp(-weights.at<double>(0,i));

	double sum = cv::sum(weights).val[0];
	for(int i = 0; i < N_EXPRESSIONS; i++)
		weights.at<double>(0,i) /= sum;


	return weights;
}

#endif