/* Copyright (c) 2012 BDT Media Automation GmbH
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * ConfigureTest.h
 *
 *  Created on: Aug 31, 2012
 *      Author: More Zeng
 */


#pragma once


class ConfigureTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE( ConfigureTest );
    CPPUNIT_TEST( testConfigure );
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp();
    void tearDown();

    void testConfigure();
};

