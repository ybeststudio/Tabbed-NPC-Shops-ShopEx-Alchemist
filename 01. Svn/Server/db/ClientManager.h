// Ara:
	private:
		bool InitializeTables();
		bool InitializeShopTable();

// Altina ekle:
#ifdef ENABLE_RENEWAL_SHOPEX
		bool InitializeShopEXTable();
#endif


// Ara:
		std::map<DWORD, TItemTable *> m_map_itemTableByVnum;
		int m_iShopTableSize;
		TShopTable * m_pShopTable;

// Altina ekle:
#ifdef ENABLE_RENEWAL_SHOPEX
		TShopTable* m_pShopEXTable;
		int m_iShopEXTableSize;
#endif

