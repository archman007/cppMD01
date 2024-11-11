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
#include <wx/wx.h>
#include <wx/fontdlg.h>

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
const long cppMD01Frame::idMenucpp = wxNewId();
const long cppMD01Frame::idMenuQuit = wxNewId();
const long cppMD01Frame::idMenuAbout = wxNewId();
const long cppMD01Frame::ID_STATUSBAR1 = wxNewId();
const long cppMD01Frame::ID_NewBlog = wxNewId();
const long cppMD01Frame::ID_MENUITEM1 = wxNewId();
const long cppMD01Frame::idpumNewCat = wxNewId();
const long cppMD01Frame::ID_PumEdCat = wxNewId();
const long cppMD01Frame::ID_ChFont = wxNewId();
const long cppMD01Frame::ID_CodeLauncher = wxNewId();
const long cppMD01Frame::ID_DBeav = wxNewId();
const long cppMD01Frame::ID_GhDt = wxNewId();
const long cppMD01Frame::ID_pumCGPT = wxNewId();
const long cppMD01Frame::ID_SelTool = wxNewId();
const long cppMD01Frame::ID_menAD = wxNewId();
const long cppMD01Frame::ID_MENUITEM2 = wxNewId();
const long cppMD01Frame::ID_CF = wxNewId();
const long cppMD01Frame::ID_menNB = wxNewId();
const long cppMD01Frame::ID_pumDel = wxNewId();
const long cppMD01Frame::ID_pumEditLink = wxNewId();
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

    Create(parent, id, _("Brooks Computing Systems, LLC  ** Programmer\'s Workbench **"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE|wxSYSTEM_MENU|wxRESIZE_BORDER|wxMAXIMIZE_BOX|wxMINIMIZE_BOX|wxFULL_REPAINT_ON_RESIZE, _T("id"));
    SetBackgroundColour(wxColour(35,225,250));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer3 = new wxBoxSizer(wxVERTICAL);
    BoxSizer4 = new wxBoxSizer(wxVERTICAL);
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    Panel1->SetBackgroundColour(wxColour(35,225,242));
    StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Label"), wxPoint(8,0), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    BoxSizer4->Add(Panel1, 1, wxALL|wxEXPAND, 5);
    BoxSizer3->Add(BoxSizer4, 1, wxALL|wxEXPAND, 5);
    BoxSizer5 = new wxBoxSizer(wxVERTICAL);
    Panel2 = new wxPanel(this, ID_PANEL3, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL3"));
    Panel2->SetBackgroundColour(wxColour(184,220,255));
    BoxSizer5->Add(Panel2, 0, wxALL|wxEXPAND, 5);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Label"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE, _T("ID_STATICTEXT2"));
    StaticText2->SetBackgroundColour(wxColour(8,223,243));
    BoxSizer5->Add(StaticText2, 0, wxALL|wxEXPAND, 5);
    BoxSizer3->Add(BoxSizer5, 0, wxALL|wxEXPAND, 5);
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
    pumNewBlogPost = new wxMenuItem((&pumMaster), ID_NewBlog, _("Create New Blog Post"), _("Create A New Blog Post"), wxITEM_NORMAL);
    pumMaster.Append(pumNewBlogPost);
    MenuItem3 = new wxMenuItem((&pumMaster), ID_MENUITEM1, _("Change Background Color"), _("Change Background Color"), wxITEM_NORMAL);
    pumMaster.Append(MenuItem3);
    pumNewCat = new wxMenuItem((&pumMaster), idpumNewCat, _("Enter New Category"), _("Enter New Category"), wxITEM_NORMAL);
    pumMaster.Append(pumNewCat);
    MenuItem5 = new wxMenuItem((&pumMaster), ID_PumEdCat, _("Edit Category"), _("Edit This Category"), wxITEM_NORMAL);
    pumMaster.Append(MenuItem5);
    pumChFont = new wxMenuItem((&pumMaster), ID_ChFont, _("Change Font"), _("Change Font Now"), wxITEM_NORMAL);
    pumMaster.Append(pumChFont);
    MenuItem6 = new wxMenu();
    pumCodeXqt = new wxMenuItem(MenuItem6, ID_CodeLauncher, _("VS Code\tLoad VS Code Now"), wxEmptyString, wxITEM_NORMAL);
    MenuItem6->Append(pumCodeXqt);
    pumTlDBeaver = new wxMenuItem(MenuItem6, ID_DBeav, _("DBeaver"), _("Execute DBeaver"), wxITEM_NORMAL);
    MenuItem6->Append(pumTlDBeaver);
    pumTGitHub = new wxMenuItem(MenuItem6, ID_GhDt, _("Github Desktop"), _("Start Github Desktop!"), wxITEM_NORMAL);
    MenuItem6->Append(pumTGitHub);
    pumChGPT = new wxMenuItem(MenuItem6, ID_pumCGPT, _("Chat GPT"), _("Start chat GPT"), wxITEM_NORMAL);
    MenuItem6->Append(pumChGPT);
    pumMaster.Append(ID_SelTool, _("Tools"), MenuItem6, _("elect A Tool"));
    pumAddDocs = new wxMenuItem((&pumDetail), ID_menAD, _("addDocs"), _("Add  New Documents / Items"), wxITEM_NORMAL);
    pumDetail.Append(pumAddDocs);
    MenuItem4 = new wxMenuItem((&pumDetail), ID_MENUITEM2, _("Change Background Color"), _("Change Background Color"), wxITEM_NORMAL);
    pumDetail.Append(MenuItem4);
    pumChgFonts = new wxMenuItem((&pumDetail), ID_CF, _("Change Fonts"), _("Change Fonts"), wxITEM_NORMAL);
    pumDetail.Append(pumChgFonts);
    menNewPost = new wxMenuItem((&pumDetail), ID_menNB, _("Create New Blog Post"), _("New Blog Post Now!"), wxITEM_NORMAL);
    pumDetail.Append(menNewPost);
    pumDelLink = new wxMenuItem((&pumDetail), ID_pumDel, _("Delete Link"), _("Delete A Item"), wxITEM_NORMAL);
    pumDetail.Append(pumDelLink);
    pumEditDetails = new wxMenuItem((&pumDetail), ID_pumEditLink, _("Edit Link Details"), _("Edit Link Details"), wxITEM_NORMAL);
    pumDetail.Append(pumEditDetails);
    ColourDialog1 = new wxColourDialog(this);
    	wxFontData fontData_1;
    	fontData_1.SetInitialFont(*wxNORMAL_FONT);
    FontDialog1 = new wxFontDialog(this, fontData_1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);
    Center();

    Connect(idMenucpp,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&cppMD01Frame::OnmenSelectCppSelected);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&cppMD01Frame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&cppMD01Frame::OnAbout);
    Connect(ID_NewBlog,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&cppMD01Frame::OnpumNewBlogPostSelected);
    Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&cppMD01Frame::OnChooseColor);
    Connect(idpumNewCat,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&cppMD01Frame::OnpumNewCatSelected);
    Connect(ID_PumEdCat,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&cppMD01Frame::OnpumEdCatSelected);
    Connect(ID_ChFont,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&cppMD01Frame::OnpumChFontSelected);
    Connect(ID_CodeLauncher,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&cppMD01Frame::OnpumCodeXqtSelected);
    Connect(ID_DBeav,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&cppMD01Frame::OnpumTlDBeaverSelected);
    Connect(ID_GhDt,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&cppMD01Frame::OnpumTGitHubSelected);
    Connect(ID_pumCGPT,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&cppMD01Frame::OnpumChGPTSelected);
    Connect(ID_menAD,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&cppMD01Frame::OnpumAddDocsSelected);
    Connect(ID_MENUITEM2,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&cppMD01Frame::OnChooseColor);
    Connect(ID_CF,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&cppMD01Frame::OnpumChFontSelected);
    Connect(ID_menNB,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&cppMD01Frame::OnpumNewBlogPostSelected);
    Connect(ID_pumDel,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&cppMD01Frame::OnpumDelLinkSelected);
    Connect(ID_pumEditLink,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&cppMD01Frame::OnpumEditLinkSelected);
    //*)

    SetStatusText("Button Clicked!");


    masterGrid = new wxGrid(this, wxID_ANY, wxDefaultPosition, wxSize(1200, 300));
    masterGrid->CreateGrid(0, 3);
    masterGrid->SetColLabelValue(0, "Category ID");
    masterGrid->SetColLabelValue(1, "Category Name");
    masterGrid->SetColLabelValue(2, "Detailed Description");
    masterGrid->SetColSize(1, 500);
    masterGrid->SetColSize(2, 575);
    masterGrid->SetDefaultCellBackgroundColour(*wxCYAN);
    masterGrid->SetLabelBackgroundColour(*wxCYAN);
    masterGrid->SetLabelBackgroundColour(*wxCYAN);

    detailGrid = new wxGrid(this, wxID_ANY, wxPoint(400, 0), wxSize(1200, 500));
    detailGrid->CreateGrid(0, 4);
    detailGrid->SetColLabelValue(0, "Link ID");
    detailGrid->SetColLabelValue(1, "Link Name");
    detailGrid->SetColLabelValue(2, "Link");
    detailGrid->SetColLabelValue(3, "Description");
    detailGrid->SetColSize(1, 500);
    detailGrid->SetColSize(2, 300);
    detailGrid->SetColSize(3, 325);
    detailGrid->SetDefaultCellBackgroundColour(*wxCYAN);
    detailGrid->SetLabelBackgroundColour(*wxCYAN);

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
    //SetSizer(            Panel1->SetBackgroundColour(color);
    //SetSizer(BoxSizer1);
    SetSizerAndFit(BoxSizer1);
    //BoxSizer1->Fit(this);
    LoadDetailData(0);
    color = "#23E1FA";
    color = "#ADD8E6";
    color = "#12EBD7";
    SetColors();

}

