#ifndef CURLSTUFF_H
#define CURLSTUFF_H
#include<string>


class curlStuff
{
    public:
        curlStuff();
        virtual ~curlStuff();
        std::string getZTitle(std::string url);
        std::string clipUrl();
        std::string getURL();
        std::string cbc;

    protected:

    private:
};

#endif // CURLSTUFF_H
