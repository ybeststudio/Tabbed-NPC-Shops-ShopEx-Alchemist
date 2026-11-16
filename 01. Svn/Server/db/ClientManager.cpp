// CClientManager::CClientManager() : icinde:
// Ara:
	m_bChinaEventServer(false),
	m_iShopTableSize(0),
	m_pShopTable(NULL),

// Altina ekle:
#ifdef ENABLE_RENEWAL_SHOPEX
	m_pShopEXTable(NULL),
	m_iShopEXTableSize(0),
#endif


// void CClientManager::QUERY_BOOT(CPeer* peer, TPacketGDBoot * p) icinde:
// Ara:
		sizeof(WORD) + sizeof(WORD) + sizeof(TMobTable) * m_vec_mobTable.size() +
		sizeof(WORD) + sizeof(WORD) + sizeof(TItemTable) * m_vec_itemTable.size() +
		sizeof(WORD) + sizeof(WORD) + sizeof(TShopTable) * m_iShopTableSize +

// Altina ekle:
#ifdef ENABLE_RENEWAL_SHOPEX
		sizeof(WORD) + sizeof(WORD) + sizeof(TShopTable) * m_iShopEXTableSize +
#endif


// void CClientManager::QUERY_BOOT(CPeer* peer, TPacketGDBoot * p) icinde:
// Ara:
	peer->EncodeWORD(sizeof(TShopTable));
	peer->EncodeWORD(m_iShopTableSize);
	peer->Encode(m_pShopTable, sizeof(TShopTable) * m_iShopTableSize);

// Altina ekle:
#ifdef ENABLE_RENEWAL_SHOPEX
	peer->EncodeWORD(sizeof(TShopTable));
	peer->EncodeWORD(m_iShopEXTableSize);
	peer->Encode(m_pShopEXTable, sizeof(TShopTable) * m_iShopEXTableSize);
#endif


// void CClientManager::QUERY_RELOAD_PROTO() icinde:
// Ara:
				sizeof(WORD) + sizeof(TShopTable) * m_iShopTableSize +

// Altina ekle:
#ifdef ENABLE_RENEWAL_SHOPEX
				sizeof(WORD) + sizeof(TShopTable) * m_iShopEXTableSize +
#endif


// void CClientManager::QUERY_RELOAD_PROTO() icinde:
// Ara:
		tmp->EncodeWORD(m_iShopTableSize);
		tmp->Encode(m_pShopTable, sizeof(TShopTable) * m_iShopTableSize);

// Altina ekle:
#ifdef ENABLE_RENEWAL_SHOPEX
		tmp->EncodeWORD(m_iShopEXTableSize);
		tmp->Encode(m_pShopEXTable, sizeof(TShopTable) * m_iShopEXTableSize);
#endif

