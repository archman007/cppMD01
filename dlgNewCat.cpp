#include "dlgNewCat.h"
#include "zDB01.h"

zDB01 db01;

//(*InternalHeaders(dlgNewCat)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(dlgNewCat)
const long dlgNewCat::ID_STATICTEXT1 = wxNewId();
const long dlgNewCat::ID_TEXTCTRL1 = wxNewId();
const long dlgNewCat::ID_STATICTEXT2 = wxNewId();
const long dlgNewCat::ID_TEXTCTRL2 = wxNewId();
const long dlgNewCat::ID_BUTTON1 = wxNewId();
const long dlgNewCat::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(dlgNewCat,wxDialog)
    //(*EventTable(dlgNewCat)
    //*)
END_EVENT_TABLE()

dlgNewCat::dlgNewCat(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    //(*Initialize(dlgNewCat)
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer3;
    wxBoxSizer* BoxSizer4;

    Create(parent, id, _("Enter New Category"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxSYSTEM_MENU|wxRESIZE_BORDER, _T("id"));
    SetClientSize(wxDefaultSize);
    Move(wxDefaultPosition);
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    BoxSizer3 = new wxBoxSizer(wxVERTICAL);
    lblCat = new wxStaticText(this, ID_STATICTEXT1, _("Category"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    BoxSizer3->Add(lblCat, 0, wxALL|wxEXPAND, 1);
    edtCat = new wxTextCtrl(this, ID_TEXTCTRL1, _("Text"), wxDefaultPosition, wxSize(371,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    BoxSizer3->Add(edtCat, 0, wxALL|wxEXPAND, 1);
    lblMemo = new wxStaticText(this, ID_STATICTEXT2, _("Memo"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    BoxSizer3->Add(lblMemo, 0, wxALL|wxEXPAND, 1);
    edtMemo = new wxTextCtrl(this, ID_TEXTCTRL2, _("Text"), wxDefaultPosition, wxSize(371,87), wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    BoxSizer3->Add(edtMemo, 0, wxALL|wxEXPAND, 1);
    BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    btnInsert = new wxButton(this, ID_BUTTON1, _("Insert"), wxDefaultPosition, wxSize(217,33), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer4->Add(btnInsert, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
    btnCancel = new wxButton(this, ID_BUTTON2, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    BoxSizer4->Add(btnCancel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
    BoxSizer3->Add(BoxSizer4, 0, wxALL|wxEXPAND, 1);
    BoxSizer2->Add(BoxSizer3, 1, wxALL|wxEXPAND, 5);
    BoxSizer1->Add(BoxSizer2, 1, wxALL|wxEXPAND, 5);
    SetSizer(BoxSizer1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&dlgNewCat::OnbtnInsertClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&dlgNewCat::OnbtnCancelClick);
    //*)
}

dlgNewCat::~dlgNewCat()
{
    //(*Destroy(dlgNewCat)
    //*)
}


void dlgNewCat::OnbtnInsertClick(wxCommandEvent& event)
{
    std::string butText = btnInsert->GetLabel().ToStdString();
    butText = butText;
    if (butText == "Insert")
    {
        std::string cat = db01.fieldToString(edtCat);
        std::string memo = db01.fieldToString(edtMemo);
        db01.insertCat(cat, memo);
        //   db02.insertLink(db02.fieldToString(edtPrim), db02.fieldToString(edtLinkName), db02.fieldToString(edtLink), db02.fieldToString(edtDetDes));

    }
    else
    {
        db01.editCat("",db01.fieldToString(edtCat), db01.fieldToString(edtMemo));
        db01.listCategories(false);

    }

//INSERT INTO `lk1`(`idlk1`, `cat`, `ddes`) VALUES ('[value-1]','[value-2]','[value-3]')
    EndModal(wxID_OK);

}

void dlgNewCat::OnbtnCancelClick(wxCommandEvent& event)
{
    EndModal(wxID_CANCEL);
}
