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

#include "rule.h"

QT_BEGIN_NAMESPACE
class QStringList;
QT_END_NAMESPACE

namespace TextEditor {
namespace Internal {

class DynamicRule : public Rule
{
public:
    DynamicRule();
    ~DynamicRule() override;

    void setActive(const QString &active);
    bool isActive() const;

    virtual void replaceExpressions(const QStringList &captures);

private:
    virtual void doReplaceExpressions(const QStringList &captures) = 0;

    bool m_active;
};

void updateDynamicRules(const QList<QSharedPointer<Rule> > &rules, const QStringList &captures);

} // namespace Internal
} // namespace TextEditor
