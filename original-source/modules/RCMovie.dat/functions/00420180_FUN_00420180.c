/*
 * FUN_00420180 at 00420180
 * undefined4 __cdecl FUN_00420180(PEXCEPTION_RECORD param_1, PVOID param_2, undefined4 param_3)
 * Address ranges: 00420180-004201ec;004201f0-004201f4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_00420180(PEXCEPTION_RECORD param_1,PVOID param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if ((param_1->ExceptionFlags & 0x66) != 0) {
    *(undefined4 *)((int)param_2 + 0x24) = 1;
    return 1;
  }
  FUN_00423813(param_1,*(PVOID *)((int)param_2 + 0xc),param_3,0,*(int **)((int)param_2 + 8),
               *(int *)((int)param_2 + 0x10),*(PVOID *)((int)param_2 + 0x14),'\x01');
  if (*(int *)((int)param_2 + 0x24) == 0) {
    FUN_0041ffce(param_2,param_1);
  }
                    /* WARNING: Could not recover jumptable at 0x004201ea. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)((int)param_2 + 0x18))();
  return uVar1;
}

