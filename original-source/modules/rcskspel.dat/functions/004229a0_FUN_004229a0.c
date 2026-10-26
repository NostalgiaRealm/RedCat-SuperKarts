/*
 * FUN_004229a0 at 004229a0
 * undefined FUN_004229a0(void)
 * Address ranges: 004229a0-00422cd4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004229a0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  DAT_00509120 = (uint)(DAT_0053b9b0 == 0);
  iVar3 = 0;
  do {
    iVar1 = FUN_00422930(DAT_00509120);
    iVar2 = FUN_00422900(iVar3);
    iVar1 = FUN_004b7470(s_lo_fnt3_fnt_004e4388 + (iVar1 * 0x17 + iVar2) * 0x94);
    if (iVar1 == 1000) {
      FUN_004afee0(s__s___d___Cannot_open_font_file__I_004e5ed8,
                   s_D__work_rcsk_Code_game_gfx_asci__004e5eb4,0xab,iVar3);
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x17);
  iVar3 = FUN_00422930(DAT_00509120,0xfffffffc,0xfffffffc);
  iVar1 = FUN_00422900(2);
  FUN_00422960(s_lo_fnt3_fnt_004e4388 + (iVar3 * 0x17 + iVar1) * 0x94);
  iVar3 = FUN_00422930(DAT_00509120,0,0xfffffffe);
  iVar1 = FUN_00422900(6);
  FUN_00422960(s_lo_fnt3_fnt_004e4388 + (iVar3 * 0x17 + iVar1) * 0x94);
  iVar3 = FUN_00422930(DAT_00509120,0xfffffffd,0xfffffffc);
  iVar1 = FUN_00422900(3);
  FUN_00422960(s_lo_fnt3_fnt_004e4388 + (iVar3 * 0x17 + iVar1) * 0x94);
  iVar3 = FUN_00422930(DAT_00509120,0xfffffffe,0xfffffffc);
  iVar1 = FUN_00422900(5);
  FUN_00422960(s_lo_fnt3_fnt_004e4388 + (iVar3 * 0x17 + iVar1) * 0x94);
  iVar3 = FUN_00422930(DAT_00509120,0,0xfffffffe);
  iVar1 = FUN_00422900(10);
  FUN_00422960(s_lo_fnt3_fnt_004e4388 + (iVar3 * 0x17 + iVar1) * 0x94);
  iVar3 = FUN_00422930(DAT_00509120,0xffffffff,0xfffffffc);
  iVar1 = FUN_00422900(0xb);
  FUN_00422960(s_lo_fnt3_fnt_004e4388 + (iVar3 * 0x17 + iVar1) * 0x94);
  iVar3 = FUN_00422930(DAT_00509120,0,0xfffffffd);
  iVar1 = FUN_00422900(0xc);
  FUN_00422960(s_lo_fnt3_fnt_004e4388 + (iVar3 * 0x17 + iVar1) * 0x94);
  iVar3 = FUN_00422930(DAT_00509120,0,0xfffffffe);
  iVar1 = FUN_00422900(0xd);
  FUN_00422960(s_lo_fnt3_fnt_004e4388 + (iVar3 * 0x17 + iVar1) * 0x94);
  iVar3 = FUN_00422930(DAT_00509120,0xfffffffe,0xfffffff8);
  iVar1 = FUN_00422900(0);
  FUN_00422960(s_lo_fnt3_fnt_004e4388 + (iVar3 * 0x17 + iVar1) * 0x94);
  iVar3 = FUN_00422930(DAT_00509120,0xfffffffb,0xfffffff2);
  iVar1 = FUN_00422900(0xe);
  FUN_00422960(s_lo_fnt3_fnt_004e4388 + (iVar3 * 0x17 + iVar1) * 0x94);
  iVar3 = FUN_00422930(DAT_00509120,0xffffffff,0xfffffffe);
  iVar1 = FUN_00422900(0xf);
  FUN_00422960(s_lo_fnt3_fnt_004e4388 + (iVar3 * 0x17 + iVar1) * 0x94);
  iVar3 = FUN_00422930(DAT_00509120,0,0);
  iVar1 = FUN_00422900(0x10);
  FUN_00422960(s_lo_fnt3_fnt_004e4388 + (iVar3 * 0x17 + iVar1) * 0x94);
  if (DAT_0053b9ac == 0) {
    FUN_004b5d80(0);
  }
  return;
}

