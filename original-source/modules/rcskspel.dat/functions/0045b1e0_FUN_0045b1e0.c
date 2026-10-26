/*
 * FUN_0045b1e0 at 0045b1e0
 * undefined FUN_0045b1e0(void)
 * Address ranges: 0045b1e0-0045b2a4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __thiscall FUN_0045b1e0(int param_1,uint param_2,undefined1 param_3)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  
  if (-*(int *)(param_1 + 8) - 1U <= param_2) {
    FUN_004bc15b();
  }
  if (param_2 == 0) {
    return param_1;
  }
  uVar4 = param_2 + *(int *)(param_1 + 8);
  if (0xfffffffd < uVar4) {
    FUN_004bc15b();
  }
  iVar2 = *(int *)(param_1 + 4);
  if (((iVar2 == 0) || (cVar1 = *(char *)(iVar2 + -1), cVar1 == '\0')) || (cVar1 == -1)) {
    if (uVar4 == 0) {
      if (iVar2 == 0) {
        return param_1;
      }
      FUN_0040b5e0(0);
      return param_1;
    }
    if (uVar4 <= *(uint *)(param_1 + 0xc)) goto LAB_0045b269;
  }
  else if (uVar4 == 0) {
    *(char *)(iVar2 + -1) = cVar1 + -1;
    *(undefined4 *)(param_1 + 4) = 0;
    *(undefined4 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0xc) = 0;
    return param_1;
  }
  FUN_0040b720(uVar4);
LAB_0045b269:
  puVar5 = (undefined4 *)(*(int *)(param_1 + 4) + *(int *)(param_1 + 8));
  for (uVar3 = param_2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *puVar5 = CONCAT22(CONCAT11(param_3,param_3),CONCAT11(param_3,param_3));
    puVar5 = puVar5 + 1;
  }
  for (param_2 = param_2 & 3; param_2 != 0; param_2 = param_2 - 1) {
    *(undefined1 *)puVar5 = param_3;
    puVar5 = (undefined4 *)((int)puVar5 + 1);
  }
  *(uint *)(param_1 + 8) = uVar4;
  *(undefined1 *)(*(int *)(param_1 + 4) + uVar4) = 0;
  return param_1;
}

