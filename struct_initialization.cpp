#include <iostream>

struct imagePrediction{
	int image;
	int label;
	imagePrediction(int arg_image, int arg_label): image{arg_image}, label{arg_label}{};
};


int main(int argc, char const *argv[]){
	imagePrediction image1{2, 4}, image2{1, 3}; 
	fprintf(stdout, "Image1: %d\t%d\n", image1.image, image1.label);
	return 0;
}