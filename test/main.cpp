//
//  main.cpp
//  test
//
//  Created by Benjamin Barnett on 1/12/21.
//  Copyright © 2021 Benjamin Barnett. All rights reserved.
//

#include <iostream>
#include "getImage.hpp"
using namespace std;

int main() {
    string file_name;
    string image_url;
    cout << "Enter your image url...\n";
    cin >> image_url;
    cout << "Enter a file name...\n";
    cin >> file_name;
    get_image(image_url.c_str(), file_name);
    return 0;
}
