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

#include "CIgniteConnHealthCheckAPI.h"
#include "CHttpRequest.h"
#include "CHttpResponse.h"

#ifdef PREFIX
#undef PREFIX
#endif
#define PREFIX "CIgniteConnHealthCheckAPI"

using namespace std;

namespace ic_network
{

CIgniteConnHealthCheckAPI::CIgniteConnHealthCheckAPI() 
{

}

CIgniteConnHealthCheckAPI::~CIgniteConnHealthCheckAPI() 
{

}

void CIgniteConnHealthCheckAPI::CheckConnectionHealthStatus(
    CIgniteHTTPConnector::CIgniteConnHealthCheckResponse &rResp, 
    const std::string& rstrUrl)
{
    CHttpRequest hReqst;
    CHttpResponse hResp;
    hReqst.SetUrl(rstrUrl);
    rResp.m_eHttpSessionErrCode = hReqst.ExecuteGET(hResp);
    rResp.m_lHttpCode = hResp.GetHttpCode();
    HCPLOG_D << "checkConnectionHealthStatus err " << 
             rResp.m_eHttpSessionErrCode << " HttpCode " << rResp.m_lHttpCode;
}

} //namespace
