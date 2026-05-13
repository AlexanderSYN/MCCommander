//
// Created by Alexander on 29.04.2026.
//

#include "../../header/fs/COPY.h"
#include "../../header/helper/Helperfs/HFILEF.h"

//===========================
//        print message
//===========================
void print_success(const std::string &msg, const fs::path& source,
                    const fs::path& target);
void print_error(const std::string &err);
void print_err_exists(const fs::path& path);
void print_error_exception(const std::string &err, const std::exception& exception,
                          const bool& isCritical);
void print_warning(const std::string &msg);

// func for copy
void copy_folder_with_overwrite(const fs::path& from, const fs::path& to,
                         const std::string& parameter);
void copy_file_with_overwrite(const fs::path& from, const fs::path& to,
                              const std::string& parameter);

//===============================================
// check parameter in func copy folder or file
//===============================================
void check_parameter_in_copy(const std::string& parameter,
                    const fs::path& source, const fs::path& target);

//===========================
//   copying file or folder
//===========================
void copy::copy_folder_or_file(const fs::path& source, const fs::path& target,
     const std::string& parameter) {

     std::string source_str = source.string();
     std::string target_str = target.string();

     try {
          check_parameter_in_copy(parameter, source, target);
     }
     catch (const fs::filesystem_error& fserr) {
          if (fserr.code() == std::errc::file_exists) {
               print_err_exists(source);
          }
          print_error_exception("", fserr, true);
     }
     catch (const std::exception& e) {
          print_error_exception("", e, true);
     }
}

//====================
// check parameter
//=====================
void check_parameter_in_copy(const std::string &parameter,
     const fs::path &source, const fs::path &target) {

     if (parameter == "-af" || parameter == "--all-files")
          copy::copy_all_files(source, target);

     else if (parameter == "-ad" || parameter == "--all-directory")
          copy::copy_folder(source, target, parameter);
     else if (parameter == "-a" || parameter == "--all") {
          copy::copy_all_files(source, target);
          copy::copy_all_folders(source, target);
     }
     else {
          if (fs::is_regular_file(source))
               copy::copy_file(source, target, parameter);
          else
               copy::copy_folder(source, target, parameter);
     }

}


//=======================
//  Copy Folder / File
//      global func
//=======================
// accepted parameter: overwrite
void copy::copy_file(const fs::path& from, const fs::path& to,
     const std::string& parameter) {

     const fs::path path_ff = path_ff::get_path();

      fs::path source = HFILEF::get_fetch_full_path(from, path_ff);
      fs::path target = HFILEF::get_fetch_full_path(to, path_ff);

      if (fs::is_directory(target)) {
           target /= source.filename();
      }

      if (fs::is_symlink(source)) {
           print_warning("cannot overwrite symlink!");
           fs::copy_symlink(source, target);
           return;
      }

     if (parameter == "--overwrite" || parameter == "-ovr") {
          fs::copy(source, target, fs::copy_options::overwrite_existing);
          print_success("success overwritten", source, target);
     }
     else {
          fs::copy(source, target, fs::copy_options::overwrite_existing);
          print_success("success copied file", source, target);
     }
}

void copy::copy_all_files(const fs::path& from, const fs::path& to) {
     try {

          for (const auto& entry : fs::directory_iterator(from)) {
               fs::path dest = to / entry.path().filename();

               if (entry.is_regular_file()) {
                    fs::copy_file(entry.path(), dest, fs::copy_options::overwrite_existing);
                    print_success("copied success", from, entry.path().filename());
               }
          }
          print_success("all files copied", from, to);
     } catch (const std::exception& e) {
          print_error_exception("error copying file",e, true);
     }
}


// accepted parameter: overwrite
void copy::copy_folder(const fs::path& from, const fs::path& to,
     const std::string& parameter) {

     const fs::path path_ff = path_ff::get_path();

     fs::path source = HFILEF::get_fetch_full_path(from, path_ff);
     fs::path target = HFILEF::get_fetch_full_path(to, path_ff);

     if (fs::is_directory(target)) {
          target /= source.filename();
     }

     if (fs::is_symlink(source)) {
          print_warning("cannot overwrite symlink!");
          fs::copy_symlink(source, target);
          return;
     }

     if (parameter == "--overwrite" || parameter == "-ovr") {
          fs::copy(source, target, fs::copy_options::overwrite_existing |
               fs::copy_options::recursive);
          print_success("success overwritten", source, target);
     }
     else {
          fs::copy(source, target, fs::copy_options::recursive);
          print_success("success copied folder", source, target);
     }
}

void copy::copy_all_folders(const fs::path &from, const fs::path &to) {
     try {
          for (const auto& entry : fs::directory_iterator(from)) {
               fs::path dest = to / entry.path().filename();

               if (entry.is_directory()) {
                    fs::copy(entry.path(), to, fs::copy_options::overwrite_existing);
                    print_success("copied success", from, entry.path().filename());
               }
          }
          print_success("all folders copied", from, to);

     } catch (const std::exception& e) {
        print_error_exception("error copying folder", e, true);
     }
}


//=======================
// copying without log
//=======================
void copy::copy_only_for_func_move(const fs::path& from, const fs::path& to) {

     const fs::path path_ff = path_ff::get_path();

     fs::path from_path_for_copy = HFILEF::get_fetch_full_path(from, path_ff);
     fs::path to_path_for_copy = HFILEF::get_fetch_full_path(to, path_ff);

     if (fs::is_directory(to_path_for_copy)) {
          to_path_for_copy /= from_path_for_copy.filename();
     }

     if (fs::is_symlink(from_path_for_copy)) {
          print_warning("cannot overwrite symlink!");
          fs::copy_symlink(from_path_for_copy, to_path_for_copy);
          return;
     }

     fs::copy(from_path_for_copy, to_path_for_copy,
                    fs::copy_options::overwrite_existing |
                    fs::copy_options::recursive);
}

//============================
//        print message
//============================
void print_success(const std::string &msg, const fs::path& source,
                    const fs::path& target) {
     std::println("[SYSTEM] {} from {} to {}", msg, source.string(),
                    target.string());
}

void print_error(const std::string &err) {
     std::println(std::cerr, "[ERROR] {}", err);
}
void print_err_exists(const fs::path& path) {
     std::println(std::cerr, "[ERROR_COPY] {} already exists", path.string());
     std::println("you can to overwrite in parameter -> -ovr / --overwrite to overwrite file");
}
void print_error_exception(const std::string &err, const std::exception& exception,
                          const bool& isCritical) {
     if (isCritical) {
          std::println(std::cerr, "[CRITICAL_ERROR_COPY] {}: {}", err, exception.what());
     }
     else {
          std::println(std::cerr, "[ERROR_COPY] {}: {}", err, exception.what());
     }
}

void print_warning(const std::string &msg) {
     std::println("[WARNING] {}", msg);
}
