/*
 * mxArray.h
 *
 *  Created on: Jun 14, 2013
 *      Author: sameer
 */

#ifndef MXARRAY_H_
#define MXARRAY_H_
#include"objects.h"
#include"cellarrayobj.h"
#include"chararrayobj.h"
//#include"matrixobjs.h"
//define types for Mex.
typedef char mxChar;
typedef bool mxLogical;
typedef size_t mwSize;
typedef size_t mwIndex;

typedef enum mxComplexity {
	mxREAL, mxCOMPLEX
} mxComplexity;
typedef enum {
	mxUNKNOWN_CLASS = 0,
	mxCELL_CLASS,
	mxSTRUCT_CLASS,
	mxLOGICAL_CLASS,
	mxCHAR_CLASS,
	mxUNUSED_CLASS,
	mxDOUBLE_CLASS,
	mxSINGLE_CLASS,
	mxINT8_CLASS,
	mxUINT8_CLASS,
	mxINT16_CLASS,
	mxUINT16_CLASS,
	mxINT32_CLASS,
	mxUINT32_CLASS,
	mxINT64_CLASS,
	mxUINT64_CLASS,
	mxFUNCTION_CLASS
} mxClassID;

class mxArray: public gc {
	// virtual Destructor. declared since the class contains virtual methods.
	virtual ~mxArray()=0;
public:
	//data extractors
	double* getPr();
	double* getPi();
	double getScalar();
	mxChar* getChars();
	mxLogical* getLogical();

	void* getData();
	void* getImagData();

	//Data setters
	void setPr(double*);
	void setPi(double*);
	void setImagData(void*);
	void setData(void*);

	//Dimension Setters
	void setM(mwSize M);
	void setN(mwSize N);
	void setDimensions(const mwSize*, mwSize ndims);

	//Dimension extractors
	size_t getM();
	size_t getN();
	mwSize* getDimensions();
	mwSize getNumberOfDimensions();
	size_t getNumberOfElements();

	//type Predicates
	int isCell();
	int isChar();
	int isClass(char *name);
	int isComplex();
	int isDouble();
	int isFunctionHandle();
	int isInt16();
	int isInt32();
	int isInt64();
	int isInt8();
	int isLogical();
	int isNumeric();
	int isSingle();
	int isSparse();
	int isStruct();

	//size predicate
	int isEmpty();
	//classes
	mxClassID getClassID();
	const char* mxGetClassName();
	void setClassName(const char* name);
	mxArray* getCell(mwIndex *val);

	//floating point predicates
	int isFinite(double v);
	int isInf(double v);
	int isNaN(double v);

	//floating point values
	double getEps();
	double getInf();
	double getNaN();

