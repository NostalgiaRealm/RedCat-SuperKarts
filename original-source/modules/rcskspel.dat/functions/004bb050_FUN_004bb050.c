/*
 * FUN_004bb050 at 004bb050
 * undefined FUN_004bb050(void)
 * Address ranges: 004bb050-004bb4f8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

LRESULT FUN_004bb050(HWND param_1,uint param_2,uint param_3,int param_4)

{
  BOOL BVar1;
  int iVar2;
  code *pcVar3;
  LRESULT LVar4;
  tagRECT tStack_50;
  tagPAINTSTRUCT tStack_40;
  
  if (param_2 < 0x117) {
    if (param_2 == 0x116) {
      if (DAT_006abb24 != (code *)0x0) {
        param_2 = 0x116;
        pcVar3 = DAT_006abb24;
        goto LAB_004bb166;
      }
      goto switchD_004bb0a2_caseD_3;
    }
    if (param_2 < 0x21) {
      if (param_2 == 0x20) {
        if (((DAT_006ab95c == 0) || (iVar2 = FUN_004b9d80(), iVar2 == 0)) ||
           (iVar2 = FUN_004b9bb0(), iVar2 == 2)) {
          SetCursor((HCURSOR)0x0);
        }
        if (DAT_006abb18 != (code *)0x0) {
          (*DAT_006abb18)(param_1,0x20,param_3,param_4);
          return 0;
        }
switchD_004bb0a2_caseD_14:
        return 1;
      }
      switch(param_2) {
      case 2:
        FUN_004afce0(s__s__d____DESTROY_MESSAGE_00502240,s_C__libraries_dxdraw_Msg_cpp_0050225c,
                     0x196);
        PostQuitMessage(0);
        LVar4 = DefWindowProcA(param_1,param_2,param_3,param_4);
        return LVar4;
      default:
        goto switchD_004bb0a2_caseD_3;
      case 6:
        _DAT_006abadc = param_3 >> 0x10;
        _DAT_006abad8 = param_3 & 0xffff;
        return 0;
      case 7:
        pcVar3 = DAT_006abb14;
        goto LAB_004bb39c;
      case 8:
        pcVar3 = DAT_006abb10;
        break;
      case 0xf:
        pcVar3 = DAT_006abb1c;
        if (DAT_006abb1c == (code *)0x0) {
          BVar1 = GetUpdateRect(param_1,&tStack_50,0);
          if (BVar1 == 0) {
            return 0;
          }
          BeginPaint(param_1,&tStack_40);
          EndPaint(param_1,&tStack_40);
          return 0;
        }
        goto LAB_004bb3af;
      case 0x12:
        FUN_004afce0(s__s__d____QUIT_MESSAGE_00502228,s_C__libraries_dxdraw_Msg_cpp_0050225c,0x19a);
        LVar4 = DefWindowProcA(param_1,param_2,param_3,param_4);
        return LVar4;
      case 0x14:
        goto switchD_004bb0a2_caseD_14;
      case 0x1c:
        _DAT_006abae4 = param_3 >> 0x10;
        DAT_006abae0 = param_3 & 0xffff;
        return 0;
      }
      goto LAB_004bb153;
    }
    switch(param_2) {
    case 0x2b:
      pcVar3 = DAT_006abb2c;
      if (DAT_006abb2c != (code *)0x0) goto LAB_004bb3af;
      if (*(int *)(param_4 + 0x14) != DAT_006a64b4) {
        LVar4 = FUN_004bb960(*(int *)(param_4 + 0x14),param_2,param_3,param_4);
        return LVar4;
      }
      goto switchD_004bb0a2_caseD_3;
    case 0x2c:
      pcVar3 = DAT_006abb30;
      break;
    default:
      goto switchD_004bb0a2_caseD_3;
    case 0x100:
      pcVar3 = DAT_006abb20;
      goto LAB_004bb39c;
    case 0x102:
      pcVar3 = DAT_006abaf0;
      break;
    case 0x104:
      pcVar3 = DAT_006abaf8;
      break;
    case 0x106:
      pcVar3 = DAT_006abaf4;
      goto LAB_004bb39c;
    case 0x111:
      pcVar3 = DAT_006abaec;
      goto LAB_004bb39c;
    case 0x113:
      FUN_004bbf90(param_3);
      LVar4 = DefWindowProcA(param_1,param_2,param_3,param_4);
      return LVar4;
    }
    goto LAB_004bb153;
  }
  if (0x200 < param_2) {
    if (0x205 < param_2) {
      if (param_2 == 0x219) {
        FUN_004bc090(param_1,0x219,param_3,param_4);
      }
      else if (param_2 == 0x30f) {
        if (DAT_006abb38 != (code *)0x0) {
          param_2 = 0x30f;
          pcVar3 = DAT_006abb38;
          goto LAB_004bb166;
        }
      }
      else if ((param_2 == 0x311) && (DAT_006abb34 != (code *)0x0)) {
        param_2 = 0x311;
        pcVar3 = DAT_006abb34;
        goto LAB_004bb3af;
      }
      goto switchD_004bb0a2_caseD_3;
    }
    if (param_2 != 0x205) {
      if (param_2 != 0x201) {
        if (param_2 == 0x202) {
          if (DAT_006abb04 != (code *)0x0) {
            param_2 = 0x202;
            pcVar3 = DAT_006abb04;
            goto LAB_004bb166;
          }
        }
        else if ((param_2 == 0x204) && (DAT_006abb08 != (code *)0x0)) {
          param_2 = 0x204;
          pcVar3 = DAT_006abb08;
          goto LAB_004bb3af;
        }
        goto switchD_004bb0a2_caseD_3;
      }
      if (DAT_006abb00 == (code *)0x0) goto switchD_004bb0a2_caseD_3;
      param_2 = 0x201;
      pcVar3 = DAT_006abb00;
      goto LAB_004bb3af;
    }
    if (DAT_006abb0c == (code *)0x0) goto switchD_004bb0a2_caseD_3;
    param_2 = 0x205;
    pcVar3 = DAT_006abb0c;
    goto LAB_004bb166;
  }
  if (param_2 == 0x200) {
    if (DAT_006abafc != (code *)0x0) {
      param_2 = 0x200;
      pcVar3 = DAT_006abafc;
      goto LAB_004bb166;
    }
    goto switchD_004bb0a2_caseD_3;
  }
  switch(param_2) {
  case 0x11f:
    pcVar3 = DAT_006abb28;
    goto LAB_004bb153;
  default:
    goto switchD_004bb0a2_caseD_3;
  case 0x132:
    pcVar3 = DAT_006abb4c;
    break;
  case 0x133:
    pcVar3 = DAT_006abb44;
    break;
  case 0x134:
    pcVar3 = DAT_006abb48;
    goto LAB_004bb153;
  case 0x135:
    pcVar3 = DAT_006abb3c;
    break;
  case 0x136:
    pcVar3 = DAT_006abb40;
LAB_004bb153:
    if (pcVar3 != (code *)0x0) {
LAB_004bb166:
      (*pcVar3)(param_1,param_2,param_3,param_4);
      return 0;
    }
    goto switchD_004bb0a2_caseD_3;
  case 0x137:
    if (DAT_006abb50 != (code *)0x0) {
      (*DAT_006abb50)(param_1,param_2,param_3,param_4);
      return 0;
    }
    goto switchD_004bb0a2_caseD_3;
  case 0x138:
    pcVar3 = DAT_006abb54;
  }
LAB_004bb39c:
  if (pcVar3 != (code *)0x0) {
LAB_004bb3af:
    (*pcVar3)(param_1,param_2,param_3,param_4);
    return 0;
  }
switchD_004bb0a2_caseD_3:
  LVar4 = DefWindowProcA(param_1,param_2,param_3,param_4);
  return LVar4;
}

