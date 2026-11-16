// Ara:
		BYTE GetTabCount() { return m_bTabCount; }
		void SetTabCoinType(BYTE tabIdx, BYTE coinType);
		BYTE GetTabCoinType(BYTE tabIdx);

// Altina ekle:
#ifdef ENABLE_SHOPEX_TAB_LEVEL
		void SetTabLevelMin(BYTE tabIdx, BYTE level)	{ if (tabIdx < SHOP_TAB_COUNT_MAX) m_aShoptabs[tabIdx].levelMin = level; }
		BYTE GetTabLevelMin(BYTE tabIdx)				{ return tabIdx < m_bTabCount ? m_aShoptabs[tabIdx].levelMin : 0; }
#endif


// Ara:
			ShopTab()
			{
				coinType = SHOP_COIN_TYPE_GOLD;

// Altina ekle:
#ifdef ENABLE_SHOPEX_TAB_LEVEL
				levelMin = 0;
#endif


// Ara:
			}
			BYTE coinType;

// Altina ekle:
#ifdef ENABLE_SHOPEX_TAB_LEVEL
			BYTE levelMin;
#endif

