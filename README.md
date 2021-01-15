# c-Test


###A few notes

I was able to create a DLL (and .LIB) for this but unable to include it in the project.  I will update this with the error I received.
> Something like invalid type or version

This test application should be run on a Mac

I did not include the API, simply because it was just a matter of clicks to set up.  I can upload this if needed.
>A lot of the work is in limbo on an ancient Windows machine.


###Roadblocks

Linker errors mostly (but this was resolved after downloading vcpkg instead of using nuget)
Moving between Mac environment and Windows for the DLL creation
Downloading Visual Studio and the proper tools for my environment(s)

###Instructions

Open up test.xcodeproj and click run.  In the xcode terminal it will ask for an image url.  Paste the url and then enter the name of the output file.  I recommend something very unique, as I didn't force write to a specific directory (like ~/Desktop).  Then serach for the file in finder and grab your BASE64 encoded data.
>To see the output for the API / Web call, make the filename BASE64API





Dependencies and Included Packages / Headers
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <curl/curl.h>
#include <string>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <condition_variable>

