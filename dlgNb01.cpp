#include "dlgNb01.h"
#include "zDB01.h"

zDB01 rdb;

//(*InternalHeaders(dlgNb01)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(dlgNb01)
const long dlgNb01::ID_LISTBOX1 = wxNewId();
const long dlgNb01::ID_PANEL1 = wxNewId();
const long dlgNb01::ID_LISTBOX2 = wxNewId();
const long dlgNb01::ID_PANEL2 = wxNewId();
const long dlgNb01::ID_NOTEBOOK1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(dlgNb01,wxDialog)
    //(*EventTable(dlgNb01)
    //*)
END_EVENT_TABLE()

dlgNb01::dlgNb01(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    //(*Initialize(dlgNb01)
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer3;
    wxBoxSizer* BoxSizer4;
    wxBoxSizer* BoxSizer5;

    Create(parent, id, _("Favorite Links App"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxSYSTEM_MENU|wxRESIZE_BORDER, _T("id"));
    SetClientSize(wxSize(365,250));
    Move(wxDefaultPosition);
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    nbk01 = new wxNotebook(this, ID_NOTEBOOK1, wxDefaultPosition, wxSize(232,142), wxNB_BOTTOM, _T("ID_NOTEBOOK1"));
    Panel1 = new wxPanel(nbk01, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    BoxSizer4 = new wxBoxSizer(wxVERTICAL);
    lbxCats = new wxListBox(Panel1, ID_LISTBOX1, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_LISTBOX1"));
    BoxSizer4->Add(lbxCats, 1, wxALL|wxEXPAND, 5);
    Panel1->SetSizer(BoxSizer4);
    BoxSizer4->Fit(Panel1);
    BoxSizer4->SetSizeHints(Panel1);
    Panel2 = new wxPanel(nbk01, ID_PANEL2, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    BoxSizer5 = new wxBoxSizer(wxVERTICAL);
    lbxLinks = new wxListBox(Panel2, ID_LISTBOX2, wxDefaultPosition, wxSize(340,180), 0, 0, 0, wxDefaultValidator, _T("ID_LISTBOX2"));
    BoxSizer5->Add(lbxLinks, 1, wxALL|wxEXPAND, 5);
    Panel2->SetSizer(BoxSizer5);
    BoxSizer5->Fit(Panel2);
    BoxSizer5->SetSizeHints(Panel2);
    nbk01->AddPage(Panel1, _("Categories"), false);
    nbk01->AddPage(Panel2, _("Links"), false);
    BoxSizer3->Add(nbk01, 1, wxALL|wxEXPAND, 5);
    BoxSizer2->Add(BoxSizer3, 1, wxALL|wxEXPAND, 5);
    BoxSizer1->Add(BoxSizer2, 1, wxALL|wxEXPAND, 5);
    SetSizer(BoxSizer1);
    SetSizer(BoxSizer1);
    Layout();

    Connect(ID_LISTBOX1,wxEVT_COMMAND_LISTBOX_SELECTED,(wxObjectEventFunction)&dlgNb01::OnlbxCatsSelect);
    Connect(ID_LISTBOX1,wxEVT_COMMAND_LISTBOX_DOUBLECLICKED,(wxObjectEventFunction)&dlgNb01::OnlbxCatsDClick);
    Connect(ID_LISTBOX2,wxEVT_COMMAND_LISTBOX_DOUBLECLICKED,(wxObjectEventFunction)&dlgNb01::OnlbxLinksDClick);
    //*)
}

dlgNb01::~dlgNb01()
{
    //(*Destroy(dlgNb01)
    //*)
}


void dlgNb01::OnlbxCatsSelect(wxCommandEvent& event)
{
}

void dlgNb01::OnlbxCatsDClick(wxCommandEvent& event)
{
    std::string zcat = event.GetString().ToStdString();
    rdb.listLinks(std::stoi(zcat.substr(0, zcat.find(" "))), false);
    lbxLinks->Clear();
    lbxLinks->InsertItems(rdb.lk2, 0);
    nbk01->SetSelection(1);
}

void dlgNb01::OnlbxLinksDClick(wxCommandEvent& event)
{
    std::string zcat = event.GetString().ToStdString();
//    rdb.listLinks(std::stoi(zcat.substr(0, zcat.find(" "))));
std::string cmd = "";
    rdb.getLink(std::stoi(zcat.substr(0, zcat.find(" "))));
    if (rdb.lk3[0].ToStdString().find("http") < rdb.lk3[0].length())
    {
        cmd = "/usr/lib/ghostery/Ghostery " + rdb.lk3[0].ToStdString();
    }
    else
    {
        cmd = rdb.lk3[0].ToStdString();
    }
    system(cmd.c_str());
    cmd = cmd;
}
