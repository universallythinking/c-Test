//
//  Base64Encoder.cpp
//  test
//
//  Created by Benjamin Barnett on 1/12/21.
//  Copyright © 2021 Benjamin Barnett. All rights reserved.
//

#include "getImage.hpp"
condition_variable cv;
mutex mtx;
string output_file;
static char encoding_table[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                                'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
                                'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
                                'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
                                'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
                                'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                                'w', 'x', 'y', 'z', '0', '1', '2', '3',
                                '4', '5', '6', '7', '8', '9', '+', '/'};
static char *decoding_table = NULL;
static int mod_table[] = {0, 2, 1};


string encode_image(char *data, size_t input_length, size_t output_length, bool from_api) {
    output_length = output_length;
    char *encoded_data = new char [output_length];
    cout << output_length;
    if (encoded_data == NULL) return NULL;
    for (int i = 0, j = 0; i < output_length;) {
        uint32_t octet_a = i < output_length ? (unsigned char)data[i++] : 0;
        uint32_t octet_b = i < output_length ? (unsigned char)data[i++] : 0;
        uint32_t octet_c = i < output_length ? (unsigned char)data[i++] : 0;

        uint32_t triple = (octet_a << 0x10) + (octet_b << 0x08) + octet_c;

        encoded_data[j++] = encoding_table[(triple >> 3 * 6) & 0x3F];
        encoded_data[j++] = encoding_table[(triple >> 2 * 6) & 0x3F];
        encoded_data[j++] = encoding_table[(triple >> 1 * 6) & 0x3F];
    }
    for (int i = 0; i < mod_table[output_length % 3]; i++)
        encoded_data[output_length - 1 - i] = '=';
    
    cv.notify_one();
    
    string final_png = "data:image/jpg;base64,";
    final_png.append(encoded_data);
    
    string return_string = final_png;
    if (from_api)
        return_string = "<img src='" + final_png + "' alt='converted image' />";
    
    cout << return_string;
    ofstream outputFile(output_file);
    outputFile << return_string;
    return return_string;
}

void base64_cleanup() {
    free(decoding_table);
}

static void curl_callback(char* buf, size_t size, size_t nmemb, void* up) {
    encode_image(buf, size, nmemb, false);
}

static void curl_callback_api(char* buf, size_t size, size_t nmemb, void* up) {
    encode_image(buf, size, nmemb, true);
}

void get_image(const char * image_url, string file_name) {
    CURL *image;
    FILE *fp;
    output_file = file_name;
    image = curl_easy_init();
    if (image) {
        fp = fopen("before.png", "wr");
        if (fp == NULL) cout << "File cannot be opened";

        curl_easy_setopt(image, CURLOPT_WRITEDATA, fp);
        curl_easy_setopt(image, CURLOPT_URL, image_url);
        if(file_name != "BASE64API")
            curl_easy_setopt(image, CURLOPT_WRITEFUNCTION, curl_callback);
        else
            curl_easy_setopt(image, CURLOPT_WRITEFUNCTION, curl_callback_api);
        curl_easy_perform(image);
        
        unique_lock<std::mutex> lck(mtx);
        cv.wait(lck);
    }
    return;
}
