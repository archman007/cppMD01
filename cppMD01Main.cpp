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
#include <wx/filedlg.h>
#include <wx/log.h>
#include <boost/filesystem.hpp>
#include <boost/algorithm/string.hpp>
namespace fs = boost::filesystem;
#include "dlgXqt2.h"
#include "dlgNewLink.h"
#include "zDB01.h"
#include "bcsGui.h"
#include "dlgSelDB.h"
#include "dlgNewCat.h"
#include "wx/clipbrd.h"
#include "dlgSelCat.h"
//#include "dlg"

//(*InternalHeaders(cppMD01Frame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat
{
    short_f, long_f
};

zDB01 zrdb;
bcsGui gui01;

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
const long cppMD01Frame::ID_STATICTEXT1 = wxNewId();
const long cppMD01Frame::ID_PANEL1 = wxNewId();
const long cppMD01Frame::ID_PANEL3 = wxNewId();
const long cppMD01Frame::ID_STATICTEXT2 = wxNewId();
const long cppMD01Frame::ID_SCROLLEDWINDOW1 = wxNewId();
const long cppMD01Frame::idMenucpp = wxNewId();
const long cppMD01Frame::idMenuQuit = wxNewId();
const long cppMD01Frame::idMenuAbout = wxNewId();
const long cppMD01Frame::ID_STATUSBAR1 = wxNewId();
const long cppMD01Frame::ID_MENUITEM1 = wxNewId();
const long cppMD01Frame::idpumNewCat = wxNewId();
const long cppMD01Frame::ID_PumEdCat = wxNewId();
const long cppMD01Frame::ID_NewBlog = wxNewId();
const long cppMD01Frame::ID_MENUITEM2 = wxNewId();
const long cppMD01Frame::ID_menAD = wxNewId();
const long cppMD01Frame::ID_menNB = wxNewId();
const long cppMD01Frame::ID_pumDel = wxNewId();
const long cppMD01Frame::ID_pumEL = wxNewId();
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

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE|wxSYSTEM_MENU|wxRESIZE_BORDER|wxMAXIMIZE_BOX|wxMINIMIZE_BOX|wxFULL_REPAINT_ON_RESIZE, _T("id"));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer3 = new wxBoxSizer(wxVERTICAL);
    BoxSizer4 = new wxBoxSizer(wxVERTICAL);
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Label"), wxPoint(8,0), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    BoxSizer4->Add(Panel1, 1, wxALL|wxEXPAND, 5);
    BoxSizer3->Add(BoxSizer4, 1, wxALL|wxEXPAND, 5);
    BoxSizer5 = new wxBoxSizer(wxVERTICAL);
    Panel2 = new wxPanel(this, ID_PANEL3, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL3"));
    BoxSizer5->Add(Panel2, 0, wxALL|wxEXPAND, 5);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Label"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE, _T("ID_STATICTEXT2"));
    BoxSizer5->Add(StaticText2, 0, wxALL|wxEXPAND, 5);
    BoxSizer3->Add(BoxSizer5, 0, wxALL|wxEXPAND, 5);
    ScrolledWindow1 = new wxScrolledWindow(this, ID_SCROLLEDWINDOW1, wxDefaultPosition, wxSize(11,7), wxVSCROLL|wxHSCROLL, _T("ID_SCROLLEDWINDOW1"));
    BoxSizer3->Add(ScrolledWindow1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2->Add(BoxSizer3, 0, wxALL|wxEXPAND, 5);
    BoxSizer1->Add(BoxSizer2, 0, wxALL|wxEXPAND, 5);
    SetSizer(BoxSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    menSelectCpp = new wxMenuItem(Menu1, idMenucpp, _("Select c++ file to compile"), _("Compile c++"), wxITEM_NORMAL);
    Menu1->Append(menSelectCpp);
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, wxFULL_REPAINT_ON_RESIZE, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -300 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    MenuItem3 = new wxMenuItem((&pumMaster), ID_MENUITEM1, _("Change Background Color"), wxEmptyString, wxITEM_NORMAL);
    pumMaster.Append(MenuItem3);
    pumNewCat = new wxMenuItem((&pumMaster), idpumNewCat, _("Enter New Category"), _("Enter New Category"), wxITEM_NORMAL);
    pumMaster.Append(pumNewCat);
    pumEdCat = new wxMenuItem((&pumMaster), ID_PumEdCat, _("Edit Category"), _("Edit This Category"), wxITEM_NORMAL);
    pumMaster.Append(pumEdCat);
    pumNewBlogPost = new wxMenuItem((&pumMaster), ID_NewBlog, _("Create New Blog Post"), _("Create A New Blog Post"), wxITEM_NORMAL);
    pumMaster.Append(pumNewBlogPost);
    MenuItem4 = new wxMenuItem((&pumDetail), ID_MENUITEM2, _("Change Background Color"), wxEmptyString, wxITEM_NORMAL);
    pumDetail.Append(MenuItem4);
    pumAddDocs = new wxMenuItem((&pumDetail), ID_menAD, _("addDocs"), _("Add  New Documents / Items"), wxITEM_NORMAL);
    pumDetail.Append(pumAddDocs);
    menNewPost = new wxMenuItem((&pumDetail), ID_menNB, _("Create New Blog Post"), _("New Blog Post Now!"), wxITEM_NORMAL);
    pumDetail.Append(menNewPost);
    pumDelLink = new wxMenuItem((&pumDetail), ID_pumDel, _("Delete Link"), _("Delete A Item"), wxITEM_NORMAL);
    pumDetail.Append(pumDelLink);
    pumEditLinl = new wxMenuItem((&pumDetail), ID_pumEL, _("Edit Link"), _("Edit Link"), wxITEM_NORMAL);
    pumDetail.Append(pumEditLinl);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);
    Center();

    Connect(idMenucpp,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&cppMD01Frame::OnmenSelectCppSelected);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&cppMD01Frame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&cppMD01Frame::OnAbout);
    Connect(idpumNewCat,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&cppMD01Frame::OnpumNewCatSelected);
    Connect(ID_PumEdCat,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&cppMD01Frame::OnpumEdCatSelected);
    Connect(ID_NewBlog,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&cppMD01Frame::OnpumNewBlogPostSelected);
    Connect(ID_menAD,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&cppMD01Frame::OnpumAddDocsSelected);
    Connect(ID_menNB,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&cppMD01Frame::OnpumNewBlogPostSelected);
    Connect(ID_pumDel,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&cppMD01Frame::OnpumDelLinkSelected);
    Connect(ID_pumEL,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&cppMD01Frame::OnpumEditLinlSelected);
    //*)

    SetStatusText("Button Clicked!");


    masterGrid = new wxGrid(this, wxID_ANY, wxDefaultPosition, wxSize(1200, 300));
    masterGrid->CreateGrid(0, 3);
    masterGrid->SetColLabelValue(0, "Category ID");
    masterGrid->SetColLabelValue(1, "Category Name");
    masterGrid->SetColLabelValue(2, "Detailed Description");
    masterGrid->SetColSize(1, 500);
    masterGrid->SetColSize(2, 575);

    detailGrid = new wxGrid(this, wxID_ANY, wxPoint(400, 0), wxSize(1200, 500));
    detailGrid->CreateGrid(0, 4);
    detailGrid->SetColLabelValue(0, "Link ID");
    detailGrid->SetColLabelValue(1, "Link Name");
    detailGrid->SetColLabelValue(2, "Link");
    detailGrid->SetColLabelValue(3, "Description");
    detailGrid->SetColSize(1, 500);
    detailGrid->SetColSize(2, 300);
    detailGrid->SetColSize(3, 325);
    //BoxSizer4->Add(Panel1, 1, wxALL|wxEXPAND, 5);
    //Panel1->SetSizer(BoxSizer4);
    //BoxSizer5->Add(Panel2, 1, wxALL|wxEXPAND, 5);
    //Panel2->SetSizer(BoxSizer5);
    detailGrid->SetMaxSize(wxSize(-1, 150));  // Set the maximum height to 150
    BoxSizer4->Add(masterGrid, 0, wxEXPAND, 2);
    BoxSizer5->Add(detailGrid, 0, wxEXPAND, 2);
    //Panel1->Add(masterGrid, 1, wxALL|wxEXPAND, 5);
    //Panel2->Add(detailGrid, 1, wxALL|wxEXPAND, 5);
    Layout();

    PopulateMasterGrid();
    detailGrid->Bind(wxEVT_GRID_CELL_LEFT_CLICK, &cppMD01Frame::OnCellClick, this);
    masterGrid->Bind(wxEVT_GRID_CELL_LEFT_CLICK, &cppMD01Frame::OnMasterGridCellClick, this);
    //masterGrid->Bind(wxEVT_GRID_CELL_LEFT_CLICK, &cppMD01Frame::OnDetailGridCellClick, this);
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
 *OnMasterGridCellClick
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
    else if (cellValue.find(".pdf") != wxNOT_FOUND)
    {
        cmd = "okular \"";
        std::string tbuf;
        tbuf = cellValue.ToStdString();
        cmd = cmd + tbuf + "\"";
        system(cmd.c_str());
    }
    else if (cellValue.find(".odt")  != wxNOT_FOUND)
    {
        std::string pbuf =  "\"" + cellValue.ToStdString() + "\" & ";
        cmd = "openoffice4 -writer " + pbuf;
        system(cmd.c_str());
    }
    else
    {
        //system(cellValue.c_str());
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
    res.num_rows();
    if (res.num_rows() > 0)
    {
        wxString zlabel = std::to_string(res.num_rows()) + " Records Retrieved";
        SetStatusText(zlabel);

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
    else
    {
        int id = 1;
        wxCommandEvent event(wxEVT_COMMAND_BUTTON_CLICKED, id);
        //wxCommandEvent& event
        OnpumAddDocsSelected(event);

    }

//    StatusBar1->SetStatusText(zlabel), 0); // 0 is the field index for the first pane
    //StatusBar1->SetLabel(zlabel);

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
    row = event.GetRow(); // Get the row index of the clicked cell
    wxString idlk1Str = masterGrid->GetCellValue(row, 0); // Retrieve the cell value from the first column
    long idlk1;
    idlk1Str.ToLong(&idlk1); // Convert the cell value to a long integer
    mkVal = masterGrid->GetCellValue(row, 0);
    StaticText2->SetLabel(masterGrid->GetCellValue(row, 1));
    // StaticText2->SetWindowStyle(wxALIGN_CENTER);
    //StaticText2->Refresh(true);

//    StaticText2->Center(wxBOTH);
    LoadDetailData(idlk1); // Load detailed data based on the converted value
}

void cppMD01Frame::OnDetailGridCellClick(wxGridEvent& event)
{
    //row = event.GetRow(); // Get the row index of the clicked cell
//    wxString idlk1Str = detailGrid->GetCellValue(row, 0); // Retrieve the cell value from the first column
    //long idlk1;
    //idlk1Str.ToLong(&idlk1); // Convert the cell value to a long integer
    //mkVal = masterGrid->GetCellValue(row, 0);
    //StaticText2->SetLabel(masterGrid->GetCellValue(row, 1));
    // StaticText2->SetWindowStyle(wxALIGN_CENTER);
    //StaticText2->Refresh(true);

//    StaticText2->Center(wxBOTH);
    //LoadDetailData(idlk1); // Load detailed data based on the converted value
}

void cppMD01Frame::OnMasterGridPopup(wxGridEvent& event)
{
    PopupMenu(&pumMaster);

}
void cppMD01Frame::OnDetailGridPopup(wxGridEvent& event)
{
    PopupMenu(&pumDetail);

}

void cppMD01Frame::OnmenSelectCppSelected(wxCommandEvent& event)
{
    boost::filesystem::path p("/home/archman/workspace/cb/cpp/cppMD01/cppMD01.cpp");

    std::cout << "Root name: " << p.root_name() << '\n';
    std::cout << "Root directory: " << p.root_directory() << '\n';
    std::cout << "Root path: " << p.root_path() << '\n';
    std::cout << "Relative path: " << p.relative_path() << '\n';
    std::cout << "Parent path: " << p.parent_path() << '\n';
    std::cout << "Filename: " << p.filename() << '\n';
    std::cout << "Extension: " << p.extension() << '\n';

    wxFileDialog openFileDialog(this, _("Open file"), "", "",
                                "c++ files (*.cpp)|*.*", wxFD_OPEN | wxFD_FILE_MUST_EXIST);

    if (openFileDialog.ShowModal() == wxID_OK)
    {
        wxString filePath = openFileDialog.GetPath();
        wxString fileName = openFileDialog.GetFilename();

        wxLogMessage("File selected: %s", filePath);
        std::string path = "/home/user/documents/file.txt";
        std::vector<std::string> result;
        /*
                // Use boost::filesystem to get the path components
                boost::filesystem::path p(path);

                for (const auto& part : p)
                {
                    result.push_back(part.string());
                }

                // Output the exploded path components
                for (const auto& part : result)
                {
                    std::cout << part << std::endl;
                }
                */


    }
}

void cppMD01Frame::ListFiles(const wxString& dir, const wxString& filespec)
{
    wxArrayString *fileList;
    fileList->Clear();

    fs::path path = std::string(dir.mb_str());
    std::string spec = std::string(filespec.mb_str());

    if (fs::exists(path) && fs::is_directory(path))
    {
        for (const auto& entry : fs::directory_iterator(path))
        {
            if (fs::is_regular_file(entry))
            {
                std::string filename = entry.path().filename().string();

                // Apply filespec filtering
                if (boost::iends_with(filename, spec.substr(1)))    // "*.ext" -> "ext"
                {
                    fileList->Add(wxString::FromUTF8(filename));
                }
            }
        }
    }
}

void cppMD01Frame::OnpumAddDocsSelected(wxCommandEvent& event)
{
    dlgXqt2 dlg(NULL, wxID_ANY);
    if (dlg.ShowModal() == wxID_OK)
    {
        switch (dlg.isel)
        {
        case 0:
            procLink();
            break;
        case 1:
            procPdf();
            break;
        case 2:
            procDoc();
            break;
        case 3:
            procExe();
            break;
        default:

            //   to be executed if expression doesn't match any constant
            break;
        }
    }
}

void cppMD01Frame::procLink()
{
    dlgNewLink dlg(NULL, wxID_ANY);
    zrdb.initField(mkVal,dlg.edtPrim);

    if (dlg.ShowModal() == wxID_OK)
    {
        RefreshDetails();
    }
}

void cppMD01Frame::procPdf()
{
    dlgNewLink dlg(NULL, wxID_ANY);
    zrdb.initField(mkVal,dlg.edtPrim);
    int flags = wxFD_OPEN | wxFD_FILE_MUST_EXIST | wxFD_DEFAULT_STYLE;
    zrdb.initField(gui01.openFileDialog(NULL, "Select A File", "/home/archman/Documents", "", "*.pdf", flags),dlg.edtLink);
    if (dlg.ShowModal() == wxID_OK)
    {

    }
    RefreshDetails();

}

void cppMD01Frame::procDoc()
{
    dlgNewLink dlg(NULL, wxID_ANY);
    zrdb.initField(mkVal,dlg.edtPrim);
    int flags = wxFD_OPEN | wxFD_FILE_MUST_EXIST | wxFD_DEFAULT_STYLE;
    zrdb.initField(gui01.openFileDialog(NULL, "Select A Document", "/home/archman/Documents", "", "*.odt", flags),dlg.edtLink);
    if (dlg.ShowModal() == wxID_OK)
    {

    }
    RefreshDetails();
}

void cppMD01Frame::procExe()
{
    dlgNewLink dlg(NULL, wxID_ANY);
    zrdb.initField(mkVal,dlg.edtPrim);
    int flags = wxFD_OPEN | wxFD_FILE_MUST_EXIST | wxFD_DEFAULT_STYLE;
    zrdb.initField(gui01.openFileDialog(NULL, "Select A File", "/home/archman/workspace/cb/cpp", "", "", flags),dlg.edtLink);
    if (dlg.ShowModal() == wxID_OK)
    {

    }
    RefreshDetails();
}

void cppMD01Frame::RefreshDetails()
{
    zrdb.listLinks(std::stoi(mkVal), dRID);
    LoadDetailData(dRID);
    //StatusBar1->Refresh(true);

    /*
    ListBox2->Clear();
    zrdb.listLinks(std::stoi(mkVal), dRID);
    for (size_t i=0; i < zrdb.zres.num_rows(); i++)
    {
        ListBox2->Append(zrdb.lk2[i]);
    }
    string zlabel = std::to_string(zrdb.zres.num_rows()) + " Records Retrieved";
    lblStatus->SetLabel(zlabel);
    //    lblStatus->Label = zlabel;
    //    lblStatus->Update();
    //    lblStatus->Refresh();Blog
    */
}




void cppMD01Frame::OnpumNewCatSelected(wxCommandEvent& event)
{
    dlgNewCat dlg(NULL,wxID_ANY);
//    zrdb.initField(mkVal,dlg.edtPrim);
//    int flags = wxFD_OPEN | wxFD_FILE_MUST_EXIST | wxFD_DEFAULT_STYLE;
//    zrdb.initField(gui01.openFileDialog(NULL, "Select A File", "/home/archman/workspace/cb/cpp", "", "", flags),dlg.edtLink);
    if (dlg.ShowModal() == wxID_OK)
    {

    }
    RefreshDetails();
}

void cppMD01Frame::OnpumNewBlogPostSelected(wxCommandEvent& event)
{
    const char * c;
    string tbuf;
    tbuf = "<a href=\"https://archman.us\" target=\"_blank\" rel=\"noopener\">";
    tbuf = tbuf + "    <img src=\"https://archman.us/images/usa_3a.gif\" alt=\"USA\" />";
    tbuf = tbuf + "</a>\n\n";
    //tbuf = "<img src=\"http://archman.us/images/usa_3a.gif\" alt=\"\" />\n\n";
    tbuf = tbuf + "Mr. <a href=\"https://archman.us\" target=\"_blank\" rel=\"noopener\">Arch Brooks</a>, Software Engineer, Brooks Computing Systems, LLC authored this article.";
    if (wxTheClipboard->Open())
    {
        // This data objects are held by the clipboard,
        // so do not delete them in the app.
        c = tbuf.c_str();
        wxTheClipboard->SetData(new wxTextDataObject(c));
        wxTheClipboard->Close();
    }


    cmd = defBro + " " + "https://archman.us/b4/wp-admin/post-new.php & ";
    system(cmd.c_str());
}

void cppMD01Frame::OnpumDelLinkSelected(wxCommandEvent& event)
{
//    std::string detailtem = ListBox2->GetStringSelection().ToStdString();
//    std::string detailtem = detailGrid->GetRowAt(row);
    std::string cap;
    wxString idlk1Str = detailGrid->GetCellValue(row, 0);
    std::string detailItem = detailGrid->GetCellValue(row, 0).ToStdString();
    std::string linkName = detailGrid->GetCellValue(row, 1).ToStdString();
    //std::string recNo = detailtem.substr(0, detailtem.find(" "));
    cap = "Are You sure You would like to delete\n\"" + detailItem + " " + linkName + "\"?";
    if (gui01.yornQues(cap, "Delete This Record?") == wxYES)
    {
        zrdb.DeleteLink(detailItem);
        RefreshDetails();
    }
}

void cppMD01Frame::OnpumEdCatSelected(wxCommandEvent& event)
{
    dlgNewCat dlg(NULL, wxID_ANY);
//    std::string detailtem = ListBox1->GetStringSelection().ToStdString();
//    std::string recNo = detailtem.substr(0, detailtem.find(" "));
    std::string recNo = detailGrid->GetCellValue(row, 0).ToStdString();
    zrdb.strIdlk1 = recNo;
    dlg.btnInsert->SetLabel( "Edit");
    zrdb.getCat();
    zrdb.initField(masterGrid->GetCellValue(row, 1).ToStdString(), dlg.edtCat);
    zrdb.initField(masterGrid->GetCellValue(row, 2).ToStdString(), dlg.edtMemo);
//    zrdb.initField(std::string(zrdb.zres[0]["cat"]), dlg.edtCat);
//    zrdb.initField(std::string(zrdb.zres[0]["ddes"]), dlg.edtMemo);
    if (dlg.ShowModal() == wxID_OK)
    {
        zrdb.editCat(zrdb.strIdlk1, zrdb.fieldToString(dlg.edtCat), zrdb.fieldToString(dlg.edtMemo));
    }
    zrdb.listCategories(false);
//    RefreshCats();
    PopulateMasterGrid();
}

void cppMD01Frame::OnpumEditLinlSelected(wxCommandEvent& event)
{
//        std::string detailtem = ListBox2->GetStringSelection().ToStdString();
//    std::string recNo = detailtem.substr(0, detailtem.find(" "));
        std::string recNo = detailGrid->GetCellValue(row, 0).ToStdString();

    zrdb.insertMode = false;
//    zrdb.getLink(std::stoi(detailtem.substr(0, detailtem.find(" "))));
    dlgNewLink dlg(NULL, wxID_ANY);
//    string sbuf = std::string(ares[i]["idlk2"]) + " " + std::string(ares[i]["lkn"]);
    zrdb.initField(detailGrid->GetCellValue(row, 0).ToStdString(), dlg.edtPrim);
    zrdb.initField(detailGrid->GetCellValue(row, 1).ToStdString(), dlg.edtLinkName);
    zrdb.initField(detailGrid->GetCellValue(row, 2).ToStdString(), dlg.edtLink);
    zrdb.initField(detailGrid->GetCellValue(row, 3).ToStdString(), dlg.edtDetDes);
    dlg.btnInset->SetLabel( "Edit");
    if (dlg.ShowModal() == wxID_OK)
    {
        zrdb.editLink(recNo,zrdb.fieldToString(dlg.edtPrim), zrdb.fieldToString(dlg.edtLink), zrdb.fieldToString(dlg.edtLinkName), zrdb.fieldToString(dlg.edtDetDes), zrdb.strIdlk1);
        RefreshDetails();
    }
}