cppMD01Frame::~cppMD01Frame()
{
    //(*Destroy(cppMD01Frame)
    //*)
}

/**
 * @brief Handles the event for choosing a color via a color dialog.
 *
 * This function displays a color selection dialog when triggered. If the user confirms a color selection,
 * it applies the selected color to various UI components, including panels, grids, and static text labels.
 *
 * @param event The event object associated with the color selection.
 *
 * UI Components Updated:
 * - Background color of the main frame.
 * - Background colors of Panel1 and Panel2.
 * - Background colors and label background colors of masterGrid and detailGrid.
 * - Background colors of StaticText1 and StaticText2.
 */
void cppMD01Frame::OnChooseColor(wxCommandEvent& event)
{
    wxColourDialog colorDialog(this, &data);

    if (colorDialog.ShowModal() == wxID_OK)
    {
        wxColourData retData = colorDialog.GetColourData();
        color = retData.GetColour();
        SetColors();

        // Apply the selected color to various UI components.
    }
}

/**
 * @brief Sets the background color for various UI components in the cppMD01Frame class.
 *
 * This function applies a specified background color (`color`) to multiple user interface
 * elements, including panels, grids, and static text controls, ensuring a consistent
 * visual appearance across the application.
 *
 * Components updated:
 * - Frame background
 * - Panel1 and Panel2
 * - masterGrid and detailGrid
 *   - Grid background
 *   - Default cell background
 *   - Label background
 * - StaticText1 and StaticText2
 *
 * The color value is expected to be predefined and accessible within the class.
 */
