/*
 * FUN_00440dd0 at 00440dd0
 * undefined FUN_00440dd0(void)
 * Address ranges: 00440dd0-00440e3e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00440dd0(int param_1)

{
  int iVar1;
  
  if ((((DAT_0053b9c0 == 0) || (DAT_0053b9c0 == 7)) || (DAT_0053b9c0 == 8)) && (DAT_0053d1d8 != 0))
  {
    iVar1 = DAT_0067ee20 + param_1 * 0xd0;
    if (*(int *)(iVar1 + 0x20) < *(int *)(iVar1 + 0x1c)) {
      FUN_00440c30();
      if (DAT_0053ba1c <= DAT_0053ba18) {
        FUN_00440d70();
        FUN_00430610(8);
        return;
      }
    }
    else {
      DAT_0053d1d8 = 0;
    }
    FUN_00430610(8);
  }
  return;
}

