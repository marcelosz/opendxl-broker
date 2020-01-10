/******************************************************************************
 * Copyright (c) 2018 McAfee, LLC - All Rights Reserved.
 *****************************************************************************/

#include "message/include/DxlRequest.h"

using namespace dxl::broker::message;

/** {@inheritDoc} */
DxlRequest::DxlRequest( dxl_message_t* msg ) : DxlMessage( msg )
{      
}

/** {@inheritDoc} */
DxlRequest::DxlRequest( const DxlRequest& req ) : DxlMessage( req )
{
}

/** {@inheritDoc} */
DxlRequest& DxlRequest::operator=(const DxlRequest& other )
{    
    if( this != &other )
    {
        DxlMessage::operator=( other );
    }
    return *this;
}

/** {@inheritDoc} */
const char* DxlRequest::getReplyToTopic() const
{
    return getMessage()->dxl_message_specificData.requestData->replyToTopic;
}

/** {@inheritDoc} */
void DxlRequest::setDestinationServiceId( const char* serviceId )
{
    setDxlRequestMessageAttributes( NULL, getMessage(), service_instance_id, serviceId );

    // Mark dirty
    markDirty();
}

/** {@inheritDoc} */
const char* DxlRequest::getDestinationServiceId() const
{
    return getMessage()->dxl_message_specificData.requestData->serviceInstanceId;
}

/** {@inheritDoc} */
void DxlRequest::setMultiServiceRequest( bool isMultiServiceRequest )
{
    setDxlRequestMultiService( NULL, getMessage(), isMultiServiceRequest );

    // Mark dirty
    markDirty();
}

/** {@inheritDoc} */
bool DxlRequest::isMultiServiceRequest() const
{
    return getMessage()->dxl_message_specificData.requestData->isMultiServiceRequest;
}

/** {@inheritDoc} */
DxlRequest::~DxlRequest()
{
}
