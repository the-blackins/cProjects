#include <stdio.h>
#include <curl/curl.h>
#include <string.h>
#include <stdlib.h>








struct MemoryStruct {
  char *memory;
  size_t size;
};
 
static size_t
WriteMemoryCallback(void *contents, size_t size, size_t nmemb, 
                    void *userp)
{
  size_t realsize = size * nmemb;
  struct MemoryStruct *mem = (struct MemoryStruct *)userp;
  
  char *ptr = realloc(mem->memory, mem->size + realsize + 1);
  if(!ptr) 
  {
    printf("not enough memory (realloc returned NULL)\n");
    return 0;
  }
 
  mem->memory = ptr;
  memcpy(&(mem->memory[mem->size]), contents, realsize);
  mem->size += realsize;
  mem->memory[mem->size] = 0;
 
  return realsize;
}



  
int main(void)
{
    CURL *curl; // file handle whn accessing files 
    CURLcode result;  //store return value when accessing api

    struct MemoryStruct chunk; 
    chunk.memory = malloc(1);
    chunk.size = 0;

    curl = curl_easy_init(); // manage request 
    // if request fails 
    if (curl == NULL)
    {
        fprintf(stderr, "HTTP request failed\n");
        return -1;
    }
                    //handle, constant( this is the option option), url for the request 
    curl_easy_setopt(curl, CURLOPT_URL, "https://www.google.com" ); // this function provides all possible options for the https request 

    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);   

    result = curl_easy_perform(curl);  // this should return curl_ok 

    if (result != CURLE_OK)
    {
        fprintf(stderr, "Error: %s\n", curl_easy_strerror(result));
        return -1;
    }

    printf("%s <--- response string\n", chunk.memory);
    free(chunk.memory);

    curl_easy_cleanup(curl);

    return 0;
}