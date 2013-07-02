/*
 * mxArray.cpp
 *
 *  Created on: Jun 18, 2013
 *      Author: sameer
 */
#include "mxArray.h"
//double* MxArray::getPr(){
//
// }
// double* getPi();
// double getScalar();
// mxChar* getChars();
// mxLogical getLogical();
//
// void* getData();
// void* getImagData();
//
// //Data setters
// void setPr(double*);
// void setPi(double*);
// void setImagData(void*);
// void setData(void*);

//Dimension Setters
void mxArray::setM(mwSize M) {
	dataobject->setM(M);
}
void mxArray::setN(mwSize N) {
	dataobject->setN(N);
}
void mxArray::setDimensions(const mwSize*dims, mwSize ndims) {
	dataobject->setDimensions(const_cast<long int*>((const long int*) dims),
			ndims);
}

//Dimension extractors
size_t mxArray::getM() {
	return dataobject->getDataSize()[0];
}
size_t mxArray::getN() {
	return dataobject->getDataSize()[1];
}
mwSize* mxArray::getDimensions() {
	return (mwSize*) dataobject->getDataSize();
}
mwSize mxArray::getNumberOfDimensions() {
	return dataobject->getNumDims();
}
size_t mxArray::getNumberOfElements() {
	return dataobject->getNumElems();
}

int mxArray::isCell() {
	return dataobject->getType() == DataObject::CELLARRAY;
}
int mxArray::isChar() {
	return dataobject->getType() == DataObject::CHARARRAY;
}
/*int isClass(char *name){

 }*/
int mxArray::isComplex() {
	return dataobject->getType() == DataObject::MATRIX_C128;
}
//TODO check in octave
int mxArray::isDouble() {
	return dataobject->getType() == DataObject::MATRIX_F64;
}

int mxArray::isFunctionHandle() {
	return dataobject->getType() == DataObject::FN_HANDLE;
}
/*int MxArray::isInt16(){
 return dataobject->getType()==DataObject::MATRIX_I32;
 }*/
int mxArray::isInt32() {
	return dataobject->getType() == DataObject::MATRIX_I32;
}
//int isInt64();
//int isInt8();
int mxArray::isLogical() {
	return dataobject->getType() == DataObject::LOGICALARRAY;
}
int mxArray::isNumeric() {
	return dataobject->getType() >= DataObject::MATRIX_C128
			&& dataobject->getType() <= DataObject::MATRIX_I32;
}
int mxArray::isSingle() {
	return dataobject->getType() == DataObject::MATRIX_F32;
}
//int isSparse();
int mxArray::isStruct() {
	return dataobject->getType() == DataObject::STRUCT_INST;
}

//size predicates
int mxArray::isEmpty() {
	return (int) dataobject->isEmpty();
}

//data extractors
double* mxArray::getPr() {
	return static_cast<double*>(dataobject->getData());
}
double* mxArray::getPi() {
	return static_cast<double*>(dataobject->getImagData());
}
double mxArray::getScalar() {
	return dataobject->getScalarDouble();
}
mxChar* mxArray::getChars() {
	return static_cast<mxChar*>(dataobject->getData());
}
mxLogical* mxArray::getLogical() {
	return static_cast<mxLogical*>(dataobject->getData());
}

void* mxArray::getData() {
	return dataobject->getData();
}
void* mxArray::getImagData() {
	return dataobject->getImagData();
}

//Data setters
void mxArray::setPr(double*data) {
	dataobject->setData(data);
}
void mxArray::setPi(double*data) {
	dataobject->setImagData(data);
}
void mxArray::setImagData(void*data) {
	dataobject->setImagData(data);
}
void mxArray::setData(void*data) {
	dataobject->setData(data);
}
//Constructors

