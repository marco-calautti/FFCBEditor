Final Fantasy CC: The Crystal Bearers Text Editor
=======

This is a cross-platform tool written in C++ intended to be used to help people translating the dialogues' text of Final Fantasy CC: The Crystal Bearers. The game DVD contains 2 archives which can be unpacked with an external tool made by Vash. Once extracted, you can use this tool to edit files containing text.

This editor provides a database based system to store info about file types (each archive contains about 1500 files :P). Once the database is ready, you will be able to work only on necessary files. You can also specify a list of headers to be excluded while parsing files.

The core library makes extensive use of the core wxWidgets library. wxWidgets GUI components are used for the User Interface.

FFCBEditor is unicode enabled and multi-language using wxWidgets internationalization facilities (gettext).


*The game itself uses ISO latin 1 for encoding strings. So, any translation to an european like language can be achieved.*

For more informations on ISO latin 1 and supported languages see <a href="http://en.wikipedia.org/wiki/ISO/IEC_8859-1">ISO/IEC 8859-1</a>
