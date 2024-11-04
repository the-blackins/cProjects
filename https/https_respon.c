// #include <stdio.h>
// #include <curl/curl.h>
// #include <stdlib.h>
// #include <string.h>

// // stores th size of the respnse string 
// typedef struct
// {
//     char *string;
//     size_t size;
// }Response;

// size_t write_chunk(void *data, size_t size, size_t nmemb, void *userdata);
// int main(void)
// {
//     CURL *curl;
//     CURLcode result;

//     curl = curl_easy_init();
//     if (curl == NULL)
//     {
//         fprintf(stderr, "HTTPS request failed\n");
//         return -1;
//     }


//     Response response;
//     response.string = malloc(1);
//     response.size = 0;
//     curl_easy_setopt(curl, CURLOPT_URL, "https://www.google.com");

//     curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_chunk); // callback function which means curl_easy perform would call this function  repeatedly. each time it does it is going parse the funtion a pointer to 
//     curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *) &response);

//     result = curl_easy_perform(curl);  // this should return curl_ok 

//     if (result != CURLE_OK)
//     {
//         fprintf(stderr, "Error: %s\n", curl_easy_strerror(result));
//         return -1;
//     }
//     printf("%s\n", response.string);

//     curl_easy_cleanup(curl);

//     free(response.string);

//     return 0;
// }

// size_t write_chunk(void *data, size_t size, size_t nmemb, void *userdata)
// {
//    size_t real_size = size *nmemb;

//    Response *response = (Response *) userdata;
//    char *ptr = realloc(response->string, response->size+real_size+ 1);

//    if(ptr == NULL)
//    {
//     return CURL_WRITEFUNC_ERROR;
//    }
//    response ->string = ptr;
//    memcpy(&(response -> string[response->size]), data, real_size);
//    response->size += real_size;
//    response-> string[response->size] = 0;

//     return real_size;
// }