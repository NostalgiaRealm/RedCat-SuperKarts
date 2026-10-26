/*
 * FUN_0040b540 at 0040b540
 * undefined FUN_0040b540(void)
 * Address ranges: 0040b540-0040b5db
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __thiscall FUN_0040b540(int param_1,undefined4 *param_2,uint param_3)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  
  if (0xfffffffd < param_3) {
    FUN_004bc15b();
  }
  iVar2 = *(int *)(param_1 + 4);
  if (((iVar2 == 0) || (cVar1 = *(char *)(iVar2 + -1), cVar1 == '\0')) || (cVar1 == -1)) {
    if (param_3 == 0) {
      FUN_0040b4f0(1);
      return param_1;
    }
    if ((*(uint *)(param_1 + 0xc) < 0x20) && (param_3 <= *(uint *)(param_1 + 0xc)))
    goto LAB_0040b5b0;
    FUN_0040b4f0(1);
  }
  else if (param_3 == 0) {
    *(char *)(iVar2 + -1) = cVar1 + -1;
    *(undefined4 *)(param_1 + 4) = 0;
    *(undefined4 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0xc) = 0;
    return param_1;
  }
  FUN_0040b720(param_3);
LAB_0040b5b0:
  puVar4 = *(undefined4 **)(param_1 + 4);
  for (uVar3 = param_3 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *puVar4 = *param_2;
    param_2 = param_2 + 1;
    puVar4 = puVar4 + 1;
  }
  for (uVar3 = param_3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined1 *)puVar4 = *(undefined1 *)param_2;
    param_2 = (undefined4 *)((int)param_2 + 1);
    puVar4 = (undefined4 *)((int)puVar4 + 1);
  }
  *(uint *)(param_1 + 8) = param_3;
  *(undefined1 *)(param_3 + *(int *)(param_1 + 4)) = 0;
  return param_1;
}

