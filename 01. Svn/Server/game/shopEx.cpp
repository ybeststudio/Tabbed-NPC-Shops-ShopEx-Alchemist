// bool CShopEx::AddGuest(LPCHARACTER ch,DWORD owner_vid, bool bOtherEmpire) icinde:
// Ara:
		const TShopTableEx& shop_tab = *it;
		TPacketGCShopStartEx::TSubPacketShopTab pack_tab;
		pack_tab.coin_type = shop_tab.coinType;

// Altina ekle:
#ifdef ENABLE_SHOPEX_TAB_LEVEL
		pack_tab.level_min = shop_tab.byLevelMin;
#endif


// bool CShopEx::AddGuest(LPCHARACTER ch,DWORD owner_vid, bool bOtherEmpire) icinde:
// Bul:
			switch (shop_tab.coinType)
			{
				case SHOP_COIN_TYPE_GOLD:
					pack_tab.items[i].price = shop_tab.items[i].price;
					break;

				case SHOP_COIN_TYPE_SECONDARY_COIN:
					pack_tab.items[i].price = shop_tab.items[i].price;
					break;
			}
			memset(pack_tab.items[i].aAttr, 0, sizeof(pack_tab.items[i].aAttr));
			memset(pack_tab.items[i].alSockets, 0, sizeof(pack_tab.items[i].alSockets));

// Degistir:
#ifdef ENABLE_RENEWAL_SHOPEX
			pack_tab.items[i].price_type = tabItems[i].price_type;
			pack_tab.items[i].price_vnum = tabItems[i].price_vnum;
#ifdef ENABLE_SHOPEX_EXTRA_PRICE
			thecore_memcpy(pack_tab.items[i].extra_price_vnum, tabItems[i].extra_price_vnum, sizeof(pack_tab.items[i].extra_price_vnum));
			thecore_memcpy(pack_tab.items[i].extra_price_count, tabItems[i].extra_price_count, sizeof(pack_tab.items[i].extra_price_count));
#endif
			pack_tab.items[i].price = tabItems[i].price;

			thecore_memcpy(pack_tab.items[i].aAttr, tabItems[i].aAttr, sizeof(pack_tab.items[i].aAttr));
			thecore_memcpy(pack_tab.items[i].alSockets, tabItems[i].alSockets, sizeof(pack_tab.items[i].alSockets));
#else
			switch (shop_tab.coinType)
			{
				case SHOP_COIN_TYPE_GOLD:
					pack_tab.items[i].price = shop_tab.items[i].price;
					break;

				case SHOP_COIN_TYPE_SECONDARY_COIN:
					pack_tab.items[i].price = shop_tab.items[i].price;
					break;
			}
			memset(pack_tab.items[i].aAttr, 0, sizeof(pack_tab.items[i].aAttr));
			memset(pack_tab.items[i].alSockets, 0, sizeof(pack_tab.items[i].alSockets));
#endif


// int CShopEx::Buy(LPCHARACTER ch, BYTE pos) icinde:
// Ara:
	if (it == m_map_guest.end())
		return SHOP_SUBHEADER_GC_END;
	TShopTableEx& shopTab = m_vec_shopTabs[tabIdx];

// Altina ekle:
#ifdef ENABLE_SHOPEX_TAB_LEVEL
	if (shopTab.byLevelMin && ch->GetLevel() < shopTab.byLevelMin)
	{
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("Your level is too low to use this item."));
		return SHOP_SUBHEADER_GC_INVALID_POS;
	}
#endif


// int CShopEx::Buy(LPCHARACTER ch, BYTE pos) icinde:
// Bul:
	switch (shopTab.coinType)
	{
		case SHOP_COIN_TYPE_GOLD:
#ifdef ENABLE_GOLD_LIMIT
			if (ch->GetGold() < (long long)dwPrice)
#else
			if (ch->GetGold() < (int)dwPrice)
#endif
			{
#ifdef ENABLE_GOLD_LIMIT
				sys_log(1, "ShopEx::Buy : Not enough money : %s has %lld, price %lld", ch->GetName(), ch->GetGold(), dwPrice);
#else
				sys_log(1, "ShopEx::Buy : Not enough money : %s has %d, price %d", ch->GetName(), ch->GetGold(), static_cast<int>(dwPrice));
#endif
				return SHOP_SUBHEADER_GC_NOT_ENOUGH_MONEY;
			}
			break;

		case SHOP_COIN_TYPE_SECONDARY_COIN:
		{
			int count = ch->CountSpecifyTypeItem(ITEM_SECONDARY_COIN);
			if (count < static_cast<int>(dwPrice))
			{
				sys_log(1, "ShopEx::Buy : Not enough myeongdojun : %s has %d, price %d", ch->GetName(), count, static_cast<int>(dwPrice));
				return SHOP_SUBHEADER_GC_NOT_ENOUGH_COINS;
			}
		}
	break;
	}

