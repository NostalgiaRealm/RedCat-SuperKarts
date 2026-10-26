/*
 * FUN_0044da90 at 0044da90
 * undefined FUN_0044da90(void)
 * Address ranges: 0044da90-0044db05
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0044da90(int param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  
  if (((*(int *)(param_1 + 4) == 0) ||
      (cVar1 = *(char *)(*(int *)(param_1 + 4) + -1), cVar1 == '\0')) || (cVar1 == -1))
  goto LAB_0044daf8;
  uVar2 = *(uint *)(param_1 + 8);
  if (0xfffffffd < uVar2) {
    FUN_004bc15b();
  }
  iVar3 = *(int *)(param_1 + 4);
  if (((iVar3 == 0) || (cVar1 = *(char *)(iVar3 + -1), cVar1 == '\0')) || (cVar1 == -1)) {
    if (uVar2 == 0) {
      if (iVar3 != 0) {
        FUN_0040b5e0(0);
      }
      goto LAB_0044daf8;
    }
    if (uVar2 <= *(uint *)(param_1 + 0xc)) goto LAB_0044daf8;
  }
  else if (uVar2 == 0) {
    *(char *)(iVar3 + -1) = cVar1 + -1;
    *(undefined4 *)(param_1 + 4) = 0;
    *(undefined4 *)(param_1 + 8) = 0;
    *(undefined4 *)(param_1 + 0xc) = 0;
    goto LAB_0044daf8;
  }
  FUN_0040b720(uVar2);
LAB_0044daf8:
  if (*(int *)(param_1 + 4) != 0) {
    *(undefined1 *)(*(int *)(param_1 + 4) + -1) = 0xff;
  }
  return;
}

