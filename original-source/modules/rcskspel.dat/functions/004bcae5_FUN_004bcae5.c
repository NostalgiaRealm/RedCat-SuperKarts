/*
 * FUN_004bcae5 at 004bcae5
 * undefined FUN_004bcae5(void)
 * Address ranges: 004bcae5-004bcb91
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint __thiscall FUN_004bcae5(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  
  uVar1 = **(uint **)(param_1 + 0x1c);
  if (((uVar1 == 0) || (uVar1 <= **(uint **)(param_1 + 0xc))) ||
     ((param_2 != 0xffffffff && (*(byte *)(uVar1 - 1) != param_2)))) {
    if ((*(int *)(param_1 + 0x50) != 0) && (param_2 != 0xffffffff)) {
      if (*(int *)(param_1 + 0x38) == 0) {
        iVar4 = FUN_004c1222(param_2 & 0xff,*(int *)(param_1 + 0x50));
        if (iVar4 != -1) {
          return param_2;
        }
      }
      else {
        iVar4 = *(int *)(param_1 + 0x44);
        iVar2 = *(int *)(iVar4 + 8);
        if (iVar2 != 0) {
          FUN_0044da90();
          cVar3 = FUN_004bcf22(*(undefined4 *)(iVar4 + 4),*(undefined4 *)(param_1 + 0x50),iVar2);
          if (cVar3 != '\0') {
            FUN_004478a0(0,0xffffffff);
            *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)(param_1 + 0x3c);
            return param_2;
          }
        }
      }
    }
    param_2 = 0xffffffff;
  }
  else {
    FUN_004bce53();
    param_2 = -(uint)(param_2 != 0xffffffff) & param_2;
  }
  return param_2;
}

