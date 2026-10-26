/*
 * FUN_00412b70 at 00412b70
 * undefined FUN_00412b70(void)
 * Address ranges: 00412b70-00412ba8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00412b70(void)

{
  int iVar1;
  int *piVar2;
  
  if (DAT_00505b44 == 0) {
    FUN_004afee0(s__s___d__Array_of_active_cops_not_004e005c,
                 s_D__work_rcsk_Code_game_Car_cops__004e0038,0x45);
  }
  iVar1 = 0;
  piVar2 = &DAT_00505af0;
  do {
    if (*piVar2 == -1) {
      return iVar1;
    }
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + 1;
  } while ((int)piVar2 < 0x505b40);
  return -1;
}

