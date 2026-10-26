/*
 * FUN_004b5c20 at 004b5c20
 * undefined FUN_004b5c20(void)
 * Address ranges: 004b5c20-004b5d7a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b5c20(undefined4 param_1,byte param_2,undefined4 param_3,undefined4 param_4,uint param_5
                 ,uint param_6,uint param_7,uint param_8)

{
  uint uVar1;
  
  if ((param_2 & 0x20) == 0) {
    _DAT_006ab7f8 = 0;
    DAT_006ab81c = 0;
    for (uVar1 = param_5; (uVar1 & 1) == 0; uVar1 = (int)uVar1 >> 1) {
      DAT_006ab81c = DAT_006ab81c + 1;
    }
    DAT_006ab7ec = 0;
    for (; (uVar1 & 1) != 0; uVar1 = (int)uVar1 >> 1) {
      DAT_006ab7ec = DAT_006ab7ec + 1;
    }
    DAT_006ab7fc = param_5;
    DAT_006ab80c = 8 - DAT_006ab7ec;
    DAT_006ab820 = 0;
    for (uVar1 = param_6; (uVar1 & 1) == 0; uVar1 = (int)uVar1 >> 1) {
      DAT_006ab820 = DAT_006ab820 + 1;
    }
    DAT_006ab7f0 = 0;
    for (; (uVar1 & 1) != 0; uVar1 = (int)uVar1 >> 1) {
      DAT_006ab7f0 = DAT_006ab7f0 + 1;
    }
    DAT_006ab800 = param_6;
    DAT_006ab810 = 8 - DAT_006ab7f0;
    DAT_006ab824 = 0;
    for (uVar1 = param_7; (uVar1 & 1) == 0; uVar1 = (int)uVar1 >> 1) {
      DAT_006ab824 = DAT_006ab824 + 1;
    }
    DAT_006ab7f4 = 0;
    for (; (uVar1 & 1) != 0; uVar1 = (int)uVar1 >> 1) {
      DAT_006ab7f4 = DAT_006ab7f4 + 1;
    }
    DAT_006ab814 = 8 - DAT_006ab7f4;
    _DAT_006ab804 = param_7;
    if ((param_2 & 1) != 0) {
      DAT_006ab828 = 0;
      for (uVar1 = param_8; (uVar1 & 1) == 0; uVar1 = (int)uVar1 >> 1) {
        DAT_006ab828 = DAT_006ab828 + 1;
      }
      for (; (uVar1 & 1) != 0; uVar1 = (int)uVar1 >> 1) {
        _DAT_006ab7f8 = _DAT_006ab7f8 + 1;
      }
      DAT_006ab818 = 8 - _DAT_006ab7f8;
      _DAT_006ab808 = param_8;
      FUN_004afce0(s_RGBA___d__d__d__d_00500c20,DAT_006ab7ec,DAT_006ab7f0,DAT_006ab7f4,_DAT_006ab7f8
                  );
      return;
    }
    DAT_006ab828 = 0x20;
    _DAT_006ab7f8 = 0;
    DAT_006ab818 = 0;
    _DAT_006ab808 = 0;
    FUN_004afce0(s_RGB___d__d__d_00500c10,DAT_006ab7ec,DAT_006ab7f0,DAT_006ab7f4);
  }
  return;
}

