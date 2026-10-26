/*
 * FUN_0040aa20 at 0040aa20
 * LRESULT __stdcall FUN_0040aa20(HWND param_1, uint param_2, uint param_3, int param_4)
 * Address ranges: 0040aa20-0040b1e7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

LRESULT FUN_0040aa20(HWND param_1,uint param_2,uint param_3,int param_4)

{
  int iVar1;
  BOOL BVar2;
  LRESULT LVar3;
  tagPAINTSTRUCT local_54;
  tagRECT local_14;
  
  if (param_2 < 0x1d) {
    if (param_2 == 0x1c) {
      DAT_0043d534 = param_3 & 0xffff;
      _DAT_0043d538 = param_3 >> 0x10;
      return 0;
    }
    switch(param_2) {
    case 1:
      break;
    case 2:
      FUN_004015a6((byte *)s__s__d____DESTROY_MESSAGE_004316a0);
      PostQuitMessage(0);
      break;
    case 6:
      _DAT_0043d52c = param_3 & 0xffff;
      _DAT_0043d530 = param_3 >> 0x10;
      return 0;
    case 7:
      if (DAT_0043d568 != (code *)0x0) {
        (*DAT_0043d568)(param_1,param_2,param_3,param_4);
        return 0;
      }
      break;
    case 8:
      if (DAT_0043d564 != (code *)0x0) {
        (*DAT_0043d564)(param_1,param_2,param_3,param_4);
        return 0;
      }
      break;
    case 0xf:
      if (DAT_0043d570 != (code *)0x0) {
        (*DAT_0043d570)(param_1,param_2,param_3,param_4);
        return 0;
      }
      BVar2 = GetUpdateRect(param_1,&local_14,0);
      if (BVar2 != 0) {
        BeginPaint(param_1,&local_54);
        EndPaint(param_1,&local_54);
      }
      return 0;
    case 0x12:
      FUN_004015a6((byte *)s__s__d____QUIT_MESSAGE_004316c4);
      break;
    case 0x14:
      return 1;
    }
  }
  else if (param_2 < 0x2c) {
    if (param_2 == 0x2b) {
      if (DAT_0043d580 != (code *)0x0) {
        (*DAT_0043d580)(param_1,0x2b,param_3,param_4);
        return 0;
      }
      if (*(int *)(param_4 + 0x14) != DAT_0043842c) {
        LVar3 = FUN_00411cc0(*(int *)(param_4 + 0x14),0x2b,param_3,param_4);
        return LVar3;
      }
    }
    else if (param_2 == 0x20) {
      if ((DAT_00438488 == 0) || (iVar1 = FUN_00404a61(), iVar1 == 0)) {
        SetCursor((HCURSOR)0x0);
      }
      else {
        iVar1 = FUN_004047e0();
        if (iVar1 == 2) {
          SetCursor((HCURSOR)0x0);
        }
      }
      if (DAT_0043d56c != (code *)0x0) {
        (*DAT_0043d56c)(param_1,0x20,param_3,param_4);
        return 0;
      }
      return 1;
    }
  }
  else if (param_2 < 0x101) {
    if (param_2 == 0x100) {
      if (DAT_0043d574 != (code *)0x0) {
        (*DAT_0043d574)(param_1,0x100,param_3,param_4);
        return 0;
      }
    }
    else if ((param_2 == 0x2c) && (DAT_0043d584 != (code *)0x0)) {
      (*DAT_0043d584)(param_1,0x2c,param_3,param_4);
      return 0;
    }
  }
  else if (param_2 < 0x112) {
    if (param_2 == 0x111) {
      if (DAT_0043d540 != (code *)0x0) {
        (*DAT_0043d540)(param_1,0x111,param_3,param_4);
        return 0;
      }
    }
    else if (param_2 == 0x102) {
      if (DAT_0043d544 != (code *)0x0) {
        (*DAT_0043d544)(param_1,0x102,param_3,param_4);
        return 0;
      }
    }
    else if (param_2 == 0x104) {
      if (DAT_0043d54c != (code *)0x0) {
        (*DAT_0043d54c)(param_1,0x104,param_3,param_4);
        return 0;
      }
    }
    else if ((param_2 == 0x106) && (DAT_0043d548 != (code *)0x0)) {
      (*DAT_0043d548)(param_1,0x106,param_3,param_4);
      return 0;
    }
  }
  else if (param_2 < 0x117) {
    if (param_2 == 0x116) {
      if (DAT_0043d578 != (code *)0x0) {
        (*DAT_0043d578)(param_1,0x116,param_3,param_4);
        return 0;
      }
    }
    else if (param_2 == 0x113) {
      FUN_0040b5c6(param_3);
    }
  }
  else if (param_2 < 0x133) {
    if (param_2 == 0x132) {
      if (DAT_0043d5a0 != (code *)0x0) {
        (*DAT_0043d5a0)(param_1,0x132,param_3,param_4);
        return 0;
      }
    }
    else if ((param_2 == 0x11f) && (DAT_0043d57c != (code *)0x0)) {
      (*DAT_0043d57c)(param_1,0x11f,param_3,param_4);
      return 0;
    }
  }
  else if (param_2 < 0x201) {
    if (param_2 == 0x200) {
      if (DAT_0043d550 != (code *)0x0) {
        (*DAT_0043d550)(param_1,0x200,param_3,param_4);
        return 0;
      }
    }
    else {
      switch(param_2) {
      case 0x133:
        if (DAT_0043d598 != (code *)0x0) {
          (*DAT_0043d598)(param_1,param_2,param_3,param_4);
          return 0;
        }
        break;
      case 0x134:
        if (DAT_0043d59c != (code *)0x0) {
          (*DAT_0043d59c)(param_1,param_2,param_3,param_4);
          return 0;
        }
        break;
      case 0x135:
        if (DAT_0043d590 != (code *)0x0) {
          (*DAT_0043d590)(param_1,param_2,param_3,param_4);
          return 0;
        }
        break;
      case 0x136:
        if (DAT_0043d594 != (code *)0x0) {
          (*DAT_0043d594)(param_1,param_2,param_3,param_4);
          return 0;
        }
        break;
      case 0x137:
        if (DAT_0043d5a4 != (code *)0x0) {
          (*DAT_0043d5a4)(param_1,param_2,param_3,param_4);
          return 0;
        }
        break;
      case 0x138:
        if (DAT_0043d5a8 != (code *)0x0) {
          (*DAT_0043d5a8)(param_1,param_2,param_3,param_4);
          return 0;
        }
      }
    }
  }
  else if (param_2 < 0x310) {
    if (param_2 == 0x30f) {
      if (DAT_0043d58c != (code *)0x0) {
        (*DAT_0043d58c)(param_1,0x30f,param_3,param_4);
        return 0;
      }
    }
    else {
      switch(param_2) {
      case 0x201:
        if (DAT_0043d554 != (code *)0x0) {
          (*DAT_0043d554)(param_1,param_2,param_3,param_4);
          return 0;
        }
        break;
      case 0x202:
        if (DAT_0043d558 != (code *)0x0) {
          (*DAT_0043d558)(param_1,param_2,param_3,param_4);
          return 0;
        }
        break;
      case 0x204:
        if (DAT_0043d55c != (code *)0x0) {
          (*DAT_0043d55c)(param_1,param_2,param_3,param_4);
          return 0;
        }
        break;
      case 0x205:
        if (DAT_0043d560 != (code *)0x0) {
          (*DAT_0043d560)(param_1,param_2,param_3,param_4);
          return 0;
        }
      }
    }
  }
  else if ((param_2 == 0x311) && (DAT_0043d588 != (code *)0x0)) {
    (*DAT_0043d588)(param_1,0x311,param_3,param_4);
    return 0;
  }
  LVar3 = DefWindowProcA(param_1,param_2,param_3,param_4);
  return LVar3;
}

