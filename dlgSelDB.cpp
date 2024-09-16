#include "dlgSelDB.h"
#include "zDB01.h"



//(*InternalHeaders(dlgSelDB)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(dlgSelDB)
const long dlgSelDB::ID_LISTBOX1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(dlgSelDB,wxDialog)
    //(*EventTable(dlgSelDB)
    //*)
END_EVENT_TABLE()
dlgSelDB::dlgSelDB(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    //(*Initialize(dlgSelDB)
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer3;

    Create(parent, id, _("Select Database"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxSYSTEM_MENU|wxRESIZE_BORDER, _T("id"));
    SetClientSize(wxSize(-1,-1));
    Move(wxDefaultPosition);
    SetMaxSize(wxSize(-1,-1));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    lbxDbNames = new wxListBox(this, ID_LISTBOX1, wxDefaultPosition, wxSize(358,256), 0, 0, 0, wxDefaultValidator, _T("ID_LISTBOX1"));
    BoxSizer3->Add(lbxDbNames, 1, wxALL|wxEXPAND, 5);
    BoxSizer2->Add(BoxSizer3, 1, wxALL|wxEXPAND, 5);
    BoxSizer1->Add(BoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(BoxSizer1);
    SetSizer(BoxSizer1);
    Layout();

    Connect(ID_LISTBOX1,wxEVT_COMMAND_LISTBOX_DOUBLECLICKED,(wxObjectEventFunction)&dlgSelDB::OnlbxDbNamesDClick);
    //*)
}

dlgSelDB::~dlgSelDB()
{
    //(*Destroy(dlgSelDB)
    //*)
}


void dlgSelDB::OnlbxDbNamesDClick(wxCommandEvent& event)
{
    buf = lbxDbNames->GetStringSelection().ToStdString();
    EndModal(wxID_OK);
}
