<div id="top" align="center">
<h1>Webserver to check content of a Docker image</h1>

<p>Crow webserver to check docker image content</p>

[Report Issue](https://github.com/Zheng-Bote/web-srv_image-tester/issues) [Request Feature](https://github.com/Zheng-Bote/web-srv_image-tester/pulls)

[![MIT License](https://img.shields.io/badge/License-MIT-green.svg)](https://choosealicense.com/licenses/mit/)
[![GitHub release (latest by date)](https://img.shields.io/github/v/release/Zheng-Bote/web-srv_image-tester?logo=GitHub)](https://github.com/Zheng-Bote/web-srv_image-tester/releases)

</div>

<hr>

<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->
**Table of Contents**

- [Description](#description)
    - [Features](#features)
  - [Status](#status)
    - [Application / Tool](#application--tool)
      - [README / Documentation](#readme--documentation)
      - [other Markdown files](#other-markdown-files)
- [Documentation](#documentation)
  - [Screenshots](#screenshots)
    - [Startpage](#startpage)
    - [list directory content with permissions](#list-directory-content-with-permissions)
    - [get directory size in Bytes](#get-directory-size-in-bytes)
    - [create (nested) directories](#create-nested-directories)
    - [upload a file](#upload-a-file)
    - [crow_web program info](#crow_web-program-info)
    - [list program (inifile) configuration](#list-program-inifile-configuration)
- [Usage](#usage)
  - [without parameter](#without-parameter)
  - [Parameters](#parameters)
  - [Inifile](#inifile)
- [Installation](#installation)
  - [Linux](#linux)
    - [AppImage](#appimage)
    - [Debian package (deb)](#debian-package-deb)
  - [from Source / Developement](#from-source--developement)
    - [Dependencies](#dependencies)
      - [CMake](#cmake)
      - [Crow](#crow)
      - [inifile-cpp](#inifile-cpp)
      - [OpenSSL (optional)](#openssl-optional)
    - [folder structure](#folder-structure)
- [Authors and License](#authors-and-license)
  - [License](#license)
  - [Authors](#authors)
    - [Code Contributors](#code-contributors)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

<hr>

# Description

![CXX](https://img.shields.io/badge/C++-23-blue?logo=cplusplus)
![HTML5](https://img.shields.io/badge/HTML-5+-E34F26?logo=html5)
![Javascript](https://img.shields.io/badge/JavaScript-vanilla-3178C6?logo=javascript)

C++23 Crow webserver to check the content of a Docker image.

### Features

- \[ ] advanced-super-extra-special feature xyz

  <br>

- \[x] OSS and license
- \[x] works as designed
- \[ ] no bugs

<br>

- \[x] some more or less usefull Github Actions for GH-repo, GH-pages, GH-wiki, CI/CD-Pipelines
- \[x] Packagemanager (CMake)
- \[x] Installation routine (AppImage)
- \[ ] portable application
- \[x] supports SSL (https)

<br>

- \[ ] runs on DOS/Windows
- \[ ] runs on MacOS
- \[x] runs on Linux
- \[ ] runs on iOS
- \[ ] runs on Android
- \[ ] runs on HarmonyOS

<p align="right">(<a href="#top">back to top</a>)</p>

## Status

### Application / Tool

![GitHub Created At](https://img.shields.io/github/created-at/Zheng-Bote/web-srv_image-tester)
[![GitHub release (latest by date)](https://img.shields.io/github/v/release/Zheng-Bote/web-srv_image-tester?logo=GitHub)](https://github.com/Zheng-Bote/web-srv_image-tester)
![Status](https://img.shields.io/badge/Status-useable-green)
![Status](https://img.shields.io/badge/Status-works_as_designed-green)
![GitHub Release Date](https://img.shields.io/github/release-date/Zheng-Bote/web-srv_image-tester)

![GitHub Issues](https://img.shields.io/github/issues/Zheng-Bote/web-srv_image-tester)
![GitHub Pull Requests](https://img.shields.io/github/issues-pr/Zheng-Bote/web-srv_image-tester)

#### README / Documentation

[![Repo - create Repo-Tree in README.md](https://github.com/Zheng-Bote/web-srv_image-tester/actions/workflows/repo-create_tree_readme.yml/badge.svg)](https://github.com/Zheng-Bote/web-srv_image-tester/actions/workflows/repo-create_tree_readme.yml)
[![Repo - add Actions In/Out to README](https://github.com/Zheng-Bote/web-srv_image-tester/actions/workflows/repo-actions_docu.yml/badge.svg)](https://github.com/Zheng-Bote/web-srv_image-tester/actions/workflows/repo-actions_docu.yml)

[![Repo - update Readme](https://github.com/Zheng-Bote/web-srv_image-tester/actions/workflows/repo-call_Readme.yml/badge.svg)](https://github.com/Zheng-Bote/web-srv_image-tester/actions/workflows/repo-call_Readme.yml)

#### other Markdown files

[![Repo - create TOC of Markdown files](https://github.com/Zheng-Bote/web-srv_image-tester/actions/workflows/repo-create_doctoc_md.yml/badge.svg)](https://github.com/Zheng-Bote/web-srv_image-tester/actions/workflows/repo-create_doctoc_md.yml)

create ToC in Markdown files in folders

- .github/actions/\*\*
- .github/workflows/\*\*
- dist/\*\*
- docs/\*\*

<p align="right">(<a href="#top">back to top</a>)</p>

# Documentation

## Screenshots

### Startpage

![App Screenshot](https://github.com/Zheng-Bote/web-srv_image-tester/blob/main/docs/img/01_en.png)

### list directory content with permissions

![App Screenshot](https://github.com/Zheng-Bote/web-srv_image-tester/blob/main/docs/img/02_en.png)

### get directory size in Bytes

![App Screenshot](https://github.com/Zheng-Bote/web-srv_image-tester/blob/main/docs/img/03_en.png)

### create (nested) directories

![App Screenshot](https://github.com/Zheng-Bote/web-srv_image-tester/blob/main/docs/img/04_en.png)

### upload a file

![App Screenshot](https://github.com/Zheng-Bote/web-srv_image-tester/blob/main/docs/img/05_en.png)

### crow_web program info

![App Screenshot](https://github.com/Zheng-Bote/web-srv_image-tester/blob/main/docs/img/06_en.png)

### list program (inifile) configuration

![App Screenshot](https://github.com/Zheng-Bote/web-srv_image-tester/blob/main/docs/img/07_en.png)

<p align="right">(<a href="#top">back to top</a>)</p>

# Usage

## without parameter

the program looks for an Inifile `<program_folder>/<prog_name>.ini`

```bash
./crow_web
./crow_web-x86_64.AppImage
```

## Parameters

Execute the program with a given Inifile.

| Parameter | Type     | Description                      |
| :-------- | :------- | :------------------------------- |
| inifile   | `string` | _Optional_ `<path_to>/<inifile>` |

```bash
./crow_web static/crow_web.ini
./crow_web-x86_64.AppImage static/crow_web.ini
```

## Inifile

```inifile
[Webserver]
url = http://localhost                            # currently not in use
port = 8182
ssl_certfile = /etc/crow_web/ssl/cert.pem
ssl_keyfile = /etc/crow_web/ssl/key.pem
ssl_pemfile = none
use_ssl = false
write_dir = /tmp                                  # Path to the directory to write files
upload_dir = /tmp/crow_web/uploads                # Path to the directory where uploaded files are stored
```

<p align="right">(<a href="#top">back to top</a>)</p>

# Installation

## Linux

### AppImage

No installation needed, the AppImage includes all dependencies. Just start in a shell the AppImage `crow_web-x86_64.AppImage`, optional with a given Inifile `crow_web-x86_64.AppImage <pathToInifile>`

### Debian package (deb)

**_still under construction_**

## from Source / Developement

Compiled with Ubuntu clang version 18.1.3 (1ubuntu1), Target: x86_64-pc-linux-gnu (https://clang.llvm.org/cxx_status.html)

### using SSL and compression

CMakeLists.txt

```CMakeLists.txt
set(CROW_ENABLE_SSL ON)
set(CROW_ENABLE_COMPRESSION ON)
```

> \[!NOTE]
> should work with any compiler with C++23 support

### Dependencies

> \[!NOTE]
> All licenses are therefore Open Source.

#### CMake

CMake: A Powerful Software Build System

[![CMake](https://img.shields.io/badge/CMake-v3.23+-064F8C?logo=cmake)](https://github.com/conan-io/conan)
[![BSD-3 License](https://img.shields.io/badge/License-BSD_3-green.svg)](https://choosealicense.com/licenses/bsd-3-clause/)

#### Crow

Crow is a C++ framework for creating HTTP or Websocket web services. A Fast and Easy to use microframework for the web.

https://crowcpp.org/master/

[![BSD-3 License](https://img.shields.io/badge/License-BSD_3-green.svg)](https://choosealicense.com/licenses/bsd-3-clause/)

#### inifile-cpp

inifile-cpp is a simple and easy to use single header-only ini file en- and decoder for C++.

https://github.com/Rookfighter/inifile-cpp

[![MIT License](https://img.shields.io/badge/License-MIT-green.svg)](https://choosealicense.com/licenses/mit/)

#### OpenSSL (optional)

> \[!NOTE]
> only needed if the web-applicationserver should run secured with https

OpenSSL - a robust, commercial-grade, full-featured toolkit for general-purpose cryptography and secure communication.

https://www.openssl.org/

[![Apache License](https://img.shields.io/badge/License-Apache-green.svg)](https://choosealicense.com/licenses/apache/)

<p align="right">(<a href="#top">back to top</a>)</p>

### folder structure

<!-- readme-tree start -->
```
.
├── .github
│   ├── actions
│   │   └── doctoc
│   │       ├── README.md
│   │       ├── action.yml
│   │       └── dist
│   │           ├── index.js
│   │           ├── index.js.map
│   │           ├── licenses.txt
│   │           └── sourcemap-register.js
│   └── workflows
│       ├── ghp-call_Readme.yml
│       ├── ghp-create_doctoc.yml
│       ├── ghp-markdown_index.yml
│       ├── repo-actions_docu.yml
│       ├── repo-call_Readme.yml
│       ├── repo-create_doctoc.yml_
│       ├── repo-create_doctoc_md.yml
│       └── repo-create_tree_readme.yml
├── .gitignore
├── LICENSE
├── README.md
├── do_compile.sh
├── docs
│   ├── doxygen
│   │   ├── annotated.html
│   │   ├── annotated_dup.js
│   │   ├── bc_s.png
│   │   ├── bc_sd.png
│   │   ├── classDateTime-members.html
│   │   ├── classDateTime.html
│   │   ├── classDateTime.js
│   │   ├── classFilesystem-members.html
│   │   ├── classFilesystem.html
│   │   ├── classFilesystem.js
│   │   ├── classInifile-members.html
│   │   ├── classInifile.html
│   │   ├── classSnippets-members.html
│   │   ├── classSnippets.html
│   │   ├── classSnippets.js
│   │   ├── classes.html
│   │   ├── classini_1_1IniField-members.html
│   │   ├── classini_1_1IniField.html
│   │   ├── classini_1_1IniFileBase-members.html
│   │   ├── classini_1_1IniFileBase.html
│   │   ├── classini_1_1IniFileBase.js
│   │   ├── classini_1_1IniFileBase__coll__graph.map
│   │   ├── classini_1_1IniFileBase__coll__graph.md5
│   │   ├── classini_1_1IniFileBase__coll__graph.svg
│   │   ├── classini_1_1IniFileBase__inherit__graph.map
│   │   ├── classini_1_1IniFileBase__inherit__graph.md5
│   │   ├── classini_1_1IniFileBase__inherit__graph.svg
│   │   ├── classini_1_1IniSectionBase-members.html
│   │   ├── classini_1_1IniSectionBase.html
│   │   ├── classini_1_1IniSectionBase__coll__graph.map
│   │   ├── classini_1_1IniSectionBase__coll__graph.md5
│   │   ├── classini_1_1IniSectionBase__coll__graph.svg
│   │   ├── classini_1_1IniSectionBase__inherit__graph.map
│   │   ├── classini_1_1IniSectionBase__inherit__graph.md5
│   │   ├── classini_1_1IniSectionBase__inherit__graph.svg
│   │   ├── closed.png
│   │   ├── dir_d44c64559bbebec7f509842c48db8b23.html
│   │   ├── dir_d44c64559bbebec7f509842c48db8b23.js
│   │   ├── doc.svg
│   │   ├── docd.svg
│   │   ├── doxygen-awesome-darkmode-toggle.js
│   │   ├── doxygen-awesome-fragment-copy-button.js
│   │   ├── doxygen-awesome-interactive-toc.js
│   │   ├── doxygen-awesome-paragraph-link.js
│   │   ├── doxygen-awesome.css
│   │   ├── doxygen.css
│   │   ├── doxygen.svg
│   │   ├── dynsections.js
│   │   ├── files.html
│   │   ├── files_dup.js
│   │   ├── folderclosed.svg
│   │   ├── folderclosedd.svg
│   │   ├── folderopen.svg
│   │   ├── folderopend.svg
│   │   ├── functions.html
│   │   ├── functions_func.html
│   │   ├── graph_legend.html
│   │   ├── graph_legend.md5
│   │   ├── graph_legend.svg
│   │   ├── hierarchy.html
│   │   ├── hierarchy.js
│   │   ├── index.html
│   │   ├── inherit_graph_0.map
│   │   ├── inherit_graph_0.md5
│   │   ├── inherit_graph_0.svg
│   │   ├── inherit_graph_1.map
│   │   ├── inherit_graph_1.md5
│   │   ├── inherit_graph_1.svg
│   │   ├── inherit_graph_10.map
│   │   ├── inherit_graph_10.md5
│   │   ├── inherit_graph_10.svg
│   │   ├── inherit_graph_11.map
│   │   ├── inherit_graph_11.md5
│   │   ├── inherit_graph_11.svg
│   │   ├── inherit_graph_12.map
│   │   ├── inherit_graph_12.md5
│   │   ├── inherit_graph_12.svg
│   │   ├── inherit_graph_13.map
│   │   ├── inherit_graph_13.md5
│   │   ├── inherit_graph_13.svg
│   │   ├── inherit_graph_14.map
│   │   ├── inherit_graph_14.md5
│   │   ├── inherit_graph_14.svg
│   │   ├── inherit_graph_15.map
│   │   ├── inherit_graph_15.md5
│   │   ├── inherit_graph_15.svg
│   │   ├── inherit_graph_16.map
│   │   ├── inherit_graph_16.md5
│   │   ├── inherit_graph_16.svg
│   │   ├── inherit_graph_17.map
│   │   ├── inherit_graph_17.md5
│   │   ├── inherit_graph_17.svg
│   │   ├── inherit_graph_18.map
│   │   ├── inherit_graph_18.md5
│   │   ├── inherit_graph_18.svg
│   │   ├── inherit_graph_19.map
│   │   ├── inherit_graph_19.md5
│   │   ├── inherit_graph_19.svg
│   │   ├── inherit_graph_2.map
│   │   ├── inherit_graph_2.md5
│   │   ├── inherit_graph_2.svg
│   │   ├── inherit_graph_20.map
│   │   ├── inherit_graph_20.md5
│   │   ├── inherit_graph_20.svg
│   │   ├── inherit_graph_21.map
│   │   ├── inherit_graph_21.md5
│   │   ├── inherit_graph_21.svg
│   │   ├── inherit_graph_22.map
│   │   ├── inherit_graph_22.md5
│   │   ├── inherit_graph_22.svg
│   │   ├── inherit_graph_23.map
│   │   ├── inherit_graph_23.md5
│   │   ├── inherit_graph_23.svg
│   │   ├── inherit_graph_3.map
│   │   ├── inherit_graph_3.md5
│   │   ├── inherit_graph_3.svg
│   │   ├── inherit_graph_4.map
│   │   ├── inherit_graph_4.md5
│   │   ├── inherit_graph_4.svg
│   │   ├── inherit_graph_5.map
│   │   ├── inherit_graph_5.md5
│   │   ├── inherit_graph_5.svg
│   │   ├── inherit_graph_6.map
│   │   ├── inherit_graph_6.md5
│   │   ├── inherit_graph_6.svg
│   │   ├── inherit_graph_7.map
│   │   ├── inherit_graph_7.md5
│   │   ├── inherit_graph_7.svg
│   │   ├── inherit_graph_8.map
│   │   ├── inherit_graph_8.md5
│   │   ├── inherit_graph_8.svg
│   │   ├── inherit_graph_9.map
│   │   ├── inherit_graph_9.md5
│   │   ├── inherit_graph_9.svg
│   │   ├── inherits.html
│   │   ├── inicpp_8h.html
│   │   ├── inicpp_8h.js
│   │   ├── inicpp_8h__dep__incl.map
│   │   ├── inicpp_8h__dep__incl.md5
│   │   ├── inicpp_8h__dep__incl.svg
│   │   ├── inicpp_8h__incl.map
│   │   ├── inicpp_8h__incl.md5
│   │   ├── inicpp_8h__incl.svg
│   │   ├── inicpp_8h_source.html
│   │   ├── jquery.js
│   │   ├── menu.js
│   │   ├── menudata.js
│   │   ├── minus.svg
│   │   ├── minusd.svg
│   │   ├── nav_f.png
│   │   ├── nav_fd.png
│   │   ├── nav_g.png
│   │   ├── nav_h.png
│   │   ├── nav_hd.png
│   │   ├── navtree.css
│   │   ├── navtree.js
│   │   ├── navtreedata.js
│   │   ├── navtreeindex0.js
│   │   ├── open.png
│   │   ├── plus.svg
│   │   ├── plusd.svg
│   │   ├── resize.js
│   │   ├── rz__config_8h_source.html
│   │   ├── rz__datetime_8cpp.html
│   │   ├── rz__datetime_8cpp__incl.map
│   │   ├── rz__datetime_8cpp__incl.md5
│   │   ├── rz__datetime_8cpp__incl.svg
│   │   ├── rz__datetime_8hpp.html
│   │   ├── rz__datetime_8hpp.js
│   │   ├── rz__datetime_8hpp__dep__incl.map
│   │   ├── rz__datetime_8hpp__dep__incl.md5
│   │   ├── rz__datetime_8hpp__dep__incl.svg
│   │   ├── rz__datetime_8hpp__incl.map
│   │   ├── rz__datetime_8hpp__incl.md5
│   │   ├── rz__datetime_8hpp__incl.svg
│   │   ├── rz__datetime_8hpp_source.html
│   │   ├── rz__filesystem_8cpp.html
│   │   ├── rz__filesystem_8cpp__incl.map
│   │   ├── rz__filesystem_8cpp__incl.md5
│   │   ├── rz__filesystem_8cpp__incl.svg
│   │   ├── rz__filesystem_8h.html
│   │   ├── rz__filesystem_8h.js
│   │   ├── rz__filesystem_8h__dep__incl.map
│   │   ├── rz__filesystem_8h__dep__incl.md5
│   │   ├── rz__filesystem_8h__dep__incl.svg
│   │   ├── rz__filesystem_8h__incl.map
│   │   ├── rz__filesystem_8h__incl.md5
│   │   ├── rz__filesystem_8h__incl.svg
│   │   ├── rz__filesystem_8h_source.html
│   │   ├── rz__html_8h_source.html
│   │   ├── rz__inifile_8cpp.html
│   │   ├── rz__inifile_8cpp__incl.map
│   │   ├── rz__inifile_8cpp__incl.md5
│   │   ├── rz__inifile_8cpp__incl.svg
│   │   ├── rz__inifile_8hpp_source.html
│   │   ├── rz__snippets_8hpp.html
│   │   ├── rz__snippets_8hpp.js
│   │   ├── rz__snippets_8hpp__incl.map
│   │   ├── rz__snippets_8hpp__incl.md5
│   │   ├── rz__snippets_8hpp__incl.svg
│   │   ├── rz__snippets_8hpp_source.html
│   │   ├── rz__string__lib_8hpp_source.html
│   │   ├── search
│   │   │   ├── all_0.js
│   │   │   ├── all_1.js
│   │   │   ├── all_2.js
│   │   │   ├── all_3.js
│   │   │   ├── all_4.js
│   │   │   ├── all_5.js
│   │   │   ├── all_6.js
│   │   │   ├── all_7.js
│   │   │   ├── all_8.js
│   │   │   ├── all_9.js
│   │   │   ├── all_a.js
│   │   │   ├── all_b.js
│   │   │   ├── all_c.js
│   │   │   ├── classes_0.js
│   │   │   ├── classes_1.js
│   │   │   ├── classes_2.js
│   │   │   ├── classes_3.js
│   │   │   ├── classes_4.js
│   │   │   ├── close.svg
│   │   │   ├── files_0.js
│   │   │   ├── files_1.js
│   │   │   ├── functions_0.js
│   │   │   ├── functions_1.js
│   │   │   ├── functions_2.js
│   │   │   ├── functions_3.js
│   │   │   ├── functions_4.js
│   │   │   ├── functions_5.js
│   │   │   ├── functions_6.js
│   │   │   ├── functions_7.js
│   │   │   ├── functions_8.js
│   │   │   ├── functions_9.js
│   │   │   ├── functions_a.js
│   │   │   ├── functions_b.js
│   │   │   ├── functions_c.js
│   │   │   ├── mag.svg
│   │   │   ├── mag_d.svg
│   │   │   ├── mag_sel.svg
│   │   │   ├── mag_seld.svg
│   │   │   ├── search.css
│   │   │   ├── search.js
│   │   │   └── searchdata.js
│   │   ├── splitbar.png
│   │   ├── splitbard.png
│   │   ├── structFilesystem_1_1fileStructure-members.html
│   │   ├── structFilesystem_1_1fileStructure.html
│   │   ├── structini_1_1Convert.html
│   │   ├── structini_1_1Convert_3_01bool_01_4-members.html
│   │   ├── structini_1_1Convert_3_01bool_01_4.html
│   │   ├── structini_1_1Convert_3_01char_01_4-members.html
│   │   ├── structini_1_1Convert_3_01char_01_4.html
│   │   ├── structini_1_1Convert_3_01char_01_5_01_4-members.html
│   │   ├── structini_1_1Convert_3_01char_01_5_01_4.html
│   │   ├── structini_1_1Convert_3_01char_0fn_0e_4-members.html
│   │   ├── structini_1_1Convert_3_01char_0fn_0e_4.html
│   │   ├── structini_1_1Convert_3_01const_01char_01_5_01_4-members.html
│   │   ├── structini_1_1Convert_3_01const_01char_01_5_01_4.html
│   │   ├── structini_1_1Convert_3_01double_01_4-members.html
│   │   ├── structini_1_1Convert_3_01double_01_4.html
│   │   ├── structini_1_1Convert_3_01float_01_4-members.html
│   │   ├── structini_1_1Convert_3_01float_01_4.html
│   │   ├── structini_1_1Convert_3_01int_01_4-members.html
│   │   ├── structini_1_1Convert_3_01int_01_4.html
│   │   ├── structini_1_1Convert_3_01long_01_4-members.html
│   │   ├── structini_1_1Convert_3_01long_01_4.html
│   │   ├── structini_1_1Convert_3_01short_01_4-members.html
│   │   ├── structini_1_1Convert_3_01short_01_4.html
│   │   ├── structini_1_1Convert_3_01std_1_1string_01_4-members.html
│   │   ├── structini_1_1Convert_3_01std_1_1string_01_4.html
│   │   ├── structini_1_1Convert_3_01unsigned_01char_01_4-members.html
│   │   ├── structini_1_1Convert_3_01unsigned_01char_01_4.html
│   │   ├── structini_1_1Convert_3_01unsigned_01int_01_4-members.html
│   │   ├── structini_1_1Convert_3_01unsigned_01int_01_4.html
│   │   ├── structini_1_1Convert_3_01unsigned_01long_01_4-members.html
│   │   ├── structini_1_1Convert_3_01unsigned_01long_01_4.html
│   │   ├── structini_1_1Convert_3_01unsigned_01short_01_4-members.html
│   │   ├── structini_1_1Convert_3_01unsigned_01short_01_4.html
│   │   ├── structini_1_1StringInsensitiveLess-members.html
│   │   ├── structini_1_1StringInsensitiveLess.html
│   │   ├── sync_off.png
│   │   ├── sync_on.png
│   │   ├── tab_a.png
│   │   ├── tab_ad.png
│   │   ├── tab_b.png
│   │   ├── tab_bd.png
│   │   ├── tab_h.png
│   │   ├── tab_hd.png
│   │   ├── tab_s.png
│   │   ├── tab_sd.png
│   │   └── tabs.css
│   └── img
│       ├── 01_en.png
│       ├── 02_en.png
│       ├── 03_en.png
│       ├── 04_en.png
│       ├── 05_en.png
│       ├── 06_en.png
│       └── 07_en.png
├── src
│   ├── CMakeLists.txt
│   ├── configure
│   │   ├── ClangTidy.cmake
│   │   ├── Doxygen.cmake
│   │   ├── do_pandoc.sh
│   │   ├── doxygen.cfg
│   │   ├── extra_headers
│   │   └── rz_config.h.in
│   ├── include
│   │   ├── inicpp.h
│   │   ├── rz_config.h
│   │   ├── rz_datetime.cpp
│   │   ├── rz_datetime.hpp
│   │   ├── rz_filesystem.cpp
│   │   ├── rz_filesystem.h
│   │   ├── rz_html.h
│   │   ├── rz_inifile.cpp
│   │   ├── rz_inifile.hpp
│   │   ├── rz_snippets.cpp
│   │   ├── rz_snippets.hpp
│   │   └── rz_string_lib.hpp
│   ├── main.cpp
│   ├── static
│   │   ├── crow_web.ini
│   │   ├── favicon.ico
│   │   ├── favicon.svg
│   │   ├── index.html
│   │   ├── main.css
│   │   └── main.js
│   └── templates
│       ├── about.html
│       └── template.html
└── tree.bak

15 directories, 345 files
```
<!-- readme-tree end -->

<p align="right">(<a href="#top">back to top</a>)</p>

# Authors and License

## License

**MIT License**

[![MIT License](https://img.shields.io/badge/License-MIT-green.svg)](https://choosealicense.com/licenses/mit/)

Copyright (c) 2025 ZHENG Robert

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

        https://choosealicense.com/licenses/mit/

## Authors

- [![Zheng Robert](https://img.shields.io/badge/Github-Zheng_Robert-black?logo=github)](https://www.github.com/Zheng-Bote)

### Code Contributors

![Contributors](https://img.shields.io/github/contributors/Zheng-Bote/web-srv_image-tester?color=dark-green)

[![Zheng Robert](https://img.shields.io/badge/Github-Zheng_Robert-black?logo=github)](https://www.github.com/Zheng-Bote)

<hr>

:vulcan_salute:

<p align="right">(<a href="#top">back to top</a>)</p>
