/*
 * FUN_004c4714 at 004c4714
 * undefined FUN_004c4714(void)
 * Address ranges: 004c4714-004c47c1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined1 * FUN_004c4714(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  undefined1 *puVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  
  iVar1 = param_1[6];
  iVar2 = param_1[4];
  pcVar3 = &DAT_006b6788;
  iVar7 = 0;
  do {
    pcVar4 = pcVar3;
    iVar8 = iVar7 + 1;
    *pcVar4 = "SunMonTueWedThuFriSat"[iVar1 * 3 + iVar7];
    (&DAT_006b678c)[iVar7] = "SunMonTueWedThuFriSat"[iVar8 + iVar2 * 3 + 0x17];
    pcVar3 = pcVar4 + 1;
    iVar7 = iVar8;
  } while (iVar8 < 3);
  pcVar4[1] = ' ';
  pcVar4[5] = ' ';
  puVar5 = (undefined1 *)FUN_004c47c2(pcVar4 + 6,param_1[3]);
  *puVar5 = 0x20;
  puVar5 = (undefined1 *)FUN_004c47c2(puVar5 + 1,param_1[2]);
  *puVar5 = 0x3a;
  puVar5 = (undefined1 *)FUN_004c47c2(puVar5 + 1,param_1[1]);
  *puVar5 = 0x3a;
  puVar5 = (undefined1 *)FUN_004c47c2(puVar5 + 1,*param_1);
  *puVar5 = 0x20;
  uVar6 = FUN_004c47c2(puVar5 + 1,(int)param_1[5] / 100 + 0x13);
  puVar5 = (undefined1 *)FUN_004c47c2(uVar6,(int)param_1[5] % 100);
  *puVar5 = 10;
  puVar5[1] = 0;
  return &DAT_006b6788;
}