void cppMD01Frame::SetColors()
{
    SetBackgroundColour(color);                       // Set frame background color
    Panel1->SetBackgroundColour(color);               // Set Panel1 background color
    Panel2->SetBackgroundColour(color);               // Set Panel2 background color
    masterGrid->SetBackgroundColour(color);           // Set masterGrid background color
    detailGrid->SetBackgroundColour(color);           // Set detailGrid background color
    masterGrid->SetDefaultCellBackgroundColour(color); // Set default cell background for masterGrid
    masterGrid->SetLabelBackgroundColour(color);      // Set label background for masterGrid
    detailGrid->SetDefaultCellBackgroundColour(color); // Set default cell background for detailGrid
    detailGrid->SetLabelBackgroundColour(color);      // Set label background for detailGrid
    StaticText1->SetBackgroundColour(color);          // Set StaticText1 background color
    StaticText2->SetBackgroundColour(color);          // Set StaticText2 background color
}

/**
 * @brief Populates the master grid with data from the MySQL database.
 *
 * This function establishes a connection to the MySQL database and relistLinkstrieves
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
    row = event.GetRow();
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
        system(cellValue.c_str());
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
    wxString zlabel;
    mysqlpp::Query query = conn.query();
    query << "SELECT idlk2, lkn, lnk, ddes FROM lk2 WHERE idlk1 = " << idlk1 << " ORDER BY lkn";
    mysqlpp::StoreQueryResult res = query.store();
    res.num_rows();
    if (res.num_rows() > 0)
    {
        zlabel = std::to_string(res.num_rows()) + " Records Retrieved";
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
//       wxCommandEvent& event
        OnpumAddDocsSelected(event);

    }
    StatusBar1->SetLabel(zlabel);
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
    mkVal = masterGrid->GetCellValue(row, 0);
    StaticText2->SetLabel(masterGrid->GetCellValue(row, 1));
    // StaticText2->SetWindowStyle(wxALIGN_CENTER);
    //StaticText2->Refresh(true);

//    StaticText2->Center(wxBOTH);
    long idlk1;
    idlk1Str.ToLong(&idlk1); // Convert the cell value to a long integer
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

/**
 * @brief Handles the popup menu event for the master grid.
 *
 * This method is triggered when a context menu event occurs on the master grid.
 * It displays a popup menu defined by `pumMaster`.
 *
 * @param event Reference to the wxGridEvent object containing event details.
 */
void cppMD01Frame::OnMasterGridPopup(wxGridEvent& event)
{
    PopupMenu(&pumMaster);
}

/**
 * @brief Event handler for displaying a context menu on the detail grid.
 *
 * This method is triggered when a user performs a context-menu event
 * (e.g., right-click) on the detail grid. It displays a popup menu
 * associated with the grid.
 *
 * @param event Reference to the wxGridEvent triggered by the user's action.
 */
void cppMD01Frame::OnDetailGridPopup(wxGridEvent& event)
{
    // Display the popup menu (pumDetail) at the location of the event.
    PopupMenu(&pumDetail);
}

/**
 * Handles the event triggered when a specific menu item is selected.
 *
 * @param event The wxCommandEvent triggered by the menu selection.
 */
void cppMD01Frame::OnmenSelectCppSelected(wxCommandEvent& event)
{
    // Define a Boost filesystem path to a specific C++ source file.
    boost::filesystem::path p("/home/archman/workspace/cb/cpp/cppMD01/cppMD01.cpp");

    // Print various components of the file path to the console.
    std::cout << "Root name: " << p.root_name() << '\n';
    std::cout << "Root directory: " << p.root_directory() << '\n';
    std::cout << "Root path: " << p.root_path() << '\n';
    std::cout << "Relative path: " << p.relative_path() << '\n';
    std::cout << "Parent path: " << p.parent_path() << '\n';
    std::cout << "Filename: " << p.filename() << '\n';
    std::cout << "Extension: " << p.extension() << '\n';

    // Create a file dialog to allow the user to select a C++ file.
    wxFileDialog openFileDialog(this, _("Open file"), "", "",
                                "C++ files (*.cpp)|*.*", wxFD_OPEN | wxFD_FILE_MUST_EXIST);

    // Check if the user selects a file in the file dialog.
    if (openFileDialog.ShowModal() == wxID_OK)
    {
        // Get the full path and filename of the selected file.
        wxString filePath = openFileDialog.GetPath();
        wxString fileName = openFileDialog.GetFilename();

        // Log the selected file path to the wxWidgets log.
        wxLogMessage("File selected: %s", filePath);

        // Example file path to demonstrate path component extraction.
        std::string path = "/home/user/documents/file.txt";
        std::vector<std::string> result;

        /*
         * Uncomment this section to extract the path components using Boost.
         *
         * boost::filesystem::path p(path);
         *
         * for (const auto& part : p)
         * {
         *     result.push_back(part.string());
         * }
         *
         * // Output the exploded path components.
         * for (const auto& part : result)
         * {
         *     std::cout << part << std::endl;
         * }
         */
    }
}

