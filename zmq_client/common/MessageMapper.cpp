#include "MessageMapper.h"
#include "ForEachUtil.h"
#include "zmq_client/ProduceResultStatus.h"

using namespace ZMQ_IMPL;
using namespace ZMQ_API;

Message MessageMapper::map(MQMessage message)
{
	Message msg;

	msg.setTopic(message.getTopic());
	msg.setBody(message.getBody().c_str(), message.getBody().size());
	if (!message.getTags().empty()) 
	{
		msg.setTags(message.getTags());
	}
	if (!message.getKeys().empty()) 
	{
		msg.setKeys(message.getKeys());
	}
	int delayLevel = message.getDelayTimeLevel();
	if (delayLevel > 0) 
	{
		msg.setDelayTimeLevel(delayLevel);
	}

	bool isReliable = message.getReliableLevel();
	if (!isReliable) 
	{
		msg.setWaitStoreMsgOK(false);
	}

	ForEachUtil::map(msg, message.getSystemProperty(), &ForEachUtil::SystemHandler);

	ForEachUtil::map(msg , message.getUserProperty(), &ForEachUtil::UserHandler);

	return msg;
}

//MQMessage MessageMapper::map(Message message)
//{
	//MQMessage msg;
// 
// 	msg.setTopic(message.getTopic());
// 	msg.setBody(message.getBody());
// 	if (null != message.getTags()) {
// 		msg.setTags(message.getTags());
// 	}
// 	if (null != message.getKeys()) {
// 		msg.setKeys(message.getKeys());
// 	}
// 
// 	msg.setReconsumeTimes(((MessageExt)message).getReconsumeTimes());
// 
// 	// maps the properties.
// 	KeyValueHandler<String, String> handler = new KeyValueHandler<String, String>() {
// 		@Override
// 			public void handle(String key, String value) {
// 				if (SystemPropertyKey.containIntraImplKey(key)) {
// 					msg.putSystemProperty(key, value);
// 				}
// 				else if (!SystemPropertyKey.containIntraMapImplKey(key)){
// 					msg.putUserProperty(key, value);
// 				}
// 				else {
// 					// nothing to do
// 					// here the intra implementation keys for map will occur.
// 				}
// 			}
// 	};
// 
// 	ForEachUtil.map(message.getProperties(), handler);

	//return msg;// TODO check whether all the fields are mapped.
//}

ProduceResult MessageMapper::map(SendResult sendResult)
{
	ProduceResult result;
	mapProduceResult(sendResult, result);
	return result;
}

void MessageMapper::mapProduceResult(SendResult& sendResult, ProduceResult& result)
{
	result.setMessageId(sendResult.getMsgId());

	switch (sendResult.getSendStatus()) 
	{
	case SEND_OK:
		result.setStatus(PRS_SEND_OK);
		break;
	case FLUSH_DISK_TIMEOUT:
		result.setStatus(PRS_FLUSH_DISK_TIMEOUT);
		break;
	case FLUSH_SLAVE_TIMEOUT:
		result.setStatus(PRS_FLUSH_SLAVE_TIMEOUT);
		break;
	case SLAVE_NOT_AVAILABLE:
		result.setStatus(PRS_SLAVE_NOT_AVAILABLE);
		break;
	default:
		break;
	}
}
