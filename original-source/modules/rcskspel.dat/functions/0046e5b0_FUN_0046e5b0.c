/*
 * FUN_0046e5b0 at 0046e5b0
 * undefined FUN_0046e5b0(void)
 * Address ranges: 0046e5b0-0046e646
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0046e5b0(int param_1)

{
  int iVar1;
  
  FUN_0046e330();
  iVar1 = FUN_004b3830(0x70);
  if (((iVar1 != 0) && (DAT_00544b60 < 0xc)) && (DAT_00544b64 == '\0')) {
    DAT_00544b64 = '\x01';
    (**(code **)(**(int **)(param_1 + 0xc + DAT_00544b60 * 4) + 0x28))(&DAT_004d2db0);
    DAT_00544b60 = DAT_00544b60 + 1;
  }
  iVar1 = FUN_004b3830(0x71);
  if ((iVar1 != 0) && (DAT_00544b64 == '\0')) {
    DAT_00544b64 = '\x01';
    if (0 < DAT_00544b60) {
      (**(code **)(**(int **)(param_1 + 0xc + DAT_00544b60 * 4) + 0x28))(&DAT_004d2db4);
      DAT_00544b60 = DAT_00544b60 + -1;
    }
  }
  iVar1 = FUN_004b3830(0x7a);
  if (iVar1 != 0) {
    DAT_00544b64 = '\0';
  }
  return;
}