/**
 * @brief Lists files in a specified directory matching a given file specification.
 *
 * This function searches through the given directory and collects filenames that
 * match the specified file extension pattern (e.g., "*.ext"). The matching filenames
 * are added to the provided wxArrayString list.
 *
 * @param dir The directory path to search for files (as wxString).
 * @param filespec The file extension filter (e.g., "*.txt") as wxString.
 *
 * @note This function assumes the file specification starts with a wildcard
 * character ('*') and filters files based on their extensions.
 *
 * @warning The function uses a pointer (`fileList`) but does not initialize it.
 * Ensure that `fileList` points to a valid `wxArrayString` object before calling
 * this function.
 *
 * @dependencies
 * - wxWidgets for `wxString` and `wxArrayString`.
 * - C++17 filesystem library (`std::filesystem` namespace as `fs`).
 * - Boost for `boost::iends_with` string comparison.
 */
void cppMD01Frame::ListFiles(const wxString& dir, const wxString& filespec)
{
    wxArrayString *fileList;  // Pointer to wxArrayString for storing filenames
    fileList->Clear();        // Clears any previous entries in fileList

    // Convert wxString to std::string for compatibility with filesystem functions
    fs::path path = std::string(dir.mb_str());
    std::string spec = std::string(filespec.mb_str());

    // Check if the directory exists and is valid
    if (fs::exists(path) && fs::is_directory(path))
    {
        // Iterate through directory entries
        for (const auto& entry : fs::directory_iterator(path))
        {
            if (fs::is_regular_file(entry)) // Only consider regular files
            {
                std::string filename = entry.path().filename().string();

                // Apply filespec filtering based on file extension
                if (boost::iends_with(filename, spec.substr(1)))    // "*.ext" -> "ext"
                {
                    fileList->Add(wxString::FromUTF8(filename));   // Add matched filename
                }
            }
        }
    }
}

/**
 * @brief Event handler for the "Add Docs" menu option in the cppMD01Frame class.
 *
 * This function is triggered when the user selects the "Add Docs" option from the menu.
 * It opens a dialog (`dlgXqt2`) to allow the user to choose an action. Based on the user's
 * selection, it executes the corresponding processing function.
 *
 * @param event The wxCommandEvent object containing event information.
 *
 * Functionality:
 * - Displays a modal dialog (`dlgXqt2`).
 * - If the dialog result is `wxID_OK`:
 *     - Executes one of the following functions based on the user's selection (`isel`):
 *         - `procLink()` for `isel == 0`
 *         - `procPdf()` for `isel == 1`
 *         - `procDoc()` for `isel == 2`
 *         - `procExe()` for `isel == 3`
 *     - If no valid option is selected, the `default` case does nothing.
 *
 * Assumptions:
 * - The `dlgXqt2` class is a custom dialog that provides an `isel` member variable
 *   indicating the user's selection.
 * - Functions `procLink()`, `procPdf()`, `procDoc()`, and `procExe()` are defined elsewhere
 *   in the program and handle specific document types or actions.
 *
 * Notes:
 * - Ensure `dlgXqt2` is properly constructed and initialized.
 * - Handle any potential errors or invalid states in the processing functions.
 */
void cppMD01Frame::OnpumAddDocsSelected(wxCommandEvent& event)
{
    dlgXqt2 dlg(NULL, wxID_ANY);  // Initialize the dialog with no parent and a unique ID.
    if (dlg.ShowModal() == wxID_OK)  // Show the dialog and check if the user pressed OK.
    {
        switch (dlg.isel)  // Determine the action based on the user's selection.
        {
        case 0:
            procLink();  // Process a link.
            break;
        case 1:
            procPdf();  // Process a PDF document.
            break;
        case 2:
            procDoc();  // Process a DOC document.
            break;
        case 3:
            procExe();  // Process an executable file.
            break;
        default:
            // No action for invalid selections.
            break;
        }
    }
}

/**
 * @brief Handles the process of creating and linking new data.
 *
 * This function launches a dialog for creating a new link, initializes a
 * field in the dialog with a value from `mkVal`, and upon confirmation,
 * processes and loads detailed data.
 *
 * Function flow:
 * - Initializes a new instance of the `dlgNewLink` dialog.
 * - Uses `zrdb.initField` to populate the `edtPrim` field of the dialog.
 * - If the user confirms the dialog (`wxID_OK`), retrieves the value from `mkVal`,
 *   converts it to a `long` integer, and loads detailed data using `LoadDetailData`.
 *
 * @note This function assumes `mkVal` contains a valid value convertible to `long`
 *       and `zrdb` is a properly initialized object with `initField` and `LoadDetailData` available.
 */