// Degistir:
#ifdef ENABLE_RENEWAL_SHOPEX
	switch (r_item.price_type)
	{
		case SHOPEX_GOLD:
#ifdef ENABLE_GOLD_LIMIT
			if (ch->GetGold() < static_cast<long long>(dwPrice))
#else
			if (ch->GetGold() < static_cast<int>(dwPrice))
#endif
				return SHOP_SUBHEADER_GC_NOT_ENOUGH_MONEY;
			break;

		case SHOPEX_COINS:
			if (ch->GetCoins() < static_cast<long long>(dwPrice))
				return SHOP_SUBHEADER_GC_NOT_ENOUGH_COINS;
			break;

		case SHOPEX_ITEM:
			if (ch->CountSpecifyItem(r_item.price_vnum) < static_cast<int>(dwPrice))
				return SHOP_SUBHEADER_GC_NOT_ENOUGH_ITEM;
			break;

		case SHOPEX_EXP:
			if (ch->GetExp() < dwPrice)
				return SHOP_SUBHEADER_GC_NOT_ENOUGH_EXP;
	}
#ifdef ENABLE_SHOPEX_EXTRA_PRICE
	for (int e = 0; e < SHOPEX_EXTRA_PRICE_MAX; ++e)
		if (r_item.extra_price_vnum[e] && ch->CountSpecifyItem(r_item.extra_price_vnum[e]) < static_cast<int>(r_item.extra_price_count[e]))
			return SHOP_SUBHEADER_GC_NOT_ENOUGH_ITEM;
#endif
#else
	switch (shopTab.coinType)
	{
		case SHOP_COIN_TYPE_GOLD:
#ifdef ENABLE_GOLD_LIMIT
			if (ch->GetGold() < (long long)dwPrice)
#else
			if (ch->GetGold() < (int)dwPrice)
#endif
			{
#ifdef ENABLE_GOLD_LIMIT
				sys_log(1, "ShopEx::Buy : Not enough money : %s has %lld, price %lld", ch->GetName(), ch->GetGold(), dwPrice);
#else
				sys_log(1, "ShopEx::Buy : Not enough money : %s has %d, price %d", ch->GetName(), ch->GetGold(), static_cast<int>(dwPrice));
#endif
				return SHOP_SUBHEADER_GC_NOT_ENOUGH_MONEY;
			}
			break;

		case SHOP_COIN_TYPE_SECONDARY_COIN:
		{
			int count = ch->CountSpecifyTypeItem(ITEM_SECONDARY_COIN);
			if (count < static_cast<int>(dwPrice))
			{
				sys_log(1, "ShopEx::Buy : Not enough myeongdojun : %s has %d, price %d", ch->GetName(), count, static_cast<int>(dwPrice));
				return SHOP_SUBHEADER_GC_NOT_ENOUGH_COINS;
			}
		}
	break;
	}
#endif


// int CShopEx::Buy(LPCHARACTER ch, BYTE pos) icinde:
// Bul:
	switch (shopTab.coinType)
	{
		case SHOP_COIN_TYPE_GOLD:
			ch->PointChange(POINT_GOLD, -dwPrice, false);
			break;

		case SHOP_COIN_TYPE_SECONDARY_COIN:
			ch->RemoveSpecifyTypeItem(ITEM_SECONDARY_COIN, dwPrice);
			break;
	}

// Degistir:
#ifdef ENABLE_RENEWAL_SHOPEX
	switch (r_item.price_type)
	{
		case SHOPEX_GOLD:
			ch->PointChange(POINT_GOLD, -dwPrice, false);
			break;

		case SHOPEX_COINS:
			ch->PointChange(POINT_COINS, -dwPrice, false);
			break;

		case SHOPEX_ITEM:
			ch->RemoveSpecifyItem(r_item.price_vnum, dwPrice);
			break;

		case SHOPEX_EXP:
			ch->PointChange(POINT_EXP, -dwPrice, false);
	}
#ifdef ENABLE_SHOPEX_EXTRA_PRICE
	for (int e = 0; e < SHOPEX_EXTRA_PRICE_MAX; ++e)
		if (r_item.extra_price_vnum[e] && r_item.extra_price_count[e])
			ch->RemoveSpecifyItem(r_item.extra_price_vnum[e], r_item.extra_price_count[e]);
#endif
	{
		item->SetAttributes(r_item.aAttr);

		for (BYTE i = 0; i < ITEM_SOCKET_MAX_NUM; i++)
			if (r_item.alSockets[i] != 0)
				item->SetSocket(i, r_item.alSockets[i]);
	}
#else
	switch (shopTab.coinType)
	{
		case SHOP_COIN_TYPE_GOLD:
			ch->PointChange(POINT_GOLD, -dwPrice, false);
			break;

		case SHOP_COIN_TYPE_SECONDARY_COIN:
			ch->RemoveSpecifyTypeItem(ITEM_SECONDARY_COIN, dwPrice);
			break;
	}
#endif

