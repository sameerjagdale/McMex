/*
 * mexgc.cpp
 *
 *  Created on: Jun 12, 2013
 *      Author: sameer
 */
#include<set>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<gc.h>
#include"mex.h"
using namespace std;

void* mxMalloc(size_t size) {
	return GC_MALLOC(size);
}
void mxFree(void*ptr) {
	GC_FREE(ptr);
}
void* mxCalloc(size_t size, int n) {
	void* temp = GC_MALLOC(size*n);
	return memset(temp, 0, n);
}
void setPr(mxArray * mxarray, double*pr) {
	mxarray->setPr(pr);

}

void mxSetM(mxArray* mxarray, mwSize M) {
	mxarray->setM(M);
}
void mxSetN(mxArray*mxarray, mwSize N) {
	mxarray->setN(N);
}
void mxSetDimensions(mxArray*mxarray, const mwSize*dims, mwSize ndims) {
	mxarray->setDimensions(dims, ndims);
}

//Dimension extractors
size_t mxGetM(mxArray*mxarray) {
	return mxarray->getM();
}
size_t mxGetN(mxArray*mxarray) {
	return mxarray->getN();
}
mwSize* mxGetDimensions(mxArray*mxarray) {
	return mxarray->getDimensions();
}
mwSize mxGetNumberOfDimensions(mxArray*mxarray) {
	return mxarray->getNumberOfDimensions();
}
size_t mxGetNumberOfElements(mxArray*mxarray) {
	return mxarray->getNumberOfElements();
}

//Type Predicates
int mxIsCell(mxArray*mxarray) {
	return mxarray->isCell();
}
int mxIsChar(mxArray*mxarray) {
	return mxarray->isChar();
}
//int mxIsClass(MxArray*mxarray, char *name);
int mxIsComplex(mxArray*mxarray) {
	return mxarray->isComplex();
}
int mxIsDouble(mxArray*mxarray) {
	return mxarray->isDouble();
}
int mxIsFunctionHandle(mxArray*mxarray) {
	return mxarray->isFunctionHandle();
}
//int mxIsInt16(MxArray*mxarray)
int mxIsInt32(mxArray*mxarray) {
	return mxarray->isInt32();
}
//int mxIsInt64(MxArray*mxarray);
//int mxIsInt8(MxArray*mxarray);
int mxIsLogical(mxArray*mxarray) {
	return mxarray->isLogical();
}
int mxIsNumeric(mxArray*mxarray) {
	return mxarray->isNumeric();
}
int mxIsSingle(mxArray*mxarray) {
	return mxarray->isSingle();
}
//int mxIsSparse(MxArray*mxarray);
int mxIsStruct(mxArray*mxarray) {
	return mxarray->isStruct();
}

//size predicate
int mxIsEmpty(mxArray*mxarray) {
	return mxarray->isEmpty();
}

//data extractors
double* mxGetPr(mxArray*mxarray) {
	return mxarray->getPr();
}
double* mxGetPi(mxArray*mxarray) {
	return mxarray->getPi();
}
double mxGetScalar(mxArray*mxarray) {
	return mxarray->getScalar();
}
mxChar* mxGetChars(mxArray*mxarray) {
	return mxarray->getChars();
}
mxLogical* mxGetLogical(mxArray*mxarray) {
	return mxarray->getLogical();
}

void* mxGetData(mxArray*mxarray) {
	return mxarray->getData();
}
void* mxGetImagData(mxArray*mxarray) {
	return mxarray->getImagData();
}
//Data setters
void mxSetPr(mxArray*mxarray, double*data) {
	mxarray->setPr(data);
}
void mxSetPi(mxArray*mxarray, double*data) {
	mxarray->setPi(data);
}
void mxSetImagData(mxArray*mxarray, void*data) {
	mxarray->setImagData(data);
}
void mxSetData(mxArray*mxarray, void*data) {
	mxarray->setData(data);
}