void cppMD01Frame::procLink()
{
    // Create a new dialog for adding a link
    dlgNewLink dlg(NULL, wxID_ANY);

    // Initialize the dialog field using `mkVal`
    zrdb.initField(mkVal, dlg.edtPrim);

    // Show the dialog and check if user pressed OK
    if (dlg.ShowModal() == wxID_OK)
    {
        // Convert the value from `mkVal` to a long and load detailed data
        LoadDetailData(std::stol(mkVal));
    }
}

// Function: cppMD01Frame::procPdf
// Purpose: Handles PDF file selection and processes user input to load and display detail data.
void cppMD01Frame::procPdf()
{
    // Create a new dialog for entering link information
    dlgNewLink dlg(NULL, wxID_ANY);

    // Initialize the primary field in the dialog with a value from mkVal
    zrdb.initField(mkVal, dlg.edtPrim);

    // Set file dialog flags for opening a file
    int flags = wxFD_OPEN | wxFD_FILE_MUST_EXIST | wxFD_DEFAULT_STYLE;

    // Open a file dialog for selecting a PDF file
    zrdb.initField(
        gui01.openFileDialog(
            NULL,                        // Parent window
            "Select A File",             // Dialog title
            "/home/archman/Documents",   // Default directory
            "",                          // Default file name
            "*.pdf",                     // File type filter
            flags                        // Dialog style flags
        ),
        dlg.edtLink                     // Target field in dialog for storing the selected file path
    );

    // Show the dialog and if the user clicks OK, process the data
    if (dlg.ShowModal() == wxID_OK)
    {
        // Convert mkVal to a long and load the corresponding detail data
        LoadDetailData(std::stol(mkVal));
    }

    // Refresh the details view to reflect any changes
    RefreshDetails();
}

/// @brief Handles the processing of a document link dialog and loads detailed data based on user input.
///
/// This method initializes a dialog for creating a new link, sets up file selection for the user, and processes the selected document.
/// It involves two key steps: initializing fields with values and opening a file selection dialog. If the user selects a valid file
/// and confirms, the document details are loaded and displayed.
///
/// @note This function assumes the presence of `dlgNewLink` (a dialog class), `zrdb` (a database or data handler object), and `gui01` (a UI manager for the file dialog).
///
/// @details The following actions are performed:
/// 1. A new dialog `dlgNewLink` is created and initialized, including its associated fields.
/// 2. A file selection dialog is opened for the user to choose an ODT (Open Document Text) file from a specified directory.
/// 3. The dialog shows the file picker and waits for the user to either confirm or cancel the selection.
/// 4. If the user confirms (by selecting a file), the detailed data corresponding to a given value (`mkVal`) is loaded.
/// 5. After loading the details, the method refreshes the UI with updated information.
///
/// @see dlgNewLink, zrdb, gui01, LoadDetailData, RefreshDetails
void cppMD01Frame::procDoc()
{
    // Create a new dialog instance for linking a document.
    dlgNewLink dlg(NULL, wxID_ANY);

    // Initialize fields in the dialog with the 'mkVal' and 'edtPrim' from 'zrdb'.
    zrdb.initField(mkVal, dlg.edtPrim);

    // Setup flags for the open file dialog: open mode, file must exist, and default style.
    int flags = wxFD_OPEN | wxFD_FILE_MUST_EXIST | wxFD_DEFAULT_STYLE;

    // Open file dialog for selecting an .odt document in a specified directory.
    zrdb.initField(gui01.openFileDialog(NULL, "Select A Document", "/home/archman/Documents", "", "*.odt", flags), dlg.edtLink);

    // If the dialog was confirmed (user selects 'OK'), load the detailed data for the document.
    if (dlg.ShowModal() == wxID_OK)
    {
        // Load the data based on the selected file's associated value.
        LoadDetailData(std::stol(mkVal));
    }

    // Refresh the UI to reflect the loaded data.
    RefreshDetails();
}

