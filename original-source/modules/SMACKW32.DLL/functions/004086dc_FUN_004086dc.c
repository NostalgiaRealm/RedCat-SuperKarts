/*
 * FUN_004086dc at 004086dc
 * undefined __fastcall FUN_004086dc(undefined4 param_1, undefined4 param_2)
 * Address ranges: 004086dc-00408707
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_004086dc(undefined4 param_1,undefined4 param_2)

{
  int extraout_EDX;
  
  (*(code *)PTR_FUN_0040ef78)(param_2);
  if ((0 < extraout_EDX) && (extraout_EDX < DAT_004104f4)) {
    *(undefined4 *)(DAT_004104f8 + extraout_EDX * 4) = 0;
  }
  (*(code *)PTR_FUN_0040ef7c)();
  return;
}

