/*
 * FUN_004bd8c0 at 004bd8c0
 * undefined FUN_004bd8c0(void)
 * Address ranges: 004bd8c0-004bd976
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint __thiscall FUN_004bd8c0(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  short sVar5;
  
  uVar1 = **(uint **)(param_1 + 0x1c);
  sVar5 = (short)param_2;
  if (((uVar1 == 0) || (uVar1 <= **(uint **)(param_1 + 0xc))) ||
     ((sVar5 != -1 && (*(short *)(uVar1 - 2) != sVar5)))) {
    if ((*(int *)(param_1 + 0x50) != 0) && (sVar5 != -1)) {
      if (*(int *)(param_1 + 0x38) == 0) {
        sVar5 = FUN_004c152d(param_2,*(int *)(param_1 + 0x50));
        if (sVar5 != -1) {
          return param_2;
        }
        return 0xffff;
      }
      iVar2 = *(int *)(param_1 + 0x44);
      iVar3 = *(int *)(iVar2 + 8);
      if (iVar3 != 0) {
        FUN_0044da90();
        cVar4 = FUN_004bcf22(*(undefined4 *)(iVar2 + 4),*(undefined4 *)(param_1 + 0x50),iVar3);
        if (cVar4 != '\0') {
          FUN_004478a0(0,0xffffffff);
          *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)(param_1 + 0x3c);
          return param_2 & 0xffff;
        }
      }
    }
    param_2 = 0xffff;
  }
  else {
    FUN_004bdcbc();
    param_2 = -(uint)(sVar5 != -1) & param_2;
  }
  return param_2;
}

