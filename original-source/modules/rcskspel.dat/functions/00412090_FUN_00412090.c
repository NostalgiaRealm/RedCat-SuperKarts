/*
 * FUN_00412090 at 00412090
 * undefined FUN_00412090(void)
 * Address ranges: 00412090-0041227e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Removing unreachable block (ram,0x0041223e) */
/* WARNING: Removing unreachable block (ram,0x00412248) */
/* WARNING: Removing unreachable block (ram,0x0041224c) */
/* WARNING: Removing unreachable block (ram,0x00412263) */

void FUN_00412090(undefined4 param_1,int *param_2)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  undefined1 *puVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  float10 fVar9;
  undefined4 unaff_retaddr;
  undefined4 uVar10;
  int local_1c [3];
  void *local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004cce5e;
  pvStack_c = ExceptionList;
  local_1c[0] = CONCAT31(local_1c[0]._1_3_,(undefined1)param_1);
  uVar4 = 0xffffffff;
  ExceptionList = &pvStack_c;
  param_2[0x1c] = 1;
  pcVar7 = &DAT_004e0008;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar1 != '\0');
  local_1c[1] = 0;
  local_1c[2] = 0;
  local_10 = (void *)0x0;
  FUN_0040b540(&DAT_004e0008,~uVar4 - 1);
  local_4 = 0;
  puVar2 = (undefined4 *)FUN_0044a700(param_1);
  (**(code **)*puVar2)(local_1c);
  puStack_8 = (undefined1 *)0xffffffff;
  if (local_1c[0] != 0) {
    cVar1 = *(char *)(local_1c[0] + -1);
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_004bc150((char *)(local_1c[0] + -1));
    }
    else {
      *(char *)(local_1c[0] + -1) = cVar1 + -1;
    }
  }
  iVar6 = *param_2 * 0xd0 + DAT_0067ee20;
  iVar3 = FUN_0040c980();
  fVar9 = (float10)FUN_00456a10(4,param_2);
  *(float *)(iVar6 + 0xa4) = (float)(fVar9 * (float10)*(float *)(iVar3 + 8));
  FUN_00411a90(unaff_retaddr,param_2);
  fVar9 = (float10)FUN_00456aa0(4,param_2);
  param_2[0x26] = (int)(float)fVar9;
  FUN_0040c960(4);
  cVar1 = FUN_0040c9b0();
  if (cVar1 != '\0') {
    FUN_004afce0(s___Attacked_by_redcat_with_gum_004e000c);
  }
  cVar1 = FUN_00417e90(unaff_retaddr);
  if (cVar1 != '\0') {
    uVar4 = 0xffffffff;
    pcVar7 = s_HIT_BY_GUM_004e002c;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    puVar5 = (undefined1 *)(~uVar4 - 1);
    cVar1 = FUN_0040b600(puVar5,1);
    if (cVar1 != '\0') {
      pcVar7 = s_HIT_BY_GUM_004e002c;
      pcVar8 = (char *)0x0;
      for (uVar4 = (uint)puVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
        pcVar7 = pcVar7 + 4;
        pcVar8 = pcVar8 + 4;
      }
      for (uVar4 = (uint)puVar5 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar8 = *pcVar7;
        pcVar7 = pcVar7 + 1;
        pcVar8 = pcVar8 + 1;
      }
      *puVar5 = 0;
    }
    puVar5 = &stack0xffffffd0;
    puStack_8 = (undefined1 *)0x1;
    uVar10 = 10;
    FUN_004371f0(10,puVar5);
    FUN_00437b40(uVar10,puVar5);
  }
  ExceptionList = local_10;
  return;
}

