// void CInputDB::Boot(const char* data) icinde:
// Ara:
		}
		data += size * sizeof(TShopTable);
	}

// Altina ekle:
#ifdef ENABLE_RENEWAL_SHOPEX
	if (decode_2bytes(data) != sizeof(TShopTable))
	{
		sys_err("shopex table size error");
		thecore_shutdown();
		return;
	}
	data += 2;

	size = decode_2bytes(data);
	data += 2;
	sys_log(0, "BOOT: SHOPEX: %d", size);

	if (size)
	{
		if (!CShopManager::instance().InitializeShopEX((TShopTable*)data, size))
		{
			sys_err("shopex table Initialize error");
			thecore_shutdown();
			return;
		}
		data += size * sizeof(TShopTable);
	}
#endif


// void CInputDB::ReloadProto(const char * c_pData) icinde:
// Ara:
		CShopManager::instance().Initialize((TShopTable *)c_pData, wSize);
		c_pData += wSize * sizeof(TShopTable);
	}

// Altina ekle:
#ifdef ENABLE_RENEWAL_SHOPEX
	wSize = decode_2bytes(c_pData);
	c_pData += sizeof(WORD);
	sys_log(0, "RELOAD: SHOPEX: %d", wSize);

	if (wSize)
	{
		CShopManager::instance().InitializeShopEX((TShopTable *)c_pData, wSize);
		c_pData += wSize * sizeof(TShopTable);
	}
#endif

