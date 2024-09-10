/***************************************************************
 * Name:      cppMD01App.cpp
 * Purpose:   Code for Application Class
 * Author:    Mr. Arch Brooks (arch@archbrooks.com)
 * Created:   Sunday, 08 September 2024 07:26:59
 * Copyright: Mr. Arch Brooks (https://archman.us)
 * License:
 **************************************************************/

#include "cppMD01App.h"

//(*AppHeaders
#include "cppMD01Main.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(cppMD01App);

bool cppMD01App::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	cppMD01Frame* Frame = new cppMD01Frame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}

