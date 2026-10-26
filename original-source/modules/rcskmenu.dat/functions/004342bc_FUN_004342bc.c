/*
 * FUN_004342bc at 004342bc
 * undefined __register FUN_004342bc(int param_1)
 * Address ranges: 004342bc-00434308
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004342bc(int param_1)

{
  int *piVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  int iVar2;
  int iVar3;
  
  *(undefined1 *)(param_1 + 0x4c) = 1;
  if (*(int *)(param_1 + 0x50) < 1) {
    if ((*(int *)(param_1 + 0x40) != 0) &&
       (iVar3 = *(int *)(*(int *)(param_1 + 0x40) + 8), -1 < iVar3 + -1)) {
      iVar2 = 0;
      do {
        piVar1 = (int *)FUN_0040f6b0(*(undefined4 **)(param_1 + 0x40),iVar2);
        FUN_00403088(piVar1,extraout_EDX,extraout_ECX);
        iVar2 = iVar2 + 1;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
    if (*(short *)(param_1 + 0x5a) != 0) {
      (**(code **)(param_1 + 0x58))(*(undefined4 *)(param_1 + 0x5c),param_1);
    }
  }
  return;
}

