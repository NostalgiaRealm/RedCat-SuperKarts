/*
 * FUN_0040960e at 0040960e
 * undefined __fastcall FUN_0040960e(undefined4 param_1, undefined4 param_2)
 * Address ranges: 0040960e-00409634
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0040960e(undefined4 param_1,undefined4 param_2)

{
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  
  (*(code *)PTR_FUN_0040ef88)(param_2,param_1);
  FUN_00408533(extraout_ECX,extraout_EDX);
  if (DAT_004104e0 == 0) {
    FUN_00408984();
  }
                    /* WARNING: Subroutine does not return */
  ExitThread(0);
}

