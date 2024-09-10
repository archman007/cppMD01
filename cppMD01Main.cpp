/***************************************************************
 * Name:      cppMD01Main.cpp
 * Purpose:   Code for Application Frame
 * Author:    Mr. Arch Brooks (arch@archbrooks.com)
 * Created:   Sunday, 08 September 2024 07:26:59
 * Copyright: Mr. Arch Brooks (https://archman.us)
 * License:
 **************************************************************/

#include "cppMD01Main.h"
#include <wx/msgdlg.h>
#include <wx/grid.h>
#include <mysql++.h>
#include <mysql.h>
#include <wx/hyperlink.h>

//(*InternalHeaders(cppMD01Frame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat
{
    short_f, long_f
};

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(cppMD01Frame)
const long cppMD01Frame::ID_PANEL1 = wxNewId();
const long cppMD01Frame::ID_PANEL3 = wxNewId();
const long cppMD01Frame::idMenuQuit = wxNewId();
const long cppMD01Frame::idMenuAbout = wxNewId();
const long cppMD01Frame::ID_STATUSBAR1 = wxNewId();
const long cppMD01Frame::ID_MENUITEM1 = wxNewId();
const long cppMD01Frame::ID_MENUITEM2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(cppMD01Frame,wxFrame)
    //(*EventTable(cppMD01Frame)
    //*)
END_EVENT_TABLE()

cppMD01Frame::cppMD01Frame(wxWindow* parent,wxWindowID id)
{
    mysqlpp::Connection conn;
    //(*Initialize(cppMD01Frame)
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer3;
    wxBoxSizer* BoxSizer4;
    wxBoxSizer* BoxSizer5;
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE|wxSYSTEM_MENU|wxRESIZE_BORDER, _T("id"));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    BoxSizer4->Add(Panel1, 1, wxALL|wxEXPAND, 5);
    BoxSizer3->Add(BoxSizer4, 1, wxALL|wxEXPAND, 5);
    BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
    Panel2 = new wxPanel(this, ID_PANEL3, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL3"));
    BoxSizer5->Add(Panel2, 0, wxALL|wxEXPAND, 5);
    BoxSizer3->Add(BoxSizer5, 0, wxALL|wxEXPAND, 5);
    BoxSizer2->Add(BoxSizer3, 0, wxALL|wxEXPAND, 5);
    BoxSizer1->Add(BoxSizer2, 0, wxALL|wxEXPAND, 5);
    SetSizer(BoxSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    MenuItem3 = new wxMenuItem((&pumMaster), ID_MENUITEM1, _("Change Background Color"), wxEmptyString, wxITEM_NORMAL);
    pumMaster.Append(MenuItem3);
    MenuItem4 = new wxMenuItem((&pumDetail), ID_MENUITEM2, _("Change Background Color"), wxEmptyString, wxITEM_NORMAL);
    pumDetail.Append(MenuItem4);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&cppMD01Frame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&cppMD01Frame::OnAbout);
    //*)

    masterGrid = new wxGrid(this, wxID_ANY, wxDefaultPosition, wxSize(400, 600));
    masterGrid->CreateGrid(0, 3);
    masterGrid->SetColLabelValue(0, "Category ID");
    masterGrid->SetColLabelValue(1, "Category Name");
    masterGrid->SetColLabelValue(2, "Detailed Description");

    detailGrid = new wxGrid(this, wxID_ANY, wxPoint(400, 0), wxSize(400, 600));
    detailGrid->CreateGrid(0, 4);
    detailGrid->SetColLabelValue(0, "Link ID");
    detailGrid->SetColLabelValue(1, "Link Name");
    detailGrid->SetColLabelValue(2, "Link");
    detailGrid->SetColLabelValue(3, "Description");
    //BoxSizer4->Add(Panel1, 1, wxALL|wxEXPAND, 5);
    //Panel1->SetSizer(BoxSizer4);
    //BoxSizer5->Add(Panel2, 1, wxALL|wxEXPAND, 5);
    //Panel2->SetSizer(BoxSizer5);

    BoxSizer4->Add(masterGrid, 1, wxEXPAND | wxALL, 5);
    BoxSizer5->Add(detailGrid, 1, wxEXPAND | wxALL, 5);
    //Panel1->Add(masterGrid, 1, wxALL|wxEXPAND, 5);
    //Panel2->Add(detailGrid, 1, wxALL|wxEXPAND, 5);
    Layout();

    PopulateMasterGrid();
    detailGrid->Bind(wxEVT_GRID_CELL_LEFT_CLICK, &cppMD01Frame::OnCellClick, this);
    masterGrid->Bind(wxEVT_GRID_CELL_LEFT_CLICK, &cppMD01Frame::OnMasterGridCellClick, this);
    masterGrid->Bind(wxEVT_GRID_CELL_RIGHT_CLICK, &cppMD01Frame::OnMasterGridPopup, this);
    detailGrid->Bind(wxEVT_GRID_CELL_RIGHT_CLICK, &cppMD01Frame::OnDetailGridPopup, this);
    detailGrid->EnableEditing(true);

    //SetSizer(BoxSizer5);
    //SetSizer(BoxSizer4);
    //SetSizer(BoxSizer3);
    //SetSizer(BoxSizer2);
    //SetSizer(BoxSizer1);
    SetSizerAndFit(BoxSizer1);
    //BoxSizer1->Fit(this);
    LoadDetailData(0);
}

