#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<assert.h>

#include "ringbuf.h"

/*
 * author: Kalpit Mody 
 * date: 09/07/2020
 * pledge: this is my own work, unless otherwise noted
 *
 * this is a template. change "author" and continue work
 *
 * update: 
 */


/* static variables (zeroed) */

int g_debug = 0 ;
int is_verbose = 0 ;
struct RingBuf rb ;

int rb_ioctl(int op) {
	switch (op) {
	case RB_Q_SIZE:
		return RINGBUF_SIZE ;
	case RB_IS_EMPTY:
		if(!rb.is_full && rb.head == rb.tail){
		return 1 ;
	} else {
		return 0;
	}	
	case RB_IS_FULL:
		if(rb.is_full){
		return 1;
	} else {
		return 0;
	}
	case RB_Q_COUNT:
	if(rb.head - rb.tail > 0){
		return rb.head - rb.tail;
	} else if(rb.head - rb.tail < 0){
		return (rb.head - rb.tail) + 16;
	} else if(rb.is_full){
		return RINGBUF_SIZE;
	} else {
		return 0;
	}
	default:
		;
	}
	return 0 ;
}

int rb_enqueue(int ele) {
	if(!rb.is_full){
		rb.ringbuf[rb.head] = ele;
		rb.head = (1 + rb.head) % RINGBUF_SIZE;	
		if(rb.head == rb.tail){
			rb.is_full = 1;
		}
		return ele;
	}
	return -1;
}

int rb_dequeue(void) {
	int temp;
	if(!rb.is_full && rb.head == rb.tail){
		return -1;
	} else {
		temp = rb.ringbuf[rb.tail];
		rb.tail = (1 + rb.tail) % RINGBUF_SIZE;
		rb.is_full = 0;
		return temp;
	}
}

