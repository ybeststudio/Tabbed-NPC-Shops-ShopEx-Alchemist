// bool CPythonNetworkStream::RecvShopPacket() icinde:
// Ara:
					TPacketGCShopStartEx::TSubPacketShopTab* pPackTab = (TPacketGCShopStartEx::TSubPacketShopTab*)&vecBuffer[read_point];
					read_point += sizeof(TPacketGCShopStartEx::TSubPacketShopTab);
					CPythonShop::instance().SetTabCoinType(i, pPackTab->coin_type);

// Altina ekle:
#ifdef ENABLE_SHOPEX_TAB_LEVEL
					CPythonShop::instance().SetTabLevelMin(i, pPackTab->level_min);
#endif


// bool CPythonNetworkStream::RecvShopPacket() icinde:
// Ara:
		case SHOP_SUBHEADER_GC_INVALID_POS:
			PyCallClassMemberFunc(m_apoPhaseWnd[PHASE_WINDOW_GAME], "OnShopError", Py_BuildValue("(s)", "INVALID_POS"));
			break;

// Altina ekle:
#ifdef ENABLE_RENEWAL_SHOPEX
		case SHOP_SUBHEADER_GC_NOT_ENOUGH_ITEM:
			PyCallClassMemberFunc(m_apoPhaseWnd[PHASE_WINDOW_GAME], "OnShopError", Py_BuildValue("(s)", "NOT_ENOUGH_ITEM"));
			break;

		case SHOP_SUBHEADER_GC_NOT_ENOUGH_EXP:
			PyCallClassMemberFunc(m_apoPhaseWnd[PHASE_WINDOW_GAME], "OnShopError", Py_BuildValue("(s)", "NOT_ENOUGH_EXP"));
			break;

		case SHOP_SUBHEADER_GC_YOU_ALREADY_HAVE_ONE:
			PyCallClassMemberFunc(m_apoPhaseWnd[PHASE_WINDOW_GAME], "OnShopError", Py_BuildValue("(s)", "ALREADY_HAVE_ONE_ITEM"));
			break;
#endif

