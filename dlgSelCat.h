#ifndef DLGSELCAT_H
#define DLGSELCAT_H

//(*Headers(dlgSelCat)
#include <wx/dialog.h>
#include <wx/listbox.h>
#include <wx/sizer.h>
//*)

class dlgSelCat: public wxDialog
{
	public:

		dlgSelCat(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~dlgSelCat();
		void RefreshCats();
		std::string catltem;

		//(*Declarations(dlgSelCat)
		wxListBox* ListBox1;
		//*)

	protected:

		//(*Identifiers(dlgSelCat)
		static const long ID_LISTBOX1;
		//*)

	private:

		//(*Handlers(dlgSelCat)
		void OnListBox1DClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