void cppMD01Frame::procExe()
{
    // Create a new dialog object (dlgNewLink) to handle user input for creating or establishing a new link.
    // The dialog is initialized with no parent window (NULL) and a unique dialog ID (wxID_ANY).
    dlgNewLink dlg(NULL, wxID_ANY);

    // Initialize the 'mkVal' field and the 'edtPrim' text control with data from the zrdb object.
    // The initField method is likely used to set up or bind some data fields.
    zrdb.initField(mkVal, dlg.edtPrim);

    // Define the flags for the file dialog:
    // - wxFD_OPEN: Open file dialog.
    // - wxFD_FILE_MUST_EXIST: Only allow existing files to be selected.
    // - wxFD_DEFAULT_STYLE: Use the default style for the dialog.
    int flags = wxFD_OPEN | wxFD_FILE_MUST_EXIST | wxFD_DEFAULT_STYLE;

    // Open a file dialog to allow the user to select a file.
    // The dialog is initialized with the following parameters:
    // - NULL for the parent window (since dlgNewLink is already created and used).
    // - "Select A File" as the dialog's prompt.
    // - "/home/archman/workspace/cb/cpp" as the initial directory.
    // - Empty string for file type filter.
    // - Empty string for wildcard (since no file types are restricted).
    // - 'flags' that define the dialog behavior.
    // The selected file path is then used to initialize 'edtLink' in the dialog.
    zrdb.initField(gui01.openFileDialog(NULL, "Select A File", "/home/archman/workspace/cb/cpp", "", "", flags), dlg.edtLink);

    // Reinitialize 'mkVal' and 'edtPrim' with updated data.
    // This is likely done to refresh the data in case any changes occurred during the file dialog operation.
    zrdb.initField(mkVal, dlg.edtPrim);

    // Show the dialog to the user and check if they click "OK" (wxID_OK).
    // If the user confirms the dialog by clicking "OK", proceed with further operations.
    if (dlg.ShowModal() == wxID_OK)
    {
        // The line 'mkVal = mkVal' is a no-op (no operation), meaning it does not modify mkVal.
        // It could be a placeholder or redundant code that doesn't affect the program.
        mkVal = mkVal;

        // Convert 'mkVal' to a long integer and call LoadDetailData.
        // This function is likely used to load additional details or data associated with 'mkVal'.
        LoadDetailData(std::stol(mkVal));
    }

    // Refresh the details view or data after completing the operations.
    // This may involve updating the UI to reflect the newly loaded data.
    RefreshDetails();
}

/// Refreshes the details for the current record by querying the database and loading additional data.
/// - Queries the database for links related to the value 'mkVal' and record ID 'dRID'.
/// - Loads additional detailed data for the record specified by 'dRID'.
void cppMD01Frame::RefreshDetails()
{
    // Query the database for links related to the value 'mkVal' and record ID 'dRID'
    zrdb.listLinks(std::stoi(mkVal), dRID);

    // Load additional detailed data for the record 'dRID'
    LoadDetailData(dRID);

    // (Commented-out code would go here for updating the ListBox and StatusBar)
}

/// @brief Event handler for selecting a new category.
///
/// This method is triggered when a user selects a new category in the user interface.
/// It opens a dialog (dlgNewCat) to allow the user to input or modify category-related information.
/// The dialog is displayed as a modal window, meaning that the user must interact with it before
/// returning to the main window. After the dialog is closed, the method triggers a refresh of
/// the details displayed in the UI.
///
/// @param event The wxCommandEvent object that contains information about the event. It is passed
/// by the wxWidgets event system, but is not used directly in this implementation.
///
/// @note The actual initialization of fields or actions on the dialog (such as file selection)
/// are commented out and not part of the current implementation. These may have been intended
/// for future functionality or were disabled during development.
///
/// @see dlgNewCat, wxCommandEvent, RefreshDetails
void cppMD01Frame::OnpumNewCatSelected(wxCommandEvent& event)
{
    // Create a new dialog for selecting or modifying category information.
    dlgNewCat dlg(NULL, wxID_ANY);

    // Initialize fields or handle additional dialog configuration if needed.
    // zrdb.initField(mkVal, dlg.edtPrim);
    // int flags = wxFD_OPEN | wxFD_FILE_MUST_EXIST | wxFD_DEFAULT_STYLE;
    // zrdb.initField(gui01.openFileDialog(NULL, "Select A File", "/home/archman/workspace/cb/cpp", "", "", flags), dlg.edtLink);

    // Show the dialog and wait for the user's response.
    if (dlg.ShowModal() == wxID_OK)
    {
        // If the user clicked OK, perform any necessary actions here.
        // Currently no additional logic is defined in this block.
    }

    // Refresh the details in the UI after the dialog is closed.
    RefreshDetails();
}

// Function: OnpumNewBlogPostSelected
// Purpose: This function is triggered when a new blog post is selected in the UI.
// It performs two actions:
// 1. Prepares a text snippet (HTML content) and copies it to the clipboard.
// 2. Opens a new blog post creation page in the default web browser.

void cppMD01Frame::OnpumNewBlogPostSelected(wxCommandEvent& event)
{
    // Declare a constant character pointer to hold the text data for clipboard
    const char * c;

    // Create a string buffer to hold the HTML content that will be copied to the clipboard
    string tbuf;

    // Build an anchor tag with an image (USA flag) and a link to the website (Archman)
    tbuf = "<a href=\"https://archman.us\" target=\"_blank\" rel=\"noopener\">";
    tbuf = tbuf + "    <img src=\"https://archman.us/images/usa_3a.gif\" alt=\"USA\" />";
    tbuf = tbuf + "</a>\n\n";

    // Optionally, a single image without a hyperlink could be used (currently commented out)
    // tbuf = "<img src=\"http://archman.us/images/usa_3a.gif\" alt=\"\" />\n\n";

    // Add text that credits the author, Arch Brooks, and links to his website
    tbuf = tbuf + "Mr. <a href=\"https://archman.us\" target=\"_blank\" rel=\"noopener\">Arch Brooks</a>, Software Engineer, Brooks Computing Systems, LLC authored this article.";

    // Try to open the system clipboard for interaction
    if (wxTheClipboard->Open())
    {
        // The clipboard will hold the text data object, so there is no need to delete it later.
        c = tbuf.c_str(); // Convert the string buffer to a C-style string

        // Set the clipboard data to the text data object containing the HTML content
        wxTheClipboard->SetData(new wxTextDataObject(c));

        // Close the clipboard to commit the changes
        wxTheClipboard->Close();
    }

    // Build the command string to open the "New Blog Post" creation page in the web browser
    // 'defBro' is a predefined string variable (probably contains the path to the browser)
    cmd = defBro + " " + "https://archman.us/b4/wp-admin/post-new.php & ";

    // Execute the system command to open the browser with the new post creation page
    system(cmd.c_str());
}

