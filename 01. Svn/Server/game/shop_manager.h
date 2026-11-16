// Ara:
	CShopManager();
	virtual ~CShopManager();
	bool	Initialize(TShopTable * table, int size);

// Altina ekle:
#ifdef ENABLE_RENEWAL_SHOPEX
	bool	InitializeShopEX(TShopTable* table, int size);
#endif

