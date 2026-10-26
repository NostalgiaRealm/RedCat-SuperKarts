/*
 * FUN_004673e0 at 004673e0
 * undefined4 __register FUN_004673e0(int param_1, int param_2)
 * Address ranges: 004673e0-0046745a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004673e0(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 local_14;
  
  if (*(short *)(param_1 + 0x23a) == 0) {
    iVar3 = 0;
    local_14 = 0;
    iVar4 = *(int *)(*(int *)(param_1 + 0x240) + 8);
    if (-1 < iVar4 + -1) {
      iVar5 = 0;
      do {
        iVar2 = FUN_004674ac(param_1,iVar5);
        if (*(char *)(iVar2 + 0x1f8) == '\0') {
          local_14 = local_14 + 1;
        }
        else {
          iVar3 = iVar3 + 1;
        }
        if (iVar3 == param_2 + 1) break;
        iVar5 = iVar5 + 1;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
    iVar4 = FUN_004674ac(param_1,param_2 + local_14);
    uVar1 = *(undefined4 *)(iVar4 + 0x1f0);
  }
  else {
    uVar1 = FUN_00466208(param_1,param_2);
  }
  return uVar1;
}