void cppMD01Frame::OnpumDelLinkSelected(wxCommandEvent& event)
{
    // Declare a string variable to hold a caption for a confirmation message
    std::string cap;

    // Get the ID and detail information from the grid cell at the specified row (the row is assumed to be set somewhere else in the code)
    // The row number is presumably provided by the context, but it's not shown here.
    wxString idlk1Str = detailGrid->GetCellValue(row, 0);  // Retrieve value from the first column of the grid at the current row
    std::string detailItem = detailGrid->GetCellValue(row, 0).ToStdString();  // Convert wxString to std::string for the first column
    std::string linkName = detailGrid->GetCellValue(row, 1).ToStdString();  // Retrieve value from the second column and convert to std::string

    // Create a confirmation message to ask the user if they want to delete the selected link
    cap = "Are You sure You would like to delete\n\"" + detailItem + " " + linkName + "\"?";

    // Display a confirmation dialog with the constructed message
    // The function `gui01.yornQues` is presumably a custom function that shows a Yes/No dialog to the user.
    // If the user selects 'Yes', the deletion will proceed.
    if (gui01.yornQues(cap, "Delete This Record?") == wxYES)
    {
        // If the user confirmed the deletion, call `zrdb.DeleteLink` to delete the link.
        // Presumably, `zrdb` is a database or data handler object that manages link records.
        zrdb.DeleteLink(detailItem);  // Delete the link identified by `detailItem`

        // Reload the data to reflect the changes (after deletion)
        // `LoadDetailData` is called with the value `mkVal` (which appears to be a value relevant to the data context).
        // It's assumed that `mkVal` is set elsewhere in the class.
        LoadDetailData(std::stol(mkVal));  // Load the updated details (convert `mkVal` to long)

        // Refresh the details displayed on the GUI to reflect the deleted item
        RefreshDetails();  // Refresh the grid or other UI elements to show the updated list
    }
}

void cppMD01Frame::OnpumEdCatSelected(wxCommandEvent& event)
{
    // Create a new instance of the dlgNewCat dialog box
    dlgNewCat dlg(NULL, wxID_ANY);

    // Retrieve the record number (ID) from the selected cell in a detail grid
    // The original code seems to be commented out (ListBox1), now it uses detailGrid with row and column 0
    std::string recNo = detailGrid->GetCellValue(row, 0).ToStdString();

    // Store the record number (ID) for use in the dialog or database operation
    zrdb.strIdlk1 = recNo;

    // Set the label of the 'Insert' button to "Edit" to indicate we're editing an existing entry
    dlg.btnInsert->SetLabel("Edit");

    // Retrieve and load category data from the database using the record number (ID)
    zrdb.getCat();

    // Initialize the category and memo fields in the dialog based on values from the master grid
    zrdb.initField(masterGrid->GetCellValue(row, 1).ToStdString(), dlg.edtCat);
    zrdb.initField(masterGrid->GetCellValue(row, 2).ToStdString(), dlg.edtMemo);

    // Open the dialog and wait for user interaction (OK or Cancel)
    if (dlg.ShowModal() == wxID_OK)
    {
        // If the user clicked 'OK', update the category and memo fields in the database
        zrdb.editCat(zrdb.strIdlk1, zrdb.fieldToString(dlg.edtCat), zrdb.fieldToString(dlg.edtMemo));
    }

    // Refresh the list of categories from the database, possibly for UI updates
    zrdb.listCategories(false);

    // Populate the master grid with the latest data (likely reflecting changes made in the dialog)
    PopulateMasterGrid();
}

// Function triggered when an item in the "Edit Link" menu is selected
void cppMD01Frame::OnpumEditLinkSelected(wxCommandEvent& event)
{
    // Retrieve the record number from the grid cell.
    // The row variable is assumed to be set elsewhere in the code.
    recNo = detailGrid->GetCellValue(row, 0).ToStdString(); // Get record number from first column

    // Set insert mode to false (indicating the operation is not an insert)
    zrdb.insertMode = false;

    // Create a dialog for editing a link
    dlgNewLink dlg(NULL, wxID_ANY);

    // Initialize the fields in the dialog with the current values from the grid
    zrdb.initField(detailGrid->GetCellValue(row, 0).ToStdString(), dlg.edtPrim);   // Primary key field
    zrdb.initField(detailGrid->GetCellValue(row, 1).ToStdString(), dlg.edtLinkName); // Link name field
    zrdb.initField(detailGrid->GetCellValue(row, 2).ToStdString(), dlg.edtLink);     // Link field
    zrdb.initField(detailGrid->GetCellValue(row, 3).ToStdString(), dlg.edtDetDes);   // Description field

    // Change the label of the "Insert" button to "Edit" since we are editing an existing record
    dlg.btnInset->SetLabel("Edit");

    // Show the dialog and check if the user pressed OK
    if (dlg.ShowModal() == wxID_OK)
    {
        // If the user pressed OK, save the edited values to the database
        // The `zrdb.editLink` method updates the record using the new field values
        zrdb.editLink(
            recNo,
            zrdb.fieldToString(dlg.edtPrim),   // Primary key from dialog field
            zrdb.fieldToString(dlg.edtLink),   // Link field from dialog field
            zrdb.fieldToString(dlg.edtLinkName), // Link name from dialog field
            zrdb.fieldToString(dlg.edtDetDes), // Description field from dialog field
            mkVal // A value presumably passed for additional processing
        );

        // Reload the updated detail data using the record number
        LoadDetailData(std::stol(mkVal)); // Reload data based on the updated record ID
    }
}

