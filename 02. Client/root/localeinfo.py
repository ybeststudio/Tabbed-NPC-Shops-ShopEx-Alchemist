# Ara:
	'NOT_ENOUGH_COINS': 					SHOP_NOT_ENOUGH_COINS,
}

# Altina ekle:
if app.ENABLE_RENEWAL_SHOPEX:
	SHOP_ERROR_DICT["NOT_ENOUGH_EXP"] =		SHOP_NOT_ENOUGH_EXP
	SHOP_ERROR_DICT["NOT_ENOUGH_ITEM"] =	SHOP_NOT_ENOUGH_ITEM
	SHOP_ERROR_DICT["ALREADY_HAVE_ONE_ITEM"] =	SHOP_ALREADY_HAVE_ONE_ITEM


# Ara:
def NumberToDecimalString(n):
	return str('.'.join([ i-3<0 and str(n)[:i] or str(n)[i-3:i] for i in range(len(str(n))%3, len(str(n))+1, 3) if i ]))

# Altina ekle:
if app.ENABLE_RENEWAL_SHOPEX:
	def NumberToShopEXP(n):
		return '0 {:s}'.format(MONETARY_UNIT_EXP) if (n <= 0) else '{:s} {:s}'.format('.'.join([(i - 3) < 0 and str(n)[:i] or str(n)[i - 3: i] for i in range(len(str(n)) % 3, len(str(n)) + 1, 3) if i]), MONETARY_UNIT_EXP)

