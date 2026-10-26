/*
 * FUN_004c852f at 004c852f
 * undefined FUN_004c852f(void)
 * Address ranges: 004c852f-004c855b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_004c852f(byte param_1)

{
  undefined4 uStack_4;
  
  if ((param_1 & 0x20) == 0) {
    if ((param_1 & 8) == 0) {
      if ((param_1 & 4) == 0) {
        if ((param_1 & 1) == 0) {
          return (param_1 & 2) << 1;
        }
        uStack_4 = 3;
      }
      else {
        uStack_4 = 2;
      }
    }
    else {
      uStack_4 = 1;
    }
  }
  else {
    uStack_4 = 5;
  }
  return uStack_4;
}

