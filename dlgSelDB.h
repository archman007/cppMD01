#ifndef DLGSELDB_H
#define DLGSELDB_H

//(*Headers(dlgSelDB)
#include <wx/dialog.h>
#include <wx/listbox.h>
#include <wx/sizer.h>
//*)

class dlgSelDB: public wxDialog
{
	public:

		dlgSelDB(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~dlgSelDB();
//		wxString db;
		std::string buf;

		//(*Declarations(dlgSelDB)
		wxListBox* lbxDbNames;
		//*)

	protected:

		//(*Identifiers(dlgSelDB)
		static const long ID_LISTBOX1;
		//*)

	private:

		//(*Handlers(dlgSelDB)
		void OnlbxDbNamesDClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
