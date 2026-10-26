/*
 * FUN_00477f60 at 00477f60
 * undefined FUN_00477f60(void)
 * Address ranges: 00477f60-00477fbb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00477f60(undefined4 *param_1)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  
  puVar1 = DAT_00544e2c;
  if (DAT_00544e2c == (undefined1 *)0x0) {
    puVar1 = &DAT_004d2404;
  }
  FUN_004b1d60(puVar1);
  puVar1 = DAT_00544e0c;
  if (DAT_00544e0c == (undefined1 *)0x0) {
    puVar1 = &DAT_004d2404;
  }
  puVar2 = DAT_00544e1c;
  if (DAT_00544e1c == (undefined1 *)0x0) {
    puVar2 = &DAT_004d2404;
  }
  uVar3 = FUN_004b1ed0(puVar2,puVar1);
  *param_1 = uVar3;
  FUN_004afce0(s__s__d____Startup_mode____d_004f7dbc,s_D__work_rcsk_Code_game_GameScree_004f7d8c,
               0x45,uVar3);
  param_1[1] = *param_1;
  return;
}

