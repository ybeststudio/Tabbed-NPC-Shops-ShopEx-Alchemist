# ShopDialog.LoadDialog icinde ara:
			if self.__repurchase_shop_button:
				self.__repurchase_shop_button.SetEvent(ui.__mem_func__(self.OnClickRepurchaseButton))

# Altina ekle:
		if app.ENABLE_RENEWAL_SHOPEX:
			self.smallRadioButtonGroup = ui.RadioButtonGroup.Create([[smallTab1, ui.__mem_func__(self.OnClickTabButton), None], [smallTab2, ui.__mem_func__(self.OnClickTabButton), None], [smallTab3, ui.__mem_func__(self.OnClickTabButton), None]])
			self.middleRadioButtonGroup = ui.RadioButtonGroup.Create([[middleTab1, ui.__mem_func__(self.OnClickTabButton), None], [middleTab2, ui.__mem_func__(self.OnClickTabButton), None]])
			self.reworkedRadioButtonGroup = None
		else:
			self.smallRadioButtonGroup = ui.RadioButtonGroup.Create([[smallTab1, lambda : self.OnClickTabButton(0), None], [smallTab2, lambda : self.OnClickTabButton(1), None], [smallTab3, lambda : self.OnClickTabButton(2), None]])
			self.middleRadioButtonGroup = ui.RadioButtonGroup.Create([[middleTab1, lambda : self.OnClickTabButton(0), None], [middleTab2, lambda : self.OnClickTabButton(1), None]])


# ShopDialog.__OnClickShopTab icinde ara:
		def __OnClickShopTab(self, idx):

# Altina ekle:
			if app.ENABLE_SHOPEX_TAB_LEVEL:
				levelMin = shop.GetTabLevelMin(idx)
				if levelMin and player.GetStatus(player.LEVEL) < levelMin:
					chat.AppendChat(chat.CHAT_TYPE_INFO, localeInfo.SHOP_TAB_LEVEL_REQUIRED.format(levelMin))
					self.__OnClickShopTab(self.tabIdx) if idx != self.tabIdx else None
					return


# ShopDialog icinde ara:
	def __ShowSmallTabs(self):
		self.smallRadioButtonGroup.Show()

# Altina ekle:
	if app.ENABLE_RENEWAL_SHOPEX:
		def __ShowReworkedShopTabs(self):
			if self.reworkedRadioButtonGroup:
				self.reworkedRadioButtonGroup.Show()

		def __HideReworkedShopTabs(self):
			if self.reworkedRadioButtonGroup:
				self.reworkedRadioButtonGroup.Hide()

		def __CreateReworkedShopButtons(self, groupSize):
			def __GetButtonX(buttonIndex, width):
				CENTER_X = (self.GetWidth()/2) + (2 if groupSize != 1 else 0)
				realgroupSize = groupSize-1
				return CENTER_X - (int(width/2) - (int(width/2 * realgroupSize)) + (((realgroupSize) - buttonIndex) * width))

			self.reworkedRadioButtonGroup = ui.RadioButtonGroup()
			for buttonNumb in xrange(groupSize):
				tmpRB = ui.RadioButton()
				tmpRB.SetParent(self)
				tmpRB.SetUpVisual("d:/ymir work/ui/game/pages/buttons/but_pages_norm.tga")
				tmpRB.SetOverVisual("d:/ymir work/ui/game/pages/buttons/but_pages_hover.tga")
				tmpRB.SetDownVisual("d:/ymir work/ui/game/pages/buttons/but_pages_down.tga")
				tmpRB.SetDisableVisual("d:/ymir work/ui/game/pages/buttons/but_pages_disable.tga")
				tmpRB.SetPosition(__GetButtonX(buttonNumb, tmpRB.GetWidth()), 298)
				tmpRB.Show()
				self.reworkedRadioButtonGroup.AddButton(tmpRB, ui.__mem_func__(self.OnClickTabButton), None)

		def __SetReworkedTabNames(self, groupSize):
			for buttonNumb in xrange(groupSize):
				self.reworkedRadioButtonGroup.SetText(buttonNumb, constInfo.NumberToStrRomanNumerals((buttonNumb + 1)))
				self.reworkedRadioButtonGroup.SetTextPosition(buttonNumb, 0, 0)
				tabName = shop.GetTabName(buttonNumb)
				if tabName:
					self.reworkedRadioButtonGroup.SetToolTipText(buttonNumb, tabName.replace("_", " "))
				else:
					self.reworkedRadioButtonGroup.SetToolTipText(buttonNumb, "")


# ShopDialog.Open icinde, ilgili if blogunun sonuna ekle:
		elif app.ENABLE_RENEWAL_SHOPEX:
			if isPrivateShop:
				self.__HideMiddleTabs()
				self.__HideSmallTabs()
			else:
				tabCount = shop.GetTabCount()
				if tabCount > 0:
					self.__CreateReworkedShopButtons(tabCount)
					self.__SetReworkedTabNames(tabCount)
					self.reworkedRadioButtonGroup.OnClick(0)
				else:
					self.__ShowBuySellButton()
					self.__HideMiddleTabs()
					self.__HideSmallTabs()


# ShopDialog.OverInItem icinde ara:
			return
		if self.tooltipItem:

# Altina ekle:
			if app.ENABLE_RENEWAL_SHOPEX:
				PriceType = shop.GetItemPriceType(slotIndex)
				if app.ENABLE_SHOPEX_EXTRA_PRICE and (PriceType == shop.SHOPEX_ITEM or shop.GetItemExtraPrice(slotIndex, 0)[0] or (PriceType == shop.SHOPEX_GOLD and not shop.IsPrivateShop())):
					self.tooltipItem.SetShopItemMultiPrice(slotIndex)
					self.__SetHoverPriceItems(slotIndex)
				elif PriceType == shop.SHOPEX_GOLD:
					self.tooltipItem.SetShopItem(slotIndex)
				elif PriceType == shop.SHOPEX_COINS:
					self.tooltipItem.SetShopItemBySecondaryCoin(slotIndex)
				else:
					self.tooltipItem.SetShopItemByShopEx(slotIndex, PriceType)
			else:
				if shop.SHOP_COIN_TYPE_GOLD == shop.GetTabCoinType(self.tabIdx):
					self.tooltipItem.SetShopItem(slotIndex)
				else: 
					self.tooltipItem.SetShopItemBySecondaryCoin(slotIndex)


# ShopDialog.__SetHoverPriceItems icinde ara:
		if shop.GetItemPriceType(slotIndex) == shop.SHOPEX_ITEM:
			items.append(shop.GetItemPriceVnum(slotIndex))

# Altina ekle:
		for n in xrange(5 if app.ENABLE_SHOPEX_EXTRA_PRICE_5 else 3 if app.ENABLE_SHOPEX_EXTRA_PRICE_3 else 2):
			(vnum, count) = shop.GetItemExtraPrice(slotIndex, n)
			if vnum and count:
				items.append(vnum)


# ShopDialog.OnUpdate icinde ara:
	def OnUpdate(self):

# Altina ekle:
		if app.ENABLE_SHOPEX_EXTRA_PRICE and app.ENABLE_IKASHOP_RENEWAL:
			self.__CheckPriceSearchKeys()

