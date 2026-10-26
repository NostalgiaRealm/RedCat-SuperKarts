/*
 * FUN_004af7a0 at 004af7a0
 * undefined FUN_004af7a0(void)
 * Address ranges: 004af7a0-004af812
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_004af7a0(int *param_1)

{
  int iVar1;
  
  if (param_1[3] == 1) {
    FUN_004afce0(s_T_ARRAY___deleting___16_16s___16_004de718,(int)param_1 + 0x2d,param_1 + 5,
                 param_1[1]);
    iVar1 = *param_1;
    if (iVar1 != 0) {
      FUN_004be99e(iVar1,0x1d8,*(undefined4 *)(iVar1 + -4),FUN_004af070);
      FUN_004bc150(iVar1 + -4);
    }
  }
  if (param_1[3] != 0) {
    FUN_004bc150(param_1[4]);
    param_1[3] = 0;
  }
  FUN_004afce0(s___done_deleting_T_ARRAY_004de6fc);
  return;
}

