# ItemToolTip icinde ara:
		self.AddItemData(itemVnum, metinSlot, attrSlot)
		self.AppendPriceBySecondaryCoin(price)

# Altina ekle:
	if app.ENABLE_RENEWAL_SHOPEX:
		def SetShopItemMultiPrice(self, slotIndex):
			itemVnum = shop.GetItemID(slotIndex)
			if not itemVnum:
				return
			prices = []
			price = shop.GetItemPrice(slotIndex)
			if shop.GetItemPriceType(slotIndex) == shop.SHOPEX_ITEM:
				prices.append((shop.GetItemPriceVnum(slotIndex), price))
			elif price > 0:
				prices.append((1, price))		# vnum 1 = Yang
			extras = 0
			for n in xrange(5 if app.ENABLE_SHOPEX_EXTRA_PRICE_5 else 3 if app.ENABLE_SHOPEX_EXTRA_PRICE_3 else 2):
				(vnum, count) = shop.GetItemExtraPrice(slotIndex, n)
				if vnum and count:
					prices.append((vnum, count))
					extras += 1

			rows = []
			item.SelectItem(itemVnum)
			if item.IsFlag(item.ITEM_FLAG_STACKABLE):
				rows.append((("alt", "mouse_right"), localeInfo.TOOLTIP_SHORTCUT_MULTI_BUY_SHOP))
			if app.ENABLE_IKASHOP_RENEWAL:
				rows.append((("ctrl", "mouse_right"), localeInfo.TOOLTIP_SHORTCUT_SHOP_SEARCH))
			if app.ENABLE_WIKI_SYSTEM:
				rows.append((("ctrl", "alt", "mouse_left"), localeInfo.TOOLTIP_SHORTCUT_WIKI))
			if app.ENABLE_IKASHOP_RENEWAL:
				for (n, vnum) in enumerate([v for (v, c) in prices if v != 1][:5]):
					item.SelectItem(vnum)
					rows.append((("ctrl", str(n + 1)), localeInfo.TOOLTIP_SHORTCUT_SHOP_SEARCH_PRICE % item.GetItemName()))

			measure = ui.TextLine()
			measure.SetFontName(self.defFontName)
			textWidth = 0
			for (keys, text) in rows:
				measure.SetText(text)
				textWidth = max(textWidth, measure.GetTextSize()[0])
			self.ClearToolTip()
			self.isShopItem = TRUE
			self.toolTipWidth = max(310, 175 + textWidth)
			metinSlot = [shop.GetItemMetinSocket(slotIndex, i) for i in xrange(player.METIN_SOCKET_MAX_NUM)]
			attrSlot = [shop.GetItemAttribute(slotIndex, i) for i in xrange(player.ATTRIBUTE_SLOT_MAX_NUM)]
			self.descUtf8Limit = 35
			try:
				self.AddItemData(itemVnum, metinSlot, attrSlot)
			finally:
				self.descUtf8Limit = 0

			self.AppendSpace(5)
			self.AppendTextLine(localeInfo.TOOLTIP_SHOP_SELL_PRICE, self.FONT_COLOR)
			for (vnum, count) in prices:
				self.__AppendPriceRow(vnum, count)
			self.AppendSpace(7)
			self.AppendShortcutTable(rows)
			self.ResizeToolTip()

		def __AppendPriceRow(self, vnum, count):
			PRICE_LACK_COLOR = 0xffe57875
			item.SelectItem(vnum)
			if vnum == 1:
				owned = player.GetElk()
				text = localeInfo.NumberToMoneyString(count)
			else:
				owned = player.GetItemCountByVnum(vnum)
				text = "%d %s (%d)" % (count, item.GetItemName(), owned)
			color = PRICE_LACK_COLOR if owned < count else self.FONT_COLOR
			icon = ui.ImageBox()
			icon.SetParent(self)
			icon.LoadImage(item.GetIconImageFileName())
			line = ui.TextLine()
			line.SetParent(self)
			line.SetFontName(self.defFontName)
			line.SetPackedFontColor(color)
			line.SetOutline()
			line.SetText(text)
			(tw, th) = line.GetTextSize()
			total = icon.GetWidth() + 4 + tw
			x = max(0, (self.toolTipWidth - total) / 2)
			y = self.toolTipHeight
			icon.SetPosition(x, y)
			icon.Show()
			line.SetPosition(x + icon.GetWidth() + 4, y + 10)
			line.Show()
			self.childrenList.append(icon)
			self.childrenList.append(line)
			self.toolTipHeight += 40
			self.ResizeToolTip()

		def SetShopItemByShopEx(self, slotIndex, type):
			itemVnum = shop.GetItemID(slotIndex)
			PriceVnum = shop.GetItemPriceVnum(slotIndex)

			if itemVnum == 0 or (PriceVnum == 0 and type == shop.SHOPEX_ITEM):
				return

			price = shop.GetItemPrice(slotIndex)
			self.ClearToolTip()
			self.isShopItem = TRUE
			metinSlot = []

			for i in xrange(player.METIN_SOCKET_MAX_NUM):
				metinSlot.append(shop.GetItemMetinSocket(slotIndex, i))
			attrSlot = []

			for i in xrange(player.ATTRIBUTE_SLOT_MAX_NUM):
				attrSlot.append(shop.GetItemAttribute(slotIndex, i))
			self.AddItemData(itemVnum, metinSlot, attrSlot)
			self.AppendSpace(5)

			if type == shop.SHOPEX_ITEM:
				self.AddSHOPEXItem(PriceVnum, price)
			else:
				self.AppendTextLine(localeInfo.TOOLTIP_BUYPRICE  % (localeInfo.NumberToShopEXP(price)), self.GetPriceColor(price))

		def AddSHOPEXItem(self, itemVnum, price):
			self.AppendTextLine(localeInfo.AUTO_PRICE)
			item.SelectItem(itemVnum)

			name = "%s(%dx)" % (item.GetItemName(), price)
			self.AutoAppendTextLine(name, self.SPECIAL_TITLE_COLOR)

			itemImage = ui.ImageBox()
			itemImage.SetParent(self)
			itemImage.Show()
			itemImage.LoadImage(item.GetIconImageFileName())
			itemImage.SetPosition(95, self.toolTipHeight)

			self.toolTipHeight += itemImage.GetHeight() - 10
			self.childrenList.append(itemImage)
			self.ResizeToolTip()

