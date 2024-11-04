#include <stdio.h>
#include <curl/curl.h>

int main() {
    CURL *curl;
    CURLcode res;

    // Initialize curl
    curl = curl_easy_init();
    if (curl) {
        // Set URL for the GET request
        curl_easy_setopt(curl, CURLOPT_URL, "https://httpbin.org/get");

        // Perform the request
        res = curl_easy_perform(curl);

        // Check for errors
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        // Cleanup
        curl_easy_cleanup(curl);
    }

    return 0;
}