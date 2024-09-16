#include "dlgSelCat.h"
#include "zDB01.h"

//(*InternalHeaders(dlgSelCat)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(dlgSelCat)
const long dlgSelCat::ID_LISTBOX1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(dlgSelCat,wxDialog)
    //(*EventTable(dlgSelCat)
    //*)
END_EVENT_TABLE()

dlgSelCat::dlgSelCat(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    //(*Initialize(dlgSelCat)
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer3;

    Create(parent, id, _("Select A Category"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxSYSTEM_MENU|wxRESIZE_BORDER, _T("id"));
    SetClientSize(wxDefaultSize);
    Move(wxDefaultPosition);
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    BoxSizer3 = new wxBoxSizer(wxVERTICAL);
    ListBox1 = new wxListBox(this, ID_LISTBOX1, wxDefaultPosition, wxSize(256,287), 0, 0, 0, wxDefaultValidator, _T("ID_LISTBOX1"));
    BoxSizer3->Add(ListBox1, 1, wxALL|wxEXPAND, 5);
    BoxSizer2->Add(BoxSizer3, 1, wxALL|wxEXPAND, 5);
    BoxSizer1->Add(BoxSizer2, 1, wxALL|wxEXPAND, 5);
    SetSizer(BoxSizer1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_LISTBOX1,wxEVT_COMMAND_LISTBOX_DOUBLECLICKED,(wxObjectEventFunction)&dlgSelCat::OnListBox1DClick);
    //*)
    RefreshCats();
}

dlgSelCat::~dlgSelCat()
{
    //(*Destroy(dlgSelCat)
    //*)
}

zDB01 zdb1;

void dlgSelCat::RefreshCats()
{
    ListBox1->Clear();
    zdb1.listCategories(false);
    for (size_t i=0; i < zdb1.zres.num_rows(); i++)
    {
        ListBox1->Append(std::string(zdb1.zres[i]["idlk1"]) + " " + std::string(zdb1.zres[i]["cat"]));
        std::string cat = std::string(zdb1.zres[i]["cat"]);
    }
}

void dlgSelCat::OnListBox1DClick(wxCommandEvent& event)
{
    catltem = ListBox1->GetStringSelection().ToStdString();
    EndModal(wxID_OK);
}
