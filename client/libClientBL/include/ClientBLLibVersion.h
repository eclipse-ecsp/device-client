/*******************************************************************************
 * Copyright (c) 2023-24 Harman International
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * SPDX-License-Identifier: Apache-2.0
 ******************************************************************************/

/*!
********************************************************************************
* \file ClientBLLibVersion.h
*
* \brief This file is to maintain the version of ClientBL library
********************************************************************************
*/

#ifndef CLIENTBL_LIB_VERSION_H
#define CLIENTBL_LIB_VERSION_H

/**
 * Macro for ClientBL library version.
 * Define it if it is not set externally.
 */
#if !defined(CLIENTBL_LIB_VERSION)
#define CLIENTBL_LIB_VERSION "1.0.0"
#endif /* CLIENTBL_LIB_VERSION */

/**
 * Macro for ClientBL library version with date and time info
 */
#define CLIENTBL_LIB_VERSION_TS CLIENTBL_LIB_VERSION " " __DATE__ " " __TIME__

#endif /* CLIENTBL_LIB_VERSION_H */
