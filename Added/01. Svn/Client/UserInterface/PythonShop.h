#pragma once

#include "StdAfx.h"
#include "Packet.h"

typedef enum
{
	SHOP_COIN_TYPE_GOLD,
	SHOP_COIN_TYPE_SECONDARY_COIN,
} EShopCoinType;

class CPythonShop : public CSingleton<CPythonShop>
{
	public:
		CPythonShop(void);
		virtual ~CPythonShop(void);

		void Clear();

		void SetItemData(DWORD dwIndex, const TShopItemData & c_rShopItemData);
		BOOL GetItemData(DWORD dwIndex, const TShopItemData ** c_ppItemData);

		void SetItemData(BYTE tabIdx, DWORD dwSlotPos, const TShopItemData & c_rShopItemData);
		BOOL GetItemData(BYTE tabIdx, DWORD dwSlotPos, const TShopItemData ** c_ppItemData);

		void SetTabCount(BYTE bTabCount) { m_bTabCount = bTabCount; }
		BYTE GetTabCount() { return m_bTabCount; }

		void SetTabCoinType(BYTE tabIdx, BYTE coinType);
		BYTE GetTabCoinType(BYTE tabIdx);
#ifdef ENABLE_SHOPEX_TAB_LEVEL
		void SetTabLevelMin(BYTE tabIdx, BYTE level)	{ if (tabIdx < SHOP_TAB_COUNT_MAX) m_aShoptabs[tabIdx].levelMin = level; }
		BYTE GetTabLevelMin(BYTE tabIdx)				{ return tabIdx < m_bTabCount ? m_aShoptabs[tabIdx].levelMin : 0; }
#endif

		void SetTabName(BYTE tabIdx, const char *name);
		const char *GetTabName(BYTE tabIdx);

		void Open(BOOL isPrivateShop, BOOL isMainPrivateShop);
		void Close();
		BOOL IsOpen();
		BOOL IsPrivateShop();
		BOOL IsMainPlayerPrivateShop();

		void ClearPrivateShopStock();
#ifdef ENABLE_GOLD_LIMIT
		void AddPrivateShopItemStock(TItemPos ItemPos, BYTE byDisplayPos, long long dwPrice);
#else
		void AddPrivateShopItemStock(TItemPos ItemPos, BYTE byDisplayPos, DWORD dwPrice);
#endif
		void DelPrivateShopItemStock(TItemPos ItemPos);
#ifdef ENABLE_GOLD_LIMIT
		long long GetPrivateShopItemPrice(TItemPos ItemPos);
#else
		int GetPrivateShopItemPrice(TItemPos ItemPos);
#endif
		void BuildPrivateShop(const char *c_szName);


	protected:
		BOOL CheckSlotIndex(DWORD dwIndex);

	protected:

		BOOL m_isShoping;
		BOOL m_isPrivateShop;
		BOOL m_isMainPlayerPrivateShop;

		struct ShopTab
		{
			ShopTab()
			{
				coinType = SHOP_COIN_TYPE_GOLD;
#ifdef ENABLE_SHOPEX_TAB_LEVEL
				levelMin = 0;
#endif
			}
			BYTE coinType;
#ifdef ENABLE_SHOPEX_TAB_LEVEL
			BYTE levelMin;
#endif
			std::string name;
#ifdef ENABLE_NPC_SHOP_TABS
			TShopItemData items[SHOP_EX_ITEM_MAX_NUM];
#else
			TShopItemData items[SHOP_HOST_ITEM_MAX_NUM];
#endif
		};
		
		BYTE m_bTabCount;
		ShopTab m_aShoptabs[SHOP_TAB_COUNT_MAX];

		typedef std::map<TItemPos, TShopItemTable> TPrivateShopItemStock;
		TPrivateShopItemStock m_PrivateShopItemStock;
};