cppMD01Frame::~cppMD01Frame()
{
    //(*Destroy(cppMD01Frame)
    //*)
}

/**
 * @brief Populates the master grid with data from the MySQL database.
 *
 * This function establishes a connection to the MySQL database and retrieves
 * all records from the "lk1" table, ordered by the "cat" column. It then clears
 * the current contents of the master grid and appends rows to match the number
 * of records fetched from the database. The grid cells are populated with the
 * data retrieved from the database.
 *
 * @note This function assumes that the MySQL connection object `conn` and
 * the master grid object `masterGrid` are properly initialized.
 *
 * @warning If the database connection fails, the function will return
 * immediately and the grid will not be populated.
 */
void cppMD01Frame::PopulateMasterGrid()
{
    // Attempt to connect to the MySQL database
    if (!conn.connect("bcswebtools", "localhost", "bcs", "Peace007!amb"))
    {
        // Database connection failed, exit the function
        // wxWrite("Database connection failed.");
        return;
    }

    // Execute the SQL query to fetch all records from the 'lk1' table, ordered by 'cat'
    mysqlpp::Query query = conn.query("SELECT * FROM lk1 ORDER BY cat");
    mysqlpp::StoreQueryResult res = query.store();

    // Clear the current contents of the grid and append rows based on the number of records fetched
    masterGrid->ClearGrid();
    masterGrid->AppendRows(res.num_rows());

    // Populate the grid with data from the result set
    for (size_t i = 0; i < res.num_rows(); ++i)
    {
        masterGrid->SetCellValue(i, 0, res[i][0].c_str());  // Set cell value for column 0
        masterGrid->SetCellValue(i, 1, res[i][1].c_str());  // Set cell value for column 1
        masterGrid->SetCellValue(i, 2, res[i][2].c_str());  // Set cell value for column 2
    }
}

/**
 * @brief Event handler for cell clicks in a wxGrid.
 *
 * This function is triggered when a cell in the wxGrid is clicked. It retrieves the value of the clicked cell.
 * If the value starts with "http", it attempts to open the URL in the default browser.
 *
 * @param event Reference to the wxGridEvent triggered by the cell click.
 */