	//constructors
	mxArray(mwSize row, mwSize col, mxComplexity complexity = mxREAL,
			mxClassID classId = mxUNKNOWN_CLASS) {
		id = classId;
		switch (classId) {
		case mxUNKNOWN_CLASS:
#ifdef DEBUG
			cout<<"class id unknown"<<std::endl;
#endif

			break;
		case mxCELL_CLASS:
#ifdef DEBUG
			cout<<"cell array constructor invoked"<<std::endl;
#endif
			dataobject = new CellArrayObj(row, col);
			break;

		case mxSTRUCT_CLASS:
#ifdef DEBUG
			cout<<"struct class not supported "<<std::endl;
#endif
			break;
		case mxLOGICAL_CLASS:
#ifdef DEBUG
			cout<<"Still have to figure out what is to be done for the logical class"<<std::endl;
#endif
			dataobject = new LogicalArrayObj(row, col);
			break;
		case mxCHAR_CLASS:
#ifdef DEBUG
			cout<<"Char class constructor invoked "<<std::endl;
#endif
			dataobject = new MatrixObj<char>(row, col);
			break;

		case mxUNUSED_CLASS:
#ifdef DEBUG
			cout<<"unused class not supported"<<std::endl;
#endif
			break;
		case mxDOUBLE_CLASS:
#ifdef DEBUG
			cout<<"Double Matrix Constructor invoked"<<std::endl;
#endif
			if (complexity == mxREAL) {
				dataobject = new MatrixObj<float64>(row, col);
			} else if (complexity == mxCOMPLEX) {
				dataobject = new MatrixObj<Complex128>(row, col);
			}
			break;
		case mxSINGLE_CLASS:
#ifdef DEBUG
			cout<<"Single Precision  Matrix Constructor invoked"<<std::endl;
#endif
			if (complexity == mxREAL) {
				dataobject = new MatrixObj<float32>(row, col);
			} else if (complexity == mxCOMPLEX) {
				dataobject = new MatrixObj<Complex64>(row, col);
			}
			break;
		case mxINT32_CLASS:
#ifdef DEBUG
			cout<<"32 bit Integer Matrix Constructor invoked"<<std::endl;
#endif
			dataobject = new MatrixObj<int>(row, col);

			break;
//TODO: other integers to be supported
		default:
#ifdef DEBUG
			cout<<"Ended up with something that was not supported"<<std::endl;
#endif
			break;
		}
	}
	mxArray(mwSize ndims, mwSize *dims, mxClassID classId, mxComplexity flag) {
		id = classId;
		switch (classId) {
		case mxUNKNOWN_CLASS:
#ifdef DEBUG
			cout<<"class id unknown"<<std::endl;
#endif

			break;
		case mxCELL_CLASS:
#ifdef DEBUG
			cout<<"cell array constructor invoked"<<std::endl;
#endif

			dataobject = new CellArrayObj(DimVector(dims, dims + ndims));
			break;

		case mxSTRUCT_CLASS:
#ifdef DEBUG
			cout<<"struct class not supported "<<std::endl;
#endif
			break;
		case mxLOGICAL_CLASS:
#ifdef DEBUG
			cout<<"Still have to figure out what is to be done for the logical class"<<std::endl;
#endif
			dataobject = new LogicalArrayObj(DimVector(dims, dims + ndims));
			break;
		case mxCHAR_CLASS:
#ifdef DEBUG
			cout<<"Char class constructor invoked "<<std::endl;
#endif
			dataobject = new MatrixObj<char>(DimVector(dims, dims + ndims));
			break;

		case mxUNUSED_CLASS:
#ifdef DEBUG
			cout<<"unused class not supported"<<std::endl;
#endif
			break;
		case mxDOUBLE_CLASS:
#ifdef DEBUG
			cout<<"Double Matrix Constructor invoked"<<std::endl;
#endif
			if (flag == mxREAL) {
				dataobject = new MatrixObj<float64>(
						DimVector(dims, dims + ndims));
			} else if (flag == mxCOMPLEX) {
				dataobject = new MatrixObj<Complex128>(
						DimVector(dims, dims + ndims));
			}
			break;
		case mxSINGLE_CLASS:
#ifdef DEBUG
			cout<<"Single Precision  Matrix Constructor invoked"<<std::endl;
#endif
			if (flag == mxREAL) {
				dataobject = new MatrixObj<float32>(
						DimVector(dims, dims + ndims));
			} else if (flag == mxCOMPLEX) {
				dataobject = new MatrixObj<Complex64>(
						DimVector(dims, dims + ndims));
			}
			break;
		case mxINT32_CLASS:
#ifdef DEBUG
			cout<<"32 bit Integer Matrix Constructor invoked"<<std::endl;
#endif
			dataobject = new MatrixObj<int>(DimVector(dims, dims + ndims));

			break;
			//TODO: other integers to be supported
		default:
#ifdef DEBUG
			cout<<"Ended up with something that was not supported"<<std::endl;
#endif
			break;
		}


	}
//interface to the interpreter
	const char* mexFunctionName();
private:
	DataObject* dataobject;
	mxClassID id;

};

#endif /* MXARRAY_H_ */
