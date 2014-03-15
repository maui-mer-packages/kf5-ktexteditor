/* This file is part of the KDE project
   Copyright (C) 2001-2014 Christoph Cullmann <cullmann@kde.org>
   Copyright (C) 2005-2014 Dominik Haumann <dhaumann@kde.org>

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public License
   along with this library; see the file COPYING.LIB.  If not, write to
   the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.
*/

#ifndef KDELIBS_KTEXTEDITOR_CONFIGPAGEINTERFACE_H
#define KDELIBS_KTEXTEDITOR_CONFIGPAGEINTERFACE_H

#include <ktexteditor_export.h>
#include <QObject>
#include <QIcon>

namespace KTextEditor
{

class ConfigPage;

/**
 * \brief Config page interface extension for the Editor and Plugin%s.
 *
 * \ingroup kte_group_plugin_extensions
 * \ingroup kte_group_editor_extensions
 */
class KTEXTEDITOR_EXPORT ConfigPageInterface
{
public:
    ConfigPageInterface();

    /**
     * Virtual destructor.
     */
    virtual ~ConfigPageInterface();

public:
    /**
     * Get the number of available config pages.
     * If a number < 1 is returned, it does not support config pages.
     * \return number of config pages
     * \see configPage()
     */
    virtual int configPages() const = 0;

    /**
     * Get the config page with the \p number, config pages from 0 to
     * configPages()-1 are available if configPages() > 0.
     * \param number index of config page
     * \param parent parent widget for config page
     * \return created config page or NULL, if the number is out of bounds
     * \see configPages()
     */
    virtual ConfigPage *configPage(int number, QWidget *parent) = 0;

private:
    class ConfigPageInterfacePrivate *const d;
};

}

Q_DECLARE_INTERFACE(KTextEditor::ConfigPageInterface, "org.kde.KTextEditor.ConfigPageInterface")

#endif

