# GameWindow.__PressNumKey icinde ara:
	def __PressNumKey(self,num):
		if app.IsPressed(app.DIK_LCONTROL) or app.IsPressed(app.DIK_RCONTROL):

# Altina ekle:
			if app.ENABLE_SHOPEX_EXTRA_PRICE and num in (1, 2) and self.interface:
				dlgShop = self.interface.dlgShop
				if dlgShop and dlgShop.IsShow() and dlgShop.hoverPriceItems:
					return

