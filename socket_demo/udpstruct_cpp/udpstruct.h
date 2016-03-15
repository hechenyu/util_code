#ifndef	UDPSTRUCT_H
#define	UDPSTRUCT_H

struct Request {
	uint8_t v1;
	uint8_t v2;
	uint16_t v3;
};

struct Response {
	uint8_t ret;
};

#endif
