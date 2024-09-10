/***************************************************************
 * Name:      cppMD01Main.h
 * Purpose:   Defines Application Frame
 * Author:    Mr. Arch Brooks (arch@archbrooks.com)
 * Created:   Sunday, 08 September 2024 07:26:59
 * Copyright: Mr. Arch Brooks (https://archman.us)
 * License:
 **************************************************************/

#ifndef CPPMYSKEL1MAIN_H
#define CPPMYSKEL1MAIN_H
#include <mysql++.h>
#include <wx/grid.h>

//(*Headers(cppMD01Frame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/statusbr.h>
//*)

class cppMD01Frame: public wxFrame
{
public:

    cppMD01Frame(wxWindow* parent,wxWindowID id = -1);
    virtual ~cppMD01Frame();
    mysqlpp::Connection conn;
    wxGrid* masterGrid;
    wxGrid* detailGrid;

private:
    void PopulateMasterGrid();
    void LoadDetailData(long idlk1);
    void OnMasterGridCellClick(wxGridEvent& event);
    void OnCellClick(wxGridEvent& event);
    void OnMasterGridPopup(wxGridEvent& event);
    void OnDetailGridPopup(wxGridEvent& event);
    //void LoadDetailData(int idlk1);

    //(*Handlers(cppMD01Frame)
    void OnQuit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    //*)

    //(*Identifiers(cppMD01Frame)
    static const long ID_PANEL1;
    static const long ID_PANEL3;
    static const long idMenuQuit;
    static const long idMenuAbout;
    static const long ID_STATUSBAR1;
    static const long ID_MENUITEM1;
    static const long ID_MENUITEM2;
    //*)

    //(*Declarations(cppMD01Frame)
    wxMenu pumDetail;
    wxMenu pumMaster;
    wxMenuItem* MenuItem3;
    wxMenuItem* MenuItem4;
    wxPanel* Panel1;
    wxPanel* Panel2;
    wxStatusBar* StatusBar1;
    //*)

    DECLARE_EVENT_TABLE()
};

#endif // CPPMYSKEL1MAIN_H

