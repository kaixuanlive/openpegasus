//%LICENSE////////////////////////////////////////////////////////////////
//
// Licensed to The Open Group (TOG) under one or more contributor license
// agreements.  Refer to the OpenPegasusNOTICE.txt file distributed with
// this work for additional information regarding copyright ownership.
// Each contributor licenses this file to you under the OpenPegasus Open
// Source License; you may not use this file except in compliance with the
// License.
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
// IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
// CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
// TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
// SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//
//////////////////////////////////////////////////////////////////////////
/* NOCHKSRC */


#ifndef Pegasus_ClientException_h
#define Pegasus_ClientException_h

#include <Pegasus/Common/Config.h>
#include <Pegasus/Common/String.h>
#include <Pegasus/Common/Exception.h>
#include <Pegasus/Client/Linkage.h>

PEGASUS_NAMESPACE_BEGIN

/**
    An exception of this type indicates that the HTTP response from the CIM
    Server was improperly formed.
*/
class PEGASUS_CLIENT_LINKAGE CIMClientMalformedHTTPException
    : public Exception
{
public:
    ///
    CIMClientMalformedHTTPException(const String& message);
};

/**
    An exception of this type indicates that an HTTP error response was sent
    by the CIM Server.
*/
class PEGASUS_CLIENT_LINKAGE CIMClientHTTPErrorException : public Exception
{
public:
    ///
    CIMClientHTTPErrorException(
        Uint32 httpStatusCode,
        const String& cimError,
        const String& cimErrorDetail);
    ///
    CIMClientHTTPErrorException(const CIMClientHTTPErrorException& httpError);
    ///
    virtual ~CIMClientHTTPErrorException();

    ///
    Uint32 getCode() const;
    ///
    String getCIMError() const;
    ///
    String getCIMErrorDetail() const;
};

/**
    An exception of this type indicates that the CIM response sent by the
    CIM Server could not be decoded from XML.
*/
class PEGASUS_CLIENT_LINKAGE CIMClientXmlException : public Exception
{
public:
    ///
    CIMClientXmlException(const String& message);
};

/**
    An exception of this type indicates that the CIM response sent by the
    CIM Server contained unexpected data.
*/
class PEGASUS_CLIENT_LINKAGE CIMClientResponseException
    : public Exception
{
public:
    ///
    CIMClientResponseException(const String& message);
};

PEGASUS_NAMESPACE_END

#endif /* Pegasus_ClientException_h */
