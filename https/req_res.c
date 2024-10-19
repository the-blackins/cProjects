#include <stdio.h>
#include <curl/curl.h>
int main(void)
{
    CURL *curl; // file handle whn accessing files 
    CURLcode result;  //store return value when accessing api

    curl = curl_easy_init(); // manage request 
    // of request fails 
    if (curl == NULL)
    {
        fprintf(stderr, "HTTP request failed\n");
        return -1;
    }
                    //handle, constant( this is the option option), url for the request 
    curl_easy_setopt(curl, CURLOPT_URL, "https://www.google.com" ); // this function provides all possible options for the https request 

    result = curl_easy_perform(curl);  // this should return curl_ok 

    if (result != CURLE_OK)
    {
        fprintf(stderr, "Error: %s\n", curl_easy_strerror(result));
        return -1;
    }

    curl_easy_cleanup(curl);

    return 0;
}