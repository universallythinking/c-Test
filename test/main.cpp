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
    string fileName;
    string imageURL;
    cout << "Enter your image url...\n";
    cin >> imageURL;
    cout << "Enter a file name...\n";
    cin >> fileName;
    getImageFromURL(imageURL.c_str(), fileName);
    return 0;
}
