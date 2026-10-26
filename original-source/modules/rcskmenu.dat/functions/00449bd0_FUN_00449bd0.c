/*
 * FUN_00449bd0 at 00449bd0
 * undefined __register FUN_00449bd0(undefined4 param_1, char param_2)
 * Address ranges: 00449bd0-00449ca8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00449bd0(undefined4 param_1,char param_2)

{
  int iVar1;
  
  if ((PTR_DAT_0047c9d8[8] != '\0') && (param_2 != '\x03')) {
    if (param_2 == '\0') {
      FUN_00449bb4();
    }
    else {
      FUN_00449bb4();
      if (DAT_0047ba18 != 0) {
        iVar1 = (*DAT_0047d7f0)();
        if (iVar1 != 0) {
          (*DAT_0047d7f8)();
          if (param_2 == '\x01') {
            (*DAT_0047d800)();
          }
          else if (param_2 == '\x02') {
            (*DAT_0047d800)();
          }
          else {
            (*DAT_0047d800)();
            (*DAT_0047d7f8)();
          }
          (*DAT_0047d7fc)();
          (*DAT_0047d7f4)();
        }
      }
    }
  }
  return;
}