void cppMD01Frame::OnpumEditDetailsSelected(wxCommandEvent& event)
{
}

/**
 * @brief Handles the event when a menu option "pumCodeXqt" is selected.
 *
 * This function opens a directory selection dialog and launches Visual Studio Code
 * in the selected directory.
 *
 * @param event The event triggered by selecting the "pumCodeXqt" option.
 */
void cppMD01Frame::OnpumCodeXqtSelected(wxCommandEvent& event)
{
    // Create and display a directory selection dialog.
    wxDirDialog dlg = new wxDirDialog();
    if (dlg.ShowModal() == wxID_OK)
    {
        // Retrieve the selected directory path.
        wxString selected_dir = dlg.GetPath();
        // (Optional) You may use the selected directory label as needed.
        // dir_label.SetLabel(f"Selected Directory: {selected_dir}");
    }

    // Construct the system command to open Visual Studio Code in the selected directory.
    std::string cmd = "code ";
    cmd += dlg.GetPath().ToStdString() + "  ";

    // Clean up the dialog and execute the command.
    dlg.Destroy();
    system(cmd.c_str());
}

//void cppMD01Frame::OnChooseColor(wxCommandEvent& event)
//{
//}

/**
 * @brief Handles the font selection event triggered by a popup menu.
 *
 * This method is invoked when the "Change Font" option is selected from the popup menu.
 * It opens a font dialog, allowing the user to choose a new font. Upon selection,
 * the chosen font is applied to multiple UI elements, including grids and static texts.
 *
 * @param event wxCommandEvent&: The event object containing information about the triggered event.
 */
void cppMD01Frame::OnpumChFontSelected(wxCommandEvent& event)
{
    wxFontData fontData;
    fontData.EnableEffects(true); // Enable font effects (e.g., underlining, strikethrough).
    fontData.SetInitialFont(masterGrid->GetFont()); // Set initial font to the current grid font.

    wxFontDialog fontDialog(this, fontData); // Initialize font dialog with font data.
    if (fontDialog.ShowModal() == wxID_OK)  // Show the dialog and check if user pressed OK.
    {
        wxFontData retData = fontDialog.GetFontData(); // Get the chosen font data.
        wxFont font = retData.GetChosenFont(); // Extract the chosen font.

        // Apply the chosen font to the main grid, detail grid, and static text elements.
        masterGrid->SetFont(font);
        masterGrid->SetDefaultCellFont(font);
        detailGrid->SetDefaultCellFont(font);
        StaticText1->SetFont(font);
        StaticText2->SetFont(font);

        // Refresh the grids to apply font changes immediately.
        masterGrid->Refresh();
        detailGrid->Refresh();
    }
}

/**
 * @brief Event handler for selecting the "DBeaver" menu option.
 *
 * This function is triggered when the user selects the DBeaver option
 * from the application's menu. It launches the DBeaver database tool
 * by executing the corresponding system command.
 *
 * @param event The wxCommandEvent object containing event details.
 */
void cppMD01Frame::OnpumTlDBeaverSelected(wxCommandEvent& event)
{
    system("dbeaver");
}

/**
 * @brief Event handler for the GitHub Desktop menu option.
 *
 * This function handles the event triggered when the "GitHub Desktop" option
 * is selected from the application's menu. It utilizes the `system` command
 * to open GitHub Desktop via the system shell.
 *
 * @param event The wxCommandEvent object containing details about the event.
 *
 * @note The command is executed in the background using the '&' operator
 * to prevent blocking the main application thread.
 *
 * @warning Using `system` can pose security risks if user input is involved.
 * Ensure the command string is not influenced by external input.
 */
void cppMD01Frame::OnpumTGitHubSelected(wxCommandEvent& event)
{
    // Launches GitHub Desktop application in the background.
    system("/usr/bin/github-desktop &");
}

/**
 * @brief Event handler for the "ChatGPT Selected" menu option.
 *
 * This function is called when the user selects the "ChatGPT" option from the menu.
 * It executes the "chat-gpt" system command, which presumably launches or interacts
 * with a ChatGPT-related application.
 *
 * @param event The command event triggered by the menu selection.
 */
void cppMD01Frame::OnpumChGPTSelected(wxCommandEvent& event)
{
    system("chat-gpt & ");
}

