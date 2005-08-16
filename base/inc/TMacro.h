// @(#)root/base:$Name:  $:$Id: TMacro.h,v 1.1 2005/08/16 12:57:57 brun Exp $
// Author: Rene Brun   16/08/2005

/*************************************************************************
 * Copyright (C) 1995-2005, Rene Brun and Fons Rademakers.               *
 * All rights reserved.                                                  *
 *                                                                       *
 * For the licensing terms see $ROOTSYS/LICENSE.                         *
 * For the list of contributors see $ROOTSYS/README/CREDITS.             *
 *************************************************************************/

#ifndef ROOT_TMacro
#define ROOT_TMacro

//////////////////////////////////////////////////////////////////////////
//                                                                      //
// TMacro                                                               //
//                                                                      //
// class supporting a collection of lines with C++ code.                //
// A TMacro can be executed, saved to a ROOT file, edited, etc          //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

#ifndef ROOT_TNamed
#include "TNamed.h"
#endif
#ifndef ROOT_TList
#include "TList.h"
#endif
#ifndef ROOT_TObjString
#include "TObjString.h"
#endif

class TMacro : public TNamed {

protected:
    TList         *fLines;      //collection of lines
    TString        fParams;     //default string of macro parameters
    
public:

    TMacro();
    TMacro(const TMacro&);
    TMacro(const char *name, const char *title="");
    virtual ~TMacro();
    virtual TObjString  *AddLine(const char *text);
    virtual void         Browse(TBrowser *b);
    virtual TObjString  *GetLineWith(const char *text) const;
    virtual void         Exec(const char *params=0);  //*MENU*
    TList               *GetListOfLines() const {return fLines;}
    virtual void         Paint(Option_t *option="");
    virtual void         Print(Option_t *option="") const;
    virtual Int_t        ReadFile(const char *filename);
    virtual void         SaveSource(const char *filename);  //*MENU*
    virtual void         SavePrimitive(ofstream &out, Option_t *option);
    virtual void         SetParams(const char *params=0); //*MENU*
        
    ClassDef(TMacro,1)  //class supporting a collection of lines with C++ code.
};

#endif
