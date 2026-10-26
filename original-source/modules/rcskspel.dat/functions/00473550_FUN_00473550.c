/*
 * FUN_00473550 at 00473550
 * undefined FUN_00473550(void)
 * Address ranges: 00473550-00473693
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __fastcall FUN_00473550(char *param_1)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  
  if (*param_1 != '\0') {
    FUN_004afce0(s__s__d____Already_checked__succes_004f7354,
                 s_D__work_rcsk_Code_game_ScreenSwi_004f732c,0x6e);
    return 0;
  }
  puVar2 = DAT_00544dcc;
  if (DAT_00544dcc == (undefined1 *)0x0) {
    puVar2 = &DAT_004d2404;
  }
  FUN_004b1d60(puVar2);
  puVar2 = DAT_00544dcc;
  if (DAT_00544dcc == (undefined1 *)0x0) {
    puVar2 = &DAT_004d2404;
  }
  FUN_004afce0(s__s__d____Reading_ini_file___s__004f73a4,s_D__work_rcsk_Code_game_ScreenSwi_004f737c
               ,0x74,puVar2);
  puVar2 = DAT_00544dac;
  if (DAT_00544dac == (undefined1 *)0x0) {
    puVar2 = &DAT_004d2404;
  }
  puVar3 = DAT_00544dbc;
  if (DAT_00544dbc == (undefined1 *)0x0) {
    puVar3 = &DAT_004d2404;
  }
  iVar4 = FUN_004b1ed0(puVar3,puVar2);
  iVar1 = iVar4 + -1;
  FUN_004afce0(s__s__d____Read__d__reference_coun_004f73ec,
               s_D__work_rcsk_Code_game_ScreenSwi_004f73c4,0x7e,iVar4,iVar1);
  if (iVar1 < 1) {
    FUN_004afce0(s__s__d____Writing_reference_count_004f748c,
                 s_D__work_rcsk_Code_game_ScreenSwi_004f7464,0x8d);
    puVar2 = DAT_00544dac;
    if (DAT_00544dac == (undefined1 *)0x0) {
      puVar2 = &DAT_004d2404;
    }
    puVar3 = DAT_00544dbc;
    if (DAT_00544dbc == (undefined1 *)0x0) {
      puVar3 = &DAT_004d2404;
    }
    FUN_004b1e70(puVar3,puVar2,0);
    *param_1 = '\x01';
  }
  else {
    FUN_004afce0(s__s__d____Writing_reference_count_004f743c,
                 s_D__work_rcsk_Code_game_ScreenSwi_004f7414,0x84);
    puVar2 = DAT_00544dac;
    if (DAT_00544dac == (undefined1 *)0x0) {
      puVar2 = &DAT_004d2404;
    }
    puVar3 = DAT_00544dbc;
    if (DAT_00544dbc == (undefined1 *)0x0) {
      puVar3 = &DAT_004d2404;
    }
    FUN_004b1e70(puVar3,puVar2,iVar1);
    *param_1 = '\0';
  }
  FUN_004afce0(s__s__d____Returning_previous_coun_004f74dc,
               s_D__work_rcsk_Code_game_ScreenSwi_004f74b4,0x97,iVar4);
  return iVar4;
}

