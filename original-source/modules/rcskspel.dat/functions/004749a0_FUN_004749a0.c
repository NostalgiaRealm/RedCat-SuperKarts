/*
 * FUN_004749a0 at 004749a0
 * undefined FUN_004749a0(void)
 * Address ranges: 004749a0-00474b12
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_004749a0(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  undefined1 local_1c [4];
  int local_18;
  undefined4 local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_004d0976;
  local_c = ExceptionList;
  local_1c[0] = (undefined1)param_2;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_4 = 0;
  ExceptionList = &local_c;
  FUN_00412870(local_1c,0,0xffffffff);
  local_4 = 0xffffffff;
  if (local_18 != 0) {
    cVar1 = *(char *)(local_18 + -1);
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_004bc150((char *)(local_18 + -1));
    }
    else {
      *(char *)(local_18 + -1) = cVar1 + -1;
    }
  }
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  if (*(char *)(param_1 + 4) == '\0') {
    ExceptionList = local_c;
    return;
  }
  pcVar5 = *(char **)(param_1 + 0x2c);
  if (pcVar5 == (char *)0x0) {
    ExceptionList = local_c;
    return;
  }
  if (*pcVar5 == '\0') {
    ExceptionList = local_c;
    return;
  }
  uVar3 = 0xffffffff;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  pcVar5 = (char *)(*(int *)(param_1 + 0x2c) + ~uVar3);
  uVar3 = 0xffffffff;
  *(char **)(param_1 + 0x2c) = pcVar5;
  pcVar6 = pcVar5;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3 - 1;
  if (0xfffffffd < uVar3) {
    FUN_004bc15b();
  }
  iVar2 = *(int *)(param_2 + 4);
  if (((iVar2 == 0) || (cVar1 = *(char *)(iVar2 + -1), cVar1 == '\0')) || (cVar1 == -1)) {
    if (uVar3 == 0) {
      FUN_0040b4f0(1);
      goto LAB_00474aed;
    }
    if ((0x1f < *(uint *)(param_2 + 0xc)) || (*(uint *)(param_2 + 0xc) < uVar3)) {
      FUN_0040b4f0(1);
      goto LAB_00474ac0;
    }
  }
  else {
    if (uVar3 == 0) {
      *(char *)(iVar2 + -1) = cVar1 + -1;
      FUN_0040b4f0(0);
      goto LAB_00474aed;
    }
LAB_00474ac0:
    FUN_0040b720(uVar3);
  }
  pcVar6 = *(char **)(param_2 + 4);
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar6 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    pcVar6 = pcVar6 + 4;
  }
  for (uVar4 = uVar3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar6 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    pcVar6 = pcVar6 + 1;
  }
  *(uint *)(param_2 + 8) = uVar3;
  *(undefined1 *)(*(int *)(param_2 + 4) + uVar3) = 0;
LAB_00474aed:
  FUN_004afce0(s___Next_string__s_004f78f8,*(undefined4 *)(param_1 + 0x2c));
  ExceptionList = local_c;
  return;
}

