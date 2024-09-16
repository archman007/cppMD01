#include "dlgXqt2.h"

//(*InternalHeaders(dlgXqt2)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(dlgXqt2)
const long dlgXqt2::ID_RADIOBOX1 = wxNewId();
const long dlgXqt2::ID_BUTTON1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(dlgXqt2,wxDialog)
	//(*EventTable(dlgXqt2)
	//*)
END_EVENT_TABLE()

dlgXqt2::dlgXqt2(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(dlgXqt2)
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer3;

	Create(parent, id, _("Select Style"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxSYSTEM_MENU|wxRESIZE_BORDER, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer3 = new wxBoxSizer(wxVERTICAL);
	wxString __wxRadioBoxChoices_1[4] =
	{
		_("Web"),
		_("PDF"),
		_("Document"),
		_("Executable")
	};
	rbtRadBut = new wxRadioBox(this, ID_RADIOBOX1, _("Process To Acomodate"), wxDefaultPosition, wxSize(304,52), 4, __wxRadioBoxChoices_1, 1, 0, wxDefaultValidator, _T("ID_RADIOBOX1"));
	BoxSizer3->Add(rbtRadBut, 1, wxALL|wxEXPAND, 5);
	butCancel = new wxButton(this, ID_BUTTON1, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer3->Add(butCancel, 0, wxALL|wxEXPAND, 1);
	BoxSizer2->Add(BoxSizer3, 1, wxALL|wxEXPAND, 5);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_RADIOBOX1,wxEVT_COMMAND_RADIOBOX_SELECTED,(wxObjectEventFunction)&dlgXqt2::OnrbtRadButSelect);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&dlgXqt2::OnbutCancelClick);
	//*)
}

dlgXqt2::~dlgXqt2()
{
	//(*Destroy(dlgXqt2)
	//*)
}

void dlgXqt2::OnbutCancelClick(wxCommandEvent& event)
{
    isel = -1;
    EndModal(wxID_CANCEL);
}

void dlgXqt2::OnrbtRadButSelect(wxCommandEvent& event)
{
    isel = event.GetSelection();
    EndModal(wxID_OK);
}

