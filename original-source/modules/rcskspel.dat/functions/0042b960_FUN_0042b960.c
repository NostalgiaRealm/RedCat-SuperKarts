/*
 * FUN_0042b960 at 0042b960
 * undefined FUN_0042b960(void)
 * Address ranges: 0042b960-0042baaa
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042b960(void)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  char *pcVar6;
  undefined4 *puVar7;
  undefined1 auStack_e8 [32];
  char acStack_c8 [200];
  
  FUN_004b1d60(s_Race_ini_004e96a4);
  DAT_00508610 = FUN_0042abe0();
  FUN_004afce0(s_JAB_num_of_opponents___d_004e96b0,DAT_00508610);
  if ((9 < DAT_00508610) || (DAT_00508610 < 0)) {
    FUN_004afee0(s__load_racer_info___s__d____Inval_004e96f0,
                 s_D__work_rcsk_Code_game_Gm_ini_cp_004e96cc,0x2c4,DAT_00508610,9);
  }
  FUN_004b1d60(s_Race_ini_004e972c);
  iVar5 = 0;
  if (0 < DAT_00508610) {
    puVar4 = &DAT_005081b8;
    do {
      FUN_004bea92(auStack_e8,&DAT_004e9738,iVar5);
      FUN_004b1f10(s_RACERS_004e973c,auStack_e8,acStack_c8,199);
      iVar3 = -1;
      pcVar6 = acStack_c8;
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
      if (iVar3 == -2) {
        FUN_004afee0(s__load_racer_info___s__d____No_va_004e9768,
                     s_D__work_rcsk_Code_game_Gm_ini_cp_004e9744,0x2e3,iVar5);
      }
      iVar3 = FUN_004b1f60(acStack_c8,0);
      if (iVar3 != 3) {
        FUN_004afee0(s__load_racer_info___s__d____Inval_004e97cc,
                     s_D__work_rcsk_Code_game_Gm_ini_cp_004e97a8,0x2ec,iVar5);
      }
      uVar2 = FUN_004b20c0(0);
      puVar4[-2] = uVar2;
      cVar1 = FUN_00417e90(iVar5);
      puVar7 = &DAT_0053be60;
      if (cVar1 == '\0') {
        puVar7 = puVar4;
      }
      uVar2 = FUN_004b20c0(1);
      *puVar7 = uVar2;
      uVar2 = FUN_004b20c0(2);
      puVar4[-1] = uVar2;
      iVar5 = iVar5 + 1;
      puVar4 = puVar4 + 0x1c;
    } while (iVar5 < DAT_00508610);
  }
  return;
}

