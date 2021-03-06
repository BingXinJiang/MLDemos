/*********************************************************************
MLDemos: A User-Friendly visualization toolkit for machine learning
Copyright (C) 2010  Basilio Noris
Contact: mldemos@b4silio.com

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public License,
version 3 as published by the Free Software Foundation.

This library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free
Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*********************************************************************/
#ifndef _REGRESSOR_GB_H_
#define _REGRESSOR_GB_H_

#include <vector>
#include "regressor.h"
#include "basicOpenCV.h"
#ifdef OPENCV3
#define CV_ROW_SAMPLE cv::ml::ROW_SAMPLE
class CvGBTreesParams
{
public:
    CvGBTreesParams(int, int, float, float, int, bool);
};

class CvGBTrees
{
public:
    enum{HUBER_LOSS, ABSOLUTE_LOSS, SQUARED_LOSS};
    void train(CvMat*, int, CvMat*, const CvMat*,const CvMat*,const CvMat*, const CvMat*, CvGBTreesParams){}
    float predict(CvMat*){return 0;}
};
#endif
class RegressorGB : public Regressor
{
private:
        int boostIters;
        int boostLossType;
        int boostTreeDepths;

        CvGBTrees* gbt;
public:
    RegressorGB();
    ~RegressorGB();
	void Train(std::vector< fvec > samples, ivec labels);
	fvec Test( const fvec &sample);
    const char *GetInfoString();

    void SetParams(int boostIters, int boostLossType, int boostTreeDepths);
};

#endif // _REGRESSOR_GB_H_


