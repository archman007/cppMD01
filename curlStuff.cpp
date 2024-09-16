#include "curlStuff.h"
#include <string>
#include <curl/curl.h>
#include <fstream>
#include <ios>
#include <strstream>
#include <sstream>
#include <iostream>
#include <curl/easy.h>
#include <boost/algorithm/string.hpp>
#include <wx/clipbrd.h>
#include <wx/msgdlg.h>

//#include <streambuf>

//using namespace std;

curlStuff::curlStuff()
{
    //ctor
}

curlStuff::~curlStuff()
{
    //DlgTstFramedtor
}

static size_t data_write(void* buf, size_t size, size_t nmemb, void* userp)
{
    if (userp)
    {
        std::ostream& os = *static_cast<std::ostream*>(userp);
        std::streamsize len = size * nmemb;
        if (os.write(static_cast<char*>(buf), len))
            return len;
    }

    return 0;
}

CURLcode curl_read(const std::string& url, std::ostream& os,
                   long timeout = 30)
{
    CURLcode code(CURLE_FAILED_INIT);
    CURL* curl = curl_easy_init();

    if (curl)
    {
        if (CURLE_OK
                == (code = curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION,
                                            &data_write)) && CURLE_OK
                == (code = curl_easy_setopt(curl, CURLOPT_NOPROGRESS,
                                            1L)) && CURLE_OK
                == (code = curl_easy_setopt(curl,
                                            CURLOPT_SSL_VERIFYHOST, 0L))
//               && CURLE_OK
//                == (code = curl_easy_setopt(curl,curl_read
//                                           CURLOPT_FOLLOWLOCATION, 1L))
                && CURLE_OK
                == (code = curl_easy_setopt(curl, CURLOPT_FILE, &os))
                && CURLE_OK
                == (code = curl_easy_setopt(curl, CURLOPT_TIMEOUT,
                                            timeout)) && CURLE_OK == (code =
                                                    curl_easy_setopt(curl, CURLOPT_URL, url.c_str())))
        {
//						curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, false);

            code = curl_easy_perform(curl);
        }
        curl_easy_cleanup(curl);
    }
    return code;
}


std::string curlStuff::getZTitle(std::string url)
{
    std::string retVal;
    std::string rbuf;
    curl_global_init (CURL_GLOBAL_ALL);
    int ii;
    /*
     * We use Curl to fetch the web page per the URL.
     *
     * A string stream is used to hold the web page
     *
     */

    std::ostringstream oss;
    if (CURLE_OK == curl_read(url, oss))
    {
        // Web page successfully written to string
        int ista;
        int isto;
        std::string html;
        html = oss.str();
        std::ofstream file("filename.txt");
        file << oss.str();

        std::string sb;
        std::string se;
//		ista = html.find("TITLE");
//		if ((ista != -1) and (ista < html.length())) {
//			sb = "<TITLE>";
//			se = "</TITLE>";
//		} else {
        sb = "<title>";
        se = "</title>";
//		}
        ista = html.find(sb);
        int rest;
        rest = 0;
//		sb = "<title";
//		se = "</title>";
        ista = html.find(sb);
//		if (ista > -1) {
//			isto = html.find(">");
//			rest = (isto - (ista + 6));
//		}
//		ista = ista + sb.length() + rest;
        ista = ista + 7;
        isto = html.find(se);
        int ilen;
        ilen = isto - ista;
//        char buffer[5000] = { 0 };
//		html.copy(html, ista, ilen);
        rbuf = html.substr(ista, ilen);
        std::string frs = "";
        std::string tos = "";
        frs = "&quot;";
        tos = '"';
        boost::replace_all(rbuf, frs, tos);
        frs = "&#39;";
        tos = "'";
        boost::replace_all(rbuf, frs, tos);
        if (ilen > 500)
        {
            rbuf = "Dummy Title";

        }
        else
        {
//			rbuf = html.substr(ista, ilen);
        }
        ilen = ilen; // @suppress("Assignment to itself")

        /*
         * The Boost tokenizer is used to parse the string stream into lines of code
         */
//		ii = strToLine(html);
//		lcnt = ii;
        /*
         * This routine reads the lines of code until the <Title> tag is encountered.
         *
         * The line containing the title tag is trimmed on both sides.
         *
         * The HTML tags are discarded leaving us with the title for the web page.
         *
         * Retval contains the web pate title.
         *
         */
//		retVal = getTitle(ii);

    }
    curl_global_cleanup();
    return rbuf;
}

std::string curlStuff::getURL()   // @suppress("No return")
{

    std::string buf;
    if (wxTheClipboard->Open())
    {
        if (wxTheClipboard->IsSupported(wxDF_TEXT))
        {
            wxTextDataObject data;
            wxTheClipboard->GetData(data);
            buf = data.GetText();
            //	        wxMessageBox( data.GetText() );

        }
        wxTheClipboard->Close();
        return buf;
        //		type filter text
    }
}

std::string curlStuff::clipUrl()
{
    cbc = getURL();
    cbc = cbc;
    if (cbc.find("http") < cbc.length())
    {
        return getZTitle(cbc);
    }
    else
    {
        wxMessageBox("URL not Detected!", "No URL in Clipboard", wxICON_HAND);
        return "";
    }

}
