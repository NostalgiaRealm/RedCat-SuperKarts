/*
 * FUN_004b3880 at 004b3880
 * undefined FUN_004b3880(void)
 * Address ranges: 004b3880-004b3901
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004b3880(uint param_1,uint param_2)

{
  SHORT SVar1;
  int iVar2;
  
  if (((int)param_2 < 0) || (3 < (int)param_2)) {
    FUN_004afee0(s__keyispressed__illegal_device_re_0050004c,param_2);
  }
  if ((param_2 & 2) != 0) {
    iVar2 = FUN_004baec0(param_1);
    if (iVar2 != 0) {
      return 0xffffffff;
    }
  }
  if ((param_2 & 1) != 0) {
    if ((param_1 & 0x100) == 0) {
      SVar1 = GetAsyncKeyState(0x10);
      if (-1 < SVar1) {
        SVar1 = GetAsyncKeyState(param_1);
        if (SVar1 < 0) {
          return 0xffffffff;
        }
      }
    }
    else {
      SVar1 = GetAsyncKeyState(0x10);
      if (SVar1 < 0) {
        SVar1 = GetAsyncKeyState(param_1);
        if (SVar1 < 0) {
          return 0xffffffff;
        }
      }
    }
  }
  return 0;
}

