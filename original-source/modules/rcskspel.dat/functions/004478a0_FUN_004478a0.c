/*
 * FUN_004478a0 at 004478a0
 * undefined FUN_004478a0(void)
 * Address ranges: 004478a0-004479b6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __thiscall FUN_004478a0(int param_1,uint param_2,uint param_3)

{
  undefined1 *puVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  
  if (*(uint *)(param_1 + 8) < param_2) {
    FUN_004bc243();
  }
  pcVar6 = *(char **)(param_1 + 4);
  if (((pcVar6 != (char *)0x0) && (cVar2 = pcVar6[-1], cVar2 != '\0')) && (cVar2 != -1)) {
    pcVar6[-1] = cVar2 + -1;
    uVar3 = 0xffffffff;
    *(undefined4 *)(param_1 + 4) = 0;
    *(undefined4 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0xc) = 0;
    pcVar7 = pcVar6;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar2 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar2 != '\0');
    uVar3 = ~uVar3 - 1;
    cVar2 = FUN_0040b600(uVar3,1);
    if (cVar2 != '\0') {
      pcVar7 = *(char **)(param_1 + 4);
      for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined4 *)pcVar7 = *(undefined4 *)pcVar6;
        pcVar6 = pcVar6 + 4;
        pcVar7 = pcVar7 + 4;
      }
      for (uVar4 = uVar3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar7 = *pcVar6;
        pcVar6 = pcVar6 + 1;
        pcVar7 = pcVar7 + 1;
      }
      FUN_0040b5e0(uVar3);
    }
  }
  uVar3 = *(int *)(param_1 + 8) - param_2;
  if (uVar3 < param_3) {
    param_3 = uVar3;
  }
  if (param_3 == 0) {
    return param_1;
  }
  iVar5 = *(int *)(param_1 + 4) + param_2;
  FUN_004bef90(iVar5,iVar5 + param_3,uVar3 - param_3);
  param_3 = *(int *)(param_1 + 8) - param_3;
  if (0xfffffffd < param_3) {
    FUN_004bc15b();
  }
  puVar1 = *(undefined1 **)(param_1 + 4);
  if (((puVar1 == (undefined1 *)0x0) || (cVar2 = puVar1[-1], cVar2 == '\0')) || (cVar2 == -1)) {
    if (param_3 == 0) {
      if (puVar1 == (undefined1 *)0x0) {
        return param_1;
      }
      *(undefined4 *)(param_1 + 8) = 0;
      *puVar1 = 0;
      return param_1;
    }
    if (param_3 <= *(uint *)(param_1 + 0xc)) goto LAB_004479a4;
  }
  else if (param_3 == 0) {
    puVar1[-1] = cVar2 + -1;
    FUN_0040b4f0(0);
    return param_1;
  }
  FUN_0040b720(param_3);
LAB_004479a4:
  *(uint *)(param_1 + 8) = param_3;
  *(undefined1 *)(param_3 + *(int *)(param_1 + 4)) = 0;
  return param_1;
}

