//
//  Base64Encoder.hpp
//  test
//
//  Created by Benjamin Barnett on 1/12/21.
//  Copyright © 2021 Benjamin Barnett. All rights reserved.
//

#ifndef Base64Encoder_hpp
#define Base64Encoder_hpp

#include <stdio.h>

#endif /* Base64Encoder_hpp */
#include <iostream>
#include <fstream>
#include <curl/curl.h>
#include <string>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <condition_variable>
using namespace std;


string encode_image(char *data,
size_t input_length,
                    size_t output_length);
void getImageFromURL(const char * image_url, string file_name);
