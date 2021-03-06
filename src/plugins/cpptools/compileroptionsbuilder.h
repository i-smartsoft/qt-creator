/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of Qt Creator.
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 as published by the Free Software
** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
****************************************************************************/

#pragma once

#include "cpptools_global.h"

#include "projectpart.h"

namespace CppTools {

enum class UsePrecompiledHeaders : char { Yes, No };
enum class UseSystemHeader : char { Yes, No };
enum class UseTweakedHeaderPaths : char { Yes, No };
enum class UseToolchainMacros : char { Yes, No };
enum class UseLanguageDefines : char { Yes, No };

class CPPTOOLS_EXPORT CompilerOptionsBuilder
{
public:
    CompilerOptionsBuilder(const ProjectPart &projectPart,
                           UseSystemHeader useSystemHeader = UseSystemHeader::No,
                           UseToolchainMacros useToolchainMacros = UseToolchainMacros::Yes,
                           UseTweakedHeaderPaths useTweakedHeaderPaths = UseTweakedHeaderPaths::Yes,
                           UseLanguageDefines useLanguageDefines = UseLanguageDefines::No,
                           const QString &clangVersion = QString(),
                           const QString &clangResourceDirectory = QString());

    QStringList build(ProjectFile::Kind fileKind, UsePrecompiledHeaders usePrecompiledHeaders);
    QStringList options() const { return m_options; }

    // Add options based on project part
    virtual void addToolchainAndProjectMacros();
    void addWordWidth();
    void addToolchainFlags();
    void addHeaderPathOptions();
    void addPrecompiledHeaderOptions(UsePrecompiledHeaders usePrecompiledHeaders);
    void addMacros(const ProjectExplorer::Macros &macros);

    void addTargetTriple();
    void addExtraCodeModelFlags();
    void enableExceptions();
    void insertWrappedQtHeaders();
    void addOptionsForLanguage(bool checkForBorlandExtensions = true);
    void updateLanguageOption(ProjectFile::Kind fileKind);

    void addMsvcCompatibilityVersion();
    void undefineCppLanguageFeatureMacrosForMsvc2015();
    void addDefineFunctionMacrosMsvc();

    void addProjectConfigFileInclude();
    void undefineClangVersionMacrosForMsvc();

    // Add custom options
    void add(const QString &option) { m_options.append(option); }
    virtual void addExtraOptions() {}

    static UseToolchainMacros useToolChainMacros();

private:
    bool excludeDefineDirective(const ProjectExplorer::Macro &macro) const;
    QString includeDirOptionForPath(const QString &path) const;
    void addWrappedQtHeadersIncludePath(QStringList &list) const;

private:
    const ProjectPart &m_projectPart;

    const UseSystemHeader m_useSystemHeader;
    const UseToolchainMacros m_useToolchainMacros;
    const UseTweakedHeaderPaths m_useTweakedHeaderPaths;
    const UseLanguageDefines m_useLanguageDefines;

    const QString m_clangVersion;
    const QString m_clangResourceDirectory;

    QStringList m_options;
};

} // namespace CppTools
