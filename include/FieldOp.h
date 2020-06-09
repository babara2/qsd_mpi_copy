//   FieldOp.h -*- C++ -*- Operators for a harmonic oscillator mode.
//
//   Copyright (C) 1995  Todd Brun and Ruediger Schack
//
//   This program is free software; you can redistribute it and/or modify
//   it under the terms of the GNU General Public License as published by
//   the Free Software Foundation; either version 2 of the License, or
//   (at your option) any later version.
//
//   This program is distributed in the hope that it will be useful,
//   but WITHOUT ANY WARRANTY; without even the implied warranty of
//   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//   GNU General Public License for more details.
//
//   You should have received a copy of the GNU General Public License
//   along with this program; if not, write to the Free Software
//   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
//
//   ----------------------------------------------------------------------
//   If you improve the code or make additions to it, or if you have
//   comments or suggestions, please contact us:
//
//   Dr. Todd Brun			        Tel    +44 (0)171 775 3292
//   Department of Physics                      FAX    +44 (0)181 981 9465
//   Queen Mary and Westfield College           email  t.brun@qmw.ac.uk
//   Mile End Road, London E1 4NS, UK
//
//   Dr. Ruediger Schack                        Tel    +44 (0)1784 443097
//   Department of Mathematics                  FAX    +44 (0)1784 430766
//   Royal Holloway, University of London       email  r.schack@rhbnc.ac.uk
//   Egham, Surrey TW20 0EX, UK
/////////////////////////////////////////////////////////////////////////////

#ifndef _FieldOp_hhh
#define _FieldOp_hhh 1

#include "PrimOp.h"

class FieldTransitionOperator: public PrimaryOperator
//  |i><j|  (Transition from |j> to |i>)
{
public:
  FieldTransitionOperator() : PrimaryOperator(0,FIELD) {
    i=0; j=0;
#ifdef DEBUG_TRACE
    std::cout << "Instantiated FieldTransitionOperator(freedom=0, i=0, j=0)." << std::endl;
#endif
  };
  FieldTransitionOperator(int thei, int thej, int freedom=0) :
    PrimaryOperator(freedom,FIELD) {
      i=thei; j=thej;
#ifdef DEBUG_TRACE
      std::cout << "Instantiated FieldTransitionOperator(freedom="<<freedom<<", i="<<thei<<", j="<<thej<<")." << std::endl;
#endif
  };
  virtual void applyTo(State&,int,double);
private:
  int i;
  int j;
};

class AnnihilationOperator: public PrimaryOperator
{
  public:
    AnnihilationOperator() : PrimaryOperator(0,FIELD) {
#ifdef DEBUG_TRACE
      std::cout << "Instantiated AnnihilationOperator(freedom=0)." << std::endl;
#endif
    };
    AnnihilationOperator(int freedom) : PrimaryOperator(freedom,FIELD) {
#ifdef DEBUG_TRACE
      std::cout << "Instantiated AnnihilationOperator(freedom="<<freedom<<")." << std::endl;
#endif
    };
    virtual void applyTo(State&,int,double);
};

class LocalLower: public PrimaryOperator
{
  public:
    LocalLower() : PrimaryOperator(0,FIELD) {
#ifdef DEBUG_TRACE
      std::cout << "Instantiated LocalLower(freedom=0)." << std::endl;
#endif
    };
    LocalLower(int freedom) : PrimaryOperator(freedom,FIELD) {
#ifdef DEBUG_TRACE
      std::cout << "Instantiated LocalLower(freedom="<<freedom<<")." << std::endl;
#endif
    };
    virtual void applyTo(State&,int,double);
};

class CreationOperator: public PrimaryOperator
{
  public:
    CreationOperator(int=0) {
      error("CreationOperator not implemented. Use AnnihilationOperator::hc().");
    }
    virtual void applyTo(State&,int,double) {};
};

class NumberOperator: public PrimaryOperator
{
  public:
    NumberOperator() : PrimaryOperator(0,FIELD) {
#ifdef DEBUG_TRACE
      std::cout << "Instantiated NumberOperator(freedom=0)." << std::endl;
#endif
    };
    NumberOperator(int freedom) : PrimaryOperator(freedom,FIELD) {
#ifdef DEBUG_TRACE
      std::cout << "Instantiated NumberOperator(freedom="<<freedom<<")." << std::endl;
#endif
    };
    virtual void applyTo(State&,int,double);
};

class XOperator: public PrimaryOperator
{
  public:
    XOperator() : PrimaryOperator(0,FIELD) {
#ifdef DEBUG_TRACE
      std::cout << "Instantiated XOperator(freedom=0)." << std::endl;
#endif
    };
    XOperator(int freedom) : PrimaryOperator(freedom,FIELD) {
#ifdef DEBUG_TRACE
      std::cout << "Instantiated XOperator(freedom="<<freedom<<")." << std::endl;
#endif
    };
    virtual void applyTo(State&,int,double);
};

class POperator: public PrimaryOperator
{
  public:
    POperator() : PrimaryOperator(0,FIELD) {
#ifdef DEBUG_TRACE
      std::cout << "Instantiated POperator(freedom=0)." << std::endl;
#endif
    };
    POperator(int freedom) : PrimaryOperator(freedom,FIELD) {
#ifdef DEBUG_TRACE
      std::cout << "Instantiated POperator(freedom="<<freedom<<")." << std::endl;
#endif
    };
    virtual void applyTo(State&,int,double);
};

class DisplacementOperator: public PrimaryOperator
  //
  // Computes  exp( alpha*adag - conj(alpha)*a ) where a and adag are
  // annihilation and creation operators.
{
  public:
    DisplacementOperator() : PrimaryOperator(0,FIELD) {
      alpha=1.0; matrixSize=0; matrix=0; vv=0;
#ifdef DEBUG_TRACE
      std::cout << "Instantiated DisplacementOperator(freedom=0, alpha=1.0)." << std::endl;
#endif
    };
    DisplacementOperator(Complex theAlpha, int freedom=0)
      : PrimaryOperator(freedom,FIELD) {
        alpha=theAlpha; matrixSize=0; matrix=0; vv=0;
#ifdef DEBUG_TRACE
        std::cout << "Instantiated DisplacementOperator(freedom="<<freedom<<", alpha="<<theAlpha<<")." << std::endl;
#endif
      };
    virtual void applyTo(State&,int,double);
  private:
    Complex alpha;
    int matrixSize;
    Complex** matrix;
    Complex* vv;
};

class RealDisplacementOperator: public PrimaryOperator
  //
  // Computes  exp( alpha(adag - a) )  where alpha is real and
  // where a and adag are annihilation and creation operators.
{
  public:
    RealDisplacementOperator() : PrimaryOperator(0,FIELD) {
      alpha=1.0; matrixSize=0; matrix=0; vv=0;
#ifdef DEBUG_TRACE
      std::cout << "RealInstantiated DisplacementOperator(freedom=0, alpha=1.0)." << std::endl;
#endif
    };
    RealDisplacementOperator(double theAlpha, int freedom=0)
      : PrimaryOperator(freedom,FIELD) {
        alpha=theAlpha; matrixSize=0; matrix=0; vv=0;
#ifdef DEBUG_TRACE
        std::cout << "Instantiated DisplacementOperator(freedom="<<freedom<<", alpha="<<theAlpha<<")." << std::endl;
#endif
      };
    virtual void applyTo(State&,int,double);
  private:
    double alpha;
    int matrixSize;
    double** matrix;
    Complex* vv;
};

#endif
