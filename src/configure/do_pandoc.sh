#!/usr/bin/bash


# markdown_phpextra (PHP Markdown Extra)
# markdown_github (deprecated GitHub-Flavored Markdown)
# markdown_mmd (MultiMarkdown)
# markdown_strict (Markdown.pl)
# commonmark (CommonMark)
# gfm (Github-Flavored Markdown)


# pandoc -f html -t markdown -s -i ../docs/doxy/html/filetime_8cpp.html -o ../docs/md/filetime_html.md


pandoc -s -i ./docs/doxy/html/filetime_8cpp.html -t markdown | grep -v "^:" | grep -v '^```' | grep -v '<!-- -->' | sed -e ':again' -e N -e '$!b again' -e 's/{[^}]*}//g' > ./docs/md/filetime_html_2.md

pandoc -s -i ./docs/doxy/html/filetime_8cpp.html -t gfm | grep -v "^:" | grep -v '^```' | grep -v '<!-- -->' | sed -e ':again' -e N -e '$!b again' -e 's/{[^}]*}//g' > ./docs/md/filetime_html_3.md

# pandoc -s -f plain -i ./docs/dependencies.txt -t gfm ./docs/md/dependencies.md
