/*
 * FUN_004b5470 at 004b5470
 * undefined FUN_004b5470(void)
 * Address ranges: 004b5470-004b55a9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_004b5470(uint param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  if (DAT_006ab7e8 == 0) {
    FUN_004afee0(s__s__d____error_please_use_get_xv_00500b5c,
                 s_C__libraries_dxdraw_Pformat_cpp_00500af4,0xe9);
  }
  if (DAT_004fe938 == 8) {
    FUN_004afee0(s__s___d___Translation_from_24_bit_00500b14,
                 s_C__libraries_dxdraw_Pformat_cpp_00500af4,0xf2);
  }
  else if ((DAT_004fe938 == 0x10) || (DAT_004fe938 == 0x18)) {
    iVar3 = _DAT_006ab77c;
    iVar5 = _DAT_006ab774;
    iVar6 = _DAT_006ab778;
    if (param_1 != DAT_006a6500) {
      uVar4 = param_1 & 0xff;
      if (DAT_006ab830 != 0) {
        uVar4 = (int)(uVar4 * uVar4) >> 8;
      }
      uVar1 = param_1 >> 8 & 0xff;
      if (DAT_006ab830 != 0) {
        uVar1 = (int)(uVar1 * uVar1) >> 8;
      }
      uVar2 = param_1 >> 0x10 & 0xff;
      if (DAT_006ab830 != 0) {
        uVar2 = (int)(uVar2 * uVar2) >> 8;
      }
      iVar3 = (int)uVar2 >> ((byte)DAT_006ab814 & 0x1f);
      iVar5 = (int)uVar4 >> ((byte)DAT_006ab80c & 0x1f);
      iVar6 = (int)uVar1 >> ((byte)DAT_006ab810 & 0x1f);
    }
    if ((((iVar5 == _DAT_006ab774) && (iVar6 == _DAT_006ab778)) && (iVar3 == _DAT_006ab77c)) &&
       (param_1 != DAT_006a6500)) {
      if (iVar5 == 0) {
        iVar5 = 1;
      }
      else {
        iVar5 = iVar5 + -1;
      }
    }
    return (iVar3 << ((byte)DAT_006ab824 & 0x1f)) + (iVar6 << ((byte)DAT_006ab820 & 0x1f)) +
           (iVar5 << ((byte)DAT_006ab81c & 0x1f));
  }
  return param_1;
}

