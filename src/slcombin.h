/* This file was automatically created by ./mktables */
#define SL_COMBINING_MAX_CHAR 0x1D200ul

#define SL_COMBINING_ALOOKUP(y,x) \
{ \
   const unsigned char *_t; \
   (y) = (((unsigned)(x) < SL_COMBINING_MAX_CHAR) \
	  && (NULL != (_t = _pSLwc_Combining_Table[(unsigned)(x)>>9])) \
	  && (_t[(unsigned)((x)>>3)&0x3F] & (1 << ((x)&7)))); \
}
extern const unsigned char *_pSLwc_Combining_Table[233];

#ifdef DEFINE_PSLWC_COMBINING_TABLE
static const unsigned char Table_01[64] =
{
  /*0x00-0x07*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*0x08-0x0F*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*0x10-0x17*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*0x18-0x1F*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*0x20-0x27*/ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  /*0x28-0x2F*/ 0xFF, 0xFF, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00,
  /*0x30-0x37*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*0x38-0x3F*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static const unsigned char Table_02[64] =
{
  /*0x00-0x07*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*0x08-0x0F*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*0x10-0x17*/ 0x78, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*0x18-0x1F*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*0x20-0x27*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*0x28-0x2F*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*0x30-0x37*/ 0x00, 0x00, 0xFE, 0xFF, 0xFB, 0xFF, 0xFF, 0xBB,
  /*0x38-0x3F*/ 0x16, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static const unsigned char Table_03[64] =
{
  /*0x00-0x07*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*0x08-0x0F*/ 0x00, 0xF8, 0x3F, 0x00, 0x00, 0x00, 0x01, 0x00,
  /*0x10-0x17*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*0x18-0x1F*/ 0x00, 0x00, 0xC0, 0xDF, 0x9F, 0x3D, 0x00, 0x00,
  /*0x20-0x27*/ 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0xFF, 0xFF,
  /*0x28-0x2F*/ 0xFF, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*0x30-0x37*/ 0x00, 0x00, 0x00, 0x00, 0xC0, 0xFF, 0x01, 0x00,
  /*0x38-0x3F*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static const unsigned char Table_04[64] =
{
  /*0x00-0x07*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*0x08-0x0F*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*0x10-0x17*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*0x18-0x1F*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*0x20-0x27*/ 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xD0,
  /*0x28-0x2F*/ 0xFF, 0x3F, 0x1E, 0x00, 0x0C, 0x00, 0x00, 0x00,
  /*0x30-0x37*/ 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xD0,
  /*0x38-0x3F*/ 0x9F, 0x39, 0x80, 0x00, 0x0C, 0x00, 0x00, 0x00
};

static const unsigned char Table_05[64] =
{
  /*0x00-0x07*/ 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xD0,
  /*0x08-0x0F*/ 0x87, 0x39, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00,
  /*0x10-0x17*/ 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xD0,
  /*0x18-0x1F*/ 0xBF, 0x3B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*0x20-0x27*/ 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xD0,
  /*0x28-0x2F*/ 0x8F, 0x39, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*0x30-0x37*/ 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0,
  /*0x38-0x3F*/ 0xC7, 0x3D, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00
};

static const unsigned char Table_06[64] =
{
  /*0x00-0x07*/ 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0,
  /*0x08-0x0F*/ 0xDF, 0x3D, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*0x10-0x17*/ 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0,
  /*0x18-0x1F*/ 0xDF, 0x3D, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*0x20-0x27*/ 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0,
  /*0x28-0x2F*/ 0xCF, 0x3D, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*0x30-0x37*/ 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*0x38-0x3F*/ 0x00, 0x84, 0x5F, 0xFF, 0x00, 0x00, 0x0C, 0x00
};

static const unsigned char Table_07[64] =
{
  /*0x00-0x07*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF2, 0x07,
  /*0x08-0x0F*/ 0x80, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*0x10-0x17*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF2, 0x1B,
  /*0x18-0x1F*/ 0x00, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*0x20-0x27*/ 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0xA0, 0xC2,
  /*0x28-0x2F*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xFF,
  /*0x30-0x37*/ 0xDF, 0x00, 0xFF, 0xFE, 0xFF, 0xFF, 0xFF, 0x1F,
  /*0x38-0x3F*/ 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static const unsigned char Table_08[64] =
{
  /*0x00-0x07*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0xC7, 0x03,
  /*0x08-0x0F*/ 0x00, 0x00, 0xC0, 0x03, 0x00, 0x00, 0x00, 0x00,
  /*0x10-0x17*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*0x18-0x1F*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*0x20-0x27*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*0x28-0x2F*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*0x30-0x37*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*0x38-0x3F*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static const unsigned char Table_09[64] =
{
  /*0x00-0x07*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*0x08-0x0F*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*0x10-0x17*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*0x18-0x1F*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*0x20-0x27*/ 0x00, 0x00, 0x1C, 0x00, 0x00, 0x00, 0x1C, 0x00,
  /*0x28-0x2F*/ 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00, 0x0C, 0x00,
  /*0x30-0x37*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0xFF,
  /*0x38-0x3F*/ 0xFF, 0xFF, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00
};

static const unsigned char Table_10[64] =
{
  /*0x00-0x07*/ 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*0x08-0x0F*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*0x10-0x17*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00,
  /*0x18-0x1F*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*0x20-0x27*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*0x28-0x2F*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*0x30-0x37*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*0x38-0x3F*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static const unsigned char Table_11[64] =
{
  /*0x00-0x07*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*0x08-0x0F*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*0x10-0x17*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*0x18-0x1F*/ 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x07, 0x00, 0x00,
  /*0x20-0x27*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*0x28-0x2F*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*0x30-0x37*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*0x38-0x3F*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static const unsigned char Table_12[64] =
{
  /*0x00-0x07*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x00, 0x00,
  /*0x08-0x0F*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*0x10-0x17*/ 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00,
  /*0x18-0x1F*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*0x20-0x27*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*0x28-0x2F*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*0x30-0x37*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*0x38-0x3F*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static const unsigned char Table_13[64] =
{
  /*0x00-0x07*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*0x08-0x0F*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*0x10-0x17*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*0x18-0x1F*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*0x20-0x27*/ 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00,
  /*0x28-0x2F*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*0x30-0x37*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*0x38-0x3F*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static const unsigned char Table_14[64] =
{
  /*0x00-0x07*/ 0xFF, 0xFF, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00,
  /*0x08-0x0F*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*0x10-0x17*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*0x18-0x1F*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*0x20-0x27*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*0x28-0x2F*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*0x30-0x37*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*0x38-0x3F*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static const unsigned char Table_15[64] =
{
  /*0x00-0x07*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*0x08-0x0F*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*0x10-0x17*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*0x18-0x1F*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*0x20-0x27*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  /*0x28-0x2F*/ 0x00, 0x00, 0x00, 0x00, 0xE0, 0xE3, 0x07, 0xF8,
  /*0x30-0x37*/ 0xE7, 0x0F, 0x00, 0x00, 0x00, 0x3C, 0x00, 0x00,
  /*0x38-0x3F*/ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const unsigned char *_pSLwc_Combining_Table[233] =
{
      NULL,  Table_01,  Table_02,  Table_03,  Table_04,  Table_05,
  Table_06,  Table_07,  Table_08,      NULL,      NULL,  Table_09,
  Table_10,      NULL,      NULL,      NULL,  Table_11,      NULL,
      NULL,      NULL,      NULL,      NULL,      NULL,      NULL,
  Table_12,      NULL,      NULL,      NULL,      NULL,      NULL,
      NULL,      NULL,      NULL,      NULL,      NULL,      NULL,
      NULL,      NULL,      NULL,      NULL,      NULL,      NULL,
      NULL,      NULL,      NULL,      NULL,      NULL,      NULL,
      NULL,      NULL,      NULL,      NULL,      NULL,      NULL,
      NULL,      NULL,      NULL,      NULL,      NULL,      NULL,
      NULL,      NULL,      NULL,      NULL,      NULL,      NULL,
      NULL,      NULL,      NULL,      NULL,      NULL,      NULL,
      NULL,      NULL,      NULL,      NULL,      NULL,      NULL,
      NULL,      NULL,      NULL,      NULL,      NULL,      NULL,
      NULL,      NULL,      NULL,      NULL,      NULL,      NULL,
      NULL,      NULL,      NULL,      NULL,      NULL,      NULL,
      NULL,      NULL,      NULL,      NULL,      NULL,      NULL,
      NULL,      NULL,      NULL,      NULL,      NULL,      NULL,
      NULL,      NULL,      NULL,      NULL,      NULL,      NULL,
      NULL,      NULL,      NULL,      NULL,      NULL,      NULL,
      NULL,      NULL,      NULL,      NULL,      NULL,  Table_13,
      NULL,  Table_14,      NULL,      NULL,      NULL,      NULL,
      NULL,      NULL,      NULL,      NULL,      NULL,      NULL,
      NULL,      NULL,      NULL,      NULL,      NULL,      NULL,
      NULL,      NULL,      NULL,      NULL,      NULL,      NULL,
      NULL,      NULL,      NULL,      NULL,      NULL,      NULL,
      NULL,      NULL,      NULL,      NULL,      NULL,      NULL,
      NULL,      NULL,      NULL,      NULL,      NULL,      NULL,
      NULL,      NULL,      NULL,      NULL,      NULL,      NULL,
      NULL,      NULL,      NULL,      NULL,      NULL,      NULL,
      NULL,      NULL,      NULL,      NULL,      NULL,      NULL,
      NULL,      NULL,      NULL,      NULL,      NULL,      NULL,
      NULL,      NULL,      NULL,      NULL,      NULL,      NULL,
      NULL,      NULL,      NULL,      NULL,      NULL,      NULL,
      NULL,      NULL,      NULL,      NULL,      NULL,      NULL,
      NULL,      NULL,      NULL,      NULL,      NULL,      NULL,
      NULL,      NULL,      NULL,      NULL,      NULL,      NULL,
      NULL,      NULL,      NULL,      NULL,      NULL,      NULL,
      NULL,      NULL,      NULL,      NULL,  Table_15
};
#endif /* DEFINE_PSLWC_COMBINING_TABLE */
