#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<ctype.h>
#include<assert.h>

#include "quiz4.h"

//author: Kalpit Mody
//date: 09/14/2020


void capitalize(char * s) {
	while (*s) {
		*s = toupper(*s) ;
		s++ ;
	}
	return ;
}


void capitalize_all(char ** sp) {
	while (*sp) {
		capitalize(*sp) ;
		sp++ ;
	}
	return ;

}


void print_all(char ** sp, char * delimit) {

	// write code here
	if(!*sp){
		return;
	}	
	while(*sp){
		printf("%s %s", *sp, delimit);
		sp++;
	}		
	printf("\n"); 
	return ;
}
