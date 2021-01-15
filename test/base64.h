//
//  base64 encoding and decoding with C++.
//  Version: 2.rc.07 (release candidate)
//

#ifndef BASE64_H_C0CE2A47_D10E_42C9_A27C_C883944E704A
#define BASE64_H_C0CE2A47_D10E_42C9_A27C_C883944E704A

#include <string>
using namespace std;
#if __cplusplus >= 201703L
#include <string_view>
#endif  // __cplusplus >= 201703L

string base64_encode     (string const& s, bool url = false);
string base64_encode_pem (string const& s);
string base64_encode_mime(string const& s);

string base64_decode(string const& s, bool remove_linebreaks = false);
string base64_encode(unsigned char const*, size_t len, bool url = false);

#if __cplusplus >= 201703L
//
// Interface with string_view rather than const string&
// Requires C++17
// Provided by Yannic Bonenberger (https://github.com/Yannic)
//
string base64_encode     (string_view s, bool url = false);
string base64_encode_pem (string_view s);
string base64_encode_mime(string_view s);

string base64_decode(string_view s, bool remove_linebreaks = false);
#endif  // __cplusplus >= 201703L

#endif /* BASE64_H_C0CE2A47_D10E_42C9_A27C_C883944E704A */
