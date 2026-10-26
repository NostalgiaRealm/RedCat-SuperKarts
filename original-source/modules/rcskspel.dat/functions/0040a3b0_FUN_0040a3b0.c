/*
 * FUN_0040a3b0 at 0040a3b0
 * undefined FUN_0040a3b0(void)
 * Address ranges: 0040a3b0-0040a4c1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0040a3b0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = -1;
  iVar5 = param_1 * 0x11c;
  *(undefined4 *)(&DAT_00503f04 + iVar5) = 0;
  FUN_00412c50((&DAT_00503ef0)[param_1 * 0x47],0);
  if (*(int *)(&DAT_00503ef8 + iVar5) == DAT_0053be28) {
    iVar2 = DAT_00508610;
    if (DAT_0053b9c0 == 0) {
      FUN_0042f740(8);
      iVar2 = DAT_00508610;
    }
    goto LAB_0040a408;
  }
  iVar2 = 0;
  if (DAT_00508610 < 1) {
LAB_0040a48d:
    FUN_004afee0(s_An_illegal_racer_was_arrested_in_004deda8,
                 s_D__work_rcsk_Code_game_ai_path_c_004ded84,0x4c9);
  }
  else {
    piVar3 = &DAT_00503ef0;
    do {
      if (*piVar3 == *(int *)(&DAT_00503ef8 + iVar5)) {
        iVar4 = iVar2;
      }
      iVar2 = iVar2 + 1;
      piVar3 = piVar3 + 0x47;
    } while (iVar2 < DAT_00508610);
    if (iVar4 == -1) goto LAB_0040a48d;
  }
  iVar2 = DAT_00508610;
  (&DAT_00503ef4)[iVar4 * 0x47] = 7;
LAB_0040a408:
  if (iVar2 < 0xf) {
    puVar1 = &DAT_00503ef4 + iVar2 * 0x47;
    do {
      if (puVar1[1] == *(int *)(&DAT_00503ef8 + iVar5)) {
        *puVar1 = 6;
      }
      puVar1 = puVar1 + 0x47;
    } while ((int)puVar1 < 0x504f98);
  }
  FUN_00413330((&DAT_00503ef0)[param_1 * 0x47]);
  FUN_004130e0((&DAT_00503ef0)[param_1 * 0x47]);
  FUN_00412fd0((&DAT_00503ef0)[param_1 * 0x47]);
  return;
}

