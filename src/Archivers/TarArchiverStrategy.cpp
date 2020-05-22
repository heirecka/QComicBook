/*
 * This file is a part of QComicBook.
 *
 * Copyright (C) 2005-2009 Pawel Stolowski <stolowski@gmail.com>
 *
 * QComicBook is free software; you can redestribute it and/or modify it
 * under terms of GNU General Public License by Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY. See GPL for more details.
 */

#include "TarArchiverStrategy.h"
#include "Utility.h"

using namespace QComicBook;
using Utility::which;

TarArchiverStrategy::TarArchiverStrategy()
    : ArchiverStrategy("cbt", FileSignature())
{
}

TarArchiverStrategy::~TarArchiverStrategy()
{
}

void TarArchiverStrategy::configure()
{
    addExtension(".tar");
    addExtension(".cbt");
    setExecutables("tar");

    if (which("tar") != QString())
    {
        setExtractArguments("tar -xvf @F");
        setListArguments("tar -tf @F");
        setSupported();
    }
}
