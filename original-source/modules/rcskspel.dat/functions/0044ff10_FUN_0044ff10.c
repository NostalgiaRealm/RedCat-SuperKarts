/*
 * FUN_0044ff10 at 0044ff10
 * undefined FUN_0044ff10(void)
 * Address ranges: 0044ff10-0044ff7d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_0044ff10(int param_1,int param_2)

{
  undefined4 uVar1;
  
  FUN_00450440();
  if (*(int *)(param_1 + 4) == param_2) {
    return;
  }
  if (param_2 == 1) {
    if (*(int *)(param_1 + 4) == 2) {
      DAT_00543d20 = DAT_00543d20 + -1;
    }
    uVar1 = 0;
  }
  else {
    if (param_2 != 2) {
      FUN_004afee0(s_Unreachable_code_004f1070);
      goto LAB_0044ff60;
    }
    uVar1 = 1;
    DAT_00543d20 = DAT_00543d20 + 1;
  }
  FUN_004503e0(uVar1);
LAB_0044ff60:
  if (DAT_00543d20 < 0) {
    FUN_004afee0(s_Active_bonus_count_<_0_004f1084);
  }
  *(int *)(param_1 + 4) = param_2;
  return;
}

