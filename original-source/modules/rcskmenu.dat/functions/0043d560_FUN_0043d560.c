/*
 * FUN_0043d560 at 0043d560
 * undefined __register FUN_0043d560(int param_1, char param_2, undefined4 param_3)
 * Address ranges: 0043d560-0043d5bc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043d560(int param_1,char param_2,undefined4 param_3)

{
  int iVar1;
  
  if (param_1 != 0) {
    if (DAT_0047d7e0 == (int *)0x0) {
      DAT_0047d7e0 = (int *)FUN_00402e7c((int *)&PTR_FUN_0040de6c,'\x01',param_3);
    }
    iVar1 = FUN_0040f70c((int)DAT_0047d7e0,param_1);
    if (param_2 == '\0') {
      if (iVar1 != -1) {
        FUN_0040f550(DAT_0047d7e0,iVar1);
      }
    }
    else if (iVar1 == -1) {
      FUN_0040f504(DAT_0047d7e0,param_1);
    }
  }
  return;
}

