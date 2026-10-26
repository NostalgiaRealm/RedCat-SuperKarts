/*
 * FUN_004314a0 at 004314a0
 * undefined FUN_004314a0(void)
 * Address ranges: 004314a0-00431599
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined1 * FUN_004314a0(undefined1 *param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  undefined1 local_85;
  char local_80 [127];
  undefined1 local_1;
  
  FUN_004be8cb(local_80,0x7e,&DAT_004eb214,param_2);
  uVar3 = 0xffffffff;
  local_1 = 0;
  pcVar5 = local_80;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  *(undefined4 *)(param_1 + 4) = 0;
  uVar3 = ~uVar3 - 1;
  *param_1 = local_85;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  if (0xfffffffd < uVar3) {
    FUN_004bc15b();
  }
  iVar2 = *(int *)(param_1 + 4);
  if (((iVar2 == 0) || (cVar1 = *(char *)(iVar2 + -1), cVar1 == '\0')) || (cVar1 == -1)) {
    if (uVar3 == 0) {
      FUN_0040b4f0(1);
      return param_1;
    }
    if ((*(uint *)(param_1 + 0xc) < 0x20) && (uVar3 <= *(uint *)(param_1 + 0xc))) goto LAB_0043156c;
    FUN_0040b4f0(1);
  }
  else if (uVar3 == 0) {
    *(char *)(iVar2 + -1) = cVar1 + -1;
    FUN_0040b4f0(0);
    return param_1;
  }
  FUN_0040b720(uVar3);
LAB_0043156c:
  pcVar5 = local_80;
  pcVar6 = *(char **)(param_1 + 4);
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
  *(uint *)(param_1 + 8) = uVar3;
  *(undefined1 *)(*(int *)(param_1 + 4) + uVar3) = 0;
  return param_1;
}

