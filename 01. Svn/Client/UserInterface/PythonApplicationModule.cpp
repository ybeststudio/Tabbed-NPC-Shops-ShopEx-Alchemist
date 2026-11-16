// void initapp() icinde:
// Ara:
	PyModule_AddIntConstant(poModule, "ENABLE_MAP_TELEPORT", 0);

// Altina ekle:
#ifdef ENABLE_RENEWAL_SHOPEX
	PyModule_AddIntConstant(poModule, "ENABLE_RENEWAL_SHOPEX", 1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_RENEWAL_SHOPEX", 0);
#endif


// void initapp() icinde:
// Ara:
	PyModule_AddIntConstant(poModule, "ENABLE_GAYA_TICKET_SYSTEM",	0);

// Altina ekle:
#ifdef ENABLE_SHOPEX_EXTRA_PRICE_5
	PyModule_AddIntConstant(poModule, "ENABLE_SHOPEX_EXTRA_PRICE_5", 1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_SHOPEX_EXTRA_PRICE_5", 0);
#endif


// void initapp() icinde:
// Ara:
	PyModule_AddIntConstant(poModule, "ENABLE_SHOPEX_EXTRA_PRICE_5", 0);

// Altina ekle:
#ifdef ENABLE_SHOPEX_EXTRA_PRICE_3
	PyModule_AddIntConstant(poModule, "ENABLE_SHOPEX_EXTRA_PRICE_3", 1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_SHOPEX_EXTRA_PRICE_3", 0);
#endif


// void initapp() icinde:
// Ara:
	PyModule_AddIntConstant(poModule, "ENABLE_SHOPEX_EXTRA_PRICE_3", 0);

// Altina ekle:
#ifdef ENABLE_SHOPEX_TAB_LEVEL
	PyModule_AddIntConstant(poModule, "ENABLE_SHOPEX_TAB_LEVEL", 1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_SHOPEX_TAB_LEVEL", 0);
#endif


// void initapp() icinde:
// Ara:
	PyModule_AddIntConstant(poModule, "ENABLE_SHOPEX_TAB_LEVEL", 0);

// Altina ekle:
#ifdef ENABLE_SHOPEX_EXTRA_PRICE
	PyModule_AddIntConstant(poModule, "ENABLE_SHOPEX_EXTRA_PRICE",	1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_SHOPEX_EXTRA_PRICE",	0);
#endif