void cppMD01Frame::OnCellClick(wxGridEvent& event)
{
    // Get the grid from the event
    wxGrid* grid = static_cast<wxGrid*>(event.GetEventObject());

    // Get the clicked cell's row and column
    int row = event.GetRow();
    int col = event.GetCol();

    // Retrieve the cell value as a wxString
    wxString cellValue = grid->GetCellValue(row, col);

    // Check if the cell value starts with "http"
    if (cellValue.StartsWith("http"))
    {
        // Open the URL in the default web browser
        wxLaunchDefaultBrowser(cellValue);
    }

    // Allow the event to continue to be processed
    event.Skip();
}

/**
 * @brief Event handler for the "Quit" command.
 *
 * This function is triggered when the user selects the "Quit" option in the menu.
 * It closes the application window.
 *
 * @param event The wxCommandEvent object containing event details.
 */
void cppMD01Frame::OnQuit(wxCommandEvent& event)
{
    Close();
}

/**
 * @brief Handles the "About" menu command event.
 *
 * This function is called when the "About" menu item is selected.
 * It retrieves the build information and displays it in a message box.
 *
 * @param event The command event associated with the "About" menu item.
 */
void cppMD01Frame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);  ///< Retrieves build information.
    wxMessageBox(msg, _("Welcome to..."));  ///< Displays the build information in a message box.
}

/**
 * @brief Loads detailed data for a specific ID and populates a grid with the retrieved information.
 *
 * This method queries the database to retrieve data from the `lk2` table where the `idlk1` matches
 * the provided ID. The result set is then used to populate a grid, clearing any existing rows and
 * adding new rows as necessary.
 *
 * @param idlk1 The ID used to filter the `lk2` table in the query.
 *
 * Steps:
 * - Create a new query using the database connection.
 * - Execute the query to select `idlk2`, `lkn`, `lnk`, and `ddes` columns from the `lk2` table where `idlk1` matches the input.
 * - Clear the existing grid and delete any rows if present.
 * - Append rows to the grid equal to the number of results returned by the query.
 * - Populate the grid cells with the data from the query result set.
 * - Clear the result set after processing.
 */
void cppMD01Frame::LoadDetailData(long idlk1)
{
    mysqlpp::Query query = conn.query();
    query << "SELECT idlk2, lkn, lnk, ddes FROM lk2 WHERE idlk1 = " << idlk1 << " ORDER BY lkn";
    mysqlpp::StoreQueryResult res = query.store();

    detailGrid->ClearGrid();
    if (detailGrid->GetNumberRows() >= 1)
    {
        detailGrid->DeleteRows(0, detailGrid->GetNumberRows());
    }
    int nrow = res.num_rows();
    detailGrid->AppendRows(nrow);

    for (size_t i = 0; i < res.num_rows(); ++i)
    {
        detailGrid->SetCellValue(i, 0, res[i]["idlk2"].c_str());
        detailGrid->SetCellValue(i, 1, res[i]["lkn"].c_str());
        detailGrid->SetCellValue(i, 2, res[i]["lnk"].c_str());
        detailGrid->SetCellValue(i, 3, res[i]["ddes"].c_str());
    }
    res.clear();
    res.empty();
}

/**
 * Handles the event when a cell in the master grid is clicked.
 *
 * @param event The wxGridEvent object that contains event information.
 *
 * Retrieves the row index of the clicked cell, extracts the value from the first column
 * of that row, converts it to a long integer, and then loads the detailed data associated
 * with the converted value.
 */
void cppMD01Frame::OnMasterGridCellClick(wxGridEvent& event)
{
    int row = event.GetRow(); // Get the row index of the clicked cell
    wxString idlk1Str = masterGrid->GetCellValue(row, 0); // Retrieve the cell value from the first column
    long idlk1;
    idlk1Str.ToLong(&idlk1); // Convert the cell value to a long integer
    LoadDetailData(idlk1); // Load detailed data based on the converted value
}

void cppMD01Frame::OnMasterGridPopup(wxGridEvent& event)
{
    PopupMenu(&pumMaster, event.GetPosition());

}
void cppMD01Frame::OnDetailGridPopup(wxGridEvent& event)
{
    PopupMenu(&pumDetail, event.GetPosition());

}
