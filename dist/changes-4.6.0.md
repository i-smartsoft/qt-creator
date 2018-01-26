Qt Creator version 4.6 contains bug fixes and new features.

The most important changes are listed in this document. For a complete
list of changes, see the Git log for the Qt Creator sources that
you can check out from the public Git repository. For example:

    git clone git://code.qt.io/qt-creator/qt-creator.git
    git log --cherry-pick --pretty=oneline origin/4.5..v4.6.0

General

* Locator
    * Added filter `b` for bookmarks
    * Added filter `t` for triggering items from main menu
    * Added filter `=` for evaluating JavaScript expressions
      (QTCREATORBUG-14380)
* File System View
    * Added bread crumbs for file path (QTCREATORBUG-19203)
    * Added `Add New`, `Rename`, `Remove File`, `Diff Against Current File`
      (QTCREATORBUG-19213, QTCREATORBUG-19209, QTCREATORBUG-19208,
      QTCREATORBUG-19211)
* Added restoration of search flags when choosing search term from history

Editing

* Added option to display annotations between lines (QTCREATORBUG-19181)
* Fixed that editor could jump to end of file when editing in a different split
  (QTCREATORBUG-19550)

All Projects

* Added filtering to project kit setup page

QMake Projects

CMake Projects

Qbs Projects

* Added option to add library paths to dependencies (QTCREATORBUG-19274)

C++ Support

* Clang Code Model
    * Switched to Clang 5.0, adding support for C++17
    * Implemented information tool tips, which improves type information
      including resolution of `auto` types (QTCREATORBUG-11259)
    * Integrated Clang-Tidy and Clazy.
      Enable checks in Options > C++ > Code Model > Clang Plugins
    * Added renaming of local symbols
    * Added separate highlighting for function definitions (QTCREATORBUG-16625)

QML Support

* Added inline annotations for issues from code model

Python Support

Debugging

* Split `Expressions` view from `Locals` view (QTCREATORBUG-19167)

QML Profiler

Qt Quick Designer

* Added font and text properties from Qt 5.10
* Fixed that items blurred when zooming in
* Fixed crash when changing control focus policy (QTCREATORBUG-19563)

Version Control Systems

* Git
    * Added `Recover Deleted Files`
    * Added `Reload` button to `git log` and `git blame`
* Gerrit
    * Added support for private and work-in-progress changes for
      Gerrit 2.15 and later

Diff Viewer

* Added folding for files and chunks

Test Integration

* Added grouping of test cases (QTCREATORBUG-17979)
* Google Test
    * Fixed detection of crashed tests (QTCREATORBUG-19565)

Beautifier

Model Editor

* Added support for text alignment
* Added support for multi-line object names
* Added support for dragging items onto model editor from more panes
* Added `Export Selected Elements`
* Added `Flat` visual role
* Added `Add Related Elements` to diagram context menu
* Added wizard for scratch models
* Fixed issue with selecting items (QTCREATORBUG-18368)

SCXML Editor

Platform Specific

Windows

* Added support for the [heob](https://github.com/ssbssa/heob/releases)
  memory analyzer
* Fixed detection of CDB in non-default installation roots

macOS

Android

* Fixed issues with GCC include directories in Clang code model

iOS

Universal Windows Platform

Remote Linux

* Fixed that remote application was not killed before deployment
  (QTCREATORBUG-19326)

Credits for these changes go to:  
Adam Treat  
Alessandro Portale  
Alexandru Croitor  
Andre Hartmann  
André Pönitz  
Christian Gagneraud  
Christian Kandeler  
Christian Stenger  
Daniel Engelke  
David Schulz  
Eike Ziller  
Friedemann Kleint  
Hannes Domani  
Hugo Holgersson  
Ivan Donchevskii  
Jake Petroules  
Jaroslaw Kobus  
Jochen Becher  
Jörg Bornemann  
Marco Benelli  
Marco Bubke  
Mitch Curtis  
Nikita Baryshnikov  
Nikolai Kosjar  
Oliver Wolff  
Orgad Shaneh  
Oswald Buddenhagen  
Przemyslaw Gorszkowski  
Robert Löhning  
Thomas Hartmann  
Tim Jenssen  
Tobias Hunger  
Tomasz Olszak  
Tor Arne Vestbø  
Ulf Hermann  
Vikas Pachdha