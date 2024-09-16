#include "dlgDe01.h"

//(*InternalHeaders(dlgDe01)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(dlgDe01)
const long dlgDe01::ID_STATICTEXT1 = wxNewId();
const long dlgDe01::ID_TEXTCTRL1 = wxNewId();
const long dlgDe01::ID_STATICTEXT2 = wxNewId();
const long dlgDe01::ID_TEXTCTRL2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(dlgDe01,wxDialog)
	//(*EventTable(dlgDe01)
	//*)
END_EVENT_TABLE()

dlgDe01::dlgDe01(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(dlgDe01)
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer3;
	wxBoxSizer* BoxSizer4;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxSYSTEM_MENU|wxRESIZE_BORDER, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer4 = new wxBoxSizer(wxVERTICAL);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	BoxSizer4->Add(StaticText1, 0, wxALL|wxEXPAND, 1);
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, _("Text"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	BoxSizer4->Add(TextCtrl1, 0, wxALL|wxEXPAND, 1);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	BoxSizer4->Add(StaticText2, 0, wxALL|wxEXPAND, 1);
	TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, _("Text"), wxDefaultPosition, wxSize(194,24), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	BoxSizer4->Add(TextCtrl2, 0, wxALL|wxEXPAND, 1);
	BoxSizer3->Add(BoxSizer4, 1, wxALL|wxEXPAND, 5);
	BoxSizer2->Add(BoxSizer3, 1, wxALL|wxEXPAND, 5);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxEXPAND, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);
	//*)
}

dlgDe01::~dlgDe01()
{
	//(*Destroy(dlgDe01)
	//*)
}

