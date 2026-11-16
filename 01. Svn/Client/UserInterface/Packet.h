// Bul:
	SHOP_TAB_COUNT_MAX = 3,

// Degistir:
#ifdef ENABLE_RENEWAL_SHOPEX
	SHOP_TAB_COUNT_MAX = 7,
#else
	SHOP_TAB_COUNT_MAX = 3,
#endif


// Ara:
	BYTE display_pos;

// Altina ekle:
#ifdef ENABLE_RENEWAL_SHOPEX
	long alSockets[ITEM_SOCKET_SLOT_MAX_NUM];
	TPlayerItemAttribute aAttr[ITEM_ATTRIBUTE_SLOT_MAX_NUM];

	BYTE price_type;
	DWORD price_vnum;

	SShopItemTable() : price_type(SHOPEX_GOLD), price_vnum(0)
	{
		memset(&alSockets, 0, sizeof(alSockets));
		memset(&aAttr, 0, sizeof(aAttr));
	}
#endif


// Ara:
	{
		char name[SHOP_TAB_NAME_MAX];
		BYTE coin_type;

// Altina ekle:
#ifdef ENABLE_SHOPEX_TAB_LEVEL
		BYTE level_min;
#endif


// Ara:
	SHOP_SUBHEADER_GC_SOLD_OUT,
	SHOP_SUBHEADER_GC_START_EX,
	SHOP_SUBHEADER_GC_NOT_ENOUGH_COINS,

// Altina ekle:
#ifdef ENABLE_RENEWAL_SHOPEX
	SHOP_SUBHEADER_GC_NOT_ENOUGH_ITEM,
	SHOP_SUBHEADER_GC_NOT_ENOUGH_EXP,
	SHOP_SUBHEADER_GC_YOU_ALREADY_HAVE_ONE,
#endif

