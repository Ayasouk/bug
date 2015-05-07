/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "img.h"

argimg *
moyfiltr_prog_1_1_svc(argimg *argp, struct svc_req *rqstp)
{

	static argimg * img = argp;
	int index;
	unsigned char * buffer = NULL;
	int offset_V = (img->n)/2;
	int offset_H = (img->m)/2;
	int i, j, h, l;
	float somme = 0.0;
	
	buffer = malloc(sizeof(n*m*sizeof(unsigned char)));
	
	for(i=1; i< img->hauteur-1; i++){
		for(j=1; j < img->largeur-1; j++){
		somme = 0.0;
			for(h= -offset_H; h<= offset_H; h++){
				for(l= -offset_V; l<=offset_V; l++){
					somme+=img->imgE[i+h+img->largeur*(j+l)];
				}
			}
			img->imgS[i+j*img->largeur] = (unsigned char) (somme/(float)n*m);
		}
	}
	return img;
}

argimg *
medfiltr_prog_2_1_svc(argimg *argp, struct svc_req *rqstp)
{
	static argimg* img = argp;
	int i, j, k, h;
	int tab[9];
	int ind = 0;
	
	for(i=1; i<img->hauteur-1; i++){ // parcours de l'image
		for(j=1; j<img->largeur-1; j++){
			for(k=i-1; k<=i+1; k++){ //initialisation tableau 
				for(h=j-1; h<=h+1; h++){
					tab[ind]=img->imgE[k+img->largeur*h];
					ind++;
				}
			}
			qsort(tab, sizeof(char), 9, comparer_int); //comparer int a faire
			img->imgS[] = img->imgE[] //a termminer 
		}
	}

	return img;
}
