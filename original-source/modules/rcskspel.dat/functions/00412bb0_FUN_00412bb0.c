/*
 * FUN_00412bb0 at 00412bb0
 * undefined FUN_00412bb0(void)
 * Address ranges: 00412bb0-00412beb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00412bb0(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (DAT_00505b44 == 0) {
    FUN_004afee0(s__s___d__Array_of_active_cops_not_004e00b0,
                 s_D__work_rcsk_Code_game_Car_cops__004e008c,0x65);
  }
  iVar1 = 0;
  piVar2 = &DAT_00505af0;
  do {
    if (*piVar2 == param_1) {
      return iVar1;
    }
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + 1;
  } while ((int)piVar2 < 0x505b40);
  return -1;
}

