#ifndef KCACHESTREAM_H
#define KCACHESTREAM_H
#include "KHttpStream.h"
#include "KHttpObject.h"
inline void set_buffer_obj(KBuffer *buffer,KHttpObject *obj)
{
	assert(obj->data->bodys==NULL);
	obj->index.content_length = buffer->getLen();
	obj->data->bodys = buffer->stealBuff();
	SET(obj->index.flags,OBJ_IS_READY);
}
class KCacheStream : public KHttpStream
{
public:
	KCacheStream(KWStream *st,bool autoDelete);
	void init(KHttpObject *obj)
	{
		this->obj = obj;
	}
	StreamState write_direct(char *buf,int len);
	StreamState write_all(const char *buf,int len);
	StreamState write_end();
private:
	KHttpObject *obj;
	KBuffer buffer;
};
#if 0
class KDiskCacheStream : public KHttpStream
{
public:
	KDiskCacheStream(KWStream *st, bool autoDelete);
	void init(KHttpObject *obj);
	StreamState write_all(const char *buf, int len);
	StreamState write_end();
private:
	KHttpObject *obj;
};
#endif
#endif
