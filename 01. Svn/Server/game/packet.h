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


// Ara:
	BYTE display_pos;
	int32_t alSockets[ITEM_SOCKET_MAX_NUM];
	TPlayerItemAttribute aAttr[ITEM_ATTRIBUTE_MAX_NUM];

// Altina ekle:
#ifdef ENABLE_RENEWAL_SHOPEX
	BYTE price_type;
	DWORD price_vnum;
#ifdef ENABLE_SHOPEX_EXTRA_PRICE
	DWORD extra_price_vnum[SHOPEX_EXTRA_PRICE_MAX];
	DWORD extra_price_count[SHOPEX_EXTRA_PRICE_MAX];
#endif

	packet_shop_item() : price_type(SHOPEX_GOLD), price_vnum(0)
	{
		memset(&alSockets, 0, sizeof(alSockets));
		memset(&aAttr, 0, sizeof(aAttr));
#ifdef ENABLE_SHOPEX_EXTRA_PRICE
		memset(&extra_price_vnum, 0, sizeof(extra_price_vnum));
		memset(&extra_price_count, 0, sizeof(extra_price_count));
#endif
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

