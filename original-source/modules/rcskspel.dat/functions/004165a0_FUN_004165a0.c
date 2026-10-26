/*
 * FUN_004165a0 at 004165a0
 * undefined FUN_004165a0(void)
 * Address ranges: 004165a0-004165c8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_004165a0(void)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = &DAT_00507388;
  do {
    if (*piVar2 == 0) {
      return iVar1;
    }
    piVar2 = piVar2 + 3;
    iVar1 = iVar1 + 1;
  } while ((int)piVar2 < 0x507f40);
  FUN_004afee0(s__get_free_car_list_entry__no_mor_004e0fc4);
  return -1;
}

