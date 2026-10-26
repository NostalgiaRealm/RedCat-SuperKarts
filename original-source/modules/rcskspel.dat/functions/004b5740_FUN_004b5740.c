/*
 * FUN_004b5740 at 004b5740
 * undefined FUN_004b5740(void)
 * Address ranges: 004b5740-004b58de
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_004b5740(uint param_1,undefined4 param_2)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  if (DAT_006ab7e8 == 0) {
    FUN_004afee0(s__s__d____error_please_use_get_xv_00500b5c,
                 s_C__libraries_dxdraw_Pformat_cpp_00500af4,0x1a7);
  }
  switch(param_2) {
  case 8:
    if (DAT_004fe938 == 8) {
      return param_1;
    }
    if (DAT_004fe938 == 0x10) {
      uVar2 = (uint)*(byte *)(DAT_006ab468 + param_1 * 4);
      if (DAT_006ab830 != 0) {
        uVar2 = (int)(uVar2 * uVar2) >> 8;
      }
      uVar3 = (uint)*(byte *)(DAT_006ab468 + 1 + param_1 * 4);
      if (DAT_006ab830 != 0) {
        uVar3 = (int)(uVar3 * uVar3) >> 8;
      }
      uVar4 = (uint)*(byte *)(DAT_006ab468 + 2 + param_1 * 4);
      if (DAT_006ab830 != 0) {
        uVar4 = (int)(uVar4 * uVar4) >> 8;
      }
      iVar6 = (int)uVar2 >> ((byte)DAT_006ab80c & 0x1f);
      iVar7 = (int)uVar3 >> ((byte)DAT_006ab810 & 0x1f);
      iVar5 = (int)uVar4 >> ((byte)DAT_006ab814 & 0x1f);
      if ((((param_1 != DAT_004ffedc) && (iVar6 == _DAT_006ab774)) && (iVar7 == _DAT_006ab778)) &&
         (iVar5 == _DAT_006ab77c)) {
        iVar6 = _DAT_006ab774 + 1;
      }
      return (iVar5 << ((byte)DAT_006ab824 & 0x1f)) + (iVar7 << ((byte)DAT_006ab820 & 0x1f)) +
             (iVar6 << ((byte)DAT_006ab81c & 0x1f));
    }
    if (DAT_004fe938 == 0x18) {
      return (uint)CONCAT21(CONCAT11(*(undefined1 *)(DAT_006ab468 + param_1 * 4),
                                     *(undefined1 *)(DAT_006ab468 + 1 + param_1 * 4)),
                            *(undefined1 *)(DAT_006ab468 + 2 + param_1 * 4));
    }
    break;
  case 0x10:
    if (DAT_004fe938 == 8) {
      FUN_004afee0(s_not_yet_supported_00500b94);
      return param_1;
    }
    if (DAT_004fe938 == 0x10) {
      return param_1;
    }
    if (DAT_004fe938 == 0x18) {
      return param_1;
    }
    break;
  case 0x18:
    sVar1 = FUN_004b5470(param_1);
    return (int)sVar1;
  case 0x20:
    sVar1 = FUN_004b55b0(param_1);
    return (int)sVar1;
  }
  return 0;
}

