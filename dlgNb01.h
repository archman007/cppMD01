#ifndef DLGNB01_H
#define DLGNB01_H

//(*Headers(dlgNb01)
#include <wx/dialog.h>
#include <wx/listbox.h>
#include <wx/notebook.h>
#include <wx/panel.h>
#include <wx/sizer.h>
//*)

class dlgNb01: public wxDialog
{
	public:

		dlgNb01(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~dlgNb01();
		int curCat;

		//(*Declarations(dlgNb01)
		wxListBox* lbxCats;
		wxListBox* lbxLinks;
		wxNotebook* nbk01;
		wxPanel* Panel1;
		wxPanel* Panel2;
		//*)

	protected:

		//(*Identifiers(dlgNb01)
		static const long ID_LISTBOX1;
		static const long ID_PANEL1;
		static const long ID_LISTBOX2;
		static const long ID_PANEL2;
		static const long ID_NOTEBOOK1;
		//*)

	private:

		//(*Handlers(dlgNb01)
		void OnlbxCatsSelect(wxCommandEvent& event);
		void OnlbxCatsDClick(wxCommandEvent& event);
		void OnlbxLinksDClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
