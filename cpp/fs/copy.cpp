//
// Created by Alexander on 29.04.2026.
//

#include "../../header/fs/copy.h"

fs::path get_full_path(fs::path path, fs::path path_ff);

///
/// @param from copy file from path
/// @param to copy file to path
/// @param path_ff original path from path_ff
/// @param parameter for copy parameter
void copy::files(fs::path from, fs::path to, fs::path path_ff, std::string parameter) {
     try {
          fs::path from_path_for_copy = get_full_path(from, path_ff);
          fs::path to_path_for_copy = get_full_path(to, path_ff);


          if (fs::is_directory(to_path_for_copy)) {
               to_path_for_copy /= from_path_for_copy.filename();
          }

          if (fs::is_symlink(from_path_for_copy)) {
               std::println(std::cerr, "[WARNING] cannot overwrite symlink!");
               fs::copy_symlink(from_path_for_copy, to_path_for_copy);
               return;
          }

          if (parameter == "-fo" || parameter == "--file-overwrite") {
               fs::copy_file(from_path_for_copy, to_path_for_copy,
                              fs::copy_options::overwrite_existing);
               std::println("[SYSTEM] success overwriten file {} to {}",
                                   from_path_for_copy.string(), to_path_for_copy.string());
          }
          else if (parameter == "-f" || parameter == "--file") {
               fs::copy_file(from_path_for_copy, to_path_for_copy);
               std::println("[SYSTEM] success copied file {} to {}",
                    from_path_for_copy.string(), to_path_for_copy.string());
          }

     } catch (const std::exception& e) {
          std::println(std::cerr, "[CRITICAL_ERROR_COPY_FILES] {}", e.what());
     }
}

void copy::folders(fs::path from, fs::path to, fs::path path_ff, std::string parameter) {
     try {
          fs::path from_path_for_copy = get_full_path(from, path_ff);
          fs::path to_path_for_copy = get_full_path(to, path_ff);

          if (fs::is_directory(to_path_for_copy)) {
               to_path_for_copy /= from_path_for_copy.filename();
          }

          if (fs::is_symlink(from_path_for_copy)) {
               std::println(std::cerr, "[WARNING] cannot overwrite symlink!");
               fs::copy_symlink(from_path_for_copy, to_path_for_copy);
               return;
          }

          if (parameter == "-do" || parameter == "--dile-overwrite") {
               fs::copy(from_path_for_copy, to_path_for_copy,
                              fs::copy_options::overwrite_existing |
                              fs::copy_options::recursive);
               std::println("[SYSTEM] success overwritten folder {} to {}",
                    from_path_for_copy.string(), to_path_for_copy.string());
          }
          else if (parameter == "-d" || parameter == "--directory") {
               fs::copy(from_path_for_copy, to_path_for_copy,
                              fs::copy_options::recursive);
               std::println("[SYSTEM] success copied folder {} to {}",
                    from_path_for_copy.string(), to_path_for_copy.string());
          }



     } catch (const std::exception& e) {
          std::println(std::cerr, "[CRITICAL_ERROR_COPY_FILES] {}", e.what());
     }
}

// check how you write
// if so
// D:/txt >> cp txt
// and if in folder txt exists txt then get D:/txt/txt
// if full path then get from
fs::path get_full_path(fs::path path, fs::path path_ff) {
     return fs::exists(path) ? path : path_ff / path;
}