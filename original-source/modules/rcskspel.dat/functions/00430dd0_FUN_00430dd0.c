/*
 * FUN_00430dd0 at 00430dd0
 * undefined FUN_00430dd0(void)
 * Address ranges: 00430dd0-00430e0a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00430dd0(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  
  iVar1 = param_2;
  if (param_3 < param_2) {
    iVar1 = param_3;
    param_3 = param_2;
  }
  if ((param_1 < iVar1) || (param_3 < param_1)) {
    FUN_004afee0(s___s___Illegal_value__d_for_range_004eb130,param_4,param_1,iVar1,param_3,param_5);
  }
  return;
}

