/*
 * FUN_004079ff at 004079ff
 * undefined __fastcall FUN_004079ff(undefined4 param_1, undefined4 param_2)
 * Address ranges: 004079ff-00407a1d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_004079ff(undefined4 param_1,undefined4 param_2)

{
  UINT in_EAX;
  undefined4 extraout_ECX;
  
  FUN_00408533(param_1,param_2);
  FUN_00408c11(extraout_ECX,0xff);
  (*(code *)PTR_FUN_0040ef80)();
                    /* WARNING: Subroutine does not return */
  ExitProcess(in_EAX);
}

