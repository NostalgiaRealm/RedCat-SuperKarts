/*
 * FUN_004b5910 at 004b5910
 * undefined FUN_004b5910(void)
 * Address ranges: 004b5910-004b5aca
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b5910(uint param_1,int param_2,short *param_3)

{
  short sVar1;
  uint uVar2;
  byte bVar3;
  uint uVar5;
  byte bVar4;
  
  if (DAT_006ab7e8 == 0) {
    FUN_004afee0(s__s__d____error_please_use_get_xv_00500b5c,
                 s_C__libraries_dxdraw_Pformat_cpp_00500af4,0x1fd);
  }
  bVar3 = (byte)DAT_006ab820;
  bVar4 = (byte)DAT_006ab824;
  if (param_2 == 8) {
    if (DAT_004fe938 == 8) {
      *(char *)param_3 = (char)param_1;
      return;
    }
    if (DAT_004fe938 == 0x10) {
      *param_3 = ((ushort)(*(byte *)(DAT_006ab468 + 2 + param_1 * 4) >> ((byte)DAT_006ab814 & 0x1f))
                 << (bVar4 & 0x1f)) +
                 ((ushort)(*(byte *)(DAT_006ab468 + 1 + param_1 * 4) >> ((byte)DAT_006ab810 & 0x1f))
                 << (bVar3 & 0x1f)) +
                 ((ushort)(*(byte *)(DAT_006ab468 + param_1 * 4) >> ((byte)DAT_006ab80c & 0x1f)) <<
                 ((byte)DAT_006ab81c & 0x1f));
      return;
    }
    if (DAT_004fe938 == 0x18) {
      *(char *)(param_3 + 1) = *(char *)(DAT_006ab468 + param_1 * 4);
      *(char *)((int)param_3 + 1) = *(char *)(DAT_006ab468 + 1 + param_1 * 4);
      *(char *)param_3 = *(char *)(DAT_006ab468 + 2 + param_1 * 4);
    }
  }
  else if (param_2 == 0x10) {
    if (DAT_004fe938 == 8) {
      FUN_004afee0(s_not_yet_supported_00500b94);
      return;
    }
    if (DAT_004fe938 == 0x10) {
      *param_3 = (short)param_1;
      return;
    }
    if (DAT_004fe938 == 0x18) {
      uVar2 = DAT_006ab800 & param_1;
      uVar5 = _DAT_006ab804 & param_1;
      *(char *)(param_3 + 1) =
           (char)((int)(DAT_006ab7fc & param_1) >> ((byte)DAT_006ab81c & 0x1f)) <<
           ((byte)DAT_006ab80c & 0x1f);
      *(char *)((int)param_3 + 1) =
           (char)((int)uVar2 >> (bVar3 & 0x1f)) << ((byte)DAT_006ab810 & 0x1f);
      *(char *)param_3 = (char)((int)uVar5 >> (bVar4 & 0x1f)) << ((byte)DAT_006ab814 & 0x1f);
      return;
    }
  }
  else if (param_2 == 0x18) {
    if (DAT_004fe938 == 0x10) {
      sVar1 = FUN_004b5470(param_1);
      *param_3 = sVar1;
      return;
    }
    FUN_004afee0(s__s___d___Translation_from_24_bit_00500ba8,
                 s_C__libraries_dxdraw_Pformat_cpp_00500af4,0x23f,DAT_004fe938);
    return;
  }
  return;
}

