/*      This definition allows for colour icon on the desktop
	when mounting a netatalk volume. What Apple 
	Computer Inc. did to achieve colour Volume Icons
	is to place a hidden file in the root of the Volume.
	Within this file are our Icon resources. We have
	icl4, icl8, ICN#, ICS#, ics4, ics8. The resource ID's
	are -16455 for all resources.

	Unforunately Apple made our life a lot harder in that
	the file is called Icon^M. Yes it has an unprintable
	character. We'll try and get around that by specifing
	Icon\015 for the filename. i.mcwilliam@uws.edu.au */


static u_int8_t	Colour_Volume_icon[] = {
	0x00,0x05,0x16,0x07,0x00,0x01,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x05,0x00,0x00,0x00,0x02,0x00,0x00,
	0x02,0x4d,0x00,0x00,0x0a,0x6e,0x00,0x00,
	0x00,0x03,0x00,0x00,0x00,0x56,0x00,0x00,
	0x00,0x05,0x00,0x00,0x00,0x04,0x00,0x00,
	0x01,0x55,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x07,0x00,0x00,0x02,0x1d,0x00,0x00,
	0x00,0x10,0x00,0x00,0x00,0x09,0x00,0x00,
	0x02,0x2d,0x00,0x00,0x00,0x20,0x49,0x63,
	0x6f,0x6e,0x0d,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x39,0xef,0x25,
	0x5f,0x39,0xef,0x2c,0x23,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x01,0x69,0x63,0x6f,
	0x6e,0x4d,0x41,0x43,0x53,0x40,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
	0x00,0x00,0x00,0x09,0xd8,0x00,0x00,0x08,
	0xd8,0x00,0x00,0x00,0x96,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xe3,
	0x00,0x00,0x00,0xaa,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x33,
	0x00,0x00,0x00,0xa3,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x0e,0x33,
	0x3e,0xaa,0xbc,0xb3,0xc0,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x0a,0x33,
	0xa3,0x33,0x3a,0x33,0xb0,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xba,
	0xb0,0x33,0xcb,0x33,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xb3,
	0xcc,0x33,0x0c,0x3b,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x0e,0xa3,
	0xde,0xeb,0xdc,0x3c,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x0c,0xa3,
	0xbe,0x3b,0xeb,0x3b,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0xaf,0xa0,0x00,0xe3,
	0x33,0x33,0x33,0x3b,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x0e,0xab,0xfa,0x00,0xce,
	0x33,0xa3,0x33,0xe0,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x0f,0xa0,0x0e,
	0xaa,0x3a,0xaa,0xb0,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x0a,0xaa,0x00,0xfa,0xca,
	0x33,0xa3,0xaa,0xab,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x03,0xaa,0x00,0xef,0xa3,
	0x33,0x33,0x3a,0xaa,0xbb,0xcb,0x00,0x00,
	0x00,0x00,0x00,0x0a,0x3a,0x00,0x0e,0xff,
	0x33,0x33,0x3a,0xa3,0x3f,0xa3,0xb0,0x00,
	0x00,0x00,0x00,0x00,0x0a,0xa0,0x0e,0xfa,
	0x3f,0xff,0xaf,0xaf,0xfa,0xab,0x3b,0x00,
	0x00,0x00,0x00,0x00,0xea,0xae,0xff,0xaa,
	0xaf,0xaf,0xba,0xe3,0x33,0xe3,0xb3,0x00,
	0x00,0x00,0x00,0x0e,0xaf,0xef,0xaa,0xbf,
	0xf3,0x3a,0x3a,0x0e,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x0d,0x0a,0x3a,0x0b,0xff,
	0xaa,0xa3,0x3a,0xe0,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x0a,0xae,0xff,
	0x33,0xa3,0x3a,0xa0,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x03,0xab,0xaa,
	0x33,0x33,0xae,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x0a,0xfa,
	0x3a,0x3a,0xe0,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0xaf,0xea,
	0xaa,0xaa,0xbd,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x0a,0xfd,0xeb,
	0xaa,0xa3,0x33,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x0e,0xea,
	0x3b,0xbb,0xb0,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,
	0xcc,0xe3,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,
	0xcc,0xe3,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x3f,0x30,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,
	0xcd,0xd3,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x30,0x30,0x33,0x33,0x33,0x33,0x3c,
	0xce,0xdd,0x33,0x33,0x33,0x33,0x33,0x03,
	0x03,0xc0,0xc0,0xcc,0xcc,0xcc,0xcc,0xcc,
	0xe0,0xed,0xdd,0xdd,0xdd,0xdd,0xdd,0x0d,
	0x0d,0xe0,0xe0,0xee,0xee,0xee,0xee,0xee,
	0x00,0x0e,0xee,0xee,0xee,0xee,0xee,0x0f,
	0x0f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0xfb,0x40,0x00,0x00,0x00,0x00,0x00,
	0x00,0xdc,0xdc,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x40,0x6b,0x00,0x00,0x00,0x00,0x00,
	0x00,0xdc,0x40,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xfb,0x6b,0xd9,0xda,0x88,0xdc,0x89,0x63,
	0x32,0x39,0xda,0x32,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xdc,0xdb,0xd9,0xdc,0x6b,0xd9,0x47,0xdb,
	0xdc,0xda,0xd9,0x39,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x5d,0x8f,0x5d,0x24,0x40,0xd9,0x32,
	0x64,0xda,0xda,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x5d,0xdb,0xf8,0x2b,0x40,0x40,0x00,
	0xf8,0xdb,0x5d,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xfb,0xdc,0x40,0xfa,0xfb,0x88,0x64,0x81,
	0xf8,0x6b,0x32,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xf8,0xdc,0xd9,0x63,0x88,0xda,0x64,0xac,
	0x5d,0x47,0x5d,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0xfd,0xff,0xfd,0x00,0x00,
	0x00,0x88,0xdb,0xda,0x6b,0x6b,0xdb,0x40,
	0xd9,0x6b,0x5d,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0xfb,0xfd,0x82,0xff,0xfd,0x00,
	0x00,0xf8,0x88,0xdb,0x6b,0x8f,0x6b,0x6b,
	0xdb,0x88,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xfd,
	0x00,0x00,0x88,0xde,0x8f,0xdb,0xdc,0x8f,
	0xde,0x64,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x8f,0x8f,0x8f,0x00,0x00,0xff,
	0xfd,0xf7,0xdc,0xda,0x6b,0xdc,0xdb,0xdc,
	0x8f,0xdd,0x5d,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0xd8,0x8f,0x8f,0x00,0x00,0xfb,
	0xff,0xfd,0x6b,0x47,0x47,0x47,0x47,0xda,
	0x8f,0xdd,0x8f,0x64,0x39,0x32,0x5d,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x8f,0xd8,0x8f,0x00,0x00,0x00,
	0xfb,0xfe,0xfe,0xd9,0xda,0x6b,0xd9,0xda,
	0xdc,0x8e,0xdb,0xd9,0xfe,0xdc,0x6b,0x64,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x8f,0x8f,0x00,0x00,
	0xfb,0xfe,0xfd,0xdb,0xfe,0xfe,0xff,0xfd,
	0xfe,0xfd,0xfe,0xfe,0xfd,0xfd,0x64,0x6b,
	0x82,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0xfb,0xfd,0xfd,0xfd,0xff,
	0xfe,0xfd,0xfd,0xfd,0xfe,0xfd,0xff,0x82,
	0xfd,0xfb,0x47,0x47,0x47,0xfb,0xda,0x39,
	0x00,0xd8,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0xfb,0xfd,0xff,0xfb,0xff,0xfd,
	0xfd,0x5d,0xfe,0xff,0xd8,0xdb,0xdc,0xda,
	0xdd,0xfb,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x57,0xfd,0x00,0xd8,0x8f,0x00,
	0x5e,0xfe,0xfe,0xdc,0x8f,0x8f,0x6b,0xdb,
	0xdc,0xfb,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x8f,0x8f,
	0x87,0xfe,0xff,0xdb,0x6b,0x8f,0xda,0xdb,
	0x8e,0xdc,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0xd8,0x8f,
	0x64,0xfd,0xdd,0xda,0x6b,0xdb,0x6d,0xdd,
	0xfb,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xfd,0xff,0xdc,0xdb,0xdc,0xdb,0xdc,0x88,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xfd,
	0xff,0xfb,0xdc,0x8f,0xdc,0x8f,0xdd,0x64,
	0x5c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0xfd,0xff,
	0xfa,0xfb,0x82,0xdd,0xdd,0xdc,0x6b,0x6b,
	0xd9,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xfb,0xfb,0xdc,0xda,0x64,0x64,0x39,0x39,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0xd9,0xf8,0xf8,0xfc,0xd9,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0xd9,0xf8,0xf8,0xfc,0xd9,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0xd9,0xff,0xd9,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0xd9,0xf8,0xfa,0xfa,0xd9,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0xd9,0x00,0xd9,
	0x00,0xd9,0xd9,0xd9,0xd9,0xd9,0xd9,0xd9,
	0xd9,0xd9,0xf8,0xf8,0xfb,0xfa,0xfa,0xd9,
	0xd9,0xd9,0xd9,0xd9,0xd9,0xd9,0xd9,0xd9,
	0xd9,0x00,0xd9,0x00,0xd0,0xf8,0x00,0xf8,
	0x00,0xf8,0xf8,0xf8,0xf8,0xf8,0xf8,0xf8,
	0xf8,0xf8,0xf8,0xfb,0x00,0xfb,0xfa,0xfa,
	0xfa,0xfa,0xfa,0xfa,0xfa,0xfa,0xfa,0xfa,
	0xfa,0x00,0xfa,0x00,0xfa,0xfb,0x00,0xfb,
	0x00,0xfb,0xfb,0xfb,0xfb,0xfb,0xfb,0xfb,
	0xfb,0xfb,0xfb,0x00,0x00,0x00,0xfb,0xfb,
	0xfb,0xfb,0xfb,0xfb,0xfb,0xfb,0xfb,0xfb,
	0xfb,0x00,0xff,0x00,0xff,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
	0x00,0x00,0x0c,0x0c,0x00,0x00,0x0c,0x0c,
	0x00,0x00,0x1f,0xe4,0x00,0x00,0x1f,0xfc,
	0x00,0x00,0x0e,0xdc,0x00,0x00,0x0c,0xcc,
	0x00,0x00,0x1f,0xe8,0x00,0x00,0x0f,0xfc,
	0x00,0x03,0x8f,0xfc,0x00,0x07,0xc7,0xf8,
	0x00,0x00,0x67,0xf8,0x00,0x07,0x37,0xfc,
	0x00,0x07,0x3f,0xfe,0x40,0x07,0x1f,0xff,
	0xe0,0x01,0x9f,0xff,0xf0,0x03,0xff,0xff,
	0xd0,0x07,0xff,0xf8,0x00,0x02,0xdf,0xf8,
	0x00,0x00,0x7f,0xf8,0x00,0x00,0x7f,0xf0,
	0x00,0x00,0x1f,0xe0,0x00,0x00,0x3f,0xf0,
	0x00,0x00,0x7f,0xf0,0x00,0x00,0x1f,0x80,
	0x00,0x00,0x04,0xc0,0x00,0x00,0x04,0xc0,
	0x00,0x00,0x03,0x80,0x00,0x00,0x05,0xc0,
	0x00,0xaf,0xf9,0xff,0xf5,0x00,0x02,0xff,
	0xf5,0xaf,0xfc,0x7f,0xf5,0x00,0x00,0x00,
	0x00,0x00,0x0c,0x0c,0x00,0x00,0x0c,0x0c,
	0x00,0x00,0x1f,0xfe,0x00,0x00,0x1f,0xfe,
	0x00,0x00,0x0f,0xfc,0x00,0x00,0x0f,0xfc,
	0x00,0x00,0x1f,0xfc,0x00,0x00,0x1f,0xfc,
	0x00,0x03,0x8f,0xfc,0x00,0x07,0xcf,0xf8,
	0x00,0x00,0x67,0xf8,0x00,0x07,0x3f,0xfc,
	0x00,0x07,0x3f,0xff,0xc0,0x07,0x1f,0xff,
	0xe0,0x01,0x9f,0xff,0xf0,0x03,0xff,0xff,
	0xf0,0x07,0xff,0xf8,0x00,0x06,0xff,0xf8,
	0x00,0x00,0x7f,0xf8,0x00,0x00,0x7f,0xf0,
	0x00,0x00,0x1f,0xe0,0x00,0x00,0x3f,0xf0,
	0x00,0x00,0x7f,0xf0,0x00,0x00,0x1f,0xe0,
	0x00,0x00,0x07,0xc0,0x00,0x00,0x07,0xc0,
	0x00,0x00,0x03,0x80,0x00,0x00,0x07,0xc0,
	0x00,0xaf,0xff,0xff,0xf5,0xaf,0xfe,0xff,
	0xf5,0xaf,0xfc,0x7f,0xf5,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x40,0x02,0x20,0x07,
	0xe0,0x02,0xa0,0x07,0xa0,0x39,0xe0,0x3d,
	0xe0,0x37,0xfc,0x1f,0xfc,0x3f,0xe0,0x0f,
	0xe0,0x07,0xc0,0x0f,0xc0,0x02,0x80,0x03,
	0x80,0x01,0xff,0xfe,0xff,0x02,0x20,0x07,
	0xf0,0x03,0xe0,0x07,0xe0,0x3f,0xe0,0x3f,
	0xe0,0x3f,0xfc,0x1f,0xfc,0x3f,0xe0,0x0f,
	0xe0,0x07,0xc0,0x0f,0xc0,0x03,0x80,0x03,
	0x80,0xff,0xff,0xfe,0xff,0x00,0x00,0x00,
	0x80,0x00,0x00,0x00,0xe0,0x00,0xa0,0x00,
	0x00,0x00,0x00,0x0e,0x3a,0xaa,0x3b,0x00,
	0x00,0x00,0x00,0x00,0x3c,0x3c,0x30,0x00,
	0x00,0x00,0x00,0x0e,0xae,0x3c,0x30,0x00,
	0x00,0x00,0xef,0xf0,0xc3,0x33,0xe0,0x00,
	0x00,0x00,0xaa,0xff,0xca,0xaa,0xa0,0x00,
	0x00,0x00,0x33,0x0f,0xf3,0x3a,0xaf,0xab,
	0x00,0x00,0x0a,0xaf,0xff,0xff,0xff,0xa3,
	0x00,0x00,0xef,0xfa,0xff,0xaa,0xe0,0x00,
	0x00,0x00,0x00,0x3a,0xf3,0x3e,0xa0,0x00,
	0x00,0x00,0x00,0x0f,0xfa,0xae,0x00,0x00,
	0x00,0x00,0x00,0xaf,0xea,0xa3,0x00,0x00,
	0x00,0x00,0x00,0x00,0x3c,0xe0,0x00,0x00,
	0x00,0x00,0x00,0x00,0x3f,0xd0,0x00,0x00,
	0x00,0xcc,0xcc,0xcc,0xce,0xed,0xdd,0xdd,
	0xdd,0xee,0xee,0xee,0xe0,0xee,0xee,0xee,
	0xff,0x00,0x00,0x01,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0xfb,0x00,0x00,0x00,0xdc,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0xfb,0xdb,0xdc,0xdc,0xdc,0xda,
	0x39,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0xdb,0xf8,0xd9,0xf8,0xdb,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0xfb,0xdc,0xfb,0xda,0xf8,0x6b,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xfb,
	0xff,0xff,0x00,0xf8,0xdb,0xdb,0xdb,0x88,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x8f,
	0x8f,0xff,0xff,0xf7,0xde,0xdc,0xde,0xdd,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xd8,
	0xd8,0x00,0xff,0xfe,0xda,0xd9,0xdc,0xdd,
	0xfe,0xdc,0x64,0x00,0x00,0x00,0x00,0x00,
	0xfd,0xfd,0xff,0xfe,0xfe,0xff,0xfe,0xfe,
	0xfe,0xfd,0xd8,0x00,0x00,0x00,0x00,0xfb,
	0xff,0xff,0xfd,0xfe,0xff,0xdc,0xdd,0xfb,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0xd8,0x8f,0xff,0xdb,0xdb,0xfb,0xdc,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0xff,0xff,0xdc,0xdd,0x88,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0xfd,0xff,0xfb,0xdd,0xdc,0xd9,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0xd9,0xf8,0xfc,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0xd9,0xff,0xfa,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0xf8,0xf8,0xf8,
	0xf8,0xf8,0xf8,0xf8,0xfb,0xfb,0xfa,0xfa,
	0xfa,0xfa,0xfa,0xfa,0xfa,0xfb,0xfb,0xfb,
	0xfb,0xfb,0xfb,0xfb,0x00,0xfb,0xfb,0xfb,
	0xfb,0xfb,0xfb,0xff,0xff,0x00,0x00,0x01,
	0x00,0x00,0x00,0x09,0xd8,0x00,0x00,0x08,
	0xd8,0x00,0x00,0x00,0x96,0x0c,0x91,0x69,
	0xd4,0x53,0x5c,0x00,0x00,0x00,0x1c,0x00,
	0x96,0x00,0x05,0x69,0x63,0x6c,0x34,0x00,
	0x00,0x00,0x32,0x69,0x63,0x6c,0x38,0x00,
	0x00,0x00,0x3e,0x49,0x43,0x4e,0x23,0x00,
	0x00,0x00,0x4a,0x69,0x63,0x73,0x23,0x00,
	0x00,0x00,0x56,0x69,0x63,0x73,0x34,0x00,
	0x00,0x00,0x62,0x69,0x63,0x73,0x38,0x00,
	0x00,0x00,0x6e,0xbf,0xb9,0xff,0xff,0x00,
	0x00,0x00,0x00,0x0c,0x91,0x6d,0x3c,0xbf,
	0xb9,0xff,0xff,0x00,0x00,0x02,0x04,0x0c,
	0x91,0x70,0x04,0xbf,0xb9,0xff,0xff,0x00,
	0x00,0x06,0x08,0x0c,0x90,0x71,0xa8,0xbf,
	0xb9,0xff,0xff,0x00,0x00,0x07,0x0c,0x0c,
	0x91,0x6c,0x58,0xbf,0xb9,0xff,0xff,0x00,
	0x00,0x07,0x50,0x0c,0x91,0x6f,0xa0,0xbf,
	0xb9,0xff,0xff,0x00,0x00,0x07,0xd4,0x0c,
	0x91,0x6b,0x90	/*,0x00 */
					};
