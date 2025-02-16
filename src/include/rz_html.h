#pragma once

#include <string>

namespace rz_html_lib
{

  const std::string HTML_HEADER = R"(<!DOCTYPE html>
<html lang="en" data-theme="dark">
<head>
  <meta charset="utf-8"/>
  <meta name="viewport" content="width=device-width, initial-scale=1" />
  <meta name="robots" content="index,follow" />
  
  <title>{{html_title}}</title>
  
  <link rel="icon" type="image/svg+xml" href="{{{ webserver_url }}}:{{ webserver_port}}/static/favicon.svg" />
  <link rel="alternate icon" href="{{{ webserver_url }}}:{{ webserver_port}}/static/favicon.ico" />
  <link rel="shortcut icon" href="{{{ webserver_url }}}:{{ webserver_port}}/static/favicon.ico" type="image/x-icon" />
</head>
<body id="body">
)";

  const std::string HTML_FOOTER = R"(

  </body>
</html>
)";

}