/*
 * FUN_00415d70 at 00415d70
 * undefined FUN_00415d70(void)
 * Address ranges: 00415d70-00415dc3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00415d70(void)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  puVar3 = &DAT_004e0298;
  do {
    uVar2 = FUN_004a6200(puVar3 + -4);
    *puVar3 = uVar2;
    puVar3 = puVar3 + 0x4b;
  } while ((int)puVar3 < 0x4e0d24);
  cVar1 = FUN_00415dd0();
  if (cVar1 == '\0') {
    FUN_004afce0(s__s__d____RCR_grid_triggers_not_f_004e0d84,
                 s_D__work_rcsk_Code_game_Car_main__004e0d60,0x1fc);
  }
  FUN_004319f0();
  FUN_00417640();
  FUN_00407490();
  return;
}

