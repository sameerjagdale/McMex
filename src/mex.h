/*
 * mex.h
 *
 *  Created on: Jun 12, 2013
 *      Author: sameer
 */
#include<cstdlib>
#include<set>
#include<iostream>
#include<gc/gc_cpp.h>
#include"mxArray.h"
#ifndef MEX_H_
#define MEX_H_
using namespace std;

void* mxMalloc(size_t size);
void* mxCalloc(size_t size, int n);
void mxFree(void*);
void setPr(mxArray* mxarray, double*pr);
void getPr(mxArray*mxarray, double *pi);

//Dimension Setters
void mxSetM(mxArray*, mwSize M);
void mxSetN(mxArray*, mwSize N);
void mxSetDimensions(mxArray*, const mwSize*, mwSize ndims);

//Dimension extractors
size_t mxGetM(mxArray*);
size_t mxGetN(mxArray*);
mwSize* mxgetDimensions(mxArray*);
mwSize mxGetNumberOfDimensions(mxArray*);
size_t mxGetNumberOfElements(mxArray*);

//type predicates
int mxIsCell(mxArray*mxarray);
int mxIsChar(mxArray*mxarray);
int mxIsClass(mxArray*mxarray, char *name);
int mxIsComplex(mxArray*mxarray);
int mxIsDouble(mxArray*mxarray);
int mxIsFunctionHandle(mxArray*mxarray);
int mxIsInt16(mxArray*mxarray);
int mxIsInt32(mxArray*mxarray);
int mxIsInt64(mxArray*mxarray);
int mxIsInt8(mxArray*mxarray);
int mxIsLogical(mxArray*mxarray);
int mxIsNumeric(mxArray*mxarray);
int mxIsSingle(mxArray*mxarray);
int mxIsSparse(mxArray*mxarray);
int mxIsStruct(mxArray*mxarray);

//size predicate
int mxIsEmpty(mxArray*mxarray);

//data extractors
double* mxGetPr(mxArray*mxarray);
double* mxGetPi(mxArray*mxarray);
double mxGetScalar(mxArray*mxarray);
mxChar* mxGetChars(mxArray*mxarray);
mxLogical* mxGetLogical(mxArray*mxarray);

void* mxGetData(mxArray*mxarray);
void* mxGetImagData(mxArray*mxarray);
//Data setters
void mxSetPr(mxArray*mxarray, double*data);
void mxSetPi(mxArray*mxarray, double*data);
void mxSetImagData(mxArray*mxarray, void*data);
void mxSetData(mxArray*mxarray, void*data);
//Constructors
mxArray* mxCreateCellArray(mwSize ndims, const mwSize*dims);
mxArray* mxCreateCellMatrix(mwSize m, mwSize n);
mxArray* mxCreateCharArray(mwSize ndims, const mwSize*dims);
mxArray* mxCreateCharMatrix(mwSize m, mwSize n);
mxArray* mxCreateCharMatrixFromStrings(mwSize m, const char**str);
mxArray* mxCreateDoubleMatrix(mwSize m, mwSize n, mxComplexity flag);
mxArray* mxCreateDoubleScalar(double val);
mxArray* mxCreateLogicalArray(mxLogical val);
mxArray* mxCreateLogicalMatrix(mwSize m, mwSize n);
mxArray* mxCreateLogicalScalar(mxLogical val);
mxArray* mxCreateNumericArray(mwSize ndims, mwSize* dims, mxClassID classId,
		mxComplexity flag);
mxArray* mxCreateNumericMatrix(mwSize m, mwSize n, mxClassID classId,
		mxComplexity flag);

mxArray* mxCreateString(const char *str);
//mxArray* mxCreateStructArray(mwSize ndims, const mwSize*dims, int num_keys,
//		const char** keys);
//mxArray* mxCreateStructMatrix(mwSize rows, mwSize cols, int num_keys,
//		const char** keys);
//mxArray* mxCreateSparse(mwSize m, mwSize n , mwSize nzmax, mxComplexity flag);
//mxArray* mxCreateSparseLogicalMatrix(mwSize m, mwSize n, mwSize nzmax);
#endif /* MEX_H_ */
