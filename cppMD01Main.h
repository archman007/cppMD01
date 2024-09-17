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
#include "dlgXqt2.h"

//(*Headers(cppMD01Frame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/scrolwin.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
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
    std::string cmd;
    std::string mkVal;

private:
    void PopulateMasterGrid();
    void LoadDetailData(long idlk1);
    void OnMasterGridCellClick(wxGridEvent& event);
    void OnCellClick(wxGridEvent& event);
    void OnMasterGridPopup(wxGridEvent& event);
    void OnDetailGridPopup(wxGridEvent& event);
    void ListFiles(const wxString& dir, const wxString& filespec);
    void procLink();
    void procPdf();
    void procDoc();
    void procExe();
    void RefreshDetails();
    bool dRID = false;
//    void OnpumNewBlogPostSelected(wxCommandEvent& event);
    std::string defBro = "/usr/bin/brave";
    int row;
    void OnDetailGridCellClick(wxGridEvent& event);
    std::string recNo;

    //void LoadDetailData(int idlk1);

    //(*Handlers(cppMD01Frame)
    void OnQuit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnmenSelectCppSelected(wxCommandEvent& event);
    void OnpumAddDocsSelected(wxCommandEvent& event);
    void OnpumNewCatSelected(wxCommandEvent& event);
    void OnpumNewBlogPostSelected(wxCommandEvent& event);
    void OnpumDelLinkSelected(wxCommandEvent& event);
    void OnpumEdCatSelected(wxCommandEvent& event);
    void OnpumEditLinkSelected(wxCommandEvent& event);
    //*)

    //(*Identifiers(cppMD01Frame)
    static const long ID_STATICTEXT1;
    static const long ID_PANEL1;
    static const long ID_PANEL3;
    static const long ID_STATICTEXT2;
    static const long ID_SCROLLEDWINDOW1;
    static const long idMenucpp;
    static const long idMenuQuit;
    static const long idMenuAbout;
    static const long ID_STATUSBAR1;
    static const long ID_MENUITEM1;
    static const long idpumNewCat;
    static const long ID_PumEdCat;
    static const long ID_NewBlog;
    static const long ID_MENUITEM2;
    static const long ID_menAD;
    static const long ID_menNB;
    static const long ID_pumDel;
    //*)

    //(*Declarations(cppMD01Frame)
    wxMenu pumDetail;
    wxMenu pumMaster;
    wxMenuItem* MenuItem3;
    wxMenuItem* MenuItem4;
    wxMenuItem* MenuItem5;
    wxMenuItem* menNewPost;
    wxMenuItem* menSelectCpp;
    wxMenuItem* pumAddDocs;
    wxMenuItem* pumDelLink;
    wxMenuItem* pumNewBlogPost;
    wxMenuItem* pumNewCat;
    wxPanel* Panel1;
    wxPanel* Panel2;
    wxScrolledWindow* ScrolledWindow1;
    wxStaticText* StaticText1;
    wxStaticText* StaticText2;
    wxStatusBar* StatusBar1;
    //*)

    DECLARE_EVENT_TABLE()
};

#endif // CPPMYSKEL1MAIN_H

