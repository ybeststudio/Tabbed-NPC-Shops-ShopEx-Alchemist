// Ara:
		return Py_BuildException();
	return Py_BuildValue("i", CPythonShop::instance().GetTabCoinType(bTabIdx));
}

// Altina ekle:
#ifdef ENABLE_SHOPEX_TAB_LEVEL
// shop.GetTabLevelMin(tab) -> the level the tab opens from (0 = none)
PyObject *shopGetTabLevelMin(PyObject *poSelf, PyObject *poArgs)
{
	BYTE bTabIdx;
	if (!PyTuple_GetInteger(poArgs, 0, &bTabIdx))
		return Py_BuildException();
	return Py_BuildValue("i", CPythonShop::instance().GetTabLevelMin(bTabIdx));
}
#endif

#ifdef ENABLE_RENEWAL_SHOPEX
PyObject *shopGetItemPriceType(PyObject *poSelf, PyObject *poArgs)
{
	int nPos;
	if (!PyTuple_GetInteger(poArgs, 0, &nPos))
		return Py_BuildException();

	const TShopItemData* c_pItemData;
	if (CPythonShop::Instance().GetItemData(nPos, &c_pItemData))
		return Py_BuildValue("i", c_pItemData->price_type);

	return Py_BuildValue("i", 1);
}

PyObject *shopGetItemPriceVnum(PyObject *poSelf, PyObject *poArgs)
{
	int nPos;
	if (!PyTuple_GetInteger(poArgs, 0, &nPos))
		return Py_BuildException();

	const TShopItemData* c_pItemData;
	if (CPythonShop::Instance().GetItemData(nPos, &c_pItemData))
		return Py_BuildValue("i", c_pItemData->price_vnum);

	return Py_BuildValue("i", 0);
}
#endif

#ifdef ENABLE_SHOPEX_EXTRA_PRICE
// shop.GetItemExtraPrice(slot, n) -> (vnum, count), n = 0 / 1
PyObject *shopGetItemExtraPrice(PyObject *poSelf, PyObject *poArgs)
{
	int nPos, n;
	if (!PyTuple_GetInteger(poArgs, 0, &nPos) || !PyTuple_GetInteger(poArgs, 1, &n))
		return Py_BuildException();

	const TShopItemData* c_pItemData;
	if (n >= 0 && n < SHOPEX_EXTRA_PRICE_MAX && CPythonShop::Instance().GetItemData(nPos, &c_pItemData))
		return Py_BuildValue("(ii)", c_pItemData->extra_price_vnum[n], c_pItemData->extra_price_count[n]);

	return Py_BuildValue("(ii)", 0, 0);
}
#endif


// void initshop() icinde:
// Ara:
		{ "GetTabCount", shopGetTabCount, METH_VARARGS },
		{ "GetTabName", shopGetTabName, METH_VARARGS },
		{ "GetTabCoinType", shopGetTabCoinType, METH_VARARGS },

// Altina ekle:
#ifdef ENABLE_SHOPEX_TAB_LEVEL
		{ "GetTabLevelMin", shopGetTabLevelMin, METH_VARARGS },
#endif
#ifdef ENABLE_RENEWAL_SHOPEX
		{ "GetItemPriceType", shopGetItemPriceType, METH_VARARGS },
		{ "GetItemPriceVnum", shopGetItemPriceVnum, METH_VARARGS },
#ifdef ENABLE_SHOPEX_EXTRA_PRICE
		{ "GetItemExtraPrice", shopGetItemExtraPrice, METH_VARARGS },
#endif
#endif


// void initshop() icinde:
// Ara:
	PyModule_AddIntConstant(poModule, "SHOP_COIN_TYPE_GOLD", SHOP_COIN_TYPE_GOLD);
	PyModule_AddIntConstant(poModule, "SHOP_COIN_TYPE_SECONDARY_COIN", SHOP_COIN_TYPE_SECONDARY_COIN);

// Altina ekle:
#ifdef ENABLE_RENEWAL_SHOPEX
	PyModule_AddIntConstant(poModule, "SHOPEX_GOLD", SHOPEX_GOLD);
	PyModule_AddIntConstant(poModule, "SHOPEX_COINS", SHOPEX_COINS);
	PyModule_AddIntConstant(poModule, "SHOPEX_ITEM", SHOPEX_ITEM);
	PyModule_AddIntConstant(poModule, "SHOPEX_EXP", SHOPEX_EXP);
	PyModule_AddIntConstant(poModule, "SHOPEX_MAX", SHOPEX_MAX);
#endif

