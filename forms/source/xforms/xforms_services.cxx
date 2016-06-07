/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * This file incorporates work covered by the following license notice:
 *
 *   Licensed to the Apache Software Foundation (ASF) under one or more
 *   contributor license agreements. See the NOTICE file distributed
 *   with this work for additional information regarding copyright
 *   ownership. The ASF licenses this file to you under the Apache
 *   License, Version 2.0 (the "License"); you may not use this file
 *   except in compliance with the License. You may obtain a copy of
 *   the License at http://www.apache.org/licenses/LICENSE-2.0 .
 */

#include "model.hxx"
#include "NameContainer.hxx"

#include <com/sun/star/beans/XPropertySet.hpp>
#include <com/sun/star/uno/Reference.hxx>
#include <com/sun/star/uno/XComponentContext.hpp>
#include <com/sun/star/uno/XInterface.hpp>
#include <cppuhelper/supportsservice.hxx>

using namespace ::com::sun::star;

namespace {

class Implementation:
    public cppu::ImplInheritanceHelper<
        NameContainer<css::uno::Reference<css::beans::XPropertySet>>,
        css::lang::XServiceInfo>
{
    OUString SAL_CALL getImplementationName()
        throw (css::uno::RuntimeException, std::exception) override
    { return OUString("com.sun.star.form.XForms"); }

    sal_Bool SAL_CALL supportsService(OUString const & ServiceName)
        throw (css::uno::RuntimeException, std::exception) override
    { return cppu::supportsService(this, ServiceName); }

    css::uno::Sequence<OUString> SAL_CALL getSupportedServiceNames()
        throw (css::uno::RuntimeException, std::exception) override
    {
        return css::uno::Sequence<OUString>{"com.sun.star.xforms.XForms"};
    }
};

}

extern "C" SAL_DLLPUBLIC_EXPORT uno::XInterface* SAL_CALL
com_sun_star_form_XForms_get_implementation(uno::XComponentContext*,
        uno::Sequence<uno::Any> const &)
{
    return cppu::acquire(new Implementation);
}

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */