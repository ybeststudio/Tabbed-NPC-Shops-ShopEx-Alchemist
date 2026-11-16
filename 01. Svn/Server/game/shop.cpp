// bool CShop::AddGuest(LPCHARACTER ch, DWORD owner_vid, bool bOtherEmpire) icinde:
// Ara:
		pack2.items[i].vnum = item.vnum;
		pack2.items[i].price = item.price;
		pack2.items[i].count = item.count;

// Altina ekle:
#ifdef ENABLE_RENEWAL_SHOPEX
		pack2.items[i].price_type = SHOPEX_GOLD;
#endif

