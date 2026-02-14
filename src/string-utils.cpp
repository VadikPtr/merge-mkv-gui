#include "string-utils.hpp"

wxString toWxString(const fs::path& path) {
#ifdef _WIN32
  try {
    return wxString(path.generic_wstring());
  } catch (const std::exception& ex) {
    wxLogError("path convertion failed: %s", ex.what());
    abort();
  }
#else
  auto str = path.u8string();
  return wxString::FromUTF8Unchecked((const char*)str.c_str());
#endif
}

std::string toStdString(const fs::path& path) {
  return toWxString(path).c_str().AsChar();
}
