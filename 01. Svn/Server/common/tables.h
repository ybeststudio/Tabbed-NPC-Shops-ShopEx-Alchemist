// Ara:
	BYTE bSkillAttrType;
	DWORD dwTargetRange;
} TSkillTable;

// Altina ekle:
#ifdef ENABLE_RENEWAL_SHOPEX
#if defined(ENABLE_SHOPEX_EXTRA_PRICE_5)
#define SHOPEX_EXTRA_PRICE_MAX 5
#elif defined(ENABLE_SHOPEX_EXTRA_PRICE_3)
#define SHOPEX_EXTRA_PRICE_MAX 3
#else
#define SHOPEX_EXTRA_PRICE_MAX 2
#endif

enum STableExTypes
{
	SHOPEX_GOLD = 1,
	SHOPEX_COINS,
	SHOPEX_ITEM,
	SHOPEX_EXP,
	SHOPEX_MAX,
};
#endif


// Ara:
	BYTE display_pos; // PC, shop_table_ex.txt

// Altina ekle:
#ifdef ENABLE_RENEWAL_SHOPEX
	int32_t alSockets[ITEM_SOCKET_MAX_NUM];
	TPlayerItemAttribute aAttr[ITEM_ATTRIBUTE_MAX_NUM];

	BYTE price_type;
	DWORD price_vnum;
#ifdef ENABLE_SHOPEX_EXTRA_PRICE
	DWORD extra_price_vnum[SHOPEX_EXTRA_PRICE_MAX];
	DWORD extra_price_count[SHOPEX_EXTRA_PRICE_MAX];
#endif

	SShopItemTable() : price_type(SHOPEX_GOLD), price_vnum(0)
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
	DWORD dwVnum;
	DWORD dwNPCVnum;

// Altina ekle:
#ifdef ENABLE_SHOPEX_TAB_LEVEL
	BYTE byLevelMin;
#endif


// Ara:
	TShopItemTable items[SHOP_HOST_ITEM_MAX_NUM];

// Altina ekle:
#ifdef ENABLE_RENEWAL_SHOPEX
	char szShopName[SHOP_TAB_NAME_MAX + 1];
#endif

