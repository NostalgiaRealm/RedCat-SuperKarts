/*
 * FUN_004426ac at 004426ac
 * undefined __register FUN_004426ac(int param_1, int param_2)
 * Address ranges: 004426ac-004426eb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004426ac(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = FUN_0044268c(param_1);
  if (-1 < iVar1 + -1) {
    iVar3 = 0;
    do {
      iVar2 = FUN_00442650(param_1,iVar3);
      (**(code **)(iVar2 + 0x28))(*(undefined4 *)(iVar2 + 0x2c),param_2);
      if (*(int *)(param_2 + 0xc) != 0) {
        return;
      }
      iVar3 = iVar3 + 1;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return;
}

