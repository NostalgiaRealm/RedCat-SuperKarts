/*
 * FUN_00429220 at 00429220
 * undefined FUN_00429220(void)
 * Address ranges: 00429220-004293f0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00429220(void)

{
  undefined4 uVar1;
  undefined *puVar2;
  
  uVar1 = 0;
  FUN_004afce0(s_set_xvga_vars_allowmodex_004e84f0);
  FUN_004b00c0(1,0x40,1);
  FUN_004afce0(s_set_xvga_vars_RESOLUTION_004e850c);
  switch(DAT_004e7b70) {
  case 0:
    FUN_004b00c0(2,0,0);
    FUN_004b00c0(0,0,0);
    return 0;
  case 1:
    FUN_004b00c0(2,0,0);
    FUN_004b00c0(0,3,0);
    return 0;
  case 2:
    FUN_004b00c0(2,0,0);
    FUN_004b00c0(0,9,0);
    return 1;
  case 3:
    FUN_004b00c0(2,1,0);
    FUN_004b00c0(0,9,0);
    uVar1 = 1;
    DAT_004e7bec = 1;
    if (DAT_004e7bfc != 0) {
      FUN_004b00c0(2,4,0);
      FUN_004b8d50(100);
      puVar2 = &DAT_0053a258;
LAB_004293ba:
      FUN_004b8dd0(&DAT_004e7c00,&DAT_004e7c10,puVar2);
      return 1;
    }
    break;
  case 4:
    FUN_004b00c0(2,1,0);
    FUN_004b00c0(0,10,0);
    uVar1 = 1;
    DAT_004e7bec = 1;
    if (DAT_004e7bfc != 0) {
      FUN_004b00c0(2,4,0);
      FUN_004b8d50(100);
      puVar2 = &DAT_0053a25c;
      goto LAB_004293ba;
    }
    break;
  case 5:
    FUN_004b00c0(2,0,0);
    FUN_004b00c0(0,6,0);
    FUN_004ac3b0(1);
    return 1;
  case 6:
    FUN_004b00c0(2,1,0);
    FUN_004b00c0(0,0xb,0);
    uVar1 = 1;
    DAT_004e7bec = 1;
    if (DAT_004e7bfc != 0) {
      FUN_004b00c0(2,4,0);
      FUN_004b8d50(100);
      puVar2 = &DAT_0053a260;
      goto LAB_004293ba;
    }
    break;
  default:
    FUN_004afee0(s__s__d____Function___s___Illegal_r_004e854c,
                 s_D__work_rcsk_Code_game_gm_body_c_004e8528,0x1ca,s_skelet_set_resolutie_004e84d8,
                 DAT_004e7b70);
  }
  return uVar1;
}

