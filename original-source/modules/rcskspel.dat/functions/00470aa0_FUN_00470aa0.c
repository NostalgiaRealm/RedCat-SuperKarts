/*
 * FUN_00470aa0 at 00470aa0
 * undefined FUN_00470aa0(void)
 * Address ranges: 00470aa0-00470c06
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Removing unreachable block (ram,0x00470b95) */
/* WARNING: Removing unreachable block (ram,0x00470b9c) */
/* WARNING: Removing unreachable block (ram,0x00470ba7) */
/* WARNING: Removing unreachable block (ram,0x00470ba0) */
/* WARNING: Removing unreachable block (ram,0x00470bc5) */
/* WARNING: Removing unreachable block (ram,0x00470bcc) */
/* WARNING: Removing unreachable block (ram,0x00470bd0) */
/* WARNING: Removing unreachable block (ram,0x00470be9) */

undefined4 FUN_00470aa0(void)

{
  char cVar1;
  char extraout_AL;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 uVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d0844;
  pvStack_c = ExceptionList;
  uVar3 = 0xffffffff;
  pcVar5 = s_game_ini_004f65f0;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  ExceptionList = &pvStack_c;
  FUN_0040b540(s_game_ini_004f65f0,~uVar3 - 1);
  local_4 = 0;
  FUN_004b1d60(&DAT_004d2404);
  FUN_00470860();
  uVar3 = 0xffffffff;
  pcVar5 = &DAT_004f65fc;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  FUN_0040b540(&DAT_004f65fc,~uVar3 - 1);
  local_4 = CONCAT31(local_4._1_3_,1);
  FUN_004b1d60(&DAT_004d2404);
  iVar4 = 0;
  do {
    FUN_004710e0(iVar4);
    uVar2 = extraout_var;
    if (extraout_AL == '\0') {
      FUN_004afee0(s__s__d____PerformLoad__d__failed_004f6638,
                   s_D__work_rcsk_Code_game_rcr_stop__004f6608,0x11c,iVar4);
      uVar2 = extraout_var_00;
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < 0xc);
  ExceptionList = pvStack_c;
  return CONCAT31(uVar2,1);
}

