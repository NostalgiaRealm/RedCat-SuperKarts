/*
 * FUN_00465840 at 00465840
 * undefined FUN_00465840(void)
 * Address ranges: 00465840-00465874
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00465840(int param_1)

{
  char cVar1;
  
  cVar1 = FUN_00415be0(DAT_0053be28);
  if ((cVar1 != '\0') && (*(int *)(param_1 + 0x10) == 0)) {
    *(undefined4 *)(param_1 + 0x14) = 2;
    *(undefined4 *)(param_1 + 0x20) = 0x3f800000;
    FUN_004654b0();
  }
  return;
}

