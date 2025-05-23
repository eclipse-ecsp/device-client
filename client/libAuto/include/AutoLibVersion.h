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
* \file AutoLibVersion.h
*
* \brief This file maintains the version of Auto library
********************************************************************************
*/

#ifdef INCLUDE_IGNITE_AUTO

#ifndef AUTO_LIB_VERSION_H
#define AUTO_LIB_VERSION_H

/**
 * Macro for IgniteAnalytics library version.
 * Define it if it is not set externally.
 */
#if !defined(AUTO_LIB_VERSION)
#define AUTO_LIB_VERSION "1.0.0"
#endif /* IGNITE_ANALYTICS_VERSION */

/**
 * Macro for Auto library version with date and time info
 */
#define AUTO_LIB_VERSION_TS AUTO_LIB_VERSION " " __DATE__ " " __TIME__

#endif /* AUTO_LIB_VERSION_H*/

#endif /* INCLUDE_IGNITE_AUTO */
