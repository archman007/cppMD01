#include "dlgNewLink.h"
#include "zDB01.h"
#include "curlStuff.h"
#include <boost/algorithm/string.hpp>

zDB01 db02;
curlStuff cs01;

//(*InternalHeaders(dlgNewLink)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(dlgNewLink)
const long dlgNewLink::ID_STATICTEXT1 = wxNewId();
const long dlgNewLink::ID_TEXTCTRL1 = wxNewId();
const long dlgNewLink::ID_STATICTEXT2 = wxNewId();
const long dlgNewLink::ID_TEXTCTRL2 = wxNewId();
const long dlgNewLink::ID_STATICTEXT3 = wxNewId();
const long dlgNewLink::ID_TEXTCTRL3 = wxNewId();
const long dlgNewLink::ID_STATICTEXT4 = wxNewId();
const long dlgNewLink::ID_TEXTCTRL4 = wxNewId();
const long dlgNewLink::ID_BUTTON1 = wxNewId();
const long dlgNewLink::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(dlgNewLink,wxDialog)
    //(*EventTable(dlgNewLink)
    //*)
END_EVENT_TABLE()

dlgNewLink::dlgNewLink(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    //(*Initialize(dlgNewLink)
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer3;
    wxBoxSizer* BoxSizer4;

    Create(parent, id, _("Insert New Link"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxSYSTEM_MENU|wxRESIZE_BORDER, _T("id"));
    SetClientSize(wxDefaultSize);
    Move(wxDefaultPosition);
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    BoxSizer3 = new wxBoxSizer(wxVERTICAL);
    lblidlk1 = new wxStaticText(this, ID_STATICTEXT1, _("Master Key"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    BoxSizer3->Add(lblidlk1, 0, wxALL|wxEXPAND, 1);
    edtPrim = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(331,24), wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    BoxSizer3->Add(edtPrim, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    lnlLinkName = new wxStaticText(this, ID_STATICTEXT2, _("Link Name"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    BoxSizer3->Add(lnlLinkName, 0, wxALL|wxEXPAND, 1);
    edtLinkName = new wxTextCtrl(this, ID_TEXTCTRL2, _("Text"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    BoxSizer3->Add(edtLinkName, 0, wxALL|wxEXPAND, 1);
    lblLink = new wxStaticText(this, ID_STATICTEXT3, _("Link"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    BoxSizer3->Add(lblLink, 0, wxALL|wxEXPAND, 1);
    edtLink = new wxTextCtrl(this, ID_TEXTCTRL3, _("Text"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    BoxSizer3->Add(edtLink, 0, wxALL|wxEXPAND, 1);
    lblDet = new wxStaticText(this, ID_STATICTEXT4, _("Detailed Description"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    BoxSizer3->Add(lblDet, 0, wxALL|wxEXPAND, 1);
    edtDetDes = new wxTextCtrl(this, ID_TEXTCTRL4, _("Note."), wxDefaultPosition, wxSize(339,112), wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL4"));
    BoxSizer3->Add(edtDetDes, 0, wxALL|wxEXPAND, 1);
    BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    btnInset = new wxButton(this, ID_BUTTON1, _("Insert"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer4->Add(btnInset, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    btnCancel = new wxButton(this, ID_BUTTON2, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    BoxSizer4->Add(btnCancel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3->Add(BoxSizer4, 0, wxALL|wxEXPAND, 1);
    BoxSizer2->Add(BoxSizer3, 1, wxALL|wxEXPAND, 5);
    BoxSizer1->Add(BoxSizer2, 1, wxALL|wxEXPAND, 5);
    SetSizer(BoxSizer1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&dlgNewLink::OnbtnInsetClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&dlgNewLink::OnbtnCancelClick);
    //*)

///   zrdb.initField(mkVal,dlg.edtPrim);
    db02.initField(db02.strIdlk1,edtPrim);
    //if db02.
    db02.initField(cs01.clipUrl(), edtLinkName);
    db02.initField(cs01.cbc, edtLink);
}

dlgNewLink::~dlgNewLink()
{
    //(*Destroy(dlgNewLink)
    //*)
}


void dlgNewLink::OnbtnInsetClick(wxCommandEvent& event)
{
    std::string buf = db02.fieldToString(edtLinkName);
    boost::replace_all(buf, "\"", "");
    boost::replace_all(buf, "amp;", "");
    db02.insertLink(db02.fieldToString(edtPrim), buf, db02.fieldToString(edtLink), db02.fieldToString(edtDetDes));
    EndModal(wxID_OK);
}

void dlgNewLink::OnbtnCancelClick(wxCommandEvent& event)
{
    EndModal(wxID_CANCEL);
}
