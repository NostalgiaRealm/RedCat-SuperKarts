/*
 * FUN_00412bf0 at 00412bf0
 * undefined FUN_00412bf0(void)
 * Address ranges: 00412bf0-00412c4c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00412bf0(undefined4 param_1,int param_2)

{
  int iVar1;
  
  if (DAT_00505b44 == 0) {
    FUN_004afee0(s__s___d__Array_of_active_cops_not_004e0104,
                 s_D__work_rcsk_Code_game_Car_cops__004e00e0,0x86);
  }
  if (param_2 == 0) {
    FUN_00412bb0(param_1);
  }
  else {
    iVar1 = FUN_00412bb0(param_1);
    if (iVar1 == -1) {
      iVar1 = FUN_00412b70();
      if (iVar1 != -1) {
        (&DAT_00505af0)[iVar1] = param_1;
        return;
      }
    }
  }
  return;
}

