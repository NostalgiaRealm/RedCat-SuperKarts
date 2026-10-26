/*
 * FUN_0046f5f0 at 0046f5f0
 * undefined FUN_0046f5f0(void)
 * Address ranges: 0046f5f0-0046f6f7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined1 * FUN_0046f5f0(undefined1 *param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  undefined4 local_14;
  undefined4 local_10;
  char local_c [11];
  undefined1 local_1;
  
  local_10 = 0;
  FUN_0046f700(param_2,&local_10,&local_14,&param_2);
  FUN_004be8cb(local_c,0xb,s__02d__02d__02d_004f6074,local_10,local_14,param_2);
  uVar3 = 0xffffffff;
  local_1 = 0;
  pcVar5 = local_c;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  *(undefined4 *)(param_1 + 4) = 0;
  uVar3 = ~uVar3 - 1;
  *param_1 = (undefined1)param_2;
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
    if ((*(uint *)(param_1 + 0xc) < 0x20) && (uVar3 <= *(uint *)(param_1 + 0xc))) goto LAB_0046f6cd;
    FUN_0040b4f0(1);
  }
  else if (uVar3 == 0) {
    *(char *)(iVar2 + -1) = cVar1 + -1;
    FUN_0040b4f0(0);
    return param_1;
  }
  FUN_0040b720(uVar3);
LAB_0046f6cd:
  pcVar5 = local_c;
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

